#include <QCoreApplication>
#include <QTextStream>
#include <QImage>
#include <QString>
#include <QList>

#include "imgparse.h"

using namespace Qt;

int main()
{
    QTextStream in(stdin);
    QTextStream out(stdout);

    const QString imgDir = "C:\\Users\\normp\\Documents\\Programming\\Technopark\\Chess in FEN\\Images\\";
    QString imgName;
    QImage img;

    out << "Input picture name: " << endl;
    in >> imgName;
    img.load(imgDir + imgName);

    if (img.isNull()) {
        out << "Cannot open image" << endl;
        return 1;
    } else {
        out << "Image loaded successfully" << endl;
    }

    QImage scaledImg = img.scaled(160, 160);

    if (!imgParse(scaledImg)) {
        out << "Cannot parse image" << endl;
        return 1;
    } else {
        out << "Image parsed successfully" << endl;
    }

    return 0;
}
