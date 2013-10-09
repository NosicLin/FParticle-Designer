#include <QMainWindow>
#include <QApplication>
#include <QDockWidget>
#include "widget/MpEmitterSettingWidget.h"
#include "widget/MpParticleSettingWidget.h"
#include "widget/MpParticleViewWidget.h"
#include "widget/MpTextureSettingWidget.h"
#include "widget/MpEnvironmentSettingWidget.h"
#include "widget/MpMainWindow.h"


#include "core/MpProject.h"

#include "MpMsgCenter.h"
#include "MpGlobal.h"
#include "test.h"

#define WIDGET_HEIGHT 295
int main(int argc, char *argv[])
{
    QApplication a(argc, argv);




    MpMainWindow win;

    /* show window */
    win.showMaximized();
    win.show();

	MpParticleEffect* effect1=createMpParticleEffect("file.fpl");
	MpParticleEffect* effect2=createMpParticleEffect("ballfire.fpl");

    MpProject* proj=new MpProject;
    MpGlobal::setCurProject(proj);
    proj->setName("Runner");

    MpGlobal::getCurProject()->addParticleEffect(effect1);
	MpGlobal::getCurProject()->addParticleEffect(effect2);

    MpGlobal::getCurProject()->setCurParticleEffect(effect1);

    effect1->getParticleEffect()->start();
	effect2->getParticleEffect()->start();

	MpGlobal::msgCenter()->emitCurParticleEffectChange();

    return a.exec();
}










