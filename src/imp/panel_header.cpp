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
#include "../panel_header.h"
#include <QRockyStyle.h>

namespace RocaEdit {

PanelHeader::PanelHeader(const QString &text, QWidget *parent) :
    QLabel(text, parent) {
    auto em = QRockyStyle::em(this);
    this->setAutoFillBackground(true);
    this->setMargin(qRound(em/2));
    this->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Fixed);
    QPalette palette(this->palette());
    palette.setBrush(QPalette::Window, palette.base());
    this->setPalette(palette);
}

PanelHeader::~PanelHeader() {
}

}
