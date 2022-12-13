digito [0-9]
%{
    int conta = 0 ;
%}
%%
{digito}+       conta++;
.               ;
\n              ;
%%
int yywrao() {return 1;}
int main (){
    yylex();
    printf("A qtdade de numeros e: %d\n");
}
