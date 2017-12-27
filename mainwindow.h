#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include "LifeBoard.h"
#include "gamesquare.h"
#include <vector>



#include <QMainWindow>
#include <QPushButton>
#include <QLabel>
#include <QGraphicsScene>
#include <QGraphicsRectItem>
#include <QGraphicsView>
#include <QDebug>
#include <QGroupBox>
#include <QHBoxLayout>
#include <QVBoxLayout>
#include <QWidget>

namespace Ui {
class MainWindow;
}
class GameSquare;
class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    void setUpGrid(size_t, size_t);
    void setUpDebugInfo();
    void setUpSquares();
    void setSquareValue(size_t, size_t, bool);
    ~MainWindow();
private slots:
    void nextStepHandler();
private:
//    Ui::MainWindow *ui;
    QGraphicsView * m_view;
    QGraphicsScene * m_scene;
    QGroupBox * m_debugBox;
    QVBoxLayout * m_debugLayout;
    LifeBoard m_board;
    QPushButton * m_nextStepButton;
    std::vector<std::vector<GameSquare*>> m_squarePtrs;
};

#endif // MAINWINDOW_H
