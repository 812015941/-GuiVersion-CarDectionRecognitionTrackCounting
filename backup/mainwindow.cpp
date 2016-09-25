#include "mainwindow.h"


using namespace cv;
MainWindow::MainWindow(QWidget *parent, Qt::WFlags flags)
	: QMainWindow(parent, flags)
{
	setupUi(this);
	this->image=new QImage();

	connect(OpenBtn,SIGNAL(clicked()),this,SLOT(getVideoPathSLOT()));
	connect(PlayBtn,SIGNAL(clicked()),this,SLOT(playVideoSLOT()));
}

MainWindow::~MainWindow()
{

}

void MainWindow::openImageMethod()
{
	QString fileName = QFileDialog::getOpenFileName(  
		this, "open image file",  
		".",  
		"Image files (*.bmp *.jpg *.pbm *.pgm *.png *.ppm *.xbm *.xpm);;All files (*.*)");  
	if(image->load(fileName))
	{
		QGraphicsScene *scene=new QGraphicsScene;
		scene->addPixmap(QPixmap::fromImage(*image));
		GraphicsView->setScene(scene);
		GraphicsView->resize(image->width()+10,image->height()+10);
		GraphicsView->show();
	}
	
}
void MainWindow::getVideoPathSLOT()//获取文件路径;
{
	this->filePath = QFileDialog::getOpenFileName(  
		this, "open image file",  
		".",  
		"Video files (*.bmp *.jpg *.pbm *.pgm *.png *.mp4 *.avi *.nsf *.flv *.mkv);;All files (*.*)");  
	QMessageBox::warning(0,"PATH",this->filePath,QMessageBox::Yes);
	
}
void MainWindow::playVideoSLOT()//play!;
{
	//展示在imshow中
	cap.open(this->filePath.toAscii().data());
	while(waitKey(1)!=27)
	{
		cap>>sequence1;
		if (!sequence1.data)
			break;
		int H=400;		
		int W = H*sequence1.cols/sequence1.rows;	
		cv::resize(sequence1, sequence1, Size(W, H));
		namedWindow("sequence1",CV_WINDOW_AUTOSIZE|CV_GUI_NORMAL);
		moveWindow("sequence1",0,0);
		imshow("sequence1",sequence1);





		//展示在qt中
		//this->qimage=this->Mat2QImage(sequence1);
		//QGraphicsScene *scene=new QGraphicsScene;
		//scene->addPixmap(QPixmap::fromImage(qimage));
		//this->GraphicsView->setScene(scene);
		////this->GraphicsView->resize(image->width()+10,image->height()+10);
		//this->GraphicsView->show();
	}
	
	
	
	

}

QImage MainWindow::Mat2QImage(Mat cvImg)
{
	QImage qImg;
	if(cvImg.channels()==3)                             //3 channels color image
	{

		cv::cvtColor(cvImg,cvImg,CV_BGR2RGB);
		qImg =QImage((const unsigned char*)(cvImg.data),
			cvImg.cols, cvImg.rows,
			cvImg.cols*cvImg.channels(),
			QImage::Format_RGB888);
	}
	else if(cvImg.channels()==1)                    //grayscale image
	{
		qImg =QImage((const unsigned char*)(cvImg.data),
			cvImg.cols,cvImg.rows,
			cvImg.cols*cvImg.channels(),
			QImage::Format_Indexed8);
	}
	else
	{
		qImg =QImage((const unsigned char*)(cvImg.data),
			cvImg.cols,cvImg.rows,
			cvImg.cols*cvImg.channels(),
			QImage::Format_RGB888);
	}

	return qImg;

}