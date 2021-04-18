#include <iostream>
#include <string>

using namespace std;

class Noh {
	friend class Fila;
	private:
		int dado; 
		Noh *proximo;
	public:
		Noh(int info){
			dado = info;
			proximo = NULL;
		}
		~Noh(){
			proximo = NULL;
			delete proximo;
		}
};

// fila dinamicamente encadeada
class Fila {
private:
	Noh* inicio;
	Noh* fim;
	int tamanho;

public:
	Fila();
	~Fila();
	void enfileira(int info);
	int desenfileira();
	int espiar();
	bool estaVazia(); // verifica se existem elementos na fila     
};


Fila::Fila() {
	inicio = NULL;
	fim = NULL;
	tamanho = 0;
}

Fila::~Fila() {
	while(!estaVazia())
		desenfileira();
}


void Fila::enfileira(int info) {
	Noh *aux = new Noh(info);
	
	if(estaVazia())
		inicio = aux;
	else
		fim->proximo = aux;
	fim = aux;
	tamanho++;    
}

int Fila::desenfileira() {
	Noh* aux = inicio;
	int dado = aux->dado;
	inicio = aux->proximo;
	
	delete aux;
	tamanho--;
	
	if(estaVazia())
		fim = NULL;
	
	return dado;

}

int Fila::espiar(){
	return inicio->dado;
}

bool Fila::estaVazia() {
	return inicio == NULL;
}

void concatenaEOrdenaFilas(Fila& monte1, Fila& monte2){
	Fila aux;
	int elEnfileirar;
	while(!monte1.estaVazia() || !monte2.estaVazia()){				
		if(!monte1.estaVazia()){
			if(!monte2.estaVazia()){
				if(monte2.espiar() < monte1.espiar())
					elEnfileirar = monte2.desenfileira();
				else
					elEnfileirar = monte1.desenfileira();
				
									
			}else{
				elEnfileirar = monte1.desenfileira();
			}
		}else
			elEnfileirar = monte2.desenfileira();
		
		
		while(!monte2.estaVazia() && monte2.espiar() == elEnfileirar)
				monte2.desenfileira();
		
		while(!monte1.estaVazia() && monte1.espiar() == elEnfileirar)
				monte1.desenfileira();
		
		aux.enfileira(elEnfileirar);
	}
	
	while (!aux.estaVazia()) 
		cout << aux.desenfileira() << " ";
}

int main() {
	Fila monte1, monte2;
	int tam1, tam2, aux;
	
	cin >> tam1;
	for(int i=0; i<tam1; i++){
		cin >> aux;
		monte1.enfileira(aux);
	}
	
	cin >> tam2;
	for(int i=0; i<tam2; i++){
		cin >> aux;
		monte2.enfileira(aux);
	}
	
	concatenaEOrdenaFilas(monte1, monte2);
	
	return 0;
}
