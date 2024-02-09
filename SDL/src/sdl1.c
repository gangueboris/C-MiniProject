#include <stdlib.h>
# include <stdio.h>
#include <SDL/SDL.h>
#define WIDTH 640
#define HIGH 480

int main(int argc, char**argv){
    if(SDL_Init(SDL_INIT_VIDEO) == -1){
        fprintf(stderr,"Error: Initialisation failed!!%s\n",SDL_GetError());
        exit(EXIT_FAILURE);
    }
    // main window
    SDL_Surface* screen = NULL;
    screen =  SDL_SetVideoMode(WIDTH, HIGH, 32, SDL_HWSURFACE);
    if(screen == NULL){
        fprintf(stderr,"Error: Impossible to load video!!%s\n",SDL_GetError());
        exit(EXIT_FAILURE);
    }
    //title of my window
    SDL_WM_SetCaption("My first window !!", NULL);
    // Background color 
    SDL_FillRect(screen, NULL,0x1ED760);
    //SDL_FillRect(screen, NULL, SDL_MapRGB(screen->format,255, 255, 0));
    SDL_Flip(screen); // Utilisez SDL_Flip pour mettre à jour l'écran

    //Handle event 
    int temp = 1;
    SDL_Event event;
    while(temp){
        SDL_WaitEvent(&event); // Waiting for an event
        switch (event.type)
        {
        case SDL_QUIT:
        temp = 0;  
            break;
        
        default:
            break;
        }

    }




    SDL_Quit();
    return EXIT_SUCCESS;
}