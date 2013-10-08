#include <QMainWindow>
#include <QApplication>
#include <QDockWidget>
#include "widget/MpEmitterSettingWidget.h"
#include "widget/MpParticleSettingWidget.h"
#include "widget/MpParticleViewWidget.h"
#include "widget/MpTextureSettingWidget.h"
#include "widget/MpEnvironmentSettingWidget.h"


#include "core/MpProject.h"

#include "MpMsgCenter.h"
#include "MpGlobal.h"
#include "test.h"

#define WIDGET_HEIGHT 295
int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    QMainWindow win;

	MpGlobal_ModuleInit();
    MpGlobal::m_project=new MpProject;

    /* emmiter setting */
    MpEmitterSettingWidget* emiter_setting_widget=new MpEmitterSettingWidget;
    QDockWidget* emmiter_setting_dock=new QDockWidget(QString("Emitter"));
    emmiter_setting_dock->setWidget(emiter_setting_widget);
    emmiter_setting_dock->setFixedSize(WIDGET_HEIGHT,140);

    /* particle setting */
    MpParticleSettingWidget* particle_setting_widget=new MpParticleSettingWidget;
    QDockWidget* particle_setting_dock=new QDockWidget(QString("Particle"));
    particle_setting_dock->setWidget(particle_setting_widget);
    particle_setting_dock->setFixedSize(WIDGET_HEIGHT,410);

    /* texture setting */
    MpTextureSettingWidget* texture_setting_widget=new MpTextureSettingWidget;
    QDockWidget* texture_setting_dock=new QDockWidget(QString("Texture"));
    texture_setting_dock->setWidget(texture_setting_widget);
    texture_setting_dock->setFixedSize(WIDGET_HEIGHT,219);

    /* environment setting */
    MpEnvironmentSettingWidget* environment_setting_widget=new  MpEnvironmentSettingWidget;
    QDockWidget* environment_setting_dock=new QDockWidget(QString("Environment"));
    environment_setting_dock->setWidget(environment_setting_widget);
    environment_setting_dock->setFixedSize(WIDGET_HEIGHT,270);


    /* dock widget */
    win.addDockWidget(Qt::LeftDockWidgetArea,emmiter_setting_dock);
    win.addDockWidget(Qt::LeftDockWidgetArea,particle_setting_dock);
    win.addDockWidget(Qt::LeftDockWidgetArea,environment_setting_dock);
    win.addDockWidget(Qt::RightDockWidgetArea,texture_setting_dock);

    /* view widget */
    MpParticleViewWidget* view=new MpParticleViewWidget;

    win.setCentralWidget(view);

	
	/* test */




    /* show window */
    win.showMaximized();
    win.show();

	MpParticleEffect*  effect=createMpParticleEffect();

	MpGlobal::project()->addParticleEffect(effect);
    MpGlobal::project()->setCurParticleEffect(effect);

    effect->getParticleEffect()->start();
	MpGlobal::msgCenter()->emitCurParticleEffectChange();

    return a.exec();
}






