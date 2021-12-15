#pragma once

namespace uiuc{
    class Cube{
        public:
            Cube();
            Cube(const Cube &obj);
            Cube& operator=(const Cube & obj);

            double getVolume();
            double getSurfaceArea();
            void setLength(double length);
            
        private:
            double length_;
    };
}