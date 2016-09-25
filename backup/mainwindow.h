#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include <opencv2/opencv.hpp>
#include <opencv2/imgproc/imgproc.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <opencv2/opencv.hpp>
#include <opencv2/video/video.hpp>


#include <QtGui/QMainWindow>
#include "ui_mainwindow.h"
#include <QtGui/QLabel>
#include <QtGui/QImage>
#include <QtGui/QFileDialog>
#include <QtGui/QGraphicsScene>
#include <QtGui/QMessageBox>
#include <QtGui/QImage>
using namespace cv;
class MainWindow : public QMainWindow,public Ui_MainWindowClass
{
	Q_OBJECT

public:
	
	MainWindow(QWidget *parent = 0, Qt::WFlags flags = 0);
	~MainWindow();

private:
	Mat mimage;
	Mat sequence1,sequence2,sequence3;
	QImage *image;
	QImage qimage;//专门来接收mat转换来的图像
	QString filePath;
	cv::VideoCapture cap;
private slots:
	void openImageMethod();
	void getVideoPathSLOT();
	void playVideoSLOT();
	QImage Mat2QImage(cv::Mat cvImg);

};

#endif // MAINWINDOW_H
