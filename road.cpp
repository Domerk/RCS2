//road.cpp

#include "road.h"

//==================================================
//============= ����������� ������ =================
//==================================================

Road::Road(QWidget *parent)
    : QWidget(parent)
{
    painter = new QPainter(); //��������
    setFixedSize(450,450);

    //============ ��������������� ���������� ===============

    level = 1; // ������� - �� ��������� ������

    nc1 = false; // ����� ����� �����
    nc2 = false;
    nc3 = false;
    nc4 = false;

    int i; // �������������� ����������

    srand (time(NULL)); // ��������������� �����
    i = rand()%2;

    if (i == 1) // ���� ��������
    {
        tc1 = 1; // �� ����� ���������� ��� ���
        tc2 = 3;
        tc3 = 1;
        tc4 = 3;
    }
    else // ���� ���
    {
        tc1 = 3; // �� ��� ���
        tc2 = 1;
        tc3 = 3;
        tc4 = 1;
    }

    t1=1; // �������
    t2=1;
    t3=1;
    t4=1;

    for (int i = 0; i<4; i++) // ������ ��������
    {
        times+=1000; // ��������� ��� ���������� �� ���������
        times+=500; // �������� ��, ��� ��� ������� 10 ��
        times+=1000;
    }

    Car1 = new Car(150,-128,1,1); // ������ �������
    Car2 = new Car(450,150,2,2);
    Car3 = new Car(250,450,3,3);
    Car4 = new Car(-128,250,4,4);

    TL1 = new TrafficLight(1,tc1); // ������ ���������
    TL2 = new TrafficLight(2,tc2);
    TL3 = new TrafficLight(3,tc3);
    TL4 = new TrafficLight(4,tc4);

    //============ ��������� ������� � ����� ================

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

    //================= ��������� ������ =====================

    startTimer(10);
}

//==================================================
//================ ��������� ������ ================
//==================================================

void Road::paintEvent(QPaintEvent* event)
{

    painter->begin(this); //�������� �������� � ����
    painter->drawImage(0,0,QImage("://images/crossroad.jpg"));

    // ���������

    TL1->light(t1); // ������� - ������� ��������� �������� �������
    TL1->show(painter); // ��������

    TL2->light(t2);
    TL2->show(painter);

    TL3->light(t3);
    TL3->show(painter);

    TL4->light(t4);
    TL4->show(painter);

    // �������

    if (level == 1) // ���� 1-� �������
    {
        Car1->moving(); // �� 1 �������
        Car1->show(painter);
    }

    if (level == 2) // ���� 2-�
    {
        Car1->moving(); // �� 2 �������
        Car1->show(painter);

        Car2->moving();
        Car2->show(painter);
    }

    if (level == 3) // �� � ��� ����� �� 4-�
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

    painter->end();//����������� ����

}

//==================================================
//================ ������ � �������� ===============
//==================================================

void Road::timerEvent(QTimerEvent *event)
{

    // ��� 1-�� ���������
    if (!nc1) // ���� ���� �� ���������
    {
        t1++; // ����������� ������
    }
    else // �����
    {
        t1=1; // ���������� ������
        nc1=false; // �������� ����
    }

    // ��� 2-�� ���������
    if (!nc2)
    {
        t2++;
    }
    else
    {
        t2=1;
        nc2=false;
    }

    // ��� 3-�� ���������
    if (!nc3)
    {
        t3++;
    }
    else
    {
        t3=1;
        nc3=false;
    }

    // ��� 4-�� ���������
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
//================ ���� ��� ������� ================
//==================================================

void Road::slotDO (QVector <int> vct)
{
    times = vct; // ��������� ������ �������
    emit signalTT(times); // ������� ��� ����������
}

//==================================================
//=============== ���� ��� ���������� ==============
//==================================================

void Road::slotTC (int no)
{
    if (no == 1) // ���� ������ ������ �� 1-�� ���������
    {
        nc1=true; // ��������� ������ ����
    }
    if (no == 2) // ���� �� 2-��
    {
        nc2=true; // �� ������
    }
    if (no == 3) // � �.�.
    {
        nc3=true;
    }
    if (no == 4)
    {
        nc4=true;
    }
}

//==================================================
//================= ���� ��� ������ ================
//==================================================

void Road::slotLEVEL(int nlevel)
{
    level = nlevel; // ��������� �������� ������
}

//==================================================
//================ ���� ��� ������� ================
//==================================================

void Road::slotSTYLE(int n, int s)
{
    emit signalSTYLE(n, s); // �������� ��, ��� ��������
}

//==================================================
//================= ���������� =====================
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
