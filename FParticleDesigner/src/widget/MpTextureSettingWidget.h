#ifndef _MP_TEXTURE_SETTING_WIDGET_H_
#define _MP_TEXTURE_SETTING_WIDGET_H_

#include <QWidget>
#include "ui_texture_setting.h"

class MpTextureSettingWidget:public QWidget 
{
	public:
		MpTextureSettingWidget();
		~MpTextureSettingWidget();

	protected:
		void init();
		void connectSignal();

	private:
		Ui_texture_setting* m_ui;
};


#endif /*_MP_TEXTURE_SETTING_WIDGET_H_*/
