#include "Filling.h"

void Filling::generateAlphabet(int x) {

    double startX = 20;
    double offsetX = startX;
    double offsetY = static_cast<double>(coordinates[x][0]);

    for (int i = 0; i < 13; ++i) {
        vector<vector<double> > letter;
        switch (i) {
        case 0: letter = Filling::createA(offsetY); break;
        case 1: letter = Filling::createB(offsetX, offsetY); break;
        case 2: letter = Filling::createC(offsetX + 15, offsetY); break;
        case 3: letter = Filling::createD(offsetX, offsetY); break;
        case 4: letter = Filling::createE(offsetX, offsetY); break;
        case 5: letter = Filling::createF(offsetX, offsetY); break;
        case 6: letter = Filling::createG(offsetX, offsetY); break;
        case 7: letter = Filling::createH(offsetX, offsetY); break;
        case 8: letter = Filling::createI(offsetX, offsetY); break;
        case 9: letter = Filling::createJ(offsetX, offsetY); break;
        case 10: letter = Filling::createK(offsetX, offsetY); break;
        case 11: letter = Filling::createL(offsetX, offsetY); break;
        case 12: letter = Filling::createM(offsetX, offsetY); break;
        }
        letters.push_back(letter);
        offsetX += 70;  
    }

    offsetX = startX;  
    offsetY = static_cast<double>(coordinates[x][1]);
    vector<int> spacing;
    
    for (int i = 13; i < 26; ++i) {
        vector<vector<double> > letter;
        switch (i) {
        case 13: letter = Filling::createN(offsetY); break;
        case 14: letter = Filling::createO(offsetX, offsetY); break;
        case 15: letter = Filling::createP(offsetX, offsetY); break;
        case 16: letter = Filling::createQ(offsetX, offsetY); break;
        case 17: letter = Filling::createR(offsetX, offsetY); break;
        case 18: letter = Filling::createS(offsetX, offsetY); break;
        case 19: letter = Filling::createT(offsetX, offsetY); break;
        case 20: letter = Filling::createU(offsetX, offsetY); break;
        case 21: letter = Filling::createV(offsetX, offsetY); break;
        case 22: letter = Filling::createW(offsetX, offsetY); break;
        case 23: letter = Filling::createX(offsetX, offsetY); break;
        case 24: letter = Filling::createY(offsetX, offsetY); break;
        case 25: letter = Filling::createZ(offsetX, offsetY); break;
        }
        letters.push_back(letter);
        offsetX += 70;  
    }
}


vector< vector<double> > Filling::createA(double offsetY) {
    vector< vector<double> > results;
    vector<vector<double> > filling;
    vector<vector<double> > filling1;
    vector<vector<double> > filling2;

    for (int i = 0; i < 15; i++) {
        filling = DeCasteljau::linearBezier({ 15.0 + i, 75 + offsetY }, { 40.0 + i, 5 + offsetY });
        filling1 = DeCasteljau::linearBezier({ 65.0 + i, 75 + offsetY}, { 40.0 + i, 5 + offsetY });
        filling2 = DeCasteljau::linearBezier({37.0, 45  + offsetY + i}, {58.0, 45 + offsetY + i});

        results.insert(results.end(), filling.begin(), filling.end());
        results.insert(results.end(), filling1.begin(), filling1.end());
        results.insert(results.end(), filling2.begin(), filling2.end());
    }

    return results;
}


