#ifndef FILLING_H
#define FILLING_H

#include "Alphabet.h"

/**
 * @class Filling
 * @brief Creates an alphabet with every letter filled 
 */
class Filling : public Alphabet {

    vector<vector<double>> coordinates = {{190.0, 270.0}, {370.0, 450.0}};

public:
    /**
        *@brief Produces every point needed for a filled font
        * @param i Distinguishes between the second and third alphabet
        */
    void generateAlphabet(int x) override;

    /**
        *@brief Creates a filled-in version of A
        * @param offsetY the vertical offset for creating A
        * @return A vector with all the points needed to fill A 
    */
    vector<vector<double>> createA(double offsetY);

    /**
        * @brief Creates a filled-in version of C
        * @param offsetX the horizontal offset for creating B
        * @param offsetY the vertical offset for creating B
        * @return A vector with all the points needed to fill B
    */
    vector<vector<double>> createB(double offsetX, double offsetY);

    /**
    * @brief Creates a filled-in version of C
    * @param offsetX the horizontal offset for creating C
    * @param offsetY the vertical offset for creating C
    * @return A vector with all the points needed to fill C
    */
    vector<vector<double>> createC(double offsetX, double offsetY);

    /**
     * @brief Creates a filled-in version of D
     * @param offsetX the horizontal offset for creating D
     * @param offsetY the vertical offset for creating D
     * @return A vector with all the points needed to fill D
     */
    vector<vector<double>> createD(double offsetX, double offsetY);

    /**
     * @brief Creates a filled-in version of E
     * @param offsetX the horizontal offset for creating E
     * @param offsetY the vertical offset for creating E
     * @return A vector with all the points needed to fill E
     */
    vector<vector<double>> createE(double offsetX, double offsetY);

    /**
     * @brief Creates a filled-in version of F
     * @param offsetX the horizontal offset for creating F
     * @param offsetY the vertical offset for creating F
     * @return A vector with all the points needed to fill F
     */
    vector<vector<double>> createF(double offsetX, double offsetY);

    /**
     * @brief Creates a filled-in version of G
     * @param offsetX the horizontal offset for creating G
     * @param offsetY the vertical offset for creating G
     * @return A vector with all the points needed to fill G
     */
    vector<vector<double>> createG(double offsetX, double offsetY);

    /**
     * @brief Creates a filled-in version of H
     * @param offsetX the horizontal offset for creating H
     * @param offsetY the vertical offset for creating H
     * @return A vector with all the points needed to fill H
     */
    vector<vector<double>> createH(double offsetX, double offsetY);

    /**
     * @brief Creates a filled-in version of I
     * @param offsetX the horizontal offset for creating I
     * @param offsetY the vertical offset for creating I
     * @return A vector with all the points needed to fill I
     */
    vector<vector<double>> createI(double offsetX, double offsetY);

    /**
     * @brief Creates a filled-in version of J
     * @param offsetX the horizontal offset for creating J
     * @param offsetY the vertical offset for creating J
     * @return A vector with all the points needed to fill J
     */
    vector<vector<double>> createJ(double offsetX, double offsetY);

    /**
     * @brief Creates a filled-in version of K
     * @param offsetX the horizontal offset for creating K
     * @param offsetY the vertical offset for creating K
     * @return A vector with all the points needed to fill K
     */
    vector<vector<double>> createK(double offsetX, double offsetY);

    /**
     * @brief Creates a filled-in version of L
     * @param offsetX the horizontal offset for creating L
     * @param offsetY the vertical offset for creating L
     * @return A vector with all the points needed to fill L
     */
    vector<vector<double>> createL(double offsetX, double offsetY);

    /**
     * @brief Creates a filled-in version of M
     * @param offsetX the horizontal offset for creating M
     * @param offsetY the vertical offset for creating M
     * @return A vector with all the points needed to fill M
     */
    vector<vector<double>> createM(double offsetX, double offsetY);

    /**
     * @brief Creates a filled-in version of N
     * @param offsetY the vertical offset for creating N
     * @return A vector with all the points needed to fill N
     */
    vector<vector<double>> createN(double offsetY);

    /**
     * @brief Creates a filled-in version of O
     * @param offsetX the horizontal offset for creating O
     * @param offsetY the vertical offset for creating O
     * @return A vector with all the points needed to fill O
     */
    vector<vector<double>> createO(double offsetX, double offsetY);

    /**
     * @brief Creates a filled-in version of P
     * @param offsetX the horizontal offset for creating P
     * @param offsetY the vertical offset for creating P
     * @return A vector with all the points needed to fill P
     */
    vector<vector<double>> createP(double offsetX, double offsetY);

    /**
     * @brief Creates a filled-in version of Q
     * @param offsetX the horizontal offset for creating Q
     * @param offsetY the vertical offset for creating Q
     * @return A vector with all the points needed to fill Q
     */
    vector<vector<double>> createQ(double offsetX, double offsetY);

    /**
     * @brief Creates a filled-in version of R
     * @param offsetX the horizontal offset for creating R
     * @param offsetY the vertical offset for creating R
     * @return A vector with all the points needed to fill R
     */
    vector<vector<double>> createR(double offsetX, double offsetY);

    /**
     * @brief Creates a filled-in version of S
     * @param offsetX the horizontal offset for creating S
     * @param offsetY the vertical offset for creating S
     * @return A vector with all the points needed to fill S
     */
    vector<vector<double>> createS(double offsetX, double offsetY);

    /**
     * @brief Creates a filled-in version of T
     * @param offsetX the horizontal offset for creating T
     * @param offsetY the vertical offset for creating T
     * @return A vector with all the points needed to fill T
     */
    vector<vector<double>> createT(double offsetX, double offsetY);

    /**
     * @brief Creates a filled-in version of U
     * @param offsetX the horizontal offset for creating U
     * @param offsetY the vertical offset for creating U
     * @return A vector with all the points needed to fill U
     */
    vector<vector<double>> createU(double offsetX, double offsetY);

    /**
     * @brief Creates a filled-in version of V
     * @param offsetX the horizontal offset for creating V
     * @param offsetY the vertical offset for creating V
     * @return A vector with all the points needed to fill V
     */
    vector<vector<double>> createV(double offsetX, double offsetY);

    /**
     * @brief Creates a filled-in version of W
     * @param offsetX the horizontal offset for creating W
     * @param offsetY the vertical offset for creating W
     * @return A vector with all the points needed to fill W
     */
    vector<vector<double>> createW(double offsetX, double offsetY);

    /**
     * @brief Creates a filled-in version of X
     * @param offsetX the horizontal offset for creating X
     * @param offsetY the vertical offset for creating X
     * @return A vector with all the points needed to fill X
     */
    vector<vector<double>> createX(double offsetX, double offsetY);

    /**
     * @brief Creates a filled-in version of Y
     * @param offsetX the horizontal offset for creating Y
     * @param offsetY the vertical offset for creating Y
     * @return A vector with all the points needed to fill Y
     */
    vector<vector<double>> createY(double offsetX, double offsetY);

    /**
     * @brief Creates a filled-in version of Z
     * @param offsetX the horizontal offset for creating Z
     * @param offsetY the vertical offset for creating Z
     * @return A vector with all the points needed to fill Z
     */
    vector<vector<double>> createZ(double offsetX, double offsetY);

    /**
    * @brief Standard destructor for class Filling
    */
    ~Filling() override = default;
};

#endif //FILLING_H
