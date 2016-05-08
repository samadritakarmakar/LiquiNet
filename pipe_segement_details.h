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



#ifndef PIPE_SEGEMENT_DETAILS_H
#define PIPE_SEGEMENT_DETAILS_H

#include <QWidget>

extern int p_sgmnt_flg;

namespace Ui {
class Pipe_Segement_Details;
}

class Pipe_Segement_Details : public QWidget
{
    Q_OBJECT

public:
    explicit Pipe_Segement_Details(QWidget *parent = 0);
    ~Pipe_Segement_Details();
public:
    void first_show();

private slots:


    void on_pipe_sgmnt_pb_clicked();

private:
    Ui::Pipe_Segement_Details *ui;
};

#endif // PIPE_SEGEMENT_DETAILS_H
