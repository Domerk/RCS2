//elements.cpp

#include "elements.h"

#define TL_RADIUS 14;
#define CLENGTH 128;

//==================================================
//=============== конструктор машинки ==============
//==================================================
Car::Car(int nx, int ny, int ndirection, int number)
{
    x = nx; // начальные координаты
    y = ny;
    direction = ndirection; // направление
    srand (time(NULL)); // гинератор псевдослучайных чисел
    Turn = rand()%3; // поворот - случайное число в заданном промежутке
    f = false; // флаги
    p = false;
    v = false;
    prev = false;
    style = 1;
    my_number = number;
}
//==================================================
//============= рисование машинки ==================
//==================================================
void Car::show(QPainter *painter)
{
    // есть 4 варианта направления движения
    // соотвественно есть 4 варианта картинки

    if (direction == 1)
    {
        switch (style) // картинка выбирается в зависимости от дизайна
        {
        case 1:
        {
            QImage car1("://images/1car1.jpg"); // установливаем картинку
            painter->drawImage(x, y, car1); // рисуем картинку
            break;
        }
        case 2:
        {
            QImage car1("://images/2car1.jpg"); // установливаем картинку
            painter->drawImage(x, y, car1); // рисуем картинку
            break;
        }
        case 3:
        {
            QImage car1("://images/3car1.jpg"); // установливаем картинку
            painter->drawImage(x, y, car1); // рисуем картинку
            break;
        }
        case 4:
        {
            QImage car1("://images/4car1.jpg"); // установливаем картинку
            painter->drawImage(x, y, car1); // рисуем картинку
            break;
        }
        }
    }

    if (direction == 2)
    {
        switch (style)
        {
        case 1:
        {
            QImage car2("://images/1car2.jpg"); // установливаем картинку
            painter->drawImage(x, y, car2); // рисуем картинку
            break;
        }
        case 2:
        {
            QImage car2("://images/2car2.jpg"); // установливаем картинку
            painter->drawImage(x, y, car2); // рисуем картинку
            break;
        }
        case 3:
        {
            QImage car2("://images/3car2.jpg"); // установливаем картинку
            painter->drawImage(x, y, car2); // рисуем картинку
            break;
        }
        case 4:
        {
            QImage car2("://images/4car2.jpg"); // установливаем картинку
            painter->drawImage(x, y, car2); // рисуем картинку
            break;
        }
        }
    }

    if (direction == 3)
    {
        switch (style)
        {
        case 1:
        {
            QImage car3("://images/1car3.jpg"); // установливаем картинку
            painter->drawImage(x, y, car3); // рисуем картинку
            break;
        }
        case 2:
        {
            QImage car3("://images/2car3.jpg"); // установливаем картинку
            painter->drawImage(x, y, car3); // рисуем картинку
            break;
        }
        case 3:
        {
            QImage car3("://images/3car3.jpg"); // установливаем картинку
            painter->drawImage(x, y, car3); // рисуем картинку
            break;
        }
        case 4:
        {
            QImage car3("://images/4car3.jpg"); // установливаем картинку
            painter->drawImage(x, y, car3); // рисуем картинку
            break;
        }
        }
    }

    if (direction == 4)
    {
        switch (style)
        {
        case 1:
        {
            QImage car4("://images/1car4.jpg"); // установливаем картинку
            painter->drawImage(x, y, car4); // рисуем картинку
            break;
        }
        case 2:
        {
            QImage car4("://images/2car4.jpg"); // установливаем картинку
            painter->drawImage(x, y, car4); // рисуем картинку
            break;
        }
        case 3:
        {
            QImage car4("://images/3car4.jpg"); // установливаем картинку
            painter->drawImage(x, y, car4); // рисуем картинку
            break;
        }
        case 4:
        {
            QImage car4("://images/4car4.jpg"); // установливаем картинку
            painter->drawImage(x, y, car4); // рисуем картинку
            break;
        }
        }
    }

}
//==================================================
//=============== движение машинки =================
//==================================================
void Car::moving()
{
    // проверяем, есть ли впереди машинка
    if (v)
    {
        emit siganlXY(direction, x, y, Turn, f, p);
        v = false;
        return;

    }

    // движение при подъезде к перекрёстку, если светофор не зелёный, то стоп


    if ((tc == 1 || tc == 2) && !f && !p)
    {

        if (direction==1 && y>=10)
        {
            emit siganlXY(direction, x, y, Turn, f, p);
            return;
        }
        if (direction==2 && x<=320)
        {
            emit siganlXY(direction, x, y, Turn, f, p);
            return;
        }
        if (direction==3 && y<=320)
        {
            emit siganlXY(direction, x, y, Turn, f, p);
            return;
        }
        if (direction==4 && x>=10)
        {
            emit siganlXY(direction, x, y, Turn, f, p);
            return;
        }
    }



    // как только светофор зелёный, то

    if (tc == 3 && !f)
    {
        p = true;
        if (direction == 1) // если движемся сверху вних
        {
            if (Turn == 1 && y >= 165)
            {
                if (!prev)
                {
                    turn();
                    return;
                }
                else
                {
                    emit siganlXY(direction, x, y, Turn, f, p);
                    prev = false;
                    return;
                }
            }

            if ((Turn == 2 || Turn == 0) && y >= 75)
            {
                if (!prev)
                {
                    turn();
                    return;
                }
                else
                {
                    emit siganlXY(direction, x, y, Turn, f, p);
                    prev = false;
                    return;
                }
            }
        }

        if (direction == 2) // если движемся справа налево
        {
            if ((Turn == 1 || Turn == 0) && x <= 150)
            {
                if (!prev)
                {
                    turn();
                    return;
                }
                else
                {
                    emit siganlXY(direction, x, y, Turn, f, p);
                    prev = false;
                    return;
                }
            }

            if (Turn == 2 && x <= 265)
            {
                if (!prev)
                {
                    turn();
                    return;
                }
                else
                {
                    emit siganlXY(direction, x, y, Turn, f, p);
                    prev = false;
                    return;
                }
            }
        }

        if (direction == 3) // если движемся снизу ввуерх
        {
            if ((Turn == 1 || Turn == 0) && y <= 140)
            {
                if (!prev)
                {
                    turn();
                    return;
                }
                else
                {
                    emit siganlXY(direction, x, y, Turn, f, p);
                    prev = false;
                    return;
                }
            }

            if (Turn == 2 && y <= 250)
            {
                if (!prev)
                {
                    turn();
                    return;
                }
                else
                {
                    emit siganlXY(direction, x, y, Turn, f, p);
                    prev = false;
                    return;
                }
            }

        }

        if (direction == 4) // если движемся слева направо
        {
            if (Turn == 1 && x >= 150)
            {
                if (!prev)
                {
                    turn();
                    return;
                }
                else
                {
                    emit siganlXY(direction, x, y, Turn, f, p);
                    prev = false;
                    return;
                }
            }

            if ((Turn == 2 || Turn == 0) && x >= 75)
            {
                if (!prev)
                {
                    turn();
                    return;
                }
                else
                {
                    emit siganlXY(direction, x, y, Turn, f, p);
                    prev = false;
                    return;
                }
            }
        }
    }


    // если машинка после повторота исчезла за краем экрана, то

    if (f)
    {
        p = false;

    }

    if (direction==1 && y>=450)
    {
        x = 150;
        y = -138;
        srand (time(NULL));
        Turn = rand()%3;
        Turn = 1;
        f = false;
        p = false;
        prev = false;
        return;
    }

    if (direction==2 && x<=-128)
    {
        x = 460;
        y = 150;
        srand (time(NULL));
        Turn = rand()%3;
        f = false;
        p = false;
        prev = false;
        return;
    }

    if (direction==3 && y<=-128)
    {
        x = 250;
        y = 460;
        srand (time(NULL));
        Turn = rand()%3;
        f = false;
        p = false;
        prev = false;
        return;
    }

    if (direction==4 && x>=450)
    {
        x = -138;
        y = 250;
        srand (time(NULL));
        Turn = rand()%3;
        f = false;
        p = false;
        prev = false;
        return;
    }


    // движение в зависимости от направления

    if (direction==1)
    {
        y++;
        emit siganlXY(direction, x, y, Turn, f, p);
        return;
    }
    if (direction==2)
    {
        x--;
        emit siganlXY(direction, x, y, Turn, f, p);
        return;
    }
    if (direction==3)
    {
        y--;
        emit siganlXY(direction, x, y, Turn, f, p);
        return;
    }
    if (direction==4)
    {
        x++;
        emit siganlXY(direction, x, y, Turn, f, p);
        return;
    }
}

