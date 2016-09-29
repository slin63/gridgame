//
//  coordinates.cpp
//  gridgame
//
//  Created by SLIN63 on 8/15/16.
//  Copyright © 2016 SLIN63. All rights reserved.
//

#include "coordinates.hpp"
#include <math.h>
#include <cstdlib>


CRDS::CRDS(const int& x_n, const int& y_n) {
    x = x_n;
    y = y_n;
}

void CRDS::delta(const int& x_n, const int& y_n) {
    x += x_n;
    y += y_n;
}

double CRDS::distance(const CRDS& other) const {
    int x_dist = pow(other.get_x() - this->x, 2);
    int y_dist = pow(other.get_y() - this->y, 2);
    double dist = pow(x_dist + y_dist, 0.5);
    return dist;
}

CRDS CRDS::largest_component(void) const
{
    int largest_x = 0;
    int largest_y = 0;

    if (x == 0 && y == 0)
        ;
    else if (std::abs(x) > std::abs(y))
        largest_x = x / std::abs(x);
    else if (std::abs(x) == std::abs(y))
        largest_x = x / std::abs(x);
    else
        largest_y = y / std::abs(y);
    
    CRDS ret(largest_x, largest_y);
    
    return ret;
}