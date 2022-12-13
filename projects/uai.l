%%
#[a-z0-9A-Z]*  ECHO;
.                  ;
\n                 ;
%%

int yywrap() {return 1;}
int main () {yylax();}