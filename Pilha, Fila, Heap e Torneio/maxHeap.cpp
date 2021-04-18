#include <iostream>
#include <algorithm>

using namespace std;

typedef int dado;

class MaxHeap{
	private:
		dado* heap;
		int capacidade, tam;
		inline int pai(int i);
		inline int esq(int i);
		inline int dir(int i);
		void MaxHeapify();
		void corrigeDescendo(int i);
		void corrigeSubindo(int i);
		void imprimeVet();
	public:
		MaxHeap(dado vet[], int tamanho);
		~MaxHeap();	
};

MaxHeap::MaxHeap(dado vet[], int tamanho){
	capacidade = tamanho;
	
	heap = new dado[capacidade];
	
	copy(vet, vet + tamanho, heap);
	
	tam = tamanho;
	
	MaxHeapify();
}

MaxHeap::~MaxHeap(){
	delete [] heap;
	capacidade = 0;
	tam = 0;
}

inline int MaxHeap::pai(int i){
	return (i-1)/2;
}

inline int MaxHeap::esq(int i){
	return 2*i + 1;
}

inline int MaxHeap::dir(int i){
	return 2*i + 2;
}

void MaxHeap::MaxHeapify(){
	for(int i= tam/2 - 1; i>=0; i--){
		corrigeDescendo(i);
		cout << tam/2 -1 - i << ": ";
		imprimeVet();
	}
}

void MaxHeap::corrigeDescendo(int i){
	int esquerda = esq(i), direita = dir(i), maior = i;
	
	if(esquerda < tam and heap[esquerda]>heap[i])
		maior = esquerda;
	
	if(direita < tam and heap[direita]>heap[maior])
		maior = direita;
	
	if(maior != i){
		int aux = heap[i];
		heap[i] = heap[maior];
		heap[maior] = aux;
		corrigeDescendo(maior);
	}	
}

void MaxHeap::imprimeVet(){
	for(int i=0; i<tam; i++)
		cout << heap[i] << " ";
	cout << endl;
}

int main(){
	int tam;
	cin >> tam;
	dado vet[tam];
	
	for(int i=0; i<tam; i++)
		cin >> vet[i];
		
	MaxHeap *m = new MaxHeap(vet, tam);
	
	delete m;
}
