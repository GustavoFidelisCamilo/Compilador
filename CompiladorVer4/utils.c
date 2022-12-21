#include <ctype.h>

#define TAM_TAB 100


struct elemTabSimbolos {
    char id[100];
    int end;
    int tip;
} tabSimb[TAM_TAB], elemTab;

int posTab = 0; 

void maiscula (char *s) {
    for(int i = 0; s[i]; i++)
        s[i] = toupper(s[i]);
}

int buscaSimbolo(char *id)
{
    int i;
    //maiscula(id);
    for (i = posTab - 1; strcmp(tabSimb[i].id, id) && i >= 0; i--)
        ;
    if (i == -1) {
        char msg[200];
        sprintf(msg, "Identificador [%s] não encontrado!", id);
        yyerror(msg);
    }
    return i;
}
void insereSimbolo (struct elemTabSimbolos elem) {
    int i; 
    //maiscula(elem.id);
    if (posTab == TAM_TAB)
        yyerror("Tabela de Simbolos Cheia!");
    for (i = posTab - 1; strcmp(tabSimb[i].id, elem.id) && i >= 0; i--)
        ;
    if (i != -1) {
        char msg[200];
        sprintf(msg, "Identificador [%s] duplicado!", elem.id);
        yyerror(msg);
    }
    tabSimb[posTab++] = elem; 
}

void mostraTabela () {
    puts("Tabela de Simbolos");
    puts("------------------");
    printf("\n%30s | %s\n", "ID", "END");
    for(int i = 0; i < 50; i++) 
        printf(".");
    for(int i = 0; i < posTab; i++)
        printf("\n%30s | %d\n", tabSimb[i].id, tabSimb[i].end);
    printf("\n");
}

// estrutura da pilha semantica
// usada para enderecos, variaveis, rotulos

#define TAM_PIL 100
int pilha[TAM_PIL];
int topo = -1;

void empilha (int valor) {
    if (topo == TAM_PIL)
        yyerror("Pilha semântica cheia");
    pilha[++topo] = valor;
}

int desempilha() {
    if (topo == -1)
        yyerror("Pilha semântica vazia");
    return pilha[topo--];
}
