#include "widget/MpTextureSettingWidget.h"


MpTextureSettingWidget::MpTextureSettingWidget()
{
	init();
}
MpTextureSettingWidget::~MpTextureSettingWidget()
{
}

void MpTextureSettingWidget::init()
{
	m_ui=new Ui_texture_setting;
	m_ui->setupUi(this);
}

