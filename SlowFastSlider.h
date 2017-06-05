#pragma once
#include <qwidget.h>
#include <qslider.h>
#include <qlabel.h>

class SlowFastSlider :public QWidget //QGroupBox? QFrame?
{
public:
	SlowFastSlider(QWidget *parent = 0);
	~SlowFastSlider();

private:
	QSlider *slider;
	QLabel  *slow;
	QLabel  *fast;
	QLabel  *info;
};

