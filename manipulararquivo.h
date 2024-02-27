#ifndef MANIPULARARQUIVO_H
#define MANIPULARARQUIVO_H
#include <QString>
#include <QStringList>
#include <fstream>
#include <piloto.h>
#include <lista.h>

namespace hpm
{
    class manipulararquivo
    {
    private:
        QString nomeDoArquivo;
        hpm::lista colecaoPilotos;
    public:
        manipulararquivo(QString nomeDoArquivo);

        void buscarDados();
        const hpm::lista &getColecaoPilotos() const;
    };
}
#endif // MANIPULARARQUIVO_H
