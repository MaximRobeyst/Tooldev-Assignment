#ifndef OBJFORM_H
#define OBJFORM_H

#include "ui_objForm.h"

class ObjForm : public QWidget
{
	Q_OBJECT
public:
	explicit ObjForm(QWidget* parent = nullptr);

private slots :
	void on_inputButton_clicked();
	void on_outputButton_clicked();
	void on_buttonBox_clicked();

private:
	Ui::Form ui;

	QString m_InputFilename;
	QString m_OutputFilename;
};

#endif // !OBJFORM_H