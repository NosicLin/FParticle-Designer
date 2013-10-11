#ifndef _MP_IO_OPERATOR_H_
#define _MP_IO_OPERATOR_H_

#include "sys/io/FsFile.h"

class MpProject;
class MpParticleEffect;

NS_FS_USE


class MpIoOperator
{
	public:
		MpIoOperator();
		~MpIoOperator();

	public:
		MpProject* loadProject(const char* filename);
		MpProject* loadProject(FsFile* file);

		bool saveProject(const char* filename,MpProject* proj);
		bool saveProject(FsFile* file,MpProject* proj);


		void exportAllParticleEffect(const char* dir,MpProject* proj);
		bool exportParticleEffect(const char* filename,MpParticleEffect* effect);
		bool exportParticleEffect(FsFile* file,MpParticleEffect* effect);



	protected:
		void saveParticleEffect(const char* prefix,FsFile* file,MpParticleEffect* effect);
};

#endif /*_MP_IO_OPERATOR_H_*/











