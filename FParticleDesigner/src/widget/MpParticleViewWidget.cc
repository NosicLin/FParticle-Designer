#include "GL/glew.h"
#include <QtGlobal>
#include <QMouseEvent>
#include "widget/MpParticleViewWidget.h"
#include "sys/io/FsVFS.h"
#include "graphics/FsRender.h"
#include "FsGlobal.h"
#include "core/MpParticleEffect.h"
#include "MpGlobal.h"

#include "core/MpProject.h"

#include "MpMsgCenter.h"
#include "MpGlobal.h"


MpParticleViewWidget::MpParticleViewWidget()
{
    m_timer=new QTimer(this);
    connect(m_timer,SIGNAL(timeout()),this,SLOT(timerUpdate()));
    m_timer->start(16);
}



MpParticleViewWidget::~MpParticleViewWidget()
{

}




void MpParticleViewWidget::initializeGL()
{
	if(glewInit()!=GLEW_OK)
	{
		FS_TRACE_WARN("Create Glew Failed");
	}

	VFS::moduleInit();

    Render* render=Render::create();
    Global::setRender(render);

    TextureMgr* tex_mgr=TextureMgr::create();
    Global::setTextureMgr(tex_mgr);


    FontTTFDataMgr* font_mgr=FontTTFDataMgr::create();
    Global::setFontTTFDataMgr(font_mgr);




}


void MpParticleViewWidget::resizeGL(int width,int height)
{
	Matrix4 mat;
    mat.makeOrthographic(-width/2,width/2,-height/2,height/2,-100,100);
    Global::render()->setProjectionMatrix(&mat);
	Global::render()->setViewport(0,0,width,height);
}

void MpParticleViewWidget::paintGL()
{

	Global::render()->setClearColor(Color::BLACK);
	Global::render()->clear();

	MpParticleEffect* mp_effect=MpGlobal::curMpParticleEffect();
	if(!mp_effect)
	{
		return ;
	}
	Particle2DEffect* effect=mp_effect->getParticleEffect();
	effect->draw(Global::render(),true);
}


Vector2 MpParticleViewWidget::toWidgetCoord(Vector2 v)
{
	float rx=v.x;
	float ry=v.y;
	QSize  wsize=size();
	rx=rx+wsize.width()/2;
	ry=wsize.height()/2-ry;

	Vector2 ret;
	ret.x=rx;
	ret.y=ry;
	return ret;
}


Vector2 MpParticleViewWidget::toEditCoord(Vector2 v)
{
	float rx=v.x;
	float ry=v.y;
	QSize wsize=size();

	rx=rx-wsize.width()/2;
	ry=wsize.height()/2-ry;

	Vector2 ret;
	ret.x=rx;
	ret.y=ry;
	return ret;
}


void MpParticleViewWidget::mousePressEvent(QMouseEvent* event)
{
	Vector2 pos=toEditCoord(Vector2(event->x(),event->y()));

	MpParticleEffect* mp_effect=MpGlobal::curMpParticleEffect();
	if(!mp_effect)
	{
        return ;
	}
	Particle2DEffect* effect=mp_effect->getParticleEffect();
    effect->setPosition(pos.x,pos.y,0);
    update();


}

void MpParticleViewWidget::timerUpdate()
{
    m_timer->start(16);

	MpParticleEffect* mp_effect=MpGlobal::curMpParticleEffect();
	if(!mp_effect)
	{
		return ;
	}
	Particle2DEffect* effect=mp_effect->getParticleEffect();

	effect->update(16.0f/1000.0f);
	update();
}

















