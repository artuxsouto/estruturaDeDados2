#include <stdlib.h>
#include <iostream>

using namespace std;

struct noFila{
	int cdg;
	char *nome;
	float salario;
	struct noFila *proximoNo;
	struct noFila *noAnterior;
};

struct noFila *inserirFuncionario(struct noFila *inicioFila, int valor, char *valor1, float valor2){
	struct noFila *percorreFila = inicioFila;
	struct noFila *novoNo = (struct noFila*)malloc(sizeof(struct noFila));
	
	if (percorreFila != NULL){
		while (percorreFila->proximoNo != NULL){
			percorreFila = percorreFila->proximoNo;
		}
		percorreFila->proximoNo = novoNo;
	}
	novoNo->noAnterior = percorreFila;
	novoNo->cdg = valor;
	novoNo->nome = valor1;
	novoNo->salario = valor2;
	novoNo->proximoNo = NULL;
	
	if (inicioFila == NULL){
		return novoNo;
	}else{
		return inicioFila;
	}
}

void imprimirFuncionario(struct noFila *inicioFila){
	struct noFila *noAtual = inicioFila;
	float calc;
	
	while(noAtual != NULL){
		if (noAtual->cdg == 0){
			calc = noAtual->salario + (noAtual->salario * 0.30);
		}else if (noAtual->cdg == 1){
			calc = noAtual->salario + (noAtual->salario * 0.25);
		}else if (noAtual->cdg == 2){
			calc = noAtual->salario + (noAtual->salario * 0.2);
		}else if (noAtual->cdg == 3){
			calc = noAtual->salario + (noAtual->salario * 0.1);
		}else{
			calc = noAtual->salario;
		}
		cout << "\nNome: " << noAtual->nome << "\nNovo Salario: " << calc << endl;
		noAtual = noAtual->proximoNo;
	}
	cout << "\n***Fim da Lista***";
}

int funcaoHash(int valor){
	int indiceCargo;
	
	if (valor == 0){
		indiceCargo = 0;
	}else if (valor == 1){
		indiceCargo = 1;
	}else if (valor == 2){
		indiceCargo = 2;	
	}else if(valor == 3){
		indiceCargo = 3;
	}else{
		indiceCargo = 4;
	}
	return indiceCargo;
}

int main(){
	
	struct noFila *tabelaFuncionario[5];
	
	for(int i = 0; i < 5; i++){
		tabelaFuncionario[i] = NULL;
	}
	char *nome;
	int cdg, indice;
	float salario;
	
	while (cdg != -1){
		cout << "\nDigite o codigo(0 a 4) ou '-1' para sair: ";
		cin >> cdg;
		if (cdg == -1){
			break;
		}
		nome = (char*)malloc(sizeof(char) *30);
		cout << "\nDigite o nome: ";
		cin >> nome;
		
		cout << "\nDigite o salario: ";
		cin >> salario;
		
		if (cdg < 5){
		indice = funcaoHash(cdg);
		tabelaFuncionario[indice] = inserirFuncionario(tabelaFuncionario[indice], cdg, nome, salario);	
		}
	}
	int busca;
	
	while (busca != -1){
		cout << "\nLocalizando funcionario por cargo:\n" << "0:Escriturario\n1:Secretario\n2:Caixa\n3:Gerente\n4:Diretor\n-1:Sair\n\nInforme: ";
		cin >> busca;
		if (busca == -1){
			cout << "\n***Fim do Programa***";
			break;
		}
		cout << "\n\nFuncionarios do cargo: " << busca << endl;
		imprimirFuncionario(tabelaFuncionario[busca]);
	}
	return 0;
}
