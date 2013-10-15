#ifndef _MP_TEXTURE_SETTING_WIDGET_H_
#define _MP_TEXTURE_SETTING_WIDGET_H_

#include <QWidget>
#include "ui_texture_setting.h"

enum 
{
	MP_BLEND_ZERO=0,
	MP_BLEND_ONE=1,

	MP_BLEND_SRC_COLOR=2,
	MP_BLEND_ONE_MINUS_SRC_COLOR=3,

	MP_BLEND_DST_COLOR=4,
	MP_BLEND_ONE_MINUS_DST_COLOR=5,

	MP_BLEND_SRC_ALPHA=6,
	MP_BLEND_ONE_MINUS_SRC_ALPHA=7,

	MP_BLEND_DST_ALPHA=8,
	MP_BLEND_ONE_MINUS_DST_ALPHA=9,

    MP_BLEND_SRC_ALPHA_SATURATE=10

};


class MpTextureSettingWidget:public QWidget 
{
	Q_OBJECT
	public:
		MpTextureSettingWidget();
		~MpTextureSettingWidget();

	public slots:
		void slotOnSetTexture();
		void slotCurParticleEffectChange();
		void slotCurProjectChange();
		void slotBlendSrcChange(int index);
		void slotBlendDstChange(int index);

	protected:
		void init();
		void connectSignal();
		void setBlendSrc(int index);
		void setBlendDst(int index);

	private:
		Ui_texture_setting* m_ui;
};


#endif /*_MP_TEXTURE_SETTING_WIDGET_H_*/
