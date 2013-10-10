#include "operator/MpIoOperator.h"

MpIoOperator::MpIoOperator()
{
}

MpIoOperator::~MpIoOperator()
{

}


MpProject* MpIoOperator::loadProject(const char* filename)
{

	FsFile* file=VFS::open(filename,VFS::FS_IO_WRONLY);
	if(file==NULL)
	{
		return NULL;
	}

	MpProject* ret=loadProject(file);
	file->decRef();
}

MpProject* MpIoOperator::loadProject(FsFile* file)
{
	FsDict* dict=ScriptUtil::parseScript(file);
	if(dict==NULL)
	{
		return NULL;
	}


	/* project */
	FsDict* d_project=ScriptUtil::getDict(dict,"project");
	if(d_project==NULL)
	{
		dict->decRef();
		return NULL;
	}

	FsArray* a_particles=ScriptUtil::getArrary(d_project,"particles");
	if(a_particles==NULL)
	{

	}


}

bool MpIoOperator::saveProject(const char* filename,MpProject* proj)
{
	FsFile* file=VFS::open(filename,VFS::FS_IO_WRONLY);
	if(file==NULL)
	{
		return false;
	}

	bool ret=saveProject(file,proj);
	file->decRef();
	return ret;
}

bool MpIoOperator::saveProject(FsFile* file,MpProject* proj)
{
	file->writeStr("version:\"v1.0\"\n");
	file->writeStr("type:\"FParticle\"\n");
	file->writeStr("project:{\n");
	file->writeStr("\tparticles:[\n");

	int particle_nu=proj->getParticleNu();
	for(int i=0;i<particle_nu;i++)
	{
		MpParticleEffect* effect=proj->getParticle(i);
		Particle2DEmitter* emitter=effect->getParticleEmitter();

		file->writeStr("\t\t{\n");
		file->writeStr("\t\t\tname:%s\n",effect->getName().c_str());
		file->writeStr("\t\t\tattr:{\n");

		const char* pre_tab4="\t\t\t\t";
		const char* pre_tab5="\t\t\t\t\t";
		const char* pre_tab6="\t\t\t\t\t\t";

		/* emitter */
		file->writeStr("%semitter:{\n",pre_tab4);
		file->writeStr("%sdurationTime:%d\n",pre_tab5,emitter->getDurationTime());
		file->writeStr("%sdurationTimeVar:%d\n",pre_tab5,emitter->getDurationTimeVar());
		file->writeStr("%semitSpeed:%d\n",pre_tab5,emitter->getEmitSpeed());
		file->writeStr("%smaxParticleNu:%d\n",pre_tab5,emitter->getMaxParticleNu());
		file->writeStr("%s}\n",pre_tab4);


		/* particle */
		file->writeStr("%sparticle:{\n",pre_tab4);
		file->writeStr("%slifeTime:%f\n",pre_tab5,emitter->getLifeTime());
		file->writeStr("%slifeTimeVar:%f\n",pre_tab5,emitter->getLifeTimeVar());
		file->writeStr("%sstartSize:%f\n",pre_tab5,emitter->getStartSize());
		file->writeStr("%sstartSizeVar%f\n",pre_tab5,emitter->getStartSizeVar());
		file->writeStr("%sendSize:%f\n",pre_tab5,emitter->getEndSize());
		file->writeStr("%sendSizeVar:%f\n",pre_tab5,emitter->getEndSizeVar());

		Color scolor=emitter->getStartColor();
		Color scolor_var=emitter->getStartColorVar();

		Color ecolor=emitter->getEndColor();
		color ecolor_var=emitter->getEndColorVar();


		file->writeStr("%sstartColor:[%d,%d,%d,%d]\n",pre_tab5,scolor.r,scolor.g,scolor.b,scolor.a);
		file->writeStr("%sstartColorVar:[%d,%d,%d,%d]\n",pre_tab5,scolor_var.r,scolor_var.g,scolor_var.b,scolor_var.a);
		file->writeStr("%sendColor:[%d,%d,%d,%d]\n",pre_tab5,ecolor.r,ecolor.g,ecolor.b,ecolor.a);
		file->writeStr("%sendColorVar:[%d,%d,%d,%d]\n",pre_tab5,ecolor_var.r,ecolor_var.g,ecolor_var.b,ecolor_var.a);
		file->writeStr("%sangle:%f\n",pre_tab5,emitter->getAngle());
		file->writeStr("%sangleVar:%f\n",pre_tab5,emitter->getAngleVar());

		file->writeStr("%sstartRotation:%f\n",pre_tab5,emitter->getStartRotation());
		file->writeStr("%sstartRotationVar:%f\n",pre_tab5,emitter->getStartRotationVar());
		file->writeStr("%sendRotation:%f\n",pre_tab5,emitter->getEndRotation());
		file->writeStr("%sendRotationVar:%f\n",pre_tab5,emitter->getEndRotationVar());

		Vector2 pos=emitter->getPosition();
		Vector2 pos_var=emitter->getPositionVar();
		file->writeStr("%sposition:[%f,%f]\n",pre_tab5,pos.x,pos.y);
		file->writeStr("%spositionVar:[%f,%f]\n",pre_tab5,pos_var.x,pos_var.y);

		int move_mode=emitter->getMoveMode();
		switch(move_mode)
		{
			case Particle2DEmitter::MOVE_FREE:
				file->writeStr("%smoveMode:\"free\"",pre_tab5);
				break;
			case Particle2DEmitter::MOVE_GROUP:
				file->writeStr("%smoveMode:\"grounp\"",pre_tab5);
				break;
		}

		file->writeStr("%s}\n",pre_tab4);

		/* texture */
		file->writeStr("%stexture:{\n",pre_tab4);
		/* TODO: blendSrc,blendDst,url */

		/* environment */
		file->writeStr("%senvironment:{\n",pre_tab4);
		int evn_mode=emitter->getEnvironmentMode();

		switch(evn_mode)
		{
			case Particle2DEmitter::ENV_GRAVITY:
				file->writeStr("%smode:\"gravity\n",pre_tab5);
				break;

			case Particle2DEmitter::ENV_RADIUS:
				file->writeStr("%smode:\"radius\"\n",pre_tab5);
				break;
		}


		/* gravity */
		file->writeStr("%sgravity:{\n",pre_tab5);
		file->writeStr("%sspeed:%f\n",pre_tab6,emitter->getSpeed());
		file->writeStr("%sspeedVar:%f\n",pre_tab6,emitter->getSpeedVar());

		Vector2 g=emitter->getGravity();

		file->writeStr("%sgravity:[%d,%d]\n",pre_tab6,g.x,g.y);
		file->writeStr("%sradialAcceleration:%f\n",pre_tab6,emitter->getRadialAcceleration());
		file->writeStr("%sradialAccelerationVar:%f\n",pre_tab6,emitter->getRadialAccelerationVar());
		file->writeStr("%stangentialAcceleration:%f\n",pre_tab6,emitter->getTangentialAcceleration());
		file->writeStr("%stangentialAccelerationVar:%f\n",pre_tab6,emitter->getTangentialAccelerationVar());
		file->writeStr("%s}\n",pre_tab5);

		/* radial */
		file->writeStr("%sradial:{\n",pre_tab5);
		file->writeStr("%sstartRadius:%f\n",pre_tab6,emitter->getStartRadius());
		file->writeStr("%sstartRadiusVar:%f\n",pre_tab6,emitter->getStartRadiusVar());
		file->writeStr("%sendRadius:%f\n",pre_tab6,emitter->getEndRadius());
		file->writeStr("%sendRadiusVar:%f\n",pre_tab6,emitter->getEndRadiusVar());
		file->writeStr("%srotateSpeed:%f\n",pre_tab6,emitter->getRotateSpeed());
		file->writeStr("%srotateSpeedVar:%f\n",pre_tab6,emitter->getRotateSpeedVar());
		file->writeStr("%s}\n",pre_tab5);

		file->writeStr("%s}\n"pre_tab4);


		file->writeStr("\t\t\t}\n");
		file->writeStr("\t\t}\n");

	}
}
















































	}
}






























