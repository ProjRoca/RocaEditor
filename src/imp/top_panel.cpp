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
#include <QButtonGroup>
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
    this->setMinimumHeight(qRound(5*em));
    this->setMaximumHeight(qRound(5*em));
    this->setSizePolicy(QSizePolicy::MinimumExpanding, QSizePolicy::Fixed);

    d->btn_render = new QRockyButton(u8"\u238b");
    d->btn_render->setMinMaxSize(qRound(2.5*em), qRound(2.5*em));

    d->btn_begin = new QRockyButton(u8"\u23ea");
    d->btn_begin->setCombineBorders(QRockyStyle::Combine_Right);
    d->btn_begin->setMinMaxSize(qRound(2.5*em), qRound(2.5*em));
    d->btn_play = new QRockyButton(u8"\u23f5");
    d->btn_play->setCheckable(true);
    d->btn_play->setCombineBorders(QRockyStyle::Combine_Left | QRockyStyle::Combine_Right);
    d->btn_play->setMinMaxSize(qRound(2.5*em), qRound(2.5*em));
    d->btn_end = new QRockyButton(u8"\u23e9");
    d->btn_end->setCombineBorders(QRockyStyle::Combine_Left);
    d->btn_end->setMinMaxSize(qRound(2.5*em), qRound(2.5*em));

    d->transport = new QWidget;
    d->transport->setPalette(style()->standardPalette());
    d->transport->setMinimumSize(qRound(16*em), qRound(3*em));
    d->transport->setMaximumSize(qRound(16*em), qRound(3*em));

    d->btn_select = new QRockyButton(u8"\u2b09");
    d->btn_select->setCheckable(true);
    d->btn_select->setChecked(true);
    d->btn_select->setCombineBorders(QRockyStyle::Combine_Right);
    d->btn_select->setMinMaxSize(qRound(2.5*em), qRound(2.5*em));
    d->btn_draw = new QRockyButton(u8"\U0001f589");
    d->btn_draw->setCheckable(true);
    d->btn_draw->setCombineBorders(QRockyStyle::Combine_Left);
    d->btn_draw->setMinMaxSize(qRound(2.5*em), qRound(2.5*em));
    auto btngrp_drawmode = new QButtonGroup(this);
    btngrp_drawmode->addButton(d->btn_select);
    btngrp_drawmode->addButton(d->btn_draw);
    btngrp_drawmode->setExclusive(true);

    d->cmb_quantize = new QComboBox;
    d->cmb_quantize->addItem("OFF");
    d->cmb_quantize->addItem("1/1");
    d->cmb_quantize->addItem("1/2");
    d->cmb_quantize->addItem("1/4");
    d->cmb_quantize->addItem("1/8");
    d->cmb_quantize->addItem("1/16");
    d->cmb_quantize->addItem("1/32");
    d->cmb_quantize->addItem("1/64");
    d->cmb_quantize->addItem("1/2T");
    d->cmb_quantize->addItem("1/4T");
    d->cmb_quantize->addItem("1/8T");
    d->cmb_quantize->addItem("1/16T");
    d->cmb_quantize->addItem("1/32T");
    d->cmb_quantize->addItem("1/64T");
    d->cmb_quantize->setCurrentIndex(5);
    d->cmb_quantize->setMinimumWidth(qRound(5*em));
    d->cmb_quantize->setMaximumWidth(qRound(5*em));
    d->cmb_quantize->setMinimumHeight(qRound(2.5*em));
    d->cmb_quantize->setMaximumHeight(qRound(2.5*em));

    d->btn_lyric = new QRockyButton("Lyrics");
    d->btn_lyric->setCheckable(true);
    d->btn_lyric->setChecked(true);
    d->btn_lyric->setCombineBorders(QRockyStyle::Combine_Right);
    d->btn_lyric->setMinMaxSize(qRound(4.5*em), qRound(2.5*em));
    d->btn_pitch = new QRockyButton("Pitch");
    d->btn_pitch->setCheckable(true);
    d->btn_pitch->setCombineBorders(QRockyStyle::Combine_Left | QRockyStyle::Combine_Right);
    d->btn_pitch->setMinMaxSize(qRound(4*em), qRound(2.5*em));
    d->btn_timing = new QRockyButton("Timing");
    d->btn_timing->setCheckable(true);
    d->btn_timing->setCombineBorders(QRockyStyle::Combine_Left);
    d->btn_timing->setMinMaxSize(qRound(4.5*em), qRound(2.5*em));
    auto btngrp_editlayer = new QButtonGroup(this);
    btngrp_editlayer->addButton(d->btn_lyric);
    btngrp_editlayer->addButton(d->btn_pitch);
    btngrp_editlayer->addButton(d->btn_timing);
    btngrp_editlayer->setExclusive(true);

    d->btn_labels = new QRockyButton(u8"\U0001f516");
    d->btn_labels->setCheckable(true);
    d->btn_labels->setChecked(true);
    d->btn_labels->setCombineBorders(QRockyStyle::Combine_Right);
    d->btn_labels->setMinMaxSize(qRound(2.5*em), qRound(2.5*em));
    d->btn_events = new QRockyButton(u8"\u2617");
    d->btn_events->setCheckable(true);
    d->btn_events->setCombineBorders(QRockyStyle::Combine_Left | QRockyStyle::Combine_Right);
    d->btn_events->setMinMaxSize(qRound(2.5*em), qRound(2.5*em));
    d->btn_notes = new QRockyButton(u8"\u266b");
    d->btn_notes->setCheckable(true);
    d->btn_notes->setCombineBorders(QRockyStyle::Combine_Left);
    d->btn_notes->setMinMaxSize(qRound(2.5*em), qRound(2.5*em));
    auto btngrp_rightpanel = new QButtonGroup(this);
    btngrp_rightpanel->addButton(d->btn_labels);
    btngrp_rightpanel->addButton(d->btn_events);
    btngrp_rightpanel->addButton(d->btn_notes);
    btngrp_rightpanel->setExclusive(true);

    auto layout0 = new QHBoxLayout;
    layout0->addSpacing(qRound(em/2));
    layout0->addWidget(d->btn_render);
    layout0->addSpacing(qRound(em/2));
    layout0->addWidget(d->btn_begin);
    layout0->addWidget(d->btn_play);
    layout0->addWidget(d->btn_end);
    layout0->addSpacing(qRound(2*em));
    layout0->addWidget(d->transport);
    layout0->addSpacing(qRound(2*em));
    layout0->addWidget(d->btn_select);
    layout0->addWidget(d->btn_draw);
    layout0->addSpacing(qRound(em/2));
    layout0->addWidget(d->cmb_quantize);
    layout0->addSpacing(qRound(em/2));
    layout0->addWidget(d->btn_lyric);
    layout0->addWidget(d->btn_pitch);
    layout0->addWidget(d->btn_timing);

    auto layout1 = new QHBoxLayout;
    layout1->addWidget(d->btn_labels);
    layout1->addWidget(d->btn_events);
    layout1->addWidget(d->btn_notes);
    layout1->addSpacing(qRound(em/2));

    auto layout = new QHBoxLayout;
    layout->setMargin(0);
    layout->setSpacing(0);
    layout->addLayout(layout0);
    layout->addStretch();
    layout->addLayout(layout1);
    this->setLayout(layout);
}

TopPanel::~TopPanel() {
}

void TopPanel::paintEvent(QPaintEvent *) {
    QPainter painter(this);
    auto em = QRockyStyle::em(this);
    painter.setRenderHint(QPainter::Antialiasing);
    painter.setPen(QPen(Qt::white, em*5/32));
    painter.setBrush(QColor(0x5c, 0x85, 0x83));
    painter.drawRoundedRect(QRectF(d->transport->geometry()), em/4, em/4);
}

}
