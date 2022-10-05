#include <stdlib.h>
#include <iostream>

using namespace std;

struct noFila{
	int idade;
	char *nome;
	struct noFila *proximoNo;
	struct noFila *noAnterior;
};

struct noFila *inserirFila(struct noFila *inicioFila, int idade, char *nome){
	struct noFila *percorreFila = inicioFila;
	struct noFila *novoNo = (struct noFila*)malloc(sizeof(struct noFila));
	
	if (percorreFila != NULL){
		while (percorreFila->proximoNo != NULL){
			percorreFila = percorreFila->proximoNo;
		}
		percorreFila->proximoNo = novoNo;
	}
	novoNo->noAnterior = percorreFila;
	novoNo->idade = idade;
	novoNo->nome = nome;
	novoNo->proximoNo = NULL;
	
	if (inicioFila == NULL){
		return novoNo;
	}else{
		return inicioFila;
	}
}

int funcaoHash(int valor){
	
	int indiceEndereco;
	
	if (valor < 30){
		indiceEndereco = 0;
	}else if((valor >= 30) && (valor < 50)){
		indiceEndereco = 1;
	}else{
		indiceEndereco = 2;		
	}
	return indiceEndereco;
}

void imprimirFila(struct noFila *inicioFila){
	struct noFila *percorreFila = inicioFila;
	
	while (percorreFila != NULL){
		cout << "\nNome: " << percorreFila->nome << "\nIdade: " << percorreFila->idade << endl;
		percorreFila = percorreFila->proximoNo;
	}
	cout << "\n*** Fim da Fila ***";
}

int main(){
	
	struct noFila *filaEspera[3];
	
	for (int i = 0; i <= 3; i ++){
		filaEspera[i] = NULL;
	}
	int idade;
	char *nome;
	int indice = -1;
	
	while (idade != -1){
		cout << "\nDigite a idade ou '-1' para sair: ";
		cin >> idade;
		if (idade == -1){
			break;
		}
		nome = (char*)malloc(sizeof(char) *30);
		cout << "\nDigite o nome: ";
		cin >> nome;
		
		indice = funcaoHash(idade);
		
		filaEspera[indice] = inserirFila(filaEspera[indice], idade, nome);
	}
	if (indice != -1){
		for (int j = 0; j < 3; j ++){
			if (j == 0){
				cout << "idade < 30:\n";
			}else if(j == 1){
				cout << "\nIdade entre 30 a 50:\n";
			}else{
				cout << "\nIdade maior que 50:\n";
			}
		imprimirFila(filaEspera[j]);
		}
}
	cout << "\n***Fim do Programa***";
	return 0;
}
