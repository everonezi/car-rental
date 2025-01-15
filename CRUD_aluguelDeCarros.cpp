#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

int indiceCliente = 0;


typedef struct{
	char placa [10];
	char marca [10];
	int ano = 0;
	char cor [10];
	char situacao[15];
}carro;

typedef struct{
	char codigoCliente [6];
	char nome [30];
	char cpf [12];
	char dataAluguel [8];
	
}cliente;

void consultarCarros(carro listaCarros[]){
	int i;
	
	for(i=0; i<5; i++){
		printf("\nCodigo do carro: %s", listaCarros[i].placa);
		printf("\nMarca: %.10s", listaCarros[i].marca);
		printf("\nAno: %d", listaCarros[i].ano);
		printf("\nCor: %s", listaCarros[i].cor);
		printf("\nSituacao: %s\n\n", listaCarros[i].situacao);
	}
}

int receberEntradaDoUsuario(int entrada){
	printf("\n\nO que deseja fazer?\n1 - Fazer um aluguel\n2 - Exibir a lista de carros\n3 - Atualizar a situacao de um aluguel\n4 - Deletar um aluguel\n5 - Cadastrar um novo cliente\n6 - Exibir lista de clientes cadastrados\n0 - Encerrar o programa\n");
	scanf("%d", &entrada);
	return entrada;
}

void cadastrarCliente(cliente listaClientes[]) {
    printf("Nome do cliente: ");
    fflush(stdin); // Limpa o buffer de entrada
    fgets(listaClientes[indiceCliente].nome, sizeof(listaClientes[indiceCliente].nome), stdin);
    listaClientes[indiceCliente].nome[strcspn(listaClientes[indiceCliente].nome, "\n")] = '\0'; // Remove o '\n'

    printf("CPF: ");
    fflush(stdin); // Limpa o buffer de entrada
    fgets(listaClientes[indiceCliente].cpf, sizeof(listaClientes[indiceCliente].cpf), stdin);
    listaClientes[indiceCliente].cpf[strcspn(listaClientes[indiceCliente].cpf, "\n")] = '\0'; // Remove o '\n'
    
    printf("Data aluguel: ");
    fflush(stdin); // Limpa o buffer de entrada
    fgets(listaClientes[indiceCliente].dataAluguel, sizeof(listaClientes[indiceCliente].dataAluguel), stdin);
    listaClientes[indiceCliente].dataAluguel[strcspn(listaClientes[indiceCliente].dataAluguel, "\n")] = '\0'; // Remove o '\n'

    printf("Codigo do cliente (5 digitos): ");
    fflush(stdin); // Limpa o buffer de entrada
    fgets(listaClientes[indiceCliente].codigoCliente, sizeof(listaClientes[indiceCliente].codigoCliente), stdin);
    listaClientes[indiceCliente].codigoCliente[strcspn(listaClientes[indiceCliente].codigoCliente, "\n")] = '\0'; // Remove o '\n'

    indiceCliente++;
}

void exibirClientes(cliente listaCliente[]) {
    int i;
    printf("\nLista de clientes cadastrados: \n");
    for (i = 0; i < indiceCliente; i++) {
        printf("\nNome do cliente: %s", listaCliente[i].nome);
        printf("\nCPF: %s", listaCliente[i].cpf);
        printf("\nData do aluguel: %s", listaCliente[i].dataAluguel);
        printf("\nCodigo do cliente: %s\n", listaCliente[i].codigoCliente);
    }
}






int main(){
	
	int entrada;
	carro listaCarros[5];
	cliente listaClientes[5];
	
	strcpy(listaCarros[0].placa, "ABC1D23");
	strcpy(listaCarros[0].marca, "Chevrolet");
	listaCarros[0].ano = 2009;
	strcpy(listaCarros[0].cor, "Prata");
	strcpy(listaCarros[0].situacao, "Disponivel"); 
	
	strcpy(listaCarros[1].placa, "XYZ4E56");
	strcpy(listaCarros[1].marca, "Fiat");
	listaCarros[1].ano = 2012;
	strcpy(listaCarros[1].cor, "Azul");
	strcpy(listaCarros[1].situacao, "Disponivel"); 
	
	strcpy(listaCarros[2].placa, "QWE7R89");
	strcpy(listaCarros[2].marca, "Volkswagen");
	listaCarros[2].ano = 1997;
	strcpy(listaCarros[2].cor, "Vermleho");
	strcpy(listaCarros[2].situacao, "Disponivel"); 
	
	strcpy(listaCarros[3].placa, "JKL2M34");
	strcpy(listaCarros[3].marca, "Porshe");
	listaCarros[3].ano = 2024;
	strcpy(listaCarros[3].cor, "Preto");
	strcpy(listaCarros[3].situacao, "Disponivel"); 
	
	strcpy(listaCarros[4].placa, "PQR6T78");
	strcpy(listaCarros[4].marca, "Ford");
	listaCarros[4].ano = 1999;
	strcpy(listaCarros[4].cor, "Branco");
	strcpy(listaCarros[4].situacao, "Disponivel"); 
	
	
	printf("\nO que deseja fazer?\n1 - Fazer um aluguel\n2 - Exibir a lista de carros\n3 - Atualizar a situacao de um aluguel\n4 - Deletar um aluguel\n5 - Cadastrar um novo cliente\n6 - Exibir lista de clientes cadastrados\n0 - Encerrar o programa\n");
	scanf("%d", &entrada);
	
	while(entrada!= 0){
		switch(entrada){
			case 1:
				
				break;
				
			case 2:
				consultarCarros(listaCarros);
				break;
				
			case 3:
				
				break;
				
			case 4:
				
				break;
				
			case 5:
				cadastrarCliente(listaClientes);
				break;
				
			case 6:
				exibirClientes(listaClientes);
				break;
		}
		entrada = receberEntradaDoUsuario(entrada);
	}
	return 0;
}
