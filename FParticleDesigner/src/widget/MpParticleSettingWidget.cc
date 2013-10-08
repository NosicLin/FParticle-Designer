#include "widget/MpParticleSettingWidget.h"
#include "operator/MpAttrOperator.h"
#include "MpGlobal.h"
#include "MpMsgCenter.h"



MpParticleSettingWidget::MpParticleSettingWidget()
{
	init();
}

MpParticleSettingWidget::~MpParticleSettingWidget()
{
}

void MpParticleSettingWidget::init()
{
	m_ui=new Ui_particle_setting;
	m_ui->setupUi(this);
	connectSignal();
}




void MpParticleSettingWidget::connectSignal()
{
	connect(MpGlobal::msgCenter(),SIGNAL(signalCurParticleEffectChange()),this,SLOT(slotCurParticleEffectChange()));

	
	MpAttrOperator* attr=MpGlobal::attrOperator();
	

	connect(m_ui->m_e_angleValue,SIGNAL(valueChanged(double)),
			attr,SLOT(onSetAngle(double)));

	connect(m_ui->m_e_angleVar,SIGNAL(valueChanged(double)),
		attr,SLOT(onSetAngleVar(double)));


    connect(m_ui->m_e_lifeTimeValue,SIGNAL(valueChanged(double)),attr,SLOT(onSetLifeTime(double)));

    connect(m_ui->m_e_lifeTimeVar,SIGNAL(valueChanged(double)),attr,SLOT(onSetLifeTimeVar(double)));


	connect(m_ui->m_e_positionXValue,SIGNAL(valueChanged(double)),attr,SLOT(onSetPositionX(double)));
    connect(m_ui->m_e_positionXVar,SIGNAL(valueChanged(double)),attr,SLOT(onSetPositionXVar(double)));


	connect(m_ui->m_e_positionYValue,SIGNAL(valueChanged(double)),attr,SLOT(onSetPositionY(double)));
	connect(m_ui->m_e_positionYVar,SIGNAL(valueChanged(double)),attr,SLOT(onSetPositionYVar(double)));

	connect(m_ui->m_e_rotateBeginValue,SIGNAL(valueChanged(double)),attr,SLOT(onSetStartRotation(double)));

	connect(m_ui->m_e_rotateBeginVar,SIGNAL(valueChanged(double)),attr,SLOT(onSetStartRotationVar(double)));

	
	connect(m_ui->m_e_rotateEndValue,SIGNAL(valueChanged(double)),attr,SLOT(onSetEndRotation(double)));

	connect(m_ui->m_e_rotateEndVar,SIGNAL(valueChanged(double)),attr,SLOT(onSetEndRotationVar(double)));

	connect(m_ui->m_e_sizeBeginValue,SIGNAL(valueChanged(double)),attr,SLOT(onSetStartSize(double)));
	connect(m_ui->m_e_sizeBeginVar,SIGNAL(valueChanged(double)),attr,SLOT(onSetStartSizeVar(double)));

	connect(m_ui->m_e_sizeEndValue,SIGNAL(valueChanged(double)),attr,SLOT(onSetEndSize(double)));
	connect(m_ui->m_e_sizeEndVar,SIGNAL(valueChanged(double)),attr,SLOT(onSetEndSizeVar(double)));

	/* start color */
    connect(m_ui->m_es_alphaValue,SIGNAL(valueChanged(int)),attr,SLOT(onSetStartColorAlpha(int)));
    connect(m_ui->m_es_alphaVar,SIGNAL(valueChanged(int)),attr,SLOT(onSetStartColorAlphaVar(int)));

    connect(m_ui->m_es_blueValue,SIGNAL(valueChanged(int)),attr,SLOT(onSetStartColorBlue(int)));
    connect(m_ui->m_es_blueVar,SIGNAL(valueChanged(int)),attr,SLOT(onSetStartColorBlueVar(int)));


    connect(m_ui->m_es_greenValue,SIGNAL(valueChanged(int)),attr,SLOT(onSetStartColorGreen(int)));
    connect(m_ui->m_es_greenVar,SIGNAL(valueChanged(int)),attr,SLOT(onSetStartColorGreenVar(int)));

    connect(m_ui->m_es_redValue,SIGNAL(valueChanged(int)),attr,SLOT(onSetStartColorRed(int)));
    connect(m_ui->m_es_redValue,SIGNAL(valueChanged(int)),attr,SLOT(onSetStartColorRedVar(int)));


	/* end color */
    connect(m_ui->m_ee_alphaValue,SIGNAL(valueChanged(int)),attr,SLOT(onSetEndColorAlpha(int)));
    connect(m_ui->m_ee_alphaVar,SIGNAL(valueChanged(int)),attr,SLOT(onSetEndColorAlphaVar(int)));

    connect(m_ui->m_ee_blueValue,SIGNAL(valueChanged(int)),attr,SLOT(onSetEndColorBlue(int)));
    connect(m_ui->m_ee_blueVar,SIGNAL(valueChanged(int)),attr,SLOT(onSetEndColorBlueVar(int)));


    connect(m_ui->m_ee_greenValue,SIGNAL(valueChanged(int)),attr,SLOT(onSetEndColorGreen(int)));
    connect(m_ui->m_ee_greenVar,SIGNAL(valueChanged(int)),attr,SLOT(onSetEndColorGreenVar(int)));

    connect(m_ui->m_ee_redValue,SIGNAL(valueChanged(int)),attr,SLOT(onSetEndColorRed(int)));
    connect(m_ui->m_ee_redValue,SIGNAL(valueChanged(int)),attr,SLOT(onSetEndColorRedVar(int)));







}

