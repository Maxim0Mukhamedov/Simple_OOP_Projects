#ifndef POLYGON_HPP
#define POLYGON_HPP

#include "ring.hpp"

class Polugon: public Ring{
 public:
    RingsContainer inners;
};

#endif