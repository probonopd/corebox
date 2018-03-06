/*
CoreBox is combination of some common desktop apps.

CoreBox is free software; you can redistribute it and/or
modify it under the terms of the GNU General Public License
as published by the Free Software Foundation; version 2
of the License.

This program is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with this program; if not, see {http://www.gnu.org/licenses/}. */

#include "coreaction/coreaction.h"

#include <QApplication>
#include <QDesktopWidget>
#include <QStyleFactory>
#include <QtSvg>


int main(int argc, char *argv[])
{
    QApplication app(argc, argv);
    app.setQuitOnLastWindowClosed(false);
    QApplication::setStyle(QStyleFactory::create("Fusion"));
    // Set application info
    app.setOrganizationName("coreaction");
    app.setApplicationName("coreaction");

    app.setWindowIcon(QIcon(":/icons/CoreAction.svg"));

    QDesktopWidget dw;
    coreaction a;

    int x = dw.width()*.23;
    int y = QApplication::desktop()->availableGeometry().height();
    a.setFixedSize(x, y);
    a.setWindowFlags(Qt::Window | Qt::FramelessWindowHint); //| Qt::ToolTip

    int sw = dw.width() - x;
    //int sh = dw.height();

    a.move(sw,0);

    return app.exec();
}
