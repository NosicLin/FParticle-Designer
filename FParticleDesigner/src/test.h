#include "core/MpParticleEffect.h"
#include "sys/io/FsVFS.h"
#include "support/util/FsScriptUtil.h"


static inline MpParticleEffect* createMpParticleEffect()
{
	FsFile* file=VFS::open("file.fpl");

	FsDict* dict=ScriptUtil::parseScript(file);
	FS_SAFE_DEC_REF(file);


	MpParticleEffect* mp_effect=MpParticleEffect::create(dict);
	FS_SAFE_DEC_REF(dict);
	return mp_effect;
}

