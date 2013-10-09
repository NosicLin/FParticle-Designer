#include "widget/MpProjectExploreModel.h"
#include "MpGlobal.h"
#include "core/MpProject.h"
#include "core/MpParticleEffect.h"

MpProjectExploreModel::MpProjectExploreModel()
{
}
MpProjectExploreModel::~MpProjectExploreModel()
{
}

QModelIndex MpProjectExploreModel::index(int row,int column,
        const QModelIndex& parent)const
{
	MpProject* proj=MpGlobal::getCurProject();
	if(!proj)
	{
		return QModelIndex();
	}

	if(!parent.isValid())
	{
		return createIndex(row,column,proj);
	}

    MpIdentify* idfier=(MpIdentify*)parent.internalPointer();
	switch(idfier->getClassType())
	{
		case MP_PROJECT:
			{
				MpProject* proj=(MpProject*)idfier;
                MpParticleEffect* effect=proj->getParticleEffect(row);
				return createIndex(row,column,effect);
			}
	}

	return  QModelIndex();
}


QModelIndex MpProjectExploreModel::parent(const QModelIndex& child)const 
{
	if(!child.isValid())
	{
		return QModelIndex();
	}
	MpIdentify* idfier=(MpIdentify*)child.internalPointer();

	switch(idfier->getClassType())
	{
		case MP_PROJECT:
			{
				return QModelIndex();
			}
		case MP_PARTICLE:
			{
				MpProject* proj=((MpParticleEffect*)idfier)->getProject();
				return createIndex(0,0,proj);
			}
	}
	return QModelIndex();
}


int MpProjectExploreModel::rowCount(const QModelIndex& parent)const
{
	if(parent.column()>0)
	{
		return 0;
	}

	if(!parent.isValid())
	{
		return  1;
	}

    MpIdentify* idfier=(MpIdentify*) parent.internalPointer();

	switch(idfier->getClassType())
	{
		case MP_PROJECT:
			{
				MpProject* proj=(MpProject*)idfier;
                return proj->getParticleEffectNu();
			}
	}
	return 0;
}

int MpProjectExploreModel::columnCount(const QModelIndex& /*parent*/)const
{
	return 1;
}


QVariant MpProjectExploreModel::data(const QModelIndex& index,int role)const
{

	if(!index.isValid())
	{
		return QVariant();
	}

    MpIdentify* idfier=(MpIdentify*)index.internalPointer();
	switch(role)
	{
		case Qt::DisplayRole:
			{
				switch(idfier->getClassType())
				{
					case MP_PROJECT:
						{
							MpProject* proj=(MpProject*)idfier;
                            return QString(proj->getName().c_str());
						}
					case MP_PARTICLE:
						{
                            MpParticleEffect* effect= (MpParticleEffect*) idfier;
							return QString(effect->getName().c_str());
						}

				}

			}
	}

    return QVariant();

}

void MpProjectExploreModel::refresh()
{
	emit layoutChanged();
}











