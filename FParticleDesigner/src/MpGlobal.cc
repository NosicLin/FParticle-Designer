#include "MpGlobal.h"
#include "MpMsgCenter.h"
#include "core/MpProject.h"
#include "core/MpParticleEffect.h"
#include "operator/MpAttrOperator.h"


MpProject* MpGlobal::m_project=NULL;
MpMsgCenter* MpGlobal::m_msgCenter=NULL;


MpMsgCenter* MpGlobal::msgCenter()
{
	if(MpGlobal::m_msgCenter==NULL)
	{
		MpGlobal::m_msgCenter=new MpMsgCenter;
	}

	return MpGlobal::m_msgCenter;
}




MpProject* MpGlobal::getCurProject()
{
	return m_project;
}

void  MpGlobal::setCurProject(MpProject* proj)
{
	if(m_project)
	{
		delete m_project;
	}
	m_project=proj;
}

MpParticleEffect* MpGlobal::getCurMpParticleEffect()
{
	if(!m_project)
	{
		return NULL;
	}

	MpParticleEffect* ret=m_project->getCurParticleEffect();
	return ret;
}


void MpGlobal::setCurMpParticleEffect(MpParticleEffect* effect)
{
	assert(m_project);
    m_project->setCurParticleEffect(effect);
}


Particle2DEmitter* MpGlobal::getCurParticle2DEmitter()
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



