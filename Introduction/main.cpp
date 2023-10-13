#include <SDL2/SDL.h>
#include <stdio.h>

#define SCREEN_WIDTH 1080
#define SCREEN_HEIGHT 520

int main(int argc, char **argv)
{
    // Initialize SDL with video support
    if (SDL_Init(SDL_INIT_VIDEO) < 0)
    {
        printf("Error: SDL failed to initialize\nSDL Error: '%s'\n", SDL_GetError());
        return 1;
    }

    // Create an SDL window
    SDL_Window *window = SDL_CreateWindow("SDL Introduction", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, SCREEN_WIDTH, SCREEN_HEIGHT, 0);
    if (!window)
    {
        printf("Error: Failed to open window\nSDL Error: '%s'\n", SDL_GetError());
        return 1;
    }

    // Create an SDL renderer for rendering graphics in the window
    SDL_Renderer *renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);
    if (!renderer)
    {
        printf("Error: Failed to create renderer\nSDL Error: '%s'\n", SDL_GetError());
        return 1;
    }

    // The game loop control variable
    bool running = true;

    // Game loop: keep the application running until 'running' is set to false
    while (running)
    {
        // Poll SDL events (e.g., window close)
        SDL_Event event;
        while (SDL_PollEvent(&event))
        {
            switch (event.type)
            {
            case SDL_QUIT:
                running = false; // Exit the game loop
                break;

            default:
                break;
            }
        }

        // Set the render draw color (R, G, B, A)
        SDL_SetRenderDrawColor(renderer, 10, 20, 205, 255);

        // Clear the renderer with the specified draw color
        SDL_RenderClear(renderer);

        // Present the renderer (draw the frame to the window)
        SDL_RenderPresent(renderer);
    }

    // Clean up and exit the application
    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    SDL_Quit();

    return 0;
}