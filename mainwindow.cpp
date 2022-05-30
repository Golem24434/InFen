#include <QMessageBox>
#include <QFileDialog>
#include <QImage>
#include <QCoreApplication>
#include <QTextStream>
#include <QImage>
#include <QString>
#include <QList>
#include <vector>
#include <iostream>
#include <QObject>
#include <QClipboard>
#include <QDesktopServices>
#include <QUrl>
#include <QStackedWidget>

#include "imgparse.h"
#include "defenition.h"
#include "fen_maker.h"
#include "mainwindow.h"
#include "./ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->main->setAlignment(Qt::AlignCenter);
    ui->label->setAlignment(Qt::AlignCenter);
    ui->label_3->setAlignment(Qt::AlignCenter);
    ui->label_2->setAlignment(Qt::AlignCenter);
    ui->lineEdit->setAlignment(Qt::AlignCenter);
    ui->label_4->setAlignment(Qt::AlignCenter);
    ui->label_5->setAlignment(Qt::AlignCenter);
    ui->label_5->hide();
    ui->pushButton_4->hide();
    ui->pushButton_5->hide();
    ui->pushButton_6->hide();
    ui->pushButton_7->hide();
    ui->lineEdit->hide();
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_pushButton_clicked()
{
    // Определить класс диалогового окна файла
       QFileDialog *fileDialog = new QFileDialog(this);
            // определить заголовок файла
       fileDialog-> setWindowTitle (tr ("Open file"));
            // Установить путь к файлу по умолчанию
       fileDialog->setDirectory(".");
            // Установить фильтр файлов
       fileDialog->setNameFilter(tr("Images(*.png *.jpg *.jpeg *.bmp)"));
            // Настройка позволяет выбрать несколько файлов, по умолчанию используется только один файл QFileDialog :: ExistingFiles
       fileDialog->setFileMode(QFileDialog::ExistingFiles);
            // Установить режим просмотра
       fileDialog->setViewMode(QFileDialog::Detail);
            // выводим путь ко всем выбранным файлам
       QPixmap pixmap = QFileDialog::getOpenFileName(fileDialog);
       ui->label_3->setPixmap(pixmap.scaled(300,300,Qt::IgnoreAspectRatio,Qt::FastTransformation));
       image = pixmap.toImage();
        ui->label_4->setText("");
        ui->lineEdit->setText("");
}


void MainWindow::on_pushButton_2_clicked()
{
    QPixmap *clearpix = new QPixmap();
    ui->label_3->setPixmap(*clearpix);
    ui->lineEdit->setText("");
    ui->label_4->setText("");
    ui->pushButton_4->hide();
    ui->label_5->hide();
    ui->lineEdit->hide();
    ui->pushButton_5->hide();
    ui->pushButton_6->hide();
    ui->pushButton_7->hide();
}


void MainWindow::on_pushButton_3_clicked()
{
        QImage img(image);
        if (img.isNull()) {
            std::cout << "Cannot open image" << Qt::endl;
            return;
        }

        img = normalizeImage(img);
        if (img.isNull()) {
            std::cout << "Cannot normalize image" << Qt::endl;
            return;
        }

        QList<QImage> cells = imgParse(img);
        if (cells.isEmpty()) {
            std::cout << "Cannot parse image" << Qt::endl;
            return;
        }

        std::vector<std::vector<int>> objects = imgsToObjects(cells);

        std::vector<char> fenPreCode = definition_of_diagrams(objects);

        FEN = FEN_maker(fenPreCode);

        std::cout << std::endl;
        std::cout << "FEN code: " << FEN << std::endl;
        ui->lineEdit->setText(QString::fromStdString(FEN));
        ui->label_4->setText("(; Your FEN code is here ↓");
        ui->pushButton_4->show();
        ui->pushButton_5->show();
        ui->pushButton_6->show();
        ui->pushButton_7->show();
        ui->label_5->show();
        ui->lineEdit->show();
}


void MainWindow::on_pushButton_4_clicked()
{
    QApplication::clipboard()->setText(QString::fromStdString(FEN));
}


void MainWindow::on_pushButton_7_clicked()
{
    QApplication::clipboard()->setText(QString::fromStdString(FEN));
    QDesktopServices::openUrl(QUrl("https://www.dailychess.com/chess/chess-fen-viewer.php"));
}


void MainWindow::on_pushButton_6_clicked()
{
    QApplication::clipboard()->setText(QString::fromStdString(FEN));
    QDesktopServices::openUrl(QUrl("https://www.chess.com"));
}


void MainWindow::on_pushButton_5_clicked()
{
    QApplication::clipboard()->setText(QString::fromStdString(FEN));
    QDesktopServices::openUrl(QUrl("https://www.lichess.org"));
}

