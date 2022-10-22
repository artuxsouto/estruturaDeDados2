#include <iostream>
#include <map>

using namespace std;

struct dadosPessoa{
	string nomeCandidato;
	int votosCandidato;
};

int main(){
	
	int chave, posicao, contador;
	map<int, dadosPessoa> eleicao;
	map<int, dadosPessoa>::iterator item;
	
	dadosPessoa candidato;
	candidato.nomeCandidato = "Joaquim Saraiva";
	candidato.votosCandidato = 0;
	eleicao[0] = candidato;
	
	candidato.nomeCandidato = "Empresa Sindicom";
	candidato.votosCandidato = 0;
	eleicao[1] = candidato;
	
	candidato.nomeCandidato = "Otavio Guidaves";
	candidato.votosCandidato = 0;
	eleicao[2] = candidato;
	
	cout << "***Eleicao do Condominio Golden***\n";
	
	while (chave != -1){
		for (item = eleicao.begin(); item != eleicao.end(); item++){
			posicao = item->first;
			cout << "\nChave: " << posicao << " - Candidato: " << eleicao[posicao].nomeCandidato << endl;
		}
		cout << "\nDigite a chave do candidato para votar: ";
		cin >> chave;
		system("cls");
		
		if (eleicao.find(chave) == eleicao.end()){
			cout << "\nEleicao finalizada!\n";		
		}else{
			eleicao[chave].votosCandidato++;
			cout << "\nVoto incluido com sucesso\n" << endl;
			contador++;
		}
	}
	if (contador > 0){
		for (item = eleicao.begin(); item != eleicao.end(); item++){
			posicao = item->first;
			cout << "\nO candidato: " << eleicao[posicao].nomeCandidato << "\nTotal de Votos: " << eleicao[posicao].votosCandidato << endl;			
		}
	}else{
		cout << "\n***FIM***";
	}
	
	cout << "\nTotal de Eleitor: " << contador << "\nObrigado! Por participar." << endl;
	
	return 0;
}
