#include "provided.h"
#include "support.h"
#include "MyMap.h"
#include <string>
#include <vector>
#include <queue>
using namespace std;

class NavigatorImpl
{
public:
    NavigatorImpl();
    ~NavigatorImpl();
    bool loadMapData(string mapFile);
    NavResult navigate(string start, string end, vector<NavSegment>& directions) const;
    vector<NavSegment> Astar(GeoCoord start, GeoCoord goal) const;
private:
    AttractionMapper m_a;
    SegmentMapper m_s;
    
   
    
};

NavigatorImpl::NavigatorImpl()
{
}

NavigatorImpl::~NavigatorImpl()
{
}

bool NavigatorImpl::loadMapData(string mapFile)
{
    MapLoader ml;
    if(!ml.load(mapFile)){
        return false;
    }
    m_a.init(ml);
    m_s.init(ml);
	return true;
}

NavResult NavigatorImpl::navigate(string start, string end, vector<NavSegment> &directions) const
{
 
    GeoCoord sgc, egc;
    if(!m_a.getGeoCoord(start, sgc)){
        return NAV_BAD_SOURCE;
    }
    if( !m_a.getGeoCoord(end, egc)){
        return NAV_BAD_DESTINATION;
    }
  
    return NAV_SUCCESS;

}


//******************** Navigator functions ************************************

// These functions simply delegate to NavigatorImpl's functions.
// You probably don't want to change any of this code.

Navigator::Navigator()
{
    m_impl = new NavigatorImpl;
}

Navigator::~Navigator()
{
    delete m_impl;
}

bool Navigator::loadMapData(string mapFile)
{
    return m_impl->loadMapData(mapFile);
}

NavResult Navigator::navigate(string start, string end, vector<NavSegment>& directions) const
{
    return m_impl->navigate(start, end, directions);
}
