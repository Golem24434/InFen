#include "imgparse.h"

#include <QRect>
#include <QString>

bool imgParse(QImage img) {
    if (img.width() != 160 && img.height() != 160) {
        return false;
    }
    QRect cell;
    QImage subImg;
    QString subImgDir = "C:\\Users\\normp\\Documents\\Programming\\Technopark\\Chess in FEN\\Images\\cells\\";
    for (int i = 0; i < 8; i++) {
        for (int j = 0; j < 8; j++) {
            cell.setRect(j * 20, i * 20, 20, 20);
            subImg = img.copy(cell);
            if (!subImg.save(subImgDir + "cell " + QString::number(i) + "_" + QString::number(j) + ".jpg")) {
                return false;
            }
        }
    }
    return true;
}
