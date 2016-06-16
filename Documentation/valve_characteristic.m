
#Copyright (C) 2016  Samadrita Karmakar <samadritakarmakar@gmail.com>
#   
#    This program is free software: you can redistribute it and/or modify
#    it under the terms of the GNU General Public License as published by
#    the Free Software Foundation, either version 3 of the License, or
#    (at your option) any later version.
#
#    This program is distributed in the hope that it will be useful,
#    but WITHOUT ANY WARRANTY; without even the implied warranty of
#    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
#    GNU General Public License for more details.
#
#    You should have received a copy of the GNU General Public License
#    along with this program.  If not, see <http://www.gnu.org/licenses/>.*/


D=1;
A=pi/4*D^2;
h=10;
k=10;
g=9.81;
for i=1:101
o(i)=i-1;
q(i)=A*(h*2*g/k)^(.5);
n=.5;
q1(i)=(o(i)/100)^n*A*(h*2*g/k)^(.5);
pq1(i)=q1(i)/q(i)*100;
n=1;
q2(i)=(o(i)/100)^n*A*(h*2*g/k)^(.5);
pq2(i)=q2(i)/q(i)*100;
n=2;
q3(i)=(o(i)/100)^n*A*(h*2*g/k)^(.5);
pq3(i)=q3(i)/q(i)*100;
endfor
plot(o,pq1,o,pq2,o,pq3)
xlabel("Opening Percentage");
ylabel("Flow Percentage");