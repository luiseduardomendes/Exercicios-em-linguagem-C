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
    Cube cube = foo();

    //cube.setLength(3.48);
    cout << "Volume: " << cube.getVolume() << endl;
    cout << "Surface: " << cube.getSurfaceArea() << endl;

    
    
    cout << endl;
    

    return 0;
}



