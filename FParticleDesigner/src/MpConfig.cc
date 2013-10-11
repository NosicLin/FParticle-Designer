#include "MpConfig.h"

MpConfig::MpConfig()
{
	m_lastExportPath=".";
}


void MpConfig::setLastExportPath(const char* name)
{
	m_lastExportPath=name;
}

std::string  MpConfig::getLastExportPath()
{
	return m_lastExportPath;
}


