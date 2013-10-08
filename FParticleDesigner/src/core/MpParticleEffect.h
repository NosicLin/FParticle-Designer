#ifndef _MP_PARTICLE_EFFECT_H_
#define _MP_PARTICLE_EFFECT_H_

#include "stage/entity/FsParticle2DEmitter.h"
#include "stage/entity/FsParticle2DEffect.h"

NS_FS_USE

class MpParticleEffect 
{
	public:
		static MpParticleEffect* create();
		static MpParticleEffect* create(FsDict* dict);

	public:
		MpParticleEffect();
		~MpParticleEffect();

	public:
		void setName(const char* name);
		std::string getName();

        Particle2DEmitter* getParticleEmitter();
        Particle2DEffect* getParticleEffect();


	protected:
		void init();
		bool init(FsDict* dict);


	private:

		std::string m_name;
        Particle2DEmitter* m_emitter;
        Particle2DEffect* m_particleEffect;
};
#endif /*_MP_PARTICLE_EFFECT_H_*/



