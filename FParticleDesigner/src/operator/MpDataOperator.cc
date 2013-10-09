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
	proj->removeParticleEffect(effect);
	if(proj->getCurParticleEffect()==effect)
	{
		proj->setCurParticleEffect(NULL);
		MpGlobal::msgCenter()->emitCurParticleEffectChange();
	}

}



