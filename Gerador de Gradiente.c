#include <stdio.h>
#include <stdlib.h>


#define HEIGHT 256
#define WIDTH 256
#define MaxCol 255

void GerarGMP(const char* filename)
{
    int vI;
    int vF;

    int vrI;
    int vrF;

    int aI;
    int aF;

    printf("Para gerar um gradiente, escolha em ordem a mudança de intensidade das Cores Vermelho, Verde e Azul.\n\nPara gerar o Branco coloque todas as cores no limite de intensidade (255)\n\nPara gerar o Preto coloque todas as cores no mínimo de intensidade(0)\n");

    printf("\nInsira a Instensidade do Vermelho Inicialmente (0 a 255):\n");
    scanf("%d", &vI);
    printf("\nInsira a Instensidade do Vermelho ao Final (0 a 255):\n");
    scanf("%d", &vF);

    printf("\nInsira a Instensidade do Verde Inicialmente (0 a 255):\n");
    scanf("%d", &vrI);
    printf("\nInsira a Instensidade do Verde ao Final (0 a 255):\n");
    scanf("%d", &vrF);

    printf("\nInsira a Instensidade do Azul Inicialmente (0 a 255):\n");
    scanf("%d", &aI);
    printf("\nInsira a Instensidade do Azul ao Final (0 a 255):\n");
    scanf("%d", &aF);

    FILE *f = fopen("C:\\Users\\pietr\\Coisas do C\\Gradiente Gerado.bmp", "wb");
    if(!f) return;

    unsigned char header[54]=
    {
        'B', 'M',
        0,0,0,0,            // Tamanho do arquivo (será preenchido)
        0,0,0,0,            // Reservado
        54,0,0,0,           // Offset onde começam os pixels
        40,0,0,0,           // Tamanho do cabeçalho da imagem
        0,0,0,0,            // Largura (preenchido abaixo)
        0,0,0,0,            // Altura (preenchido abaixo)
        1,0,                // Planos (sempre 1)
        24,0,               // Bits por pixel (24 bits = RGB)
        0,0,0,0, 0,0,0,0, 0,0,0,0, 0,0,0,0, 0,0,0,0, 0,0,0,0 // Outros campos zerados
    };
        header[18] = WIDTH & 0xFF; header[19] = (WIDTH >> 8) & 0xFF;
        header[22] = HEIGHT & 0xFF; header[23] = (HEIGHT >> 8) & 0xFF;

        //Isso aq foi tudo IA//

        fwrite (header, 1, 54, f);
       
        for (int y = 0; y < 256; y++)
    {
        for (int x = 0; x < 256; x++)
        {
         float t = (float)x/ (WIDTH -1 );

            unsigned char r = (unsigned char)(vI * (1 - t) + vF * t);
            unsigned char g = (unsigned char)(vrI * (1 - t) + vrF * t);
            unsigned char b = (unsigned char)(aI * (1 - t) + aF * t);        

            fputc(b, f);
            fputc(g, f);
            fputc(r, f);
        }       
    }
     fclose (f);
}
    
int main()
{ 
    GerarGMP("Gradiente.bmp");
    printf("Seu Gradiente foi Criado!");
    return 0;
}
