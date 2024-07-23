#include "topbar.h"

TopBar::TopBar(QPushButton* button, QLabel* title, QPixmap button_icon)
{
    QHBoxLayout* layout = new QHBoxLayout(this);

    button->setIcon(QIcon(button_icon));
    button->setIconSize(QSize(50,50));
    button->setFixedSize(50,50);
    button->setCursor(Qt::PointingHandCursor);
    button->setToolTip("Home");
    button->setStyleSheet("border: none; background-color: transparent;");
    title->setStyleSheet("border: 5px solid #d0d0d0; border-radius: 10px; background-color: white;");
    title->setAlignment(Qt::AlignCenter);
    layout->addWidget(button);
    layout->addWidget(title);

    this->setLayout(layout);
}
