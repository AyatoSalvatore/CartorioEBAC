#include <stdio.h> //biblioteca de comunicação com o usuário
#include <stdlib.h> //biblioteca de alocação de espaço em memória
#include <locale.h> //biblioteca de alocações de texto por região
#include <string.h> //biblioteca responsável pelas strings

int registrar() //Função responsável por cadastrar os usuários no sistema
{
	//inicio criação de variáveis/strings
	char arquivo[40];
	char cpf[40];
	char nome[40];
	char sobrenome [40];
	char cargo[40];
	//final da criação de variáveis/strings
	
	printf("Digite o CPF de cadastro: "); //coletando informação do usuário
	scanf("%s", cpf); //%s refere-se a strings, salva-las
	
	strcpy(arquivo, cpf); //responsável por criar os valores das strings
	
	FILE *file; // cria o arquivo do banco de dados
	file = fopen(arquivo, "w"); // cria o arquivo e o "w" significa write
	fprintf(file,cpf); // salvo o valor da variável
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
	fprintf(file,","); //"," significa o espaço em branco para cada string
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
		printf("Não foi possível localizar o arquivo!.\n");
	}
	
	while(fgets(conteudo, 200, file) != NULL)
	{
		printf("\nEssas são as informações do usuário: ");
		printf("%s", conteudo);
		printf("\n\n");
	}
	
	system("pause");
}

int deletar()
{
	char cpf[40];
	
	printf("Digite o CPF do usuário a ser deletado: ");
	scanf("%s",cpf);
	
	remove(cpf);
	
	FILE *file;
	file = fopen(cpf,"r");
	  
	if(file == NULL)
	{
		printf("Este usuário não consta no sistema!.\n");
		system("pause");
	}
}

int main()
{
	int opcao=0; //Definindo Variáveis
	int laco=1;
	
	for(laco=1;laco=1;)
	{
		
		system("cls");
		
	    setlocale(LC_ALL, "Portuguese"); //Definindo a linguagem
	
	    printf("### Cartório da EBAC ###\n\n"); //Inicio do menu
	    printf("Escolha a opção do seu desejo no menu:\n\n");
	    printf("\t1 - Registrar usuários\n");
	    printf("\t2 - Consultar usuários\n");
	    printf("\t3 - Deletar usuários\n\n");
	    printf("\t4 - Sair\n\n");
	    printf("Opção: "); // fim do menu
	
	    scanf("%d", &opcao); //armazenando a escolha do usuário
	
	    system("cls"); //responsavel por limpar a tela
	    
	    
	    switch(opcao) //inicio da seleção do menu
		{
			case 1:
			registrar(); //chamada de funções
		    break;
		    
		    case 2:
		    consultar();
			break;
			
			case 3:
			deletar();
			break;
			
			case 4:
			printf("O sistema está sendo fechado!");
			return 0;
			break;
			
			default:
			printf("Está opção não está disponível!\n");
			system("pause");
			break;
			
		} //fim da seleção
   
    }
}
