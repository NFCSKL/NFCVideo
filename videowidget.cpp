#include "videowidget.h"
#include <qaction.h>
#include <qmessagebox.h>
#include <SlowFastSlider.h>
#include <qboxlayout.h>
#include <qpushbutton.h>
#include <qmessagebox.h>


VideoWidget::VideoWidget(QWidget *parent)
	: QWidget(parent), scrollArea(new QScrollArea)
{
	QVBoxLayout* col = new QVBoxLayout();
	videoOutput = new CVImageWidget();
	videoOutput->setSizePolicy(QSizePolicy::Ignored, QSizePolicy::Ignored);

	videoLabel = new QLabel();
	videoLabel->setSizePolicy(QSizePolicy::Ignored, QSizePolicy::Ignored);
	videoLabel->setScaledContents(false);

	scrollArea->setBackgroundRole(QPalette::Midlight);
	scrollArea->setWidget(videoOutput);
	scrollArea->setVisible(true);
	scrollArea->setFrameStyle(0);
	col->addWidget(scrollArea);

	QHBoxLayout* row = new QHBoxLayout();
	QPushButton* playBtn = new QPushButton("Play");
	QPushButton* nextBtn = new QPushButton(">");
	QPushButton* prevBtn = new QPushButton("<");
	QPushButton* zoomInBtn = new QPushButton("Zoom x1.2");
	QPushButton* normBtn = new QPushButton("100%");
	QPushButton* fitBtn = new QPushButton("Fit window");

	QPushButton* xxxxBtn = new QPushButton();
	xxxxBtn->setIcon(QIcon("E:\\7.Dep\\Icons1\\1471538877_save.png"));
//	xxxxBtn->setIcon(QIcon("C:\\1.Dep\\Icons1\\1471538877_save.png"));
	xxxxBtn->setMinimumSize(40, 40);
	QPushButton* yyyyBtn = new QPushButton();
	yyyyBtn->setIcon(QIcon("E:\\7.Dep\\Icons1\\1471538875_home.png"));
//	yyyyBtn->setIcon(QIcon("C:\\1.Dep\\Icons1\\1471538875_home.png"));
	yyyyBtn->setMinimumSize(40, 40);
	QPushButton* zzzzBtn = new QPushButton();
	zzzzBtn->setIcon(QIcon("E:\\7.Dep\\Icons1\\1471538455_pause-circle-outline.png"));
//	zzzzBtn->setIcon(QIcon("C:\\1.Dep\\Icons1\\1471538455_pause-circle-outline.png"));
	zzzzBtn->setMinimumSize(40, 40);
	lab = new QLabel();
	lab->setMinimumWidth(100);
	lab->setText("1234");
	//SlowFastSlider* slider = new SlowFastSlider(this);
	row->addWidget(prevBtn);
	row->addWidget(playBtn);
	row->addWidget(nextBtn);
	row->addWidget(zoomInBtn);
	row->addWidget(normBtn);
	row->addWidget(fitBtn);
	row->addWidget(xxxxBtn);
	row->addWidget(yyyyBtn);
	row->addWidget(zzzzBtn);
	row->addWidget(lab);
	//row->addWidget(slider);
	row->addStretch(2);
	col->addLayout(row);

	this->setLayout(col);

	scaleFactor = 1.0;
	adjustToWidget = false;

	connect(nextBtn, &QPushButton::clicked, this, &VideoWidget::nextClicked);
	connect(playBtn, &QPushButton::clicked, this, &VideoWidget::playClicked);
	connect(prevBtn, &QPushButton::clicked, this, &VideoWidget::prevClicked);
	connect(zoomInBtn, &QPushButton::clicked, this, &VideoWidget::zoomInClicked);
	connect(normBtn, &QPushButton::clicked, this, &VideoWidget::normClicked);
	connect(fitBtn, &QPushButton::clicked, this, &VideoWidget::fitClicked);
	connect(xxxxBtn, &QPushButton::clicked, this, &VideoWidget::xxxxClicked);
	connect(yyyyBtn, &QPushButton::clicked, this, &VideoWidget::yyyyClicked);
	connect(zzzzBtn, &QPushButton::clicked, this, &VideoWidget::zzzzClicked);

	currentImg = cv::imread("E:\\6.Testdata\\Bilder\\IMG_1424.JPG");
//	currentImg = cv::imread("C:\\2.Testdata\\Bilder\\IMG_1424.JPG");


//	connect(parent, QWidget::adjustSize, this, )

	//connect(this, SIGNAL(updateView(cv::Mat)), &mainWnd, SLOT(updateView(cv::Mat)));
	//connect(this, SIGNAL(updateSlider(int)), &mainWnd, SLOT(updateSlider(int)));
	//connect(this, SIGNAL(updateButtons(bool)), &mainWnd, SLOT(updateButtons(bool)));
	//connect(this, SIGNAL(updateCurrentTime(std::string)), &mainWnd, SLOT(setCurrentTime(std::string)));
}

VideoWidget::~VideoWidget()
{

}

void VideoWidget::showImage(cv::Mat img)
{
	if(!adjustToWidget && (scaleFactor == 1.0))
		videoOutput->showImage(img);
	else {
		cv::Mat _tmp;
		resize(_tmp, currentImg);
		videoOutput->showImage(_tmp);
	}
}

void VideoWidget::updateVideo(void)
{
	showImage(currentImg);
}

