#include "mainwindow.h"
#include <QtGui/QApplication>
#include <QtCore/QTextCodec>
int main(int argc, char *argv[])
{
	QTextCodec *textCode = QTextCodec::codecForLocale();//以下四行解决了中文路劲出错的问题
	QTextCodec::setCodecForCStrings( textCode );
	QTextCodec::setCodecForLocale( textCode );
	QTextCodec::setCodecForTr( textCode );
	QApplication a(argc, argv);
	MainWindow w;
	w.show();
	return a.exec();
}
