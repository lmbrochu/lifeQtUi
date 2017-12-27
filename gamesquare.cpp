#include "gamesquare.h"

GameSquare::GameSquare(size_t i, size_t j, bool active, MainWindow * theMainWindow):m_i{i}, m_j{j}, m_active{active},
    m_mainWindow{theMainWindow}{

}
void GameSquare::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *){
    painter->setPen(QPen(Qt::black, 0));
    QColor color{};
    if(m_active){
        color = QColor{"#000"};
    }
    else{
        color = QColor{"#0F0"};
    }
    painter->drawRect(0,0,8,8);
    painter->fillRect(0,0,8,8,color); // same thing, local coordinates.
}
QRectF GameSquare::boundingRect() const{
    return QRect(0,0,8,8); // in local coordinates right... to be tested
}
void GameSquare::mousePressEvent(QGraphicsSceneMouseEvent *event){
     m_active = !m_active;
     m_mainWindow->setSquareValue(m_i, m_j, m_active);
     update();
     QGraphicsItem::mousePressEvent(event);
}
void GameSquare::invertActivity(){
    m_active = !m_active;
    update();
}
