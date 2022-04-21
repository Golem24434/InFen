#include <QCoreApplication>
#include <QTextStream>

int main(int argc, char *argv[])
{
    QCoreApplication app(argc, argv);

    QTextStream in(stdin);
    QTextStream out(stdout);

    int a;
    in >> a;
    out << "Your penis is " << a << Qt::endl;

    return app.exec();
}
