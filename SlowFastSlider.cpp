#include "SlowFastSlider.h"



SlowFastSlider::SlowFastSlider(QWidget *parent)
	: QWidget(parent)
{
	slider = new QSlider(Qt::Horizontal);
//	slow = new QLabel("Slow");
//	fast = new QLabel("Fast");
//	info = new QLabel("1x");
	//slider->setFixedSize(200, 20);
}


SlowFastSlider::~SlowFastSlider()
{
}
