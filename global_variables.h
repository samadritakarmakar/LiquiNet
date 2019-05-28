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



#ifndef GLOBAL_VARIABLES_H
#define GLOBAL_VARIABLES_H
#endif // GLOBAL_VARIABLES_H

#ifndef ARMA_64BIT_WORD
#define ARMA_64BIT_WORD
#endif // GLOBAL_VARIABLES_H

#include <armadillo>





using namespace arma;

extern double rangep, ro, g, mu, Re0, Re, qa;
extern int N, E, elc, elcf, ndc,ndcf, flg1, stop ;
extern mat C;
extern mat Q;
extern mat H;
extern mat C1;
extern mat Q1;
extern mat H1;
extern mat Q2;
extern mat H2;
extern mat A;
extern mat q;
extern mat qc;
extern mat f;
extern mat h0;
extern mat h;
extern mat hc;
extern mat c;
extern mat n;
extern mat n1;
extern mat n1;
extern mat n2;
extern mat cc;
extern mat en;
extern mat o;
extern mat D;
extern mat L;
extern mat e;
extern mat k;
extern mat K;
extern mat ch;
extern mat ch_n;
extern mat Cd;
extern mat Hd;
extern mat err;
extern mat Q3;
extern mat H3;

void calculate_h();
void calc_C(int opt);
int set_H_Q();
int check_h();

