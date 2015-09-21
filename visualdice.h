#ifndef VISUALDICE_H
#define VISUALDICE_H

#define DEFAULT_BLOCK_SIZE 75

#include <array>
#include <string>

#include <QWidget>
#include <QAbstractButton>
#include <QPaintEvent>
#include <QColor>

namespace loloof64 {

    class VisualDice : public QAbstractButton
    {
        Q_OBJECT

    public:
        explicit VisualDice(QWidget *parent = 0, int blocksSize = DEFAULT_BLOCK_SIZE);
        explicit VisualDice(int blocksSize);
        ~VisualDice();

    public slots:
        void throwDice();

    private:
        const int blocksSize;
        const QColor backgroundColor{Qt::white};
        const QColor pointsColor{Qt::black};

        int drawnValue{0};

        /*
         * Each string define all points coords for a given value.
         * For each couple of digits, row is the first given.
         */
        std::array<std::string, 6> pointsDef {{
            "11", "0220", "021120", "00022022", "0002112022", "000210122022"
        }};

        void init();
        void paintEvent(QPaintEvent* event);
    };

}

#endif // VISUALDICE_H
