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

		if ((valor >= 5)&&(valor <= 7)){
			indiceCat = 0;
		}else if ((valor >= 8)&&(valor <= 10)){
			indiceCat = 1;
		}else if ((valor >= 11)&&(valor <= 13)){
			indiceCat = 0;
		}else if ((valor >= 14)&&(valor <= 17)){
			indiceCat = 1;
		}else{
			indiceCat = 2;
		}
	return indiceCat;
}

void imprimirNadador(struct noFila *inicioFila){
	struct noFila *noAtual = inicioFila;

	while(noAtual != NULL){
		cout << "\nNadador(a): " << noAtual->nome << "\nIdade: " << noAtual->idade << endl;
		noAtual = noAtual->proximoNo;
	}
	cout << "\n***Fim da Lista***\n";
}

int main(){
	struct noFila *tabelaNadador[2];

	for (int i = 0; i <= 2; i++){
		tabelaNadador[i] = NULL;
	}

	int idade;
	int indice = -1;
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
	if (indice != -1){
		for (int j = 0; j <= 2; j++){
			if (j == 0){
				cout << "\nInfantil A";
			}else if (j == 1){
				cout << "\nInfantil B";
			}else{
				cout << "\nAdulto";
			}
			imprimirNadador(tabelaNadador[j]);
		}
	}
	cout << "\n***Fim do Programa***";
	return 0;
}
