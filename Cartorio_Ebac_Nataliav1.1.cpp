#include <stdio.h> //biblioteca de comunicação com o usuário
#include <stdlib.h> //biblioteca de alocação de espaço de memória
#include <locale.h> //biblioteca de alocações de texto por região
#include <string.h> //biblioteca responsável por cuidar das strings

int registrar() //função responsável por cadastrar os usuários no sistema
{

	//início criação de variáveis/string
	char arquivo[40]; //caracteres
	char cpf[40];
	char nome[40];
	char sobrenome[40];
	char cargo[40];
	//final da criaçã de variáveis/string
	
	printf("Digite o CPF a ser cadastrado: \n"); //coletar informação do usuário
	scanf("%s",cpf); //%s se refere a string (salvar)
	
	strcpy(arquivo, cpf); //responsável por copiar os valores das strings
	FILE *file; //cria o arquivo

	file = fopen(arquivo, "w"); //cria o arquivo
	fprintf(file,"CPF: ");	
	fprintf(file,cpf); //salva o valor da variável
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
		printf("Não foi possível localizar o arquivo.\n");
	}

	while(fgets(conteudo, 200, file) != NULL) //enquanto estiver escrevendo na variavel ou string conteudo até 200 valores que estão dentro do arquivo enquanto for diferente de nulo
	{
		printf("\nEssas são as informações do usuário: \n");
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
		printf("O usuário não foi localizado!\n");
		system("pause");
	}
		
}

int main ()
{
	int opcao=0; //definindo variáveis
	int laco=1; //definindo repetição
	
	for(laco=1;laco=1;)
	{
	
		system("cls"); //apaga todas as informações do console
	
		setlocale(LC_ALL, "Portuguese"); //definindo a linguagem
				
//definindo a linguagem

		printf("### Cartório da EBAC ###\n\n");
	
//início do menu

		printf("Escolha a opção desejada do menu: \n\n"); //início do menu \n pula linha
		printf("\t1 - Registrar nomes\n");
		printf("\t2 - Consultar nomes\n");
		printf("\t3 - Deletar nomes\n\n");
		printf("\t4 - Sair do sistema\n\n"); 
		printf("Opção: "); //fim do menu
	
		scanf("%d", &opcao); //armazenando a escolha do usuário
	
		system("cls"); //responsável por limpar a tela
		
		switch(opcao) //início da seleção do menu
		{
			case 1:
			registrar(); //chamada de funções
			break;
			
			case 2:
			consultar(); //consulta de funções
			break;
			
			case 3:
			deletar(); //deleta funções
			break;
			
			case 4:
			printf("Obrigado por utilizar o sistema!");
			return 0; //quebra laço e sai do sistema
			break;	
			
			default:
			printf("Essa opção não está disponível, tente novamente.\n\n"); 
			system("pause"); //comando para pausar a tela
			break;	
		} //fim da seleção
	
		
	
		printf("Esse software é de livre uso dos alunos.\n");
	

	}


}
