//Espelhamento Linear
#include <iostream>
#include <stdlib.h>

using namespace std;

struct dadosPessoa{
	int idade, rg;
	float altura;
};

int funcaoHash(int chave, int tamanhoTabela){
	int indice = chave % tamanhoTabela;
	return indice;	
}

int inserirTabelaHash(struct dadosPessoa tabelaHash[], int chave, int valor, float valor1, int tamanhoTabela){
	
	int indice = funcaoHash(chave, tamanhoTabela);
	
	while (tabelaHash[indice].rg != -1){
		if (indice == tamanhoTabela){
			indice = -2;
			break;
		}
		if (tabelaHash[indice].rg == chave){
			indice = -1;
			break;
		}
		indice ++;
	}
	
	if (indice >= 0){
		tabelaHash[indice].rg = chave;
		tabelaHash[indice].idade = valor;
		tabelaHash[indice].altura = valor1;
	}
	return indice;
}

void imprimirTabelaHash(struct dadosPessoa tabelaHash[], int tamanhoDaTabela){
	
	for (int i = 0; i < tamanhoDaTabela; i++){
		cout << "[" << i << "] " << tabelaHash[i].rg << "\nIdade: " << tabelaHash[i].idade << "\nAltura: " << tabelaHash[i].altura << "\nRG: " << tabelaHash[i].rg << endl;
	}
	cout << "\n***FIM***\n";
}

int procuraNaTabela(struct dadosPessoa tabelaHash[], int chave, int tamanhoTabela){
	
	int indice;
	indice = funcaoHash(chave, tamanhoTabela);
	
	while (tabelaHash[indice].rg != chave){
		if (tabelaHash[indice].rg == -1){
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
	
	int chave, resultado, idade, rg, controle, contador, busca;
	float altura;
	
	int tamanhoTabela = 10;
	
	struct dadosPessoa tabelaHash[tamanhoTabela];
	
	for (int i = 0; i < tamanhoTabela; i++){
		tabelaHash[i].rg = -1;
	}
	
	while (controle != -1){
		
		cout << "\n***Menu***\n1 - Cadastrar dados.\n2 - Imprimir Tabela Hash.\n3 - Procurar dados com RG.\n0 - Sair.\n\nDigite a opcao: ";
		cin >> controle;
		
		if (controle == 1){
			cout << "\n***Cadastrando uma pessoa***" << endl;
			
			cout << "\nDigite o RG(apenas numeros) da pessoa: ";
			cin >> chave;
		
			cout << "\nDigite a idade da pessoa: ";
			cin >> idade;
		
			cout << "\nDigite a altura da pessoa: ";
			cin >> altura;
		
			resultado = inserirTabelaHash(tabelaHash, chave, idade, altura, tamanhoTabela);
		
		if (resultado >= 0){
			cout << "\nChave inserida com sucesso!\n";
			contador++;
		}else if (resultado == -2){
			cout << "\n---Tabela nao possui espaco livre---";
		}else{
			cout << "\n---Chave ja existente!---";
		}
		
		}else if (controle == 2){
			cout << "\n***Imprimindo TabelaHash***" << endl;
			imprimirTabelaHash(tabelaHash, tamanhoTabela);
		}else if (controle == 3){
			cout << "\n\n***Buscando na Tabela Hash***\n\n\nDigite a chave para ser localizada: ";
			cin >> busca;
		
			resultado = procuraNaTabela(tabelaHash, busca, tamanhoTabela);
			if (resultado >= 0){
				cout << "\nA chave buscada esta na posicao: " << resultado << endl;
				imprimirTabelaHash(tabelaHash, tamanhoTabela);			
		}else{
			cout << "\n---RG nao localizado---" << endl;
		}
		}else{
			cout << "***FIM***\nTotal de cadastro: " << contador << endl;
			controle = -1;
		}		
	}
	cout << "\nObrigado! Volte sempre.";
	return 0;
}
