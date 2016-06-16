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



#include "detail_input.h"
#include "ui_detail_input.h"
#include "pipe_segement_details.h"
#include "booster_details.h"
#include "flow_control_valve_details.h"
#include <QString>
#include <QFile>
#include <QXmlStreamWriter>
#include <QFileDialog>
#include <QDir>
#include "global_variables.h"
#include <QDebug>

//error dialog for node input
#include "error_dialog.h"

#include "progress.h"
//unsure
#include "ui_progress.h"
#include "results.h"
#include "thread.h"
#include "selection_help.h"


//unsure at the time of addition
//#include "QPushButton"


//Element tab

int p_sgmnt_flg=0,bstr_flg=0,fcv_flg=0, slv_pb_flag1=0, slv_pb_flag2=0;


Detail_Input::Detail_Input(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::Detail_Input)
{
    ui->setupUi(this);
    this->setWindowTitle("Input Details");
}

Detail_Input::~Detail_Input()
{
    delete ui;
}

void Detail_Input::first_display()
{
    show_detail_elmnt();
    set_elmnt_dtls_rb();
    set_nde_rb();
    this->show();
}

void Detail_Input::on_nxt_elmnt_pb_clicked()
{
    if(elcf>=elc && elc<=E-1 && node_ok())
    {
        en(elc,0)=ui->nde_f_le->text().toInt();
        en(elc,1)=ui->nde_s_le->text().toInt();
        qDebug()<<en(elc,0)<<" "<<en(elc,1);
        if(elc<E-1)
        {
            elc++;
            show_detail_elmnt();
        }
    }
    if(elcf<elc && elcf<=E-1)
    {
        elcf=elc;
    }
    p_sgmnt_flg=0;
    bstr_flg=0;
    fcv_flg=0;
    set_elmnt_dtls_rb();
    if(elcf==E-1 && (ui->pipe_sgmnt_rb->isChecked() || ui->booster_rb->isChecked() || ui->fcv_rb->isChecked()))
    {
        slv_pb_flag1=1;
        chk_slv_pb_status();
    }
}

void Detail_Input::on_prvs_elmnt_pb_clicked()
{
    if(elc>0 && node_ok())
    {
            en(elc,0)=ui->nde_f_le->text().toInt();
            en(elc,1)=ui->nde_s_le->text().toInt();
            elc--;
            show_detail_elmnt();
            set_elmnt_dtls_rb();
    }
}



void Detail_Input::on_pipe_sgmnt_rb_clicked()
{
    Pipe_Segement_Details *d=new Pipe_Segement_Details;
    d->show();

    if(ch(elc)==1 || p_sgmnt_flg==1)
    {
        d->first_show();
    }
    ch(elc)=1;
    p_sgmnt_flg=1;

}

void Detail_Input::on_booster_rb_clicked()
{
    Booster_Details *d=new Booster_Details;

    d->show();
    if(ch(elc)==2 || bstr_flg==1)
    {
        d->first_show();
    }
    ch(elc)=2;
    bstr_flg=1;
}

void Detail_Input::on_fcv_rb_clicked()
{
    Flow_Control_Valve_Details *d=new Flow_Control_Valve_Details;
    d->show();
    if(ch(elc)==3 || fcv_flg==1)
    {
        d->first_show();
    }
    ch(elc)=3;
    fcv_flg=1;
}

void Detail_Input::show_detail_elmnt()
{
    if(elcf>=elc)
    {
       ui->nde_f_le->setText(QString::number(en(elc,0)));
       ui->nde_s_le->setText(QString::number(en(elc,1)));
    }
    else
    {
        ui->nde_f_le->setText("");
        ui->nde_s_le->setText("");
    }
    ui->E_le->setText(QString::number(elc+1));
}

