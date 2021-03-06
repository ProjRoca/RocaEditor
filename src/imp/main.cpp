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
#include "../import_plugins.h"
#include <QApplication>
#include <QFont>
#include <QRockyStyle.h>
#include "../main_window.h"

int main(int argc, char *argv[]) {
    QApplication app(argc, argv);

    app.setStyle(new QRockyStyle);
    app.setPalette(app.style()->standardPalette());
    {
        QFont font(app.font());
        font.setHintingPreference(QFont::PreferNoHinting);
        font.setStyleHint(QFont::System, QFont::StyleStrategy(QFont::ForceOutline | QFont::PreferAntialias));
        app.setFont(font);
    }

    RocaEdit::MainWindow w;
    w.showMaximized();

    return app.exec();
}
