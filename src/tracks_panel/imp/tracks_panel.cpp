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
#include "../tracks_panel.h"
#include "../tracks_panel_p.h"
#include <QScrollArea>
#include <QVBoxLayout>
#include "../tracks_bus.h"
#include "../tracks_item.h"

namespace RocaEdit {

TracksPanel::TracksPanel(QWidget *parent) :
    SidePanel("Tracks", parent),
    d(new TracksPanelPrivate(this)) {

    d->tracks_bus = new TracksBus;
    d->tracks_list = new QWidget;

    auto layout0 = new QVBoxLayout;
    layout0->setMargin(0);
    layout0->setSpacing(0);
    for(int i = 0; i < 16; ++i) {
        layout0->addWidget(new TracksItem);
    }
    layout0->addStretch();
    d->tracks_list->setLayout(layout0);

    auto scroll_area = new QScrollArea;
    scroll_area->setWidgetResizable(true);
    scroll_area->setWidget(d->tracks_list);
    scroll_area->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);

    auto layout = new QVBoxLayout;
    layout->setMargin(0);
    layout->setSpacing(0);
    layout->addWidget(d->tracks_bus);
    layout->addWidget(scroll_area);

    this->centralWidget()->setLayout(layout);
}

TracksPanel::~TracksPanel() {
}

}
