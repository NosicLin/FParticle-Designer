#ifndef _MP_UI_OPERATOR_H_
#define _MP_UI_OPERATOR_H_
#include <QObject>

class MpUiOperator:public QObject
{
    Q_OBJECT
	public slots:

		void newParticle();
		void renameParticle();

		void exportParticleEffect();
		void exportAllParticleEffect();

		void removeParticle();

		/* project */
		void newProject();
		void loadProject();
		void saveProject();
		void closeProject();

		/* texture */
		void setTexture();
};


#endif /*_MP_UI_OPERATOR_H_*/

