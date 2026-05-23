#include <stdio.h>

int main()
{
    setbuf(stdin, NULL);

    int N1;
    int N2;

    char resposta;

    printf("digite o primeiro número:\n");
    scanf("%d", &N1);

    printf("digite o segundo número:\n");
    scanf("%d", &N2);

    int soma;
    soma = N1 + N2;

    int subtração;
    subtração = N1 - N2;

    int multiplicação;
    multiplicação = N1 * N2;

    do{
    printf("digite agora:\n(a para adicão)\n(s para subtração)\n(m para multiplicação)");
    scanf(" %c", &resposta);
    if (resposta != 'a' && resposta != 's' && resposta != 'm')
    {
        printf("\nResposta Inválida!");
    }
    }while (resposta != 'a' && resposta != 's' && resposta != 'm');
    
    if(resposta == 'a')
    {
        printf("A soma é = %d", soma);
    }

    if (resposta == 's')
    {
        printf("A subtração é = %d", subtração);
    }
    
    if (resposta == 'm')
    {
        printf("A multiplicação é = %d", multiplicação);
    }

    setbuf(stdin, NULL);
    return 0;
}