#include "Sdl.h"

bool init(SDL_Window** window, SDL_Renderer** renderer) {
    if (SDL_Init(SDL_INIT_VIDEO) < 0) {
        std::cerr << "SDL could not initialize! SDL_Error: " << SDL_GetError() << std::endl;
        return false;
    }

    *window = SDL_CreateWindow("SDL Game", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED,
        960, 560, SDL_WINDOW_SHOWN);
    if (*window == NULL) {
        std::cerr << "Window could not be created! SDL_Error: " << SDL_GetError() << std::endl;
        SDL_Quit();
        return false;
    }

    *renderer = SDL_CreateRenderer(*window, -1, SDL_RENDERER_ACCELERATED);
    if (*renderer == NULL) {
        std::cerr << "Renderer could not be created! SDL_Error: " << SDL_GetError() << std::endl;
        SDL_DestroyWindow(*window);
        SDL_Quit();
        return false;
    }

    SDL_SetRenderDrawColor(*renderer, 255, 255, 255, 255); 

    cout << "SDL Initialized Successfully!" << endl;
    SDL_RenderClear(*renderer);
    SDL_SetRenderDrawColor(*renderer, 0, 0, 0, 255);

    return true;
}

void firstAlphabet(SDL_Renderer** renderer, vector<vector<vector<double> > > letters) {
    bool drawWhiteLine = false;

    for (int i = 0; i < 26; ++i) {
        vector<vector<double> > letter = letters[i];
        for (const vector<double>& point : letter) {
            if (point.empty()) {
                drawWhiteLine = true;
                SDL_SetRenderDrawColor(*renderer, 255, 255, 255, 255);
            }
            else if (drawWhiteLine) {
                SDL_Rect rect = { static_cast<int>(point[0]), static_cast<int>(point[1]), 2, 2 };
                SDL_RenderFillRect(*renderer, &rect);
                if (point == letter.back()) {
                    drawWhiteLine = false;
                    SDL_SetRenderDrawColor(*renderer, 0, 0, 0, 255);
                }
            }
            else {
                SDL_Rect rect = { static_cast<int>(point[0]), static_cast<int>(point[1]), 2, 2 };
                SDL_RenderFillRect(*renderer, &rect);
            }
        }
    }
}

void drawSeparator(SDL_Renderer** renderer, vector<double> start, vector<double> finish) {
    vector<vector<double> > line = DeCasteljau::linearBezier(start, finish);
    for (const vector<double>& point : line) {
        SDL_Rect rect = { static_cast<int>(point[0]), static_cast<int>(point[1]), 1, 1 };
        SDL_RenderFillRect(*renderer, &rect);
    }
}

void draw(SDL_Renderer** renderer, vector<vector<vector<double> > > letters) {
    for (int i = 0; i < 26; ++i) {
        vector<vector<double> > letter = letters[i];
        for (const vector<double>& point : letter) {
            SDL_Rect rect = { static_cast<int>(point[0]), static_cast<int>(point[1]), 2, 2 };
            SDL_RenderFillRect(*renderer, &rect);
        }
    }
}

void wait(SDL_Renderer** renderer) {
    SDL_RenderPresent(*renderer);
    bool running = true;
    SDL_Event e;
    while (running) {
        while (SDL_PollEvent(&e) != 0) {
            if (e.type == SDL_QUIT) {
                running = false;
            }
        }
    }
}

void close(SDL_Window** window, SDL_Renderer** renderer) {
    std::cout << "Rendering completed." << std::endl;
    SDL_DestroyRenderer(*renderer);
    SDL_DestroyWindow(*window);
    SDL_Quit();
}