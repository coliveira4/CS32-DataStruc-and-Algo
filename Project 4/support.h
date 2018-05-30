//
//  support.hpp
//  Project 4
//
//  Created by Christina Oliveira on 3/15/17.
//  Copyright © 2017 Christina Oliveira. All rights reserved.
//

#ifndef support_h
#define support_h
#include <iostream>
#include <string>
#include <stdio.h>


class StreetSegment;
class GeoCoord;

bool operator<( const GeoCoord& g1, const GeoCoord& g2 );

bool operator<=( const GeoCoord& g1, const GeoCoord& g2 );

bool operator>( const GeoCoord& g1, const GeoCoord& g2 );

bool operator>=( const GeoCoord& g1, const GeoCoord& g2 );

bool operator==( const GeoCoord& g1, const GeoCoord& g2 );

bool operator!=( const GeoCoord& g1, const GeoCoord& g2 );

std::string getdirection(GeoCoord g, GeoCoord g2);

double getdistance(GeoCoord g, GeoCoord g2);
    
    




#endif /* support_h */
