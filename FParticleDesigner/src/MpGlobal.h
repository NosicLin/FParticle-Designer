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
		static MpAttrOperator* attrOperator();
		static MpProject* project();
		static MpMsgCenter* msgCenter();

		static MpParticleEffect* curMpParticleEffect();
        static Particle2DEmitter* curParticle2DEmitter();

	public:
		static MpAttrOperator* m_attrOperator;
		static MpProject* m_project;
		static MpMsgCenter* m_msgCenter;
};


void MpGlobal_ModuleInit();



#endif /*_MP_GLOBAL_H_*/

