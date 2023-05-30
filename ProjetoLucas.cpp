#include <iostream>

using namespace std;

typedef struct {
	string Nome;
	float Valor;
	int Quantidade;
} Produtos;

void LeInformacoes(Produtos Prod[10]) { //Cadastro dos produtos
	for(int i = 0; i < 10; i++) {
		cout << "    ------PRODUTO" << i << "--------" << endl;
		cout << "Nome: "; cin >> Prod[i].Nome;
		cout << "Valor: R$"; cin >> Prod[i].Valor;
		cout << "Quantidade: "; cin >> Prod[i].Quantidade;
	}
}

void LucroMaximo(Produtos Prod[10]) { //Verifica��o de poss�vel faturamento m�ximo
	float MaiorValor, FaturamentoMaximo;
	int MaiorQuantidade, i;
	
	for(i = 0; i < 10; i++) {
		if(Prod[i].Valor > MaiorValor) {
			FaturamentoMaximo += Prod[i].Valor * Prod[i].Quantidade;		
		}
	}
	cout << "O faturamento maximo dessa maquina pode ser de R$" << FaturamentoMaximo << endl;
}

void ListaProdutos(Produtos Prod[10]) { //Listagem com nome, valor e quantidade de produtos
	for(int i = 0; i < 10; i ++) {
		cout << "Nome: " << Prod[i].Nome << endl;
		cout << "Valor: R$" << Prod[i].Valor << endl;
		cout << "Quantidade: " << Prod[i].Quantidade << endl;
		cout << endl;
	}
}

void ReporProdutos(Produtos Prod[10]) { //Reposi��o de produtos faltantes
	int NumeroProdutoReposto;
	int QuantidadeReposta;
	char ContinuaRepor;
	
	do {
		cout << "    ------REPOSICAO------" << endl;
		cout << "Informe o numero do produto a ser reposto: "; cin >> NumeroProdutoReposto;
		cout << "Informe a quantidade a ser reposta: "; cin >> QuantidadeReposta;
		for(int i = 0; i < 10; i++) {
			if(i == NumeroProdutoReposto) { //Verifica��o do numero do produto para ac�mulo de quantidade
				Prod[i].Quantidade += QuantidadeReposta;
			}
		}		
		cout << "Deseja continuar repondo itens? (S/N)"; cin >> ContinuaRepor;
	} while(ContinuaRepor == 'S');
}

void EscolhaCompra(Produtos Prod[10]) { //Escolha dos produtos pelo usu�rio
	int NumeroProdutoCompra, QuantidadeCompra;
	float ValorPago, ValorTotal, ValorMaquina, ValorTroco;
	char Continuar, Troco;
	
	do {
		for(int i = 0; i < 10; i++) {
			cout << "  ----PRODUTO[" << i << "]----" << endl;
			cout << "Nome: " << Prod[i].Nome << endl; //Exibi��o dos produtos cadastrados
			cout << "Valor: R$" << Prod[i].Valor << endl; //Exibi��o dos produtos cadastrados
			cout << "Quantidade: " << Prod[i].Quantidade << endl; //Exibi��o dos produtos cadastrados
			cout << endl;
		}
		cout << "Informe o numero do produto que deseja comprar: "; cin >> NumeroProdutoCompra;
		if(NumeroProdutoCompra > 10) { //Verifica��o do �ndice informado pelo usu�rio
			cout << "Informe um numero valido!!!";
			break;
		}
		cout << "Informe a quantidade que deseja comprar: "; cin >> QuantidadeCompra;
		if(QuantidadeCompra > Prod[NumeroProdutoCompra].Quantidade) { //Verifica��o se a quantidade desejada est� dentro do estoque 
			cout << "Quantidade insuficiente!!!";
			break;
		}
		for(int i = 0; i < 10; i++) {
			if(i == NumeroProdutoCompra) {
				Prod[i].Quantidade -= QuantidadeCompra;	//Decr�scimo da quantidade do produto em caso de compra
			}	
		}
		ValorPago = Prod[NumeroProdutoCompra].Valor * QuantidadeCompra; //C�lculo do valor pago pelo produto
		cout << "O valor a ser pago eh de R$" << ValorPago << endl;
		cout << endl;
		cout << "Deseja continuar a compra? (S/N)"; cin >> Continuar;
		cout << endl;
		}
		ValorTotal += ValorPago; //Ac�mulo do valor total da compra
	} while(Continuar == 'S');
	
	cout << "O valor total da compra foi de R$" << ValorTotal << endl;
	cout << "Precisa de troco? (S/N)"; cin >> Troco; //Verifica necessidade de troco
	cout << endl;
	if(Troco == 'S') {
		cout << "Qual o valor voce colocara na maquina?"; cin >> ValorMaquina;
		cout << endl;
		ValorTroco = ValorMaquina - ValorTotal; //Calcula o valor do troco
		cout << "O seu troco eh de R$" << ValorTroco << endl;
		cout << endl;
		cout << "Obrigado!!!" << endl;
	}
	else if(Troco == 'N') {
		cout << "Obrigado!!!" << endl;
	}
	else {
		cout << "Informe uma resposta valida!!!" << endl;
	}
}

int main(int argc, char** argv) {

	char Modo;
	int Opcao;
	Produtos Prod[10];

	cout << "------MODO ADMINISTRADOR-------" << endl;
	
	do {	
		LeInformacoes(Prod); //Leitura dos itens dispon�veis
	
		cout << endl;
		cout << "Selecione uma opcao: " << endl;
		cout << "[0] - Reposicao de produtos" << endl;
		cout << "[1] - Listagem dos produtos" << endl;
		cout << "[2] - Faturamento da maquina" << endl;
		cin >> Opcao;
		cout << endl;
		
		if(Opcao == 0) {
			ReporProdutos(Prod); //Op��o de rep�r itens
		}
		else if(Opcao == 1) {
			ListaProdutos(Prod); //Listagem de produtos
		}
		else if(Opcao == 2) {
			LucroMaximo(Prod); //Faturamento m�ximo
		}
		else {
			cout << "Informe uma opcao valida!!!";
			break;
		}
		
		cout << "Deseja ir para o modo usuario? (S/N)"; cin >> Modo;
		cout << endl;
	} while(Modo == 'N');
	
	do {
		cout << "------MODO USUARIO------" << endl;
		EscolhaCompra(Prod); //Entrada no modo usu�rio
		cout << endl;
		cout << "Deseja permanecer no modo usuario? (S/N)"; cin >> Modo;
	} while(Modo == 'S');
	
	return 0;
}
