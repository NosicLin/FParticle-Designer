#include <QtGlobal>
#include <QApplication>
#include <QVBoxLayout>

#include "widget/MpProjectExploreWidget.h"
#include "widget/MpProjectExploreModel.h"
#include "MpGlobal.h"
#include "MpMsgCenter.h"
#include "core/MpIdentify.h"
#include "operator/MpDataOperator.h"
#include "operator/MpUiOperator.h"
#include "operator/MpOperator.h"


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
	ma_exportParticle=mn_particle->addAction("Export Particle");
	ma_deleteParticle=mn_particle->addAction("Delete Particle");

}

void MpProjectExploreWidget::initWidget()
{
	/* view */
	m_projectExploreView=new QTreeView(this);
	m_projectExploreView->setHeaderHidden(true);
	m_projectExploreView->collapseAll();

	/* model */
	m_projectExploreModel=new MpProjectExploreModel();
	m_projectExploreView->setModel(m_projectExploreModel);


	QVBoxLayout* vlayout=new QVBoxLayout;
    vlayout->addWidget(m_projectExploreView);
	setLayout(vlayout);

}


void MpProjectExploreWidget::connectSignal()
{

    connect(MpGlobal::msgCenter(),SIGNAL(signalCurParticleEffectChange()),
			this,SLOT(slotCurParticleEffectChange()));

    connect(MpGlobal::msgCenter(),SIGNAL(signalCurProjectChange()),
			this,SLOT(slotCurProjectChange()));

    connect(MpGlobal::msgCenter(),SIGNAL(signalParticleEffectAttrChange(MpParticleEffect*)),
			this,SLOT(slotParticleEffectAttrChange(MpParticleEffect*)));

	connect(MpGlobal::msgCenter(),SIGNAL(signalRemoveParticleEffect(MpParticleEffect* )),
			this,SLOT(slotRemoveParticleEffect(MpParticleEffect* )));


	connect(MpGlobal::msgCenter(),SIGNAL(signalAddParticleEffect(MpParticleEffect*)),this,SLOT(slotRemoveParticleEffect(MpParticleEffect*)));

    connect(m_projectExploreView,SIGNAL(pressed(const QModelIndex&)),
			this, SLOT(slotMousePress(const QModelIndex&)));



	/* project */
    connect(ma_newParticle,SIGNAL(triggered()),MpOperator::ui(), SLOT(newParticle()));

	/* particle */
	connect(ma_renameParticle,SIGNAL(triggered()),MpOperator::ui(),SLOT(renameParticle()));
	connect(ma_deleteParticle,SIGNAL(triggered()),MpOperator::ui(),SLOT(removeParticle()));

	connect(ma_exportAll,SIGNAL(triggered()),MpOperator::ui(),SLOT(exportAllParticleEffect()));

}

void MpProjectExploreWidget::slotCurProjectChange()
{
	m_projectExploreView->reset();
    m_projectExploreModel->refresh();
}


void MpProjectExploreWidget::slotCurParticleEffectChange()
{
    m_projectExploreModel->refresh();
}

void MpProjectExploreWidget::slotParticleEffectAttrChange(MpParticleEffect* /* effect */)
{
	m_projectExploreModel->refresh();
}

void MpProjectExploreWidget::slotRemoveParticleEffect(MpParticleEffect*  effect )
{
	m_projectExploreModel->refresh();
}


void MpProjectExploreWidget::slotMousePress(const QModelIndex& index)
{
	if(!index.isValid())
	{
		return ;
    }

    MpIdentify* idfier=(MpIdentify*) index.internalPointer();
    switch(idfier->getClassType())
    {
        case MP_PARTICLE:
        {
			MpOperator::data()->setCurParticleEffect((MpParticleEffect*)idfier);
        }
    }

    if((QApplication::mouseButtons()&Qt::RightButton))
    {
		switch(idfier->getClassType())
		{
			case MP_PROJECT:
				{
					mn_project->popup(QCursor::pos());
					break;
				}
			case MP_PARTICLE:
				{
					mn_particle->popup(QCursor::pos());
					break;
				}
		}
	}




}
























