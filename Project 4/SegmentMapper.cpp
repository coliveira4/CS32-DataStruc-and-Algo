#include "provided.h"
#include "MyMap.h"
#include <vector>
#include <set>
#include <iostream>
#include <fstream>
#include <sstream>

using namespace std;
class AttractionMapper;

class SegmentMapperImpl
{
public:
	SegmentMapperImpl();
	~SegmentMapperImpl();
	void init(const MapLoader& ml);
	vector<StreetSegment> getSegments(const GeoCoord& gc) const;
private:
    MyMap<GeoCoord, vector<StreetSegment>>  m_map;
};

SegmentMapperImpl::SegmentMapperImpl()
{
}

SegmentMapperImpl::~SegmentMapperImpl()
{
}

void SegmentMapperImpl::init(const MapLoader& ml)
{
    StreetSegment s;
    
    for(int i=0; i< ml.getNumSegments(); i++){         //for each segment
        ml.getSegment(i, s);
        vector<StreetSegment>* vp = m_map.find(s.segment.start);        //check to see if start coord is present in map
        if(vp == nullptr){
            vector<StreetSegment> ssv;
            ssv.push_back(s);
            m_map.associate(s.segment.start, ssv);    //associate this vector
        }
        if(vp !=nullptr){
            vp->push_back(s);
            m_map.associate(s.segment.start, *vp);
        }
        
        vector<StreetSegment>* vp2 = m_map.find(s.segment.end);        //check to see if start coord is present in map
        if(vp2 == nullptr){
            vector<StreetSegment> ssv;
            ssv.push_back(s);
            m_map.associate(s.segment.end, ssv);    //associate this vector
        }
        if(vp2 !=nullptr){
            vp2->push_back(s);
            m_map.associate(s.segment.end, *vp2);
        }
        
        for(int i =0; i < s.attractions.size(); i++){
            vector<StreetSegment>* vp3 = m_map.find(s.attractions[i].geocoordinates);
            if(vp3 == nullptr){
                vector<StreetSegment> ssv;
                ssv.push_back(s);
                m_map.associate(s.attractions[i].geocoordinates, ssv);    //associate this vector
            }
            if(vp3 !=nullptr){
                vp3->push_back(s);
                m_map.associate(s.attractions[i].geocoordinates, *vp3);
            }

            
        }
    } 
}
vector<StreetSegment> SegmentMapperImpl::getSegments(const GeoCoord& gc) const
{
    vector<StreetSegment> segments;
    if(m_map.find(gc) == nullptr)
        return segments;              //its eterting this loop
    
    segments = *m_map.find(gc);
	return segments;  
}

//******************** SegmentMapper functions ********************************

// These functions simply delegate to SegmentMapperImpl's functions.
// You probably don't want to change any of this code.

SegmentMapper::SegmentMapper()
{
	m_impl = new SegmentMapperImpl;
}

SegmentMapper::~SegmentMapper()
{
	delete m_impl;
}

void SegmentMapper::init(const MapLoader& ml)
{
	m_impl->init(ml);
}

vector<StreetSegment> SegmentMapper::getSegments(const GeoCoord& gc) const
{
	return m_impl->getSegments(gc);
}
