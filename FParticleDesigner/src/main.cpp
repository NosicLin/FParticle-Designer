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
#include "operator/MpDataOperator.h"
#include "operator/MpOperator.h"

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
    MpOperator::data()->setCurProject(NULL);

    return a.exec();
}










