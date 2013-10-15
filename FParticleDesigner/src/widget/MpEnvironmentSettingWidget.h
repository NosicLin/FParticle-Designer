#ifndef _MP_ENVIRONMENT_SETTING_WIDGET_H_
#define _MP_ENVIRONMENT_SETTING_WIDGET_H_

#include <QWidget>
#include "ui_environment_setting.h"

enum 
{
	MP_MODEL_GRAVITY=0,
	MP_MODEL_RADIUS=1,
};

enum 
{
	MP_MOVE_MODE_FREE=0,
	MP_MOVE_MODE_GROUP=1,
};

class MpEnvironmentSettingWidget:public QWidget 
{
	Q_OBJECT
	public:
		MpEnvironmentSettingWidget();
		~MpEnvironmentSettingWidget();

	public slots:
		void slotCurParticleEffectChange();
		void slotSelectModeChange(int index);
		void slotMoveModeChange(int index);

	public:
		void setEvnMode(int mode);
		void setMoveMode(int mode);

	protected:
		void init();
		void connectSignal();

	private:
        Ui_environment_setting* m_ui;
};


#endif /*_MP_ENVIRONMENT_SETTING_WIDGET_H_*/

