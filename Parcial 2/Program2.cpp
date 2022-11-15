//Mapa associativo
#include <iostream>
#include <map>
#include <stdlib.h>

using namespace std;

int main(){
	
	int chave, codigo, contador;
	map<int, int> enade;
	map<int, int>::iterator item;
	
	while (chave != -1){
		
		cout << "\n***MENU***\n1 - Cadastrar aluno.\n2 - Quantidade de aluno para prova.\n3 - Imprimir o codigo dos alunos.\n0 - Sair.\n***\nDigite uma opcao: ";
		cin >> chave;
		
		if (chave == 1){
			codigo = 0;
			while (codigo != -2){
				cout << "\nDigite o codigo do aluno: ";
				cin >> codigo;
				
				enade[contador] = codigo;
				contador++;
			}			
		}else if (chave == 2){
			cout << "\nQuantidade de alunos a fazer a prova ENADE: " << contador << endl;
		}else if (chave == 3){
			for (item = enade.begin(); item != enade.end(); item ++){
				cout << item->first << " - " << item->second << endl;
			}
		}else{
			cout << "\n***FIM***" << endl;
			chave = -1;
		}
	}
	cout << "\nObrigado! Volte sempre." << endl;
	return 0;
}
