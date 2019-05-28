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
//#include "error_dialog.h"
//#include "ui_error_dialog.h"
mat A1=zeros<mat>(N,1);

int set_H_Q()
{
    //error_dialog* d=new error_dialog;
    int hc=0, fc=0, i, j, err_flg=1;
    Q2=zeros<mat>(N,1);
    H2=zeros<mat>(N,1);
    n1=zeros<mat>(1,N);
    n2=zeros<mat>(1,N);
    for (i=0;i<=N-1;i++)
    {
        Q2(i,0)=Q(i,0);
        if(ch_n(i)==1)
        {
            H2(i,0)=H(i,0);
            n1(hc)=i+1;
            hc++;
            qDebug()<<"n1 "<<n1(hc-1);
        }
        else if(ch_n(i)==2)
        {
            //Q1(fc,0)=Q2(i,0);
            n2(fc)=i+1;
            //Q1(i,0)=Q1(i,0)-C.row(i)*H2(0)-Cd.row(i)*Hd(0);
            fc++;
            qDebug()<<"n2 "<<n2(fc-1);
        }
    }
    Q2=Q2-C*H2-Cd*Hd;//new theory required
    Q1=zeros<mat>(fc,1);
    H1=zeros<mat>(fc,1);


    qDebug()<<"fc "<<fc;
    if(fc!=0)
    {
        C1=zeros<mat>(fc,fc);
        for(i=0;i<fc;i++)
        {
            for(j=0;j<fc;j++)
            {
                C1(i,j)=C(n2(i)-1,n2(j)-1);
                qDebug()<<"C1"<<C1(i,j);
            }
        }

    }

    fc=0;
    hc=0;
    for(i=0;i<=N-1;i++)
    {
        qDebug()<<"i "<<i;
        if(i+1==n2(fc))
        {
            Q1(fc,0)=Q2(i,0);
            fc++;
            qDebug()<<"fc "<<fc;
        }
        else if(i+1==n1(hc))
        {
            Q2(i,0)=0;
            hc++;
        }
    qDebug()<<"Q2 "<<Q2(i,0);
    }
    if(fc!=0)
    {
        if(rank(C1)<fc)
        {
            //d->callerror("Faulty Input");
            //d->show();
            err_flg=0;
        }
        else
        {
            H1=solve(C1,Q1);
            err_flg=1;
        }
    }

    //put H & Q in right points. Code for further solving.
    hc=0;
    fc=0;

    for(i=0;i<=N-1;i++)
    {
        if(ch_n(i)==1)
        {
            H3(i,0)=H(i,0);
            hc++;
            qDebug()<<"H3"<<H3(i,0);
        }
        else if(ch_n(i)==2)
        {
           H3(i,0)=H1(fc,0);
           fc++;
           qDebug()<<"H3"<<H3(i,0);
        }
    }
return err_flg;
}

