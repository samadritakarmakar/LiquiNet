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



#ifndef DETAIL_INPUT_H
#define DETAIL_INPUT_H

#include <QMainWindow>

namespace Ui {
class Detail_Input;
}

class Detail_Input : public QMainWindow
{
    Q_OBJECT

public:
    explicit Detail_Input(QWidget *parent = 0);
    ~Detail_Input();
public:
    void first_display();
    void show_detail_elmnt();
    void set_elmnt_dtls_rb();
    void show_detail_nde();
    void nde_input();
    void set_nde_rb();
    void uncheck_nde_rb();
    void chk_slv_pb_status();

private slots:
    void on_nxt_elmnt_pb_clicked();

    void on_pipe_sgmnt_rb_clicked();

    void on_booster_rb_clicked();

    void on_fcv_rb_clicked();

    void on_prvs_elmnt_pb_clicked();

    void on_nxt_nde_pb_clicked();

    void on_head_nde_rb_clicked();

    void on_flw_nde_rb_clicked();

    void on_prv_nde_pb_clicked();

    void on_slve_pb_clicked();

    void on_save_as_pb_clicked();

    void set_stop();

    void on_slctn_hlpr_clicked();

    int node_ok();

private:
    Ui::Detail_Input *ui;
};

#endif // DETAIL_INPUT_H
