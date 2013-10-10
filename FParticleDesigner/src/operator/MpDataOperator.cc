#include "operator/MpDataOperator.h"

#include "MpGlobal.h"
#include "MpMsgCenter.h"
#include "core/MpProject.h"
#include "core/MpParticleEffect.h"


void MpDataOperator::setCurProject(MpProject* proj)
{
	MpGlobal::setCurProject(proj);
	MpGlobal::msgCenter()->emitCurProjectChange();
	MpGlobal::msgCenter()->emitCurParticleEffectChange();
}

void MpDataOperator::setCurParticleEffect(MpParticleEffect* effect)
{
	MpGlobal::setCurMpParticleEffect(effect);
	MpGlobal::msgCenter()->emitCurParticleEffectChange();
}


void MpDataOperator::addParticleEffect(MpProject* proj,MpParticleEffect* effect)
{
	proj->addParticleEffect(effect);
	proj->setCurParticleEffect(effect);
	MpGlobal::msgCenter()->emitCurParticleEffectChange();
}

void MpDataOperator::removeParticleEffect(MpProject* proj,MpParticleEffect* effect)
{
	if(proj->getCurParticleEffect()==effect)
	{
		proj->setCurParticleEffect(NULL);
		MpGlobal::msgCenter()->emitCurParticleEffectChange();

	}

	proj->removeParticleEffect(effect);
	MpGlobal::msgCenter()->emitRemoveParticleEffect(effect);

	//qDebug("%x",long(effect));
    //delete effect;
}


void MpDataOperator::renameParticleEffect(MpParticleEffect* effect,const char* name)
{
	effect->setName(name);
	MpGlobal::msgCenter()->emitParticleEffectAttrChange(effect);
}












