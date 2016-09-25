#include "mainwindow.h"
#include "BackMod.h"

extern Mat sequence2;
extern int countNum1,countNum2,countNum3;
class MySVM : public CvSVM
{
public:
	//���SVM�ľ��ߺ����е�alpha����
	double * get_alpha_vector()
	{
		return this->decision_func->alpha;
	}

	//���SVM�ľ��ߺ����е�rho����,��ƫ����
	float get_rho()
	{
		return this->decision_func->rho;
	}
};
MySVM svm1=MySVM();
MySVM svm2=MySVM();
MySVM svm3=MySVM();

using namespace std;
using namespace cv;
MainWindow::MainWindow(QWidget *parent, Qt::WFlags flags)
	: QMainWindow(parent, flags)
{
	setupUi(this);
	this->image=new QImage();
	this->whetherToStop=false;
	this->whetherToShowInImshow=false;
	connect(OpenBtn,SIGNAL(clicked()),this,SLOT(getVideoPathSLOT()));
	connect(PlayBtn,SIGNAL(clicked()),this,SLOT(playVideoSLOT()));
	//connect(PlayBtn,SIGNAL(clicked()),this,SLOT(test()));//for test;
	connect(this,SIGNAL(getData(QString)),imageLabel,SLOT(setText(QString)));
	connect(StopBtn,SIGNAL(clicked()),this,SLOT(stopPlayVideoSLOT()));
	connect(DrawBtn,SIGNAL(clicked()),this,SLOT(drawLineSlOT()));
	connect(ExitBtn,SIGNAL(clicked()),this,SLOT(close()));

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
void MainWindow::getVideoPathSLOT()//��ȡ�ļ�·��;
{
	whetherToStop=false;
	this->filePath = QFileDialog::getOpenFileName(  
		this, "open image file",  
		".",  
		"Video files (*.bmp *.jpg *.pbm *.pgm *.png *.mp4 *.avi *.nsf *.flv *.mkv);;All files (*.*)");  
	QMessageBox::warning(0,"PATH",this->filePath,QMessageBox::Yes);
	
}

void MainWindow::playVideoSLOT()//play!;
{
	
	
	if (filePath==NULL)
	{
		QMessageBox::warning(0,"����","��ѡ����Ƶ�ļ���",QMessageBox::Yes);
		return;
	}else 
	{
		//��ȡxml
		loadXml();
		
		QByteArray ba=filePath.toLatin1();

		char *tmp=ba.data();
		video=tmp;
		//BackModel m;
		//m.setVideoPath(tmp);
		//m.BackMode();//ֻ�ǽ��д�����չʾ��
		////////////////////////////////////
		Mat dstimg1, dstimg2, dstimg3;
		BackgroundSubtractorMOG mog;
		cap.open(video);
		while (waitKey(1) != 10)
		{

			if (whetherToStop==true||filePath==NULL)
			{
				QMessageBox::warning(0,"ֹͣ","������ѡ����Ƶ�ļ���",QMessageBox::Yes);
				cap.release();
				break;
			}
			cap >> sequence1;
			if (!sequence1.data)
				break;
			int H=500;		
			int W = H*sequence1.cols/sequence1.rows;		
			cv::resize(sequence1, sequence1, Size(W, H));//����ȷ�����ڴ�С
			cvtColor(sequence1, sequence1, CV_BGR2GRAY);
			cap >> sequence2;
			sequence2.copyTo(sequence21);
			cv::resize(sequence21,sequence21,Size(W,H));
			if (!sequence2.data)
				break;
			cv::resize(sequence2, sequence2, Size(W, H));
			cap>>sequence3;
			cv::resize(sequence3, sequence3, Size(W, H));
			cvtColor(sequence2, sequence2, CV_BGR2GRAY);
			subtract(sequence1, sequence2, dstimg1);
			threshold(dstimg1, dstimg1, 20, 255, THRESH_BINARY);
			//��˹
			mog(sequence2, dstimg2, 0.01);
			threshold(dstimg2, dstimg2, 50, 255, THRESH_BINARY);
			foreGround = Mat::zeros(dstimg2.size(), CV_8UC1);



			//�ϲ����룩
			H=dstimg1.rows;
			W=dstimg1.cols;
			for (int i = 0;i < H;i++)
			{
				uchar *data = foreGround.ptr<uchar>(i);
				uchar *data1 = dstimg1.ptr<uchar>(i);
				uchar *data2 = dstimg2.ptr<uchar>(i);
				for (int j = 0;j < W;j++)
				{
					if (data1[j] ==255&&data2[j] == 255)//����֡��õ���ͼ�����ش���5�ұ�����ģ�õ�������Ϊ255ʱΪǰ��ͼ
						data[j] = 255;
					else
						data[j] = 0;
				}
			}
			//����5��
			Mat element = getStructuringElement(MORPH_RECT, Size(9, 9));
			dilate(foreGround, foreGround, element, Point(-1, -1), 5);
			erode(foreGround, foreGround, element, Point(-1, -1), 2);
			dilate(foreGround, foreGround, element, Point(-1, -1), 3);
			vector<vector<Point>> contours;
			vector<Vec4i> hierarchy;
			findContours(foreGround, contours, hierarchy, RETR_TREE, CHAIN_APPROX_SIMPLE, Point(0, 0));
			vector<vector<Point>> contours_poly(contours.size());


			vector<Rect> boundrect(contours.size());
			int len=contours.size();
			for (size_t i = 0; i < len; i++)
			{
				approxPolyDP(Mat(contours[i]), contours_poly[i], 10, 1);  //�����ڶ�������Խ�����ľ��ο�Խ�١�����Ǻܴ󡣡�
				boundrect[i] = boundingRect(Mat(contours_poly[i]));
			}	
			///////////////���ֵļ�⣨�Ѿ�����Բ�㣩
			vector<Rect> boundrect1 = CarSift(boundrect, sequence2,1);//ɸѡ�г��ľ���,����Ϊ1
			vector<Rect> boundrect2 = CarSift(boundrect, sequence2,2);
			vector<Rect> boundrect3 = CarSift(boundrect, sequence2,3);
			vector<Rect> resultRectTYC1=meanshiftTYC(boundrect1,sequence2,sequence21,1);//boundrect1Ϊʶ���ÿһ֡�Ŀ򣨻���˸�� sequence2Ϊgreyͼ sequence3Ϊԭͼ
			vector<Rect> resultRectTYC2=meanshiftTYC(boundrect2,sequence2,sequence21,2);
			vector<Rect> resultRectTYC3=meanshiftTYC(boundrect3,sequence2,sequence21,3);
			//�ڻ��ߺ�Ž��м���
			if (selection.width==0&&selection.height==0)//Ĭ��
			{
				selection  = Rect(Point(0,int(sequence2.rows*0.5)),Point(sequence2.cols,sequence2.rows));
				origin=selection.tl();
				result=selection.br();
			}
			if(!selectObject&&selection.width>0&&selection.height>0)
			{

				for (size_t i = 0; i < resultRectTYC1.size(); i++)
				{
					int rectny=resultRectTYC1[i].tl().y;
					int d=getD(rectny,selectObject,selection,origin);
					savePoint(resultRectTYC1[i].tl(),resultRectTYC1[i],d,rectps1,Threshold,countNum1,1);
				}

				for (size_t i = 0; i < resultRectTYC2.size(); i++)
				{
					int rectny=resultRectTYC2[i].tl().y;
					int d=getD(rectny,selectObject,selection,origin);
					savePoint(resultRectTYC2[i].tl(),resultRectTYC2[i],d,rectps2,Threshold,countNum2,2);
				}

				for (size_t i = 0; i < resultRectTYC3.size(); i++)
				{
					int rectny=resultRectTYC3[i].tl().y;
					int d=getD(rectny,selectObject,selection,origin);
					savePoint(resultRectTYC3[i].tl(),resultRectTYC3[i],d,rectps3,Threshold,countNum3,3);
				}
			}

		

			if(!selectObject&&selection.width>0&&selection.height>0)
			{
				int width = abs(origin.x - result.x);  
				int height = abs(origin.y - result.y);  
				if (width == 0 || height == 0)  
				{  

					printf("width == 0 || height == 0");  
					return;  
				}  
				dst = sequence2(Rect(min(result.x,origin.x),min(result.y,origin.y),width,height));  
				cv::line(sequence2,Point(0,origin.y),Point(sequence2.cols,origin.y),Scalar(30,70,150),2,8,0);

			}
			namedWindow("tmp");
			moveWindow("tmp",0,0);
			resizeWindow("tmp",0,0);
			if (whetherToShowInImshow==true)
			{
				namedWindow("sequence2");
				moveWindow("sequence2",0,0);
				imshow("sequence2",sequence2);//��qt����ʾͼƬ�Ĵ���
				setMouseCallback("sequence2",on_mouse,0);
			}
			if (whetherToShowInImshow==false)
			{
				destroyWindow("sequence2");
			}


			//չʾ��qt��

			QImage tmp=Mat2QImage(sequence2);
			QGraphicsScene *scene=new QGraphicsScene;
			scene->addPixmap(QPixmap::fromImage(tmp));
			this->GraphicsView->setScene(scene);
			//this->GraphicsView->resize(image->width()+10,image->height()+10);
			this->GraphicsView->show();
			//??????

			//
			//��signal�����ź�
			QString countNum1tmp=QString::number(countNum1,10);
			QString countNum2tmp=QString::number(countNum2,10);
			QString countNum3tmp=QString::number(countNum3,10);
			QString showInWindowLabel=
				"Small:"+countNum1tmp+"\n"
				+"Middle:"+countNum2tmp+"\n"
				+"Big:"+countNum3tmp;

			emit getData(showInWindowLabel);
		}
	}
	
	

}
void MainWindow::stopPlayVideoSLOT()
{

	whetherToStop=true;
	filePath.clear();
}
	
void MainWindow::drawLineSlOT()
{
	if (whetherToShowInImshow==false)
	{
		whetherToShowInImshow=true;
	}else if (whetherToShowInImshow==true)
	{
		whetherToShowInImshow=false;
	}
	
}
void MainWindow::loadXml()
{
	QMessageBox::warning(0,"����xml��","���ȷ�������ػ���ѧϰ�ļ�����ȴ�",QMessageBox::Yes);
	char *xmlPath1 = "E:/TestVideo/svm1.xml";
	char *xmlPath2 = "E:/TestVideo/svm2.xml";
	char *xmlPath3 = "E:/TestVideo/svm3.xml";
	///////�Ȳ�ִ��
	svm1.load(xmlPath1);
	svm2.load(xmlPath2);
	svm3.load(xmlPath3);
	QMessageBox::warning(0,"����xml�ɹ�","���سɹ����������",QMessageBox::Yes);
}

void MainWindow::test()
{
	
	cap.open(this->filePath.toAscii().data());
	while(waitKey(1)!=27)
	{
		cap>>sequence2;
		
		//int H=400;		
		//int W = H*testMat.cols/testMat.rows;	
		//cv::resize(testMat, testMat, Size(W, H));
		cvtColor(sequence2, sequence2, CV_BGR2GRAY);
		cv::resize(sequence2, sequence2, Size(500, 600));
		imshow("testMat",sequence2);
		//
		qimages=Mat2QImage(sequence2);
		QGraphicsScene *scene=new QGraphicsScene;
		scene->addPixmap(QPixmap::fromImage(qimages));
		this->GraphicsView->setScene(scene);
		//this->GraphicsView->resize(image->width()+10,image->height()+10);
		this->GraphicsView->show();
		countNum1=countNum1+1;
		//��signal�����ź�
		QString tmp=QString::number(countNum1,10);
		emit getData(tmp);
	}
}

QImage Mat2QImage(Mat cvImg)
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