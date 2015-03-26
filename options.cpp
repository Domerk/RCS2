// options.cpp

#include "options.h"

const int M_RED = 5; // минимальные значения времени
const int M_YELLOW = 2;
const int M_GREEN = 5;

const int DEFAULT_RED = 10; // умолчания
const int DEFAULT_YELLOW = 5;
const int DEFAULT_GREEN = 10;

Options::Options(QWidget *parent)
    : QWidget(parent)
{
    setFixedSize(200,450); // фиксированный размер
    vb = new QVBoxLayout(); // вертикальная компановка



    //============= Trafficligne 1 ================

    lTR1 = new QLabel(tr("<H3>Светофор 1</H3>"));
    vb->addWidget(lTR1);
    this->setLayout(vb);

    gl1 = new QGridLayout; // табличня компановка

    lred1 = new QLabel(tr("Красный")); // надпись
    sred1 = new QSpinBox; // строка ввода
    sred1->setMinimum(M_RED); // минимальное значение
    sred1->setValue(DEFAULT_RED); // текущее значение
    sred1->setSuffix(tr(" сек.")); // единицы измерения

    lyellow1 = new QLabel(tr("Жёлтый"));
    syellow1 = new QSpinBox;
    syellow1->setMinimum(M_YELLOW);
    syellow1->setValue(DEFAULT_YELLOW);
    syellow1->setSuffix(tr(" сек."));

    lgreen1 = new QLabel(tr("Зелёный"));
    sgreen1 = new QSpinBox;
    sgreen1->setMinimum(M_GREEN);
    sgreen1->setValue(DEFAULT_GREEN);
    sgreen1->setSuffix(tr(" сек."));

    gl1->addWidget(lred1, 0, 0); // добавляем элменеты в компановку
    gl1->addWidget(sred1, 0, 1);

    gl1->addWidget(lyellow1, 1, 0);
    gl1->addWidget(syellow1, 1, 1);

    gl1->addWidget(lgreen1, 2, 0);
    gl1->addWidget(sgreen1, 2, 1);

    vb->addLayout(gl1); // добавляем табличную компановку в вертикальную компановку
    this->setLayout(vb);

    //============= Trafficligne 2 ================

    lTR2 = new QLabel(tr("<H3>Светофор 2</H3>"));
    vb->addWidget(lTR2);
    this->setLayout(vb);

    gl2 = new QGridLayout;

    lred2 = new QLabel(tr("Красный"));
    sred2 = new QSpinBox;
    sred2->setMinimum(M_RED);
    sred2->setValue(DEFAULT_RED);
    sred2->setSuffix(tr(" сек."));

    lyellow2 = new QLabel(tr("Жёлтый"));
    syellow2 = new QSpinBox;
    syellow2->setMinimum(M_YELLOW);
    syellow2->setValue(DEFAULT_YELLOW);
    syellow2->setSuffix(tr(" сек."));

    lgreen2 = new QLabel(tr("Зелёный"));
    sgreen2 = new QSpinBox;
    sgreen2->setMinimum(M_GREEN);
    sgreen2->setValue(DEFAULT_GREEN);
    sgreen2->setSuffix(tr(" сек."));

    gl2->addWidget(lred2, 0, 0);
    gl2->addWidget(sred2, 0, 1);

    gl2->addWidget(lyellow2, 1, 0);
    gl2->addWidget(syellow2, 1, 1);

    gl2->addWidget(lgreen2, 2, 0);
    gl2->addWidget(sgreen2, 2, 1);

    vb->addLayout(gl2);
    this->setLayout(vb);

    //============= Trafficligne 3 ================

    lTR3 = new QLabel(tr("<H3>Светофор 3</H3>"));
    vb->addWidget(lTR3);
    this->setLayout(vb);

    gl3 = new QGridLayout;

    lred3 = new QLabel(tr("Красный"));
    sred3 = new QSpinBox;
    sred3->setMinimum(M_RED);
    sred3->setValue(DEFAULT_RED);
    sred3->setSuffix(tr(" сек."));

    lyellow3 = new QLabel(tr("Жёлтый"));
    syellow3 = new QSpinBox;
    syellow3->setMinimum(M_YELLOW);
    syellow3->setValue(DEFAULT_YELLOW);
    syellow3->setSuffix(tr(" сек."));

    lgreen3 = new QLabel(tr("Зелёный"));
    sgreen3 = new QSpinBox;
    sgreen3->setMinimum(M_GREEN);
    sgreen3->setValue(DEFAULT_GREEN);
    sgreen3->setSuffix(tr(" сек."));

    gl3->addWidget(lred3, 0, 0);
    gl3->addWidget(sred3, 0, 1);

    gl3->addWidget(lyellow3, 1, 0);
    gl3->addWidget(syellow3, 1, 1);

    gl3->addWidget(lgreen3, 2, 0);
    gl3->addWidget(sgreen3, 2, 1);

    vb->addLayout(gl3);
    this->setLayout(vb);

    //============= Trafficligne 4 ================

    lTR4 = new QLabel(tr("<H3>Светофор 4</H3>"));;
    vb->addWidget(lTR4);
    this->setLayout(vb);

    gl4 = new QGridLayout;

    lred4 = new QLabel(tr("Красный"));
    sred4 = new QSpinBox;
    sred4->setMinimum(M_RED);
    sred4->setValue(DEFAULT_RED);
    sred4->setSuffix(tr(" сек."));

    lyellow4 = new QLabel(tr("Жёлтый"));
    syellow4 = new QSpinBox;
    syellow4->setMinimum(M_YELLOW);
    syellow4->setValue(DEFAULT_YELLOW);
    syellow4->setSuffix(tr(" сек."));

    lgreen4 = new QLabel(tr("Зелёный"));
    sgreen4 = new QSpinBox;
    sgreen4->setMinimum(M_GREEN);
    sgreen4->setValue(DEFAULT_GREEN);
    sgreen4->setSuffix(tr(" сек."));

    gl4->addWidget(lred4, 0, 0);
    gl4->addWidget(sred4, 0, 1);

    gl4->addWidget(lyellow4, 1, 0);
    gl4->addWidget(syellow4, 1, 1);

    gl4->addWidget(lgreen4, 2, 0);
    gl4->addWidget(sgreen4, 2, 1);

    vb->addLayout(gl4);
    this->setLayout(vb);

    //================== Buttons ==================

    hb = new QHBoxLayout; // горизонтальная компановка

    pb1 = new QPushButton (tr("Применить")); // кнопка "Применить"
    hb->addWidget(pb1); // добавляем её в компановку
    connect(pb1, SIGNAL(clicked()), SLOT(DO())); // соеднияем сигнал "нажатие кнопки" и нужный слот

    pb2 = new QPushButton (tr("Сброс")); // кнопка "Сброс настроек"
    hb->addWidget(pb2);
    connect(pb2, SIGNAL(clicked()), SLOT(RESTART()));

    vb->addLayout(hb);
    this->setLayout(vb);

}

//==================================================
//======= слот, принимающий значения настроек ======
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

    emit sendDO(vct); // передаём вектор времени
}

//==================================================
//========== слот, сбрасывающий настройки ==========
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
//==================== деструктор ==================
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
