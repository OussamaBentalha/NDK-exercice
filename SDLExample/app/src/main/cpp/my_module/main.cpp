/**
 * Note: this code has been taken from https://github.com/stephen47/android-sdl2-gradle-template
 */


#include "SDL.h"
#include <android/log.h>
#include <stdio.h>

int main(int argc, char* argv[]) {

    SDL_Window *window;                    // Declare a pointer

    SDL_Init(SDL_INIT_VIDEO);              // Initialize SDL2

    // Create an application window with the following settings:
    window = SDL_CreateWindow(
        "Atelier SDL",                  // window title
        SDL_WINDOWPOS_UNDEFINED,           // initial x position
        SDL_WINDOWPOS_UNDEFINED,           // initial y position
        640,                               // width, in pixels
        480,                               // height, in pixels
        SDL_WINDOW_OPENGL                  // flags - see below
    );

    // Check that the window was successfully created
    if (window == NULL) {
        // In the case that the window could not be made...
        printf("Could not create window: %s\n", SDL_GetError());
        return 1;
    }

    // The window is open: could enter program loop here (see SDL_PollEvent())
    // Setup renderer
    SDL_Renderer* renderer = NULL;
    renderer =  SDL_CreateRenderer( window, -1, SDL_RENDERER_ACCELERATED);

    // Set render color to red ( background will be rendered in this color )
    SDL_SetRenderDrawColor( renderer, 255, 0, 0, 255 );


    // Clear winow
    SDL_RenderClear( renderer );


    // Tracer Cercle Epaix
    SDL_SetRenderDrawColor( renderer, 0, 255, 255, 255 );
    SDL_Rect pixel;
    pixel.w = 10;
    pixel.h = 10;
    int rayon = 100;
    int xcenter = 100;
    int ycenter = 100;

    int x = 0;
    int y = rayon;
    int m = 5 - 4*rayon;
    while(x <= y){
        pixel.x = x + xcenter;
        pixel.y = y + ycenter;
        SDL_RenderFillRect( renderer, &pixel );
        pixel.x = y + xcenter;
        pixel.y = x + ycenter;
        SDL_RenderFillRect( renderer, &pixel );
        pixel.x = - x + xcenter;
        pixel.y = y + ycenter;
        SDL_RenderFillRect( renderer, &pixel );
        pixel.x = - y + xcenter;
        pixel.y = x + ycenter;
        SDL_RenderFillRect( renderer, &pixel );
        pixel.x = x+xcenter;
        pixel.y = -y+ycenter;
        SDL_RenderFillRect( renderer, &pixel );
        pixel.x = y+xcenter;
        pixel.y = -x+ycenter;
        SDL_RenderFillRect( renderer, &pixel );
        pixel.x = -x+xcenter;
        pixel.y = -y+ycenter;
        SDL_RenderFillRect( renderer, &pixel );
        pixel.x = -y+xcenter;
        pixel.y = -x+ycenter;
        SDL_RenderFillRect( renderer, &pixel );
        if(m>0){
            y = y - 1;
            m = m - 8*y;
        }
        x = x + 1;
        m = m + 8*x + 4;
    }

    // Void Tracer Cercle Pixel
    SDL_SetRenderDrawColor( renderer, 255, 255, 255, 0 );
    rayon = 200;
    xcenter = 500;
    ycenter = 500;

    x = 0;
    y = rayon;
    m = 5 - 4*rayon;
    while(x <= y){
        SDL_RenderDrawPoint( renderer, x+xcenter, y+ycenter);
        SDL_RenderDrawPoint( renderer, y+xcenter, x+ycenter);
        SDL_RenderDrawPoint( renderer, -x+xcenter, y+ycenter);
        SDL_RenderDrawPoint( renderer, -y+xcenter, x+ycenter);
        SDL_RenderDrawPoint( renderer, x+xcenter, -y+ycenter);
        SDL_RenderDrawPoint( renderer, y+xcenter, -x+ycenter);
        SDL_RenderDrawPoint( renderer, -x+xcenter, -y+ycenter);
        SDL_RenderDrawPoint( renderer, -y+xcenter, -x+ycenter);
        if(m>0){
            y = y - 1;
            m = m - 8*y;
        }
        x = x + 1;
        m = m + 8*x + 4;
    }


    // Creat a rect at pos ( 50, 50 ) that's 50 pixels wide and 50 pixels high.
    SDL_Rect r;
    r.x = 1000;
    r.y = 1000;
    r.w = 50;
    r.h = 50;

    // Set render color to blue ( rect will be rendered in this color )
    SDL_SetRenderDrawColor( renderer, 0, 0, 255, 255 );

    // Render rect
    SDL_RenderFillRect( renderer, &r );


    //EVENEMENT CLIQUE
    SDL_Event event;
    if ( SDL_PollEvent(&event) ){
        SDL_Log("-----   EVENT ---------------");
        switch(event.type)
        {
            case SDL_FINGERMOTION:
                SDL_Log("-----   SDL FINGER MOTION ---------------");
                /*SDL_Log("FINGER MOTION");
                r.x = event.motion.x;
                r.y = event.motion.y;
                SDL_RenderFillRect( renderer, &r );*/
                break;
            case SDL_FINGERDOWN:
                SDL_Log("-----   SDL FINGER DOWN ---------------");
                break;
            case SDL_FINGERUP:
                SDL_Log("-----   SDL FINGER UP ---------------");
                break;
            case SDL_MOUSEMOTION:
                SDL_Log("-----   SDL MOUSE MOTION ---------------");
                break;
            case SDL_MOUSEBUTTONDOWN:
                SDL_Log("-----   SDL_MOUSE BUTTON DOWN ---------------");
                break;
            case SDL_MOUSEBUTTONUP:
                SDL_Log("-----   SDL_MOUSE BUTTON UP ---------------");
                break;
            case SDL_KEYDOWN:
                SDL_Log("-----   SDL_KEYDOWN BUTTON DOWN ---------------");
                break;
        }
    }

    // Render the rect to the screen
    SDL_RenderPresent(renderer);

    SDL_Delay(80000);  // Pause execution for 3000 milliseconds, for example

    // Close and destroy the window
    SDL_DestroyWindow(window);

    // Clean up
    SDL_Quit();
    return 0;
}

void traceCerclePixel (int rayon, int xcenter, int ycenter){

}