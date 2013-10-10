#include <QDialog>
#include <QMessageBox>
#include <stdio.h>
#include "operator/MpUiOperator.h"
#include "operator/MpOperator.h"
#include "operator/MpDataOperator.h"
#include "widget/SdInputDialog.h"
#include "MpGlobal.h"
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

void MpUiOperator::exportAll()
{
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










 




