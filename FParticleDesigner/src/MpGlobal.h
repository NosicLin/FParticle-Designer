#ifndef _MP_GLOBAL_H_
#define _MP_GLOBAL_H_

#include <QObject>
class MpAttrOperator;
class MpProject;
class MpParticleEffect;
class MpMsgCenter;

#include "stage/entity/FsParticle2DEmitter.h"

NS_FS_USE

class MpGlobal
{
	public:
		/* operator */
		static MpAttrOperator* attrOperator();

		/* msg center */
		static MpMsgCenter* msgCenter();

		/* project */
		static MpProject* getCurProject();
		static void setCurProject(MpProject* proj);

		/* particle effect */
		static MpParticleEffect* getCurMpParticleEffect();
		static void setCurMpParticleEffectt(MpParticleEffect* effect);

		/* particle emitter */
        static Particle2DEmitter* getCurParticle2DEmitter();


	public:
		static MpAttrOperator* m_attrOperator;
		static MpProject* m_project;
		static MpMsgCenter* m_msgCenter;
};


void MpGlobal_ModuleInit();



#endif /*_MP_GLOBAL_H_*/








