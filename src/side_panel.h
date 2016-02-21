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
#include <QVBoxLayout>

namespace RocaEdit {

class SidePanel : public QWidget {
    Q_OBJECT

public:
    explicit SidePanel(const QString &title, QWidget *parent = nullptr);
    ~SidePanel();
    class PanelHeader *headerWidget() const {
        return header;
    }
    QWidget *centralWidget() const {
        return central;
    }
    void setHeaderWidget(class PanelHeader *header);
    void setCentralWidget(QWidget *central);

private:
    QVBoxLayout *layout;
    class PanelHeader *header;
    QWidget *central;
};

}
