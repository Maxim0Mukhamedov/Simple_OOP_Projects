#ifndef GEO2D_HPP
#define GEO2D_HPP

#include "iosfwd"
#include "transform.hpp"

class Drawer {

};
class Iterator {

};
class CoordType {

};
class ScaleType {

};
class RotType {

};

class Figure {
 public:
    using SizeType = int;
 public:
    void Draw(Drawer& drawer) {

    }
    void WriteTo(const std::istream& istrm) {

    }
    void GetTransform() {

    }

 private:
    Transform transform;
};

#endif