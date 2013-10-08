#include "MpGlobal.h"
#include "operator/MpAttrOperator.h"
#include "graphics/FsTexture2D.h"


MpAttrOperator::MpAttrOperator()
{
}

void MpAttrOperator::onSetDurationTime(double value)
{
	Particle2DEmitter* emitter=MpGlobal::curParticle2DEmitter();
	if(emitter) 
	{
		emitter->setDurationTime(value);
	}
}

void MpAttrOperator::onSetDurationTimeVar(double value)
{
	Particle2DEmitter* emitter=MpGlobal::curParticle2DEmitter();
	if(emitter) 
	{
		emitter->setDurationTimeVar(value);
	}
}

void MpAttrOperator::onSetMaxParticleNu(int num)
{
	Particle2DEmitter* emitter=MpGlobal::curParticle2DEmitter();
	if(emitter) 
	{
		emitter->setMaxParticleNu(num);
	}
}

void MpAttrOperator::onSetEmitterSpeed(int num)
{
	Particle2DEmitter* emitter=MpGlobal::curParticle2DEmitter();
	if(emitter) 
	{
        emitter->setEmitSpeed(num);
	}
}

void MpAttrOperator::onSetLifeTime(double value)
{
	Particle2DEmitter* emitter=MpGlobal::curParticle2DEmitter();
	if(emitter) 
	{
		emitter->setLifeTime(value);
	}
}

void MpAttrOperator::onSetLifeTimeVar(double value)
{
	Particle2DEmitter* emitter=MpGlobal::curParticle2DEmitter();
	if(emitter) 
	{
		emitter->setLifeTimeVar(value);
	}
}



void MpAttrOperator::onSetStartSize(double value)
{
	Particle2DEmitter* emitter=MpGlobal::curParticle2DEmitter();
	if(emitter)
	{
		emitter->setStartSize(value);
	}
}

void MpAttrOperator::onSetStartSizeVar(double value)
{
	Particle2DEmitter* emitter=MpGlobal::curParticle2DEmitter();
	if(emitter)
	{
		emitter->setStartSizeVar(value);
	}
}

void MpAttrOperator::onSetEndSize(double value)
{
	Particle2DEmitter* emitter=MpGlobal::curParticle2DEmitter();
	if(emitter)
	{
		emitter->setEndSize(value);
	}
}

void MpAttrOperator::onSetEndSizeVar(double value)
{
	Particle2DEmitter* emitter=MpGlobal::curParticle2DEmitter();
	if(emitter)
	{
		emitter->setEndSizeVar(value);
	}
}

void MpAttrOperator::onSetStartColorRed(int value)
{
	Particle2DEmitter* emitter=MpGlobal::curParticle2DEmitter();
	if(emitter)
	{
		Color c=emitter->getStartColor();
		c.r=value;
		emitter->setStartColor(c);
	}
}

void MpAttrOperator::onSetStartColorRedVar(int value)
{
	Particle2DEmitter* emitter=MpGlobal::curParticle2DEmitter();
	if(emitter)
	{
		Color c=emitter->getStartColorVar();
		c.r=value;
		emitter->setStartColorVar(c);
	}
}



void MpAttrOperator::onSetStartColorGreen(int value)
{
	Particle2DEmitter* emitter=MpGlobal::curParticle2DEmitter();
	if(emitter)
	{
		Color c=emitter->getStartColor();
		c.g=value;
		emitter->setStartColor(c);
	}
}

void MpAttrOperator::onSetStartColorGreenVar(int value)
{
	Particle2DEmitter* emitter=MpGlobal::curParticle2DEmitter();
	if(emitter)
	{
		Color c=emitter->getStartColorVar();
		c.g=value;
		emitter->setStartColorVar(c);
	}
}


void MpAttrOperator::onSetStartColorBlue(int value)
{
	Particle2DEmitter* emitter=MpGlobal::curParticle2DEmitter();
	if(emitter)
	{
		Color c=emitter->getStartColor();
		c.b=value;
		emitter->setStartColor(c);
	}
}

void MpAttrOperator::onSetStartColorBlueVar(int value)
{
	Particle2DEmitter* emitter=MpGlobal::curParticle2DEmitter();
	if(emitter)
	{
		Color c=emitter->getStartColorVar();
		c.b=value;
		emitter->setStartColorVar(c);
	}
}


void MpAttrOperator::onSetStartColorAlpha(int value)
{
	Particle2DEmitter* emitter=MpGlobal::curParticle2DEmitter();
	if(emitter)
	{
		Color c=emitter->getStartColor();
		c.a=value;
		emitter->setStartColor(c);
	}
}

void MpAttrOperator::onSetStartColorAlphaVar(int value)
{
	Particle2DEmitter* emitter=MpGlobal::curParticle2DEmitter();
	if(emitter)
	{
		Color c=emitter->getStartColorVar();
		c.a=value;
		emitter->setStartColorVar(c);
	}
}



