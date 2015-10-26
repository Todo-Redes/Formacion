#include <SDL.h>
#include <stdio.h>

/// Dimensiones de la pantalla.
const int SCREEN_WIDTH = 640;
const int SCREEN_HEIGHT = 480;


int main( int argc, char* args[] )
{
	SDL_Window* window = NULL;

	SDL_Surface* screenSurface = NULL;

	if( SDL_Init( SDL_INIT_VIDEO ) < 0 ) {
		printf( "Error: No se puede iniciar SDL." );
	} else {
        /// Ventana principal.
		window = SDL_CreateWindow( "Hola Mundo SDL", SDL_WINDOWPOS_UNDEFINED,
                                  SDL_WINDOWPOS_UNDEFINED, SCREEN_WIDTH,
                                  SCREEN_HEIGHT, SDL_WINDOW_SHOWN );

        screenSurface = SDL_GetWindowSurface( window );

        SDL_FillRect( screenSurface, NULL,
                     SDL_MapRGB( screenSurface->format,
                                0xFF, 0xFF, 0xFF ) );
        SDL_UpdateWindowSurface( window );
        SDL_Delay( 2000 );
	}

	SDL_DestroyWindow( window );

	SDL_Quit();

	return 0;
}

