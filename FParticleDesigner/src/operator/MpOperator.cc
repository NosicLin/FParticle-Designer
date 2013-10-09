#include "operator/MpOperator.h"
#include "operator/MpAttrOperator.h"
#include "operator/MpDataOperator.h"
#include "operator/MpUiOperator.h"



MpAttrOperator* MpOperator::m_attr=NULL;
MpDataOperator* MpOperator::m_data=NULL;
MpUiOperator* MpOperator::m_ui=NULL;


MpAttrOperator* MpOperator::attr()
{
	if(MpOperator::m_attr==NULL)
	{
		MpOperator::m_attr=new MpAttrOperator;
	}
	return MpOperator::m_attr;
}

MpDataOperator* MpOperator::data()
{
	if(MpOperator::m_data==NULL)
	{
		MpOperator::m_data=new MpDataOperator;
	}

	return MpOperator::m_data;
}

MpUiOperator* MpOperator::ui()
{
	if(MpOperator::m_ui==NULL)
	{
		MpOperator::m_ui=new MpUiOperator;
	}
	return MpOperator::m_ui;
}







