//
// Created by jeremy on 11/22/20.
//


#include <QtWidgets>

#include "screenshot.h"

Screenshot::Screenshot()
        :  screenshotLabel(new QLabel(this))
{
    setWindowFlags(Qt::BypassWindowManagerHint | Qt::WindowStaysOnTopHint | Qt::FramelessWindowHint | Qt::Tool);

    QVBoxLayout *mainLayout = new QVBoxLayout(this);
    mainLayout->setMargin(0);
    mainLayout->addWidget(screenshotLabel);
    shootScreen();
    move(0,0);
    this->showFullScreen();

}

void Screenshot::shootScreen()
{

    QRect geometry;
    for (QScreen* const screen : QGuiApplication::screens()) {
        QRect scrRect = screen->geometry();
        scrRect.moveTo(scrRect.x() / screen->devicePixelRatio(),
                       scrRect.y() / screen->devicePixelRatio());
        geometry = geometry.united(scrRect);
    }

    originalPixmap = (QApplication::primaryScreen()->grabWindow(
            QApplication::desktop()->winId(),
            geometry.x(),
            geometry.y(),
            geometry.width(),
            geometry.height()));
    auto screenNumber = QApplication::desktop()->screenNumber();

    screenshotLabel->setMinimumSize(geometry.width() , geometry.height() );

    QScreen* screen = QApplication::screens()[screenNumber];
    originalPixmap.setDevicePixelRatio(screen->devicePixelRatio());

    updateScreenshotLabel(screen->devicePixelRatio());
    resize(originalPixmap.size());

}

void Screenshot::updateScreenshotLabel(qreal pixel_ratio)
{
    auto scaled_pixmap = originalPixmap.scaled(screenshotLabel->size()*pixel_ratio,
                                               Qt::KeepAspectRatio,
                                               Qt::SmoothTransformation);

    screenshotLabel->resize(scaled_pixmap.size());
    screenshotLabel->setPixmap(scaled_pixmap);
    screenshotLabel->resize(scaled_pixmap.size());
}
