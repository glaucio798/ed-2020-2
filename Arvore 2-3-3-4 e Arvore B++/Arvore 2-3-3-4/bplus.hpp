#include <iostream>
#include <string.h>
#include "pacote.hpp"
using namespace std;

class Bplus
{
private:
	pacote *raiz;
	pacote *dividePacote(pacote *bloco, dado &promovido);
	void insereEmIntermediarioNaoCheio(pacote *bloco, pacote *novo, dado promovido);
	void imprimeAux(pacote *bloco);
	pacote *insereRecAux(pacote *bloco, dado umDado, dado &promovido);

public:
	Bplus() : raiz(NULL) {}
	void imprimir();
	void inserirRecursivamente(dado umDado);
};

pacote *Bplus::dividePacote(pacote *bloco, dado &promovido)
{
	promovido = bloco->elementos[POS_MEIO];
	pacote *novo = new pacote(bloco->eFolha);
	novo->elementos[0] = bloco->elementos[POS_MEIO + 1];
	novo->numElementos = CAP_PACOTE / 2;
	bloco->numElementos = CAP_PACOTE / 2;
	cout << "novo" << novo->numElementos << " vei " << bloco->numElementos;

	if (!bloco->eFolha)
	{
		for (int i = 0; i < POS_MEIO + 1; i++)
			novo->filho[i] = bloco->filho[POS_MEIO + 1 + i];
	}

	return novo;
}

void Bplus::insereEmIntermediarioNaoCheio(pacote *bloco, pacote *novo, dado promovido)
{
	cout << "entao entra aqui";
	int pos = int(bloco->numElementos) - 1;

	while (pos >= 0 and strcmp(bloco->elementos[pos].chave, promovido.chave) > 0)
	{
		bloco->elementos[pos + 1] = bloco->elementos[pos];
		bloco->filho[pos + 2] = bloco->filho[pos + 1];
		pos--;
		cout << " while: " << pos << " ";
	}
	cout << " e acaba aqui" << endl;

	bloco->elementos[pos + 1] = promovido;
	bloco->filho[pos + 2] = novo;
	bloco->numElementos++;
}

void Bplus::inserirRecursivamente(dado umDado)
{
	if (raiz == NULL)
	{
		raiz = new pacote(true);
		raiz->elementos[0] = umDado;
		raiz->numElementos = 1;
	}
	else
	{
		dado promovido;
		pacote *novo = insereRecAux(raiz, umDado, promovido);

		if (novo)
		{
			pacote *antigaRaiz = raiz;
			raiz = new pacote(false);
			raiz->elementos[0] = promovido;
			raiz->numElementos = 1;
			raiz->filho[0] = antigaRaiz;
			raiz->filho[1] = novo;
		}
	}
}

pacote *Bplus::insereRecAux(pacote *bloco, dado umDado, dado &promovido)
{
	if (bloco->eFolha)
	{
		if (!bloco->cheio())
		{
			bloco->inserir(umDado);
			return NULL;
		}
		else
		{
			pacote *novo = dividePacote(bloco, promovido);
			cout << "aqui " << umDado.chave << " " << bloco->elementos[POS_MEIO].chave << endl;
			if (strcmp(umDado.chave, bloco->elementos[POS_MEIO].chave) <= 0)
			{
				cout << "aqui2" << endl;
				bloco->inserir(umDado);
				cout << "aqui3" << endl;
			}
			else
			{
				cout << "deve ser aqui entao ne porra" << novo->numElementos << endl;

				novo->inserir(umDado);
				cout << "deve ser aqui entao ne porra" << novo->numElementos << endl;
			}
			return novo;
		}
	}
	else
	{
		int i = bloco->numElementos - 1;
		while (i >= 0 and strcmp(bloco->elementos[i].chave, umDado.chave) > 0)
			i--;
		pacote *blocoAux = insereRecAux(bloco->filho[i + 1], umDado, promovido);

		if (blocoAux)
		{
			if (!bloco->cheio())
			{
				cout << "ta cheio?" << endl;
				insereEmIntermediarioNaoCheio(bloco, blocoAux, promovido);
				return NULL;
			}
			else
			{
				dado promovidoFilho = promovido;
				pacote *novo = dividePacote(bloco, promovido);

				if (strcmp(promovidoFilho.chave, bloco->elementos[POS_MEIO].chave) <= 0)
				{
					insereEmIntermediarioNaoCheio(bloco, blocoAux, promovidoFilho);
				}
				else
				{
					insereEmIntermediarioNaoCheio(novo, blocoAux, promovidoFilho);
				}
				return novo;
			}
		}
		return NULL;
	}
}

void Bplus::imprimir()
{
	imprimeAux(raiz);
	cout << endl;
}

void Bplus::imprimeAux(pacote *bloco)
{
	bloco->imprimir();
	if (!bloco->eFolha)
		for (int i = 0; i <= bloco->numElementos; i++)
			imprimeAux(bloco->filho[i]);
	else
		cout << " foia ";
}