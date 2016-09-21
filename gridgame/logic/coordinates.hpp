//
//  coordinates.hpp
//  gridgame
//
//  Created by SLIN63 on 8/15/16.
//  Copyright © 2016 SLIN63. All rights reserved.
//

#ifndef COORDINATES_HPP
#define COORDINATES_HPP


class CRDS {
    
public:
    CRDS() = default;
    CRDS(const int&, const int&);
    inline int get_x() const;
    inline int get_y() const;
    void delta(const int&, const int&);
    double distance(const CRDS&) const;
    CRDS largest_component(void) const;
    
private:
    int x;
    int y;
};

int CRDS::get_x(void) const { return x; }
int CRDS::get_y(void) const { return y; }

#endif /* coordinates_hpp */
