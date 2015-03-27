// main.cpp

#include <QtGui>
#include "widget.h"
#include "road.h"
#include "options.h"


int main (int argc, char **argv)
{
    QApplication app (argc, argv);
    QResource::registerResource("images.qrc"); // подключаем файл ресурсов

    QTextCodec::setCodecForTr(QTextCodec::codecForName("UTF-8"));

    Widget w; //создаём окошко
    w.show(); //показываем окошко

    return app.exec();
}

