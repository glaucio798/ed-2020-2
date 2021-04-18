#include <iostream>

using namespace std;

typedef string dado;

class noh {
    friend class lista;
    friend class tabelaHash;
    private:
        dado valor, chave;
        noh* proximo;
        noh* anterior;
    public:
        noh(dado val, dado cv);
};

noh::noh(dado val, dado cv) {
    valor = val;
    chave = cv;
    proximo = NULL;
    anterior = NULL;
    
}

class lista {
	friend class tabelaHash;
    private:
        noh* primeiro;
        noh* ultimo;
        int tamanho;
    public:
        lista();
        ~lista();
        bool listaVazia(){return primeiro == NULL;};
        void insere(dado valor, dado chave);
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

void lista::insere(dado valor, dado chave) {
    noh* novo = new noh(valor, chave);
    if(listaVazia()){
		primeiro = novo;
	}else{
		ultimo->proximo = novo;
		novo->anterior = ultimo;
	}
	ultimo = novo;
	tamanho++;
}

class tabelaHash{
	friend class lista;
	friend class noh;
	private:
		int capacidade;
		lista* tabela;
		int funcaoHash(dado chave);
	public:
		tabelaHash(int cap);
		~tabelaHash();
		void insere(dado val, dado chave);
		string busca(dado chave);
};

tabelaHash::tabelaHash(int cap){
	capacidade = cap;
	tabela = new lista[capacidade];
}

tabelaHash::~tabelaHash(){
	for(int i=0; i<capacidade; i++){
		delete &tabela[i];
	}
	delete [] tabela;
}

int tabelaHash::funcaoHash(dado chave){
	return chave.length() % capacidade;
}

void tabelaHash::insere(dado val, dado chave){
	int pos = funcaoHash(chave);
	tabela[pos].insere(val, chave);
}

string tabelaHash::busca(dado chave){
	int pos = funcaoHash(chave);
	if(tabela[pos].listaVazia())
		return "NULL";
	
	noh* aux = tabela[pos].primeiro;
	while(aux != NULL && aux->chave != chave )
		aux = aux->proximo;
	
	if(aux != NULL)
		return aux->valor;
	else
		return "NULL";
}

int main() {
    tabelaHash* hash = new tabelaHash(23);
    dado val, chave;
    int n;
    cin >> n;
    
    for(int i=0; i<n; i++){
		cin >> chave;
		getline(cin, val);
	hash->insere(val, chave);
	}
	
	dado busca;
	
	cin >> busca;
	
	while(busca != "-1"){
		cout << "[" << busca << "] => " << hash->busca(busca) << endl;
		cin >> busca;
	}
	
	delete hash;
    return 0;
}
