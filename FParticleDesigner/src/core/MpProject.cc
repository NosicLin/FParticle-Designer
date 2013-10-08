#include <assert.h>
#include "core/MpProject.h"


MpProject::MpProject()
{
	m_curParticleEffect=NULL;

}

MpProject::~MpProject()
{
}



std::string MpProject::getName()
{
	return m_name;
}

void MpProject::setName(const char* name)
{
	m_name=std::string(name);
}



void MpProject::addParticleEffect(MpParticleEffect* ef) 
{
	m_particleEffects.push_back(ef);
}

void MpProject::removeParticleEffect(MpParticleEffect* ef)
{
	std::vector<MpParticleEffect*>::iterator iter;
	for(iter=m_particleEffects.begin();iter!=m_particleEffects.end();++iter)
	{
		if(*iter==ef)
		{
			m_particleEffects.erase(iter);
			return ;
		}
	}
	assert(0);
}

int MpProject::getParticleEffectNu()
{
	return m_particleEffects.size();
}

MpParticleEffect* MpProject::getCurParticleEffect()
{
	return m_curParticleEffect;
}


void MpProject::setCurParticleEffect(MpParticleEffect* effect)
{
	m_curParticleEffect=effect;
}

