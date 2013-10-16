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
#include "util/SdRenderUtil.h"

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

    /* for fix function pipeline */
    SdRenderUtil::setProjectionMatrix(&mat);

}

void MpParticleViewWidget::paintGL()
{

	Global::render()->setClearColor(Color::BLACK);
	Global::render()->clear();

    MpParticleEffect* mp_effect=MpGlobal::getCurMpParticleEffect();
	if(!mp_effect)
	{
        renderText(20,20,"Particle: No Active");
        return ;
    }


    Particle2DEffect* effect=mp_effect->getParticleEffect();

	float vx=effect->getPositionX();
	float vy=effect->getPositionY();

	QSize s=size();

    Vector2 minpos=toEditCoord(Vector2(0,s.height()));
    Vector2 maxpos=toEditCoord(Vector2(s.width(),0));


    minpos=minpos+Vector2(vx,vy);
    maxpos=maxpos+Vector2(vx,vy);



    SdRenderUtil::drawLine(Vector2(-1000000,vy),Vector2(1000000,vy),1,Color::RED);
    SdRenderUtil::drawLine(Vector2(vx,-1000000),Vector2(vx,100000),1,Color::BLUE);

    effect->draw(Global::render(),true);

    SdRenderUtil::drawLine(Vector2(vx,vy),Vector2(vx,vy),1,Color::WHITE);

    renderText(20,20,QString("").sprintf("Particle:%s",mp_effect->getName().c_str()));
	float life_time,elapse_time;

	life_time=effect->getLifeTime();
	elapse_time=effect->getElapseTime();

    renderText(20,40,QString("").sprintf("LifeTime:%.2f/%.2f (%.2f)",elapse_time,life_time,elapse_time/life_time));
	renderText(20,60,QString("").sprintf("CurrentParticle:%d",effect->getParticleNu()));
	renderText(20,80,QString("").sprintf("MaxParticle:%d",effect->getMaxParticleNu()));

	if(effect->isStop())
	{
		effect->start();
	}

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

    MpParticleEffect* mp_effect=MpGlobal::getCurMpParticleEffect();
	if(!mp_effect)
	{
        return ;
	}
	Particle2DEffect* effect=mp_effect->getParticleEffect();
    effect->setPosition(pos.x,pos.y,0);
    update();


}

void MpParticleViewWidget::mouseMoveEvent(QMouseEvent* event)
{
    Vector2 pos=toEditCoord(Vector2(event->x(),event->y()));

    MpParticleEffect* mp_effect=MpGlobal::getCurMpParticleEffect();
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
 //   m_timer->start(16);

    MpParticleEffect* mp_effect=MpGlobal::getCurMpParticleEffect();
	if(!mp_effect)
	{
		return ;
	}
	Particle2DEffect* effect=mp_effect->getParticleEffect();

    effect->update(16.0f/1000.0f);
	update();
}





























