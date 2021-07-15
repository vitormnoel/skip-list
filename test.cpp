#include "skiplist.cpp"
#include <time.h>

int main(void)
{
	clock_t tempo;
	//CRIAÇÃO DA LISTA
    skip_list *sl=create_sl();
	
	int i=1;
	//INSERÇÃO DE 600K NÓS
	for(;i<600000; ++i)
	{
		insert(sl, i, i);
	}
	
	//REMOÇÃO DE 510911 NÓS
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
	
	//LIBERANDO O ESPAÇO UTILIZADO PELA LISTA
	sl_free(sl);
	
/*	CALCULO DE TEMPO GASTO EM UMA EXECUÇÃO
	1. PARA UTILIZAR BASTA COLOCAR ESSE COMANDO ANTES DA EXECUÇÃO DA PARTE QUE DESEJA CALCULAR
	tempo = clock ();
	
	2. AO FIM DA EXECUÇÃO DO BLOCO DESEJADO, DEVE-SE COLOCAR ESSE PARA FINALIZAR A CONTAGEM
	tempo = clock () - tempo;

	3. PRINT DO TEMPO GASTO
	printf("%f", ((float)tempo)/CLOCKS_PER_SEC);
*/    
	return 0;
}
