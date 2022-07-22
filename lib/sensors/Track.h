#pragma once
#include "Coordinate.h"
#include<string>
#include <iostream>
#include <fstream> 

class Track
{
public:
    std::vector<Coordinate> track;
    std::vector<double> length_of_parts; 
    Track(){}
    Coordinate point_on_track(const double& distance);
    void add_point(const Coordinate& point);
    void print_Track();
    void new_track(const std::string& path);
    double distance_between_two_points(const Coordinate& _Coord1, const Coordinate& _Coord2);

};

void Track::new_track(const std::string& path)
{
  std::fstream file(path);   +
  double x,y,z;
  while (!file.eof()) 
  {
    file >> x;
    file.ignore(1);
    file >> y;
    file.ignore(1);
    file >> z;
    Coordinate point(x,y,z);
    add_point(point);
  }
  file.close(); 
}



void Track::add_point(const Coordinate& point)
{
    track.push_back(point);
    if(length_of_parts.size()>1)
    {
        double l =distance_between_two_points(track[track.size()-1],track[track.size()-2]);
        length_of_parts.push_back(l);
    }
}

Coordinate Track::point_on_track(const double& distance)
{
    double remain_distance = distance;
    for (int i = 0; i < track.size() - 1; i++)
    {
        if (remain_distance-length_of_parts[i] < 0)
        {
            Coordinate point;
            point.x = track[i].x + (track[i + 1].x - track[i].x) * (remain_distance / length_of_parts[i]);
            point.y = track[i].y + (track[i + 1].y - track[i].y) * (remain_distance / length_of_parts[i]);
            point.z = track[i].z + (track[i + 1].z - track[i].z) * (remain_distance / length_of_parts[i]);
            return(point);
        }
        remain_distance -= length_of_parts[i];
    }
}

double Track::distance_between_two_points(const Coordinate& _Coord1, const Coordinate& _Coord2)
{
    return(sqrt(pow(_Coord2.x - _Coord1.x, 2) + pow(_Coord2.y - _Coord1.y, 2) + pow(_Coord2.z - _Coord1.z, 2)));
}

