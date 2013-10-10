#ifndef _MP_IO_OPERATOR_H_
#define _MP_IO_OPERATOR_H_


class FsFile;
class MpProject;
class MpParticleEffect;


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



		void exportParticleEffect(const char* filename,MpParticleEffect* effect);
		void exportParticleEffect(FsFile* file,MpParticleEffect* effect);

};

#endif /*_MP_IO_OPERATOR_H_*/





