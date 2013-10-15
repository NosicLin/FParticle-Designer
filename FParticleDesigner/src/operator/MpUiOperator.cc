#include <QtGlobal>
#include <string>
#include <QFileDialog>
#include <QDialog>
#include <QMessageBox>
#include <stdio.h>

#include "operator/MpUiOperator.h"
#include "operator/MpOperator.h"
#include "operator/MpDataOperator.h"
#include "operator/MpIoOperator.h"
#include "util/MpPathUtil.h"
#include "util/MpPathUtil.h"


#include "widget/SdInputDialog.h"
#include "MpGlobal.h"
#include "MpConfig.h"
#include "core/MpParticleEffect.h"
#include "core/MpProject.h"

#include "FsGlobal.h"
#include "graphics/FsTexture2D.h"
#include "stage/entity/FsParticle2DEmitter.h"
#include "sys/io/FsVFS.h"



NS_FS_USE



void MpUiOperator::newParticle()
{
	char buf[1024];
	int i=0;
	while(true)
	{
		sprintf(buf,"untitled-particle-%d",i);
        if(MpGlobal::getCurProject()->hasParticleWithName(buf))
		{
			i++;
			continue;
		}
		break;
	}

	SdInputDialog dialog("New Particle",buf);
    if(dialog.exec()==QDialog::Accepted)
	{
		std::string name=dialog.getTextField();
		if(name=="")
		{
			QMessageBox msg(QMessageBox::Warning,"New Particle","Name Can't Be Empty String");
			msg.exec();
		}
        else if(MpGlobal::getCurProject()->hasParticleWithName(name.c_str()))
		{
			QMessageBox msg(QMessageBox::Warning,"New Particle",QString("Name(")+QString(name.c_str())+") Alread Exist");
			msg.exec();
		}
		else 
		{
            MpParticleEffect* effect=MpParticleEffect::create();
			effect->setName(name.c_str());
            MpOperator::data()->addParticleEffect(MpGlobal::getCurProject(),effect);
		}
	}
}

void MpUiOperator::exportAllParticleEffect()
{
	MpProject* proj=MpGlobal::getCurProject();
	if(!proj)
	{
        return ;
	}


    std::string export_dir=MpGlobal::getConfig()->getLastExportPath();
    QString path=QFileDialog::getExistingDirectory(NULL,tr("Export All Particle"),export_dir.c_str(),QFileDialog::ShowDirsOnly);

    int particle_effect_nu=proj->getParticleEffectNu();

	for(int i=0;i<particle_effect_nu;i++)
	{
        MpParticleEffect* effect=proj->getParticleEffect(i);

        std::string name=path.toStdString()+std::string("/")+effect->getName()+std::string(".fpl");
        int ret=MpOperator::io()->exportParticleEffect(name.c_str(),effect);

		if(!ret)
		{
			std::string info=std::string("Export Failed(")+name+std::string(")");
			QMessageBox msg(QMessageBox::Warning,"Export Particle",info.c_str());
			msg.exec();
		}
	}

}




void MpUiOperator::renameParticle()
{
	MpParticleEffect* effect=MpGlobal::getCurMpParticleEffect();
	SdInputDialog dialog("Rename Particle",effect->getName().c_str());

	if(dialog.exec()==QDialog::Accepted)
	{
		std::string name=dialog.getTextField();
		if(name=="")
		{
			QMessageBox msg(QMessageBox::Warning,"Rename Particle","Name Can't Be Empty String");
			msg.exec();
		}
		else if(MpGlobal::getCurProject()->hasParticleWithName(name.c_str()))
		{
			QMessageBox msg(QMessageBox::Warning,"Rename Particle",QString("Name(")+QString(name.c_str())+") Alread Exist"); 
			msg.exec();
		}
		else 
		{
			MpOperator::data()->renameParticleEffect(effect,name.c_str());
		}

	}
}

void MpUiOperator::removeParticle()
{
	MpProject* proj=MpGlobal::getCurProject();
	MpParticleEffect* effect=MpGlobal::getCurMpParticleEffect();
	std::string name=effect->getName();

	QMessageBox msg(QMessageBox::Warning,"Delete Partile",QString("Are You Sure To Remove ParticleEffect (")+QString(name.c_str())+")",QMessageBox::Ok|QMessageBox::Cancel);

	if(msg.exec()==QMessageBox::Ok)
	{
		MpOperator::data()->removeParticleEffect(proj,effect);
	}
}



