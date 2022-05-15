#ifndef IMGPARSE_H
#define IMGPARSE_H

#include <QImage>
#include <QColor>
#include <vector>

std::vector<std::vector<int>> imgParse(QImage img);
QImage normalizeImage(QImage img);
std::vector<int> imgToPixels(QImage img);

#endif // IMGPARSE_H
