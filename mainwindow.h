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



extern QImage Mat2QImage(Mat cvImg);
class MainWindow : public QMainWindow,public Ui_MainWindowClass
{
	Q_OBJECT

public:
	
	MainWindow(QWidget *parent = 0, Qt::WFlags flags = 0);
	~MainWindow();
	QImage *image;
	//QImage qimage;//专门来接收mat转换来的图像
	//QImage MainWindow::Mat2QImage(Mat cvImg);
	QImage qimages;

private:
	Mat mimage;
	VideoCapture capTest;
	bool whetherToStop;
	bool whetherToShowInImshow;
	QString filePath;
	void loadXml();
private slots:
	void openImageMethod();
	void getVideoPathSLOT();
	void playVideoSLOT();
	void stopPlayVideoSLOT();
	void drawLineSlOT();
	void test();
	
signals:
	void getData(QString);//信号不用去实现


};



#endif // MAINWINDOW_H
