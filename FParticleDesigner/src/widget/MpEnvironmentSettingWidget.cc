#include "widget/MpEnvironmentSettingWidget.h"
#include "MpGlobal.h"
#include "operator/MpAttrOperator.h"
#include "stage/entity/FsParticle2DEmitter.h"
#include "MpMsgCenter.h"

NS_FS_USE

MpEnvironmentSettingWidget::MpEnvironmentSettingWidget()
{
	init();
}

MpEnvironmentSettingWidget::~MpEnvironmentSettingWidget()
{
}

void MpEnvironmentSettingWidget::init()
{
    m_ui=new Ui_environment_setting;
	m_ui->setupUi(this);
	connectSignal();
}


void MpEnvironmentSettingWidget::connectSignal()
{
	MpAttrOperator* attr=MpGlobal::attrOperator();
	connect(m_ui->m_eg_gravityXValue,SIGNAL(valueChanged(double)),attr,SLOT(onSetGravityX(double)));
	connect(m_ui->m_eg_gravityYValue,SIGNAL(valueChanged(double)),attr,SLOT(onSetGravityY(double)));
	connect(m_ui->m_eg_radialAccelValue,SIGNAL(valueChanged(double)),attr,SLOT(onSetRadialAcceleration(double)));
	connect(m_ui->m_eg_radialAccelVar,SIGNAL(valueChanged(double)),attr,SLOT(onSetRadialAccelerationVar(double)));
	connect(m_ui->m_eg_tangentialAccelValue,SIGNAL(valueChanged(double)),attr,SLOT(onSetTangentialAcceleration(double)));
	connect(m_ui->m_eg_tangentialAccelVar,SIGNAL(valueChanged(double)),attr,SLOT(onSetTangentialAccelerationVar(double)));


    connect(m_ui->m_modeSelect,SIGNAL(currentIndexChanged(int)),this,SLOT(slotSelectModeChange(int)));
	connect(MpGlobal::msgCenter(),SIGNAL(signalCurParticleEffectChange()),this,SLOT(slotCurParticleEffectChange()));
}


void MpEnvironmentSettingWidget::slotCurParticleEffectChange()
{

	Particle2DEmitter* emiter=MpGlobal::curParticle2DEmitter();

	if(emiter)
	{
        this->setEnabled(true);
		Vector2 gravity=emiter->getGravity();

		/* gravity mode */
		m_ui->m_eg_gravityXValue->setValue(gravity.x);
		m_ui->m_eg_gravityYValue->setValue(gravity.y);

		m_ui->m_eg_radialAccelValue->setValue(emiter->getRadialAcceleration());

		m_ui->m_eg_radialAccelVar->setValue(emiter->getRadialAccelerationVar());
		m_ui->m_eg_speedValue->setValue(emiter->getSpeed());
		m_ui->m_eg_speedVar->setValue(emiter->getSpeedVar());
		m_ui->m_eg_tangentialAccelValue->setValue(emiter->getTangentialAcceleration());
		m_ui->m_eg_tangentialAccelVar->setValue(emiter->getTangentialAccelerationVar());


		/* radius mode */



	}
	else 
	{
        this->setEnabled(false);
	}


}

void MpEnvironmentSettingWidget::setEvnMode(int mode)
{
	if(mode==MP_MODEL_GRAVITY)
	{
		m_ui->m_modeSelect->setCurrentIndex(0);
		m_ui->m_stackWidget->setCurrentIndex(0);
		MpGlobal::attrOperator()->onSetEnvMode(Particle2DEmitter::ENV_GRAVITY);

	}
	else 
	{
		m_ui->m_modeSelect->setCurrentIndex(1);
		m_ui->m_stackWidget->setCurrentIndex(1);
		MpGlobal::attrOperator()->onSetEnvMode(Particle2DEmitter::ENV_RADIAL);
	}
}


void MpEnvironmentSettingWidget::slotSelectModeChange(int index)
{
	if(index==MP_MODEL_GRAVITY)
	{
		m_ui->m_stackWidget->setCurrentIndex(0);
		MpGlobal::attrOperator()->onSetEnvMode(Particle2DEmitter::ENV_GRAVITY);
	}
	else 
	{
		m_ui->m_stackWidget->setCurrentIndex(1);
		MpGlobal::attrOperator()->onSetEnvMode(Particle2DEmitter::ENV_RADIAL);
	}


}
















