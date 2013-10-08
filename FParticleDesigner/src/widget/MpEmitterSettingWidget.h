#ifndef _MP_EMITTER_SETTING_WIDGET_H_
#define _MP_EMITTER_SETTING_WIDGET_H_

#include <QWidget>
#include <QDoubleSpinBox>
#include "ui_emiter_setting.h"


class MpEmitterSettingWidget:public QWidget
{
	Q_OBJECT

	public:
        MpEmitterSettingWidget(QWidget* parent=0);
		~MpEmitterSettingWidget();

    public slots:
        void onCurParticleEffectChange();

	protected:
		void init();
        void connectSignal();


	private:
		Ui_emitter* m_ui;
};





#endif /*_MP_EMITTER_SETTING_WIDGET_H_*/

