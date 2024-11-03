#include <stdio.h> //biblioteca de comunica��o com o usu�rio
#include <stdlib.h> //biblioteca de aloca��o de espa�o de mem�ria
#include <locale.h> //biblioteca de aloca��es de texto por regi�o
#include <string.h> //biblioteca respons�vel por cuidar das strings

int registrar() //fun��o respons�vel por cadastrar os usu�rios no sistema
{

	//in�cio cria��o de vari�veis/string
	char arquivo[40]; //caracteres
	char cpf[40];
	char nome[40];
	char sobrenome[40];
	char cargo[40];
	//final da cria�� de vari�veis/string
	
	printf("Digite o CPF a ser cadastrado: \n"); //coletar informa��o do usu�rio
	scanf("%s",cpf); //%s se refere a string (salvar)
	
	strcpy(arquivo, cpf); //respons�vel por copiar os valores das strings
	FILE *file; //cria o arquivo

	file = fopen(arquivo, "w"); //cria o arquivo
	fprintf(file,"CPF: ");	
	fprintf(file,cpf); //salva o valor da vari�vel
	fclose(file); //fecha o arquivo
	
	file = fopen(arquivo, "a"); //atualizar
	fprintf(file,"; Nome: ");
	fclose(file);
	
	printf("Digite o nome: \n");
	scanf("%s",nome);
	
	file = fopen(arquivo, "a"); //atualizar
	fprintf(file,nome);
	fclose(file);
	
	file = fopen(arquivo, "a"); //atualizar
	fprintf(file,"; Sobrenome: ");
	fclose(file);
	
	printf("Digite o sobrenome: \n");
	scanf("%s",sobrenome);
	
	file = fopen(arquivo, "a"); //atualizar
	fprintf(file,sobrenome);
	fclose(file);
	
	file = fopen(arquivo, "a"); //atualizar
	fprintf(file,"; Cargo: ");
	fclose(file);
	
	printf("Digite o cargo: \n");
	scanf("%s",cargo);
	
	file = fopen(arquivo, "a"); //atualizar
	fprintf(file,cargo);
	fclose(file);
	
	file = fopen(arquivo, "a"); //atualizar o arquivo
	fprintf(file,";");
	fclose(file);
	
}

int consultar()
{
	setlocale(LC_ALL, "Portuguese"); //definindo a linguagem
	
	char cpf[40];
	char conteudo[200];
	
	printf("Digite o CPF que deseja consultar: \n");
	scanf("%s",cpf);
	
	FILE *file;
	file = fopen(cpf,"r"); //para ler o arquivo
	
	if(file == NULL)
	{
		printf("N�o foi poss�vel localizar o arquivo.\n");
	}

	while(fgets(conteudo, 200, file) != NULL) //enquanto estiver escrevendo na variavel ou string conteudo at� 200 valores que est�o dentro do arquivo enquanto for diferente de nulo
	{
		printf("\nEssas s�o as informa��es do usu�rio: \n");
		printf("%s", conteudo);
		printf("\n\n");
	}
	
	system("pause");

}

int deletar()
{

	char cpf[40];
	
	printf("Digite o CPF que deseja deletar: \n");
	scanf("%s",cpf);
	
	remove(cpf);
	
	FILE *file;
	file = fopen(cpf,"r");
	
	if(file == NULL)
	{
		printf("O usu�rio n�o foi localizado!\n");
		system("pause");
	}
		
}

int main ()
{
	int opcao=0; //definindo vari�veis
	int laco=1; //definindo repeti��o
	
	for(laco=1;laco=1;)
	{
	
		system("cls"); //apaga todas as informa��es do console
	
		setlocale(LC_ALL, "Portuguese"); //definindo a linguagem
				
//definindo a linguagem

		printf("### Cart�rio da EBAC ###\n\n");
	
//in�cio do menu

		printf("Escolha a op��o desejada do menu: \n\n"); //in�cio do menu \n pula linha
		printf("\t1 - Registrar nomes\n");
		printf("\t2 - Consultar nomes\n");
		printf("\t3 - Deletar nomes\n\n");
		printf("\t4 - Sair do sistema\n\n"); 
		printf("Op��o: "); //fim do menu
	
		scanf("%d", &opcao); //armazenando a escolha do usu�rio
	
		system("cls"); //respons�vel por limpar a tela
		
		switch(opcao) //in�cio da sele��o do menu
		{
			case 1:
			registrar(); //chamada de fun��es
			break;
			
			case 2:
			consultar(); //consulta de fun��es
			break;
			
			case 3:
			deletar(); //deleta fun��es
			break;
			
			case 4:
			printf("Obrigado por utilizar o sistema!");
			return 0; //quebra la�o e sai do sistema
			break;	
			
			default:
			printf("Essa op��o n�o est� dispon�vel, tente novamente.\n\n"); 
			system("pause"); //comando para pausar a tela
			break;	
		} //fim da sele��o
	
		
	
		printf("Esse software � de livre uso dos alunos.\n");
	

	}


}
