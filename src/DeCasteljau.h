#ifndef DECASTELJAU_H
#define DECASTELJAU_H

#include <vector>
#include <functional>
#include <iostream>
using namespace std;

/**
*@class DeCasteljau
* @brief Implements the DeCasteljau algorithm 
*/
class DeCasteljau {
	protected:
		/**
			* @brief Returns the interpolated point between p0 and p1 for time t 
			* @param p0 the first point 
			* @param p1 the second point 
			* @param t the time parameter of the interpolation
			* @return a vector containing 2 doubles (the x and y coordinates of a point)
		*/
		static vector<double> interpolation(vector<double> p0, vector<double> p1, double t);

	public:
		/**
			* @brief Creates a straight line between p0 and p1 
			* @param p0 the first point
			* @param p1 the second point
			* @return a vector containing all the points of the line to be drawn 
		*/
		static vector<vector<double>> linearBezier(vector<double> p0, vector <double> p1);

		/**
			* @brief Creates a curve between p0 and p2 with p1 determining the curvature 
			* @param p0 the first point
			* @param p1 the second point
			* @param p2 the third point 
			* @return a vector containing all the points of the curve to be drawn
		*/
		static vector<vector<double>> quadraticBezier(vector <double> p0, vector <double> p1, vector <double> p2);

		/**
			* @brief Creates a curve between p0 and p3 with p1 and p2 determining the curvature
			* @param p0 the first point
			* @param p1 the second point
			* @param p2 the third point
			* @param p3 the fourth point 
			* @return a vector containing all the points of the curve to be drawn
		*/
		static vector<vector<double>> cubicBezier(vector <double> p0, vector <double> p1, vector <double> p2, vector <double> p3);
};

#endif //DECASTELJAU_H