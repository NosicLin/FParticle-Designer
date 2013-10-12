#include <string>
#include <QtGlobal>
#include "core/MpParticleEffect.h"
#include "support/util/FsDict.h"
#include "support/util/FsArray.h"
#include "support/util/FsString.h"
#include "support/util/FsScriptUtil.h"




MpParticleEffect::MpParticleEffect()
{
	m_emitter=NULL;
	m_particleEffect=NULL;
	m_textureEmbed=false;
	m_texturePath="";
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


int MpParticleEffect::getClassType()
{
	return MP_PARTICLE;
}


const char* MpParticleEffect::className()
{
	return "ParticleEffect";
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

	FsDict* d_texture=ScriptUtil::getDict(dict,"texture");
	if(d_texture==NULL)
	{
		qDebug("texture filed not find");
		emitter->decRef();
		return NULL;
	}

	FsString* s_url=ScriptUtil::getString(d_texture,"url");
	if(s_url==NULL)
	{
		d_texture->decRef();
		emitter->decRef();
		return NULL;
	}

	bool embed;
	ScriptUtil::getBoolean(d_texture,"embed",&embed);

    setTexturePath(s_url->cstr());
	setTextureEmbed(embed);

	d_texture->decRef();
    s_url->decRef();

	m_particleEffect=Particle2DEffect::create(emitter);
	m_emitter=emitter;
	return true;
}


void MpParticleEffect::setProject(MpProject* proj)
{
	m_project=proj;
}


MpProject* MpParticleEffect::getProject()
{
	return m_project;
}


void MpParticleEffect::setTexturePath(const char* name)
{
	m_texturePath=name;
}


std::string MpParticleEffect::getTexturePath()
{
	return m_texturePath;
}


void MpParticleEffect::setTextureEmbed(bool embed)
{
	m_textureEmbed=embed;
}


bool MpParticleEffect::getTextureEmbed()
{
	return m_textureEmbed;
}



