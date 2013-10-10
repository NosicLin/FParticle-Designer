#ifndef _MP_UI_OPERATOR_H_
#define _MP_UI_OPERATOR_H_
#include <QObject>


class MpUiOperator:public QObject
{
    Q_OBJECT

	public slots:
		void newParticle();
		void renameParticle();
		void exportAll();
		void removeParticle();
};


#endif /*_MP_UI_OPERATOR_H_*/

