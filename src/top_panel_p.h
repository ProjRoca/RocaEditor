/*
    Project Roca
    Copyright (C) 2016 StarBrilliant <m13253@hotmail.com>

    This program is free software; you can redistribute it and/or
    modify it under the terms of the GNU Lesser General Public
    License as published by the Free Software Foundation; either
    version 3.0 of the License, or (at your option) any later version.

    This program is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
    Lesser General Public License for more details.

    You should have received a copy of the GNU Lesser General Public
    License along with this program.  If not,
    see <http://www.gnu.org/licenses/>.
*/
#pragma once
#include "top_panel.h"
#include <QComboBox>
#include <QHBoxLayout>
#include <QRockyButton.h>

namespace RocaEdit {

class TopPanelPrivate {
    friend class TopPanel;
    class TopPanel *q;

    TopPanelPrivate(TopPanel *q) :
        q(q) {
    }

    QRockyButton *btn_new;
    QRockyButton *btn_open;
    QRockyButton *btn_save;

    QRockyButton *btn_cut;
    QRockyButton *btn_copy;
    QRockyButton *btn_paste;

    QRockyButton *btn_render;
    QRockyButton *btn_settings;

    QWidget *playback_control;

    QRockyButton *btn_select;
    QRockyButton *btn_draw;

    QComboBox *cmb_quantize;
    QComboBox *cmb_notelen;

    QRockyButton *btn_lyric;
    QRockyButton *btn_pitch;
    QRockyButton *btn_timing;
};

}
