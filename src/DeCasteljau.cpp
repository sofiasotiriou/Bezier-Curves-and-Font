#include "DeCasteljau.h"
#include <vector>
using namespace std;

vector<double> DeCasteljau::interpolation(vector<double> p0, vector<double> p1, double t) {
    vector<double> a = { (1 - t) * p0[0], (1 - t) * p0[1] };
    vector<double> b = { t * p1[0], t * p1[1] };
    return { a[0] + b[0], a[1] + b[1] };
}


vector<vector<double>> DeCasteljau::linearBezier(vector <double> p0, vector <double> p1) {
    vector<vector<double>> result;
    int t_scaled = 0;         
    int scale = 1000;         

    while (t_scaled <= scale) {
        double t = static_cast<double>(t_scaled) / scale; 
        result.push_back(interpolation(p0, p1, t));
        t_scaled += 10; 
    }

    return result;
}

vector < vector<double> > DeCasteljau::quadraticBezier(vector <double> p0, vector <double> p1, vector <double> p2) {
    vector <vector<double> > result;

    int t_scaled = 0;
    int scale = 1000;
    while (t_scaled <= scale) {
        double t = static_cast<double>(t_scaled) / scale;
        vector <double> p01 = interpolation(p0, p1, t);
        vector <double> p12 = interpolation(p1, p2, t);
        result.push_back(interpolation(p01, p12, t));
        t_scaled += 1;
    }
    return result;
}

vector < vector<double> > DeCasteljau::cubicBezier(vector <double> p0, vector<double> p1, vector<double> p2, vector<double> p3) {
    vector < vector<double> > result;

    int t_scaled = 0;
    int scale = 1000;
    while (t_scaled <= scale) {
        double t = static_cast<double> (t_scaled) / scale;
        vector <double> p01 = interpolation(p0, p1, t);
        vector <double> p12 = interpolation(p1, p2, t);
        vector <double> p23 = interpolation(p2, p3, t);
        vector <double> p012 = interpolation(p01, p12, t);
        vector <double> p123 = interpolation(p12, p23, t);
        result.push_back(interpolation(p012, p123, t));
        t_scaled += 1;
    }
    return result;
}