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



#ifndef PROGRESS_H
#define PROGRESS_H

#include <QWidget>

namespace Ui {
class Progress;
}

class Progress : public QWidget
{
    Q_OBJECT

public:
    explicit Progress(QWidget *parent = 0);
    ~Progress();
//    void set_progress(int p);

public slots:
    void set_progress(int p);
        /*void on_stop_pb_clicked();*/

/*private slots:
    void on_stop_pb_clicked();*/

public:
    Ui::Progress *ui;
/*private:
    Ui::Progress *ui;*/
};

#endif // PROGRESS_H
