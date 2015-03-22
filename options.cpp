// options.cpp

#include "options.h"

const int M_RED = 5; // ����������� �������� �������
const int M_YELLOW = 2;
const int M_GREEN = 5;

const int DEFAULT_RED = 10; // ���������
const int DEFAULT_YELLOW = 5;
const int DEFAULT_GREEN = 10;

Options::Options(QWidget *parent)
    : QWidget(parent)
{
    setFixedSize(200,450); // ������������� ������
    vb = new QVBoxLayout(); // ������������ ����������



    //============= Trafficligne 1 ================

    lTR1 = new QLabel(tr("<H3>�������� 1</H3>"));
    vb->addWidget(lTR1);
    this->setLayout(vb);

    gl1 = new QGridLayout; // �������� ����������

    lred1 = new QLabel(tr("�������")); // �������
    sred1 = new QSpinBox; // ������ �����
    sred1->setMinimum(M_RED); // ����������� ��������
    sred1->setValue(DEFAULT_RED); // ������� ��������
    sred1->setSuffix(tr(" ���.")); // ������� ���������

    lyellow1 = new QLabel(tr("Ƹ����"));
    syellow1 = new QSpinBox;
    syellow1->setMinimum(M_YELLOW);
    syellow1->setValue(DEFAULT_YELLOW);
    syellow1->setSuffix(tr(" ���."));

    lgreen1 = new QLabel(tr("������"));
    sgreen1 = new QSpinBox;
    sgreen1->setMinimum(M_GREEN);
    sgreen1->setValue(DEFAULT_GREEN);
    sgreen1->setSuffix(tr(" ���."));

    gl1->addWidget(lred1, 0, 0); // ��������� �������� � ����������
    gl1->addWidget(sred1, 0, 1);

    gl1->addWidget(lyellow1, 1, 0);
    gl1->addWidget(syellow1, 1, 1);

    gl1->addWidget(lgreen1, 2, 0);
    gl1->addWidget(sgreen1, 2, 1);

    vb->addLayout(gl1); // ��������� ��������� ���������� � ������������ ����������
    this->setLayout(vb);

    //============= Trafficligne 2 ================

    lTR2 = new QLabel(tr("<H3>�������� 2</H3>"));
    vb->addWidget(lTR2);
    this->setLayout(vb);

    gl2 = new QGridLayout;

    lred2 = new QLabel(tr("�������"));
    sred2 = new QSpinBox;
    sred2->setMinimum(M_RED);
    sred2->setValue(DEFAULT_RED);
    sred2->setSuffix(tr(" ���."));

    lyellow2 = new QLabel(tr("Ƹ����"));
    syellow2 = new QSpinBox;
    syellow2->setMinimum(M_YELLOW);
    syellow2->setValue(DEFAULT_YELLOW);
    syellow2->setSuffix(tr(" ���."));

    lgreen2 = new QLabel(tr("������"));
    sgreen2 = new QSpinBox;
    sgreen2->setMinimum(M_GREEN);
    sgreen2->setValue(DEFAULT_GREEN);
    sgreen2->setSuffix(tr(" ���."));

    gl2->addWidget(lred2, 0, 0);
    gl2->addWidget(sred2, 0, 1);

    gl2->addWidget(lyellow2, 1, 0);
    gl2->addWidget(syellow2, 1, 1);

    gl2->addWidget(lgreen2, 2, 0);
    gl2->addWidget(sgreen2, 2, 1);

    vb->addLayout(gl2);
    this->setLayout(vb);

    //============= Trafficligne 3 ================

    lTR3 = new QLabel(tr("<H3>�������� 3</H3>"));
    vb->addWidget(lTR3);
    this->setLayout(vb);

    gl3 = new QGridLayout;

    lred3 = new QLabel(tr("�������"));
    sred3 = new QSpinBox;
    sred3->setMinimum(M_RED);
    sred3->setValue(DEFAULT_RED);
    sred3->setSuffix(tr(" ���."));

    lyellow3 = new QLabel(tr("Ƹ����"));
    syellow3 = new QSpinBox;
    syellow3->setMinimum(M_YELLOW);
    syellow3->setValue(DEFAULT_YELLOW);
    syellow3->setSuffix(tr(" ���."));

    lgreen3 = new QLabel(tr("������"));
    sgreen3 = new QSpinBox;
    sgreen3->setMinimum(M_GREEN);
    sgreen3->setValue(DEFAULT_GREEN);
    sgreen3->setSuffix(tr(" ���."));

    gl3->addWidget(lred3, 0, 0);
    gl3->addWidget(sred3, 0, 1);

    gl3->addWidget(lyellow3, 1, 0);
    gl3->addWidget(syellow3, 1, 1);

    gl3->addWidget(lgreen3, 2, 0);
    gl3->addWidget(sgreen3, 2, 1);

    vb->addLayout(gl3);
    this->setLayout(vb);

    //============= Trafficligne 4 ================

    lTR4 = new QLabel(tr("<H3>�������� 4</H3>"));;
    vb->addWidget(lTR4);
    this->setLayout(vb);

    gl4 = new QGridLayout;

    lred4 = new QLabel(tr("�������"));
    sred4 = new QSpinBox;
    sred4->setMinimum(M_RED);
    sred4->setValue(DEFAULT_RED);
    sred4->setSuffix(tr(" ���."));

    lyellow4 = new QLabel(tr("Ƹ����"));
    syellow4 = new QSpinBox;
    syellow4->setMinimum(M_YELLOW);
    syellow4->setValue(DEFAULT_YELLOW);
    syellow4->setSuffix(tr(" ���."));

    lgreen4 = new QLabel(tr("������"));
    sgreen4 = new QSpinBox;
    sgreen4->setMinimum(M_GREEN);
    sgreen4->setValue(DEFAULT_GREEN);
    sgreen4->setSuffix(tr(" ���."));

    gl4->addWidget(lred4, 0, 0);
    gl4->addWidget(sred4, 0, 1);

    gl4->addWidget(lyellow4, 1, 0);
    gl4->addWidget(syellow4, 1, 1);

    gl4->addWidget(lgreen4, 2, 0);
    gl4->addWidget(sgreen4, 2, 1);

    vb->addLayout(gl4);
    this->setLayout(vb);

    //================== Buttons ==================

    hb = new QHBoxLayout; // �������������� ����������

    pb1 = new QPushButton (tr("���������")); // ������ "���������"
    hb->addWidget(pb1); // ��������� � � ����������
    connect(pb1, SIGNAL(clicked()), SLOT(DO())); // ��������� ������ "������� ������" � ������ ����

    pb2 = new QPushButton (tr("�����")); // ������ "����� ��������"
    hb->addWidget(pb2);
    connect(pb2, SIGNAL(clicked()), SLOT(RESTART()));

    vb->addLayout(hb);
    this->setLayout(vb);

}

