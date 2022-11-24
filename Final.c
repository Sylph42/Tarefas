//MATRÍCULA: 20221045050036
//NOME: Ana Késia Araújo Gomes
//USUÁRIO: Sylph42

// permitir que o usuário especifique um valor/ativo
// procurar 2,10,11,12,13 dos derivativos
// gerar um arquivo que printe essas partes de todos os arquivos que cumpram as condições.

#include <stdio.h>
#include <cs50.h>
#include <string.h>
#include <stdlib.h>

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

void split1(char *line){
  
    //data
    char *token = strtok(line, ";");
    //printf(" %-2s |", token);
     char* data = token;
    char *tok[52];

    for(int i = 0; i != 51; i++){
        token = strtok(NULL, ";");
      //printf(" %s " , token);
     tok[i] = token;
    }

printf(" %-2s |", data);
//cod
     if(tok[0]!=NULL){
printf(" %-2s |" , tok[0]);
}
//codigoMenor
if(tok[1]!=NULL){
printf(" %-2s |" , tok[1]);
}
//dataVencimento
if(tok[6]!=NULL){
printf(" %5s |" , tok[6]);
}
//preço
if(tok[15]!=NULL){
    replace(tok[15],',','.');
printf(" %5s |" , tok[15]);
}

//moeda
if(tok[13]!=NULL){
printf(" %-2s |" , tok[13]);
}
//num
if(tok[34]!=NULL){
printf(" %5s |" , tok[34]);
}

//outro arquivo
if(tok[8]!=NULL){
printf(" %-2s |" , tok[8]);
}

if(tok[9]!=NULL){
printf(" %5s |" , tok[9]);
}

   if(tok[10]!=NULL){
printf(" %5s |", tok[10]);
}

   if(tok[11]!=NULL){
printf(" %5s |\n ", tok[11]);
}
   }

void split2(char *line){

    FILE *ArqResultante = fopen("ResultadosDaB3.csv", "w");
  
    //data
    char *token = strtok(line, ";");
    fprintf(ArqResultante," %s |", token);
    char* data = token;
    char *tok[52];

    for(int i = 0; i != 51; i++){
        token = strtok(NULL, ";");
      //printf(" %s " , token);
     tok[i] = token;
}
//cod

fprintf(ArqResultante, " %-2s |", data);

     if(tok[0]!=NULL){
fprintf(ArqResultante," %s |" , tok[0]);
}
//codigoMenor
if(tok[1]!=NULL){
fprintf(ArqResultante, " %s |" , tok[1]);
}
//dataVencimento
if(tok[6]!=NULL){
fprintf(ArqResultante," %s |" , tok[6]);
}

//num
if(tok[34]!=NULL){
fprintf(ArqResultante," %s |" , tok[34]);
}

//preço
if(tok[15]!=NULL){
fprintf(ArqResultante, " %s |" , tok[15]);
}

//moeda
if(tok[13]!=NULL){
fprintf(ArqResultante," %s |" , tok[13]);
}

//outro arquivo
if(tok[8]!=NULL){
fprintf(ArqResultante," %s |" , tok[8]);
}

if(tok[9]!=NULL){
fprintf(ArqResultante," %s |" , tok[9]);
}

  if(tok[10]!=NULL){
fprintf(ArqResultante," %s |", tok[10]);
}

  if(tok[11]!=NULL){
fprintf(ArqResultante," %s |\n ", tok[11]);
}

}

char* readline(FILE *data){
    int size = 10;
    char *line = malloc(sizeof(char) * size);
    int i = 0;
    do{
        fread(&line[i], sizeof(char), 1, data);
        i++;
        if( i == size ){
            size += 50;
            line = realloc(line, sizeof(char) * size);
        }
    }while( line[i-1] != '\n' && line[i-1] != '\r'  && line[i-1] != EOF );

    line[i] = '\0';
    return line;
}

int main(int argc, char **argv){
    FILE *arquivo = fopen(argv[1], "r");

  char *line = readline(arquivo);

    int o, b;

// printf("Como você quer pesquisar no arquivo?\n");
// printf("1 - Valor | 2 - Ativo \n");
scanf("%i", &o);
  
 switch(o){
    case 1:
// printf ("Qual o valor mínimo dos ativos que deseja procurar?\n");
// scanf("%i", &b);

for(int i = 0; i <53000 ; i++){
 line = readline(arquivo);
  // //printf("%s\n", line);

   split1(line);

}
    break;

    case 2:
// printf ("Qual  ativo deseja procurar?\n");
// scanf("%i", &b);
     
for(int i = 0; i <53000 ; i++){
 line = readline(arquivo);
  ////printf("%s\n", line);

   split2(line);

}
    break;

    default:
    printf("Valor inválido");
    break;
}

}
