#ifndef _MP_OPERTOR_H_
#define _MP_OPERTOR_H_

class MpAttrOperator;
class MpDataOperator;
class MpUiOperator;
class MpIoOperator;

class MpOperator 
{
	public:
		static MpAttrOperator* attr();
		static MpDataOperator* data();
		static MpUiOperator* ui();
		static MpIoOperator* io();

	private:
		static MpAttrOperator* m_attr;
		static MpDataOperator* m_data;
		static MpUiOperator* m_ui;
		static MpIoOperator* m_io;

};

#endif /*_MP_OPERTOR_H_*/

