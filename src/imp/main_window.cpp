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
#include "../main_window.h"
#include "../main_window_p.h"
#include <QVBoxLayout>
#include "../side_panel.h"

namespace RocaEdit {

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    d(new MainWindowPrivate(this)) {

    setWindowTitle("RocaEditor");

    d->center_widget = new QWidget;
    d->top_panel = new TopPanel;
    d->main_splitter = new QSplitter;
    d->main_splitter->setChildrenCollapsible(false);
    d->main_splitter->addWidget(new SidePanel("Tracks"));
    d->main_splitter->addWidget(new QWidget);
    d->main_splitter->addWidget(new SidePanel("Notes"));
    auto layout = new QVBoxLayout;
    layout->setMargin(0);
    layout->setSpacing(0);
    layout->addWidget(d->top_panel);
    layout->addWidget(d->main_splitter);
    d->center_widget->setLayout(layout);
    this->setCentralWidget(d->center_widget);
    this->adjustSize();
}

MainWindow::~MainWindow() {
}

}
