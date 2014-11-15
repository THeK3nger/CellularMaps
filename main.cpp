#include<iostream>
#include<stdio.h>

// Visual Studio want this include to cout strings.
#include <string>

#include "CellularMap.h"

using namespace std;

string mapToString(CellularMap& cm) {
    string returnString;
    for (int column = 0, row = 0; row < cm.getHeight(); row++) {
        for (column = 0; column < cm.getWidth(); column++)
        {
            returnString += cm.getElement(column, row) == 1 ? "#" : ".";
        }
        returnString += "\n";
    }
    return returnString;
}

int main() {
    // This is an use example for the CellularMap class.
    CellularMap cm(50, 50, 40);
    for (int i=0;i<4;++i){
        cm.evolveMap(CellularMap::CM_CONSERVATIVE);
    }
    for (int i=0;i<2;++i){
        cm.evolveMap(CellularMap::CM_SMOOTH);
    }
    string mapS = mapToString(cm);
    cout << mapS;
    cout << "........." << endl;
    getchar();
    return 0;
}
