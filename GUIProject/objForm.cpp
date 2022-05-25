#include "objForm.h"
#include <string>
#include <Conversion.h>
#include <qfiledialog.h>

ObjForm::ObjForm(QWidget* parent)
	: QWidget(parent)
{
	ui.setupUi(this);
}

void ObjForm::on_inputButton_clicked()
{
	m_InputFilename = QFileDialog::getOpenFileName(this, "Open a file");
}

void ObjForm::on_outputButton_clicked()
{
	m_OutputFilename = QFileDialog::getOpenFileName(this, "Open a file");
}

void ObjForm::on_buttonBox_clicked()
{
	JsonToObj(m_InputFilename.toStdString(), m_OutputFilename.toStdString());
	auto vertexList = GetVerticesFromObj(m_OutputFilename.toStdString());

	for (int i = 0; i < vertexList.size(); ++i)
	{
		ui.tableWidget->insertRow(ui.tableWidget->rowCount());
		ui.tableWidget->setItem(ui.tableWidget->rowCount() - 1, 0,
			new QTableWidgetItem(QString(std::to_string(i).c_str())));
		ui.tableWidget->setItem(ui.tableWidget->rowCount() - 1, 1,
			new QTableWidgetItem(QString((
				std::to_string(vertexList[i].position.x) + ", " + std::to_string(vertexList[i].position.y) + ", " + std::to_string(vertexList[i].position.z)).c_str())));
		ui.tableWidget->setItem(ui.tableWidget->rowCount() - 1, 2,
			new QTableWidgetItem(QString((
				std::to_string(vertexList[i].uv.x) + ", " + std::to_string(vertexList[i].uv.y)).c_str())));
		ui.tableWidget->setItem(ui.tableWidget->rowCount() - 1, 3,
			new QTableWidgetItem(QString((
				std::to_string(vertexList[i].normal.x) + ", " + std::to_string(vertexList[i].normal.y) + ", " + std::to_string(vertexList[i].normal.z)).c_str())));
	}
}
