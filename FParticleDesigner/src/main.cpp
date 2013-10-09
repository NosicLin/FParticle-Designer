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

	MpGlobal_ModuleInit();
    MpGlobal::m_project=new MpProject;

    MpMainWindow win;

    /* show window */
    win.showMaximized();
    win.show();

	MpParticleEffect*  effect=createMpParticleEffect();

    MpGlobal::getCurProject()->addParticleEffect(effect);
    MpGlobal::getCurProject()->setCurParticleEffect(effect);

    effect->getParticleEffect()->start();
	MpGlobal::msgCenter()->emitCurParticleEffectChange();

    return a.exec();
}






