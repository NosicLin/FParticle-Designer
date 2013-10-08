#include "MpGlobal.h"
#include "MpMsgCenter.h"
#include "core/MpProject.h"
#include "core/MpParticleEffect.h"
#include "operator/MpAttrOperator.h"


MpAttrOperator* MpGlobal::m_attrOperator=NULL;
MpProject* MpGlobal::m_project=NULL;
MpMsgCenter* MpGlobal::m_msgCenter=NULL;


void MpGlobal_ModuleInit()
{
    MpGlobal::m_attrOperator=new MpAttrOperator;
	MpGlobal::m_project=NULL;
	MpGlobal::m_msgCenter=new MpMsgCenter;
}

MpAttrOperator* MpGlobal::attrOperator()
{
	return m_attrOperator;
}

MpMsgCenter* MpGlobal::msgCenter()
{
	return m_msgCenter;
}



MpProject* MpGlobal::project()
{
	return m_project;
}


MpParticleEffect* MpGlobal::curMpParticleEffect()
{
	if(!m_project)
	{
		return NULL;
	}

	MpParticleEffect* ret=m_project->getCurParticleEffect();
	return ret;
}

Particle2DEmitter* MpGlobal::curParticle2DEmitter()
{
	if(!m_project)
	{
		return NULL;
	}

	MpParticleEffect* pf=m_project->getCurParticleEffect();
	if(!pf)
	{
		return NULL;
	}

    Particle2DEmitter* ret=pf->getParticleEmitter();
	return ret;
}













