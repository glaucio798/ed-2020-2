#include <iostream>

using namespace std;

class noh
{
	friend class pilha;

private:
	int dado; // poderia ser outro tipo de variÃ¡vel
	noh *prox;
};

// pilha dinamicamente encadeada
class pilha
{
private:
	noh *topo;
	int tamanho;

public:
	pilha();
	~pilha();
	void push(int d) { empilha(d); }
	void empilha(int d);
	int pop() { return desempilha(); }
	int desempilha(); // retorna o topo da pilha
	int espia();	  // espia o topo da pilha
	bool vazia();
};

/* implementar os métodos da pilha */

pilha::pilha()
{
	topo = NULL;
}

pilha::~pilha()
{
	while (topo != NULL)
		this->pop();
};

void pilha::empilha(int novoVal)
{
	noh *aux = new noh;
	aux->prox = topo;
	aux->dado = novoVal;
	topo = aux;
	tamanho++;
}

int pilha::desempilha()
{
	noh *aux = topo;
	topo = topo->prox;
	int retirado = aux->dado;
	delete aux;
	tamanho--;
	return retirado;
}

int pilha::espia()
{
	return topo->dado;
}

bool pilha::vazia()
{
	return topo == NULL;
}

//  Implementar aqui
int acessaElemento(pilha &p1, int elemento)
{
	int pos = 1;
	pilha aux;
	while (!p1.vazia() && p1.espia() != elemento)
	{
		aux.push(p1.pop());
		pos++;
	}

	if (p1.vazia())
		pos = -1;
	else
	{
		p1.pop();
	}

	while (!aux.vazia())
		p1.push(aux.pop());

	return pos;
}

int main()
{
	pilha p1;
	int n, numero, elemento;
	cin >> n;

	while (n > 0)
	{
		cin >> numero;
		p1.empilha(numero);
		n--;
	}

	cin >> elemento;
	cout << acessaElemento(p1, elemento) << endl;

	while (not p1.vazia())
	{
		cout << p1.desempilha() << " ";
	}

	cout << endl;

	return 0;
}
