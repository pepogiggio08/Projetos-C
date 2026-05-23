#include <stdio.h>
#include <stdlib.h>

typedef struct {
    float *itens;
    size_t count;
    size_t capacity;
} Numbers;

#define Da_Append(xs, x)\
 do{\
        if (xs.count >= xs.capacity) {\
            if (xs.capacity == 0) xs.capacity = 256;\
            else xs.capacity *= 2;\
            xs.itens = realloc(xs.itens, xs.capacity * sizeof(xs.itens));\
        }\
        xs.itens[xs.count++] = x;\
 }while (0)
 
 
int main(void) {
    
    
   
    Numbers xs = {0};
    for (int x = 0; x < 10; x++) 
    {
        Da_Append(xs, x);
    }
    for (size_t i = 0; i < xs.count; i++) 
    {
        printf("%f\n", xs.itens[i]);
    }

    free(xs.itens);
    return 0;
}
