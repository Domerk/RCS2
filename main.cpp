// main.cpp

#include <QtGui>
#include "widget.h"
#include "road.h"
#include "options.h"


int main (int argc, char **argv)
{
    QApplication app (argc, argv);
    QResource::registerResource("images.qrc"); // ���������� ���� ��������

    QTextCodec::setCodecForTr(QTextCodec::codecForName("System"));

    Widget w; //������ ������
    w.show(); //���������� ������

    return app.exec();
}

