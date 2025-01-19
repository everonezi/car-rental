#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

int indiceCliente = 0;


//Criação das structs
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

//Exibe a lista de carros, dando as informações, como por exemplo, se o carro está disponível ou não
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

//Função para receber uma entrada do usuário para controlar o fluxo do programa
int receberEntradaDoUsuario(int entrada){
	printf("\n\nO que deseja fazer?\n1 - Fazer um aluguel\n2 - Exibir a lista de carros\n3 - Atualizar a situacao de um aluguel\n4 - Cadastrar um novo cliente\n5 - Exibir lista de clientes cadastrados\n0 - Encerrar o programa\n");
	scanf("%d", &entrada);
	return entrada;
}

void cadastrarCliente(cliente listaClientes[]) {
    printf("Nome do cliente:");
    fflush(stdin); // Limpa o buffer de entrada
    fgets(listaClientes[indiceCliente].nome, sizeof(listaClientes[indiceCliente].nome), stdin);
    listaClientes[indiceCliente].nome[strcspn(listaClientes[indiceCliente].nome, "\n")] = '\0'; // Remove o '\n'

    printf("CPF:");
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

//Função para alugar o carro
void AlugarCarro(cliente listaCliente[], carro listaCarros[]){
	int i,j;
	char placa[10];
	char cpfCliente[12];
	int clienteNcadastrado=1;
	
	consultarCarros(listaCarros);
	
	printf("Informe a placa do veiculo que deseja alugar: ");
	fflush(stdin);
	fgets(placa,sizeof(placa),stdin);
	placa[strcspn(placa, "\n")] = 0;
	
	printf("\nInforme o CPF do cliente que deseja alugar o carro com a placa %s\n", placa);
	fflush(stdin);
	fgets(cpfCliente,sizeof(cpfCliente),stdin);
	cpfCliente[strcspn(cpfCliente, "\n")] = 0;
	
	//Consulta se o cliente esta cadastrado
	for(i=0;i<5;i++){
		if(strcmp(listaCliente[i].cpf,cpfCliente)==0){
			clienteNcadastrado = 0;
		}
	}
	if(clienteNcadastrado>0){
		printf("Cliente nao cadastrado !!! Por favor realize o cadastro\n\n");
		cadastrarCliente(listaCliente);
	}
	
	//Verifica se o carro esta disponivel e realiza o aluguel
	for(i=0;i<5;i++){
		if(strcmp(listaCarros[i].situacao,"Disponivel")==0){
			if(strcmp(listaCarros[i].placa,placa)==0){
				strcpy(listaCarros[i].situacao,"Alugado");
				strcat(listaCarros[i].situacao," por ");
				strcat(listaCarros[i].situacao,cpfCliente);
				printf("Veiculo com a placa %s alugado com sucesso pelo cliente com CPF %s!\n\n", placa, cpfCliente);
			}
		}else{
			printf("Veiculo Indisponivel!!");
		}
	}
}

//Exibe a lista de clientes cadastrados
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

//Atualiza o aluguel de um carro com base na placa
void atualizarAluguel(carro listaCarros[]){
	char placaAlterar[10];
	char atualizarSituacao[15];
	int i;
	
	printf("Digite a placa do carro que deseja alterar a situacao: ");
	fflush(stdin);
	fgets(placaAlterar, sizeof(placaAlterar), stdin);
	placaAlterar[strcspn(placaAlterar, "\n")] = 0;
	
	for(i=0;i<5;i++){
		if(strcmp(listaCarros[i].placa,placaAlterar)==0){
			printf("\nSituacao do carro: ('Disponivel' ou 'Alugado')");
			fflush(stdin);
			fgets(atualizarSituacao, sizeof(atualizarSituacao), stdin);
			atualizarSituacao[strcspn(atualizarSituacao, "\n")] = 0;
			break;
		}
	}
	
	strcpy(listaCarros[i].situacao, atualizarSituacao);
}

int main(){
	
	int entrada;
	carro listaCarros[5];
	cliente listaClientes[5];
	
	//Cadastro de 5 carros disponiveis
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
	
	
	//Recebe uma entrada do usuário para controlar o programa
	printf("\nO que deseja fazer?\n1 - Fazer um aluguel\n2 - Exibir a lista de carros\n3 - Atualizar a situacao de um aluguel\n4 - Cadastrar um novo cliente\n5 - Exibir lista de clientes cadastrados\n0 - Encerrar o programa\n");
	scanf("%d", &entrada);
	
	while(entrada!= 0){
		switch(entrada){
			case 1:
				AlugarCarro(listaClientes,listaCarros);
				break;
				
			case 2:
				consultarCarros(listaCarros);
				break;
				
			case 3:
				atualizarAluguel(listaCarros);
				break;
				
			case 4:
				cadastrarCliente(listaClientes);
				break;
				
			case 5:
				exibirClientes(listaClientes);
				break;
		}
		entrada = receberEntradaDoUsuario(entrada);
	}
	return 0;
}
