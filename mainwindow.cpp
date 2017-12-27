#include "mainwindow.h"
MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent)
{
    m_board = LifeBoard{std::vector<std::vector<bool>>(100,std::vector<bool>(100))};
    m_scene = new QGraphicsScene(this);
    m_scene->setSceneRect(0,0,800,800);
    m_view = new QGraphicsView(m_scene);
    m_view->setRenderHint(QPainter::Antialiasing);
    m_view->setScene(m_scene);
    m_view->setFrameStyle(0);
    m_view->setMaximumSize(800,800);
    m_debugBox = new QGroupBox{};
    m_debugLayout = new QVBoxLayout{};
    m_debugBox->setLayout(m_debugLayout);
    QHBoxLayout * mainLayout = new QHBoxLayout{};
    mainLayout->addWidget(m_view);
    mainLayout->addWidget(m_debugBox);
    QWidget * mainWidget = new QWidget{};
    mainWidget->setLayout(mainLayout);
    setCentralWidget(mainWidget);
    m_nextStepButton = new QPushButton{"Next Step", this};
    connect(m_nextStepButton, SIGNAL (released()), this, SLOT (nextStepHandler()));
    resize(1200, 900);
    setUpSquares();
}
void MainWindow::setUpSquares(){
    m_squarePtrs = std::vector<std::vector<GameSquare*>>(100, std::vector<GameSquare*>(100));
    for(size_t i = 0 ; i < m_board.getData().size(); ++i){
        for(size_t j = 0; j < m_board.getData()[i].size();++j){
            GameSquare * square = new GameSquare{i,j,false,this};
            m_squarePtrs[i][j] = square;
            m_scene->addItem(square);
            square->setPos(i*8,j*8);
        }
    }
}
void MainWindow::nextStepHandler(){
    auto changes = m_board.computeNextStep();
    for( std::pair<size_t, size_t> const & pair: changes){
        m_squarePtrs[std::get<0>(pair)][std::get<1>(pair)]->invertActivity();
    }
}
void MainWindow::setUpDebugInfo(){
    QLabel * label1 = new QLabel{};
    QLabel * label2 = new QLabel{};
    QLabel * label3 = new QLabel{};


    label1->setText("QGraphicsScene's sceneRect() width: "+QString::number(m_scene->sceneRect().width())+" Height: "+QString::number(m_scene->sceneRect().height()));
    label2->setText("QGraphicsView (inherited from QWidget)");
    label3->setText("width "+QString::number(m_view->width())+" height "+ QString::number(m_view->height()));
    m_debugLayout->addWidget(m_nextStepButton);
    m_debugLayout->addWidget(label1);
    m_debugLayout->addWidget(label2);
    m_debugLayout->addWidget(label3);

}
void MainWindow::setSquareValue(size_t i, size_t j , bool value){
    m_board.setValue(i, j, value);
}

MainWindow::~MainWindow()
{
}


