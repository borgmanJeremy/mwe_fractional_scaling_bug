//
// Created by jeremy on 11/22/20.
//


#include <QApplication>
#include <QScreen>

#include "screenshot.h"

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);

    Screenshot screenshot;
    app.exec();

    return 0;
}
