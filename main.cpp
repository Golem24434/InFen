#include <QCoreApplication>
#include <QTextStream>
#include <QImage>
#include <QString>
#include <QList>
#include <vector>

#include "imgparse.h"

using namespace Qt;

int main() {

<<<<<<< HEAD
=======
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

    QImage normedImg = normalizeImage(img);

    QList<QImage> images = imgParse(normedImg);

    std::vector<std::vector<int>> objects = imgsToObjects(images);

    if (objects.empty()) {
        out << "Cannot parse image" << endl;
        return 1;
    } else {
        out << "Image parsed successfully" << endl;
    }

    return 0;
>>>>>>> imgparser
}
