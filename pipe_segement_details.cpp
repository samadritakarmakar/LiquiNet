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



#include "pipe_segement_details.h"
#include "ui_pipe_segement_details.h"
#include "global_variables.h"
#include <math.h>
#include <QDebug>

Pipe_Segement_Details::Pipe_Segement_Details(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Pipe_Segement_Details)
{
    ui->setupUi(this);
}

Pipe_Segement_Details::~Pipe_Segement_Details()
{
    delete ui;
}

void Pipe_Segement_Details::on_pipe_sgmnt_pb_clicked()
{
    D(elc)=ui->D_le->text().toDouble();
    L(elc)=ui->L_le->text().toDouble();
    e(elc)=ui->e_le->text().toDouble();
    k(elc)=ui->k_le->text().toDouble();
    Hd(elc)=0;
    o(elc)=0;
    n(elc)=0;
    this->close();
    //qDebug()<<"Area "<<A(elc)<<"\nHead Loss "<<h0(elc)<<"\nFriction Factor"<<f(elc);
}

void Pipe_Segement_Details::first_show()
{
    ui->D_le->setText(QString::number(D(elc)));
    ui->L_le->setText(QString::number(L(elc)));
    ui->k_le->setText(QString::number(k(elc)));
    ui->e_le->setText(QString::number(e(elc)));
}