//==================================================
//=========== слот для цвета светофора =============
//==================================================

void Car::slotTC(int no, int tc_color)
{
    if (no==direction) // если номер светофора совпадает с направлением движения
    {
        tc = tc_color; // сохраняем его текущий цвет
    }
}

//==================================================
//=============== слот для машинки =================
//==================================================

void Car::slotXY(int dir, int mx, int my, int mt, bool mf, bool mp)
{

    vx = mx;
    vy = my;

    // если впереди есть машинка, движущаяся по тому же направлению

    if (dir == direction)
    {
        if (direction == 1 && my>y && (my-y-128)<=5)
        {
            v = true;
        }
        if (direction == 2 && x>mx && (x-mx-128)<=5)
        {
            v = true;
        }
        if (direction == 3 && y>my && (y-my-128)<=5 )
        {
            v = true;
        }
        if (direction == 4 && mx>x && (mx-x-128)<=5)
        {
            v = true;
        }
    }

    // если впереди есть машинка, двигающаяся по другому направлению

    if (direction == 1)
    {
        if ((dir == 2 || dir == 4) && mx+128+10>=x && x+60>=mx && y<=my && y+128+10>=my)
        {
            v = true;
        }
    }

    if (direction == 2)
    {
        if ((dir == 1 || dir == 3) && x>=mx && x<=mx+60+10 && y+60>=my && my+128+60+10>=y) // !!!!!
        {
            v = true;
        }
    }

    if (direction == 3)
    {
        if ((dir == 2 || dir == 4) && mx+128+20>=x && x+60>=mx && y>=my && y<=my+60+10)
        {
            v = true;
        }
    }

    if (direction == 4)
    {
        if ((dir == 1 || dir == 3) && x+128<=mx && x+128+10>=mx && y>=my && my+128+10>=y)
        {
            v = true;
        }
    }

    // проверка на наличие другой машинки при совершении поворота

    if (direction == 1 && Turn == 1 && p && !f && mp) // direction = 4;
    {

        if ((dir == 2 || dir == 4) && mx>=140+128 && mx <= x-128-10)
        {
            v = true;
        }

        if (dir == 3 && my>=250-128 && my<=250+60)
        {
            prev = true;
        }
    }

    if (direction == 1 && Turn == 2 && p && !f && mp) // direction = 2;
    {
        if (mx >= 35-10 && mx <= 35+128+10+60 )
        {
            prev = true;
        }
    }

    // если движемся слева направо

    if (direction == 2 && Turn == 1 && p && !f && mp) // direction = 1;
    {
        if ((dir == 1 || dir == 3)&& my >= y+128 && my <= y+128+10 && mx<=150+60+10 && mx>=150-60-10)
        {
            prev = true;
        }

        if (dir == 4 && my <= y+128+10 && my>=y-128-10 && mx<=150+128+10 && mx>=150-128-10)
        {
            prev = true;
        }

    }

    if (direction == 2 && Turn == 2 && p && !f && mp) //  direction = 3;
    {
        if ((dir == 1 || dir == 3)&& my >= y-128-10 && my <= y+128+10 && mx<=250+60 && mx>=250)
        {
            prev = true;
        }

        if (dir == 4 && my <= y+128+10 && mx<=250+128+10 && mx>=250-10)
        {
            prev = true;
        }

    }

    // если движемся снизу вверх

    if (direction == 3 && Turn == 1 && p && !f && mp) // direction = 2;
    {

        if (dir == 1 && mx >= 145-60-10 && mx<=145+60+10 && my >= 150-128-10 && my<=150+128+10)
        {
            prev = true;
        }

        if ((dir == 2 || dir == 4) && mx >= 145-128-10 && mx<=145+128+10 && my >= 150-60-10 && my<=150+60+10)
        {
            prev = true;
        }

    }

    if (direction == 3 && Turn == 2 && p && !f && mp) // direction = 4;
    {

        if (dir == 1 && mx >= 345-128-10 && mx<=345+128+10 && my >= 250-128-10 && my<=250+128+10)
        {
            prev = true;
        }
        if ((dir == 2 || dir == 4) && mx >= 345-128-10 && mx<=345+128+10 && my >= 250-128-10 && my<=250+128+10)
        {
            prev = true;
        }
    }

    // если движемся справа налево

    if (direction == 4 && Turn == 1 && p && !f && mp) // direction = 3;
    {
        if ((dir == 1 || dir == 3) && mx >= 250-60-10 && mx<=250+60+10 && my >= 170-128-10 && my<=170+128+10)
        {
            prev = true;
        }

        if (dir == 2 && mx >= 250-128-10 && mx<=250+128+10 && my >= 170-60-10 && my<=170+60+10)
        {
            prev = true;
        }

    }

    if (direction == 4 && Turn == 2&& p && !f && mp) // direction = 1;
    {
        if ((dir == 1 || dir == 3) && mx >= 150-60-10 && mx<=150+60+10 && my<=y+60+10)
        {
            prev = true;
        }

        if (dir == 2 && mx >= 150-128-10 && mx<=150+128+10 && my<=y+128+10)
        {
            prev = true;
        }
    }
}

