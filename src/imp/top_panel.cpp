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
    this->setMinimumWidth(qRound(64*em));
    this->setMaximumHeight(qRound(5*em));

    d->btn_tracks = new QRockyButton(u8"\u2261");
    d->btn_tracks->setCheckable(true);
    d->btn_tracks->setChecked(true);
    d->btn_tracks->setMinMaxSize(qRound(2.5*em), qRound(2.5*em));

    d->btn_render = new QRockyButton(u8"\u238b");
    d->btn_render->setCombineBorders(QRockyStyle::Combine_Right);
    d->btn_render->setMinMaxSize(qRound(2.5*em), qRound(2.5*em));
    d->btn_settings = new QRockyButton(u8"\U0001f6c8");
    d->btn_settings->setCombineBorders(QRockyStyle::Combine_Left);
    d->btn_settings->setMinMaxSize(qRound(2.5*em), qRound(2.5*em));

    d->btn_begin = new QRockyButton(u8"\u23ee");
    d->btn_begin->setCombineBorders(QRockyStyle::Combine_Right);
    d->btn_begin->setMinMaxSize(qRound(2.5*em), qRound(2.5*em));
    d->btn_prev = new QRockyButton(u8"\u23ea");
    d->btn_prev->setCombineBorders(QRockyStyle::Combine_Left | QRockyStyle::Combine_Right);
    d->btn_prev->setMinMaxSize(qRound(2.5*em), qRound(2.5*em));
    d->btn_play = new QRockyButton(u8"\u23f5");
    d->btn_play->setCheckable(true);
    d->btn_play->setCombineBorders(QRockyStyle::Combine_Left | QRockyStyle::Combine_Right);
    d->btn_play->setMinMaxSize(qRound(2.5*em), qRound(2.5*em));
    d->btn_next = new QRockyButton(u8"\u23e9");
    d->btn_next->setCombineBorders(QRockyStyle::Combine_Left | QRockyStyle::Combine_Right);
    d->btn_next->setMinMaxSize(qRound(2.5*em), qRound(2.5*em));
    d->btn_end = new QRockyButton(u8"\u23ed");
    d->btn_end->setCombineBorders(QRockyStyle::Combine_Left);
    d->btn_end->setMinMaxSize(qRound(2.5*em), qRound(2.5*em));

    d->transport = new QWidget;
    d->transport->setAutoFillBackground(true);
    d->transport->setPalette(style()->standardPalette());
    d->transport->setMinimumSize(qRound(12*em), qRound(4*em));
    d->transport->setMaximumSize(qRound(12*em), qRound(4*em));

    d->btn_select = new QRockyButton(u8"\u2b09");
    d->btn_select->setCheckable(true);
    d->btn_select->setChecked(true);
    d->btn_select->setCombineBorders(QRockyStyle::Combine_Right);
    d->btn_select->setMinMaxSize(qRound(2.5*em), qRound(2.5*em));
    d->btn_draw = new QRockyButton(u8"\U0001f589");
    d->btn_draw->setCheckable(true);
    d->btn_draw->setCombineBorders(QRockyStyle::Combine_Left);
    d->btn_draw->setMinMaxSize(qRound(2.5*em), qRound(2.5*em));

    d->cmb_quantize = new QComboBox;
    d->cmb_quantize->addItem("1/16");
    d->cmb_quantize->setMinimumWidth(qRound(5*em));
    d->cmb_quantize->setMaximumWidth(qRound(5*em));
    d->cmb_quantize->setMinimumHeight(qRound(2.5*em));
    d->cmb_quantize->setMaximumHeight(qRound(2.5*em));

    d->btn_lyric = new QRockyButton("Lyrics");
    d->btn_lyric->setCheckable(true);
    d->btn_lyric->setChecked(true);
    d->btn_lyric->setCombineBorders(QRockyStyle::Combine_Right);
    d->btn_lyric->setMinMaxSize(qRound(4*em), qRound(2.5*em));
    d->btn_pitch = new QRockyButton("Pitch");
    d->btn_pitch->setCheckable(true);
    d->btn_pitch->setCombineBorders(QRockyStyle::Combine_Left | QRockyStyle::Combine_Right);
    d->btn_pitch->setMinMaxSize(qRound(4*em), qRound(2.5*em));
    d->btn_timing = new QRockyButton("Timing");
    d->btn_timing->setCheckable(true);
    d->btn_timing->setCombineBorders(QRockyStyle::Combine_Left);
    d->btn_timing->setMinMaxSize(qRound(4*em), qRound(2.5*em));

    d->btn_labels = new QRockyButton(u8"\U0001f516");
    d->btn_labels->setCheckable(true);
    d->btn_labels->setMinMaxSize(qRound(2.5*em), qRound(2.5*em));

    auto layout0 = new QHBoxLayout;
    layout0->setMargin(qRound(em));
    layout0->addWidget(d->btn_tracks);
    layout0->addSpacing(qRound(em/2));
    layout0->addWidget(d->btn_render);
    layout0->addWidget(d->btn_settings);
    layout0->addSpacing(qRound(em/2));
    layout0->addWidget(d->btn_begin);
    layout0->addWidget(d->btn_prev);
    layout0->addWidget(d->btn_play);
    layout0->addWidget(d->btn_next);
    layout0->addWidget(d->btn_end);
    layout0->addStretch();

    auto layout1 = new QHBoxLayout;
    layout1->addSpacing(qRound(em/4));
    layout1->addWidget(d->transport);
    layout1->addSpacing(qRound(em/4));

    auto layout2 = new QHBoxLayout;
    layout2->setMargin(qRound(em));
    layout2->addStretch();
    layout2->addWidget(d->btn_select);
    layout2->addWidget(d->btn_draw);
    layout2->addSpacing(qRound(em/2));
    layout2->addWidget(d->cmb_quantize);
    layout2->addSpacing(qRound(em/2));
    layout2->addWidget(d->btn_lyric);
    layout2->addWidget(d->btn_pitch);
    layout2->addWidget(d->btn_timing);
    layout2->addSpacing(qRound(em/2));
    layout2->addWidget(d->btn_labels);

    auto layout = new QHBoxLayout;
    layout->setMargin(0);
    layout->setSpacing(0);
    layout->addLayout(layout0, 1);
    layout->addLayout(layout1, 0);
    layout->addLayout(layout2, 1);
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
