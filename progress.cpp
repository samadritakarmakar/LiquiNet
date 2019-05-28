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



#include "progress.h"
#include "ui_progress.h"
#include "global_variables.h"

Progress::Progress(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Progress)
{
    ui->setupUi(this);
}

Progress::~Progress()
{
    delete ui;
}

/*void Progress::on_stop_pb_clicked()
{
    stop=1;
    this->close();
}*/

void Progress::set_progress(int p)
{
    //ui->progressBar->setMinimum(0);
    //ui->progressBar->setMaximum(99);
    ui->progressBar->setValue(p);
    this->show();
}
