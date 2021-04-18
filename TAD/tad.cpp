#include <iostream>
using namespace std;

struct obra{
	string nome;
	float valor;
};

struct artista {
	string nome, telefone, endereco;
};

struct entusiasta {
	string nome, email;
	obra ultima_comprada;
};

class exposicao {
	private:
		artista *artistas;
		entusiasta *entusiastas;
		int posArtista, posEntusiasta, capacidadeArtista, capacidadeEntusiasta;
		
	public:
		exposicao();
		exposicao(int qntArtistas, int qntEntusiastas);
		~exposicao();
		bool cadastraArtista(string nome, string telefone, string endereco);
		bool cadastraEntusiasta(string nome, string email, string name_obra, float valor_obra);
		bool recuperaArtista(string nome);
		void imprimirTudo();
};

exposicao::exposicao(){
	artistas = new artista[100];
	entusiastas = new entusiasta[100];
	posArtista = 0;
	posEntusiasta = 0;
	capacidadeArtista = 100;
	capacidadeEntusiasta = 100;
}

exposicao::exposicao(int qntArtistas, int qntEntusiastas){
	artistas = new artista[qntArtistas];
	entusiastas = new entusiasta[qntEntusiastas];
	posArtista = 0;
	posEntusiasta = 0;
	capacidadeArtista = qntArtistas;
	capacidadeEntusiasta = qntEntusiastas;
}


exposicao::~exposicao(){
	delete [] artistas;
	delete [] entusiastas;
	posArtista = 0;
	posEntusiasta = 0;
	capacidadeArtista = 0;
	capacidadeEntusiasta = 0;
	cout << "EXPOSICAO DELETADA";
}

bool exposicao::cadastraArtista(string nome, string telefone, string endereco){
	if(posArtista> capacidadeArtista-1)
		return false;
	
	artistas[posArtista].nome = nome;	
	artistas[posArtista].telefone = telefone;
	artistas[posArtista].endereco = endereco;
	
	posArtista++;
	
	return true;
}

bool exposicao::cadastraEntusiasta(string nome, string email, string name_obra, float valor_obra){
	if(posEntusiasta> capacidadeEntusiasta-1)
		return false;
	
	entusiastas[posEntusiasta].nome = nome;	
	entusiastas[posEntusiasta].email = email;
	entusiastas[posEntusiasta].ultima_comprada.nome = name_obra;
	entusiastas[posEntusiasta].ultima_comprada.valor = valor_obra;
	
	posEntusiasta++;
	
	return true;
}

bool exposicao::recuperaArtista(string procurado){
	for(int i=0; i<posArtista; i++){
		if(artistas[i].nome == procurado){
			cout << artistas[i].nome << endl 
			<< artistas[i].endereco << endl 
			<< artistas[i].telefone << endl;
			
			return true;
		}	
	}
	return false;
}

void exposicao::imprimirTudo(){
	cout << "ARTISTAS" << endl;
	for(int i=0; i<posArtista; i++){
		cout << artistas[i].nome << endl 
			<< artistas[i].endereco << endl 
			<< artistas[i].telefone << endl << endl;
	}
	
	cout << "ENTUSIASTAS" << endl;
	for(int i=0; i<posEntusiasta; i++){
		cout << entusiastas[i].nome << endl 
			<< entusiastas[i].email << endl 
			<< entusiastas[i].ultima_comprada.nome << endl
			<< entusiastas[i].ultima_comprada.valor << endl << endl;
	}
}

int main(){
	int escolha;
	string nomeArtista, enderecoArtista, telefoneArtista, nomeEntusiasta, emailEntusiasta, nomeObra;
	float valorObra;
	
	int qntArtista, qntEntusiastas;
	
	cout << "Digite a quantidade de artistas: ";
	cin >> qntArtista;
	cout << "Digite a quantidade de entusiastas: ";
	cin >> qntEntusiastas;
	
	exposicao *expoLavras = new exposicao(qntArtista, qntEntusiastas);
	
	do{
		cout << endl
			 << "1 Cadastrar artista" << endl
			 << "2 Cadastrar entusiasta" << endl
			 << "3 busca artista" << endl
			 << "4 imprime todos" << endl
			 << "9 sair" << endl;
			 
		cin >> escolha;
		
		switch(escolha){
			case 1:
				cout << "Digite nome, endereço e telefone do artista separados por enter" << endl;
				cin >> nomeArtista >> enderecoArtista >> telefoneArtista;
				if(expoLavras->cadastraArtista(nomeArtista, telefoneArtista, enderecoArtista))
					cout << "Artista cadastrado com sucesso" << endl;
				else
					cout << "Erro a cadastrar artista" << endl;
				break;	
			
			case 2:
				cout << "Digite nome, email e nome da obra e valor da obra do entusiasta separados por enter" << endl;
				cin >> nomeEntusiasta >> emailEntusiasta >> nomeObra >> valorObra;
				if(expoLavras->cadastraEntusiasta(nomeEntusiasta, emailEntusiasta, nomeObra, valorObra))
					cout << "Entusiasta cadastrado com sucesso" << endl;
				else
					cout << "Erro a cadastrar entusiasta" << endl;
				break;
			case 3:
				cout << "Digite o nome do artista que quer procurar" << endl;
				cin >> nomeArtista;
				if(!expoLavras->recuperaArtista(nomeArtista))
					cout << "Artista nao encontrado" << endl;
				break;
			case 4:
				expoLavras->imprimirTudo();
		}
		
	}while(escolha!=9);
	
	delete expoLavras;

}

