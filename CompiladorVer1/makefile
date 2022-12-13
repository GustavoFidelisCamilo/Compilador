lexico: lexico.l prog1.simples;
		flex -o lexico.c lexico.l;\
		gcc lexico.c -o lexico;\
		./lexico < prog1.simples;

limpa: ;
	rm lexico lexico.c;