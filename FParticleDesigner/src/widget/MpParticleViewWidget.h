#ifndef _MP_PARTICLE_VIEW_WIDGET_H_
#define _MP_PARTICLE_VIEW_WIDGET_H_

#include <QGLWidget>
#include <QTimer>

#include "math/FsVector2.h"


NS_FS_USE

class MpParticleViewWidget:public QGLWidget
{
	Q_OBJECT
	public:
		virtual void initializeGL();
		virtual void resizeGL(int width,int height);

		/* override QGLWidget */
		virtual void paintGL();

	public:
		virtual void mousePressEvent(QMouseEvent* event);

	public slots:
		void timerUpdate();



	public:
		Vector2 toWidgetCoord(Vector2 v);
		Vector2 toEditCoord(Vector2 v);

	public:
		MpParticleViewWidget();
		~MpParticleViewWidget();

	private:
		QTimer* m_timer;


};



#endif /*_MP_PARTICLE_VIEW_WIDGET_H_*/


