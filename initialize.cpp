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



#include "initialize.h"
#include "ui_initialize.h"
#include "global_variables.h"
#include "detail_input.h"
#include <QDebug>
#include <QXmlStreamReader>
#include <QFileDialog>
#include <QDir>
#include "selection_help.h"

mat C;
mat Q;
mat H;
mat C1;
mat Q1;
mat H1;
mat Q2;
mat H2;
mat A;
mat q;
mat qc;
mat f;
mat h0;
mat h;
mat hc;
mat c;
mat n;
mat n1;
mat n2;
mat cc;
mat en;
mat o;
mat D;
mat L;
mat e;
mat k;
mat K;
mat ch;
mat ch_n;
mat Cd;
mat Hd;
mat err;
mat H3;
mat Q3;
double range, ro, g, mu, Re0, Re, qa;
int N, E, elc=0,elcf=0, ndc=0, ndcf=0, stop=0,flg1;

Initialize::Initialize(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::Initialize)
{
    ui->setupUi(this);
}

Initialize::~Initialize()
{
    delete ui;
}

void Initialize::on_Dtl_Inpt_pb_clicked()
{
    range=ui->range_le->text().toDouble();
    g=ui->g_le->text().toDouble();
    ro=ui->ro_le->text().toDouble();
    mu=ui->mu_le->text().toDouble();
    Re0=ui->Re_le->text().toDouble();
    qa=ui->qa_le->text().toDouble();
    E=ui->E_le->text().toInt();
    N=ui->N_le->text().toInt();
    this->close();
    initialize_zeros();
    qDebug()<<C.n_rows<<C.n_cols;
    Detail_Input *d=new Detail_Input;
    d->show();
    /*selection_help* h=new selection_help(g, mu, ro);
    h->show();*/
}



void Initialize::on_opn_fle_pb_clicked()
{
    int i;
    QString filename=QFileDialog::getOpenFileName(0,tr("Open Problem Case"), QDir::currentPath(),"LiquiNet File(*.lqi)");
    QFile file(filename);
    if(file.open(QIODevice::ReadOnly))
    {
        QXmlStreamReader lqi(&file);
        while(!lqi.atEnd())
        {
            lqi.readNext();
            if(lqi.name().toString()=="range")

                range=lqi.readElementText().toDouble();

            else if(lqi.name().toString()=="g")

                g=lqi.readElementText().toDouble();

            else if(lqi.name().toString()=="ro")

                ro=lqi.readElementText().toDouble();

            else if(lqi.name().toString()=="mu")

                mu=lqi.readElementText().toDouble();

            else if(lqi.name().toString()=="Re0")

                Re0=lqi.readElementText().toDouble();

            else if (lqi.name().toString()=="qa")

                qa=lqi.readElementText().toDouble();

            else if(lqi.name().toString()=="E")

                E=lqi.readElementText().toInt();

            else if(lqi.name().toString()=="N")
            {
                 N=lqi.readElementText().toInt();
                 initialize_zeros();
            }
            else if(lqi.name().toString()=="elcf")

            elcf=lqi.readElementText().toInt();

            else if(lqi.name().toString()=="ndcf")

            ndcf=lqi.readElementText().toInt();

            else if(lqi.name().toString()=="element")
            {
                i=lqi.attributes().value("elc").toInt();
                while(lqi.readNextStartElement())
                {
                    if(lqi.name().toString()=="ch")
                        ch(i)=lqi.readElementText().toDouble();
                    else if(lqi.name().toString()=="D")
                        D(i)=lqi.readElementText().toDouble();
                    else if(lqi.name().toString()=="L")
                        L(i)=lqi.readElementText().toDouble();
                    else if(lqi.name().toString()=="e")
                        e(i)=lqi.readElementText().toDouble();
                    else if(lqi.name().toString()=="k")
                        k(i)=lqi.readElementText().toDouble();
                    else if(lqi.name().toString()=="q")
                        q(i)=lqi.readElementText().toDouble();
                    else if(lqi.name().toString()=="Hd")
                        Hd(i)=lqi.readElementText().toDouble();
                    else if(lqi.name().toString()=="o")
                        o(i)=lqi.readElementText().toDouble();
                    else if(lqi.name().toString()=="n")
                        n(i)=lqi.readElementText().toDouble();
                    else if(lqi.name().toString()=="en0")
                        en(i,0)=lqi.readElementText().toDouble();
                    else if(lqi.name().toString()=="en1")
                        en(i,1)=lqi.readElementText().toDouble();
                }

            }
            else if(lqi.name().toString()=="node")
            {
                i=lqi.attributes().value("ndc").toInt();
                while(lqi.readNextStartElement())
                {
                    if(lqi.name().toString()=="ch_n")
                        ch_n(i)=lqi.readElementText().toDouble();
                    else if(lqi.name().toString()=="H")
                        H(i)=lqi.readElementText().toDouble();
                    else if(lqi.name().toString()=="Q")
                        Q(i)=lqi.readElementText().toDouble();
                }
            }
        }
        Detail_Input *d=new Detail_Input;
        d->first_display();
        this->close();
        /*selection_help* h=new selection_help(g, mu, ro);
        h->show();*/
     }
}

void Initialize::initialize_zeros()
{
    C=zeros<mat>(N,N);
    Q=zeros<mat>(N,1);
    H=zeros<mat>(N,1);
    //C1=zeros<mat>(N); //Moved to set_H_Q.cpp
    //Q1=zeros<mat>(N,1); //Moved to set_H_Q.cpp
    //H1=zeros<mat>(N,1); //Moved to set_H_Q.cpp
    Q2=zeros<mat>(N,1);
    //H2=zeros<mat>(N,1);
    A=zeros<mat>(1,E);
    q=zeros<mat>(1,E);
    qc=zeros<mat>(1,E);
    f=zeros<mat>(1,E); //Copy made in on_slve_pb_clicked()
    h0=zeros<mat>(1,E);
    h=zeros<mat>(1,E);
    hc=zeros<mat>(1,E);
    c=zeros<mat>(1,E);
    n=zeros<mat>(1,E);
    //n1=zeros<mat>(1,N); //Moved to set_H_Q.cpp
    //n2=zeros<mat>(1,N); //Moved to set_H_Q.cpp
    cc=zeros<mat>(1,E);
    en=zeros<mat>(E,2);
    o=zeros<mat>(1,E);
    D=zeros<mat>(1,E);
    L=zeros<mat>(1,E);
    e=zeros<mat>(1,E);
    k=zeros<mat>(1,E);//to be added in head loss calc for pipe.
    K=zeros<mat>(1,E);
    ch=zeros<mat>(1,E);
    ch_n=zeros<mat>(1,N);
    Cd=zeros<mat>(N,E);
    Hd=zeros<mat>(E,1);
    err=zeros<mat>(1,E);
    //H3=zeros<mat>(N,1); //Moved to detail_input.cpp, on_slve_pb_clicked()
    //Q3=zeros<mat>(N,1); //Moved to detail_input.cpp, on_slve_pb_clicked()
}
