#include "skiplist.cpp"
#include <time.h>

int main(void)
{
	clock_t tempo;
	//CRIA��O DA LISTA
    skip_list *sl=create_sl();
	
	int i=1;
	//INSER��O DE 600K N�S
	for(;i<600000; ++i)
	{
		insert(sl, i, i);
	}
	
	//REMO��O DE 510911 N�S
	for(i=20; i<510911; ++i)
	{
		if(!erase(sl, i))
			printf("!!!\n");
	}

	//PRINT DA LISTA COM SUAS CAMADAS
	print_sl(sl);
	
	//PESQUISA POR VALOR
	int *p=search(sl, 18);
	
	if(p){
		printf("\n\n>>>>valor %d encontrado\n", *p);
	}else if(p == NULL){
		printf("\n\n>>>>valor nao encontrado");
	}
	
	//LIBERANDO O ESPA�O UTILIZADO PELA LISTA
	sl_free(sl);
	
/*	CALCULO DE TEMPO GASTO EM UMA EXECU��O
	1. PARA UTILIZAR BASTA COLOCAR ESSE COMANDO ANTES DA EXECU��O DA PARTE QUE DESEJA CALCULAR
	tempo = clock ();
	
	2. AO FIM DA EXECU��O DO BLOCO DESEJADO, DEVE-SE COLOCAR ESSE PARA FINALIZAR A CONTAGEM
	tempo = clock () - tempo;

	3. PRINT DO TEMPO GASTO
	printf("%f", ((float)tempo)/CLOCKS_PER_SEC);
*/    
	return 0;
}
