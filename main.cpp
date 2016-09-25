#include "mainwindow.h"
#include <QtGui/QApplication>
#include <QtCore/QTextCodec>
#include <QtGui/QFont>
int main(int argc, char *argv[])
{
	QTextCodec *textCode = QTextCodec::codecForLocale();//�������н��������·�����������
	QTextCodec::setCodecForCStrings( textCode );
	QTextCodec::setCodecForLocale( textCode );
	QTextCodec::setCodecForTr( textCode );
	QApplication a(argc, argv);
	QApplication::setStyle("plastique");//���÷��
	MainWindow w;
	QFont font;
	font.setFamily(("consola"));//������������(QString)
	w.setFont(font);
	w.setWindowTitle("���������ϵͳ");
	w.setWindowIcon(QIcon("game.ico"));
	w.show();
	

	return a.exec();
}
