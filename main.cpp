#include "mainwindow.h"
#include <QtGui/QApplication>
#include <QtCore/QTextCodec>
#include <QtGui/QFont>
int main(int argc, char *argv[])
{
	QTextCodec *textCode = QTextCodec::codecForLocale();//以下四行解决了中文路劲出错的问题
	QTextCodec::setCodecForCStrings( textCode );
	QTextCodec::setCodecForLocale( textCode );
	QTextCodec::setCodecForTr( textCode );
	QApplication a(argc, argv);
	QApplication::setStyle("plastique");//设置风格
	MainWindow w;
	QFont font;
	font.setFamily(("consola"));//设置文字字体(QString)
	w.setFont(font);
	w.setWindowTitle("车流量监控系统");
	w.setWindowIcon(QIcon("game.ico"));
	w.show();
	

	return a.exec();
}
