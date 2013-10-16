#include <QtGlobal>
#include "core/MpProject.h"
#include "core/MpParticleEffect.h"

#include "operator/MpIoOperator.h"
#include "sys/io/FsVFS.h"
#include "sys/io/FsFile.h"
#include "sys/io/FsSysFile.h"
#include "support/util/FsDict.h"
#include "support/util/FsScriptUtil.h"
#include "support/util/FsArray.h"
#include "support/util/FsString.h"

#include "graphics/FsRender.h"



NS_FS_USE
const char* S_BlendFactorToStr(int factor)
{
	switch(factor)
	{
		case Render::FACTOR_ZERO:
			return "Zero";
		case Render::FACTOR_ONE:
			return "One";
		case Render::FACTOR_SRC_COLOR:
			return "SrcColor";
		case Render::FACTOR_ONE_MINUS_SRC_COLOR:
			return "OneMinusSrcColor";
		case Render::FACTOR_DST_COLOR:
			return "DstColor";
		case Render::FACTOR_ONE_MINUS_DST_COLOR:
			return "OneMinusDstColor";
		case Render::FACTOR_SRC_ALPHA:
			return "SrcAlpha";
		case Render::FACTOR_ONE_MINUS_SRC_ALPHA:
			return "OneMinusSrcAlpha";
		case Render::FACTOR_DST_ALPHA:
			return "DstAlpha";
		case Render::FACTOR_ONE_MINUS_DST_ALPHA:
			return "OneMinusDstAlpha";
		case Render::FACTOR_SRC_ALPHA_SATURATE:
			return "SrcAlphaSaturate";
	}
	assert(0);
}




MpIoOperator::MpIoOperator()
{
}

MpIoOperator::~MpIoOperator()
{

}


MpProject* MpIoOperator::loadProject(const char* filename)
{

	FsFile* file=SysFile::open(filename);
	if(file==NULL)
    {
        qDebug("Open File(%s) Failed",filename);
		return NULL;
	}

	MpProject* ret=loadProject(file);
    file->decRef();
    return ret;
}

MpProject* MpIoOperator::loadProject(FsFile* file)
{
	FsDict* dict=ScriptUtil::parseScript(file);
	if(dict==NULL)
    {
        qDebug("Parse Script Failed");
		return NULL;
	}


	/* project */
	FsDict* d_project=ScriptUtil::getDict(dict,"project");
	if(d_project==NULL)
    {
        qDebug("Can't Get Project");
		dict->decRef();
		return NULL;
	}

    FsArray* a_particles=ScriptUtil::getArray(d_project,"particles");
	if(a_particles==NULL)
    {
        qDebug("Can't Get Particles");
		d_project->decRef();
        dict->decRef();
		return NULL;
	}

	MpProject* proj=new MpProject;

	int particle_nu=a_particles->size();
	for(int i=0;i<particle_nu;i++)
	{
		FsDict* d_par=ScriptUtil::getDict(a_particles,i);
		if(d_par==NULL)
		{
			qDebug("Get Particle %d Failed",i);
			continue;

		}

		FsDict* d_attr=ScriptUtil::getDict(d_par,"attr");
		if(d_attr==NULL)
		{
			qDebug("Can't Get Particle %d Attribute",i);
			d_par->decRef();
			continue;

		}

		FsString* s_name=ScriptUtil::getString(d_par,"name");
		if(s_name==NULL)
		{
			qDebug("Can't Get Particle %d Name",i);
			d_par->decRef();
			d_attr->decRef();
			continue;
		}

        MpParticleEffect* effect=MpParticleEffect::create(d_attr);
		if(effect)
		{
        	effect->setName(s_name->cstr());
        	proj->addParticleEffect(effect);
		}


        d_par->decRef();
        d_attr->decRef();
        s_name->decRef();
    }

	dict->decRef();
	d_project->decRef();
	a_particles->decRef();

	return proj;
}

