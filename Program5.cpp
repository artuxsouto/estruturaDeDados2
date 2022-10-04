#include <iostream>
#include <stdlib.h>

using namespace std;

struct noFila{
	int idade;
	char *nome;
	struct noFila *proximoNo;
	struct noFila *noAnterior;
};

struct noFila *inserirNadador(struct noFila *inicioFila, int idade, char *nome){
	struct noFila *percorreFila = inicioFila;
	struct noFila *noAtual = (struct noFila*)malloc(sizeof(struct noFila));

	if(percorreFila != NULL){
		while(percorreFila->proximoNo != NULL){
			percorreFila = percorreFila->proximoNo;
		}
		percorreFila->proximoNo = noAtual;
	}
	noAtual->noAnterior = percorreFila;
	noAtual->idade = idade;
	noAtual->nome = nome;
	noAtual->proximoNo = NULL;

	if(inicioFila == NULL){
		return noAtual;
	}else{
		return inicioFila;
	}
}

int funcaoHash(int valor){

	int indiceCat;

		if ((valor == 5)&&(valor < 8)){
			indiceCat = 0;
		}else if ((valor == 8)&&(valor < 11)){
			indiceCat = 1;
		}else if ((valor == 11)&&(valor < 14)){
			indiceCat = 2;
		}else if ((valor == 14)&&(valor < 18)){
			indiceCat = 3;
		}else {
			indiceCat = 4;
		}
	return indiceCat;
}

void imprimirNadador(struct noFila *inicioFila){
	struct noFila *noAtual = inicioFila;

	while(noAtual != NULL){
		cout << "\nNadador: " << noAtual->nome << "\nIdade: " << noAtual->idade << endl;
		noAtual = noAtual->proximoNo;
	}
	cout << "\n***Fim da Lista***\n";
}

int main(){
	struct noFila *tabelaNadador[5];

	for (int i = 0; i < 5; i++){
		tabelaNadador[i] = NULL;
	}

	int idade, indice;
	char *nome;

	while(idade != -1){
		cout << "\nDigite a idade ou '-1' para sair: ";
		cin >> idade;
		if (idade == -1){
			break;
		}
		nome = (char*)malloc(sizeof(char) *30);
		cout << "\nNome: ";
		cin >> nome;

		indice = funcaoHash(idade);
		tabelaNadador[indice] = inserirNadador(tabelaNadador[indice], idade, nome);
	}
	int busca;

	while (busca != -1){
		cout << "\nBuscar Nadador:\n" << "0:5 ate 7\n1:8 ate 10\n2:11 ate 13\n3:14 ate 17\n4:Maior de 18\n-1:Sair\n\nInforme: ";
		cin >> busca;
		if (busca == -1){
			cout << "\n***Fim do programa***";
			break;
		}
		cout << "\n\nNadador por Categoria: " << busca << endl;
		imprimirNadador(tabelaNadador[busca]);
	}
	return 0;
}