vector<vector<double> > Filling::createB(double offsetX, double offsetY) {

    vector<vector<double> > results;
    
    vector<vector<double> > curve1 = DeCasteljau::cubicBezier({ 15 + offsetX, 5 + offsetY }, { 80 + offsetX,  offsetY }, { 80 + offsetX, 40 + offsetY }, { 30 + offsetX, 40 + offsetY });
    vector<vector<double> > curve2 = DeCasteljau::cubicBezier({ 30 + offsetX, 40 + offsetY }, { 80 + offsetX, 35 + offsetY }, { 80 + offsetX, 80 + offsetY }, { 15 + offsetX, 75 + offsetY });
    vector<vector<double> > curve3 = DeCasteljau::cubicBezier({ 30 + offsetX, 17 + offsetY }, { 55 + offsetX, 15 + offsetY }, { 55 + offsetX, 30 + offsetY }, { 30 + offsetX, 29 + offsetY });
    vector<vector<double> > curve4 = DeCasteljau::cubicBezier({ 30 + offsetX, 52 + offsetY }, { 55 + offsetX, 52 + offsetY }, { 55 + offsetX, 67 + offsetY }, { 30 + offsetX, 64 + offsetY });

    vector<vector<double> > topCurve;
    vector<vector<double> > bottomCurve;
    vector<vector<double> > line;

    for (long long unsigned int i = 0; i < curve1.size(); i++) {
        topCurve = DeCasteljau::linearBezier(curve1[i], curve3[i]);
        bottomCurve = DeCasteljau::linearBezier(curve2[i], curve4[i]);

        results.insert(results.end(), topCurve.begin(), topCurve.end());
        results.insert(results.end(), bottomCurve.begin(), bottomCurve.end());
    }

    for (int i=0; i < 15; i++) {
        line = DeCasteljau::linearBezier({ 15 + offsetX + i, 5 + offsetY }, { 15 + offsetX + i, 75 + offsetY });

        results.insert(results.end(), line.begin(), line.end());
    }

    return results;
}

vector< vector<double> > Filling::createC(double offsetX, double offsetY) {
    vector<vector<double> > results;
    vector<vector<double> > curve;

    for (int i = 0; i < 15; i++) {
        curve = DeCasteljau::cubicBezier({ 50 + offsetX, 5 + offsetY + i }, { offsetX - 15 + i, offsetY + i }, { offsetX - 15 + i, offsetY + 80 - i }, { 50 + offsetX, 75 + offsetY - i });
        results.insert(results.end(), curve.begin(), curve.end());
    }

    return results;
}

vector<vector<double> > Filling::createD(double offsetX, double offsetY) {
    vector<vector<double> > results;
    vector<vector<double> > line;
    vector<vector<double> > curve;

    for (int i=0; i < 15; i++) {
        curve = DeCasteljau::cubicBezier({ 20 + offsetX + i, 5 + offsetY + i }, { 80 + offsetX - i, offsetY - 5 + i }, { 80 + offsetX - i, 85 + offsetY - i }, { 20 + offsetX + i, 75 + offsetY - i });
        line = DeCasteljau::linearBezier({ 20 + offsetX + i, 5 + offsetY }, { 20 + offsetX + i, 75 + offsetY });
        results.insert(results.end(), line.begin(), line.end());
        results.insert(results.end(), curve.begin(), curve.end());
    }
    return results;
}

vector<vector<double> > Filling::createE(double offsetX, double offsetY) {
    vector<vector<double> > results;
    vector<vector<double> > line1;
    vector<vector<double> > line2;
    vector<vector<double> > line3;
    vector<vector<double> > line4;

    for (int i=0; i < 15; i++) {
        line1 = DeCasteljau::linearBezier({ 60 + offsetX, 5 + offsetY + i }, { 15 + offsetX, 5 + offsetY + i });
        line2 = DeCasteljau::linearBezier({ 55 + offsetX, 32 + offsetY + i }, { 15 + offsetX, 32 + offsetY + i });
        line3 = DeCasteljau::linearBezier({ 60 + offsetX, 60 + offsetY + i }, { 15 + offsetX, 60 + offsetY + i });
        line4 = DeCasteljau::linearBezier({ 15 + offsetX + i, 5 + offsetY }, { 15 + offsetX + i, 75 + offsetY });

        results.insert(results.end(), line1.begin(), line1.end());
        results.insert(results.end(), line2.begin(), line2.end());
        results.insert(results.end(), line3.begin(), line3.end());
        results.insert(results.end(), line4.begin(), line4.end());

    }
    return results;
}

vector<vector<double> > Filling::createF(double offsetX, double offsetY) {
    vector<vector<double> > results;
    vector<vector<double> > line1;
    vector<vector<double> > line2;
    vector<vector<double> > line3;

    for (int i=0; i < 15; i++) {
        line1 = DeCasteljau::linearBezier({ 60 + offsetX, 5 + offsetY + i }, { 15 + offsetX, 5 + offsetY + i });
        line2 = DeCasteljau::linearBezier({ 45 + offsetX, 32 + offsetY + i }, { 15 + offsetX, 32 + offsetY + i });
        line3 = DeCasteljau::linearBezier({ 15 + offsetX + i, 5 + offsetY }, { 15 + offsetX + i, 75 + offsetY });

        results.insert(results.end(), line1.begin(), line1.end());
        results.insert(results.end(), line2.begin(), line2.end());
        results.insert(results.end(), line3.begin(), line3.end());

    }

    return results;
}

