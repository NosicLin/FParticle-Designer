#ifndef _MP_PROJECT_EXPLORE_WIDGET_H_
#define _MP_PROJECT_EXPLORE_WIDGET_H_

#include <QWidget>
#include <QTreeView>
#include <QMenu>
#include <QAction>


class MpProjectExploreModel;


class  MpProjectExploreWidget:public QWidget 
{
	public:
		MpProjectExploreWidget();
		~MpProjectExploreWidget();

	protected:
		void initMenu();
		void initWidget();
		void connectSignal();


	private:
		QTreeView* m_projectExploreView;
		MpProjectExploreModel* m_projectExploreModel;


	private: /* menu */

		/* project */
		QMenu* mn_project;
		QAction* ma_newParticle;
		QAction* ma_exportAll;

		/* particle */
		QMenu* mn_particle;
		QAction* ma_renameParticle;
		QAction* ma_exportParticle;
		QAction* ma_deleteParticle;


};



#endif /*_MP_PROJECT_EXPLORE_WIDGET_H_*/

