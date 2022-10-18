#include <stdlib.h>
#include <iostream>

using namespace std;

struct dadosPessoa{
	int idade, codigo;
	float salario;
};

int funcaoHash(int chave, int tamanhoTabela){
	int indice = chave % tamanhoTabela;
	return indice;
}

int funcaoHashSegundoPasso(int chave, int tamanhoTabela){
	int indice = (1+(chave % (tamanhoTabela)));
	return indice;
}
int funcaoReHash(int i, int k, int tamanhoTabela){
	int indice = (i + k) % tamanhoTabela;
	return indice;
}

void imprimirTabelaHash(struct dadosPessoa tabelaHash[], int tamanhoTabela){
	for (int i = 0; i < tamanhoTabela; i ++){
		cout << "[" << i << "] " << tabelaHash[i].codigo << "\nIdade: " << tabelaHash[i].idade << "\nSalario: R$ " << tabelaHash[i].salario << "\nCodigo do funcionario: " << tabelaHash[i].codigo << endl;
	}
	cout << "\n***FIM***\n";
}

int procuraNaTabela(struct dadosPessoa tabelaHash[], int chave, int tamanhoTabela){
	int indice, i, k;
	i = funcaoHash(chave, tamanhoTabela);
	k = funcaoHashSegundoPasso(chave, tamanhoTabela);
	indice = funcaoReHash(i, k, tamanhoTabela);
	
	while (tabelaHash[indice].codigo != chave){
		if (tabelaHash[indice].codigo == -1){
			indice = -1;
			break;
		}
		if (indice == tamanhoTabela){
			indice = -2;
			break;
		}
		indice ++;
	}
	return indice;
}

int inserirNaTabela(struct dadosPessoa tabelaHash[], int chave, int valor, float salario, int tamanhoTabela){
	int indice, i, k;
	i = funcaoHash(chave, tamanhoTabela);
	k = funcaoHashSegundoPasso(chave, tamanhoTabela);
	indice = funcaoReHash(i, k, tamanhoTabela);
	
	while (tabelaHash[indice].codigo != -1){
		if (indice == tamanhoTabela){
			indice = -2;
			break;
		}
		if (tabelaHash[indice].codigo == chave){
			indice = -1;
			break;
		}
		indice ++;
	}
	if (indice >= 0){
		tabelaHash[indice].codigo = chave;
		tabelaHash[indice].idade = valor;
		tabelaHash[indice].salario = salario;
	}
	return indice;
}

int main(){
	
	int tamanhoTabela, resultado, idade;
	float salario;
	cout << "Insercao de Numeros - Espelhamento Duplo\nInforme o tamanho da tabela: ";
	cin >> tamanhoTabela;
	
	struct dadosPessoa tabelaHash[tamanhoTabela];
	
	for (int i = 0; i < tamanhoTabela; i++){
		tabelaHash[i].codigo = -1;
	}
	
	int chave = 0;
	while(chave != -1){
		cout << "\nDigite o codigo do funcionario: ";
		cin >> chave;
		
		if (chave == -1){
			break;
		}
		
		cout << "\nDigite a idade: ";
		cin >> idade;
		
		cout << "\nDigite o salario: ";
		cin >> salario;
		
		resultado = inserirNaTabela(tabelaHash, chave, idade, salario, tamanhoTabela);
		
		if (resultado >= 0){
			cout << "\n---Chave inserida com sucesso!\n";
			imprimirTabelaHash(tabelaHash, tamanhoTabela);
		}else if(resultado == -2){
			cout << "\n---Nao existe espaco livre na tabela hash";
		}else{
			cout << "\n--Chave ja existente!";
		}
	}
	
	cout << "\n***Busca na Tabela Hash***\n";
	chave = 0;
	while (chave != -1){
		cout << "\nDigite a chave para ser localizada: ";
		cin >> chave;
		
		resultado = procuraNaTabela(tabelaHash, chave, tamanhoTabela);
		if (resultado >= 0){
			cout << "\nA chave procurada esta no indice [" << resultado << "]\n";
			imprimirTabelaHash(tabelaHash, tamanhoTabela);
		}else{
			cout << "\nChave nao localizada!";
		}
	}
	return 0;
}
