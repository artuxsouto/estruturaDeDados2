#include <stdlib.h>
#include <iostream>

using namespace std;

int funcaoHash(int chave, int tamanhoTabela){

	int indice = chave % tamanhoTabela;
	return indice;	
}

int inserirTabelaHash(int tabelaHash[], int chave, int tamanhoTabela){
	
	int indice = funcaoHash(chave, tamanhoTabela);
	
	while (tabelaHash[indice] != -1){
		if (indice == tamanhoTabela){
			indice = -2;
			break;
		}
		if (tabelaHash[indice] == chave){
			indice = -1;
			break;
		}
		indice ++;
	}
	
	if (indice >= 0){
		tabelaHash[indice] = chave;
	}
	return indice;
}

void imprimirTabelaHash(int tabelaHash[], int tamanhoDaTabela){
	
	for (int i = 0; i < tamanhoDaTabela; i++){
		cout << "[" << i << "] " << tabelaHash[i] << endl;
	}
	cout << "\n***FIM***\n";
}

int procuraNaTabela(int tabelaHash[], int chave, int tamanhoTabela){
	
	int indice;
	indice = funcaoHash(chave, tamanhoTabela);
	
	while (tabelaHash[indice] != chave){
		if (tabelaHash[indice] == -1){
			indice = -1;
			break;			
		}if (indice == tamanhoTabela){
			indice = -2;
			break;		
		}
		indice ++;
	}
	return indice;
}

int main(){
	
	int tamanhoTabela, chave, resultado;
	
	cout << "Informe a quantidade de posicoes da tabela: ";
	cin >> tamanhoTabela;
	
	int *tabelaHash = (int*)malloc(sizeof(int) * tamanhoTabela);
	
	for (int i = 0; i < tamanhoTabela; i ++){
		tabelaHash[i] = -1;
	}
	
	while (chave != -1){
		cout << "\nDigite o numero a ser inserido: ";
		cin >> chave;
		
		resultado = inserirTabelaHash(tabelaHash, chave, tamanhoTabela);
		
		if (resultado >= 0){
			cout << "***\nChave inserida com sucesso!\n";
			imprimirTabelaHash(tabelaHash, tamanhoTabela);
		}else if (resultado == -2){
				cout << "\n---Tabela nao possui espaco livre---";
		}else{
			cout << "\n---Chave ja existente!---";
		}
	}
	
	cout << "\n\n***Buscando na Tabela Hash***\n\n" << endl;
	chave = 0;
	
	while (chave != -1){
		cout << "\nDigite a chave para ser localizada: ";
		cin >> chave;
		
		resultado = procuraNaTabela(tabelaHash, chave, tamanhoTabela);
		if (resultado >= 0){
			cout << "\nA chave buscada esta na posicao: " << resultado << endl;
			imprimirTabelaHash(tabelaHash, tamanhoTabela);			
		}else{
			cout << "\n---Chave nao localizada---" << endl;
		}
	}	
	return 0;
}
