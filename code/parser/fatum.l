%{
    #include "y.tab.h"
    #include <string.h>

    void yyerror(char* s);
%}

%%
"Bazinga!"                  {return BAZINGA;}
("My name is ")[a-zA-Z]+    {    
                                //printf("Caracter:%s\n",yytext+11);
                                 yylval.name=strdup(yytext+11);
                                 return ADVENTURER_NAME;
                            }
\n                          ;
.                           {yyerror("Syntax error.");exit(-1);}
%%