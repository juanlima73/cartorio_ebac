//o sistema l� tudo de forma algoritma, de cima pra baixo
#include <stdio.h> //biblioteca de comunica��o com o usu�rio
#include <stdlib.h> //biblioteca de aloca��o de espa�o em mem�ria
#include <locale.h> //biblioteca de aloca��es de texto por regi�o
#include <string.h> //biblioteca respons�vel por cuidar das strings

int registro () //n�o possui ; pois isto � uma fun��o. Responsav�l por cadastras os usu�rios no sistema
{
	//inicio criacao de variaveis/string
	char arquivo[40];
	char cpf[40];//char � uma variavel que reconhece letras e numeros, por�m neste caso ela da o sentido de string que iremos precisar para a build do prog 
	char nome [40];// tudo dentro de {} significa instru��es e deve ter ;
	char sobrenome [40];
	char cargo [40];
	//final criacao de variaveis/string
	
	printf("Digite o CPF a ser cadastrado: ");//coletando informacao do usuario
	scanf("%s", cpf);//%s refere-se a string e esta armazenandos os dados dentro da variavel cpf
	
	strcpy(arquivo, cpf);//neste caso estou copiando as informa��es do cpf igualar com o arquivo. Ou seja o valor de arquivo agora � igual ao cpf
	
	FILE *file;//criando um arquivo(file). Acesse o FILE(bibliotecas dev c++) e crie o file
	file = fopen(arquivo, "w");//abra o arquivo e nomeio com a informa��o que est� dentro da variavel "arquivo" ("w ou write" escreve no novo arquivo)
	fprintf(file,cpf);//salvando a variavel cpf dentro do arquivo file
	fclose(file);//fechando o arquivo
	
	file = fopen(arquivo, "a");//abrindo o arquivo que ser� nomeado com o cpf digitado pelo user ("a" para atualizar o arquivo)
	fprintf(file, ",");//colocando uma virgula para separar as informa��es.
	fclose(file);
	
	printf("Digite o nome a ser cadastrado: ");
	scanf("%s", nome);
	
	file = fopen(arquivo, "a");
	fprintf(file,nome);
	fclose(file);
	
	file = fopen(arquivo, "a");
	fprintf(file,",");
	fclose(file);
	
	printf("Digite o sobrenome a ser cadastrado: ");
	scanf("%s", sobrenome);
	
	file = fopen(arquivo, "a");
	fprintf(file,sobrenome);
	fclose(file);
	
	file = fopen(arquivo, "a");
	fprintf(file, ",");
	fclose(file);
	
	printf("Digite o cargo a ser cadastrado: ");
	scanf("%s", cargo);
	
	file = fopen(arquivo, "a");
	fprintf(file,cargo);
	fclose(file);
	
	system("pause");
}

int consulta ()
{
	setlocale(LC_ALL, "Portuguese");//A defini��o de linguagem deve ser feito em cada fun��o criada, pois uma fun��o n�o enxerga a outra
	
	char cpf[40]; //� um instru��o de fun��o diferente de registro, por este motivo se faz necessario criar novamente a variable cpf novamente.
	char conteudo[200]; //ir� armazenar o conteudo que est� dentro do arquivo dos registros existentes.
	
	printf("Digite o CPF a ser consultado: ");
	scanf("%s", cpf);
	
	FILE *file;//abrindo o arquivo
	file = fopen(cpf, "r");//lendo as informa��es armazenadas dentro do arquivo ("r" read - ler)
	
	if(file == NULL)//valida��o caso n�o encontre o item procurado dentro do arquivo. Se o arquivo (file) n�o encontrou o cpf (n�o foi possivel abri...) 
	{
		printf("N�o foi possivel abrir o arquivo, n�o localizado!. \n");
	}
	
	while(fgets(conteudo, 200, file) != NULL)//instru��o de valida��o do enquanto (enquanto tiver conteudo dentro do arquivo, ser� armazenado dentro da variavel arquivo.
	//fun�a� whlie � repeti��o(enquanto...).
	//fgets indo buscar arquivo 
	//Nesta sintaxe estou salvando dentro da string os 200 caracteres que est�o dentro do arquivo(file)
	// vai parar quando for nulo, pois n�o colocamos 200 caracteres no arquivo
	{
		printf("\nEssas s�o as informa��es do usu�rio: ");
		printf("%s", conteudo);
		printf("\n\n");
	}
	
	system("pause");
	
}

