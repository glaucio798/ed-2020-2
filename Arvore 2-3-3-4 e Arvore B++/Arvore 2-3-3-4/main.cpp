#include <iostream>
#include "bplus.hpp"

using namespace std;

int main()
{
    Bplus arvere;
    dado umDado;
    char umaChave[50];
    char operacao;

    do
    {
        try
        {
            cin >> operacao;
            switch (operacao)
            {
            case 'i': // inserir
                cin >> umDado.chave >> umDado.valor;
                arvere.inserirRecursivamente(umDado);
                break;
            // case 'b': // buscar
            //     cin >> umaChave;
            //     umDado = arvere.buscar(umaChave);
            //     cout << "Busca: "<< umDado.chave << "/" << umDado.valor << endl;
            //     break;
            case 'p': // mostrar estrutura
                arvere.imprimir();
                break;
            // case 'd': // mostrar estrutura
            //     arvere.depurar();
            //     break;
            case 's': // sair
                // será tratado no while
                break;
            default:
                cout << "Opção inválida!" << endl;
            }
        }
        catch (runtime_error &e)
        {
            cerr << e.what() << endl;
        }
    } while (operacao != 's');

    return 0;
}
