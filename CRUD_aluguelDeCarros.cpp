#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

typedef struct{
	int codigoCar = 0;
	char marca [10];
	int ano = 0;
	char cor [10];
	char situacao[15];
}carro;

typedef struct{
	int codigoCliente = 0;
	char nome [30];
	char cpf [11];
	char dataAluguel [8];
	
}cliente;

void consulta(carro listaCarros[]){
	int i;
	
	for(i=0; i<5; i++){
		printf("\nCodigo do carro: %d", listaCarros[i].codigoCar);
		printf("\nMarca: %s", listaCarros[i].marca);
		printf("\nAno: %d", listaCarros[i].ano);
		printf("\nCor: %s", listaCarros[i].cor);
		printf("\nSituacao: %s\n\n", listaCarros[i].situacao);
	}
}

int receberEntradaDoUsuario(int entrada){
	printf("O que deseja fazer?\n1 - Fazer um aluguel\n2 - Exibir a lista de carros\n3 - Atualizar a situacao de um aluguel\n4 - Deletar um aluguel\n5 - Cadastrar um novo cliente\n0 - Encerrar o programa\n");
	scanf("%d", &entrada);
	return entrada;
}




int main(){
	srand(time(NULL));
	int entrada;
	carro listaCarros[5];
	carro indice;
	
	listaCarros[0].codigoCar = rand();
	strcpy(listaCarros[0].marca, "Chevrolet");
	listaCarros[0].ano = 2009;
	strcpy(listaCarros[0].cor, "Prata");
	strcpy(listaCarros[0].situacao, "Disponivel"); 
	
	listaCarros[1].codigoCar = rand();
	strcpy(listaCarros[1].marca, "Fiat");
	listaCarros[1].ano = 2012;
	strcpy(listaCarros[1].cor, "Azul");
	strcpy(listaCarros[1].situacao, "Disponivel"); 
	
	listaCarros[2].codigoCar = rand();
	strcpy(listaCarros[2].marca, "Volkswagen");
	listaCarros[2].ano = 1997;
	strcpy(listaCarros[2].cor, "Vermleho");
	strcpy(listaCarros[2].situacao, "Disponivel"); 
	
	listaCarros[3].codigoCar = rand();
	strcpy(listaCarros[3].marca, "Porshe");
	listaCarros[3].ano = 2024;
	strcpy(listaCarros[3].cor, "Preto");
	strcpy(listaCarros[3].situacao, "Disponivel"); 
	
	listaCarros[4].codigoCar = rand();
	strcpy(listaCarros[4].marca, "Ford");
	listaCarros[4].ano = 1999;
	strcpy(listaCarros[4].cor, "Branco");
	strcpy(listaCarros[4].situacao, "Disponivel"); 
	
	
	printf("O que deseja fazer?\n1 - Fazer um aluguel\n2 - Exibir a lista de carros\n3 - Atualizar a situacao de um aluguel\n4 - Deletar um aluguel\n5 - Cadastrar um novo cliente\n0 - Encerrar o programa\n");
	scanf("%d", &entrada);
	
	while(entrada!= 0){
		if(entrada== 2){
			consulta(listaCarros);
		}
		entrada = receberEntradaDoUsuario(entrada);
	}
}
