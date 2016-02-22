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
#include "../tracks_bus.h"
#include "../tracks_bus_p.h"
#include <QHBoxLayout>
#include <QPainter>
#include <QPalette>
#include <QVBoxLayout>
#include <algorithm>
#include <cmath>
#include <random>
#include <QRockyStyle.h>

namespace RocaEdit {

TracksBus::TracksBus(QWidget *widget) :
    QWidget(widget),
    d(new TracksBusPrivate(this)) {
    auto em = QRockyStyle::em(this);

    this->setAutoFillBackground(true);
    QPalette palette(this->palette());
    palette.setColor(QPalette::Window, palette.alternateBase().color());
    palette.setColor(QPalette::WindowText, palette.brightText().color());
    palette.setColor(QPalette::Button, palette.alternateBase().color());
    palette.setColor(QPalette::ButtonText, QColor(0x33, 0x33, 0x33));
    palette.setColor(QPalette::Light, QColor(0x33, 0x33, 0x33));
    this->setPalette(palette);

    d->btn_mute = new QRockyButton("M");
    d->btn_mute->setCheckable(true);
    d->btn_mute->setCombineBorders(QRockyStyle::Combine_Right);
    d->btn_mute->setMinMaxSize(qRound(1.5*em), qRound(1.5*em));
    d->btn_mute->setPalette(palette);
    d->btn_render = new QRockyButton("R");
    d->btn_render->setCombineBorders(QRockyStyle::Combine_Left);
    d->btn_render->setMinMaxSize(qRound(1.5*em), qRound(1.5*em));
    d->btn_render->setPalette(palette);

    d->sld_volume = new QSlider;
    d->sld_volume->setMinimum(0);
    d->sld_volume->setMaximum(65536);
    d->sld_volume->setValue(65536);
    d->sld_volume->setMinimumWidth(qRound(7*em));
    d->sld_volume->setSizePolicy(QSizePolicy::MinimumExpanding, QSizePolicy::Minimum);
    d->sld_volume->setOrientation(Qt::Horizontal);
    this->connect(d->sld_volume, &QSlider::valueChanged, this, &TracksBus::onVolumeChange);
    d->lbl_volume = new QLabel("0.0 dB");
    d->lbl_volume->setMinimumWidth(qRound(4.5*em));
    d->lbl_volume->setPalette(palette);

    auto layout0 = new QHBoxLayout;
    layout0->addSpacing(qRound(1.5*em));
    layout0->addWidget(d->btn_mute);
    layout0->addWidget(d->btn_render);
    layout0->addSpacing(qRound(1.5*em));
    layout0->addWidget(d->sld_volume);
    layout0->addSpacing(qRound(em/2));
    layout0->addWidget(d->lbl_volume);
    layout0->addSpacing(qRound(em));

    auto layout = new QVBoxLayout;
    layout->setMargin(0);
    layout->setSpacing(0);
    layout->addSpacing(qRound(em));
    layout->addLayout(layout0);
    layout->addSpacing(qRound(em));

    this->setLayout(layout);
}

TracksBus::~TracksBus() {
}

void TracksBus::onVolumeChange(int value) {
    int vol = value;
    if(vol != 0) {
        double vol_db = std::log10(double(value) / d->sld_volume->maximum())*20;
        d->lbl_volume->setText(QString("%1 dB").arg(vol_db, 0, 'f', 1));
    } else {
        d->lbl_volume->setText(u8"-\u221e dB");
    }
}

}
