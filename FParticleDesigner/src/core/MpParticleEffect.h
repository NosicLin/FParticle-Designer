#ifndef _MP_PARTICLE_EFFECT_H_
#define _MP_PARTICLE_EFFECT_H_

#include "stage/entity/FsParticle2DEmitter.h"
#include "stage/entity/FsParticle2DEffect.h"

#include "core/MpIdentify.h"


NS_FS_USE

class MpProject;

class MpParticleEffect: public MpIdentify
{
	public:
		static MpParticleEffect* create();
		static MpParticleEffect* create(FsDict* dict);

	public:
		MpParticleEffect();
		~MpParticleEffect();

	public:
		virtual int getClassType();
		virtual const char* className();

	public:
		void setName(const char* name);
		std::string getName();

		void setTexturePath(const char* name);
		std::string getTexturePath();

		void setTextureEmbed(bool embed);
		bool getTextureEmbed();


        Particle2DEmitter* getParticleEmitter();
        Particle2DEffect* getParticleEffect();

		void setProject(MpProject* proj);
		MpProject* getProject();


	protected:
		void init();
		bool init(FsDict* dict);


	private:
		std::string m_name;
        Particle2DEmitter* m_emitter;
        Particle2DEffect* m_particleEffect;

		MpProject* m_project;

		bool m_textureEmbed;
		std::string m_texturePath;
};
#endif /*_MP_PARTICLE_EFFECT_H_*/



