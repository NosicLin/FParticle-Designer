#ifndef _MP_GLOBAL_H_
#define _MP_GLOBAL_H_

#include <QObject>
class MpAttrOperator;
class MpProject;
class MpParticleEffect;
class MpMsgCenter;
class MpConfig;

#include "stage/entity/FsParticle2DEmitter.h"

NS_FS_USE

class MpGlobal
{
	public:
		/* msg center */
		static MpMsgCenter* msgCenter();

		/* project */
		static MpProject* getCurProject();
		static void setCurProject(MpProject* proj);

		/* particle effect */
		static MpParticleEffect* getCurMpParticleEffect();
        static void setCurMpParticleEffect(MpParticleEffect* effect);

		/* particle emitter */
        static Particle2DEmitter* getCurParticle2DEmitter();


		/* config */
		static MpConfig* getConfig();

	private:
		static MpProject* m_project;
		static MpMsgCenter* m_msgCenter;
		static MpConfig* m_config;


};





#endif /*_MP_GLOBAL_H_*/








