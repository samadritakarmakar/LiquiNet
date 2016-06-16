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



#include "results.h"
#include "ui_results.h"
#include "global_variables.h"
#include <QStandardItemModel>
#include <QDebug>
#include <QFileDialog>
#include <QString>
#include <QDir>

#include "error_dialog.h"

Results::Results(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Results)
{
    ui->setupUi(this);
    this->setWindowTitle("Results");

}

Results::~Results()
{
    delete ui;
}

void Results::generate_results()
{
    int i;
    QStandardItemModel *mdl_e=new QStandardItemModel(E,4,this);
    mdl_e->setHorizontalHeaderItem(0,new QStandardItem("Element No."));
    mdl_e->setHorizontalHeaderItem(1,new QStandardItem("Element Type"));
    mdl_e->setHorizontalHeaderItem(2,new QStandardItem("Flow from\n Node"));
    mdl_e->setHorizontalHeaderItem(3,new QStandardItem("Flow to\n Node"));
    mdl_e->setHorizontalHeaderItem(4,new QStandardItem("Dia"));
    mdl_e->setHorizontalHeaderItem(5,new QStandardItem("Length"));
    mdl_e->setHorizontalHeaderItem(6,new QStandardItem("Roughness"));
    mdl_e->setHorizontalHeaderItem(7,new QStandardItem("k factor"));
    mdl_e->setHorizontalHeaderItem(8,new QStandardItem("Booster\n Head"));
    mdl_e->setHorizontalHeaderItem(9,new QStandardItem("Valve\n Opening"));
    mdl_e->setHorizontalHeaderItem(10,new QStandardItem("Valve\n n factor"));
    mdl_e->setHorizontalHeaderItem(11,new QStandardItem("Flow"));
    mdl_e->setHorizontalHeaderItem(12,new QStandardItem("Head Loss"));
    mdl_e->setHorizontalHeaderItem(13,new QStandardItem("Error (%)"));
    qDebug()<<"E "<<E;
    for(i=0;i<E;i++)
    {
        QStandardItem *itm_elno=new QStandardItem(QString::number(i+1));
        mdl_e->setItem(i,itm_elno);
        QStandardItem *itm_elmnt_type=new QStandardItem(element_type(i));
        mdl_e->setItem(i,1,itm_elmnt_type);
        QStandardItem *itm_elmnt_frm_nde=new QStandardItem(QString::number(en(i,0)));
        mdl_e->setItem(i,2,itm_elmnt_frm_nde);
        QStandardItem *itm_elmnt_to_nde=new QStandardItem(QString::number(en(i,1)));
        mdl_e->setItem(i,3,itm_elmnt_to_nde);
        QStandardItem *itm_D=new QStandardItem(QString::number(D(i)));
        mdl_e->setItem(i,4,itm_D);
        QStandardItem *itm_L=new QStandardItem(QString::number(L(i)));
        mdl_e->setItem(i,5,itm_L);
        QStandardItem *itm_e=new QStandardItem(QString::number(e(i)));
        mdl_e->setItem(i,6,itm_e);
        QStandardItem *itm_k=new QStandardItem(QString::number(k(i)));
        mdl_e->setItem(i,7,itm_k);
        QStandardItem *itm_Hd=new QStandardItem(QString::number(Hd(i)));
        mdl_e->setItem(i,8,itm_Hd);
        QStandardItem *itm_o=new QStandardItem(QString::number(o(i)));
        mdl_e->setItem(i,9,itm_o);
        QStandardItem *itm_n=new QStandardItem(QString::number(n(i)));
        mdl_e->setItem(i,10,itm_n);
        QStandardItem *itm_qc=new QStandardItem(QString::number(qc(i)));
        mdl_e->setItem(i,11,itm_qc);
        qDebug()<<"qc "<<qc(i)<<"hc "<<hc(i);
        QStandardItem *itm_hc=new QStandardItem(QString::number(hc(i)));
        mdl_e->setItem(i,12,itm_hc);
        QStandardItem *itm_err=new QStandardItem(QString::number(err(i)));
        mdl_e->setItem(i,13,itm_err);
    }
    QStandardItemModel *mdl_n=new QStandardItemModel(N,3,this);
    mdl_n->setHorizontalHeaderItem(0,new QStandardItem("Node No."));
    mdl_n->setHorizontalHeaderItem(1,new QStandardItem("Nodal Head"));
    mdl_n->setHorizontalHeaderItem(2,new QStandardItem("Nodal Flow"));
    for(i=0;i<N;i++)
    {
        QStandardItem *itm_ndeno=new QStandardItem(QString::number(i+1));
        mdl_n->setItem(i,itm_ndeno);
        QStandardItem *itm_H=new QStandardItem(QString::number(H3(i,0)));
        mdl_n->setItem(i,1,itm_H);
        QStandardItem *itm_Q=new QStandardItem(QString::number(Q3(i,0)));
        mdl_n->setItem(i,2,itm_Q);
        qDebug()<<"H "<<H3(i,0)<<"Q "<<Q3(i,0);
    }
    ui->ElementTable->setModel(mdl_e);
    ui->ElementTable->resizeColumnsToContents();
    ui->ElementTable->resizeRowsToContents();
    ui->NodeTable->setModel(mdl_n);
    this->show();
if(stop==1)
{
    error_dialog* error=new error_dialog;
    error->callerror("Manual Stop, Error in Input or Inconvergent Problem Set");
}
}


void Results::on_pushButton_clicked()
{
    this->close();
}

void Results::on_csv_pb_clicked()
{
    int i;
    QString filename=QFileDialog::getSaveFileName(0,"Save Csv as", QDir::currentPath(),"Comma Separated Values(*.csv)");
    QFile file(filename);
    file.open(QFile::WriteOnly|QFile::Text);
    QTextStream out(&file);
    out<<"Generated by LiquiNet,,,\n,,,\nElement No.,Element Type,Flow from Node,Flow to Node,Dia,Length,Roughness,k factor,Booster Head,Valve Opening,Valve n factor,Flow,Head Loss,Error (%)\n";
    for(i=0;i<E;i++)
    {
        out<<QString::number(i+1)<<","<<element_type(i)<<","<<QString::number(en(i,0))<<","<<QString::number(en(i,1))<<","<<QString::number(D(i))<<","<<QString::number(L(i))<<","<<QString::number(e(i))<<","<<QString::number(k(i))<<","<<QString::number(Hd(i))<<","<<QString::number(o(i))<<","<<QString::number(n(i))<<","<<QString::number(qc(i))<<","<<QString::number(hc(i))<<","<<QString::number(err(i))<<"\n";
    }
    out<<",,,\nNode No.,Nodal Head,Nodal Flow,\n";
    for(i=0;i<N;i++)
    {
        out<<QString::number(i+1)<<","<<QString::number(H3(i,0))<<","<<QString::number(Q3(i))<<"\n";
    }

    file.flush();
    file.close();
}

QString Results::element_type(int i)
{
    if(ch(i)==1)
        return "Pipe Element";
    else if(ch(i)==2)
        return "Booster";
    else if(ch(i)==3)
        return "Flow Control Valve";
}
