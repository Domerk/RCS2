//widget_style.cpp

#include "widget_style.h"

//==================================================
//=========== конструктор окна настроек ============
//==================================================

WidgetStyle::WidgetStyle(QWidget *parent)
    : QWidget(parent)

{
    //================== заголовок окна =====================

    setWindowTitle(tr("Вид автомобилей"));
    setFixedSize(400,300);

    //================== содержимое окна =====================

     vb = new QVBoxLayout; // компоновки
     gl = new QGridLayout;

     t1 = new QLabel(tr("<H3>Выберите автомобиль</H3>"));
     vb->addWidget(t1);

     spb = new QSpinBox; // спинбокс
     spb->setValue(1); // значение по умолчанию 1
     spb->setMinimum(1); // минимальное значение 1
     spb->setMaximum(4); // максимальное значение 4
     spb->setFixedWidth(60); // длинна 60

     vb->addWidget(spb); // добавляем спинбокс в компановку

     t2 = new QLabel(tr("Номер автомобиля соответсвует номеру уровня."));
     vb->addWidget(t2); // добавляем текст в компановку

     t3 = new QLabel(tr("<H3>Выберите новый дизайн</H3>"));
     vb->addWidget(t3);


     // создаём пиксмапы
     QPixmap  car1 ("://images/1car4.jpg");
     QPixmap  car2 ("://images/2car4.jpg");
     QPixmap  car3 ("://images/3car4.jpg");
     QPixmap  car4 ("://images/4car4.jpg");

     pb1 = new QPushButton; // создаём кнопку
     pb1->setIcon(car1); // в качестве конки берём пиксмап
     pb1->setIconSize(car1.size()); // размер иконки равен размеру пиксмапа
     connect(pb1, SIGNAL(clicked()), SLOT(C1())); // соединяем кнопку со слотом

     pb2 = new QPushButton;
     pb2->setIcon(car2);
     pb2->setIconSize(car1.size());
     connect(pb2, SIGNAL(clicked()), SLOT(C2()));

     pb3 = new QPushButton;
     pb3->setIcon(car3);
     pb3->setIconSize(car1.size());
     connect(pb3, SIGNAL(clicked()), SLOT(C3()));

     pb4 = new QPushButton;
     pb4->setIcon(car4);
     pb4->setIconSize(car1.size());
     connect(pb4, SIGNAL(clicked()), SLOT(C4()));

     gl->addWidget(pb1, 0, 0); // добавляем кнопки в табличную компановку
     gl->addWidget(pb2, 0, 1);
     gl->addWidget(pb3, 1, 0);
     gl->addWidget(pb4, 1, 1);

     vb->addLayout(gl); // добавляем табличную компановку в вертикальную компановку

     t4 = new QLabel(tr("Для внесения изменений нажмите на кнопку <Br> с понравившимся изображением."));
     vb->addWidget(t4); // добавляем текст

     this->setLayout(vb); // добавляем вертикальную компановку в виджет

}

//==================================================
//===================== слоты ======================
//==================================================

void WidgetStyle::C1()
{
    int a = 1; // это будет номер картинки
    int s = spb->value(); // а это - номер автомобиля
    emit signalSTYLE(s, a); // высылаем сигнал
}

void WidgetStyle::C2()
{
    int a = 2;
    int s = spb->value();
    emit signalSTYLE(s, a);
}

void WidgetStyle::C3()
{
    int a = 3;
    int s = spb->value();
    emit signalSTYLE(s, a);
}

void WidgetStyle::C4()
{
    int a = 4;
    int s = spb->value();
    emit signalSTYLE(s, a);
}

//==================================================
//================== деструктор ====================
//==================================================

WidgetStyle::~WidgetStyle()
{
    delete pb1;
    delete pb2;
    delete pb3;
    delete pb4;
    delete spb;
    delete vb;
    delete gl;
    delete t1;
    delete t2;
    delete t3;
    delete t4;
}
//====================================================


