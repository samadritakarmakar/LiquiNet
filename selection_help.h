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



#ifndef SELECTION_HELP_H
#define SELECTION_HELP_H

#include <QWidget>

namespace Ui {
class selection_help;
}

class selection_help : public QWidget
{
    Q_OBJECT

public:
    explicit selection_help(double g1, double mu1, double ro1, QWidget *parent = 0);
    ~selection_help();

private slots:
    void on_D_rb_clicked();

    void on_Hd_rb_clicked();

    void on_o_rb_clicked();

    void on_Go_pb_clicked();

private:
    Ui::selection_help *ui;
    double g, mu, ro;
    int ch_c;
};

#endif // SELECTION_HELP_H
