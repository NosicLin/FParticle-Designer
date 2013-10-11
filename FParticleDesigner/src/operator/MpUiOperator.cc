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

#include "widget/SdInputDialog.h"
#include "MpGlobal.h"
#include "MpConfig.h"
#include "core/MpParticleEffect.h"
#include "core/MpProject.h"




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
	//	std::string path=dir+"/"+name;
	std::string path=name;

	qDebug("Begin Save Project %s",name.c_str());
	if(!MpOperator::io()->saveProject(path.c_str(),proj))
	{
		qDebug("Save Project %s Failed",name.c_str());
	}
}


void MpUiOperator::loadProject()
{
	QString path=QFileDialog::getOpenFileName(NULL,tr("Open Image"),".",tr("FParticle File(*.fparticle)"));
	if(path.length()==NULL)
	{
		return ;
	}

	MpProject* proj=MpOperator::io()->loadProject(path.toStdString().c_str());
	if(proj==NULL)
	{
		QMessageBox msg(QMessageBox::Warning,"Open Project","Can't Open Project");
		msg.exec();
	}
	else 
	{
		proj->setName(path.toStdString().c_str());
		MpOperator::data()->setCurProject(proj);
	}
}


void MpUiOperator::closeProject()
{
	QMessageBox msg(QMessageBox::Warning,"Close Project","Are You Sure To Close Project",QMessageBox::Ok|QMessageBox::Cancel);
	if(msg.exec()==QMessageBox::Ok)
	{
		MpOperator::data()->setCurProject(NULL);
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












