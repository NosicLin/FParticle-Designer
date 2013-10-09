#ifndef _MP_MSG_CENTER_H_
#define _MP_MSG_CENTER_H_ 
#include <QObject>

class MpMsgCenter: public QObject
{
	Q_OBJECT
	public:
		MpMsgCenter();


    signals:
		void signalCurProjectChange();
		void signalCurParticleEffectChange();

	public:
		void emitCurParticleEffectChange();
		void emitCurProjectChange();
};


#endif /*_MP_MSG_CENTER_H_*/

