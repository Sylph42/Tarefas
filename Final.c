//MATRÍCULA: 20221045050036
//NOME: Ana Késia Araújo Gomes
//USUÁRIO: Sylph42

//MATRÍCULA: 20221045050443
//NOME: FRANCISCO CAUAN ALMEIDA SAMPAIO
//USUÁRIO: cauan-sampaio

#include <cs50.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>


//textos repetidos em diferentes seções

void Texto(){
    printf("Como você quer que seja mostrado o resultado?\n");
    printf("1 - No terminal | 2 - Em um novo arquivo |\n");
}

void Texto1(){
  printf("\n=====Dados dos Derivativos=====\n");
  printf("|  Codigo     |    Ativo   |   Vcto     | Strike  | Tipo |  Coberto  |  Travado  |  Descob.  |\n");
}

void Texto2(){
  FILE *NovoArq = fopen("B3R.csv", "w");
  fprintf(NovoArq, "\n=====Dados dos Derivativos=====\n");
  fprintf(NovoArq,"|  Codigo     |    Ativo   |   Vcto     | Strike  | Tipo |  Coberto  |  Travado  |  Descob.  |\n");
}

void LocalP(){
    printf("Em qual parte deseja filtrar?\n");
    printf("| 1 -  Coberto  | 2 -  Travado  | 3 - Descob.  |\n");
}


//função para substituir vírgula por ponto
void replace(char * letra, char antigo, char novo)
{
    int i = 0;

     //ler até o final da string
    while(letra[i] != '\0')
    {
       //caso encontre o caractere
        if(letra[i] == antigo)
        {
            letra[i] = novo;
        }

        i++;
    }
}


unsigned int get_split_size(char *line)
{
  unsigned size = 0;
  char *c = line;
  while (*c != '\0')
  {
    if (*c == ';')
      size++;
    c++;
  }
  return size + 1;
}

char **malloc_tokens(char *line, unsigned *size)
{
  *size = get_split_size(line);
  char **tokens = malloc(sizeof(char *) * (*size));
  tokens[0] = line;
  return tokens;
}

char **split(char *line, char *delim, unsigned *size)
{
  unsigned pos = 0;
  char *c = NULL;

  char **tokens = malloc_tokens(line, size);
  for (c = tokens[0] + 1; *c != '\0'; c++)
  {
    if (*c == delim[0])
    {
      *c = '\0';
      pos++;
      tokens[pos] = c + 1;
    }
  }

  return tokens;
}

void check_endline(FILE *data)
{
  char c = fgetc(data);
  if (c != '\n')
  {
    ungetc(c, data);
  }
}

char *readline(FILE *data)
{
  int size = 4096;
  size_t len_read = 0;
  char *line = (char *)malloc(sizeof(char) * size);
  int line_lenght = 0;
  do
  {
    len_read = fread(&line[line_lenght], sizeof(char), 1, data);
    if (len_read > 0)
    {
      line_lenght++;
      if (line_lenght == size)
      {
        size <<= 1;
        line = realloc(line, sizeof(char) * size);
      }
    }
  } while (line[line_lenght - 1] != '\n' && line[line_lenght - 1] != '\r' && len_read > 0);

  if (line_lenght == 0)
    return NULL;
  line[line_lenght - 1] = '\0';
  check_endline(data);

  line = realloc(line, line_lenght);
  return line;
}

void free_tokens(char **tokens)
{
  free(tokens[0]);
  free(tokens);
  tokens = NULL;
}



