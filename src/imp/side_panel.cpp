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
#include "../side_panel.h"
#include "../panel_header.h"

namespace RocaEdit {

SidePanel::SidePanel(const QString &title, QWidget *parent) :
    QWidget(parent) {
    this->header = new PanelHeader(title);
    this->central = new QWidget;
    this->layout = new QVBoxLayout;

    this->layout->setMargin(0);
    this->layout->setSpacing(0);
    this->layout->addWidget(this->header);
    this->layout->addWidget(this->central);
    this->setLayout(this->layout);
    this->setSizePolicy(QSizePolicy::Minimum, QSizePolicy::MinimumExpanding);
}

SidePanel::~SidePanel() {
}

void SidePanel::setHeaderWidget(PanelHeader *header) {
    this->layout->replaceWidget(this->header, header, Qt::FindDirectChildrenOnly);
    delete this->header;
    this->header = header;
}

void SidePanel::setCentralWidget(QWidget *central) {
    this->layout->replaceWidget(this->central, central, Qt::FindDirectChildrenOnly);
    delete this->central;
    this->central = central;
}

}
