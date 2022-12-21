// EStrutura da Tabela de SImbolos

#define TAM_TAB 100
#include <ctype.h>
struct elemTabSimbolos{
    char id[100]; // identificador
    int end;      // endereco
    int tip;      // tipo
} tabSimb[TAM_TAB], elemTab;

int posTab = 0;

//funçao para transforma tudo em maiuscula para nao possuir diferenças entre nomes com letras maiusculas e minusculas, em tese nao sera usado mas talvez
void maiuscula(char *s){ 
    for(int i =0; s[i]; i++){
        s[i] = toupper(s[i]);
    }
}

int buscaSimbolo(char *id){
    char msg[200];
    int i;
    //maiuscula(id);
    for (i = posTab -1; strcmp(tabSimb[i].id, id) && i >= 0; i--)
        ;
    if (i == -1)
        sprintf(msg,"Indentificador  [%s] não encontrado", id);
        yyerror(msg);
    return i;
}



void insereSimbolo (struct elemTabSimbolos elem){
    int i;
    char msg[200];
    //maiuscula(elem.id);
    if (posTab == TAM_TAB)
        yyerror("Tabela de Simbolos Cheia!");
    for (i = posTab -1; strcmp(tabSimb[i].id, elem.id) && i >= 0; i--)
        ;
    if (i != -1)
        sprintf(msg, "Indentificador  [%s] não encontrado", elem.id);
        yyerror(msg);
    tabSimb[posTab++] = elem;
}

void mostraTabela(){
    puts("Tabela de Simbolos");
    puts("------------------");
    printf("\n%30s | %s\n", "ID", "END");
    for(int i = 0; i<50; i++)
        printf(".");
    for(int i =0; i < posTab; i++)
        printf("\n%30s | %d\n", tabSimb[i].id, tabSimb[i].end);
    printf("\n");
}

//Estrutura da Pilha Semantica
// usada para enderecos, variaveis e rotulos

#define TAM_PIL 100
int topo = -1;
int pilha[TAM_PIL];

void empilha (int valor){
    if(topo == TAM_PIL)
        yyerror("Pilha semântica cheia!");
    pilha[++topo] = valor;
}

int desempilha(){
    if(topo == -1){
        yyerror("Pilha semântica vazia!");
    }
    return pilha[topo--];
}
