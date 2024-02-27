#ifndef LISTA_H
#define LISTA_H

#include <no.h>
#include <piloto.h>

namespace hpm
{
    class lista
    {
    private:
        No *inicio;
        int quantidadeElementos;

    public:
        lista();

        int getQuantidadeElementos()const {return quantidadeElementos;}
        bool estaVazia()const {return quantidadeElementos==0;} //ou inicio==0

        void inserirInicio(piloto dado);
        void inserirFinal(piloto dado);
        void inserirPosicao(piloto dado,int posicao);

        piloto acessarInicio()const;
        piloto acessarFinal()const;
        piloto acessarPosicao(int posicao)const;

        void retirarInicio();
        void retirarFinal();
        void retirarPosicao(int posicao);

        void OrdenadoCrescente(piloto dados);
        void OrdenadoDescrescente(piloto dados);

        QString toString()const;
    };
}

#endif // LISTA_H