//==================================================
//=============== слот для дизайна =================
//==================================================

void Car::slotSTYLE(int number, int new_style)
{
    if (my_number == number) // если номер равен номеру машинки
    {
        style = new_style; // применяем дизайн
    }
}

//==================================================
//================ поворот машинки =================
//==================================================

void Car::turn()
{
    // значения поворота:
    // 0 - едем прямо
    // 1 - поворачиваем по часовой стрелку
    // 2 - поворачиваем против часовой стрелки

    f = true;

    if (Turn == 0) // если значение повротора 0
    {
        return; // то едем прямо
    }


    // если движемся сверху вниз

    if (direction == 1 && Turn == 1)
    {
        direction = 4;
        x = 140;
        y = 250;
        emit siganlXY(direction, x, y, Turn, f, p);
        return;
    }

    if (direction == 1 && Turn == 2)
    {
        direction = 2;
        x = 35;
        y = 150;
        int nx = x + CLENGTH;
        emit siganlXY(direction, nx, y, Turn, f, p);
        return;
    }

    // если движемся слева направо

    if (direction == 2 && Turn == 1)
    {
        direction = 1;
        y++;
        x = 150;
        emit siganlXY(direction, x, y, Turn, f, p);
        return;
    }

    if (direction == 2 && Turn == 2)
    {
        direction = 3;
        y = 35;
        x = 250;
        int ny = y + CLENGTH;
        emit siganlXY(direction, x, ny, Turn, f, p);
        return;
    }

    // если движемся снизу вверх

    if (direction == 3 && Turn == 1)
    {
        direction = 2;
        x = 145;
        y = 150;
        int nx = x + CLENGTH;
        emit siganlXY(direction, nx, y, Turn, f, p);
        return;
    }

    if (direction == 3 && Turn == 2)
    {
        direction = 4;
        x = 245;
        y = 250;
        emit siganlXY(direction, x, y, Turn, f, p);
        return;
    }

    // если движемся справа налево

    if (direction == 4 && Turn == 1)
    {
        direction = 3;
        y = 170;
        x = 250;
        int ny = y + CLENGTH;
        emit siganlXY(direction, x, ny, Turn, f, p);
        return;
    }

    if (direction == 4 && Turn == 2)
    {
        direction = 1;
        y++;
        x = 150;
        emit siganlXY(direction, x, y, Turn, f, p);
        return;
    }
}

