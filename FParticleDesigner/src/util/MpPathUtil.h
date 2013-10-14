#ifndef _MP_PATH_UTIL_H_
#define _MP_PATH_UTIL_H_

class MpPathUtil
{
	public:
		static std::string baseName(const char* file);
		static std::string dirName(const char* file);
		static std::string removePrePath(std::string name,
										 std::string pre_path);
		static std::string toStdName(std::string name);
};


#endif /*_MP_PATH_UTIL_H_*/

