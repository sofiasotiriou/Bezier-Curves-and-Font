# Bezier-Curves-and-Font
Created by: Sofia Sotiriou and Antonella Mele 
Done during Advanced Programming and Project at the École nationale supérieure d'informatique pour l'industrie et l'entreprise

## Description 

A C++ program that creates and displays the english alphabet (uppercase and sans-serif) in three different policies: 
- Policy 1: Drawing the outline of each letter in black on a white background on a bitmap.
- Policy 2: Filling the letters in black.
- Policy 3: Adding a red border to the previous version.

The creation of all three policies is done with Bezier curves, which are implemented using the deCasteljau algorithm, a recursive algorithm which performs a series of interpolations between a number of points to produce a straight line or a curve. 

The visualization of the three policies is achieved with the use of th SDL library, which creates a graphical window containing all three policies. 

## Project structure 

Each policy is represented by a collection of points and lines stored in a three-dimensional vector. The vector contains two-dimensional vectors which each represent a letter to be drawn and each ”letter” contains all the points that make up its lines or curves. 

![Diagram](https://github.com/user-attachments/assets/d5d1f30c-ef01-470f-b478-a6e14f828437)

##### Notes on the diagram
- In the class Trace instead of putting all 26 vectors for the first alphabet and all 26 for the third thus reducing the readability of the diagram, (letter)1 and (letter)3 were used as placeholders for all those vectors instead.
- In a similar fashion, in the class Filling, instead of putting all the function that create a letter (createA, createB createC etc.), only createA and createN were named, as they have a single position offset as a parameter (because they are the first on their line, so one of their offsets was input manually, while for the rest of the letters it is calculated from the previous letter), and for the rest of the letters that have the same function signature, create(letter) was used.

## Final Result 

![Result](https://github.com/user-attachments/assets/13d535c5-1d8d-481d-a2fb-cd887ae28715)


### Note 

The program was tested on both a Windows and an UNIX-based environment and it was found that in order to run on windows the main() method in 'main.cpp" needed to be named WinMain() while in the UNIX based environment main() runned normally. 
