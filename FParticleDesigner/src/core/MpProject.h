#ifndef _MP_PROJECT_H_
#define _MP_PROJECT_H_

#include <vector>
#include <string>

class MpParticleEffect;
class MpProject 
{
	public:
		MpProject();
		~MpProject();

	public:
		std::string getName();
		void setName(const char* name);

	public:
		/* particle */
		void addParticleEffect(MpParticleEffect* ef);
		void removeParticleEffect(MpParticleEffect* ef);
		int getParticleEffectNu();
		MpParticleEffect* getParticleEffect(int index);

		/* cur particle */
		MpParticleEffect* getCurParticleEffect();
		void setCurParticleEffect(MpParticleEffect* effect);

	private:
		std::vector<MpParticleEffect* > m_particleEffects;
		std::string m_name;

		MpParticleEffect* m_curParticleEffect;
};

#endif /*_MP_PROJECT_H_*/

