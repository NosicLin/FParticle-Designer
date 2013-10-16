#include <QtGlobal>
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
#include "operator/MpIoOperator.h"
#include "util/MpPathUtil.h"

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

    qDebug("ExePath=%s",argv[0]);

	if(argc==1)
	{
    	MpOperator::data()->setCurProject(NULL);
	}
	else 
	{
		const char* filename=argv[1];

		std::string dir_name=MpPathUtil::dirName(filename);
		std::string file_name=MpPathUtil::baseName(filename);

		std::string vfs_root;

		if(dir_name=="")
		{
			vfs_root="./";
		}
		else 
		{
			vfs_root=dir_name+"/";
		}


		VFS::setRoot(vfs_root.c_str());
		MpProject* proj=MpOperator::io()->loadProject(filename);

		if(proj)
		{
			proj->setDir(dir_name.c_str());
			proj->setName(file_name.c_str());
			MpOperator::data()->setCurProject(proj);
		}
		else 
		{
			MpOperator::data()->setCurProject(NULL);
		}
	}
	return a.exec();
}


























