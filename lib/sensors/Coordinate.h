#pragma once
#include <cmath>
#include<vector>
#include<iostream>
#define My_Pi 3.14159265358979323846
class Coordinate
{
public:
    double x, y, z;
    Coordinate() { x = 0, y = 0, z = 0; }
    Coordinate(const double& _x, const double& _y, const double& _z);
    Coordinate from_sphere_to_decart(const Coordinate& _Coord);
    Coordinate& operator=(Coordinate& _Coord);

};


Coordinate::Coordinate(const double& _x, const double& _y, const double& _z)
{
    x = _x;
    y = _y;
    z = _z;
}

Coordinate& Coordinate::operator=(Coordinate& _Coord)
{
    x = _Coord.x;
    y = _Coord.y;
    z = _Coord.z;
    return *this;
}

Coordinate Coordinate::from_sphere_to_decart(const Coordinate& _Coord)
{
    Coordinate point_in_decart;
    double R = 6378000;
    point_in_decart.x = R * cos(_Coord.x* My_Pi / 180) * sin(_Coord.y * My_Pi / 180);
    point_in_decart.y = R * sin(_Coord.x * My_Pi / 180) * sin(_Coord.y * My_Pi / 180);
    point_in_decart.z = _Coord.z;
    return(point_in_decart);
}




