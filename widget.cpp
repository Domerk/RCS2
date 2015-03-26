// widget.cpp

#include "widget.h"

//==================================================
//=========== конструктор главного окна ============
//==================================================

Widget::Widget(QMainWindow *parent)
    : QMainWindow(parent)
{
    //================== заголовок окна =====================

    setWindowTitle("RCS 2.0");
    setFixedSize(700,490);

    QIcon  icn ("://images/logo.gif");
    setWindowIcon(icn);

    //================== содержимое окна =====================

    mainWidget = new QWidget();
    mainLayout = new QHBoxLayout();
    road = new Road();
    options = new Options();
    wgs = new WidgetStyle();


    connect(options, SIGNAL(sendDO(QVector <int>)), road, SLOT(slotDO(QVector <int>)));
    connect (this, SIGNAL (signalLEVEL(int)), road, SLOT (slotLEVEL(int)));
    connect (wgs, SIGNAL(signalSTYLE(int,int)), road, SLOT(slotSTYLE(int,int)));

    //=================== создаЄм меню ======================

    menuBar = new QMenuBar();

    // первый пункт
    pmenu = new QMenu(tr("&Файл"));
    pmenu ->addAction(tr("&Выход"),
                      this, SLOT(close()));

    // второй пункт
    pmenu1 = new QMenu (tr("&Уровень"));
    pmenu1 ->addAction(tr("&Уровень 1"),
                      this, SLOT(LEVEL_1()));
    pmenu1 ->addAction(tr("&Уровень 2"),
                      this, SLOT(LEVEL_2()));
    pmenu1 ->addAction(tr("&Уровень 3"),
                      this, SLOT(LEVEL_3()));
    pmenu1 ->addAction(tr("&Уровень 4"),
                      this, SLOT(LEVEL_4()));

    // третий пункт меню
    pmenu2 = new QMenu (tr("&Вид"));
    pmenu2 ->addAction(tr("&Вид автомобилей"),
                    wgs, SLOT(show()));


    // четвёртый пункт меню
    pmenu3 = new QMenu(tr("&Информация"));
    pmenu3 ->addAction(tr("&О программе"), this,
                       SLOT(label_program()));
    pmenu3 ->addAction(tr("&Разработчик"), this,
                       SLOT(label_developer()));
    pmenu3 ->addSeparator();
    pmenu3 ->addAction(tr("&Помощь"), this,
                       SLOT(label_help()));

    // выводим меню
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
                              "<H2><CENTER>Симулятор</CENTER>"
                              "<CENTER>регулируемого перекрёстка</CENTER></H2>"
                              "<H3><CENTER>RCS 2.0</CENTER></H3>"
                              "<P>             </P>"
                              "<P>&nbsp;&nbsp;&nbsp;&nbsp;Данная программа носит название<BR>"
                              "&nbsp;&nbsp;&nbsp;&nbsp;Симулятор регулируемого перекрёстка (RCS 2.0)<BR>"
                              "&nbsp;&nbsp;&nbsp;&nbsp;и представляет собой интекративную модель,<BR>"
                              "&nbsp;&nbsp;&nbsp;&nbsp;позволяющую симулировать различные<BR>"
                              "&nbsp;&nbsp;&nbsp;&nbsp;дорожные ситуации, связанные с работой<BR>"
                              "&nbsp;&nbsp;&nbsp;&nbsp;светофоров на перекрёстке.</P>"
                              "<b><P>&nbsp;&nbsp;&nbsp;&nbsp;Основан на Qt 4.7.4</P></b>"
                              "<P>&nbsp;&nbsp;&nbsp;&nbsp;Версия 2.0<BR>"
                              "&nbsp;&nbsp;&nbsp;&nbsp;Разработка: Сентябрь - Октябрь 2014</P>"
                              ));

    lprogram->setWindowFlags(Qt::Window | Qt::WindowSystemMenuHint);
    lprogram->setFixedSize(280,240);
    lprogram->setWindowTitle(tr("О программе"));

    //=================== ldeveloper ========================

    ldeveloper = new QLabel(tr(
                                "<B><P><CENTER>СПб ГУАП</CENTER>"
                                "<B><CENTER>Институт вычислительных систем</CENTER></B>"
                                "<B><CENTER>и программирования</CENTER></P></B>"
                                "<P><B><CENTER>Кафедра вычислительных систем и сетей</CENTER></P></B>"
                                "<P>&nbsp;&nbsp;&nbsp;&nbsp;Разработчик: Максимова Ольга</P>"
                                "<P>&nbsp;&nbsp;&nbsp;&nbsp;Учебная группа №4242</P>"
                                "<P>&nbsp;&nbsp;&nbsp;&nbsp;Время: Сентябрь 2013 - Октябрь 2014</P>"
                                ));

    ldeveloper->setWindowFlags(Qt::Window | Qt::WindowSystemMenuHint);
    ldeveloper->setFixedSize(260,160);
    ldeveloper->setWindowTitle(tr("Разработчик"));


    //====================== lhelp ==========================

    lhelp = new QLabel(tr(
                           "<B><P><CENTER><H2>Работа с программой</H2></CENTER></P></B>"
                           "<P>&nbsp;&nbsp;&nbsp;&nbsp;<b>Программа позволяет симулировать различные<BR>"
                           "&nbsp;&nbsp;&nbsp;&nbsp;дорожные ситуации, управляя светофорами.</b></P>"
                           "<P>&nbsp;&nbsp;&nbsp;&nbsp;- Для того, чтобы <b>изменить время работы</b><BR>"
                           "&nbsp;&nbsp;&nbsp;&nbsp;определённого сигнала светофора введите <BR>"
                           "&nbsp;&nbsp;&nbsp;&nbsp;необходимое значение в соотвествующее<BR>"
                           "&nbsp;&nbsp;&nbsp;&nbsp;поле: не менее 5и секунд для красного и зелёного<BR>"
                           "&nbsp;&nbsp;&nbsp;&nbsp;и не менее 2х для жёлтого сигнала.<BR>"
                           "&nbsp;&nbsp;&nbsp;&nbsp;Нажмите Применить для задания времени.</P>"
                           "<P>&nbsp;&nbsp;&nbsp;&nbsp;- Для установления <b>настроек времени<BR>"
                           "&nbsp;&nbsp;&nbsp;&nbsp;по умолчнаию</b> нажмите Сбросить + Применить.<BR>"
                           "&nbsp;&nbsp;&nbsp;&nbsp;<BR>"
                           "&nbsp;&nbsp;&nbsp;&nbsp;- Количество <b>автомобилей</b> на дороге<BR>"
                           "&nbsp;&nbsp;&nbsp;&nbsp;можно регулировать, выбирая соотвествующий<BR>"
                           "&nbsp;&nbsp;&nbsp;&nbsp;уровень сложности. Для этого служит меню Уровень.<BR>"
                           "&nbsp;&nbsp;&nbsp;&nbsp;Номер уровная соотвествует количеству автомобилей.</P>"
                           "<P>&nbsp;&nbsp;&nbsp;&nbsp;- Для <b>изменения дизайна</b> автомобилей<BR>"
                           "&nbsp;&nbsp;&nbsp;&nbsp;воспользуйтесь меню Вид -> Вид автомобиля.<BR>"
                           "&nbsp;&nbsp;&nbsp;&nbsp;В открывшемся окне выберите автомобиль, <BR>"
                           "&nbsp;&nbsp;&nbsp;&nbsp;и установите понравившийся дизайн. </P>"
                           ));

    lhelp->setFixedSize(300,340);
    lhelp->setWindowTitle(tr("Помощь"));

    //=======================================================
}

//==================================================
//=========== надпись с инфой о программе ==========
//==================================================

void Widget::label_program()
{
    lprogram->show();
}

//==================================================
//========== надпись с инфой о разработчике ========
//==================================================

void Widget::label_developer()
{
    ldeveloper->show();
}


//==================================================
//============ надпись со справкой =================
//==================================================

void Widget::label_help()
{
    lhelp->show();
}

//==================================================
//================ уровень 1 =======================
//==================================================

void Widget::LEVEL_1()
{
    int x = 1;
    signalLEVEL (x);
}

//==================================================
//================ уровень 2 =======================
//==================================================

void Widget::LEVEL_2()
{
    int x = 2;
    signalLEVEL (x);
}

//==================================================
//================ уровень 3 =======================
//==================================================

void Widget::LEVEL_3()
{
    int x = 3;
    signalLEVEL (x);
}

//==================================================
//================ уровень 4 =======================
//==================================================

void Widget::LEVEL_4()
{
    int x = 4;
    signalLEVEL (x);
}


//==================================================
//================== деструктор ====================
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
