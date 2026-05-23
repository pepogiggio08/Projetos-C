#include <stdio.h>
#include <stdlib.h>
#include <SDL3/SDL.h>
#include <fcntl.h> 
#include <io.h>

int main()
{
SDL_Init(SDL_INIT_VIDEO);
_setmode(_fileno(stdin), _O_BINARY); 
int width, height, maxc, c;
FILE *in = stdin;
char *pthroway = calloc(1000, sizeof(char));

fscanf(in, "%s", pthroway);
while(fgetc(in) != '\n');

c = fgetc(in);
if (c == '#')
{
    while(fgetc(in) != '\n');
}
else
{
    ungetc(c, in);
}
fscanf(in, " %d %d %d", &width, &height, &maxc);

fgetc(in);

printf("width=%d, height=%d", width, height);

SDL_Window *pwindow = SDL_CreateWindow("Image Viewer", width, height, 0);
SDL_Surface *psurface = SDL_GetWindowSurface(pwindow);
SDL_UpdateWindowSurface(pwindow);

const SDL_PixelFormatDetails *formatDetails = SDL_GetPixelFormatDetails(psurface->format);
SDL_Rect pixel = (SDL_Rect){0,0,1,1};
Uint32 color = 0;

for(int y = 0; y < height; y++)
{
    for(int x = 0; x < width; x++)
    {
        Uint8 r, g, b;
        r = fgetc(in);
        g = fgetc(in);
        b = fgetc(in);
        color = SDL_MapRGB(formatDetails, NULL, r, g, b);
        pixel.x = x;
        pixel.y = y;
        SDL_FillSurfaceRect(psurface, &pixel, color);

    }
}
SDL_UpdateWindowSurface(pwindow);

int appruning = 1;
while(appruning)
{
    SDL_Event event;
    while(SDL_PollEvent(&event))
    {
        if(event.type == SDL_EVENT_QUIT)
        {
            appruning = 0;
        }
    }
}
free(pthroway);

return 0;
}