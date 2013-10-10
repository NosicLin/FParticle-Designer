#ifndef _MP_PROJECT_EXPLORE_MODEL_H_
#define _MP_PROJECT_EXPLORE_MODEL_H_ 
#include <QAbstractItemModel>

class MpParticleEffect;
class  MpProjectExploreModel:public QAbstractItemModel 
{
	Q_OBJECT 
	public:
		MpProjectExploreModel();
		~MpProjectExploreModel();

	public:
		virtual QModelIndex index(int row,int column,
						const QModelIndex& parent=QModelIndex())const ;

		virtual QModelIndex parent(const QModelIndex& child) const ;
		virtual int rowCount(const QModelIndex& parent=QModelIndex())const;
		virtual int columnCount(const QModelIndex& parent=QModelIndex())const;
		virtual QVariant data(const QModelIndex& index,int role=Qt::DisplayRole)const ;
	public:
        void refresh();
        void particleEffectRemove(MpParticleEffect* effect);
};




#endif /*_MP_PROJECT_EXPLORE_MODEL_H_*/

