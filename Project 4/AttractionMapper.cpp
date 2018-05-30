#include "provided.h"
#include "MyMap.h"
#include <string>
using namespace std;

class AttractionMapperImpl
{
public:
	AttractionMapperImpl();
	~AttractionMapperImpl();
	void init(const MapLoader& ml);
	bool getGeoCoord(string attraction, GeoCoord& gc) const;
private:
    MyMap<string, GeoCoord>  m_map;
};

AttractionMapperImpl::AttractionMapperImpl()
{
}

AttractionMapperImpl::~AttractionMapperImpl()
{
}

void AttractionMapperImpl::init(const MapLoader& ml)
{
    //create a my map, mapping attractions to coords
    StreetSegment s;
    for(int i=0; i< ml.getNumSegments(); i++){
        ml.getSegment(i, s);
        for(int i =0; i < s.attractions.size(); i++)
            m_map.associate(s.attractions[i].name, s.attractions[i].geocoordinates);
    }
    
}

bool AttractionMapperImpl::getGeoCoord(string attraction, GeoCoord& gc) const
{
    for(int i = 0; i < attraction.size(); i++)
    {
        attraction[i] = tolower(attraction[i]);
    }
    if(attraction.size() > 0){
        attraction[0] = toupper(attraction[0]);}
    for(int i = 0; i < attraction.size(); i++)
    {
        if(attraction[i] == ' '){
            i++;
            if(i < attraction.size())
                attraction[i] = toupper(attraction[i]);
        }
    }

    
    if(m_map.find(attraction) == nullptr)
        return false;
    gc = *m_map.find(attraction);
    return true;
}

//******************** AttractionMapper functions *****************************

// These functions simply delegate to AttractionMapperImpl's functions.
// You probably don't want to change any of this code.

AttractionMapper::AttractionMapper()
{
	m_impl = new AttractionMapperImpl;
}

AttractionMapper::~AttractionMapper()
{
	delete m_impl;
}

void AttractionMapper::init(const MapLoader& ml)
{
	m_impl->init(ml);
}

bool AttractionMapper::getGeoCoord(string attraction, GeoCoord& gc) const
{
	return m_impl->getGeoCoord(attraction, gc);
}
