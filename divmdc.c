#include <stdio.h>
int main(){
	int num1, num2, divisores, divisores1, divisores2, tamanho1, tamanho2, i;
	int maiorn, menorn, result;


	printf("Digite o 1º número: ");
	scanf("%d",&num1);
	printf("Digite o 2º número: ");
	scanf("%d",&num2);

	tamanho1 = 0;
	tamanho2 = 0;

	for(divisores = 1; divisores < num1; divisores++){
		if (num1 % divisores == 0)
			tamanho1 ++; //vai estabelecer o tamanho do vetor 1
		else if (num2%divisores == 0)
			tamanho2++; //vai estabelecer o tamanho do vetor 2
	}
	
	printf("divisores do número 1: ");
	int div[tamanho1];
	i = 0;
	divisores1 =  1;
	for(divisores1; divisores1 < num1; divisores1++){
		if (num1 % divisores1 == 0){
			div[i] = divisores1;   // a lista vai receber os divisores do primeiro número
			printf("%d ", div[i]);
			i++;
		}
	}

	printf("\ndivisores do número 2: ");
	int div2[tamanho2];
	i  = 0;
	divisores2 = 1;
	for (divisores2; divisores2  < num2; divisores2++){
		if (num2 % divisores2 == 0){
			div2[i] = divisores2;  // a lista vai receber os divisores do segundo número
			printf("%d ", div2[i]);
			i++;
		}

	}

	//saber o maior e o menor número
	if (num1 > num2){   
		maiorn =  num1;
		menorn = num2;
	}
	else if (num2 > num1){
		maiorn = num2;
		menorn = num1;
	}
	
	result = maiorn % menorn;
	
	// descobrindo o mdc pelo processo das divisões sucessivas
	while(1){
		if (result == 0){
			printf("\nMaior Divisor Comum: %d", menorn);
			break;
		}
		else if(result != 0){
			maiorn = menorn;
			menorn = result;
		}
		result = maiorn % menorn;
		
	}
	

	return 0;
}