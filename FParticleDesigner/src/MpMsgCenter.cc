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

void MpMsgCenter::emitParticleEffectAttrChange(MpParticleEffect* effect)
{
	emit signalParticleEffectAttrChange(effect);
}

void MpMsgCenter::emitRemoveParticleEffect(MpParticleEffect* effect)
{
	emit signalRemoveParticleEffect(effect);
}


