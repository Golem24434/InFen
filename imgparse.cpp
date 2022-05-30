#include "imgparse.h"

#include <QRect>
#include <QString>

QList<QImage> imgParse(QImage img) {
    QList<QImage> images;
    QRect cell;
    QImage subImg;
    //const QString subImgDir = "C:\\Users\\normp\\Documents\\Programming\\Technopark\\Chess in FEN\\Images\\cells\\";
    for (int i = 0; i < 8; i++) {
        for (int j = 0; j < 8; j++) {
            cell.setRect(j * 20, i * 20, 20, 20);
            subImg = img.copy(cell);
            //subImg.save(subImgDir + "cell " + QString::number(i) + "_" + QString::number(j) + ".jpg");
            images.append(subImg);
        }
    }
    return images;
}

QImage normalizeImage(QImage img) {
    img = img.convertToFormat(QImage::Format_Grayscale8);
    img = img.scaled(160, 160);
    return img;
}

std::vector<int> imgToPixels(QImage img) {
    std::vector<int> pixels(img.height() * img.width());
    for (int i = 0; i < img.height(); i++) {
        for (int j = 0; j < img.width(); j++) {
            QColor color = img.pixelColor(i, j);
            pixels[i * img.width() + j] = color.green();
        }
    }
    return pixels;
}

std::vector<std::vector<int>> imgsToObjects(QList<QImage> imgs) {
    std::vector<std::vector<int>> objects;
    foreach(QImage i, imgs) {
        objects.push_back(imgToPixels(i));
    }
    return objects;
}
