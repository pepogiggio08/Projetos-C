#include <stdio.h>
void averiguar()
{  
char resposta;
char resposta2;
char resposta3;

char afirm1[200];
char afirm2[200];
char af3tipo;
char afirm3[200];

printf("Bem Vindo ao Aristóteles, um algoritmo que verifica a verdade de uma afirmação a partir da outra!\n");
printf("Para averiguarmos, insira três afirmações, duas afirmações devem ser conhecidas e é necessário dizer se ela é dada como verdadeira, falsa ou indeterminada.\n");
printf("O Algoritmo descobrirá qual é a afirmação indeterminada a partir das declarações anteriores.\n\nAVISO: Infelizmente, devido a possíveis ambiguidades nas conjecturas lógicas, nem todos os casos poderão ser determinados pelo algoritmo\n\n\n");
printf("Insira sua primeira afirmação:\n");

setbuf (stdin, NULL);
fgets(afirm3, 200, stdin);
do{
printf("\nEssa afirmação é verdadeira? (digite v para verdadeiro, f para falsa e i para indeterminada, os caracteres devem estar em minúsculo)", afirm1);
scanf(" %c", &resposta);
if(resposta != 'v' && resposta != 'f' && resposta != 'i')
{
printf("\nResposta Inválida!\n");
}
}while(resposta != 'v' && resposta != 'f' && resposta != 'i');


printf("\nInsira sua segunda afirmação:\n");

setbuf (stdin, NULL);
fgets(afirm2, 200, stdin);
do{
printf("\nEssa afirmação é verdadeira? (digite v para verdadeiro, f para falsa e i para indeterminada, os caracteres devem estar em minúsculo)", afirm1);
scanf(" %c", &resposta2);
if(resposta2 != 'v' && resposta2 != 'f' && resposta2 != 'i')
{
printf("\nResposta Inválida!\n");
}
}while(resposta2 != 'v' && resposta2 != 'f' && resposta2 != 'i');

printf("\nInsira sua terceira afirmação(deve ser uma soma ou disjunção das anteriores):\n");
setbuf(stdin, NULL);
fgets(afirm3, 200, stdin); 

printf("A terceira afirmação é uma:\nConjunção das anteriores(digite c)\nDisjunção das anteriores(digite d)\n");

do{
scanf(" %c", &af3tipo);
if(af3tipo != 'c' && af3tipo != 'd')
{
printf("\nResposta Inválida!\n");
}
}while(af3tipo != 'c' && af3tipo != 'd');

do{
printf("\nEssa afirmação é verdadeira? (digite v para verdadeiro, f para falsa e i para indeterminada, os caracteres devem estar em minúsculo)", afirm1);
scanf(" %c", &resposta3);
if(resposta3 != 'v' && resposta3 != 'f' && resposta3 != 'i')
{
printf("\nResposta Inválida!\n");
}
}while(resposta3 != 'v' && resposta3 != 'f' && resposta3 != 'i');


//Essa parte aqui debaixo foi do gemini porque eu fiquei de saco cheio de reescrever tudo depois
//q eu descobri q não tem o operador !==//

  if(resposta == 'i') 
    {
        if(af3tipo == 'c' && resposta2 == 'v' && resposta3 == 'v') {
            printf("\nA afirmação 1 é verdadeira!");
        }
        else if(af3tipo == 'c' && resposta2 == 'f' && resposta3 == 'f') {
            printf("\nA afirmação 1 é falsa!");
        }
        else if(af3tipo == 'd' && resposta2 == 'f' && resposta3 == 'v') {
            printf("\nA afirmação 1 é verdadeira!");
        }
        else if(af3tipo == 'd' && resposta2 == 'f' && resposta3 == 'f') {
            printf("\nA afirmação 1 é falsa!");
        }
        else {
            printf("\nNão é possível determinar :(");
        }
    }    
    else if(resposta2 == 'i') 
    {
        if(af3tipo == 'c' && resposta == 'v' && resposta3 == 'v') {
            printf("\nA afirmação 2 é verdadeira!");
        }
        else if(af3tipo == 'c' && resposta == 'f' && resposta3 == 'f') {
            printf("\nA afirmação 2 é falsa!");
        }
        else if(af3tipo == 'd' && resposta == 'f' && resposta3 == 'v') {
            printf("\nA afirmação 2 é verdadeira!");
        }
        else {
            printf("\nNão é possível determinar :(");
        }
    }
    else if(resposta3 == 'i') 
    {
        if(af3tipo == 'c' && resposta == 'v' && resposta2 == 'v') {
            printf("\nA afirmação 3 é verdadeira!");
        }
        else if(af3tipo == 'c' && (resposta == 'f' || resposta2 == 'f')) {
            printf("\nA afirmação 3 é falsa!");
        }
        else if(af3tipo == 'd' && resposta == 'f' && resposta2 == 'f') {
            printf("\nA afirmação 3 é falsa!");
        }
        else if(af3tipo == 'd' && (resposta == 'v' || resposta2 == 'v')) {
            printf("\nA afirmação 3 é verdadeira!");
        }
        else {
            printf("\nNão é possível determinar :(");
        }
    }
}

int main()
{
averiguar();
return 0;
}