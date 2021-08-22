#include <stdio.h>
#include <stdlib.h>

typedef struct pilha{
    char caractere; //a pilha recebe valores do tipo caractere (char)
    struct pilha *proximo;
    struct pilha *anterior;
}Pilha;

Pilha *inicio = NULL; //definindo o topo da pilha
int tamanho = 0;

void adcionar(char caractere){
    
    //alocação de memória 
    Pilha *novo = malloc(sizeof(Pilha));
    novo->caractere = caractere;
    novo->proximo = NULL;
    novo->anterior = NULL;
    
    // se a pilha estiver vazia
    if (inicio == NULL){
        inicio = novo; 
    }

    //se já tiver algum ítem
    else{ 
        novo->proximo = inicio;
        inicio->anterior = novo;
        inicio = novo;
    }
    tamanho++;

}


void remover(){
    
    if (inicio != NULL){
         
        Pilha *lixo = inicio; //lixo criado
        
        if (tamanho == 1){ //se tiver apenas um elemento
            inicio = NULL;
        }
        else{ //se tiver mais de um elemento
            inicio = inicio->proximo;
            inicio->anterior = NULL;
        }
        free(lixo);
        tamanho--;
    }
    else{
        printf("\nA pilha está vazia!\n");
    }  
}

void imprimir(){
    Pilha *auxiliar = inicio;
    int i;
    for (i = 0; i < tamanho; i++){
        printf("Resultado: %d\n", auxiliar->caractere - '0'); //imprimindo o resultado da forma inteiro (int)
        auxiliar = auxiliar->proximo;
    }
}

void calcular(char *expressao){ //função calcular que vai receber uma string que nada mais é que um vetor de caracteres
    int i;
    int te = strlen(expressao); //vai definir o tamanho da expressão recebida 
    for (i = 0; i < te; i++){
        char aux = expressao[i]; //  vai representar cada caractere em sequência

        adcionar(aux); //vai adcionar cada caractere na lista
        
        //==> explicação dos if e if else a seguir
        //se o caractere que está no  topo da pilha (inicio) é um operador (+-/*)...
        //vai remover o operador do topo
        //vai guardar o novo topo que vai ser um número
        //vai remover o  topo novamente
        //vai guardar o novo topo que vai ser um número
        //vai remover o topo novamente (aqui a pilha estará vazia)
        //irá realizar a operação com os números guardados conforme a opeção
        //irá guardar o resultado da operação na pilha

        //obs: quando subtrai o carctere '0' de um char ele vira  int, e quando é somado um int ao caractere '0' ele vira um char 


        if (inicio->caractere == '+'){ 
            remover();
            int aux1 = inicio->caractere - '0';
            remover();
            int aux2 = inicio->caractere - '0';
            remover();
            int soma = aux2 + aux1;
            adcionar(soma + '0');
        }
        else if(inicio->caractere == '-'){
            remover();
            int aux1 = inicio->caractere - '0';
            remover();
            int aux2 = inicio->caractere - '0';
            remover();
            int sub = aux2 - aux1;
            adcionar(sub + '0');
        }
        else if(inicio->caractere == '/'){
            remover();
            int aux1 = inicio->caractere - '0';
            remover();
            int aux2 = inicio->caractere - '0';
            remover();
            int div = aux2 / aux1;
            adcionar(div + '0');
        }
        else if(inicio->caractere == '*'){
            remover();
            int aux1 = inicio->caractere - '0';
            remover();
            int aux2 = inicio->caractere - '0';
            remover();
            int mult = aux2 * aux1;
            adcionar(mult + '0');
        }
        

    }
      
    
}


int main(){
    //alguns exemplos usados
    calcular("12+53-*"); 
    imprimir();
    remover(); //usado para zerar a pilha e fazer uma nova operação 
    calcular("12-45+*");
    imprimir();


    return 0;
}
