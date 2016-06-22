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
void calculate_h()
{
    for(int i=0;i<E;i++)
    {
        if(ch(i)==1)
            {
                A(i)=M_PI/4*pow(D(i),2);
                q(i)=Re0*A(i)*mu/(ro*D(i));
                K(i)=e(i)/D(i);
                f(i)=.094*pow(K(i),0.225)+0.53*K(i)+88*pow(K(i),0.44)*pow(Re0,(-1.62*pow(K(i),0.134)));
                h0(i)=f(i)*L(i)*pow(q(i),2)/(2*g*D(i)*pow(A(i),2))+k(i)*pow(q(i),2)/(2*g*pow(A(i),2));
            }
            else if(ch(i)==2)
            {
                q(i)=qa;
                A(i)=M_PI/4*pow(D(i),2);
                h0(i)=pow((q(i)/A(i)),2)/(2*g)-Hd(i);
            }
            else if(ch(i)==3)
            {
                A(i)=M_PI/4*pow(D(i),2);
                if(o(i)==0)
                {
                    o(i)=1;
                    q(i)=0;
                }
                h0(i)=pow((q(i)/A(i)),2)*k(i)/(2*g)*pow((100.0/o(i)),(2*n(i)));
            }
    }
}
