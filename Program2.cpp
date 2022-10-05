#include <stdlib.h>
#include <iostream>

using namespace std;

struct noFila{
	float peso, altura;
	struct noFila *proximoNo;
	struct noFila *noAnterior;
};

struct noFila *inserirFila(struct noFila *inicioFila, float peso, float altura){
	struct noFila *percorreFila = inicioFila;
	struct noFila *novoNo = (struct noFila*)malloc(sizeof(struct noFila));
	
	if (percorreFila != NULL){
		while (percorreFila->proximoNo != NULL){
			percorreFila = percorreFila->proximoNo;
		}
		percorreFila->proximoNo = novoNo;
	}
	novoNo->noAnterior = percorreFila;
	novoNo->peso = peso;
	novoNo->altura = altura;
	novoNo->proximoNo = NULL;
	
	if (inicioFila == NULL){
		return novoNo;
	}else{
		return inicioFila;
	}
}

int funcaoHash(float valor1, float valor2){
	float calc = valor1 / (valor2 * valor2);
	int indiceIMC;
	
	if((calc >= 18.5) && (calc < 25)){
		indiceIMC = 0;
	}else if (calc > 25){
		indiceIMC = 1;		
	}else{
		indiceIMC = 2;
	}
	return indiceIMC;
}

void imprimirFila(struct noFila *inicioFila){
	struct noFila *noAtual = inicioFila;
	
	while(noAtual != NULL){
		cout << "\nPeso: " << noAtual->peso << "\nAltura: " << noAtual->altura << endl;
		noAtual = noAtual->proximoNo;
		}
		cout << "\n*** Fim da Lista ***\n";
}

int main(){
	struct noFila *filaIMC[3];
	
	for (int i = 0; i < 3; i ++){
		filaIMC[i] = NULL;
	}
	float peso, altura;
	int indice;
	
	while (peso != -1){
		cout << "\nDigite o peso ou '-1' para sair: ";
		cin >> peso;
		if (peso == -1){
			break;
		}
		cout << "\nDigite a altura: ";
		cin >> altura;
		
		indice = funcaoHash(peso, altura);
		filaIMC[indice] = inserirFila(filaIMC[indice], peso, altura);
}
	int busca;
	if (indice =! -1){
		while (busca != -1){
			cout << "\nDigite o IMC(0:Ideal, 1:Acima, 2:Abaixo) para consulta ou digite '-1' para sair: ";
			cin >> busca;
		if (busca == -1){
			cout << "\n***Fim do Programa***";
			break;
		}else if(busca == 0){
			cout << "\nPeso Ideal:\n";
		}else if(busca == 1){
			cout << "\nAcima do peso ideal:\n";
		}else{
			cout << "\nAbaixo do peso ideal:\n";
		}
		imprimirFila(filaIMC[busca]);
	}
}
	cout << "\n***Fim do Programa***";
	return 0;
}
