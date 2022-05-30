#ifndef IMGPARSE_H
#define IMGPARSE_H

#include <QImage>
#include <QColor>
#include <QList>
#include <vector>

QList<QImage> imgParse(QImage img);
QImage normalizeImage(QImage img);
std::vector<int> imgToPixels(QImage img);
std::vector<std::vector<int>> imgsToObjects(QList<QImage> img);

#endif // IMGPARSE_H
