//
//  support.cpp
//  Project 4
//
//  Created by Christina Oliveira on 3/15/17.
//  Copyright © 2017 Christina Oliveira. All rights reserved.
//

#include "support.h"
#include "provided.h"

bool operator<( const GeoCoord& g1, const GeoCoord& g2 )
{
    return(g1.latitude < g2.latitude && g1.longitude < g2.longitude);
    
}
bool operator<=( const GeoCoord& g1, const GeoCoord& g2 )
{
    if(g1.latitude <= g2.latitude && g1.longitude <= g2.longitude){
        return true;
    }
    return false;
}
bool operator>( const GeoCoord& g1, const GeoCoord& g2 )
{
    if(g1.latitude > g2.latitude && g1.longitude > g2.longitude){
        return true;
    }
    return false;
}
bool operator>=( const GeoCoord& g1, const GeoCoord& g2 )
{
    if(g1.latitude >= g2.latitude && g1.longitude >= g2.longitude){
        return true;
    }
    return false;
}
bool operator==( const GeoCoord& g1, const GeoCoord& g2 )
{
    if(g1.latitude == g2.latitude && g1.longitude == g2.longitude){
        return true;
    }
    return false;
}
bool operator!=( const GeoCoord& g1, const GeoCoord& g2 )
{
    if(g1.latitude != g2.latitude && g1.longitude != g2.longitude){
        return true;
    }
    return false;
}

std::string getdirection(GeoCoord g, GeoCoord g2){
    GeoSegment gs(g,g2);
    double angle = angleOfLine(gs);
    std::string direction;
   
    if(angle >= 0 || angle <= 22.5)
        direction = "east";
    else if(angle > 22.5 || angle <= 67.5)
        direction = "northeast";
    else if(angle > 67.5 || angle <= 112.5)
        direction = "north";
    else if(angle > 112.5 || angle <= 157.5)
        direction = "northwest";
    else if(angle > 157.5 || angle <= 202.5)
        direction = "west";
    else if(angle > 202.5 || angle <= 247.5)
        direction = "southwest";
    else if(angle > 247.5 || angle <= 292.5)
        direction = "south";
    else if(angle > 292.5 || angle <= 337.5)
        direction = "southeast";
    else if(angle > 337.5 || angle < 360)
        direction = "east";


    return direction;
    
    
}
double getdistance(GeoCoord g, GeoCoord g2){
    
    return distanceEarthMiles(g, g2);
}