void VideoWidget::prevClicked(void)
{
	scaleFactor *= 1.2;
	adjustToWidget = false;
	showImage(currentImg);

	//QMessageBox msgBox;
	//msgBox.setText("Prev");
	//msgBox.exec();

	//SlowFastSlider aa = new SlowFastSlider();
	//aa.show();
	//_sleep(2000);
}

void VideoWidget::playClicked(void)
{
	adjustToWidget = true;
	showImage(currentImg);


	//QMessageBox msgBox;
	//msgBox.setText("Load");
	//msgBox.exec();
	
	//cv::Mat img = cv::imread("C:\\2.Testdata\\Bilder\\boldt.jpg");
	//cv::Mat _tmp;
	//cv::cvtColor(img, _tmp, CV_BGR2RGB);
	//QImage qimg = QImage(_tmp.data, _tmp.cols, _tmp.rows, _tmp.step, QImage::Format_RGB888);
	//videoLabel->setPixmap(QPixmap::fromImage(qimg));
	//scrollArea->setVisible(true);

	//videoLabel->adjustSize();

	//videoOutput->showImage(img);
	//scrollArea->setVisible(true);


}

void VideoWidget::zoomInClicked(void)
{
	scaleFactor *= 1.2;
	adjustToWidget = false;
	showImage(currentImg);
}

void VideoWidget::normClicked(void)
{
	scaleFactor = 1.0;
	adjustToWidget = false;
	showImage(currentImg);
}

void VideoWidget::fitClicked(void)
{
	adjustToWidget = true;
	showImage(currentImg);
}

void VideoWidget::nextClicked(void)
{
	//QMessageBox msgBox;
	//msgBox.setText("Next");
	//msgBox.exec();
	//setStatusTip("AAAA");
	scaleFactor = 1.0;
	adjustToWidget = false;
	showImage(currentImg);
	//videoOutput->adjustSize();
	//cv::Mat _tmp;
	//cv::cvtColor(img, _tmp, CV_BGR2RGB);
	//QImage qimg = QImage(_tmp.data, _tmp.cols, _tmp.rows, _tmp.step, QImage::Format_RGB888);
	//videoOutput->setPixmap(QPixmap::fromImage(qimg));
	//scrollArea->setVisible(true);

	//videoLabel->adjustSize();

}

void VideoWidget::xxxxClicked(void)
{
	cv::Mat _tmp;
	cv::Mat img = cv::imread("E:\\6.Testdata\\Bilder\\fruits.jpg");
//	cv::Mat img = cv::imread("C:\\2.Testdata\\Bilder\\boldt.jpg");
	cv::resize(img, _tmp, cv::Size(img.cols * 5, img.rows * 5), 0, 0, cv::INTER_NEAREST);
	//cv::resize(img, _tmp, cv::Size(), 2, 2, cv::INTER_NEAREST);
	videoOutput->showImage(_tmp);
	//videoOutput->adjustSize();

}

void VideoWidget::yyyyClicked(void)
{
	cv::Mat _tmp;
	cv::Mat img = cv::imread("E:\\6.Testdata\\Bilder\\fruits.jpg");
	//	cv::Mat img = cv::imread("C:\\2.Testdata\\Bilder\\boldt.jpg");
	cv::resize(img, _tmp, cv::Size(img.cols * 5, img.rows * 5), 0, 0, cv::INTER_CUBIC);
	//cv::resize(img, _tmp, cv::Size(), 2, 2, cv::INTER_NEAREST);
	videoOutput->showImage(_tmp);
	//videoOutput->adjustSize();

}

void VideoWidget::zzzzClicked(void)
{
	QSize siz = scrollArea->size();
	setStatusTip(QString::number(siz.width()));
	cv::Mat _tmp;
	cv::Mat img = cv::imread("E:\\6.Testdata\\Bilder\\fruits.jpg");
	//	cv::Mat img = cv::imread("C:\\2.Testdata\\Bilder\\boldt.jpg");
	cv::resize(img, _tmp, cv::Size(siz.width(),siz.height()), 0, 0, cv::INTER_AREA);
	videoOutput->showImage(_tmp);
	//videoOutput->adjustSize();

}

void VideoWidget::paintEvent(QPaintEvent* /*event*/)
{
	//QSize siz = scrollArea->size();
	//lab->setText(QString::number(siz.width()));
	lab->setText(QString::number(scaleFactor*100) + " %");
	//	videoOutput->showImage(currentImg);

}


void VideoWidget::resize(cv::Mat& _tmp, const cv::Mat& img)
{
	if (adjustToWidget) {
		QSize siz = scrollArea->size();
		double wig_w = double(siz.width());
		double wig_h = double(siz.height());
		double img_w = double(img.cols);
		double img_h = double(img.rows);

		if ((wig_w / img_w) > (wig_h / img_h))
			scaleFactor = wig_h / img_h;
		else
			scaleFactor = wig_w / img_w;

		//if( (double(siz.width()) / (double(img.cols)) > (double(siz.height()) / double(img.rows))
		//7 == 5 ? 4 : 3     // evaluates to 3, since 7 is not equal to 5.
	}

	if(scaleFactor > 1.0)
		cv::resize(img, _tmp, cv::Size(img.cols * scaleFactor, img.rows * scaleFactor), 0, 0, cv::INTER_CUBIC);
	else
		cv::resize(img, _tmp, cv::Size(img.cols * scaleFactor, img.rows * scaleFactor), 0, 0, cv::INTER_AREA);

}

void VideoWidget::resizeEvent(QResizeEvent* event)
{
	QWidget::resizeEvent(event);
	updateVideo();
}