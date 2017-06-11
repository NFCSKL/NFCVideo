#ifndef MYTESTWIDGET_H
#define MYTESTWIDGET_H

#include <QWidget>
#include <qtextedit.h>
#include <qpushbutton.h>

class MyTestWidget : public QWidget
{
	Q_OBJECT
public:
	MyTestWidget(QWidget *parent);
	~MyTestWidget();

private slots:
	void xxxClicked(void);
	void yyyClicked(void);
	void zzzClicked(void);

private:
	QTextEdit	*textEdit;

};

#endif