//==================================================
//==================================================
//==================== светофоры ===================
//==================================================
//==================================================

TrafficLight::TrafficLight (int npos, int ncolor)
{
    position = npos;
    radius = TL_RADIUS;
    Traffic_Color = ncolor;

    if (Traffic_Color == 3) // в зависимости от цвета
    {
        cp = 2; // устанавливаем флаг
    }
    else
    {
        cp = 1;
    }

    if (position == 1) // в зависимости от номера
    {
        x1 = 65; // устанавливаем координаты
        y1 = 42;
        x2 = 356;
        y2 = 335;
        a = 0;
    }

    if (position == 2)
    {
        x1 = 87;
        y1 = 355;
        x2 = 376;
        y2 = 62;
        a = 270;
    }

    if (position == 3)
    {
        x1 = 356;
        y1 = 376;
        x2 = 65;
        y2 = 83;
        a = 180;
    }
    if (position == 4)
    {
        x1 = 336;
        y1 = 62;
        x2 = 46;
        y2 = 355;
        a = 90;
    }

    // заполняем массив времени
    // значениями по умолчанию
    // в 10мс
    for (int i = 0; i<4; i++)
    {
        TTtimes+=1000;
        TTtimes+=500;
        TTtimes+=1000;
    }

}

//==================================================
//==================== светить =====================
//==================================================

