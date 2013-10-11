#ifndef _MP_MSG_CENTER_H_
#define _MP_MSG_CENTER_H_ 
#include <QObject>


class MpParticleEffect;
class MpMsgCenter: public QObject
{
	Q_OBJECT
	public:
		MpMsgCenter();


    signals:
		void signalCurProjectChange();
		void signalCurParticleEffectChange();
		void signalParticleEffectAttrChange(MpParticleEffect* effect);
		void signalRemoveParticleEffect(MpParticleEffect* effect);
		void signalAddParticleEffect(MpParticleEffect* effect);

	public:
		void emitCurParticleEffectChange();
		void emitCurProjectChange();

		void emitAddParticleEffect(MpParticleEffect* effect);
		void emitParticleEffectAttrChange(MpParticleEffect* effect);
		void emitRemoveParticleEffect(MpParticleEffect* effect);
};


#endif /*_MP_MSG_CENTER_H_*/

