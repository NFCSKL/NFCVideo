#include "MyTestWidget.h"
#include <qboxlayout.h>



MyTestWidget::MyTestWidget(QWidget *parent)
	: QWidget(parent)
{
	QVBoxLayout* col = new QVBoxLayout();
	textEdit = new QTextEdit(this);

	QHBoxLayout* row = new QHBoxLayout();
	QPushButton* xxxBtn = new QPushButton("1");
	row->addWidget(xxxBtn);
	QPushButton* yyyBtn = new QPushButton("2");
	row->addWidget(yyyBtn);
	QPushButton* zzzBtn = new QPushButton("3");
	row->addWidget(zzzBtn);

	col->addWidget(textEdit);
	col->addLayout(row);

	this->setLayout(col);

	connect(xxxBtn, &QPushButton::clicked, this, &MyTestWidget::xxxClicked);
	connect(yyyBtn, &QPushButton::clicked, this, &MyTestWidget::yyyClicked);
	connect(zzzBtn, &QPushButton::clicked, this, &MyTestWidget::zzzClicked);

}


MyTestWidget::~MyTestWidget()
{
}

void MyTestWidget::xxxClicked(void)
{
	QString text = "AAAAA\n";

	textEdit->insertPlainText(text);
	//QTextDocument *document = textEdit->document();
	//QTextCursor cursor = document->e;
	//cursor.insertText(text);

}

void MyTestWidget::yyyClicked(void)
{
}

void MyTestWidget::zzzClicked(void)
{
}
