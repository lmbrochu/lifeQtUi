#ifndef GAMESQUARE_H
#define GAMESQUARE_H
#include "mainwindow.h"
#include <QGraphicsItem>

class MainWindow;
class GameSquare : public QGraphicsItem
{
public:
    GameSquare(size_t, size_t, bool, MainWindow *);
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *);
    QRectF boundingRect() const;
    void mousePressEvent(QGraphicsSceneMouseEvent *event);
    void invertActivity();
private:
    MainWindow * m_mainWindow;
    size_t m_i;
    size_t m_j;
    bool m_active;
};

#endif // GAMESQUARE_H
