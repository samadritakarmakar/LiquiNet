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



#include "global_variables.h"
#include <QDebug>

void calc_C(int opt)
{
    C=zeros<mat>(N,N);
    Cd=zeros<mat>(N,E);
    for (int i=0;i<=E-1;i++)
    {
        if (opt==1)
            c(i)=q(i)/(h0(i)+Hd(i));
        else
            c(i)=(c(i)+cc(i))/2;

        C(en(i,0)-1,en(i,0)-1)=c(i)+C(en(i,0)-1,en(i,0)-1);
        C(en(i,1)-1,en(i,1)-1)=c(i)+C(en(i,1)-1,en(i,1)-1);
        C(en(i,0)-1,en(i,1)-1)=-c(i)+C(en(i,0)-1,en(i,1)-1);
        C(en(i,1)-1,en(i,0)-1)=-c(i)+C(en(i,1)-1,en(i,0)-1);
        Cd(en(i,0)-1,i)=c(i);
        Cd(en(i,1)-1,i)=-c(i);
        qDebug()<<"c("<<i<<") "<<c(i);

    }
}
