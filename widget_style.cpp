//widget_style.cpp

#include "widget_style.h"

//==================================================
//=========== ����������� ���� �������� ============
//==================================================

WidgetStyle::WidgetStyle(QWidget *parent)
    : QWidget(parent)

{
    //================== ��������� ���� =====================

    setWindowTitle(tr("��� �����������"));
    setFixedSize(400,300);

    //================== ���������� ���� =====================

     vb = new QVBoxLayout; // ����������
     gl = new QGridLayout;

     t1 = new QLabel(tr("<H3>�������� ����������</H3>"));
     vb->addWidget(t1);

     spb = new QSpinBox; // ��������
     spb->setValue(1); // �������� �� ��������� 1
     spb->setMinimum(1); // ����������� �������� 1
     spb->setMaximum(4); // ������������ �������� 4
     spb->setFixedWidth(60); // ������ 60

     vb->addWidget(spb); // ��������� �������� � ����������

     t2 = new QLabel(tr("����� ���������� ������������ ������ ������."));
     vb->addWidget(t2); // ��������� ����� � ����������

     t3 = new QLabel(tr("<H3>�������� ����� ������</H3>"));
     vb->addWidget(t3);


     // ������ ��������
     QPixmap  car1 ("://images/1car4.jpg");
     QPixmap  car2 ("://images/2car4.jpg");
     QPixmap  car3 ("://images/3car4.jpg");
     QPixmap  car4 ("://images/4car4.jpg");

     pb1 = new QPushButton; // ������ ������
     pb1->setIcon(car1); // � �������� ����� ���� �������
     pb1->setIconSize(car1.size()); // ������ ������ ����� ������� ��������
     connect(pb1, SIGNAL(clicked()), SLOT(C1())); // ��������� ������ �� ������

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

     gl->addWidget(pb1, 0, 0); // ��������� ������ � ��������� ����������
     gl->addWidget(pb2, 0, 1);
     gl->addWidget(pb3, 1, 0);
     gl->addWidget(pb4, 1, 1);

     vb->addLayout(gl); // ��������� ��������� ���������� � ������������ ����������

     t4 = new QLabel(tr("��� �������� ��������� ������� �� ������ <Br> � ������������� ������������."));
     vb->addWidget(t4); // ��������� �����

     this->setLayout(vb); // ��������� ������������ ���������� � ������

}

//==================================================
//===================== ����� ======================
//==================================================

void WidgetStyle::C1()
{
    int a = 1; // ��� ����� ����� ��������
    int s = spb->value(); // � ��� - ����� ����������
    emit signalSTYLE(s, a); // �������� ������
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
//================== ���������� ====================
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


