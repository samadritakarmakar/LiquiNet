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



#include <math.h>
#include "global_variables.h"
//#include "error_dialog.h"
#include <QDebug>


int check_h()
{
    int i,flg=0;
    for(i=0; i<E; i++)
    {
        h(i)=H3(en(i,0)-1,0)-H3(en(i,1)-1,0);
        qc(i)=c(i)*(h(i)+Hd(i));
        if(ch(i)==1)
        {
            Re=ro*qc(i)*D(i)/(A(i)*mu);
            f(i)=.094*pow(K(i),0.225)+0.53*K(i)+88*pow(K(i),0.44)*pow(fabs(Re),(-1.62*pow(K(i),0.134)));
            hc(i)=f(i)*L(i)*pow(qc(i),2)/(2*g*D(i)*pow(A(i),2))+k(i)*pow(qc(i),2)/(2*g*pow(A(i),2));
        }
        else if (ch(i)==2 && qc(i)>0)
        {
            hc(i)=pow((qc(i)/A(i)),2)/(2*g)-Hd(i);
        }
        else if(ch(i)==2 && qc(i)<0)
        {
            hc(i)=-pow((qc(i)/A(i)),2)/(2*g)-Hd(i);
        }
        else if(ch(i)==3)
        {
            hc(i)=k(i)*pow((qc(i)/A(i)),2)/(2*g)*pow((100.0/o(i)),(2*n(i)));
        }
        cc(i)=fabs(qc(i)/(hc(i)+Hd(i)));
        err(i)=fabs(fabs(hc(i))-fabs(h(i)))/fabs(h(i))*100;
        qDebug()<<"hc "<<hc(i)<<"h "<<h(i)<<"D "<<D(i)<<"f "<<f(i)<<"L "<<L(i)<<"A "<<A(i);
        if(err(i)<rangep)
        {
            flg++;
        }
        if(hc(i)!=hc(i))
        {
            qDebug()<<"Inside break for NaN";
            stop=1;
        }
    }
    qDebug()<<"flg "<< flg;
return flg;
}
