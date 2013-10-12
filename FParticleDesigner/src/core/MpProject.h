#ifndef _MP_PROJECT_H_
#define _MP_PROJECT_H_

#include <vector>
#include <string>
#include "core/MpIdentify.h"


class MpParticleEffect;
class MpProject :public MpIdentify
{
	public:
		MpProject();
		~MpProject();

	public:
		virtual int getClassType();
		virtual const char* className();

	public:
		/* dir */
		std::string getDir();
		void setDir(const std::string& name);

		/* name */
		std::string getName();
		void setName(const char* name);
		bool hasParticleWithName(const char* name);


	public:
		/* particle */
		void addParticleEffect(MpParticleEffect* ef);
		void removeParticleEffect(MpParticleEffect* ef);

		int getParticleEffectNu();
		MpParticleEffect* getParticleEffect(int index);
		int getParticleEffectPos(MpParticleEffect* ef);


		/* cur particle */
		MpParticleEffect* getCurParticleEffect();
		void setCurParticleEffect(MpParticleEffect* effect);

	private:
		MpParticleEffect* m_curParticleEffect;
		std::vector<MpParticleEffect* > m_particleEffects;
		std::string m_name;
		std::string m_dir;
};

#endif /*_MP_PROJECT_H_*/


