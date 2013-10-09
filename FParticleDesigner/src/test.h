#include "core/MpParticleEffect.h"
#include "sys/io/FsVFS.h"
#include "support/util/FsScriptUtil.h"


static inline MpParticleEffect* createMpParticleEffect(const char* filename)
{
	FsFile* file=VFS::open(filename);

	FsDict* dict=ScriptUtil::parseScript(file);
	FS_SAFE_DEC_REF(file);


	MpParticleEffect* mp_effect=MpParticleEffect::create(dict);
	mp_effect->setName(filename);

	FS_SAFE_DEC_REF(dict);
	return mp_effect;
}

