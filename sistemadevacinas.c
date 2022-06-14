#include <stdio.h>
#define SIZE 200
char nome[SIZE][50];
int cpf[SIZE];
char vacina[SIZE][50];
char data[SIZE][50];
int lote[SIZE];
int op;
void cadastro();
void pesquisa();
void lista();

int main(void){
	do{
		system("cls");
		printf("                           Sistema de Cadastro de Vacinas                  \n                          ================================\n");
		printf("1 - Cadastrar Vacina\n2 - Listar Aplicacoes\n3 - Consultar CPF\n4 - Sair\n");
		scanf("%d", &op);
		switch(op){
			case 1:
				cadastro();
			break;
			case 2:
				lista();
			break;
			case 3:
				pesquisa();
			break;
			case 4:
				system("exit");
			break;
			default:
				printf("opcao invalida");
			break;
		}
	}while(op!=4);
}
void lista(){
	int i;
	for(i=0; i<SIZE; i++){
		if(cpf[i]>0){
			printf("\nCodigo: %d\nNome: %s\nCPF: %d\nVacina: %s\nData: %s\nNumero do Lote: %d\n============================", i, nome[i], cpf[i], vacina[i], data[i], lote[i]);
		}
	}
	getchar();
	getchar();
}
void cadastro(){
	static int linha;
	do{
		printf("\nDigite o nome: ");
		scanf("%s", &nome[linha]);
		fflush(stdin);
		printf("\nDigite o CPF: ");
		scanf("%d", &cpf[linha]);
		fflush(stdin);
		printf("\nDigite a Vacina: ");
		scanf("%s", &vacina[linha]);
		fflush(stdin);
		printf("\nDigite a Data: ");
		scanf("%s", &data[linha]);
		fflush(stdin);
		printf("\nDigite o Lote: ");
		scanf("%d", &lote[linha]);
		fflush(stdin);
		printf("\nDigite 1 para continuar ou outro valor para sair ");
		scanf("%d", &op);
		system("cls");
		linha++;
	}while(op==1);
}
void pesquisa(){
	int cpfPesquisa;
	int i;
	do{
		printf("\nDigite 1 para pesquisar CPF ");
		scanf("%d", &op);
		switch(op){
			case 1:
				printf("\nDigite o CPF: ");
				scanf("%d", &cpfPesquisa);
				for(i=0; i<SIZE; i++){
					if(cpf[i]==cpfPesquisa){
					printf("\nCodigo: %d\nNome: %s\nCPF: %d\nVacina: %s\nData: %s\nNumero do Lote: %d", i, nome[i], cpf[i], vacina[i], data[i], lote[i]);
					}
				}
				break;		
			default:
				printf("\nOpcao invalida");
				break;
		}
		printf("\nDigite 1 para continuar pesquisando ");
		scanf("%d", &op);
	}while(op==1);
}
