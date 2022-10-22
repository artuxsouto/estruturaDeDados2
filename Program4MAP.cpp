#include <iostream>
#include <stdlib.h>
#include <map>

using namespace std;

struct dadosVeiculo{
	char *nome;
	string marca, cor;
	int ano;
};

int main(){
	
	int chave, anoCarro, posicao;
	string marcaCarro, corCarro;
	char *nomeCarro;
	
	map<int, dadosVeiculo> carro;
	map<int, dadosVeiculo>::iterator item;
	
	dadosVeiculo infoCarro;
	
	while(nomeCarro != "-1"){
		cout << "***Cadastro de Veiculo***" << endl;
		cout << "\nInforme o ano de fabricacao ou '-1' para sair: ";
		cin >> anoCarro;
		
		if (anoCarro == -1){
			break;
		}
		cout << "\nInforme a marca: ";
		cin >> marcaCarro;
		
		cout << "\nInforme a cor: ";
		cin >> corCarro;
		
		nomeCarro = (char*)malloc(sizeof(char) *30);
		cout << "\nInforme o nome do condutor: ";
		cin >> nomeCarro;
		
		infoCarro.ano = anoCarro;
		infoCarro.marca = marcaCarro;
		infoCarro.cor = corCarro;
		infoCarro.nome = nomeCarro;
		carro[chave] = infoCarro;
		chave++;
		system("cls");
	}
	
	cout << "Quantidade de carros cadastrados: " << chave << endl;
	
	for (item = carro.begin(); item != carro.end(); item++){
		posicao = item->first;
		
		cout << "\nChave: " << posicao << " - Nome do condutor: " 
		<< carro[posicao].nome << "\nMarca do Veiculo: " 
		<< carro[posicao].marca << "\nCor do veiculo: " << carro[posicao].cor 
		<< "\nAno de fabricacao: " << carro[posicao].ano << "\n--\n" << endl;
	}
	
	cout << "\nInforme uma chave para buscar: ";
	cin >> chave;
	
	if (carro.find(chave) == carro.end()){
		cout << "\nChave não encontrada!";
	}else{
		cout << "\nChave Encontrada: " << chave << " - Nome do condutor: " 
		<< carro[chave].nome << "\nMarca do Veiculo: " 
		<< carro[chave].marca << "\nCor do veiculo: " << carro[chave].cor 
		<< "\nAno de fabricacao: " << carro[chave].ano << "\n--\n" << endl;
	}
	
	cout << "\nInforme uma chave para ser removida: ";
	cin >> chave;
	
	if (carro.find(chave) == carro.end()){
		cout << "\nChave nao encontrada.";
	}else{
		item = carro.find(chave);
		carro.erase(item);
		cout << "\nChave excluida!\n";
	}
	
	cout << "\nNova Lista:" << endl;
	
	for (item = carro.begin(); item != carro.end(); item++){
		posicao = item->first;
		
		cout << "\nChave: " << posicao << " - Nome do condutor: " 
		<< carro[posicao].nome << "\nMarca do Veiculo: " 
		<< carro[posicao].marca << "\nCor do veiculo: " << carro[posicao].cor 
		<< "\nAno de fabricacao: " << carro[posicao].ano << "\n--\n" << endl;
	}
	return 0;
}
