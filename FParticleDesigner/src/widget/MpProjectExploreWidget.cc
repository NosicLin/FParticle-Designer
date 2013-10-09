#include <QVBoxLayout>
#include "widget/MpProjectExploreWidget.h"
#include "widget/MpProjectExploreModel.h"


MpProjectExploreWidget::MpProjectExploreWidget()
{
	initWidget();
	initMenu();
	connectSignal();
}

MpProjectExploreWidget::~MpProjectExploreWidget()
{
}


void MpProjectExploreWidget::initMenu()
{
	/* project */
	mn_project= new QMenu(this);
	ma_newParticle=mn_project->addAction("New Particle");
	ma_exportAll=mn_project->addAction("Export All");

	/* particle */
	mn_particle= new QMenu(this);
	ma_renameParticle=mn_particle->addAction("Rename Particle");
	ma_exportParticle=mn_project->addAction("Export Particle");
	ma_deleteParticle=mn_project->addAction("Delete Particle");

}

void MpProjectExploreWidget::initWidget()
{
	/* view */
	m_projectExploreView=new QTreeView(this);
	m_projectExploreView->setHeaderHidden(true);
	m_projectExploreView->setIndentation(12);

	/* model */
	m_projectExploreModel=new MpProjectExploreModel();



	m_projectExploreView->setModel(m_projectExploreModel);

	QVBoxLayout* vlayout=new QVBoxLayout;
    vlayout->addWidget(m_projectExploreView);
	setLayout(vlayout);

}


void MpProjectExploreWidget::connectSignal()
{

}












