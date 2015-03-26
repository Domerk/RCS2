//road.cpp

#include "road.h"

//==================================================
//============= конструктор дороги =================
//==================================================

Road::Road(QWidget *parent)
    : QWidget(parent)
{
    painter = new QPainter(); //художник
    setFixedSize(450,450);

    //============ вспомогательные переменные ===============

    level = 1; // уровень - по умолчанию первый

    nc1 = false; // флаги смены цвета
    nc2 = false;
    nc3 = false;
    nc4 = false;

    int i; // дополнительная переменная

    srand (time(NULL)); // псевдослучайное число
    i = rand()%2;

    if (i == 1) // если единичка
    {
        tc1 = 1; // то цвета чередуются вот так
        tc2 = 3;
        tc3 = 1;
        tc4 = 3;
    }
    else // если нет
    {
        tc1 = 3; // то вот так
        tc2 = 1;
        tc3 = 3;
        tc4 = 1;
    }

    t1=1; // таймеры
    t2=1;
    t3=1;
    t4=1;

    for (int i = 0; i<4; i++) // массив таймеров
    {
        times+=1000; // заполняем его значениями по умолчанию
        times+=500; // учитывая то, что шаг таймера 10 мс
        times+=1000;
    }

    Car1 = new Car(150,-128,1,1); // создам машинки
    Car2 = new Car(450,150,2,2);
    Car3 = new Car(250,450,3,3);
    Car4 = new Car(-128,250,4,4);

    TL1 = new TrafficLight(1,tc1); // создаём светофоры
    TL2 = new TrafficLight(2,tc2);
    TL3 = new TrafficLight(3,tc3);
    TL4 = new TrafficLight(4,tc4);

    //============ соединяем сигналы и слоты ================

    connect(this, SIGNAL(signalTT(QVector<int>)), TL1, SLOT(slotTT(QVector<int>)));
    connect(this, SIGNAL(signalTT(QVector<int>)), TL2, SLOT(slotTT(QVector<int>)));
    connect(this, SIGNAL(signalTT(QVector<int>)), TL3, SLOT(slotTT(QVector<int>)));
    connect(this, SIGNAL(signalTT(QVector<int>)), TL4, SLOT(slotTT(QVector<int>)));

    connect(TL1, SIGNAL(signalR(int)), this, SLOT(slotTC(int)));
    connect(TL2, SIGNAL(signalR(int)), this, SLOT(slotTC(int)));
    connect(TL3, SIGNAL(signalR(int)), this, SLOT(slotTC(int)));
    connect(TL4, SIGNAL(signalR(int)), this, SLOT(slotTC(int)));

    connect(TL1, SIGNAL(signalTC(int, int)), Car1, SLOT(slotTC(int,int)));
    connect(TL1, SIGNAL(signalTC(int, int)), Car2, SLOT(slotTC(int,int)));
    connect(TL1, SIGNAL(signalTC(int, int)), Car3, SLOT(slotTC(int,int)));
    connect(TL1, SIGNAL(signalTC(int, int)), Car4, SLOT(slotTC(int,int)));

    connect(TL2, SIGNAL(signalTC(int,int)), Car1, SLOT(slotTC(int,int)));
    connect(TL2, SIGNAL(signalTC(int,int)), Car2, SLOT(slotTC(int,int)));
    connect(TL2, SIGNAL(signalTC(int,int)), Car3, SLOT(slotTC(int,int)));
    connect(TL2, SIGNAL(signalTC(int,int)), Car4, SLOT(slotTC(int,int)));

    connect(TL3, SIGNAL(signalTC(int,int)), Car1, SLOT(slotTC(int,int)));
    connect(TL3, SIGNAL(signalTC(int,int)), Car2, SLOT(slotTC(int,int)));
    connect(TL3, SIGNAL(signalTC(int,int)), Car3, SLOT(slotTC(int,int)));
    connect(TL3, SIGNAL(signalTC(int,int)), Car4, SLOT(slotTC(int,int)));

    connect(TL4, SIGNAL(signalTC(int,int)), Car1, SLOT(slotTC(int,int)));
    connect(TL4, SIGNAL(signalTC(int,int)), Car2, SLOT(slotTC(int,int)));
    connect(TL4, SIGNAL(signalTC(int,int)), Car3, SLOT(slotTC(int,int)));
    connect(TL4, SIGNAL(signalTC(int,int)), Car4, SLOT(slotTC(int,int)));

    connect (Car1, SIGNAL(siganlXY(int,int,int,int,bool,bool)), Car2, SLOT(slotXY(int,int,int,int,bool,bool)));
    connect (Car1, SIGNAL(siganlXY(int,int,int,int,bool,bool)), Car3, SLOT(slotXY(int,int,int,int,bool,bool)));
    connect (Car1, SIGNAL(siganlXY(int,int,int,int,bool,bool)), Car4, SLOT(slotXY(int,int,int,int,bool,bool)));

    connect (Car2, SIGNAL(siganlXY(int,int,int,int,bool,bool)), Car1, SLOT(slotXY(int,int,int,int,bool,bool)));
    connect (Car2, SIGNAL(siganlXY(int,int,int,int,bool,bool)), Car3, SLOT(slotXY(int,int,int,int,bool,bool)));
    connect (Car2, SIGNAL(siganlXY(int,int,int,int,bool,bool)), Car4, SLOT(slotXY(int,int,int,int,bool,bool)));

    connect (Car3, SIGNAL(siganlXY(int,int,int,int,bool,bool)), Car1, SLOT(slotXY(int,int,int,int,bool,bool)));
    connect (Car3, SIGNAL(siganlXY(int,int,int,int,bool,bool)), Car2, SLOT(slotXY(int,int,int,int,bool,bool)));
    connect (Car3, SIGNAL(siganlXY(int,int,int,int,bool,bool)), Car4, SLOT(slotXY(int,int,int,int,bool,bool)));

    connect (Car4, SIGNAL(siganlXY(int,int,int,int,bool,bool)), Car1, SLOT(slotXY(int,int,int,int,bool,bool)));
    connect (Car4, SIGNAL(siganlXY(int,int,int,int,bool,bool)), Car2, SLOT(slotXY(int,int,int,int,bool,bool)));
    connect (Car4, SIGNAL(siganlXY(int,int,int,int,bool,bool)), Car3, SLOT(slotXY(int,int,int,int,bool,bool)));

    connect (this, SIGNAL(signalSTYLE(int,int)), Car1, SLOT(slotSTYLE(int,int)));
    connect (this, SIGNAL(signalSTYLE(int,int)), Car2, SLOT(slotSTYLE(int,int)));
    connect (this, SIGNAL(signalSTYLE(int,int)), Car3, SLOT(slotSTYLE(int,int)));
    connect (this, SIGNAL(signalSTYLE(int,int)), Car4, SLOT(slotSTYLE(int,int)));

    //================= запускаем таймер =====================

    startTimer(10);
}

