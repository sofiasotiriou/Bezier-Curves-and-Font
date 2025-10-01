/**
 * @file Sdl.h
 * @brief Header file containing functions for SDL initialization, rendering, and cleanup.
 */
#ifndef SDL_H
#define SDL_H

#include <SDL2/SDL.h>
#include <iostream>
#include <vector>
#include "DeCasteljau.h"
using namespace std;

/**
 * @brief Initializes SDL, creates a window, and a renderer.
 * 
 * @param window A pointer to the SDL_Window object that will be created.
 * @param renderer A pointer to the SDL_Renderer object that will be created.
 * 
 * @return True if initialization succeeds, false otherwise.
 */
bool init(SDL_Window** window, SDL_Renderer** renderer);

/**
*@brief Draws the first alphabet using the provided letters.
*
* @param renderer A pointer to the SDL_Renderer used to draw the points.
* @param letters A 3D vector containing the points for all letters.
*/
void firstAlphabet(SDL_Renderer** renderer, vector<vector<vector<double>>> letters);

/**
 * @brief Draws the provided letters to the screen.
 *
 * @param renderer A pointer to the SDL_Renderer used to draw the points.
 * @param letters A 3D vector containing the points for all letters.
 */
void draw(SDL_Renderer** renderer, vector<vector<vector<double>>> letters);

/**
 * @brief Draws a separator line between two points using linear B�zier interpolation.
 * 
 * @param renderer A pointer to the SDL_Renderer used to draw the line.
 * @param start A vector containing the x and y coordinates of the starting point.
 * @param finish A vector containing the x and y coordinates of the finishing point.
 */
void drawSeparator(SDL_Renderer** renderer, vector<double> start, vector<double> finish);

/**
 * @brief Waits for a quit event to close the window and renderer.
 *
 * @param renderer A pointer to the SDL_Renderer used to present the content.
 */
void wait(SDL_Renderer** renderer);

/**
 * @brief Cleans up SDL resources and closes the window and renderer.
 *
 * @param window A pointer to the SDL_Window to be destroyed.
 * @param renderer A pointer to the SDL_Renderer to be destroyed.
 */
void close(SDL_Window** window, SDL_Renderer** renderer);

#endif