#include "operator/MpOperator.h"
#include "operator/MpUiOperator.h"
#include "operator/MpAttrOperator.h"
#include "core/MpParticleEffect.h"
#include "MpGlobal.h"
#include "MpMsgCenter.h"

#include "graphics/FsRender.h"


#include "widget/MpTextureSettingWidget.h"

static int S_BlendFactorMpToFs(int index)
{
    switch(index)
    {
        case MP_BLEND_ZERO: return Render::FACTOR_ZERO;
        case MP_BLEND_ONE: return Render::FACTOR_ONE;

        case MP_BLEND_SRC_COLOR: return Render::FACTOR_SRC_COLOR;
        case MP_BLEND_ONE_MINUS_SRC_COLOR:return Render::FACTOR_ONE_MINUS_SRC_COLOR;

        case MP_BLEND_DST_COLOR: return Render::FACTOR_DST_COLOR;
        case MP_BLEND_ONE_MINUS_DST_COLOR:return Render::FACTOR_ONE_MINUS_DST_COLOR;

        case MP_BLEND_SRC_ALPHA: return Render::FACTOR_SRC_ALPHA;
        case MP_BLEND_ONE_MINUS_SRC_ALPHA: return Render::FACTOR_ONE_MINUS_SRC_ALPHA;

        case MP_BLEND_DST_ALPHA: return Render::FACTOR_DST_ALPHA;
        case MP_BLEND_ONE_MINUS_DST_ALPHA: return Render::FACTOR_ONE_MINUS_DST_ALPHA;

        case MP_BLEND_SRC_ALPHA_SATURATE: return Render::FACTOR_SRC_ALPHA_SATURATE;
    }

    assert(0);
    return 0;
}


static int S_BlendFactorFsToMp(int index)
{
    switch(index)
    {
        case Render::FACTOR_ZERO: return MP_BLEND_ZERO;
        case Render::FACTOR_ONE: return MP_BLEND_ONE;
        case Render::FACTOR_SRC_COLOR: return MP_BLEND_SRC_COLOR;
        case Render::FACTOR_ONE_MINUS_SRC_COLOR: return MP_BLEND_ONE_MINUS_SRC_COLOR;
        case Render::FACTOR_DST_COLOR: return MP_BLEND_DST_COLOR;
        case Render::FACTOR_ONE_MINUS_DST_COLOR: return MP_BLEND_ONE_MINUS_DST_COLOR;
        case Render::FACTOR_SRC_ALPHA: return MP_BLEND_SRC_ALPHA;
        case Render::FACTOR_ONE_MINUS_SRC_ALPHA: return MP_BLEND_ONE_MINUS_SRC_ALPHA;
        case Render::FACTOR_DST_ALPHA: return MP_BLEND_DST_ALPHA;
        case Render::FACTOR_ONE_MINUS_DST_ALPHA: return MP_BLEND_ONE_MINUS_DST_ALPHA;
        case Render::FACTOR_SRC_ALPHA_SATURATE: return MP_BLEND_SRC_ALPHA_SATURATE;
    }
    assert(0);
    return 0;
}


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
    Particle2DEmitter* emiter=MpGlobal::getCurParticle2DEmitter();


	if(effect)
	{

		this->setEnabled(true);
		m_ui->m_t_imagePath->setText(effect->getTexturePath().c_str());

		int blend_src=emiter->getBlendSrc();
		int blend_dst=emiter->getBlendDst();

		m_ui->m_c_blendSrc->setCurrentIndex(S_BlendFactorFsToMp(blend_src));
		m_ui->m_c_blendDst->setCurrentIndex(S_BlendFactorFsToMp(blend_dst));

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




void MpTextureSettingWidget::setBlendSrc(int index)
{
	m_ui->m_c_blendSrc->setCurrentIndex(index);
    MpOperator::attr()->onSetBlendSrc(S_BlendFactorMpToFs(index));

}

void MpTextureSettingWidget::setBlendDst(int index)
{
	m_ui->m_c_blendDst->setCurrentIndex(index);
    MpOperator::attr()->onSetBlendDst(S_BlendFactorMpToFs(index));
}


void MpTextureSettingWidget::slotBlendSrcChange(int index)
{
    MpOperator::attr()->onSetBlendSrc(S_BlendFactorMpToFs(index));
}


void MpTextureSettingWidget::slotBlendDstChange(int index)
{
    MpOperator::attr()->onSetBlendDst(S_BlendFactorMpToFs(index));
}






void MpTextureSettingWidget::connectSignal()
{
	connect(m_ui->m_b_browse,SIGNAL(clicked()),this,SLOT(slotOnSetTexture()));
	connect(MpGlobal::msgCenter(),SIGNAL(signalCurParticleEffectChange()),this,SLOT(slotCurParticleEffectChange()));
    connect(MpGlobal::msgCenter(),SIGNAL(signalCurProjectChange()),this,SLOT(slotCurProjectChange()));

    connect(m_ui->m_c_blendSrc,SIGNAL(currentIndexChanged(int)),this,SLOT(slotBlendSrcChange(int)));
    connect(m_ui->m_c_blendDst,SIGNAL(currentIndexChanged(int)),this,SLOT(slotBlendDstChange(int)));


}








