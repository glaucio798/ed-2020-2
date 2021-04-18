#include <iostream>

using namespace std;

typedef int dado;

class noh {
    friend class lista;
    private:
        dado valor;
        noh* proximo;
        noh* anterior;
    public:
        noh(dado d);
};

noh::noh(dado d) {
    valor = d;
    proximo = NULL;
    anterior = NULL;
    
}

class lista {
    private:
        noh* primeiro;
        noh* ultimo;
        int tamanho;
    public:
        lista();
        ~lista();
        bool listaVazia(){return primeiro == NULL;};
        void insere(dado valor);
        void removeRepetidos();
        dado remove(noh* aRemover);
        lista & operator=(const lista& L2);
        void imprime();
		void imprimeReverso();
};


lista::lista() {
    primeiro = NULL;
    ultimo = NULL;
    tamanho = 0;
}

lista::~lista( ) {
    noh* aux = primeiro;
    noh* temp;

    while (aux != NULL) {
        temp = aux;
        aux = aux->proximo;
        delete temp;
    }
    primeiro = NULL;
    ultimo = NULL;
    tamanho = 0;
}

void lista::insere(dado valor) {
    noh* novo = new noh(valor);
    if(listaVazia()){
		primeiro = novo;
	}else{
		ultimo->proximo = novo;
		novo->anterior = ultimo;
	}
	ultimo = novo;
	tamanho++;
}

dado lista::remove(noh* aRemover) {
	if(ultimo == aRemover)
		ultimo = aRemover->anterior;
	
	if(primeiro == aRemover)
		primeiro = aRemover->proximo;
		
	if(aRemover->anterior)aRemover->anterior->proximo = aRemover->proximo;
	if(aRemover->proximo)aRemover->proximo->anterior = aRemover->anterior;

	dado data = aRemover->valor;
	
	delete aRemover;
	
	tamanho--;
	return data;
}

lista & lista::operator=(const lista& L2){
	noh* aux;
	if(!listaVazia()){
		aux = primeiro;
		noh* temp;
		cout << aux->valor << endl;
		while (aux != NULL) {
			temp = aux;
			aux = aux->proximo;
			delete temp;
		}
		primeiro = NULL;
		ultimo = NULL;
	}
	
	aux = L2.primeiro;
	while (aux != NULL) {
		insere(aux->valor);
		aux = aux->proximo;
	}

    return *this;
}

void lista::removeRepetidos(){
	noh* aux;
	noh* teste = primeiro;
	while(teste != NULL){
		aux = teste->proximo;
		while(aux != NULL){
			if(aux->valor == teste->valor and teste != aux){
				noh* deletar = aux;
				aux = aux->proximo;
				remove(deletar);
			}else{
				aux = aux->proximo;
			}
		}
		teste = teste->proximo;
	}
}

void lista::imprime(){
	noh* aux = primeiro;
	while(aux != NULL){
		cout << aux->valor << " ";
		aux = aux->proximo;
	}
	cout << endl;
}

void lista::imprimeReverso(){
	noh* aux = ultimo;
	while(aux != NULL){
		cout << aux->valor << " ";
		aux = aux->anterior;
	}
	cout << endl;
}

int main() {
    lista* L1 = new lista();
	
	int aux, n;
	cin >> n;
	
	for(int i=0; i<n; i++){
		cin >> aux;
		L1->insere(aux);	
	}
	
    lista* L2 = new lista();
	*L2 = *L1;
	
	L1->removeRepetidos();
	
	L1->imprime();
	L1->imprimeReverso();
	
	delete L2;
	delete L1;
    return 0;
}