void MpAttrOperator::onSetEndColorRed(int value)
{
	Particle2DEmitter* emitter=MpGlobal::curParticle2DEmitter();
	if(emitter)
	{
		Color c=emitter->getEndColor();
		c.r=value;
		emitter->setEndColor(c);
	}
}

void MpAttrOperator::onSetEndColorRedVar(int value)
{
	Particle2DEmitter* emitter=MpGlobal::curParticle2DEmitter();
	if(emitter)
	{
		Color c=emitter->getEndColorVar();
		c.r=value;
		emitter->setEndColorVar(c);
	}
}

void MpAttrOperator::onSetEndColorGreen(int value)
{
	Particle2DEmitter* emitter=MpGlobal::curParticle2DEmitter();
	if(emitter)
	{
		Color c=emitter->getEndColor();
		c.g=value;
		emitter->setEndColor(c);
	}
}

void MpAttrOperator::onSetEndColorGreenVar(int value)
{
	Particle2DEmitter* emitter=MpGlobal::curParticle2DEmitter();
	if(emitter)
	{
		Color c=emitter->getEndColorVar();
		c.g=value;
		emitter->setEndColorVar(c);
	}
}



void MpAttrOperator::onSetEndColorBlue(int value)
{
	Particle2DEmitter* emitter=MpGlobal::curParticle2DEmitter();
	if(emitter)
	{
		Color c=emitter->getEndColor();
		c.b=value;
		emitter->setEndColor(c);
	}
}

void MpAttrOperator::onSetEndColorBlueVar(int value)
{
	Particle2DEmitter* emitter=MpGlobal::curParticle2DEmitter();
	if(emitter)
	{
		Color c=emitter->getEndColorVar();
		c.b=value;
		emitter->setEndColorVar(c);
	}
}



void MpAttrOperator::onSetEndColorAlpha(int value)
{
	Particle2DEmitter* emitter=MpGlobal::curParticle2DEmitter();
	if(emitter)
	{
		Color c=emitter->getEndColor();
		c.a=value;
		emitter->setEndColor(c);
	}
}

void MpAttrOperator::onSetEndColorAlphaVar(int value)
{
	Particle2DEmitter* emitter=MpGlobal::curParticle2DEmitter();
	if(emitter)
	{
		Color c=emitter->getEndColorVar();
		c.a=value;
		emitter->setEndColorVar(c);
	}
}

void MpAttrOperator::onSetAngle(double value)
{
	Particle2DEmitter* emitter=MpGlobal::curParticle2DEmitter();
	if(emitter)
	{
		emitter->setAngle(value);
	}
}

void MpAttrOperator::onSetAngleVar(double value)
{
	Particle2DEmitter* emitter=MpGlobal::curParticle2DEmitter();
	if(emitter)
	{
		emitter->setAngleVar(value);
	}
}


void MpAttrOperator::onSetStartRotation(double value)
{
	Particle2DEmitter* emitter=MpGlobal::curParticle2DEmitter();
	if(emitter)
	{
		emitter->setStartRotation(value);
	}
}


void MpAttrOperator::onSetStartRotationVar(double value)
{
	Particle2DEmitter* emitter=MpGlobal::curParticle2DEmitter();
	if(emitter)
	{
		emitter->setStartRotationVar(value);
	}
}


void MpAttrOperator::onSetEndRotation(double value)
{
	Particle2DEmitter* emitter=MpGlobal::curParticle2DEmitter();
	if(emitter)
	{
		emitter->setEndRotation(value);
	}
}

void MpAttrOperator::onSetEndRotationVar(double value)
{
	Particle2DEmitter* emitter=MpGlobal::curParticle2DEmitter();
	if(emitter)
	{
		emitter->setEndRotationVar(value);
	}
}

void MpAttrOperator::onSetPositionX(double value)
{
	Particle2DEmitter* emitter=MpGlobal::curParticle2DEmitter();
	if(emitter)
	{
		Vector2 pos=emitter->getPosition();
		pos.x=value;
		emitter->setPosition(pos);
	}
		
}

void MpAttrOperator::onSetPositionXVar(double value)
{
	Particle2DEmitter* emitter=MpGlobal::curParticle2DEmitter();
	if(emitter)
	{
		Vector2 pos=emitter->getPositionVar();
		pos.x=value;
		emitter->setPositionVar(pos);
	}
}


void MpAttrOperator::onSetPositionY(double value)
{
	Particle2DEmitter* emitter=MpGlobal::curParticle2DEmitter();
	if(emitter)
	{
		Vector2 pos=emitter->getPosition();
		pos.y=value;
		emitter->setPosition(pos);
	}

}


