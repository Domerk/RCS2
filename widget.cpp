// widget.cpp

#include "widget.h"

//==================================================
//=========== ����������� �������� ���� ============
//==================================================

Widget::Widget(QMainWindow *parent)
    : QMainWindow(parent)
{
    //================== ��������� ���� =====================

    setWindowTitle("RCS 2.0");
    setFixedSize(700,490);

    QIcon  icn ("://images/logo.gif");
    setWindowIcon(icn);

    //================== ���������� ���� =====================

    mainWidget = new QWidget();
    mainLayout = new QHBoxLayout();
    road = new Road();
    options = new Options();
    wgs = new WidgetStyle();


    connect(options, SIGNAL(sendDO(QVector <int>)), road, SLOT(slotDO(QVector <int>)));
    connect (this, SIGNAL (signalLEVEL(int)), road, SLOT (slotLEVEL(int)));
    connect (wgs, SIGNAL(signalSTYLE(int,int)), road, SLOT(slotSTYLE(int,int)));

    //=================== ������ ���� ======================

    menuBar = new QMenuBar();

    // ������ �����
    pmenu = new QMenu(tr("&����"));
    pmenu ->addAction(tr("&�����"),
                      this, SLOT(close()));

    // ������ �����
    pmenu1 = new QMenu (tr("&�������"));
    pmenu1 ->addAction(tr("&������� 1"),
                      this, SLOT(LEVEL_1()));
    pmenu1 ->addAction(tr("&������� 2"),
                      this, SLOT(LEVEL_2()));
    pmenu1 ->addAction(tr("&������� 3"),
                      this, SLOT(LEVEL_3()));
    pmenu1 ->addAction(tr("&������� 4"),
                      this, SLOT(LEVEL_4()));

    // ������ ����� ����
    pmenu2 = new QMenu (tr("&���"));
    pmenu2 ->addAction(tr("&��� �����������"),
                    wgs, SLOT(show()));


    // �������� ����� ����
    pmenu3 = new QMenu(tr("&����������"));
    pmenu3 ->addAction(tr("&� ���������"), this,
                       SLOT(label_program()));
    pmenu3 ->addAction(tr("&�����������"), this,
                       SLOT(label_developer()));
    pmenu3 ->addSeparator();
    pmenu3 ->addAction(tr("&������"), this,
                       SLOT(label_help()));

    // ������� ����
    menuBar ->addMenu(pmenu);
    menuBar ->addMenu(pmenu1);
    menuBar ->addMenu(pmenu2);
    menuBar ->addMenu(pmenu3);

    this->setMenuBar(menuBar);

    mainLayout->addWidget(road);
    mainLayout->addWidget(options);
    mainWidget->setLayout(mainLayout);
    setCentralWidget(mainWidget);

    //==================== lprogram =========================

    lprogram = new QLabel(tr(
                              "<H2><CENTER>���������</CENTER>"
                              "<CENTER>������������� ����������</CENTER></H2>"
                              "<H3><CENTER>RCS 2.0</CENTER></H3>"
                              "<P>             </P>"
                              "<P>&nbsp;&nbsp;&nbsp;&nbsp;������ ��������� ����� ��������<BR>"
                              "&nbsp;&nbsp;&nbsp;&nbsp;��������� ������������� ���������� (RCS 2.0)<BR>"
                              "&nbsp;&nbsp;&nbsp;&nbsp;� ������������ ����� ������������� ������,<BR>"
                              "&nbsp;&nbsp;&nbsp;&nbsp;����������� ������������ ���������<BR>"
                              "&nbsp;&nbsp;&nbsp;&nbsp;�������� ��������, ��������� � �������<BR>"
                              "&nbsp;&nbsp;&nbsp;&nbsp;���������� �� ����������.</P>"
                              "<b><P>&nbsp;&nbsp;&nbsp;&nbsp;������� �� Qt 4.7.4</P></b>"
                              "<P>&nbsp;&nbsp;&nbsp;&nbsp;������ 2.0<BR>"
                              "&nbsp;&nbsp;&nbsp;&nbsp;����������: �������� - ������� 2014</P>"
                              ));

    lprogram->setWindowFlags(Qt::Window | Qt::WindowSystemMenuHint);
    lprogram->setFixedSize(280,240);
    lprogram->setWindowTitle(tr("� ���������"));

    //=================== ldeveloper ========================

    ldeveloper = new QLabel(tr(
                                "<B><P><CENTER>��� ����</CENTER>"
                                "<B><CENTER>�������� �������������� ������</CENTER></B>"
                                "<B><CENTER>� ����������������</CENTER></P></B>"
                                "<P><B><CENTER>������� �������������� ������ � �����</CENTER></P></B>"
                                "<P>&nbsp;&nbsp;&nbsp;&nbsp;�����������: ��������� �����</P>"
                                "<P>&nbsp;&nbsp;&nbsp;&nbsp;������� ������ �4242</P>"
                                "<P>&nbsp;&nbsp;&nbsp;&nbsp;�����: �������� 2013 - ������� 2014</P>"
                                ));

    ldeveloper->setWindowFlags(Qt::Window | Qt::WindowSystemMenuHint);
    ldeveloper->setFixedSize(260,160);
    ldeveloper->setWindowTitle(tr("�����������"));


    //====================== lhelp ==========================

    lhelp = new QLabel(tr(
                           "<B><P><CENTER><H2>������ � ����������</H2></CENTER></P></B>"
                           "<P>&nbsp;&nbsp;&nbsp;&nbsp;<b>��������� ��������� ������������ ���������<BR>"
                           "&nbsp;&nbsp;&nbsp;&nbsp;�������� ��������, �������� �����������.</b></P>"
                           "<P>&nbsp;&nbsp;&nbsp;&nbsp;- ��� ����, ����� <b>�������� ����� ������</b><BR>"
                           "&nbsp;&nbsp;&nbsp;&nbsp;������������ ������� ��������� ������� <BR>"
                           "&nbsp;&nbsp;&nbsp;&nbsp;����������� �������� � ��������������<BR>"
                           "&nbsp;&nbsp;&nbsp;&nbsp;����: �� ����� 5� ������ ��� �������� � �������<BR>"
                           "&nbsp;&nbsp;&nbsp;&nbsp;� �� ����� 2� ��� ������ �������.<BR>"
                           "&nbsp;&nbsp;&nbsp;&nbsp;������� ��������� ��� ������� �������.</P>"
                           "<P>&nbsp;&nbsp;&nbsp;&nbsp;- ��� ������������ <b>�������� �������<BR>"
                           "&nbsp;&nbsp;&nbsp;&nbsp;�� ���������</b> ������� �������� + ���������.<BR>"
                           "&nbsp;&nbsp;&nbsp;&nbsp;<BR>"
                           "&nbsp;&nbsp;&nbsp;&nbsp;- ���������� <b>�����������</b> �� ������<BR>"
                           "&nbsp;&nbsp;&nbsp;&nbsp;����� ������������, ������� ��������������<BR>"
                           "&nbsp;&nbsp;&nbsp;&nbsp;������� ���������. ��� ����� ������ ���� �������.<BR>"
                           "&nbsp;&nbsp;&nbsp;&nbsp;����� ������� ������������ ���������� �����������.</P>"
                           "<P>&nbsp;&nbsp;&nbsp;&nbsp;- ��� <b>��������� �������</b> �����������<BR>"
                           "&nbsp;&nbsp;&nbsp;&nbsp;�������������� ���� ��� -> ��� ����������.<BR>"
                           "&nbsp;&nbsp;&nbsp;&nbsp;� ����������� ���� �������� ����������, <BR>"
                           "&nbsp;&nbsp;&nbsp;&nbsp;� ���������� ������������� ������. </P>"
                           ));

    lhelp->setFixedSize(300,340);
    lhelp->setWindowTitle(tr("������"));

    //=======================================================
}

