#include <QDir>
#include <QFileInfo>
#include "util/MpPathUtil.h"


std::string MpPathUtil::baseName(const char* file)
{
	QFileInfo info(file);
	return info.fileName().toStdString();
}


std::string MpPathUtil::dirName(const char* file)
{
	QFileInfo info(file);
	return info.absoluteDir().absolutePath().toStdString();
}

std::string MpPathUtil::removePrePath(std::string name,
									  std::string pre_path)
{

	name=MpPathUtil::toStdName(name);
	pre_path=MpPathUtil::toStdName(pre_path);


	int path_length=pre_path.size();
	int name_length=name.size();


	if(path_length==0)
	{
		return name;
	}

	if(pre_path[path_length-1]!='/')
	{
		pre_path=pre_path+"/";
		path_length++;
	}

	if(path_length>name_length)
	{
		return name;
	}

	bool is_prefix=true;

	for(int i=0;i<path_length;i++)
	{
		if(pre_path[i]!=name[i])
		{
			is_prefix=false;
		}
	}
	if(!is_prefix)
	{
		return name;
	}

	else 
	{
		return name.c_str()+path_length;
	}
}


std::string MpPathUtil::toStdName(std::string name)
{
	int size=name.size();
	for(int i=0;i<size;i++)
	{
		if(name[i]=='\\')
		{
            name[i]='/';
		}
	}
	return name;
}