void Detail_Input::set_elmnt_dtls_rb()
{
        if(ch(elc)==1)
        {
            ui->pipe_sgmnt_rb->setChecked(true);
        }
        else if(ch(elc)==2)
            {
                ui->booster_rb->setChecked(true);
            }
        else if(ch(elc)==3)
        {
            ui->fcv_rb->setChecked(true);
        }
        else if(ch(elc)==0)
        {
            ui->pipe_sgmnt_rb->setAutoExclusive(false);
            ui->pipe_sgmnt_rb->setChecked(false);
            ui->booster_rb->setAutoExclusive(false);
            ui->booster_rb->setChecked(false);
            ui->fcv_rb->setAutoExclusive(false);
            ui->fcv_rb->setChecked(false);
            ui->pipe_sgmnt_rb->setAutoExclusive(true);
            ui->booster_rb->setAutoExclusive(true);
            ui->fcv_rb->setAutoExclusive(true);
        }
}

//check if node is within limits
int Detail_Input::node_ok()
{
    qDebug()<<"working";
    int n1,n2;
    n1=ui->nde_f_le->text().toInt();
    n2=ui->nde_s_le->text().toInt();
    if(n1<0 || n1==0 || n1>N || n2<0 || n2==0 || n2>N)
    {
        error_dialog* e=new error_dialog;
        e->callerror("Check your node number Input");
        qDebug()<<"going in!!";
        return 0;
    }
    else
        return 1;
}

//Node tab

void Detail_Input::on_nxt_nde_pb_clicked()
{
    nde_input();
    if(ndc==ndcf && ndc<N-1)
    {
        ui->head_nde_le->setText("");
        ui->flw_nde_le->setText("");
        ui->head_nde_le->setDisabled(true);
        ui->flw_nde_le->setDisabled(true);
        uncheck_nde_rb();
        ndc++;
        ndcf++;
        ui->nde_nmbr_le->setText(QString::number(ndc+1));
    }
    else if(ndc<ndcf)
    {
        ndc++;
        set_nde_rb();
    }
    if(ndcf==N-1 && (ui->head_nde_rb->isChecked() || ui->flw_nde_rb->isChecked()))
    {
        slv_pb_flag2=1;
        chk_slv_pb_status();
    }
}

void Detail_Input::on_head_nde_rb_clicked()
{
    ui->flw_nde_le->setDisabled(true);
    ui->head_nde_le->setDisabled(false);
    ch_n(ndc)=1;
}

void Detail_Input::on_flw_nde_rb_clicked()
{
    ui->head_nde_le->setDisabled(true);
    ui->flw_nde_le->setDisabled(false);
    ch_n(ndc)=2;
}




void Detail_Input::on_prv_nde_pb_clicked()
{
    nde_input();
    if(ndc>0)
    {
        ndc--;
        set_nde_rb();
    }
}

void Detail_Input::nde_input()
{
    if(ui->head_nde_rb->isChecked())
    {

        H(ndc,0)=ui->head_nde_le->text().toDouble();
        ch_n(ndc)=1;
    }
    else if(ui->flw_nde_rb->isChecked())
    {
        Q(ndc,0)=ui->flw_nde_le->text().toDouble();
        //Q(ndc,0)=Q2(ndc,0);
        ch_n(ndc)=2;
    }
}

void Detail_Input::set_nde_rb()
{
    if(ch_n(ndc)==1)
    {
        uncheck_nde_rb();
        on_head_nde_rb_clicked();
        ui->head_nde_le->setText(QString::number(H(ndc,0)));
        ui->flw_nde_le->setText("");
        ui->head_nde_rb->setChecked(true);

    }
    else
    {
        on_flw_nde_rb_clicked();
        ui->flw_nde_le->setText(QString::number(Q(ndc,0)));
        ui->head_nde_le->setText("");
        ui->flw_nde_rb->setChecked(true);
    }
    ui->nde_nmbr_le->setText(QString::number(ndc+1));
}

