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
#include "../top_panel.h"
#include "../top_panel_p.h"
#include <QHBoxLayout>
#include <QPainter>
#include <QStyle>

namespace RocaEdit {

TopPanel::TopPanel(QWidget *parent) :
    QWidget(parent),
    d(new TopPanelPrivate(this)) {
    auto em = QRockyStyle::em(this);
    this->setAutoFillBackground(true);
    QPalette palette(this->palette());
    palette.setColor(QPalette::Window, QColor(0x82, 0x8a, 0x8c));
    this->setPalette(palette);

    this->setMaximumHeight(qRound(4*em));
    d->btn_new = new QRockyButton("New");
    d->btn_new->setCombineBorders(QRockyStyle::Combine_Right);
    d->btn_new->setMinMaxSize(qRound(2*em), qRound(2*em));
    d->btn_open = new QRockyButton("Opn");
    d->btn_open->setCombineBorders(QRockyStyle::Combine_Left | QRockyStyle::Combine_Right);
    d->btn_open->setMinMaxSize(qRound(2*em), qRound(2*em));
    d->btn_save = new QRockyButton("Sav");
    d->btn_save->setCombineBorders(QRockyStyle::Combine_Left);
    d->btn_save->setMinMaxSize(qRound(2*em), qRound(2*em));
    d->btn_render = new QRockyButton("Rdr");
    d->btn_render->setCombineBorders(QRockyStyle::Combine_Right);
    d->btn_render->setMinMaxSize(qRound(2*em), qRound(2*em));
    d->btn_settings = new QRockyButton("Stg");
    d->btn_settings->setCombineBorders(QRockyStyle::Combine_Left);
    d->btn_settings->setMinMaxSize(qRound(2*em), qRound(2*em));
    d->btn_select = new QRockyButton("Sel");
    d->btn_select->setCheckable(true);
    d->btn_select->setChecked(true);
    d->btn_select->setCombineBorders(QRockyStyle::Combine_Right);
    d->btn_select->setMinMaxSize(qRound(2*em), qRound(2*em));
    d->btn_draw = new QRockyButton("Drw");
    d->btn_draw->setCheckable(true);
    d->btn_draw->setCombineBorders(QRockyStyle::Combine_Left);
    d->btn_draw->setMinMaxSize(qRound(2*em), qRound(2*em));
    d->cmb_quantize = new QComboBox;
    d->cmb_quantize->addItem("1/16");
    d->cmb_quantize->setMinimumHeight(qRound(2*em));
    d->cmb_quantize->setMaximumHeight(qRound(2*em));
    d->cmb_notelen = new QComboBox;
    d->cmb_notelen->addItem("L1/8");
    d->cmb_notelen->setMinimumHeight(qRound(2*em));
    d->cmb_notelen->setMaximumHeight(qRound(2*em));
    d->btn_lyric = new QRockyButton("Lrc");
    d->btn_lyric->setCheckable(true);
    d->btn_lyric->setChecked(true);
    d->btn_lyric->setCombineBorders(QRockyStyle::Combine_Right);
    d->btn_lyric->setMinMaxSize(qRound(2*em), qRound(2*em));
    d->btn_pitch = new QRockyButton("Pit");
    d->btn_pitch->setCheckable(true);
    d->btn_pitch->setCombineBorders(QRockyStyle::Combine_Left | QRockyStyle::Combine_Right);
    d->btn_pitch->setMinMaxSize(qRound(2*em), qRound(2*em));
    d->btn_timing = new QRockyButton("Tim");
    d->btn_timing->setCheckable(true);
    d->btn_timing->setCombineBorders(QRockyStyle::Combine_Left);
    d->btn_timing->setMinMaxSize(qRound(2*em), qRound(2*em));
    auto layout = new QHBoxLayout;
    layout->setMargin(0);
    layout->setSpacing(0);
    layout->addSpacing(qRound(em));
    layout->addWidget(d->btn_new);
    layout->addWidget(d->btn_open);
    layout->addWidget(d->btn_save);
    layout->addSpacing(qRound(em));
    layout->addWidget(d->btn_render);
    layout->addWidget(d->btn_settings);
    layout->addSpacing(qRound(em));
    layout->addStretch(0);
    layout->addSpacing(qRound(em));
    layout->addWidget(d->btn_select);
    layout->addWidget(d->btn_draw);
    layout->addSpacing(qRound(em));
    layout->addWidget(d->cmb_quantize);
    layout->addSpacing(qRound(em/2));
    layout->addWidget(d->cmb_notelen);
    layout->addSpacing(qRound(em));
    layout->addWidget(d->btn_lyric);
    layout->addWidget(d->btn_pitch);
    layout->addWidget(d->btn_timing);
    layout->addSpacing(qRound(em));
    this->setLayout(layout);
}

TopPanel::~TopPanel() {
}

void TopPanel::paintEvent(QPaintEvent *) {
    QStyleOption option;
    option.initFrom(this);
    QPainter painter(this);
    QRockyStyle().drawPrimitive(QStyle::PE_Widget, &option, &painter, this);
}

}
