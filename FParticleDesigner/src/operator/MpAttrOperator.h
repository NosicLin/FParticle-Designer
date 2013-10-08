#ifndef _MP_ATTR_OPERATOR_H_
#define _MP_ATTR_OPERATOR_H_


namespace Faeris
{
    class Texture2D;
}


#include <QObject>
class MpAttrOperator :public QObject
{
    Q_OBJECT
	public:
        MpAttrOperator();

	public slots:
		void onSetDurationTime(double value);
		void onSetDurationTimeVar(double value);
		void onSetMaxParticleNu(int num);
		void onSetEmitterSpeed(int num);


		void onSetLifeTime(double value);
		void onSetLifeTimeVar(double value);
		void onSetStartSize(double value);
		void onSetStartSizeVar(double value);
		void onSetEndSize(double value);
		void onSetEndSizeVar(double value);
		/* start color */
		void onSetStartColorRed(int value);
		void onSetStartColorRedVar(int value);
		void onSetStartColorBlue(int value);
		void onSetStartColorBlueVar(int value);
		void onSetStartColorGreen(int value);
		void onSetStartColorGreenVar(int value);
		void onSetStartColorAlpha(int value);
		void onSetStartColorAlphaVar(int value);


		/* end color */
		void onSetEndColorRed(int value);
		void onSetEndColorRedVar(int value);
		void onSetEndColorGreen(int value);
		void onSetEndColorGreenVar(int value);
		void onSetEndColorBlue(int value);
		void onSetEndColorBlueVar(int value);
		void onSetEndColorAlpha(int value);
		void onSetEndColorAlphaVar(int value);


		/* angle */
		void onSetAngle(double value);
		void onSetAngleVar(double value);
		
		/* rotation */
		void onSetStartRotation(double value);
		void onSetStartRotationVar(double value);

		void onSetEndRotation(double value);
		void onSetEndRotationVar(double value);

		/* position */
		void onSetPositionX(double value);
		void onSetPositionXVar(double value);
		void onSetPositionY(double value);
		void onSetPositionYVar(double value);

		/* move mode */
		void onSetMoveMode(int value);

		/* blend */
		void onSetBlendSrc(int value);
		void onSetBlendDst(int value);
        void onSetTexture(Faeris::Texture2D* value);

		/* environment mode */
		void onSetEnvMode(int value);

		/* gravity mode*/
		void  onSetSpeed(double value);
		void onSetSpeedVar(double value);

		void onSetGravityX(double  value);
		void onSetGravityY(double value);
		void onSetRadialAcceleration(double value);
		void onSetRadialAccelerationVar(double value);
		void onSetTangentialAcceleration(double value);
		void onSetTangentialAccelerationVar(double value);

		/* radial mode */
		void onSetStartRadius(double value);
		void onSetStartRadiusVar(double value);

		void onSetEndRadius(double value);
		void onSetEndRadiusVar(double value);

		void onSetRotateSpeed(double value);
		void onSetRotateSpeedVar(double value);
};


#endif /*_MP_ATTR_OPERATOR_H_*/









