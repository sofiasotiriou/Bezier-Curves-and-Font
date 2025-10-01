#include "Trace.h"

void Trace::generateAlphabet(int x) {
    double offsetX = 0;
    double offsetY = coordinates[x][0];
    vector<vector<double> > letter;
    int c = 0;
    for (auto pointer : ab[x]) {
        if (c == 0) {
            letter = createLetter(*pointer, offsetX, offsetY);
            offsetX += 90;  
        }
        else if (c == 2) {
            offsetX += 15;
            letter = createLetter(*pointer, offsetX, offsetY);
            offsetX += 55;
        }
        else if (c == 13) {
            offsetY = coordinates[x][1];
            offsetX = 0;
            letter = createLetter(*pointer, offsetX, offsetY);
            offsetX += 90;  
        }
        else {
            letter = createLetter(*pointer, offsetX, offsetY);
            offsetX += 70; 
        }
        letters.push_back(letter);
        c++;
    }
}

vector<vector<double> > Trace::createLetter(vector<vector<vector<double> > > letter, double offsetX, double offsetY) {
    results.clear();
    for (const vector<vector<double> >& component : letter) {
        if (component.size() == 2) {
            line = DeCasteljau::linearBezier({ static_cast<double>(component[0][0]) + offsetX, static_cast<double>(component[0][1]) + offsetY },
                { static_cast<double>(component[1][0]) + offsetX, static_cast<double>(component[1][1]) + offsetY });
            results.insert(results.end(), line.begin(), line.end());
        }
        else if (component.size() == 4) {
            line = DeCasteljau::cubicBezier({ static_cast<double>(component[0][0]) + offsetX, static_cast<double>(component[0][1]) + offsetY },
                { static_cast<double>(component[1][0]) + offsetX, static_cast<double>(component[1][1]) + offsetY },
                { static_cast<double>(component[2][0]) + offsetX, static_cast<double>(component[2][1]) + offsetY },
                { static_cast<double>(component[3][0]) + offsetX, static_cast<double>(component[3][1]) + offsetY });
            results.insert(results.end(), line.begin(), line.end());

        }
        else if (component.size() == 0) {
            results.insert(results.end(), vector<double>());
        }
        else {
            cout << "error" << component.size() << endl;
        }
    }
    return results;
}