#ifndef RING_HPP
#define RING_HPP

#include "geo2d.hpp"
#include "line.hpp"

class Ring: public Figure{
 private:
    Line outer;
};

#endif