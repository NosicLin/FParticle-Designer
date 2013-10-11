#ifndef _MP_CONFIG_H_
#define _MP_CONFIG_H_

#include <string>


class MpConfig 
{
	public:
		MpConfig();
		void setLastExportPath(const char*  name);
		std::string getLastExportPath();

	private:
		std::string m_lastExportPath;
};



#endif /*_MP_CONFIG_H_*/

