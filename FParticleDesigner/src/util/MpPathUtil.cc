#include <QDir>
#include <QFileInfo>
#include "util/MpPathUtil.h"


std::string MpPathUtil::baseName(const char* file)
{
	QFileInfo info(file);
	return info.baseName().toStdString();
}


std::string MpPathUtil::dirName(const char* file)
{
	QFileInfo info(file);
	return info.dir().dirName().toStdString();
}

