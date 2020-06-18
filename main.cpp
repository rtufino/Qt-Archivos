#include <QCoreApplication>
#include <QFile>
#include <QDebug>

void leerBytes(QString);
void leerTexto(QString);
void escribirTexto(QString);

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    QString cancion = "apuesta.txt";

    qDebug() << "Leer archivo con QFile:";
    leerBytes(cancion);

    qDebug() << "\nLeer archivo de texto con QTextStream:";
    leerTexto(cancion);

    qDebug() << "\nEscribir archivo de texto con QTextStream:";
    escribirTexto("frase.txt");

    return 0;
}

void escribirTexto(QString archivo){

    QFile data(archivo);
    QString frase = "Ni patria ni bandera, ni raza ni condición.\n";
    frase += "Ni límites ni fronteras, extranjero soy.";

    if (data.open(QFile::WriteOnly | QFile::Truncate)) {
        QTextStream salida(&data);
        salida << frase;
        qDebug() << "Archivo almacenado en:" << archivo;
    }
}

void leerTexto(QString archivo){
    QFile file(archivo);

    if (!file.open(QIODevice::ReadOnly | QIODevice::Text))
        return;

    QTextStream in(&file);
    while (!in.atEnd()) {
        QString linea = in.readLine();
        qDebug() << linea;
    }

    file.close();
}

void leerBytes(QString archivo){

    QFile f(archivo);

    if (f.open(QIODevice::ReadOnly)){
        while (!f.atEnd()){
            QByteArray data = f.read(1024);
            qDebug() << data;
        }
        f.close();
    }else
    {
        qFatal("No se puede abrir el fichero para lectura");

    }
}
