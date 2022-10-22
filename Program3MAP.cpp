#include <iostream>
#include <stdlib.h>
#include <map>

using namespace std;

int main(){
	
	string nome;
	int chave;
	map<int, string> enade;
	map<int, string>::iterator item;
	
	while(nome != "-1"){
		cout << "***LISTA DE ALUNOS PARA FAZER A PROVA DO ENADE 2022***" << endl;
		cout << "\nInforme o nome do aluno ou '-1' para sair: ";
		cin >> nome;
		if (nome == "-1"){
			break;
			system("cls");
		}
		enade.insert(pair<int, string>(chave, nome));
		chave++;
		system("cls");
	}
	cout << "\nQuantidade de alunos que vao fazer o ENADE: " << chave << endl;
	
	for (item = enade.begin(); item != enade.end(); item++){
		cout << "\nAluno: " << item->second << endl;
	}	
	return 0;
}
