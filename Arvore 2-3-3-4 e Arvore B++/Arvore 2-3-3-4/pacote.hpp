#include <iostream>
#include <string.h>
#include "configuracao.hpp"
using namespace std;

// essa classe também poderia se chamar bloco, pagina, packet ou pedaco
class pacote
{
    friend class sequenceset;
    friend class Bplus;
    // classe não possui métodos públicos
    // objetos da classe são criados e manuseados
    // apenas pela classe sequenceset
private:
    bool eFolha;
    dado elementos[CAP_PACOTE];
    unsigned numElementos;
    pacote *pai;
    pacote *filho[CAP_PACOTE + 1];
    pacote *posProximoPacote;
    pacote(bool folha) : pai(NULL), numElementos(0), posProximoPacote(NULL), eFolha(folha) {}
    bool cheio() { return (numElementos == CAP_PACOTE); }
    void inserir(dado umDado);
    inline bool chaveEhMaiorQueTodos(char *chave);
    inline bool chaveEhMenorQueTodos(char *chave);
    void imprimir();
};

void pacote::inserir(dado umDado)
{
    int posicao = numElementos - 1;
    // Faz a procura pela posição de inserção do elemento de forma decrescente
    while ((posicao >= 0) and strcmp(umDado.chave, elementos[posicao].chave) < 0)
    {
        elementos[posicao + 1] = elementos[posicao];
        posicao--;
    }
    elementos[posicao + 1] = umDado;
    numElementos++;
}

void pacote::imprimir()
{
    cout << "[";
    for (unsigned i = 0; i < numElementos; i++)
        cout << "(" << elementos[i].chave << "/" << elementos[i].valor << ")";
    cout << "]";
}

bool pacote::chaveEhMaiorQueTodos(char *chave)
{
    return (elementos[numElementos - 1].chave < chave);
}

bool pacote::chaveEhMenorQueTodos(char *chave)
{
    return (elementos[0].chave > chave);
}
