//
// Created by jeremy on 11/22/20.
//

#ifndef SCREENSHOT_H
#define SCREENSHOT_H

#include <QPixmap>
#include <QWidget>

QT_BEGIN_NAMESPACE
class QGroupBox;
class QHBoxLayout;
class QLabel;
class QPushButton;
class QSpinBox;
class QVBoxLayout;
QT_END_NAMESPACE

class Screenshot : public QWidget
{
Q_OBJECT

public:
    Screenshot();

private slots:
    void shootScreen();

private:
    void updateScreenshotLabel();

    QPixmap originalPixmap;
    QLabel *screenshotLabel;
};

#endif // SCREENSHOT_H

