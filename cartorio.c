//o sistema lê tudo de forma algoritma, de cima pra baixo
#include <stdio.h> //biblioteca de comunicação com o usuário
#include <stdlib.h> //biblioteca de alocação de espaço em memória
#include <locale.h> //biblioteca de alocações de texto por região
#include <string.h> //biblioteca responsável por cuidar das strings

int registro () //não possui ; pois isto é uma função. Responsavél por cadastras os usuários no sistema
{
	//inicio criacao de variaveis/string
	char arquivo[40];
	char cpf[40];//char é uma variavel que reconhece letras e numeros, porém neste caso ela da o sentido de string que iremos precisar para a build do prog 
	char nome [40];// tudo dentro de {} significa instruções e deve ter ;
	char sobrenome [40];
	char cargo [40];
	//final criacao de variaveis/string
	
	printf("Digite o CPF a ser cadastrado: ");//coletando informacao do usuario
	scanf("%s", cpf);//%s refere-se a string e esta armazenandos os dados dentro da variavel cpf
	
	strcpy(arquivo, cpf);//neste caso estou copiando as informações do cpf igualar com o arquivo. Ou seja o valor de arquivo agora é igual ao cpf
	
	FILE *file;//criando um arquivo(file). Acesse o FILE(bibliotecas dev c++) e crie o file
	file = fopen(arquivo, "w");//abra o arquivo e nomeio com a informação que está dentro da variavel "arquivo" ("w ou write" escreve no novo arquivo)
	fprintf(file,cpf);//salvando a variavel cpf dentro do arquivo file
	fclose(file);//fechando o arquivo
	
	file = fopen(arquivo, "a");//abrindo o arquivo que será nomeado com o cpf digitado pelo user ("a" para atualizar o arquivo)
	fprintf(file, ",");//colocando uma virgula para separar as informações.
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
	setlocale(LC_ALL, "Portuguese");//A definição de linguagem deve ser feito em cada função criada, pois uma função não enxerga a outra
	
	char cpf[40]; //é um instrução de função diferente de registro, por este motivo se faz necessario criar novamente a variable cpf novamente.
	char conteudo[200]; //irá armazenar o conteudo que está dentro do arquivo dos registros existentes.
	
	printf("Digite o CPF a ser consultado: ");
	scanf("%s", cpf);
	
	FILE *file;//abrindo o arquivo
	file = fopen(cpf, "r");//lendo as informações armazenadas dentro do arquivo ("r" read - ler)
	
	if(file == NULL)//validação caso não encontre o item procurado dentro do arquivo. Se o arquivo (file) não encontrou o cpf (não foi possivel abri...) 
	{
		printf("Não foi possivel abrir o arquivo, não localizado!. \n");
	}
	
	while(fgets(conteudo, 200, file) != NULL)//instrução de validação do enquanto (enquanto tiver conteudo dentro do arquivo, será armazenado dentro da variavel arquivo.
	//funçaõ whlie é repetição(enquanto...).
	//fgets indo buscar arquivo 
	//Nesta sintaxe estou salvando dentro da string os 200 caracteres que estão dentro do arquivo(file)
	// vai parar quando for nulo, pois não colocamos 200 caracteres no arquivo
	{
		printf("\nEssas são as informações do usuário: ");
		printf("%s", conteudo);
		printf("\n\n");
	}
	
	system("pause");
	
}

int deletar ()
{
	char cpf[40]; //string pois o cpf contém mais de um valor. Variavel char seria apenas se fosse um unico valor
	
	printf("Digite o CPF do usuário a ser deletado: ");
	scanf("%s",cpf);
	
	remove(cpf); //vem de uma determinada biblioteca, está função so server para deletar. Ela não busca o arquivo na "pasta ou servidor"
	
	FILE *file; //acessa a função FILE na bliblioteca e procure o arquivo parametro file
	file = fopen(cpf, "r"); //após acessar o file, abra o file/cpf
	
	if(file == NULL)
	{
		printf("O usuário não se encontra no sistema!\n");
		system("pause");
	}
	
	else
	{
		printf("Usuário deletado com sucesso!\n");
		system("pause");
	}
	
}



int main () //main é função principal, sempre será a primeira
{
	int opcao=0; //Declarando que o espaço da variavel chamada opcao é 0. Boas praticas para não correr risco de contaminar a variavel
	int laco=1; //laco e o nome da variavel que irá dar o loop no programa
	char senhadigitada[10]="a";
	int comparacao;
	
	setlocale(LC_ALL, "Portuguese"); //Definindo a Linguagem
	
	printf("### Cartório da EBAC ###\n\n");
	printf("Login de administrador!\n\nDigite a sua senha: ");
	scanf("%s",senhadigitada);
	
	comparacao = strcmp(senhadigitada, "admin"); //strcmp tem por finalidade comparar strings se possui o mesmo "número de memoria" pois se trata de strings.	
	system("cls"); //Limpa as informações anteriores da tela
	
	if(comparacao == 0)
	{
			
	
		for(laco=1;laco=1;) //Está dando sentido de loop no programa, irá fazer sempre o programa voltar da estaca zero após colher as informacoes digitada pelo user
		{
		
			system("cls"); //Limpa as informações anteriores da tela
		
			setlocale(LC_ALL, "Portuguese"); //Definindo a Linguagem
	
			printf("### Cartório da EBAC ###\n\n"); //Inicio do Menu
			printf("Escolha a opção desejada do menu:\n\n");
			printf("\t1 - Registrar nomes\n");
			printf("\t2 - Consultar nomes\n");
			printf("\t3 - Deletar nomes\n\n"); 
			printf("\t4- Sair do sistema\n\n");
		
			printf("Opção: ");//Fim do menu	
	
			scanf("%d", &opcao); //scanf irá armazenar os dados do usuario. %d e uma declaracao que é variavel do tipo inteiro
	
			system("cls"); //limpa a tela com todas as informações que tinha antes
		
			switch(opcao) //opção armazenada na variavel
			{
				case 1: //caso o valor da variavél seja 1:
				registro(); //chamada de funcoes
				break;
				
				case 2: //caso o valor da variavél seja 2:
				consulta();
				break;
			
				case 3: //caso o valor da variavél seja 3:
				deletar();
				break;
			
				case 4:
				printf("Obrigado por utilizar o sistema\n");
				return 0;
				break;
				
				default: //é uma especie de else, caso não tenha nenhum tipo de comparação verdadeira irá retornar:
				printf("Essa opção não está disponivel!\n");
				system("pause");
				break;
			} // fim da selecao
	
		}
	}	
	
	else
		printf("Senha incorreta!");
	
}
