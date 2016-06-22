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



#include "selection_help.h"
#include "ui_selection_help.h"
#include <QString>
#include <math.h>
#include <QDebug>

//double g, mu, ro;
int ch_c;

selection_help::selection_help(double g1, double mu1, double ro1, QWidget *parent) :
    QWidget(parent),
    ui(new Ui::selection_help)
{
    g=g1;
    mu=mu1;
    ro=ro1;
    this->setWindowTitle("Selection Helper");
    ui->setupUi(this);
}

selection_help::~selection_help()
{
    delete ui;
}

void selection_help::on_D_rb_clicked()
{
    ui->D_le->setEnabled(true);
    ui->h_le->setEnabled(true);
    ui->q_le->setEnabled(true);
    ui->e_le->setEnabled(true);
    ui->L_le->setEnabled(true);
    ui->k_le->setEnabled(true);
    ui->n_le->setEnabled(false);
    ch_c=1;
}

void selection_help::on_Hd_rb_clicked()
{
    ui->D_le->setEnabled(true);
    ui->h_le->setEnabled(true);
    ui->q_le->setEnabled(true);
    ui->e_le->setEnabled(false);
    ui->L_le->setEnabled(false);
    ui->k_le->setEnabled(false);
    ui->n_le->setEnabled(false);
    ch_c=2;
}

void selection_help::on_o_rb_clicked()
{
    ui->D_le->setEnabled(true);
    ui->h_le->setEnabled(true);
    ui->q_le->setEnabled(true);
    ui->e_le->setEnabled(false);
    ui->L_le->setEnabled(false);
    ui->k_le->setEnabled(true);
    ui->n_le->setEnabled(true);
    ch_c=3;
}

void selection_help::on_Go_pb_clicked()
{
    double h=ui->h_le->text().QString::toDouble();
    double D=ui->D_le->text().QString::toDouble();
    double e=ui->e_le->text().QString::toDouble();
    double L=ui->L_le->text().QString::toDouble();
    double k=ui->k_le->text().QString::toDouble();
    double q=ui->q_le->text().QString::toDouble();
    double n=ui->n_le->text().QString::toDouble();
    double D1, A, Re, K, f;
    if(ch_c==1)
    {
        int count=0;
       do
        {
            D1=D;
            A=M_PI/4*pow(D,2);
            Re=ro*q*D/(A*mu);
            K=e/D;
            f=.094*pow(K,0.225)+0.53*K+88*pow(K,0.44)*pow(fabs(Re),(-1.62*pow(K,0.134)));
            D=pow(8*(f*L/D+k)*pow(q,2)/(g*pow(M_PI,2)*h),(1.0/4.0));
            count++;
            if(count>100)
                break;
        qDebug()<<"ro "<<ro<<"A "<<A<<"Re "<<Re<<"f "<<f <<"D "<<D;
        }while(D!=D1);
        ui->result_lb->setText("Internal Diameter");
        ui->Result_le->setText(QString::number(D1));
    }
    else if(ch_c==2)
    {
        A=M_PI/4*pow(D,2);
        double Hd=pow(q/A,2)/(2.0*g)+h;
        ui->result_lb->setText("Booster Head Reqired");
        ui->Result_le->setText(QString::number(Hd));
    }
    else if(ch_c==3)
    {
        A=M_PI/4*pow(D,2);

        double o=pow(k*pow(q/A,2)/(2.0*g*h),(0.5/n))*100.0;
        ui->result_lb->setText("Valve Opening Reqired");
        ui->Result_le->setText(QString::number(o));
    }
}
