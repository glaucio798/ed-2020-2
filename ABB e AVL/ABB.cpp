#include <iostream>

using namespace std;

typedef int dado;

class noh {
    friend class ABB;
    private:
        dado valor;
        noh* esquerdo;
        noh* direito;
        noh* pai;
    public:
        noh(dado d);
};

noh::noh(dado d){
	valor = d;
	esquerdo = NULL;
	direito = NULL;
	pai = NULL;
}

class ABB {
	private:
		noh* raiz;
		noh* inserirRecAux(noh* umNoh, dado valor);
		int contaNohAux(noh* umNoh);
		void destruirNohRecursivamente(noh* umNoh);
	public:
		ABB();
		~ABB();
        void inserirRec(dado d);
        int contaNoh();
};

ABB::ABB(){
	raiz = NULL;
}

ABB::~ABB(){
	destruirNohRecursivamente(raiz);
}

void ABB::destruirNohRecursivamente(noh* umNoh){
	if(umNoh != NULL){
		destruirNohRecursivamente(umNoh->esquerdo);
		destruirNohRecursivamente(umNoh->direito);
		delete umNoh;
	}
}

void ABB::inserirRec(dado d){
	raiz = inserirRecAux(raiz, d);
}

noh* ABB::inserirRecAux(noh* umNoh, dado valor){
	if(umNoh == NULL)
		
		return new noh(valor);
	else {
		if(valor < umNoh->valor){
			umNoh->esquerdo = inserirRecAux(umNoh->esquerdo, valor);
			umNoh->esquerdo->pai = umNoh;
		}else{
			umNoh->direito = inserirRecAux(umNoh->direito, valor);
			umNoh->direito->pai = umNoh;
		}
	}
	
	return umNoh;
}

int ABB::contaNoh(){
	if(raiz != NULL){
		int esq, dir;
		esq = contaNohAux(raiz->esquerdo);
		dir = contaNohAux(raiz->direito);
		cout << esq + dir + 1 << " " << esq - dir;
		return esq+dir+1;
	}else{
		cout << 0 << " " << 0;
		return 0;
	}
}

int ABB::contaNohAux(noh* umNoh){
	if(umNoh == NULL)
		return 0;
	
	int esq = 0, dir = 0;
	 
	esq = contaNohAux(umNoh->esquerdo);
	dir = contaNohAux(umNoh->direito);
	
	 return esq + dir + 1;
}

int main(){
	
	ABB* arvore = new ABB();
	
	dado aux;
	
	cin >> aux;
	
	while(aux != -1){
		arvore->inserirRec(aux);
		cin >> aux;
	}
	
	arvore->contaNoh();
	
	delete arvore;
	
	return 0;
}