vector<vector<double> > Filling::createG(double offsetX, double offsetY) {
    vector<vector<double> > results;
    vector<vector<double> > line1;
    vector<vector<double> > line2;
    vector<vector<double> > curve;

    for (int i=0; i < 15; i++) {
        line1 = DeCasteljau::linearBezier({ 60 + offsetX - i, 70 + offsetY }, { 60 + offsetX - i, 35 + offsetY });
        line2 = DeCasteljau::linearBezier({ 30 + offsetX, 35 + offsetY + i }, { 60 + offsetX, 35 + offsetY + i });
        results.insert(results.end(), line1.begin(), line1.end());
        results.insert(results.end(), line2.begin(), line2.end());

    }

    vector<vector<double> > curve1 = DeCasteljau::cubicBezier({ 60 + offsetX, 5 + offsetY }, { offsetX - 20, offsetY - 15 }, { offsetX - 15, 95 + offsetY }, { 60 + offsetX, 70 + offsetY });
    vector<vector<double> > curve2 = DeCasteljau::cubicBezier({ 60 + offsetX, 20 + offsetY }, { offsetX - 5 , offsetY }, { offsetX, 70 + offsetY }, { 45 + offsetX, 55 + offsetY });
    vector<vector<double> > curve3;
    for (long long unsigned int i=0; i < curve1.size(); i++) {
        curve3 = DeCasteljau::linearBezier(curve1[i], curve2[i]);
        results.insert(results.end(), curve3.begin(), curve3.end());
    }

    return results;
}

vector<vector<double> > Filling::createH(double offsetX, double offsetY) {
    vector<vector<double> > results;
    vector<vector<double> > line1;
    vector<vector<double> > line2;
    vector<vector<double> > line3;

    for (int i=0; i < 15; i++) {
        line1 = DeCasteljau::linearBezier({ 15 + offsetX + i, 5 + offsetY }, { 15 + offsetX + i, 75 + offsetY });
        line2 = DeCasteljau::linearBezier({ 30 + offsetX + i, 32 + offsetY }, { 30 + offsetX + i,47 + offsetY });
        line3 = DeCasteljau::linearBezier({ 45 + offsetX + i, 5 + offsetY }, { 45 + offsetX + i, 75 + offsetY });

        results.insert(results.end(), line1.begin(), line1.end());
        results.insert(results.end(), line2.begin(), line2.end());
        results.insert(results.end(), line3.begin(), line3.end());
    }
    return results;
}

vector<vector<double> > Filling::createI(double offsetX, double offsetY) {
    vector<vector<double> > results;
    vector<vector<double> > line1;
    vector<vector<double> > line2;
    vector<vector<double> > line3;

    for (int i=0; i < 15; i++) {
        line1 = DeCasteljau::linearBezier({ 15 + offsetX, 5 + offsetY + i }, { 50 + offsetX, 5 + offsetY + i });
        line2 = DeCasteljau::linearBezier({ 25 + offsetX + i,20 + offsetY }, { 25 + offsetX + i,60 + offsetY });
        line3 = DeCasteljau::linearBezier({ 15 + offsetX, 60 + offsetY + i }, { 50 + offsetX, 60 + offsetY + i });

        results.insert(results.end(), line1.begin(), line1.end());
        results.insert(results.end(), line2.begin(), line2.end());
        results.insert(results.end(), line3.begin(), line3.end());
    }
    return results;
}

vector<vector<double> > Filling::createJ(double offsetX, double offsetY) {
    vector<vector<double> > results;
    vector<vector<double> > line1; 
    vector<vector<double> > line2;
    vector<vector<double> > curve1;

    for (int i=0; i < 14; i++) {
        line1 = DeCasteljau::linearBezier({ 25 + offsetX, 5 + offsetY + i }, { 70 + offsetX, 5 + offsetY + i });
        line2 = DeCasteljau::linearBezier({ 40 + offsetX + i, 20 + offsetY }, { 40 + offsetX + i, 57 + offsetY });
        curve1 = DeCasteljau::cubicBezier({ 54 + offsetX - i, 57 + offsetY }, { 54 + offsetX - i, 80 + offsetY - i }, { 15 + offsetX + i, 80 + offsetY - i }, { 15 + offsetX + i, 57 + offsetY });

        results.insert(results.end(), line1.begin(), line1.end());
        results.insert(results.end(), line2.begin(), line2.end());
        results.insert(results.end(), curve1.begin(), curve1.end());

    }
    return results;
}

