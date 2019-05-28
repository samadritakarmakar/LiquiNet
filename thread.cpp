/* LiquiNet is cross platform GUI software to solve water or Liquid Pipe Network Problems
    Copyright (C) 2016  Samadrita Karmakar (samadritakarmakar@gmail.com)

    This program is free software: you can redistribute it and/or modify
    it under the terms of the GNU General Public License as published by
    the Free Software Foundation, either version 3 of the License, or
    (at your option) any later version.

    This program is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU General Public License for more details.

    You should have received a copy of the GNU General Public License
    along with this program.  If not, see <http://www.gnu.org/licenses/>.*/



#include "thread.h"
#include <QDebug>

void Thread::run()
{

    int flg=0, set_h_q_flg=0;
    stop=0;
    calculate_h();
    calc_C(1);
    if(set_H_Q())
    {
        Q3=C*H3+Cd*Hd;
        qDebug()<<"Wait....Working";
        flg=check_h();
        while(flg<E)
        {
            set_h_q_flg=set_H_Q();
            if(set_h_q_flg)
            {
                calc_C(2);
                flg=check_h();
                flg1=flg;
                Q3=C*H3+Cd*Hd;
            }
            if(set_h_q_flg==0 || stop==1)
            {
                stop=1;
                //qDebug()<<"Inside break for NaN";
                break;
            }
        emit prgrss(int(100*flg/E));
        }
    }
}


