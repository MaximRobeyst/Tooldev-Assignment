#ifndef OBJFORM_H
#define OBJFORM_H

#include "ui_objform.h"

class ObjForm : public QWidget
{
	Q_OBJECT
public:
	explicit ObjForm(QWidget* parent = nullptr);

private slots :
	void on_inputFile_valueChanged(const std::string& inputfile);
	void on_outputFile_valueChanged(const std::string& inputfile);

private:
	Ui::Form ui;
};

#endif // !OBJFORM_H