int main(int argc, char **argv)
{
  FILE *arquivo = fopen(argv[1], "r");
  FILE *arquivo2 = fopen(argv[2], "r");
  char **tokens = NULL, **instruments = NULL;
  unsigned int size, size2;
  char *line, *line2 = NULL;
  int o, v, s = 0, x = 0, Valor;

  string a = get_string("Qual ativo deseja procurar?\n");
  printf("Obs.: Certifique-se de que seu ativo está presente em ambos os arquivos.\n"); 

printf("Como você quer pesquisar no arquivo?\n");
printf("1 - Valor | 2 - Ativo | 3 - Combinado \n");
scanf("%i", &o);

   switch(o)
   {

   default:
    printf("Valor inválido");
    break;

///////////////////////////////////////////////////////////Filtro Valor

    case 1:
    Texto();
    scanf("%i", &s);

    if(s!=1&&s!=2){
      printf("Valor inválido\n");
                 break;   }
                                                  ///Printado no terminal
     if(s==1)
     {
    LocalP();
    scanf("%d", &x);

    printf("Qual valor mínimo deseja procurar?\n");
    scanf("%d", &v);

    Texto1();
    for (int i = 0; i <1000000; i++)
    {
    line = readline(arquivo);
    tokens = split(line, ";", &size);
    do
    {
      if (instruments != NULL)
      {
        free_tokens(instruments);
        instruments = NULL;
      }
      line2 = readline(arquivo2);
      if (line2 != NULL)
      {
        instruments = split(line2, ";", &size2);
      }
    } while ((strcmp(tokens[1], instruments[1]) != 0) && line2 != NULL);

  if(instruments[35] != NULL)
    {
    replace(instruments[35],',','.');
    }

  switch(x){

  case 1:
  Valor = (atoi(tokens[9]));
  if(Valor > v)
      {
    printf("|  %-10s | %-10s | %-10s ", tokens[1], instruments[2], instruments[10]);
    printf("| %7s | %4s ", instruments[35], instruments[36]);
    printf("| %9s | %9s | %9s |\n", tokens[9], tokens[10], tokens[11]);
      }
   break;

  case 2:
  Valor = (atoi(tokens[10]));
  if(Valor > v)
       {
    printf("|  %-10s | %-10s | %-10s ", tokens[1], instruments[2], instruments[10]);
    printf("| %7s | %4s ", instruments[35], instruments[36]);
    printf("| %9s | %9s | %9s |\n", tokens[9], tokens[10], tokens[11]);
       }
  break;

  case 3:
 Valor = (atoi(tokens[11]));
  if(Valor > v)
        {
    printf("|  %-10s | %-10s | %-10s ", tokens[1], instruments[2], instruments[10]);
    printf("| %7s | %4s ", instruments[35], instruments[36]);
    printf("| %9s | %9s | %9s |\n", tokens[9], tokens[10], tokens[11]);
        }
  break;
      }
    }
  }

                                                      //Printado em novo arquivo

     if(s==2)
     {
    FILE *NovoArq = fopen("B3R.csv", "w");
    LocalP();
    scanf("%d", &x);

    printf("Qual valor mínimo deseja procurar?\n");
    scanf("%d", &v);

    Texto2();
    for (int i = 0; i <1000000; i++)
    {
    line = readline(arquivo);
    tokens = split(line, ";", &size);
    do
    {
      if (instruments != NULL)
      {
        free_tokens(instruments);
        instruments = NULL;
      }
      line2 = readline(arquivo2);
      if (line2 != NULL)
      {
        instruments = split(line2, ";", &size2);
      }
    } while ((strcmp(tokens[1], instruments[1]) != 0) && line2 != NULL);

  if(instruments[35] != NULL){
    replace(instruments[35],',','.');
    }

  switch(x)
  {

  case 1:
  Valor = (atoi(tokens[9]));
  if(Valor > v)
    {
    fprintf(NovoArq, "|  %-10s | %-10s | %-10s ", tokens[1], instruments[2], instruments[10]);
    fprintf(NovoArq, "| %7s | %4s ", instruments[35], instruments[36]);
    fprintf(NovoArq, "| %9s | %9s | %9s |\n", tokens[9], tokens[10], tokens[11]);
    }
   break;


  case 2:
  Valor = (atoi(tokens[10]));
  if(Valor > v)
    {
    fprintf(NovoArq, "|  %-10s | %-10s | %-10s ", tokens[1], instruments[2], instruments[10]);
    fprintf(NovoArq, "| %7s | %4s ", instruments[35], instruments[36]);
    fprintf(NovoArq, "| %9s | %9s | %9s |\n", tokens[9], tokens[10], tokens[11]);
    }
  break;

  case 3:
 Valor = (atoi(tokens[11]));
  if(Valor > v)
    {
    fprintf(NovoArq, "|  %-10s | %-10s | %-10s ", tokens[1], instruments[2], instruments[10]);
    fprintf(NovoArq, "| %7s | %4s ", instruments[35], instruments[36]);
    fprintf(NovoArq, "| %9s | %9s | %9s |\n", tokens[9], tokens[10], tokens[11]);
   }
  break;
  }

  }
    }


 ///////////////////////////////////////////////////////////Filtro Ativo

    case 2:

    Texto();
    scanf("%i", &s);
    
        if(s!=1&&s!=2){
      printf("Valor inválido\n");
                 break;   }
                                                   ///Printado no terminal

     if(s==1)
      {

  Texto1();
  for (int i = 0; i <1000000; i++)
  {
    line = readline(arquivo);
    tokens = split(line, ";", &size);
    do
    {
      if (instruments != NULL)
      {
        free_tokens(instruments);
        instruments = NULL;
      }
      line2 = readline(arquivo2);
      if (line2 != NULL)
      {
        instruments = split(line2, ";", &size2);
      }
    } while ((strcmp(tokens[1], instruments[1]) != 0) && line2 != NULL);

  if(instruments[35] != NULL){
    replace(instruments[35],',','.');
    }


  if(strcmp(instruments[2], a) == 0)
    {
    printf("|  %-10s | %-10s | %-10s ", tokens[1], instruments[2], instruments[10]);
    printf("| %7s | %4s ", instruments[35], instruments[36]);
    printf("| %9s | %9s | %9s |\n", tokens[9], tokens[10], tokens[11]);
    }
  }
    break;
     }


                                                   ///Printado em novo arquivo

     if(s==2)
     {
    FILE *NovoArq = fopen("B3R.csv", "w");

     Texto2();
      for (int i = 0; i <1000000; i++)
  {
    line = readline(arquivo);
    tokens = split(line, ";", &size);
    do
    {
      if (instruments != NULL)
      {
        free_tokens(instruments);
        instruments = NULL;
      }
      line2 = readline(arquivo2);
      if (line2 != NULL)
      {
        instruments = split(line2, ";", &size2);
      }
    } while ((strcmp(tokens[1], instruments[1]) != 0) && line2 != NULL);

  if(instruments[35] != NULL){
    replace(instruments[35],',','.');
    }


  if(strcmp(instruments[2], a) == 0)
    {
    fprintf(NovoArq, "|  %-10s | %-10s | %-10s ", tokens[1], instruments[2], instruments[10]);
    fprintf(NovoArq, "| %7s | %4s ", instruments[35], instruments[36]);
    fprintf(NovoArq, "| %9s | %9s | %9s |\n", tokens[9], tokens[10], tokens[11]);
    }
  }
     }
     break;



///////////////////////////////////////////////////////////Filtro Conjunto


    case 3:

  LocalP();
  scanf("%d", &x);

  printf("Qual valor mínimo deseja procurar?\n");
  scanf("%d", &v);

 Texto();
    scanf("%i", &s);

      if(s!=1&&s!=2){
      printf("Valor inválido\n");
                 break;   }
                                                   //Printado no terminal

     if(s==1)
     {

  Texto1();

  for (int i = 0; i <1000000; i++)
  {
    line = readline(arquivo);
    tokens = split(line, ";", &size);
    do
    {
      if (instruments != NULL)
      {
        free_tokens(instruments);
        instruments = NULL;
      }
      line2 = readline(arquivo2);
      if (line2 != NULL)
      {
        instruments = split(line2, ";", &size2);
      }
    } while ((strcmp(tokens[1], instruments[1]) != 0) && line2 != NULL);

  if(instruments[35] != NULL){
    replace(instruments[35],',','.');
    }

 switch(x)
          {

  case 1:
  Valor = (atoi(tokens[9]));
  if(Valor > v)
  {
     if(strcmp(instruments[2], a) == 0)
     {
    printf("|  %-10s | %-10s | %-10s ", tokens[1], instruments[2], instruments[10]);
    printf("| %7s | %4s ", instruments[35], instruments[36]);
    printf("| %9s | %9s | %9s |\n", tokens[9], tokens[10], tokens[11]);
    }
  }
   break;

  case 2:
  Valor = (atoi(tokens[10]));
  if(Valor > v)
  {
     if(strcmp(instruments[2], a) == 0)
     {
    printf("|  %-10s | %-10s | %-10s ", tokens[1], instruments[2], instruments[10]);
    printf("| %7s | %4s ", instruments[35], instruments[36]);
    printf("| %9s | %9s | %9s |\n", tokens[9], tokens[10], tokens[11]);
    }
  }
  break;

  case 3:
 Valor = (atoi(tokens[11]));
  if(Valor > v)
  {
     if(strcmp(instruments[2], a) == 0)
     {
    printf("|  %-10s | %-10s | %-10s ", tokens[1], instruments[2], instruments[10]);
    printf("| %7s | %4s ", instruments[35], instruments[36]);
    printf("| %9s | %9s | %9s |\n", tokens[9], tokens[10], tokens[11]);
    }
  }
  break;
        }
    }
  }

                                                  //Printado em novo arquivo

   if(s==2)
   {
 FILE *NovoArq = fopen("B3R.csv", "w");

  Texto2();

  for (int i = 0; i <1000000; i++)
  {
    line = readline(arquivo);
    tokens = split(line, ";", &size);
    do
    {
      if (instruments != NULL)
      {
        free_tokens(instruments);
        instruments = NULL;
      }
      line2 = readline(arquivo2);
      if (line2 != NULL)
      {
        instruments = split(line2, ";", &size2);
      }
    } while ((strcmp(tokens[1], instruments[1]) != 0) && line2 != NULL);

  if(instruments[35] != NULL){
    replace(instruments[35],',','.');
    }

 switch(x)
 {

  case 1:
  if(strcmp(instruments[2], a) == 0)
  {
     Valor = (atoi(tokens[9]));
  if(Valor > v)
     {
   fprintf(NovoArq, "|  %-10s | %-10s | %-10s ", tokens[1], instruments[2], instruments[10]);
    fprintf(NovoArq, "| %7s | %4s ", instruments[35], instruments[36]);
    fprintf(NovoArq, "| %9s | %9s | %9s |\n", tokens[9], tokens[10], tokens[11]);
    }
  }
   break;

  case 2:
  if(strcmp(instruments[2], a) == 0)
  {
    Valor = (atoi(tokens[10]));
     if(Valor > v)
     {
    fprintf(NovoArq, "|  %-10s | %-10s | %-10s ", tokens[1], instruments[2], instruments[10]);
    fprintf(NovoArq, "| %7s | %4s ", instruments[35], instruments[36]);
    fprintf(NovoArq, "| %9s | %9s | %9s |\n", tokens[9], tokens[10], tokens[11]);
    }
  }
  break;

  case 3:
  if(strcmp(instruments[2], a) == 0)
  {
    Valor = (atoi(tokens[11]));
    if(Valor > v)
     {
    fprintf(NovoArq, "|  %-10s | %-10s | %-10s ", tokens[1], instruments[2], instruments[10]);
    fprintf(NovoArq, "| %7s | %4s ", instruments[35], instruments[36]);
    fprintf(NovoArq, "| %9s | %9s | %9s |\n", tokens[9], tokens[10], tokens[11]);
    }
  }
  break;
    }
  }
}

  free_tokens(tokens);
  free_tokens(instruments);

  fclose(arquivo);
  fclose(arquivo2);
}}