void TrafficLight::light (int atime)
{

    //========== если красный ===========
    if (Traffic_Color==1)
    {
        cp = 1; // флаг
        if (position == 1) // в зависимости от номера
        {
            if (atime >= TTtimes[0]) // обращаемся к соответствующей ячейке массива времени
            {
                Traffic_Color=2; // меняем цвет на жёлтый
                emit signalTC(position, Traffic_Color); // высылаем сигнал машинкам
                emit signalR(position); // высылаем сигнал дороге
                return; // выходим
            }
        }
        if (position == 2)
        {
            if (atime >= TTtimes[3])
            {
                Traffic_Color=2;
                emit signalTC(position, Traffic_Color);
                emit signalR(position);
                return;
            }
        }
        if (position == 3)
        {
            if (atime >= TTtimes[6])
            {
                Traffic_Color=2;
                emit signalTC(position, Traffic_Color);
                emit signalR(position);
                return;
            }
        }
        if (position == 4)
        {
            if (atime >= TTtimes[9])
            {
                Traffic_Color=2;
                emit signalTC(position, Traffic_Color);
                emit signalR(position);
                return;
            }
        }

    }

    //============== если жёлтый ==============

    if (Traffic_Color==2 && cp == 1) // тут учитывем флаг, т.е. предыдущий цвет
    {
        if (position == 1)
        {
            if (atime >= TTtimes[1])
            {
                Traffic_Color=3;
                emit signalTC(position, Traffic_Color);
                emit signalR(position);
                return;
            }
        }
        if (position == 2)
        {
            if (atime >= TTtimes[4])
            {
                Traffic_Color=3;
                emit signalTC(position, Traffic_Color);
                emit signalR(position);
                return;
            }
        }
        if (position == 3)
        {
            if (atime >= TTtimes[7])
            {
                Traffic_Color=3;
                emit signalTC(position, Traffic_Color);
                emit signalR(position);
                return;
            }
        }
        if (position == 4)
        {
            if (atime >= TTtimes[10])
            {
                Traffic_Color=3;
                emit signalTC(position, Traffic_Color);
                emit signalR(position);
                return;
            }
        }

    }

    if (Traffic_Color==2 && cp == 2)
    {
        if (position == 1)
        {
            if (atime >= TTtimes[1])
            {
                Traffic_Color=1;
                emit signalTC(position, Traffic_Color);
                emit signalR(position);
                return;
            }
        }
        if (position == 2)
        {
            if (atime >= TTtimes[4])
            {
                Traffic_Color=1;
                emit signalTC(position, Traffic_Color);
                emit signalR(position);
                return;
            }
        }
        if (position == 3)
        {
            if (atime >= TTtimes[7])
            {
                Traffic_Color=1;
                emit signalTC(position, Traffic_Color);
                emit signalR(position);
                return;
            }
        }
        if (position == 4)
        {
            if (atime >= TTtimes[10])
            {
                Traffic_Color=1;
                emit signalTC(position, Traffic_Color);
                emit signalR(position);
                return;
            }
        }

    }

    //============= если зелёный ===================

    if (Traffic_Color==3)
    {
        cp = 2;
        if (position == 1)
        {
            if (atime >= TTtimes[2])
            {
                Traffic_Color=2;
                emit signalTC(position, Traffic_Color);
                emit signalR(position);
                return;
            }
        }
        if (position == 2)
        {
            if (atime >= TTtimes[5])
            {
                Traffic_Color=2;
                emit signalTC(position, Traffic_Color);
                emit signalR(position);
                return;
            }
        }
        if (position == 3)
        {
            if (atime >= TTtimes[8])
            {
                Traffic_Color=2;
                emit signalTC(position, Traffic_Color);
                emit signalR(position);
                return;
            }
        }
        if (position == 4)
        {
            if (atime >= TTtimes[11])
            {
                Traffic_Color=2;
                emit signalTC(position, Traffic_Color);
                emit signalR(position);
                return;
            }
        }

    }

    emit signalTC(position, Traffic_Color);
}


//==================================================
//============= рисование светофора ================
//==================================================

void TrafficLight::show(QPainter *painter)
{

    //устанавливаем цвет и толщину

    //карандаша

    if (Traffic_Color == 1) // если 1, то красный
    {
        painter->setPen(QPen(Qt::red,1));
        painter->setBrush(QBrush(Qt::red));
    }

    if (Traffic_Color == 2) // если 2, то жёлтый
    {
        painter->setPen(QPen(Qt::yellow,1));
        painter->setBrush(QBrush(Qt::yellow));
    }

    if (Traffic_Color == 3 ) // если 3, то зелёный
    {
        painter->setPen(QPen(Qt::green,1));
        painter->setBrush(QBrush(Qt::green));
    }

    painter->drawChord(x1, y1, 2*radius, 2*radius, 16*a, 16*180);
    painter->drawChord(x2, y2, 2*radius, 2*radius, 16*a, 16*180);

}

//==================================================
//============== слот для времени ==================
//==================================================

void TrafficLight::slotTT(QVector <int> vct)
{
    TTtimes = vct; // принимаем вектор времени
}

