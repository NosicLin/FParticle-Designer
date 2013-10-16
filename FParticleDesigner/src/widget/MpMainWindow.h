#ifndef _MP_MAIN_WIDGET_H_
#define _MP_MAIN_WIDGET_H_

#include <QDockWidget>
#include <QMainWindow>
#include <QMenu>
#include <QAction>
#include "widget/MpEmitterSettingWidget.h"
#include "widget/MpParticleSettingWidget.h"
#include "widget/MpParticleViewWidget.h"
#include "widget/MpTextureSettingWidget.h"
#include "widget/MpEnvironmentSettingWidget.h"
#include "widget/MpProjectExploreWidget.h"


class MpMainWindow:public QMainWindow 
{
	Q_OBJECT

	public:
		MpMainWindow();
		~MpMainWindow();

	public slots:
		void slotOnAbout();


    protected:
		void initMenuBar();
		void initWidget();
		void connectSignal();


	private: /* widget */
		/* emitter setting */
		MpEmitterSettingWidget* m_emitterSettingWidget;
		QDockWidget* m_emitterSettingDockWidget;

		/* particle setting */
		MpParticleSettingWidget* m_particleSettingWidget;
		QDockWidget* m_particleSettingDockWidget;


		/* texture setting */
		MpTextureSettingWidget* m_textureSettingWidget;
		QDockWidget* m_textureSettingDockWidget;


		/* environment setting */
		MpEnvironmentSettingWidget* m_environmentSettingWidget;
		QDockWidget* m_environmentSettingDockWidget;

		/* project explore */
		MpProjectExploreWidget* m_projectExploreWidget;
		QDockWidget* m_projectExploreDockWidget;


		/* particle view */
		MpParticleViewWidget* m_particleViewWidget;

	private: /* menu area */
	
		QMenuBar* m_menuBar;
		/* menu */
		QMenu* mn_file;
		QAction* ma_newProject;
		QAction* ma_openProject;
		QAction* ma_closeProject;
		QAction* ma_saveProject;
		QAction* ma_saveProjectAs;

		QAction* ma_newParticle;
		QAction* ma_exportParticle;
		QAction* ma_exportAll;
		QAction* ma_quit;


		/*  example */
		QMenu* mn_example;
		QAction* ma_fire;


		/*  about */
		QMenu*  mn_about;
		QAction* ma_aboutThis;
		QAction* ma_onlineTutorial;
};
#endif /*_MP_MAIN_WIDGET_H_*/


