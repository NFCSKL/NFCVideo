#ifndef VIDEOWIDGET_H
#define VIDEOWIDGET_H

#include <QWidget>
#include <cvimagewidget.h>
#include <opencv2\opencv.hpp>
#include <qscrollarea.h>
#include <qlabel.h>


class VideoWidget : public QWidget
{
	Q_OBJECT

public:
	VideoWidget(QWidget *parent);
	~VideoWidget();

	void showImage(cv::Mat img);
	void updateVideo(void);

private slots:
	void nextClicked(void);
	void prevClicked(void);
	void playClicked(void);
	void zoomInClicked(void);
	void normClicked(void);
	void fitClicked(void);
	void xxxxClicked(void);
	void yyyyClicked(void);
	void zzzzClicked(void);

	void paintEvent(QPaintEvent* /*event*/);

private:
	void resize(cv::Mat& _tmp, const cv::Mat& img);
	void resizeEvent(QResizeEvent * event);
	CVImageWidget*	videoOutput;
	QScrollArea*	scrollArea;
	QLabel*			videoLabel;
	QLabel*			lab;
	double			scaleFactor;
	bool			adjustToWidget;

	cv::Mat	currentImg;
};

#endif // VIDEOWIDGET_H