vector<vector<double> > Filling::createK(double offsetX, double offsetY) {
    vector<vector<double> > results;

    vector<vector<double> > line1;
    vector<vector<double> > line2;
    vector<vector<double> > line3;

    for (int i=0; i < 15; i++) {
        line1 = DeCasteljau::linearBezier({55 + offsetX + i, 5 + offsetY}, {25 + offsetX + i, 39 + offsetY});
        line2 = DeCasteljau::linearBezier({ 55 + offsetX + i, 75 + offsetY }, { 25 + offsetX + i, 39 + offsetY });
        line3 = DeCasteljau::linearBezier({15 + offsetX + i, 75 + offsetY}, { 15 + offsetX + i, 5 + offsetY });

        results.insert(results.end(), line1.begin(), line1.end());
        results.insert(results.end(), line2.begin(), line2.end());
        results.insert(results.end(), line3.begin(), line3.end());
    }
    return results;
}

vector<vector<double> > Filling::createL(double offsetX, double offsetY) {
    vector<vector<double> > results;
    vector<vector<double> > line1;
    vector<vector<double> > line2;

    for (int i=0; i < 15; i++) {
        line1 = DeCasteljau::linearBezier({ 15 + offsetX + i, 5 + offsetY }, { 15 + offsetX + i, 75 + offsetY });
        line2 = DeCasteljau::linearBezier({ 60 + offsetX, 60 + offsetY + i }, { 15 + offsetX, 60 + offsetY + i });

        results.insert(results.end(), line1.begin(), line1.end());
        results.insert(results.end(), line2.begin(), line2.end());
    }
    return results;
}

vector<vector<double> > Filling::createM(double offsetX, double offsetY) {
    vector<vector<double> > results;
    vector<vector<double> > line1;
    vector<vector<double> > line2; 
    vector<vector<double> > line3;
    vector<vector<double> > line4;

    for (int i=0; i < 15; i++) {
        line1 = DeCasteljau::linearBezier({30 + offsetX - i, 5 + offsetY}, {40 + offsetX, 25 + offsetY + i});
        line2 = DeCasteljau::linearBezier({50 + offsetX + i, 5 + offsetY}, {40 + offsetX, 25 + offsetY + i});
        line4 = DeCasteljau::linearBezier({ 30 + offsetX - i, 5 + offsetY }, { 30 + offsetX - i, 75 + offsetY });
        line3 = DeCasteljau::linearBezier({ 50 + offsetX + i, 5 + offsetY }, { 50 + offsetX + i, 75 + offsetY });

        results.insert(results.end(), line1.begin(), line1.end());
        results.insert(results.end(), line2.begin(), line2.end());
        results.insert(results.end(), line3.begin(), line3.end());
        results.insert(results.end(), line4.begin(), line4.end());
    }
    return results;
}

vector<vector<double> > Filling::createN(double offsetY) {
    vector<vector<double> > results;
    vector<vector<double> > line1;
    vector<vector<double> > line2;
    vector<vector<double> > line3;

    for ( int i=0; i < 15; i++) {
        line1 = DeCasteljau::linearBezier({15.0 + i, 15 + offsetY}, {65.0 + i, 85 + offsetY});
        line2 = DeCasteljau::linearBezier({ 15.0 + i, 15 + offsetY }, { 15.0 + i, 85 + offsetY });
        line3 = DeCasteljau::linearBezier({ 65.0 + i, 15 + offsetY }, { 65.0 + i, 85 + offsetY });

        results.insert(results.end(), line1.begin(), line1.end());
        results.insert(results.end(), line2.begin(), line2.end());
        results.insert(results.end(), line3.begin(), line3.end());
    }

    return results;
}

