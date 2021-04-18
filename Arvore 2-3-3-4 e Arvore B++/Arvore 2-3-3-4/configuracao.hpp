using namespace std;
#include <iostream>

struct elemento
{
    char chave[50];
    char valor[10];
};

typedef elemento dado;

// capacidade máxima e mínima do pacote
const unsigned CAP_PACOTE = 3;
const unsigned MIN_PACOTE = 1;

// posição do elemento do meio do pacote
const unsigned POS_MEIO = 1;

// posição inválida no disco
const int POS_INVALIDA = -1;
