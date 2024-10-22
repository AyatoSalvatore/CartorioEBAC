#include <stdio.h> //biblioteca de comunica��o com o usu�rio
#include <stdlib.h> //biblioteca de aloca��o de espa�o em mem�ria
#include <locale.h> //biblioteca de aloca��es de texto por regi�o
#include <string.h> //biblioteca respons�vel pelas strings

int registrar() //Fun��o respons�vel por cadastrar os usu�rios no sistema
{
	//inicio cria��o de vari�veis/strings
	char arquivo[40];
	char cpf[40];
	char nome[40];
	char sobrenome [40];
	char cargo[40];
	//final da cria��o de vari�veis/strings
	
	printf("Digite o CPF de cadastro: "); //coletando informa��o do usu�rio
	scanf("%s", cpf); //%s refere-se a strings, salva-las
	
	strcpy(arquivo, cpf); //respons�vel por criar os valores das strings
	
	FILE *file; // cria o arquivo do banco de dados
	file = fopen(arquivo, "w"); // cria o arquivo e o "w" significa write
	fprintf(file,cpf); // salvo o valor da vari�vel
	fclose(file); // fecha o arquivo
	
	file = fopen(arquivo, "a"); //"a" significa editar
	fprintf(file,",");
	fclose(file);
	
	printf ("Digite o nome de cadastro: ");
	scanf("%s",nome);
	
	file = fopen(arquivo, "a");
	fprintf(file,nome);
	fclose(file);
	
	file = fopen(arquivo, "a");
	fprintf(file,","); //"," significa o espa�o em branco para cada string
	fclose(file);
	
	printf ("Digite o sobrenome de cadastro: ");
	scanf("%s",sobrenome);
	
	file = fopen(arquivo, "a");
	fprintf(file,sobrenome);
	fclose(file);
	
	file = fopen(arquivo, "a");
	fprintf(file,",");
	fclose(file);
	
	printf ("Digite o cargo de cadastro: ");
	scanf("%s",cargo);
	
	file = fopen(arquivo, "a");
	fprintf(file,cargo);
	fclose(file);
	
	system("pause");
}

int consultar()
{
	setlocale(LC_ALL, "Portuguese");
	
	char cpf[40];
	char conteudo[200];
	
	printf("Digite o CPF a ser consultado: ");
	scanf("%s",cpf);
	
	FILE *file;
	file = fopen(cpf,"r"); //"r" significa read, ler o arquivo
	
	if(file == NULL)
	{
		printf("N�o foi poss�vel localizar o arquivo!.\n");
	}
	
	while(fgets(conteudo, 200, file) != NULL)
	{
		printf("\nEssas s�o as informa��es do usu�rio: ");
		printf("%s", conteudo);
		printf("\n\n");
	}
	
	system("pause");
}

int deletar()
{
	char cpf[40];
	
	printf("Digite o CPF do usu�rio a ser deletado: ");
	scanf("%s",cpf);
	
	remove(cpf);
	
	FILE *file;
	file = fopen(cpf,"r");
	  
	if(file == NULL)
	{
		printf("Este usu�rio n�o consta no sistema!.\n");
		system("pause");
	}
}

int main()
{
	int opcao=0; //Definindo Vari�veis
	int laco=1;
	
	for(laco=1;laco=1;)
	{
		
		system("cls");
		
	    setlocale(LC_ALL, "Portuguese"); //Definindo a linguagem
	
	    printf("### Cart�rio da EBAC ###\n\n"); //Inicio do menu
	    printf("Escolha a op��o do seu desejo no menu:\n\n");
	    printf("\t1 - Registrar usu�rios\n");
	    printf("\t2 - Consultar usu�rios\n");
	    printf("\t3 - Deletar usu�rios\n\n");
	    printf("\t4 - Sair\n\n");
	    printf("Op��o: "); // fim do menu
	
	    scanf("%d", &opcao); //armazenando a escolha do usu�rio
	
	    system("cls"); //responsavel por limpar a tela
	    
	    
	    switch(opcao) //inicio da sele��o do menu
		{
			case 1:
			registrar(); //chamada de fun��es
		    break;
		    
		    case 2:
		    consultar();
			break;
			
			case 3:
			deletar();
			break;
			
			case 4:
			printf("O sistema est� sendo fechado!");
			return 0;
			break;
			
			default:
			printf("Est� op��o n�o est� dispon�vel!\n");
			system("pause");
			break;
			
		} //fim da sele��o
   
    }
}