//==================================================
//======= ����, ����������� �������� �������� ======
//==================================================
void Options::DO()
{
    QVector <int> vct(12);

    vct[0]=100*sred1->value();
    vct[1]=100*syellow1->value();
    vct[2]=100*sgreen1->value();

    vct[3]=100*sred2->value();
    vct[4]=100*syellow2->value();
    vct[5]=100*sgreen2->value();

    vct[6]=100*sred3->value();
    vct[7]=100*syellow3->value();
    vct[8]=100*sgreen3->value();

    vct[9]=100*sred4->value();
    vct[10]=100*syellow4->value();
    vct[11]=100*sgreen4->value();

    emit sendDO(vct); // ������� ������ �������
}

//==================================================
//========== ����, ������������ ��������� ==========
//==================================================
void Options::RESTART()
{
    sred1->setValue(DEFAULT_RED);
    syellow1->setValue(DEFAULT_YELLOW);
    sgreen1->setValue(DEFAULT_GREEN);

    sred2->setValue(DEFAULT_RED);
    syellow2->setValue(DEFAULT_YELLOW);
    sgreen2->setValue(DEFAULT_GREEN);

    sred3->setValue(DEFAULT_RED);
    syellow3->setValue(DEFAULT_YELLOW);
    sgreen3->setValue(DEFAULT_GREEN);

    sred4->setValue(DEFAULT_RED);
    syellow4->setValue(DEFAULT_YELLOW);
    sgreen4->setValue(DEFAULT_GREEN);

}
//==================================================
//==================== ���������� ==================
//==================================================
Options::~Options()
{
    delete vb;

    delete gl1;
    delete gl2;
    delete gl3;
    delete gl4;

    delete hb;

    delete lTR1;
    delete lTR2;
    delete lTR3;
    delete lTR4;

    delete lred1;
    delete lred2;
    delete lred3;
    delete lred4;
    delete lyellow1;
    delete lyellow2;
    delete lyellow3;
    delete lyellow4;
    delete lgreen1;
    delete lgreen2;
    delete lgreen3;
    delete lgreen4;

    delete sred1;
    delete sred2;
    delete sred3;
    delete sred4;
    delete syellow1;
    delete syellow2;
    delete syellow3;
    delete syellow4;
    delete sgreen1;
    delete sgreen2;
    delete sgreen3;
    delete sgreen4;

    delete pb1;
    delete pb2;
}

//==================================================
