#ifndef ALPHABET_H
#define ALPHABET_H 

#include <vector>
#include "DeCasteljau.h"
using namespace std;

/**
* @class Alphabet
* @brief Parent class for Trace and Filling
*/
struct Alphabet {

    /**
    * @brief Default Constructor for class Alphabet
    */
    Alphabet() = default;

    /** @var vector<<vector<vector<double>>> letters
     *  Contains the points to be drawn for a full alphabet (filled or traced)
     */
    vector<vector<vector<double>>> letters;
    /**
    * @brief Produces all the points for the traced version of the alphabet
    * @param x Distinguishes between the two alphabets that need to be traced/filled
    */
    virtual void generateAlphabet(int x) = 0;

    /**
    * @brief Default Destructor for class Alphabet
    */
    virtual ~Alphabet() {};

protected: 
    vector<vector<double>> results;
};

#endif // ALPHABET_H