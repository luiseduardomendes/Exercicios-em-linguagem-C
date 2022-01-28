/* storage by pointer */

#include <iostream>
#include "cube.hpp"

using namespace std;

using uiuc::Cube;

Cube foo (){
    Cube cube;
    cube.setLength(3);
    Cube c(cube);
    return c;
}

int main(){
    Cube *c1;
    Cube &cube1 = *c1;
    Cube *c2;
    Cube &cube2 = *c2;

    cube2.setLength(3);

    //cube.setLength(3.48);
    cout << "Volume cube 1: " << cube1.getVolume() << endl;
    cout << "Surface cube 1: " << cube1.getSurfaceArea() << endl;

    cout << "Volume cube 2: " << cube2.getVolume() << endl;
    cout << "Surface cube 2: " << cube2.getSurfaceArea() << endl;

    cube1 = cube2;

    cout << "Volume cube 1: " << cube1.getVolume() << endl;
    cout << "Surface cube 1: " << cube1.getSurfaceArea() << endl;

    cout << "Volume cube 2: " << cube2.getVolume() << endl;
    cout << "Surface cube 2: " << cube2.getSurfaceArea() << endl;

    
    cout << endl;
    

    return 0;
}



