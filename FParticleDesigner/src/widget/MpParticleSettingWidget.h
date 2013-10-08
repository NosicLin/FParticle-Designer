#ifndef _MP_PARTICLE_SETTING_WIDGET_H_
#define _MP_PARTICLE_SETTING_WIDGET_H_

#include <QWidget>
#include "ui_particle_setting.h"

class MpParticleSettingWidget:public QWidget 
{
	Q_OBJECT
	public:
		MpParticleSettingWidget();
		~MpParticleSettingWidget();


	public slots:
		void slotCurParticleEffectChange();



	protected:
		void init();
		void connectSignal();

	private:
		Ui_particle_setting* m_ui;
};


#endif /*_MP_PARTICLE_SETTING_WIDGET_H_*/


