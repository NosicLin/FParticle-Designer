#include <QtGlobal>
#include "MpMsgCenter.h"

MpMsgCenter::MpMsgCenter()
{
}


void MpMsgCenter::emitCurParticleEffectChange()
{
	emit signalCurParticleEffectChange();
}


void MpMsgCenter::emitCurProjectChange()
{
	emit signalCurProjectChange();

}








