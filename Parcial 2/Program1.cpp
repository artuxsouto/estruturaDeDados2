//Espelhamento Duplo
#include <iostream>
#include <stdlib.h>

using namespace std;

int funcaoHash(int chave, int tamanhoTabelaHash){
	int indice = chave % tamanhoTabelaHash;
	return indice;
}

int funcaoHashSegundoPasso(int chave, int tamanhoTabelaHash){
	int indice = (1+(chave % (tamanhoTabelaHash)));
	return indice;
}

int funcaoReHash(int i, int k, int tamanhoTabelaHash){
	int indice = (i + k) % tamanhoTabelaHash;
	return indice;
}

struct employee{
	int idade, codigo;
	float salario;
};

int inserirNaTabelaHash(struct employee tabelaHash[], int chave, int idade, float salario, int tamanhoTabelaHash){
	int indice, i, k;
	i = funcaoHash(chave, tamanhoTabelaHash);
	k = funcaoHashSegundoPasso(chave, tamanhoTabelaHash);
	indice = funcaoReHash(i, k, tamanhoTabelaHash);
	
	while (tabelaHash[indice].codigo != -1){
		if (indice == tamanhoTabelaHash){
			indice = -2;
			break;
		}
		if (tabelaHash[indice].codigo == chave){
			indice = -1;
			break;
		}
		indice++;
	}
	
	if (indice >= 0){
		tabelaHash[indice].codigo = chave;
		tabelaHash[indice].idade = idade;
		tabelaHash[indice].salario = salario;
	}
	return indice;
}
	
	int procurarNaTabelaHash(struct employee tabelaHash[], int chave, int tamanhoTabelaHash){
		int indice, i, k;
		i = funcaoHash(chave, tamanhoTabelaHash);
		k = funcaoHashSegundoPasso(chave, tamanhoTabelaHash);
		indice = funcaoReHash(i, k, tamanhoTabelaHash);
		
		while (tabelaHash[indice].codigo != chave){
			if (tabelaHash[indice].codigo == -1){
				indice = -1;
				break;
			}
			if (indice == tamanhoTabelaHash){
				indice = -2;
				break;
			}
			indice++;
		}
		return indice;
	}
	
	void imprimirTabelaHash(struct employee tabelaHash[], int tamanhoTabelaHash){
		for (int i = 0; i < tamanhoTabelaHash; i++){
			cout << "[" << i << "] Codigo: " << tabelaHash[i].codigo << "\nIdade: " << tabelaHash[i].idade << "\nSalario: R$ " << tabelaHash[i].salario << endl;
		}
		cout << "***FIM**" << endl;
	}
	
	int main(){
		int idade, codigo, chave, cadastro, busca, contador;
		int tamanhoTabela = 12;
		float salario;
		
		struct employee tabelaHash[tamanhoTabela];
		
		for (int i = 0; i < tamanhoTabela; i++){
			tabelaHash[i].codigo = -1;
		}
		
		chave = 0;
		while (chave != -1){
			cout << "\n***MENU***\n1 - Cadastro de funcionario.\n2 - Imprimir tabela.\n3 - Busca funcionario por codigo.\n0 - Sair." << "\nDigite a opcao: ";
			cin >> chave;
			
			if (chave == 1){
				cout << "\nDigite o codigo do funcionario: ";
				cin >> codigo;
				
				cout << "\nDigite a idade: ";
				cin >> idade;
				
				cout << "\nDigite o salario: ";
				cin >> salario;
				
				cadastro = inserirNaTabelaHash(tabelaHash, codigo, idade, salario, tamanhoTabela);
				
				if (cadastro >= 0){
					cout << "\n***Chave inserida com sucesso!***\n";
					contador++;
				}else if (cadastro == -2){
					cout << "\n***Nao existe espaco livre :(***\n";
				}else{
					cout << "\n***Chave ja existente!***";
				}
			}else if (chave == 2){
				cout << "\n***Imprimir tabela de funcionario***" << endl;
				imprimirTabelaHash(tabelaHash, tamanhoTabela);
			}else if (chave == 3){
				cout << "\nDigite o codigo para busca: ";
				cin >> busca;
				
				cadastro = procurarNaTabelaHash(tabelaHash, busca, tamanhoTabela);
				
				if (cadastro >= 0){
					cout << "\nChave encontra-se no indice [" << cadastro <<"]" << endl;
					imprimirTabelaHash(tabelaHash, tamanhoTabela);		
				}else{
					cout << "\nFuncionario inexistente" << endl;
				}
			}else{
				cout << "\n***FIM***\nFuncionarios cadastrados: " << contador << endl;
				chave = -1;
			}
		}
			return 0;
		}
