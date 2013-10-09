#ifndef _MP_IDENTIFY_H_
#define _MP_IDENTIFY_H_

enum{
	MP_IDENTIFY,
	MP_PROJECT,
	MP_PARTICLE,
};

class MpIdentify 
{
	public:
		virtual int getClassType();
		virtual const char* className();
};



#endif /*_MP_IDENTIFY_H_*/

