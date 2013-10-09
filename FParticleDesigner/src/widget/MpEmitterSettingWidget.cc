#include <QtGlobal>
#include "widget/MpEmitterSettingWidget.h"
#include "operator/MpAttrOperator.h"
#include "MpGlobal.h"
#include "MpMsgCenter.h"


MpEmitterSettingWidget::MpEmitterSettingWidget(QWidget* parent)
    :QWidget(parent)
{
	init();
}

MpEmitterSettingWidget::~MpEmitterSettingWidget()
{
}

void MpEmitterSettingWidget::init()
{
	m_ui=new Ui_emitter;
    m_ui->setupUi(this) ;

    connectSignal();
}


void MpEmitterSettingWidget::connectSignal()
{
    MpAttrOperator* attr=MpGlobal::attrOperator();

	connect(m_ui->m_e_emitSpeed,SIGNAL(valueChanged(int)),
			attr,SLOT(onSetEmitterSpeed(int )));
	connect(m_ui->m_e_lifeTimeMax,SIGNAL(valueChanged(double)),
			attr,SLOT(onSetDurationTime(double)));
	connect(m_ui->m_e_lifeTimeVar,SIGNAL(valueChanged(double)),
			attr,SLOT(onSetDurationTimeVar(double)));
	connect(m_ui->m_e_maxParticle,SIGNAL(valueChanged(int)),
            attr,SLOT(onSetMaxParticleNu(int)));


	connect(MpGlobal::msgCenter(),SIGNAL(signalCurParticleEffectChange()),this,SLOT(onCurParticleEffectChange()));

}

void MpEmitterSettingWidget::onCurParticleEffectChange()
{
    Particle2DEmitter* emiter=MpGlobal::getCurParticle2DEmitter();

	if(emiter)
	{
		this->setEnabled(true);
		m_ui->m_e_emitSpeed->setValue(emiter->getEmitSpeed());
		m_ui->m_e_lifeTimeMax->setValue(emiter->getDurationTime());
		m_ui->m_e_lifeTimeVar->setValue(emiter->getDurationTimeVar());
		m_ui->m_e_maxParticle->setValue(emiter->getMaxParticleNu());
	}
	else 
	{
		this->setEnabled(false);
	}



}


























