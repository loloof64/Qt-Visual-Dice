#include "visualdice.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    loloof64::VisualDice w;
    w.show();

    return a.exec();
}
