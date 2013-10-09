#ifndef _MP_DATA_OPERATOR_H_
#define _MP_DATA_OPERATOR_H_

class MpProject;
class MpParticleEffect;
class MpDataOperator 
{
	public:
		void setCurProject(MpProject* proj);
		void setCurParticleEffect(MpParticleEffect* effect);

		void addParticleEffect(MpProject* proj,MpParticleEffect* effect);
		void removeParticleEffect(MpProject* proj,MpParticleEffect* effect);
};

#endif /*_MP_DATA_OPERATOR_H_*/

