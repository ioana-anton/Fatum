%{
    #include <stdlib.h>
    #include <stdio.h>
    #include "gameplay/colours.h"
    #include "actions.h"

    void yyerror(char* s);
    int yylex();

    

%}

%union{
  char* name;
}

%token BAZINGA  
%token<name> ADVENTURER_NAME

%%
prg: stmt prg
     |
     ;

stmt: BAZINGA {
                exit(CODE_BAZINGA);
              }
      |ADVENTURER_NAME  {
                            //printf("Yac: Adventure name branch!\n");
                            FILE* f = fopen("output.txt","w");
                            fprintf(f,"%s",yylval.name);
                            fclose(f);
                            exit(CODE_ADVENTURER_NAME);
                        }

%%

int main(int argc, char* argv[]){
  printf("%s>> ",KGRN);
  yyparse();
  return 0;
}