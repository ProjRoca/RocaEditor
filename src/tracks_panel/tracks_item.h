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
#include <QWidget>
#include <memory>

namespace RocaEdit {

class TracksItem : public QWidget {
    Q_OBJECT
    friend class TracksItemPrivate;
    std::unique_ptr<class TracksItemPrivate> d;

public:
    explicit TracksItem(QWidget *widget = nullptr);
    ~TracksItem();
    static QColor generateColor();
    const QColor &color() const;
    void setColor(const QColor &color);
    void paintEvent(QPaintEvent *event);

private slots:
    void onVolumeChange(int value);
};

}
