#include <iostream>
#include "cube.hpp"

using namespace std;

int main(){
    uiuc::Cube cube;

    cube.setLength(3.48);
    cout << "Volume: " << cube.getVolume() << endl;
    cout << "Surface: " << cube.getSurfaceArea() << endl;

    return 0;
}



