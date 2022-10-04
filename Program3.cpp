#include <iostream>
#include <stdlib.h>

using namespace std;

struct noFila{
	float preco;
	char *nome;
	int cdg;
	struct noFila *proximoNo;
	struct noFila *noAnterior;
};

struct noFila *inserirProduto(struct noFila *inicioFila, float preco, char *nome, int cdg){
	struct noFila *percorreFila = inicioFila;
	struct noFila *noAtual = (struct noFila*)malloc(sizeof(struct noFila));
	
	if(percorreFila != NULL){
		while(percorreFila->proximoNo != NULL){
			percorreFila = percorreFila->proximoNo;
		}
		percorreFila->proximoNo = noAtual;
	}
	noAtual->noAnterior = percorreFila;
	noAtual->preco = preco;
	noAtual->nome = nome;
	noAtual->cdg;
	noAtual->proximoNo = NULL;
	
	if(inicioFila == NULL){
		return noAtual;
	}else{
		return inicioFila;
	}
}

int funcaoHash(int valor){
	
	int indiceRegiao;

		if (valor == 1){
			indiceRegiao = 0;
		}else if (valor == 2){
			indiceRegiao = 1;
		}else if (valor == 3){
			indiceRegiao = 2;
		}else if (valor == 4){
			indiceRegiao = 3;
		}else if ((valor == 5)||(valor == 6)||(valor > 21)||(valor <= 30)){
			indiceRegiao = 4;
		}else if ((valor > 6)&&(valor <= 9)){
			indiceRegiao = 5;
		}else if ((valor > 9)&&(valor <= 20)){
			indiceRegiao = 6;
		}
	return indiceRegiao;
}

void imprimirProduto(struct noFila *inicioFila){
	struct noFila *noAtual = inicioFila;
	
	while(noAtual != NULL){
		cout << "\nProduto: " << noAtual->nome << "\nPreco: " << noAtual->preco << endl;
		noAtual = noAtual->proximoNo;
	}
	cout << "\n***Fim da Lista***\n";
}

int main(){
	struct noFila *tabelaProduto[6];
	
	for (int i = 0; i < 7; i++){
		tabelaProduto[i] = NULL;
	}
	
	float preco;
	char *nome;
	int cdg, indice;
	
	while(preco != -1){
		cout << "\nDigite o preco ou '-1' para sair: ";
		cin >> preco;
		if (preco == -1){
			break;
		}
		nome = (char*)malloc(sizeof(char) *30);
		cout << "\nDescricao do produto: ";
		cin >> nome;
		
		cout << "\nCodigo de origem(1 a 30): ";
		cin >> cdg;
		
		if (cdg < 31){
			indice = funcaoHash(cdg);
			tabelaProduto[indice] = inserirProduto(tabelaProduto[indice], preco, nome, cdg);
		}
	}
	int busca;
	
	while (busca != -1){
		cout << "\nBuscar Regiao:\n" << "0:Sul\n1:Norte\n2:Leste\n3:Oeste\n4:Nordeste\n5:Sudeste\n6:Centro-Oeste\n-1:Sair\n\nInforme: ";
		cin >> busca;
		if (busca == -1){
			cout << "\n***Fim do programa***";
			break;
		}
		cout << "\n\nProdutos na Regiao: " << busca << endl;
		imprimirProduto(tabelaProduto[busca]);
	}

	return 0;
}