vector<vector<double> > Filling::createO(double offsetX, double offsetY) {
    vector<vector<double> > results;

    vector<vector<double> > curve1 = DeCasteljau::cubicBezier({ 50 + offsetX, 15 + offsetY }, { offsetX, offsetY + 10 }, { offsetX, 90 + offsetY }, { 50 + offsetX, 85 + offsetY });
    vector<vector<double> > curve2 = DeCasteljau::cubicBezier({ 50 + offsetX, 15 + offsetY }, { 100 + offsetX, offsetY + 10 }, { 100 + offsetX, 90 + offsetY }, { 50 + offsetX, 85 + offsetY });
    vector<vector<double> > curve3 = DeCasteljau::cubicBezier({ 50 + offsetX, 30 + offsetY }, { 20 + offsetX, offsetY + 30 }, { 20 + offsetX, 75 + offsetY }, { 50 + offsetX, 70 + offsetY });
    vector<vector<double> > curve4 = DeCasteljau::cubicBezier({ 50 + offsetX, 30 + offsetY }, { 80 + offsetX, offsetY + 30 }, { 80 + offsetX, 75 + offsetY }, { 50 + offsetX, 70 + offsetY });


    vector<vector<double> > fillingL;
    vector<vector<double> > fillingR;
    for (long long unsigned int i=0; i < curve1.size(); i++) {
        fillingL = DeCasteljau::linearBezier(curve1[i], curve3[i]);
        fillingR = DeCasteljau::linearBezier(curve2[i], curve4[i]);

        results.insert(results.end(), fillingL.begin(), fillingL.end());
        results.insert(results.end(), fillingR.begin(), fillingR.end());
    }

    return results;
}

vector<vector<double> > Filling::createP(double offsetX, double offsetY) {
    vector<vector<double> > results;
    vector<vector<double> > line;
    vector<vector<double> > curve;
    for (int i=0; i < 15; i++) {
        line = DeCasteljau::linearBezier({ 45 + offsetX - i, 85 + offsetY }, { 45 + offsetX - i, 15 + offsetY });
        curve = DeCasteljau::cubicBezier({ 30 + offsetX + i, 15 + offsetY + i }, { 80 + offsetX - i, 5 + offsetY + i }, { 80 + offsetX - i, 55 + offsetY - i }, { 45 + offsetX, 55 + offsetY - i });

        results.insert(results.end(), curve.begin(), curve.end());
        results.insert(results.end(), line.begin(), line.end());

    }
    return results;
}

vector<vector<double> > Filling::createQ(double offsetX, double offsetY) {
    vector<vector<double> > results;
    vector<vector<double> > curve1;
    vector<vector<double> > curve2;
    vector<vector<double> > line;

    for (int i=0; i < 15; i++) {
        curve1 = DeCasteljau::cubicBezier({ 40 + offsetX, 30 + offsetY - i }, { 20 + offsetX - i, 25 + offsetY - i }, { 15 + offsetX - i, 70 + offsetY + i }, { 40 + offsetX, 70 + offsetY + i });
        curve2 = DeCasteljau::cubicBezier({ 40 + offsetX, 30 + offsetY - i }, { 55 + offsetX + i, 25 + offsetY - i }, { 55 + offsetX + i, 70 + offsetY + i }, { 40 + offsetX, 70 + offsetY + i });

        results.insert(results.end(), curve1.begin(), curve1.end());
        results.insert(results.end(), curve2.begin(), curve2.end());
    }
    vector<vector<double> > line1 = DeCasteljau::linearBezier({ 55 + offsetX, 75 + offsetY }, { 65 + offsetX, 85 + offsetY });
    vector<vector<double> > line2 = DeCasteljau::linearBezier({ 60 + offsetX, 67 + offsetY }, { 70 + offsetX, 75 + offsetY });

    for (long long unsigned int i=0; i < line1.size(); i++) {
        line = DeCasteljau::linearBezier(line1[i], line2[i]);
        results.insert(results.end(), line.begin(), line.end());
    }
    
    return results;
}

vector<vector<double> > Filling::createR(double offsetX, double offsetY) {
    vector<vector<double> > results;
    vector<vector<double> > line1;
    vector<vector<double> > line2;
    vector<vector<double> > curve;

    for (int i=0; i < 15; i++) {
        line1 = DeCasteljau::linearBezier({ 15 + offsetX + i, 15 + offsetY }, { 15 + offsetX + i, 85 + offsetY });
        curve = DeCasteljau::cubicBezier({ 15 + offsetX + i, 15 + offsetY + i }, { 65 + offsetX - i, offsetY + i }, { 65 + offsetX - i, 60 + offsetY - i }, { 30 + offsetX, 50 + offsetY - i });
        line2 = DeCasteljau::linearBezier({ 60 + offsetX - i, 85 + offsetY }, { 30 + offsetX - i, 50 + offsetY });
        results.insert(results.end(), line1.begin(), line1.end());
        results.insert(results.end(), line2.begin(), line2.end());
        results.insert(results.end(), curve.begin(), curve.end());

    }
    return results;
}