void MpAttrOperator::onSetPositionYVar(double value)
{
	Particle2DEmitter* emitter=MpGlobal::curParticle2DEmitter();
	if(emitter)
	{
		Vector2 pos=emitter->getPositionVar();
		pos.y=value;
		emitter->setPositionVar(pos);
	}
}




void MpAttrOperator::onSetMoveMode(int value)
{
	Particle2DEmitter* emitter=MpGlobal::curParticle2DEmitter();
	if(emitter)
	{
		emitter->setMoveMode(value);
	}
}


void MpAttrOperator::onSetBlendSrc(int value)
{
	Particle2DEmitter* emitter=MpGlobal::curParticle2DEmitter();
	if(emitter)
	{
		emitter->setBlendSrc(value);
	}
}

void MpAttrOperator::onSetBlendDst(int value)
{
	Particle2DEmitter* emitter=MpGlobal::curParticle2DEmitter();
	if(emitter)
	{
		emitter->setBlendDst(value);
	}
}

void MpAttrOperator::onSetTexture(Faeris::Texture2D* value)
{
	Particle2DEmitter* emitter=MpGlobal::curParticle2DEmitter();
	if(emitter)
	{
		emitter->setTexture(value);
	}
}


void MpAttrOperator::onSetEnvMode(int value)
{
	Particle2DEmitter* emitter=MpGlobal::curParticle2DEmitter();
	if(emitter)
	{
        emitter->setEnvironmentMode(value);
	}
}


void MpAttrOperator::onSetSpeed(double value)
{
	Particle2DEmitter* emitter=MpGlobal::curParticle2DEmitter();
	if(emitter)
	{
		emitter->setSpeed(value);
	}
}

void MpAttrOperator::onSetSpeedVar(double value)
{
	Particle2DEmitter* emitter=MpGlobal::curParticle2DEmitter();
	if(emitter)
	{
		emitter->setSpeedVar(value);
	}
}

void MpAttrOperator::onSetGravityX(double value)
{
	Particle2DEmitter* emitter=MpGlobal::curParticle2DEmitter();
	if(emitter)
	{
		Vector2 gravity=emitter->getGravity();
		gravity.x=value;
		emitter->setGravity(gravity);
	}
}

void MpAttrOperator::onSetGravityY(double value)
{
	Particle2DEmitter* emitter=MpGlobal::curParticle2DEmitter();
	if(emitter)
	{
		Vector2 gravity=emitter->getGravity();
		gravity.y=value;
		emitter->setGravity(gravity);
	}
}


void MpAttrOperator::onSetRadialAcceleration(double value)
{
	Particle2DEmitter* emitter=MpGlobal::curParticle2DEmitter();
	if(emitter)
	{
		emitter->setRadialAcceleration(value);
	}

}

void MpAttrOperator::onSetRadialAccelerationVar(double value)
{
	Particle2DEmitter* emitter=MpGlobal::curParticle2DEmitter();
	if(emitter)
	{
		emitter->setRadialAccelerationVar(value);
	}
}


void MpAttrOperator::onSetTangentialAcceleration(double value)
{
	Particle2DEmitter* emitter=MpGlobal::curParticle2DEmitter();
	if(emitter)
	{
		emitter->setTangentialAcceleration(value);
	}

}


void MpAttrOperator::onSetTangentialAccelerationVar(double value)
{
	Particle2DEmitter* emitter=MpGlobal::curParticle2DEmitter();
	if(emitter)
	{
		emitter->setTangentialAccelerationVar(value);
	}
}

void MpAttrOperator::onSetStartRadius(double value)
{
	Particle2DEmitter* emitter=MpGlobal::curParticle2DEmitter();
	if(emitter)
	{
		emitter->setStartRadius(value);
	}
}

void MpAttrOperator::onSetStartRadiusVar(double value)
{
	Particle2DEmitter* emitter=MpGlobal::curParticle2DEmitter();
	if(emitter)
	{
		emitter->setStartRadiusVar(value);
	}
}

void MpAttrOperator::onSetEndRadius(double value)
{
	Particle2DEmitter* emitter=MpGlobal::curParticle2DEmitter();
	if(emitter)
	{
		emitter->setEndRadius(value);
	}
}

void MpAttrOperator::onSetEndRadiusVar(double value)
{
	Particle2DEmitter* emitter=MpGlobal::curParticle2DEmitter();
	if(emitter)
	{
		emitter->setEndRadiusVar(value);
	}
}

void MpAttrOperator::onSetRotateSpeed(double value)
{
	Particle2DEmitter* emitter=MpGlobal::curParticle2DEmitter();
	if(emitter)
	{
		emitter->setRotateSpeed(value);
	}
}


void MpAttrOperator::onSetRotateSpeedVar(double value)
{
	Particle2DEmitter* emitter=MpGlobal::curParticle2DEmitter();
	if(emitter)
	{
		emitter->setRotateSpeedVar(value);
	}
}
















