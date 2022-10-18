#include <iostream>
#include <map>

using namespace std;

int main(){
	
	int chave;
	string curso;
	map<int, string> mat;
	map<int, string>::iterator item;
	
	mat[103] = "Estrutura de Dado I";
	mat[203] = "Estrutura de Dados II";
	mat[303] = "Estrutura de Dados III";
	mat[405] = "Prog. Orientada a Objetos";	
	
	cout << "Informe a chave: ";
	cin >> chave;
	
	if (mat.find(chave) == mat.end()){
		cout << "\nChave inexistente!";
	}else{
		cout << mat.find(chave)->first << " => Disciplina: " << mat.find(chave)->second << endl;
	}
	
	cout << "\nInforme uma nova chave para disciplina: ";
	cin >> chave;
	
	if (mat.find(chave) == mat.end()){
		cout << "\nInfome a disciplina: ";
		cin >> curso;
		mat.insert(pair<int, string>(chave, curso));
		cout << "\nChave incluida!\n";				
	}else{
		cout << "\nChave já cadastrada!";
	}
	
	cout << "\nInforme uma chave para ser removida: ";
	cin >> chave;
	
	if (mat.find(chave) == mat.end()){
		cout << "\nChave nao encontrada.";
	}else{
		item = mat.find(chave);
		mat.erase(item);
		cout << "\nChave excluida!\n";
	}
	
	cout << "\nTodas as disciplinas registradas:\n";
	
	for (item = mat.begin(); item != mat.end(); item++){
		cout << item->first << " - " << item->second << endl;
	}
	return 0;
}
