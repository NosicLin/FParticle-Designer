#ifndef _SD_INPUT_DIALOG_H_
#define _SD_INPUT_DIALOG_H_

#include "ui_input_text.h"
#include <QDialog>
#include <string>

class SdInputDialog:public QDialog
{
	public:
		SdInputDialog(const char* title);
		SdInputDialog(const char* title,const char* value);

	public:
		void setTitle(const char* title);
		void setTextField(const char* value);
		std::string getTextField();

	protected:
		void init(const std::string& title,const std::string& value);

	private:
		Ui_input* m_ui;

};


#endif /*_SD_INPUT_DIALOG_H_*/




