#include "operator/MpOperator.h"
#include "operator/MpUiOperator.h"
#include "core/MpParticleEffect.h"
#include "MpGlobal.h"
#include "MpMsgCenter.h"

#include "widget/MpTextureSettingWidget.h"


MpTextureSettingWidget::MpTextureSettingWidget()
{
	init();
	connectSignal();
}
MpTextureSettingWidget::~MpTextureSettingWidget()
{

}


void MpTextureSettingWidget::init()
{
	m_ui=new Ui_texture_setting;
	m_ui->setupUi(this);
}

void MpTextureSettingWidget::slotOnSetTexture()
{
	MpOperator::ui()->setTexture();
	MpParticleEffect* effect=MpGlobal::getCurMpParticleEffect();
	m_ui->m_t_imagePath->setText(effect->getTexturePath().c_str());
}

void MpTextureSettingWidget::slotCurParticleEffectChange()
{
	MpParticleEffect*  effect=MpGlobal::getCurMpParticleEffect();
	if(effect)
	{
		this->setEnabled(true);
		m_ui->m_t_imagePath->setText(effect->getTexturePath().c_str());
	}
	else 
	{
		this->setEnabled(false);
	}

}

void MpTextureSettingWidget::slotCurProjectChange()
{
	slotCurParticleEffectChange();
}





void MpTextureSettingWidget::connectSignal()
{
	connect(m_ui->m_b_browse,SIGNAL(clicked()),this,SLOT(slotOnSetTexture()));
	connect(MpGlobal::msgCenter(),SIGNAL(signalCurParticleEffectChange()),this,SLOT(slotCurParticleEffectChange()));
	connect(MpGlobal::msgCenter(),SIGNAL(signalCurProjectChange()),this,SLOT(slotCurProjectChange()));

}








