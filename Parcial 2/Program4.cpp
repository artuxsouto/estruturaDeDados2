//Mapa associativo com Espelhamento - alocação Dinânmica
#include <iostream>
#include <stdlib.h>

using namespace std;

struct dadosPessoa{
	int rg;
	int chave;
	float salario;
};

struct mapaHash{
	int tamanho;
	int contador;
	dadosPessoa** listaEmployee;
};

mapaHash* criarMapaHash(int tamanho){
	int i;
	mapaHash *mapa = (mapaHash*)malloc(sizeof(mapaHash));
	mapa->listaEmployee = (dadosPessoa**)malloc(tamanho * sizeof(dadosPessoa));
	
	mapa->contador = 0;
	mapa->tamanho = tamanho;
	
	for (i = 0; i < tamanho; i++){
		mapa->listaEmployee[i] = (dadosPessoa*)malloc(sizeof(dadosPessoa));
		mapa->listaEmployee[i] = NULL;
	}
	return mapa;
}

unsigned int FuncaoHash(mapaHash *mapa, unsigned int chave){
	unsigned int indiceHash = chave;
	indiceHash = (indiceHash >> 3) * 2654435761;
	indiceHash = indiceHash % mapa->tamanho;
	
	return indiceHash;
}
void inserir(mapaHash *mapa, unsigned int chave, int valor, float valor1){
	unsigned int indice = FuncaoHash(mapa, chave);
	dadosPessoa *no = mapa->listaEmployee[indice];
	
	if (no == NULL){
		no = (dadosPessoa*)malloc(sizeof(dadosPessoa));
		mapa->listaEmployee[indice] = no;
		mapa->contador++;
	}else{
		cout << "\nColisao! chave existente sera substituida" << endl;
		
		mapa->listaEmployee[indice]->chave = chave;
		mapa->listaEmployee[indice]->rg = valor;
		mapa->listaEmployee[indice]->salario = valor1;
	}
	return;
}

void imprimirMapa(mapaHash *mapa){
	for (int i = 0; i < mapa->tamanho; i++){
		if (mapa->listaEmployee[i] != NULL){
			cout << "\nChave: " << mapa->listaEmployee[i]->chave << "\nRG: " << mapa->listaEmployee[i]->rg << "\nSalario: " << mapa->listaEmployee[i]->salario << endl;
		}else{
			cout << "\n[" << i << "] Valor: NULL" << endl;
		}
	}
}

int main(){
	
	int tamanho = 10;
	mapaHash *mapa = NULL;
	
	mapa = criarMapaHash(tamanho);
	
	int controle, rg;
	float salario;
	int chave = 0;
	
	
	while (controle != -1){
		cout << "\n***MENU***\n1 - Cadastrar novo funcionario.\n2 - Imprimir todos funcionarios.\n0 - Sair.\n\nDigite a opcao: ";
		cin >> controle;
		
		if (controle == 1){
			cout << "\nDigite o cpf: ";
			cin >> chave;
			
			cout << "\nDigite o RG: ";
			cin >> rg;
			
			cout << "\nDigite o salario: ";
			cin >> salario;
			
			inserir(mapa, chave, rg, salario);

		}else if (controle == 2){
			cout << "\n***IMPRIMIR FUNCIONARIOS***" << endl;
			imprimirMapa(mapa);			
		}else{
			cout << "\n***FIM***\nFuncionarios cadastrados: " << mapa->contador << endl;
			controle = -1;
		}
	}
	cout << "\nObrigado! Volte sempre." << endl;
	
	return 0;
}
