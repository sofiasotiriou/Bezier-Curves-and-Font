#include <SDL2/SDL.h>
#include "Sdl.h"
#include "Trace.h"
#include "Filling.h"
#include <iostream>
#include <vector>
using namespace std;

int main() {
    SDL_Window* window = NULL;
    SDL_Renderer* renderer = NULL;

    if (!init(&window, &renderer)) {
        cerr << "Failed to initialize!" <<endl;
        return -1;
    }

    //create first alphabet
    Trace* alphabet1 = new Trace();
    alphabet1->generateAlphabet(0);
    firstAlphabet(&renderer, alphabet1->letters);

    drawSeparator(&renderer, {0.0, 185.0}, {960.0,185.0});

    //create second alphabet
    Filling* alphabet2 = new Filling();;
    alphabet2->generateAlphabet(0);
    draw(&renderer, alphabet2->letters);

    drawSeparator(&renderer, { 0.0, 365.0 }, { 960.0, 365.0 });

    //create the outline for the third alphabet
    alphabet1->letters.clear();
    alphabet1->generateAlphabet(1);
    SDL_SetRenderDrawColor(renderer, 255, 50, 50, 255);
    draw(&renderer, alphabet1->letters);
    delete alphabet1;

    //create the filling for the third alphabet
    alphabet2->letters.clear();
    alphabet2->generateAlphabet(1);
    SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
    draw(&renderer, alphabet2->letters);
    delete alphabet2;

    wait(&renderer);
    close(&window, &renderer);

    return 0;
}