int deletar ()
{
	char cpf[40]; //string pois o cpf cont�m mais de um valor. Variavel char seria apenas se fosse um unico valor
	
	printf("Digite o CPF do usu�rio a ser deletado: ");
	scanf("%s",cpf);
	
	remove(cpf); //vem de uma determinada biblioteca, est� fun��o so server para deletar. Ela n�o busca o arquivo na "pasta ou servidor"
	
	FILE *file; //acessa a fun��o FILE na bliblioteca e procure o arquivo parametro file
	file = fopen(cpf, "r"); //ap�s acessar o file, abra o file/cpf
	
	if(file == NULL)
	{
		printf("O usu�rio n�o se encontra no sistema!\n");
		system("pause");
	}
	
	else
	{
		printf("Usu�rio deletado com sucesso!\n");
		system("pause");
	}
	
}



int main () //main � fun��o principal, sempre ser� a primeira
{
	int opcao=0; //Declarando que o espa�o da variavel chamada opcao � 0. Boas praticas para n�o correr risco de contaminar a variavel
	int laco=1; //laco e o nome da variavel que ir� dar o loop no programa
	char senhadigitada[10]="a";
	int comparacao;
	
	setlocale(LC_ALL, "Portuguese"); //Definindo a Linguagem
	
	printf("### Cart�rio da EBAC ###\n\n");
	printf("Login de administrador!\n\nDigite a sua senha: ");
	scanf("%s",senhadigitada);
	
	comparacao = strcmp(senhadigitada, "admin"); //strcmp tem por finalidade comparar strings se possui o mesmo "n�mero de memoria" pois se trata de strings.	
	system("cls"); //Limpa as informa��es anteriores da tela
	
	if(comparacao == 0)
	{
			
	
		for(laco=1;laco=1;) //Est� dando sentido de loop no programa, ir� fazer sempre o programa voltar da estaca zero ap�s colher as informacoes digitada pelo user
		{
		
			system("cls"); //Limpa as informa��es anteriores da tela
		
			setlocale(LC_ALL, "Portuguese"); //Definindo a Linguagem
	
			printf("### Cart�rio da EBAC ###\n\n"); //Inicio do Menu
			printf("Escolha a op��o desejada do menu:\n\n");
			printf("\t1 - Registrar nomes\n");
			printf("\t2 - Consultar nomes\n");
			printf("\t3 - Deletar nomes\n\n"); 
			printf("\t4- Sair do sistema\n\n");
		
			printf("Op��o: ");//Fim do menu	
	
			scanf("%d", &opcao); //scanf ir� armazenar os dados do usuario. %d e uma declaracao que � variavel do tipo inteiro
	
			system("cls"); //limpa a tela com todas as informa��es que tinha antes
		
			switch(opcao) //op��o armazenada na variavel
			{
				case 1: //caso o valor da variav�l seja 1:
				registro(); //chamada de funcoes
				break;
				
				case 2: //caso o valor da variav�l seja 2:
				consulta();
				break;
			
				case 3: //caso o valor da variav�l seja 3:
				deletar();
				break;
			
				case 4:
				printf("Obrigado por utilizar o sistema\n");
				return 0;
				break;
				
				default: //� uma especie de else, caso n�o tenha nenhum tipo de compara��o verdadeira ir� retornar:
				printf("Essa op��o n�o est� disponivel!\n");
				system("pause");
				break;
			} // fim da selecao
	
		}
	}	
	
	else
		printf("Senha incorreta!");
	
}
