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
#include <QLabel>
#include <QRockyButton.h>
#include <QSlider>

namespace RocaEdit {

class TracksItemPrivate {
    friend class TracksItem;
    class TracksItem *q;

public:
    explicit TracksItemPrivate(TracksItem *q) :
        q(q) {
    }

private:
    QColor track_color;
    QWidget *lbl_color;
    QLabel *lbl_artwork;
    QLabel *lbl_trackname;
    QLabel *lbl_sfname;
    QRockyButton *btn_mute;
    QRockyButton *btn_solo;
    QSlider *sld_volume;
};

}
