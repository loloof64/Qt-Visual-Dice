#include "visualdice.h"

#include <QPainter>
#include <QPainterPath>

#include <cstdlib>
#include <ctime>

namespace loloof64 {
    using namespace std;
    VisualDice::VisualDice(QWidget *parent, int blocksSize) :
        QAbstractButton(parent),
        blocksSize(blocksSize)
    {
        init();
    }

    VisualDice::VisualDice(int blocksSize) :
        VisualDice(0, blocksSize)
    {

    }

    VisualDice::~VisualDice()
    {

    }

    void VisualDice::init()
    {
        setFixedSize(3*blocksSize, 3*blocksSize);
        srand(time(0));
        connect(this, SIGNAL(clicked()), this, SLOT(throwDice()));
    }

    void VisualDice::paintEvent(QPaintEvent *event)
    {
        QPainter painter(this);
        painter.fillRect(0, 0, width(), height(), backgroundColor);

        string pointsCoords{pointsDef[drawnValue]};
        auto const coordsNumber = pointsCoords.size()/2;

        for (unsigned int i = 0; i < coordsNumber; i++){
            int row{pointsCoords[2*i] - '0'};
            int column{pointsCoords[2*i + 1] - '0'};

            QPainterPath circlePath{};
            circlePath.addEllipse((column+0.1) * blocksSize, (row+0.1) * blocksSize, blocksSize * 0.8, blocksSize * 0.8);
            painter.fillPath(circlePath, pointsColor);
        }
    }

    void VisualDice::throwDice(){
        drawnValue = rand() % 6;
    }
}
