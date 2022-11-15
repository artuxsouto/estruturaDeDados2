//Mapa associativo e Listas
#include <iostream>
#include <map>
#include <stdlib.h>

using namespace std;

struct dadosCarro{
	int chassi, ano;
};

int main(){
	
	int chave,ano, chassi, contador, busca, posicao;
	map<int, dadosCarro> carro;
	map<int, dadosCarro>::iterator item;
	
	dadosCarro veiculo;
	
	while (chave != -1){
		
		cout << "\n***MENU***\n1 - Inserir informacao do carro.\n2 - Quantidade de veiculos cadastrados.\n3 - Imprimir todos os carros.\n4 - Procurar um carro pela chave\n5 - Remover um carro.\n0 - Sair\n***\nDigite a opcao: ";
		cin >> chave;
		
		if (chave == 1){
			chassi = 0;
			while (chassi != -1){
				cout << "\nDigite o chassi: ";
				cin >> chassi;
				
				cout << "\nDigite o ano: ";
				cin >> ano;
				
				veiculo.chassi = chassi;
				veiculo.ano = ano;
				carro[contador] = veiculo;
				contador++;
			}			
			
		}else if (chave == 2){
			cout << "\nQuantidade de carros cadastrados: " << contador << endl;
		}else if (chave == 3){
			for (item = carro.begin(); item != carro.end(); item++){
				posicao = item->first;
				
				cout << "\nChave: " << posicao << "\nChassi: " << carro[posicao].chassi << "\nAno: " << carro[posicao].ano << endl;
			}			
		}else if (chave == 4){
			
			cout << "\nInforme a chave para busca: ";
			cin >> busca;
			
			if (carro.find(busca) == carro.end()){
				cout << "\nVeiculo nao encontrado" << endl;
			}else{
				cout << "Veiculo encontrado:\nChassi: " << carro[busca].chassi << "\nAno: " << carro[busca].ano << endl;
			}
		}else if (chave == 5){
			cout << "\nInforme a chave para ser removida: ";
			cin >> busca;
			
			if (carro.find(busca) == carro.end()){
		cout << "\nVeiculo nao encontrado.";
	}else{
		item = carro.find(busca);
		carro.erase(item);
		cout << "\nVeiculo removido!\n";
	}
		}else{
			cout << "\n***FIM**" << endl;
			chave = -1;
		}
	}
	
	cout << "\nObrigado! Volte sempre." << endl; 
	
	return 0;
}
