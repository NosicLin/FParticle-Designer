#ifndef _SD_RENDER_UTIL_H_
#define _SD_RENDER_UTIL_H_ 

#include "FsMacros.h"
#include "math/FsVector2.h"
#include "graphics/FsColor.h"


NS_FS_USE
namespace SdRenderUtil
{
	void drawLine(Vector2 start,Vector2 end,float width,Color c);
	void drawRectangle(Vector2 start,Vector2 end,Color c);
	void setProjectionMatrix(Matrix4* mat);
};

#endif /*_SD_RENDER_UTIL_H_*/

