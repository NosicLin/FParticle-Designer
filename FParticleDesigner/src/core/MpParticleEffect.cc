#include "core/MpParticleEffect.h"



MpParticleEffect::MpParticleEffect()
{
	m_emitter=NULL;
	m_particleEffect=NULL;
}



MpParticleEffect::~MpParticleEffect()
{
	FS_SAFE_DEC_REF(m_emitter);
	FS_SAFE_DEC_REF(m_particleEffect);
	m_emitter=NULL;
	m_particleEffect=NULL;
}


MpParticleEffect* MpParticleEffect::create()
{
	MpParticleEffect* ret=new MpParticleEffect();
	ret->init();
	return ret;
}

MpParticleEffect* MpParticleEffect::create(FsDict* dict)
{
	MpParticleEffect* ret= new MpParticleEffect() ;
	if(!ret->init(dict))
	{
		delete ret;
		return NULL;
	}
	return ret;
}

void MpParticleEffect::setName(const char* name)
{
	m_name=std::string(name);
}


std::string MpParticleEffect::getName()
{
	return m_name;
}

Particle2DEmitter* MpParticleEffect::getParticleEmitter()
{
	return m_emitter;
}


Particle2DEffect* MpParticleEffect::getParticleEffect()
{
	return m_particleEffect;
}

void MpParticleEffect::init()
{
    Particle2DEmitter* emitter=Particle2DEmitter::create();
    m_particleEffect=Particle2DEffect::create(emitter);
	m_emitter=emitter;
}

bool MpParticleEffect::init(FsDict* dict)
{
	Particle2DEmitter* emitter=Particle2DEmitter::create(dict);
	if(emitter==NULL)
	{
		return false;
	}
	m_particleEffect=Particle2DEffect::create(emitter);
	m_emitter=emitter;
	return true;
}
