void MpUiOperator::saveProject()
{

	MpProject* proj=MpGlobal::getCurProject();
	std::string dir=proj->getDir();
	std::string name=proj->getName();
	std::string path=dir+"/"+name;

	qDebug("Begin Save Project %s",name.c_str());
	if(!MpOperator::io()->saveProject(path.c_str(),proj))
	{
		qDebug("Save Project %s Failed",name.c_str());
	}
}


void MpUiOperator::loadProject()
{
	QString path=QFileDialog::getOpenFileName(NULL,tr("Open Project"),".",tr("FParticle File(*.fparticle)"));
	if(path.length()==NULL)
	{
		return ;
	}

	std::string dir_name=MpPathUtil::dirName(path.toStdString().c_str());
	std::string file_name=MpPathUtil::baseName(path.toStdString().c_str());
	std::string vfs_root=dir_name+"/";
	VFS::setRoot(vfs_root.c_str());

	MpProject* proj=MpOperator::io()->loadProject(path.toStdString().c_str());

	if(proj==NULL)
	{
		QMessageBox msg(QMessageBox::Warning,"Open Project","Can't Open Project");
		msg.exec();
	}
	else 
	{
		proj->setDir(dir_name.c_str());
		proj->setName(file_name.c_str());
		MpOperator::data()->setCurProject(proj);
	}
}


void MpUiOperator::closeProject()
{
	MpProject* proj=MpGlobal::getCurProject();
	if(proj)
	{
		QMessageBox msg(QMessageBox::Warning,"Close Project","Are You Sure To Close Project",QMessageBox::Ok|QMessageBox::Cancel);
		if(msg.exec()==QMessageBox::Ok)
		{
			MpOperator::data()->setCurProject(NULL);
		}
	}
}

void MpUiOperator::exportParticleEffect()
{
	MpParticleEffect* effect=MpGlobal::getCurMpParticleEffect();
	if(!effect)
	{
		return ;
	}
	std::string export_name=MpGlobal::getConfig()->getLastExportPath()+std::string("/")+effect->getName()+std::string(".fpl");

	QString path=QFileDialog::getSaveFileName(NULL,tr("Export Particle"),export_name.c_str(),tr("FParticle File(*.fpl)"));

	if(path.length()==0)
	{
		return;
	}

	std::string last_dir=MpPathUtil::dirName(path.toStdString().c_str());
	qDebug("last dir=%s",last_dir.c_str());

	MpGlobal::getConfig()->setLastExportPath(last_dir.c_str());

	int ret=MpOperator::io()->exportParticleEffect(path.toStdString().c_str(),effect);


	if(!ret)
	{
		QMessageBox msg(QMessageBox::Warning,"Export Particle","Export Failed");
		msg.exec();
	}
}

void MpUiOperator::setTexture()
{
	MpProject*  proj=MpGlobal::getCurProject();
	MpParticleEffect* effect=MpGlobal::getCurMpParticleEffect();
	if(effect==NULL)
	{
		return ;

	}



	std::string proj_path=proj->getDir();
	QString path=QFileDialog::getOpenFileName(NULL,tr("Open Image"),proj_path.c_str(),tr("image(*.png)"));

	/*
	   qDebug("proj_path=%s",proj_path.c_str());
	   qDebug("load_path=%s",path.toStdString().c_str());
	   */


	if(path.length()==NULL)
	{
		return ;
	}




	std::string t_path=path.toStdString();
	std::string relative_path=MpPathUtil::removePrePath(t_path,proj_path);
	//qDebug("relative_path=%s",relative_path.c_str());

	Texture2D* texture=Global::textureMgr()->loadTexture(relative_path.c_str());
	if(texture==NULL)
	{
		qDebug("load Texture Failed");
	}

	Particle2DEmitter* emitter=effect->getParticleEmitter();

	emitter->setTexture(texture);
	effect->setTexturePath(relative_path.c_str());
}


void MpUiOperator::newProject()
{
	QString path=QFileDialog::getSaveFileName(NULL,tr("New Project"),".",tr("Particle Designer(*.fparticle)"));


	std::string t_path=path.toStdString();
	std::string t_path_dir=MpPathUtil::dirName(t_path.c_str());
	std::string t_path_name=MpPathUtil::baseName(t_path.c_str());

	/*
	   qDebug("t_path=%s",t_path.c_str());
	   qDebug("t_path_dir=%s",t_path_dir.c_str());
	   qDebug("t_path_name=%s",t_path_name.c_str());
	   */

	std::string vfs_root=t_path_dir+"/";
	VFS::setRoot(vfs_root.c_str());


	MpProject* proj=new MpProject();
	proj->setDir(t_path_dir.c_str());
	proj->setName(t_path_name.c_str());
	MpOperator::data()->setCurProject(proj);


}



