void MpParticleSettingWidget::slotCurParticleEffectChange()
{
	Particle2DEmitter* emiter=MpGlobal::curParticle2DEmitter();

	if(emiter)
	{
        this->setEnabled(true);
		m_ui->m_e_angleValue->setValue(emiter->getAngle());
		m_ui->m_e_angleVar->setValue(emiter->getAngleVar());
		m_ui->m_e_lifeTimeValue->setValue(emiter->getLifeTime());
		m_ui->m_e_lifeTimeVar->setValue(emiter->getLifeTimeVar());

		Vector2 pos=emiter->getPosition();
		Vector2 pos_var=emiter->getPositionVar();
		m_ui->m_e_positionXValue->setValue(pos.x);
		m_ui->m_e_positionXVar->setValue(pos_var.x);
		m_ui->m_e_positionYValue->setValue(pos.y);
		m_ui->m_e_positionYVar->setValue(pos_var.y);

        m_ui->m_e_rotateBeginValue->setValue(emiter->getStartRotation());
        m_ui->m_e_rotateBeginVar->setValue(emiter->getStartRotationVar());

        m_ui->m_e_rotateEndValue->setValue(emiter->getEndRotation());
        m_ui->m_e_rotateEndVar->setValue(emiter->getEndRotationVar());


        m_ui->m_e_sizeBeginValue->setValue(emiter->getStartSize());
        m_ui->m_e_sizeBeginVar->setValue(emiter->getStartSizeVar());
        m_ui->m_e_sizeEndValue->setValue(emiter->getEndSize());
        m_ui->m_e_sizeEndVar->setValue(emiter->getEndSizeVar());


		Color start_color=emiter->getStartColor();
		Color start_color_var=emiter->getStartColorVar();
		Color end_color=emiter->getEndColor();
        Color end_color_var=emiter->getEndColorVar();

		m_ui->m_es_redValue->setValue(start_color.r);
		m_ui->m_es_greenValue->setValue(start_color.g);
		m_ui->m_es_blueValue->setValue(start_color.b);
		m_ui->m_es_alphaValue->setValue(start_color.a);

		m_ui->m_es_redVar->setValue(start_color_var.r);
		m_ui->m_es_greenVar->setValue(start_color_var.g);
		m_ui->m_es_blueVar->setValue(start_color_var.b);
		m_ui->m_es_alphaVar->setValue(start_color_var.a);


		m_ui->m_ee_redValue->setValue(end_color.r);
		m_ui->m_ee_greenValue->setValue(end_color.g);
		m_ui->m_ee_blueValue->setValue(end_color.b);
		m_ui->m_ee_alphaValue->setValue(end_color.a);

		m_ui->m_ee_redVar->setValue(end_color_var.r);
		m_ui->m_ee_greenVar->setValue(end_color_var.g);
		m_ui->m_ee_blueVar->setValue(end_color_var.b);
		m_ui->m_ee_alphaVar->setValue(end_color_var.a);






	}
	else 
	{
        this->setEnabled(false);
	}

}









