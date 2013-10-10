#ifndef _MP_PROJECT_EXPLORE_WIDGET_H_
#define _MP_PROJECT_EXPLORE_WIDGET_H_

#include <QWidget>
#include <QTreeView>
#include <QMenu>
#include <QAction>

class MpProjectExploreModel;
class MpParticleEffect;

class  MpProjectExploreWidget:public QWidget 
{
	Q_OBJECT
	public:
		MpProjectExploreWidget();
		~MpProjectExploreWidget();

	public slots:
		void slotMousePress(const QModelIndex& );

		void slotCurParticleEffectChange();
		void slotCurProjectChange();
		void slotParticleEffectAttrChange(MpParticleEffect* effect);
		void slotRemoveParticleEffect(MpParticleEffect* effect);


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






