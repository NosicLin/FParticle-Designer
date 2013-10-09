#include "widget/SdInputDialog.h"


SdInputDialog::SdInputDialog(const char* title)
{
	init(std::string(title),std::string(""));
}

SdInputDialog::SdInputDialog(const char* title,const char* value)
{
	init(std::string(title),std::string(value));
}


void SdInputDialog::setTitle(const char* title)
{
    m_ui->m_title->setText(QString(title));
}
void SdInputDialog::setTextField(const char* value)
{
    m_ui->m_editText->setText(QString(value));
}

std::string SdInputDialog::getTextField()
{
    return m_ui->m_editText->text().toStdString();
}

void SdInputDialog::init(const std::string& title,const std::string& value)
{
	m_ui=new Ui_input;
	m_ui->setupUi(this);
	setTitle(title.c_str());
    setTextField(value.c_str());
}





