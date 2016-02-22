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
#include "../tracks_item.h"
#include "../tracks_item_p.h"
#include <QHBoxLayout>
#include <QPainter>
#include <QPalette>
#include <QVBoxLayout>
#include <algorithm>
#include <cmath>
#include <random>
#include <QRockyStyle.h>

namespace RocaEdit {

TracksItem::TracksItem(QWidget *widget) :
    QWidget(widget),
    d(new TracksItemPrivate(this)) {
    auto em = QRockyStyle::em(this);

    this->setAutoFillBackground(true);
    QPalette palette(this->palette());
    palette.setColor(QPalette::Window, palette.alternateBase().color());
    palette.setColor(QPalette::WindowText, palette.brightText().color());
    palette.setColor(QPalette::Button, palette.alternateBase().color());
    palette.setColor(QPalette::ButtonText, QColor(0x33, 0x33, 0x33));
    palette.setColor(QPalette::Light, QColor(0x33, 0x33, 0x33));
    this->setPalette(palette);

    d->lbl_color = new QWidget;
    d->lbl_color->setMinimumWidth(qRound(em));
    d->lbl_color->setMaximumWidth(qRound(em));
    d->lbl_color->setSizePolicy(QSizePolicy::Fixed, QSizePolicy::Minimum);

    d->lbl_artwork = new QLabel;
    auto pxm_artwork = QIcon::fromTheme("face-smile").pixmap(qRound(4*em), qRound(4*em));
    d->lbl_artwork->setPixmap(pxm_artwork);
    d->lbl_artwork->setMinimumSize(qRound(4*em), qRound(4*em));
    d->lbl_artwork->setMaximumSize(qRound(4*em), qRound(4*em));

    d->lbl_trackname = new QLabel("Track 1");
    QFont font1_5x(this->font());
    if(font1_5x.pointSizeF() > 0) {
        font1_5x.setPointSizeF(font1_5x.pointSizeF()*3/2);
    } else {
        font1_5x.setPixelSize((font1_5x.pixelSize()*3+1)/2);
    }
    d->lbl_trackname->setFont(font1_5x);
    d->lbl_trackname->setPalette(palette);
    d->lbl_trackname->setSizePolicy(QSizePolicy::Ignored, QSizePolicy::Fixed);
    d->lbl_sfname = new QLabel("Roca IcySnowy 0.1.0alpha");
    d->lbl_sfname->setPalette(palette);
    d->lbl_sfname->setSizePolicy(QSizePolicy::Ignored, QSizePolicy::Fixed);

    d->btn_mute = new QRockyButton("M");
    d->btn_mute->setCheckable(true);
    d->btn_mute->setCombineBorders(QRockyStyle::Combine_Right);
    d->btn_mute->setMinMaxSize(qRound(1.5*em), qRound(1.5*em));
    d->btn_mute->setPalette(palette);
    d->btn_solo = new QRockyButton("S");
    d->btn_solo->setCheckable(true);
    d->btn_solo->setCombineBorders(QRockyStyle::Combine_Left);
    d->btn_solo->setMinMaxSize(qRound(1.5*em), qRound(1.5*em));
    d->btn_solo->setPalette(palette);

    d->sld_volume = new QSlider;
    d->sld_volume->setMinimum(0);
    d->sld_volume->setMaximum(65536);
    d->sld_volume->setValue(65536);
    d->sld_volume->setMinimumWidth(qRound(7*em));
    d->sld_volume->setSizePolicy(QSizePolicy::MinimumExpanding, QSizePolicy::Minimum);
    d->sld_volume->setOrientation(Qt::Horizontal);
    this->connect(d->sld_volume, &QSlider::valueChanged, this, &TracksItem::onVolumeChange);
    d->lbl_volume = new QLabel("0.0 dB");
    d->lbl_volume->setMinimumWidth(qRound(4.5*em));
    d->lbl_volume->setPalette(palette);

    auto layout0 = new QVBoxLayout;
    layout0->addWidget(d->lbl_trackname);
    layout0->addWidget(d->lbl_sfname);

    auto layout1 = new QHBoxLayout;
    layout1->addWidget(d->lbl_artwork);
    layout1->addSpacing(qRound(em));
    layout1->addLayout(layout0);

    auto layout2 = new QHBoxLayout;
    layout2->addSpacing(qRound(em/2));
    layout2->addWidget(d->btn_mute);
    layout2->addWidget(d->btn_solo);
    layout2->addSpacing(qRound(1.5*em));
    layout2->addWidget(d->sld_volume);
    layout2->addSpacing(qRound(em/2));
    layout2->addWidget(d->lbl_volume);

    auto layout3 = new QVBoxLayout;
    layout3->addSpacing(qRound(em/8));
    layout3->addLayout(layout1);
    layout3->addLayout(layout2);
    layout3->addSpacing(qRound(em/2));

    auto layout = new QHBoxLayout;
    layout->setMargin(0);
    layout->setSpacing(0);
    layout->addWidget(d->lbl_color);
    layout->addLayout(layout3);

    this->setLayout(layout);

    this->setColor(generateColor());
}

TracksItem::~TracksItem() {
}

void TracksItem::paintEvent(QPaintEvent *) {
    auto  em = QRockyStyle::em(this);
    QPainter painter(this);
    painter.setRenderHint(QPainter::Antialiasing);
    painter.setPen(Qt::NoPen);
    painter.setBrush(QBrush(d->track_color));
    painter.drawRect(QRectF(d->lbl_color->geometry()));
    painter.setBrush(QBrush(QColor(0x26, 0x2d, 0x33)));
    painter.drawRect(QRectF(0, 0, this->geometry().width(), em/8));
}

QColor TracksItem::generateColor() {
    std::random_device rd;
    std::default_random_engine re(rd());
    std::uniform_real_distribution<qreal> hdist(0, 1);
    std::normal_distribution<qreal> sdist(1/3.0, 1/24.0);
    std::normal_distribution<qreal> ldist(0.5, 1/12.0);
    qreal h = hdist(re);
    qreal s = std::max<qreal>(std::min<qreal>(sdist(re), 5.0/24), 11.0/24);
    qreal l = std::max<qreal>(std::min<qreal>(ldist(re), 0.75), 0.25);
    return QColor::fromHslF(h, s, l).toRgb();
}

const QColor &TracksItem::color() const {
    return d->track_color;
}

void TracksItem::setColor(const QColor &color) {
    d->track_color = color;
    this->update();
}

void TracksItem::onVolumeChange(int value) {
    int vol = value;
    if(vol != 0) {
        double vol_db = std::log10(double(value) / d->sld_volume->maximum())*20;
        d->lbl_volume->setText(QString("%1 dB").arg(vol_db, 0, 'f', 1));
    } else {
        d->lbl_volume->setText(u8"-\u221e dB");
    }
}

}
