#include <stdio.h>

int main(){
    int iniciar, qtd, maiorn, natual;            //declaração das variáveis

    printf("Digite a quantidade de números: ");   
    scanf("%d",&qtd);                            //quantidade de números

    maiorn = -1;

    for (iniciar = 0; iniciar < qtd; iniciar++){ //a comparação vai ocorrer de 0 até a quantidade determinada
        printf("Digite o número: ");
        scanf("%d",&natual);                     //vai receber um número
        
        if (natual > maiorn) maiorn = natual;    //se o número recebido for maior que o maior número anterior, então ele é o novo maior número
    }

    
    printf("\nMaior número: %d", maiorn);        //ao final o maior número será mostrado

    return 0;
}