bool MpIoOperator::saveProject(const char* filename,MpProject* proj)
{
    qDebug("Save Project=%s",filename);
    FsFile* file=SysFile::open(filename,FsFile::FS_IO_WRONLY|FsFile::FS_IO_TRUNC|FsFile::FS_IO_CREATE);
	if(file==NULL)
	{
		qDebug("Open %s Failed",filename);
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

    int particle_nu=proj->getParticleEffectNu();
	for(int i=0;i<particle_nu;i++)
	{
        MpParticleEffect* effect=proj->getParticleEffect(i);

		file->writeStr("\t\t{\n");
		file->writeStr("\t\t\tname:\"%s\"\n",effect->getName().c_str());
		file->writeStr("\t\t\tattr:{\n");
        saveParticleEffect("\t\t\t\t",file,effect);

		file->writeStr("\t\t\t}\n");
		file->writeStr("\t\t}\n");

    }
	file->writeStr("\t]\n");
	file->writeStr("}\n");

	file->writeStr("info:{\n");
	file->writeStr("\tabout:\"FParticle Designer v1.0 For Faeris Engine\"\n");
	file->writeStr("}\n");
	file->writeStr("\n");

    return true;
}



void MpIoOperator::saveParticleEffect(const char* prefix,FsFile* file,MpParticleEffect* effect)
{

	char pre_tab4[1024];
	char pre_tab5[1024];
	char pre_tab6[1024];

	sprintf(pre_tab4,"%s",prefix);
	sprintf(pre_tab5,"%s\t",prefix);
	sprintf(pre_tab6,"%s\t\t",prefix);

	Particle2DEmitter* emitter=effect->getParticleEmitter();

	/* emitter */
	file->writeStr("%semitter:{\n",pre_tab4);
	file->writeStr("%sdurationTime:%f\n",pre_tab5,emitter->getDurationTime());
	file->writeStr("%sdurationTimeVar:%f\n",pre_tab5,emitter->getDurationTimeVar());
	file->writeStr("%semitSpeed:%d\n",pre_tab5,emitter->getEmitSpeed());
	file->writeStr("%smaxParticleNu:%d\n",pre_tab5,emitter->getMaxParticleNu());
	file->writeStr("%s}\n",pre_tab4);


	/* particle */
	file->writeStr("%sparticle:{\n",pre_tab4);
	file->writeStr("%slifeTime:%f\n",pre_tab5,emitter->getLifeTime());
	file->writeStr("%slifeTimeVar:%f\n",pre_tab5,emitter->getLifeTimeVar());
	file->writeStr("%sstartSize:%f\n",pre_tab5,emitter->getStartSize());
	file->writeStr("%sstartSizeVar:%f\n",pre_tab5,emitter->getStartSizeVar());
	file->writeStr("%sendSize:%f\n",pre_tab5,emitter->getEndSize());
	file->writeStr("%sendSizeVar:%f\n",pre_tab5,emitter->getEndSizeVar());

	Color scolor=emitter->getStartColor();
	Color scolor_var=emitter->getStartColorVar();

	Color ecolor=emitter->getEndColor();
	Color ecolor_var=emitter->getEndColorVar();


	file->writeStr("%sstartColor:[%d,%d,%d,%d]\n",   pre_tab5, scolor.r,     scolor.g,     scolor.b,     scolor.a);
	file->writeStr("%sstartColorVar:[%d,%d,%d,%d]\n",pre_tab5, scolor_var.r, scolor_var.g, scolor_var.b, scolor_var.a);
	file->writeStr("%sendColor:[%d,%d,%d,%d]\n",     pre_tab5, ecolor.r,     ecolor.g,     ecolor.b,     ecolor.a);
	file->writeStr("%sendColorVar:[%d,%d,%d,%d]\n",  pre_tab5, ecolor_var.r, ecolor_var.g, ecolor_var.b, ecolor_var.a);
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
			file->writeStr("%smoveMode:\"free\"\n",pre_tab5);
			break;
		case Particle2DEmitter::MOVE_GROUP:
			file->writeStr("%smoveMode:\"group\"\n",pre_tab5);
			break;
	}

	file->writeStr("%s}\n",pre_tab4);

	/* texture */
	file->writeStr("%stexture:{\n",pre_tab4);

	if(effect->getTexturePath().size()!=0)
	{
		file->writeStr("%surl:\"%s\"\n",pre_tab5,effect->getTexturePath().c_str());
	}

	file->writeStr("%sblendSrc:\"%s\"\n",pre_tab5,S_BlendFactorToStr(emitter->getBlendSrc()));
	file->writeStr("%sblendDst:\"%s\"\n",pre_tab5,S_BlendFactorToStr(emitter->getBlendDst()));


	/* TODO: blendSrc,blendDst,url */
	file->writeStr("%s}\n",pre_tab4);

	/* environment */
	file->writeStr("%senvironment:{\n",pre_tab4);
	int evn_mode=emitter->getEnvironmentMode();

	switch(evn_mode)
	{
		case Particle2DEmitter::ENV_GRAVITY:
			file->writeStr("%smode:\"gravity\"\n",pre_tab5);
			break;

		case Particle2DEmitter::ENV_RADIAL:
			file->writeStr("%smode:\"radius\"\n",pre_tab5);
			break;
	}



	/* gravity */
	file->writeStr("%sgravity:{\n",pre_tab5);
	file->writeStr("%sspeed:%f\n",pre_tab6,emitter->getSpeed());
	file->writeStr("%sspeedVar:%f\n",pre_tab6,emitter->getSpeedVar());

	Vector2 g=emitter->getGravity();

	file->writeStr("%sgravity:[%f,%f]\n",pre_tab6,g.x,g.y);
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
	file->writeStr("%s}\n",pre_tab4);
}



bool MpIoOperator::exportParticleEffect(const char* filename,MpParticleEffect* effect)
{
    FsFile* file=SysFile::open(filename,FsFile::FS_IO_WRONLY|FsFile::FS_IO_TRUNC|FsFile::FS_IO_CREATE);

	if(file==NULL)
    {
        qDebug("Open File(%s) Failed",filename);
        return false;
	}
	bool ret=exportParticleEffect(file,effect);
	file->decRef();
	return ret;

}



bool MpIoOperator::exportParticleEffect(FsFile* file,MpParticleEffect* effect)
{
    saveParticleEffect("",file,effect);
    return true;
}




