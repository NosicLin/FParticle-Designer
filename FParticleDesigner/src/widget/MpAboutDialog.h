#ifndef _MP_ABOUT_DIALOG_H_
#define _MP_ABOUT_DIALOG_H_
#include "ui_about_fp.h"

#include <QDialog>

class MpAboutDialog:public QDialog 
{
	public:
		MpAboutDialog();

	private:
		Ui_AboutDialog* m_ui;
};


#endif /*_MP_ABOUT_DIALOG_H_*/