vector<vector<double> > Filling::createS(double offsetX, double offsetY) {
    vector<vector<double> > results;

    vector<vector<double> > curve1 = DeCasteljau::cubicBezier({ 50 + offsetX, 30 + offsetY }, { 55 + offsetX, 20 + offsetY }, { 15 + offsetX, 25 + offsetY }, { 35 + offsetX, 45 + offsetY });
    vector<vector<double> > curve2 = DeCasteljau::cubicBezier({ 50 + offsetX, 15 + offsetY }, { 15 + offsetX, 5 + offsetY }, { 10 + offsetX, 57 + offsetY }, { 35 + offsetX, 52 + offsetY });
    vector<vector<double> > curve3 = DeCasteljau::cubicBezier({ 35 + offsetX, 45 + offsetY }, { 60 + offsetX, 45 + offsetY }, { 60 + offsetX, 90 + offsetY }, { 20 + offsetX, 85 + offsetY });
    vector<vector<double> > curve4 = DeCasteljau::cubicBezier({ 35 + offsetX, 52 + offsetY }, { 45 + offsetX, 60 + offsetY }, { 45 + offsetX, 80 + offsetY }, { 20 + offsetX, 70 + offsetY });

    vector<vector<double> > topCurve;
    vector<vector<double> > bottomCurve;
    for (long long unsigned int i=0; i < curve1.size(); i++) {
        topCurve = DeCasteljau::linearBezier(curve1[i], curve2[i]);
        bottomCurve = DeCasteljau::linearBezier(curve3[i], curve4[i]);

        results.insert(results.end(), topCurve.begin(), topCurve.end());
        results.insert(results.end(), bottomCurve.begin(), bottomCurve.end());
    }

    return results;
}

vector<vector<double> > Filling::createT(double offsetX, double offsetY) {
    vector<vector<double> > results;
    vector<vector<double> > line1;
    vector<vector<double> > line2;

    for (int i=0; i < 15; i++) {
        line1 = DeCasteljau::linearBezier({ 5 + offsetX, 15 + offsetY + i }, { 70 + offsetX, 15 + offsetY + i });
        line2 = DeCasteljau::linearBezier({ 44 + offsetX - i, 85 + offsetY }, { 44 + offsetX - i, 15 + offsetY });
        results.insert(results.end(), line1.begin(), line1.end());
        results.insert(results.end(), line2.begin(), line2.end());
    }
    return results;
}

vector<vector<double> > Filling::createU(double offsetX, double offsetY) {
    vector<vector<double> > results;
    vector<vector<double> > curve;
    vector<vector<double> > line1;
    vector<vector<double> > line2;

    for (int i=0; i < 15; i++) {
        line1 = DeCasteljau::linearBezier({ 15 + offsetX + i, 15 + offsetY }, { 15 + offsetX + i, 60 + offsetY });
        line2 = DeCasteljau::linearBezier({ 60 + offsetX + i, 15 + offsetY }, { 60 + offsetX + i, 60 + offsetY });
        curve = DeCasteljau::cubicBezier({ 15 + offsetX + i, 60 + offsetY }, { 25 + offsetX + i, 92 + offsetY - i }, { 65 + offsetX - i, 92 + offsetY - i }, { 75 + offsetX - i, 60 + offsetY });

        results.insert(results.end(), line1.begin(), line1.end());
        results.insert(results.end(), line2.begin(), line2.end());
        results.insert(results.end(), curve.begin(), curve.end());

    }

    return results;
}

vector<vector<double> > Filling::createV(double offsetX, double offsetY) {
    vector<vector<double> > results;
    vector<vector<double> > line1;
    vector<vector<double> > line2;


    for (int i=0; i < 15; i++) {
        line1 = DeCasteljau::linearBezier({ 15 + offsetX + i, 15 + offsetY }, { 38 + offsetX + i, 85 + offsetY });
        line2 = DeCasteljau::linearBezier({ 60 + offsetX + i, 15 + offsetY }, { 38 + offsetX + i, 85 + offsetY });

        results.insert(results.end(), line1.begin(), line1.end());
        results.insert(results.end(), line2.begin(), line2.end());
    }
    return results;
}