void Detail_Input::uncheck_nde_rb()
{
    ui->head_nde_rb->setAutoExclusive(false);
    ui->flw_nde_rb->setAutoExclusive(false);
    ui->head_nde_rb->setChecked(false);
    ui->flw_nde_rb->setChecked(false);
    ui->head_nde_rb->setAutoExclusive(true);
    ui->flw_nde_rb->setAutoExclusive(true);
}

void Detail_Input::chk_slv_pb_status()
{
    if(slv_pb_flag1==1 && slv_pb_flag2==1)
        ui->slve_pb->setEnabled(true);
}

void Detail_Input::on_slve_pb_clicked()
{
    Progress *P=new Progress;
    Thread *t=new Thread;
    Results* e=new Results;
    H3=zeros<mat>(N,1);
    Q3=zeros<mat>(N,1);
    f=zeros<mat>(1,E);
    P->set_progress(0);
    connect(t,SIGNAL(prgrss(int)),P,SLOT(set_progress(int)));
    connect(P->ui->stop_pb,SIGNAL(clicked()),this,SLOT(set_stop()));
    connect(P->ui->stop_pb,SIGNAL(clicked()),P,SLOT(close()));
    connect(t,SIGNAL(finished()),P,SLOT(close()));
    connect(t,SIGNAL(finished()),e,SLOT(generate_results()));

    P->show();
    t->start();
    qDebug()<<flg1;
}

void Detail_Input::set_stop()
{
    stop=1;
}

//Save As Push Button

void Detail_Input::on_save_as_pb_clicked()
{
    QString filename=QFileDialog::getSaveFileName(0,tr("Save Problem Case as"), QDir::currentPath(),"LiquiNet File(*.lqi)");
        QFile file(filename);
        file.open(QIODevice::WriteOnly);
        QXmlStreamWriter lqi(&file);
        lqi.setAutoFormatting(true);
        lqi.writeStartDocument();
        lqi.writeStartElement("LiquiNet");
        lqi.writeTextElement("range", QString::number(range));
        lqi.writeTextElement("g", QString::number(g));
        lqi.writeTextElement("ro", QString::number(ro));
        lqi.writeTextElement("mu", QString::number(mu));
        lqi.writeTextElement("Re0", QString::number(Re0));
        lqi.writeTextElement("qa", QString::number(qa));
        lqi.writeTextElement("E", QString::number(E));
        lqi.writeTextElement("N", QString::number(N));
        lqi.writeTextElement("elcf", QString::number(elcf));
        lqi.writeTextElement("ndcf", QString::number(ndcf));
        for(int i=0;i<E;i++)
        {
            lqi.writeStartElement("element");
            lqi.writeAttribute("elc", QString::number(i));
            lqi.writeTextElement("ch", QString::number(ch(i)));
            lqi.writeTextElement("D", QString::number(D(i)));
            lqi.writeTextElement("L", QString::number(L(i)));
            lqi.writeTextElement("e", QString::number(e(i)));
            lqi.writeTextElement("k", QString::number(k(i)));
            lqi.writeTextElement("q", QString::number(q(i)));
            lqi.writeTextElement("Hd",QString::number(Hd(i)));
            lqi.writeTextElement("o",QString::number(o(i)));
            lqi.writeTextElement("n",QString::number(n(i)));
            lqi.writeTextElement("en0",QString::number(en(i,0)));
            lqi.writeTextElement("en1",QString::number(en(i,1)));
            lqi.writeEndElement();
        }
        for(int i=0;i<N;i++)
        {
            lqi.writeStartElement("node");
            lqi.writeAttribute("ndc", QString::number(i));
            lqi.writeTextElement("ch_n", QString::number(ch_n(i)));
            lqi.writeTextElement("H", QString::number(H(i,0)));
            lqi.writeTextElement("Q", QString::number(Q(i,0)));
            lqi.writeEndElement();
        }
        lqi.writeEndDocument();
        file.flush();
        file.close();

}
//open selection helper
void Detail_Input::on_slctn_hlpr_clicked()
{
    selection_help* h=new selection_help(g, mu, ro);
    h->show();
}