//==================================================
//================ рисование дороги ================
//==================================================

void Road::paintEvent(QPaintEvent* event)
{

    painter->begin(this); //начинаем рисовать в окне
    painter->drawImage(0,0,QImage("://images/crossroad.jpg"));

    // светофоры

    TL1->light(t1); // светить - передаём светофору значение таймера
    TL1->show(painter); // показать

    TL2->light(t2);
    TL2->show(painter);

    TL3->light(t3);
    TL3->show(painter);

    TL4->light(t4);
    TL4->show(painter);

    // машинки

    if (level == 1) // если 1-й уровень
    {
        Car1->moving(); // то 1 машинка
        Car1->show(painter);
    }

    if (level == 2) // если 2-й
    {
        Car1->moving(); // то 2 машинки
        Car1->show(painter);

        Car2->moving();
        Car2->show(painter);
    }

    if (level == 3) // ну и так далее до 4-х
    {
        Car1->moving();
        Car1->show(painter);

        Car2->moving();
        Car2->show(painter);

        Car3->moving();
        Car3->show(painter);
    }

    if (level == 4)
    {
        Car1->moving();
        Car1->show(painter);

        Car2->moving();
        Car2->show(painter);

        Car3->moving();
        Car3->show(painter);

        Car4->moving();
        Car4->show(painter);
    }

    painter->end();//освобождаем окно

}

//==================================================
//================ работа с таймером ===============
//==================================================

void Road::timerEvent(QTimerEvent *event)
{

    // для 1-го светофора
    if (!nc1) // если цвет не изменился
    {
        t1++; // увеличиваем таймер
    }
    else // иначе
    {
        t1=1; // сбрасываем таймер
        nc1=false; // опускаем флаг
    }

    // для 2-го светофора
    if (!nc2)
    {
        t2++;
    }
    else
    {
        t2=1;
        nc2=false;
    }

    // для 3-го светофора
    if (!nc3)
    {
        t3++;
    }
    else
    {
        t3=1;
        nc3=false;
    }

    // для 4-го светофора
    if (!nc4)
    {
        t4++;
    }
    else
    {
        t4=1;
        nc4=false;
    }

    repaint();
}

//==================================================
//================ слот для времени ================
//==================================================

void Road::slotDO (QVector <int> vct)
{
    times = vct; // принимаем вектор времени
    emit signalTT(times); // передаём его светофорам
}

//==================================================
//=============== слот для светофоров ==============
//==================================================

void Road::slotTC (int no)
{
    if (no == 1) // если сигнал пришёл от 1-го светофора
    {
        nc1=true; // поднимаем первый флаг
    }
    if (no == 2) // если от 2-го
    {
        nc2=true; // то второй
    }
    if (no == 3) // и т.д.
    {
        nc3=true;
    }
    if (no == 4)
    {
        nc4=true;
    }
}

//==================================================
//================= слот для уровня ================
//==================================================

void Road::slotLEVEL(int nlevel)
{
    level = nlevel; // сохраняем значение уровня
}

//==================================================
//================ слот для дизайна ================
//==================================================

void Road::slotSTYLE(int n, int s)
{
    emit signalSTYLE(n, s); // высылаем то, что получили
}

//==================================================
//================= деструктор =====================
//==================================================

Road::~Road()
{
    delete painter;
    delete Car1;
    delete Car2;
    delete Car3;
    delete Car4;
    delete TL1;
    delete TL2;
    delete TL3;
    delete TL4;
}

//==================================================
