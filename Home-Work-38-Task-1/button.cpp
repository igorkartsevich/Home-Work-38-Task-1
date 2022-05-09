#include "button.h"

Button::Button(QWidget *parent)
{
    setParent(parent);
    setSizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
    upPixmap = QPixmap("up_icon.png");
    downPixmap = QPixmap("down_icon.png");
    currentPixmap = upPixmap;
    setGeometry(currentPixmap.rect());

    connect(this, &QPushButton::clicked, this, &Button::setDown);

    player->setMedia(QUrl::fromLocalFile("click.mp3"));

}
void Button::paintEvent(QPaintEvent* e) {
    QPainter paint(this);
    paint.drawPixmap(e->rect(), currentPixmap);

}
void Button::keyPressEvent(QKeyEvent* event) {
    setDown();

}
void Button::setDown() {
    currentPixmap = downPixmap;
    update();
    player->setVolume(30);
    player->play();
    QTimer::singleShot(150, [this]() {
        currentPixmap = upPixmap;
        update();
        });

}