//==================================================
//=========== ������� � ����� � ��������� ==========
//==================================================

void Widget::label_program()
{
    lprogram->show();
}

//==================================================
//========== ������� � ����� � ������������ ========
//==================================================

void Widget::label_developer()
{
    ldeveloper->show();
}


//==================================================
//============ ������� �� �������� =================
//==================================================

void Widget::label_help()
{
    lhelp->show();
}

//==================================================
//================ ������� 1 =======================
//==================================================

void Widget::LEVEL_1()
{
    int x = 1;
    signalLEVEL (x);
}

//==================================================
//================ ������� 2 =======================
//==================================================

void Widget::LEVEL_2()
{
    int x = 2;
    signalLEVEL (x);
}

//==================================================
//================ ������� 3 =======================
//==================================================

void Widget::LEVEL_3()
{
    int x = 3;
    signalLEVEL (x);
}

//==================================================
//================ ������� 4 =======================
//==================================================

void Widget::LEVEL_4()
{
    int x = 4;
    signalLEVEL (x);
}


//==================================================
//================== ���������� ====================
//==================================================

Widget::~Widget()
{
    delete menuBar;
    delete pmenu;
    delete pmenu1;
    delete pmenu2;
    delete pmenu3;
    delete lprogram;
    delete ldeveloper;
    delete lhelp;
    delete mainLayout;
    delete road;
    delete options;
    delete mainWidget;
    delete wgs;
}
//====================================================
