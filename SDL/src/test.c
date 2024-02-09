#include <SDL/SDL.h>
#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <time.h>

//Screen dimension constants
const int WIDTH = 1000;
const int HEIGHT = 600;
const int SIZE = 500;

SDL_Surface *screen = NULL;
SDL_Event event;
bool quit = false;

void GenerateArray(int arr[]);
void Swap(int arr[], int i, int j);
void SelectionSort(int arr[]);
void draw(int arr[], int i, int j);

void setup() {
    // Initialize SDL
    if (SDL_Init(SDL_INIT_VIDEO) < 0) {
        fprintf(stderr, "SDL could not initialize! SDL_Error: %s\n", SDL_GetError());
        exit(1);
    }

    // Set up the screen surface
    screen = SDL_SetVideoMode(WIDTH, HEIGHT, 32, SDL_HWSURFACE | SDL_DOUBLEBUF);
    if (screen == NULL) {
        fprintf(stderr, "SDL_SetVideoMode failed! SDL_Error: %s\n", SDL_GetError());
        exit(1);
    }

    SDL_WM_SetCaption("Selection Sort", NULL);
}

bool processEvent() {
    while (SDL_PollEvent(&event)) {
        if (event.type == SDL_QUIT)
            return true;
        else if (event.type == SDL_KEYDOWN && event.key.keysym.sym == SDLK_ESCAPE)
            return true;
    }
    return false;
}

void GenerateArray(int arr[]) {
    srand(time(NULL));
    for (int i = 0; i < SIZE; i++) {
        arr[i] = 1 + rand() % HEIGHT;
    }
}

void Swap(int arr[], int i, int j) {
    int temp = arr[i];
    arr[i] = arr[j];
    arr[j] = temp;
}

void SelectionSort(int arr[]) {
    int i, j, index;

    for (i = 0; i < SIZE - 1; i++) {
        index = i;
        for (j = i + 1; j < SIZE; j++) {
            if (arr[j] < arr[index]) {
                index = j;
            }
        }
        draw(arr, i, index);
        Swap(arr, i, index);
        SDL_Delay(5);
    }
}

void draw(int arr[], int i, int j) {
    SDL_Rect rect;

    SDL_FillRect(screen, NULL, SDL_MapRGB(screen->format, 255, 255, 255)); // Clear the screen

    rect.x = j * WIDTH / SIZE;
    rect.y = HEIGHT - arr[j];
    rect.w = WIDTH / SIZE;
    rect.h = arr[j];
    SDL_FillRect(screen, &rect, SDL_MapRGB(screen->format, 0, 0, 255));

    rect.x = j * WIDTH / SIZE;
    rect.y = HEIGHT - arr[i];
    rect.w = WIDTH / SIZE;
    rect.h = arr[i];
    SDL_FillRect(screen, &rect, SDL_MapRGB(screen->format, 255, 165, 0));

    rect.x = i * WIDTH / SIZE;
    rect.y = HEIGHT - arr[i];
    rect.w = WIDTH / SIZE;
    rect.h = arr[i];
    SDL_FillRect(screen, &rect, SDL_MapRGB(screen->format, 0, 0, 255));

    rect.x = i * WIDTH / SIZE;
    rect.y = HEIGHT - arr[j];
    rect.w = WIDTH / SIZE;
    rect.h = arr[j];
    SDL_FillRect(screen, &rect, SDL_MapRGB(screen->format, 255, 255, 255));

    SDL_Flip(screen);
}

int main(int argc, char *args[]) {
    int arr[SIZE];

    setup();
    GenerateArray(arr);

    for (int i = 0; i < SIZE; i++) {
        draw(arr, i, i);
        SDL_Delay(5);
    }

    SDL_Delay(1000); // Delay before sorting
    SelectionSort(arr);

    while (!quit) {
        quit = processEvent();
    }

    SDL_Quit();
    return 0;
}
