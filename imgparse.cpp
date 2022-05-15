#include "imgparse.h"

#include <QRect>
#include <QString>
#include <QTextStream>
#include <QFile>

std::vector<std::vector<int>> imgParse(QImage img) {
    std::vector<std::vector<int>> pixels(64);
    QRect cell;
    QImage subImg;

    QTextStream in(stdin);
    QTextStream out(stdout);

    QString subImgDir;
    out << "Input parsed images dir: " << Qt::endl;
    subImgDir = in.readLine();

    QFile vectorFile(subImgDir + "\\vectorFile.txt");
    vectorFile.open(QIODevice::WriteOnly);

    QTextStream file(&vectorFile);
    //file.setAutoDetectUnicode(true);

    for (int i = 0; i < 8; i++) {
        for (int j = 0; j < 8; j++) {
            cell.setRect(j * 20, i * 20, 20, 20);
            subImg = img.copy(cell);
            subImg.save(subImgDir + "\\cell " + QString::number(i) + "_" + QString::number(j) + ".jpg");
            pixels[i * 8 + j] = imgToPixels(subImg);

            file << "cell " + QString::number(i) + "_" + QString::number(j) << Qt::endl;
            for (int k = 0; k < 20 * 20; k++) {
                file << pixels[i * 8 + j][k] << ", ";
                if ((k + 1) % 20 == 0) {
                    file << Qt::endl;
                }
            }
            file << Qt::endl << Qt::endl;
        }
    }
    return pixels;
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