vector<vector<double> > Filling::createW(double offsetX, double offsetY) {
    vector<vector<double> > results;
    vector<vector<double> > line1;
    vector<vector<double> > line2;
    vector<vector<double> > line3;
    vector<vector<double> > line4;


    for (int i=0; i < 15; i++) {
        line1 = DeCasteljau::linearBezier({ 15 + offsetX + i, 15 + offsetY }, { 25 + offsetX + i, 85 + offsetY });
        if (i < 10) {
            line2 = DeCasteljau::linearBezier({ 25 + offsetX + i, 85 + offsetY }, { 40 + offsetX + i, 50 + offsetY });
            line3 = DeCasteljau::linearBezier({ 50 + offsetX + i, 85 + offsetY }, { 40 + offsetX + i, 50 + offsetY });
        }
        else {
            line2 = DeCasteljau::linearBezier({ 25 + offsetX + i, 85 + offsetY }, { 40 + offsetX + 10, 50 + offsetY });
            line3 = DeCasteljau::linearBezier({ 50 + offsetX + i, 85 + offsetY }, { 40 + offsetX + 10, 50 + offsetY });

        }
        line4 = DeCasteljau::linearBezier({ 50 + offsetX + i, 85 + offsetY }, { 60 + offsetX + i, 15 + offsetY });

        results.insert(results.end(), line1.begin(), line1.end());
        results.insert(results.end(), line2.begin(), line2.end());
        results.insert(results.end(), line3.begin(), line3.end());
        results.insert(results.end(), line4.begin(), line4.end());
    }
    return results;
}

vector<vector<double> > Filling::createX(double offsetX, double offsetY) {
    vector<vector<double> > results;
    vector<vector<double> > line1;
    vector<vector<double> > line2;

    for (int i=0; i < 15; i++) {
        line1 = DeCasteljau::linearBezier({ 15 + offsetX + i, 15 + offsetY }, { 60 + offsetX + i, 85 + offsetY });
        line2 = DeCasteljau::linearBezier({ 15 + offsetX + i, 85 + offsetY }, { 60 + offsetX + i, 15 + offsetY });

        results.insert(results.end(), line1.begin(), line1.end());
        results.insert(results.end(), line2.begin(), line2.end());
    }
    return results;
}

vector<vector<double> > Filling::createY(double offsetX, double offsetY) {
    vector<vector<double> > results;
    vector<vector<double> > line1;
    vector<vector<double> > line2;
    vector<vector<double> > line3;

    for (int i=0; i < 15; i++) {
        line1 = DeCasteljau::linearBezier({ 15 + offsetX + i, 15 + offsetY }, { 38 + offsetX + i, 53 + offsetY });
        line2 = DeCasteljau::linearBezier({ 60 + offsetX + i, 15 + offsetY }, { 38 + offsetX + i, 53 + offsetY });
        line3 = DeCasteljau::linearBezier({ 38 + offsetX + i, 53 + offsetY }, { 38 + offsetX + i, 85 + offsetY });

        results.insert(results.end(), line1.begin(), line1.end());
        results.insert(results.end(), line2.begin(), line2.end());
        results.insert(results.end(), line3.begin(), line3.end());
    }
    return results;
}

vector<vector<double> > Filling::createZ(double offsetX, double offsetY) {
    vector<vector<double> > results;
    vector<vector<double> > line1;
    vector<vector<double> > line2;
    vector<vector<double> > line3;

    for (int i=0; i < 15; i++) {
        line1 = DeCasteljau::linearBezier({ 15 + offsetX, 15 + offsetY + i }, { 80 + offsetX, 15 + offsetY + i });
        line2 = DeCasteljau::linearBezier({ 80 + offsetX, 15 + offsetY + i }, { 15 + offsetX, 70 + offsetY + i });
        line3 = DeCasteljau::linearBezier({ 15 + offsetX, 70 + offsetY + i }, { 80 + offsetX, 70 + offsetY + i });

        results.insert(results.end(), line1.begin(), line1.end());
        results.insert(results.end(), line2.begin(), line2.end());
        results.insert(results.end(), line3.begin(), line3.end());
    }
    return results;
}