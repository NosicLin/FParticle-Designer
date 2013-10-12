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

	/* FIXME: if delete proj,MpProjectExploreWidget will crash, 
	 * I don't know why, i have let MpProjectExploreModel emit layoutChanged signal
	 * but if don't delete, memory will leak
	 */

	//delete proj;   
}

void MpDataOperator::setCurParticleEffect(MpParticleEffect* effect)
{
	MpGlobal::setCurMpParticleEffect(effect);
	MpGlobal::msgCenter()->emitCurParticleEffectChange();
}


void MpDataOperator::addParticleEffect(MpProject* proj,MpParticleEffect* effect)
{
	proj->addParticleEffect(effect);
	MpGlobal::msgCenter()->emitAddParticleEffect(effect);

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

	/* FIXME: it delete  effect MpProjectExploreWidget will crash */
    //delete effect;
	
}


void MpDataOperator::renameParticleEffect(MpParticleEffect* effect,const char* name)
{
	effect->setName(name);
	MpGlobal::msgCenter()->emitParticleEffectAttrChange(effect);
}












