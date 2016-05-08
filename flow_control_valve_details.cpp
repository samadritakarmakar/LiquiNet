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



#include "flow_control_valve_details.h"
#include "ui_flow_control_valve_details.h"
#include "global_variables.h"
#include <QDebug>
#include <QString>

Flow_Control_Valve_Details::Flow_Control_Valve_Details(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Flow_Control_Valve_Details)
{
    ui->setupUi(this);
}

Flow_Control_Valve_Details::~Flow_Control_Valve_Details()
{
    delete ui;
}

void Flow_Control_Valve_Details::on_ok_fvc_pb_clicked()
{

    D(elc)=ui->D_le->text().toDouble();
    o(elc)=ui->o_le->text().toDouble();
    k(elc)=ui->k_le->text().toDouble();
    n(elc)=ui->n_le->text().toDouble();
    L(elc)=0;
    e(elc)=0;
    Hd(elc)=0;
    q(elc)=qa;
    //calculate_h(); Moved to thread.cpp with necessary
    this->close();
    //qDebug()<<"Area "<<A(elc)<<"\nHead Loss "<<h0(elc);
}

void Flow_Control_Valve_Details::first_show()
{
    ui->D_le->setText(QString::number(D(elc)));
    ui->o_le->setText(QString::number(o(elc)));
    ui->k_le->setText(QString::number(k(elc)));
    ui->n_le->setText(QString::number(n(elc)));

}
