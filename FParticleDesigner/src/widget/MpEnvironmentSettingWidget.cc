#include "widget/MpEnvironmentSettingWidget.h"
#include "MpGlobal.h"
#include "operator/MpAttrOperator.h"
#include "operator/MpOperator.h"
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
    MpAttrOperator* attr=MpOperator::attr();

	/* gravity */
	connect(m_ui->m_eg_speedValue,SIGNAL(valueChanged(double)),attr,SLOT(onSetSpeed(double)));
	connect(m_ui->m_eg_speedVar,SIGNAL(valueChanged(double)),attr,SLOT(onSetSpeedVar(double)));

	connect(m_ui->m_eg_gravityXValue,SIGNAL(valueChanged(double)),attr,SLOT(onSetGravityX(double)));
	connect(m_ui->m_eg_gravityYValue,SIGNAL(valueChanged(double)),attr,SLOT(onSetGravityY(double)));
	connect(m_ui->m_eg_radialAccelValue,SIGNAL(valueChanged(double)),attr,SLOT(onSetRadialAcceleration(double)));
	connect(m_ui->m_eg_radialAccelVar,SIGNAL(valueChanged(double)),attr,SLOT(onSetRadialAccelerationVar(double)));
	connect(m_ui->m_eg_tangentialAccelValue,SIGNAL(valueChanged(double)),attr,SLOT(onSetTangentialAcceleration(double)));
	connect(m_ui->m_eg_tangentialAccelVar,SIGNAL(valueChanged(double)),attr,SLOT(onSetTangentialAccelerationVar(double)));


	/* radius */

	connect(m_ui->m_er_endRadiusValue,SIGNAL(valueChanged(double)),attr,SLOT(onSetEndRadius(double)));
	connect(m_ui->m_er_endRadiusVar,SIGNAL(valueChanged(double)),attr,SLOT(onSetEndRadiusVar(double)));

	connect(m_ui->m_er_rotateSpeedValue,SIGNAL(valueChanged(double)),attr,SLOT(onSetRotateSpeed(double)));
	connect(m_ui->m_er_rotateSpeedVar,SIGNAL(valueChanged(double)),attr,SLOT(onSetRotateSpeedVar(double)));

	connect(m_ui->m_er_startRadiusValue,SIGNAL(valueChanged(double)),attr,SLOT(onSetStartRadius(double)));
	connect(m_ui->m_er_startRadiusVar,SIGNAL(valueChanged(double)),attr,SLOT(onSetStartRadiusVar(double)));


    connect(m_ui->m_modeSelect,SIGNAL(currentIndexChanged(int)),this,SLOT(slotSelectModeChange(int)));
	connect(MpGlobal::msgCenter(),SIGNAL(signalCurParticleEffectChange()),this,SLOT(slotCurParticleEffectChange()));
}


void MpEnvironmentSettingWidget::slotCurParticleEffectChange()
{

    Particle2DEmitter* emiter=MpGlobal::getCurParticle2DEmitter();

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
		m_ui->m_er_endRadiusValue->setValue(emiter->getEndRadius());
		m_ui->m_er_endRadiusVar->setValue(emiter->getEndRadiusVar());
		m_ui->m_er_rotateSpeedValue->setValue(emiter->getRotateSpeed());
		m_ui->m_er_rotateSpeedVar->setValue(emiter->getRotateSpeedVar());
		m_ui->m_er_startRadiusValue->setValue(emiter->getStartRadius());
        m_ui->m_er_startRadiusVar->setValue(emiter->getStartRadiusVar());


        if(emiter->getEnvironmentMode()==Particle2DEmitter::ENV_GRAVITY)
        {
            setEvnMode(MP_MODEL_GRAVITY);

        }
        else
        {
            setEvnMode(MP_MODEL_RADIUS);
        }
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
        MpOperator::attr()->onSetEnvMode(Particle2DEmitter::ENV_GRAVITY);

	}
	else 
	{
		m_ui->m_modeSelect->setCurrentIndex(1);
		m_ui->m_stackWidget->setCurrentIndex(1);
        MpOperator::attr()->onSetEnvMode(Particle2DEmitter::ENV_RADIAL);
	}
}


void MpEnvironmentSettingWidget::slotSelectModeChange(int index)
{
	if(index==MP_MODEL_GRAVITY)
	{
		m_ui->m_stackWidget->setCurrentIndex(0);
        MpOperator::attr()->onSetEnvMode(Particle2DEmitter::ENV_GRAVITY);
	}
	else 
	{
		m_ui->m_stackWidget->setCurrentIndex(1);
        MpOperator::attr()->onSetEnvMode(Particle2DEmitter::ENV_RADIAL);
	}


}
















