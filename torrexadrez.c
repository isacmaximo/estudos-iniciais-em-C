#include <stdio.h>
int main(){
	int coluna, linha, contado1, contador2;
	printf("Coordenada iniciais: ");
	scanf("%d,%d",&coluna,&linha); 						//coordenada: coluna,linha

	printf("Posições possíveis: ");
	for (contado1 = 1; contado1 <= 8; contado1++){    	//contador1 vai de 1 até 8
		if (contado1 == linha)     						// se o contador for igual a linha ele pula esse valor
			continue;
		printf( "(%d,%d),", coluna,contado1); 			// todas as linhas possíveis em relação a coluna
	} 

	for (contador2 = 1; contador2 <= 8; contador2++){   //contador2 vai de 1 até 8
		if (contador2 == coluna)     				  	// se o contador for igual a coluna ele pula esse valor
			continue;
		printf("(%d,%d)", contador2, linha);		  	//todas colunas possíveis em relação a linha
		if (contador2 == 8)                           	// estabelece a quantidade de vírgulas
			break;
		printf(",");
	}
	return 0;
}
