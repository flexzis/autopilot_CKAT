#pragma once
#include <cmath>
#include <vector>
#define My_Pi 3.14159265358979323846

class Coordinate
{
public:
    double x, y, z;
    Coordinate() { x = 0, y = 0, z = 0; }
    Coordinate(const double& _x, const double& _y, const double& _z);
    Coordinate from_sphere_to_decart(Coordinate& _Coord);
    Coordinate point_on_track(const std::vector<Coordinate>& _Coordinates, const double& distance);
    Coordinate& operator=(Coordinate& _Coord);
    double distance_between_two_points(const Coordinate& _Coord1, const Coordinate& _Coord2);
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

Coordinate Coordinate::from_sphere_to_decart(Coordinate& _Coord)
{
    Coordinate point_in_decart;
    double R = 6378000;
    point_in_decart.x = R * cos(_Coord.x* My_Pi / 180) * sin(_Coord.y * My_Pi / 180);
    point_in_decart.y = R * sin(_Coord.x * My_Pi / 180) * sin(_Coord.y * My_Pi / 180);
    point_in_decart.z = _Coord.z;
    return(point_in_decart);
}



double Coordinate::distance_between_two_points(const Coordinate& _Coord1, const Coordinate& _Coord2)
{
    return(sqrt(pow(_Coord2.x - _Coord1.x, 2) + pow(_Coord2.y - _Coord1.y, 2) + pow(_Coord2.z - _Coord1.z, 2)));
}

Coordinate Coordinate::point_on_track(const std::vector<Coordinate>& _Coordinates, const double& distance)
{
    double remain_distance = distance;
    for (int i = 0; i < _Coordinates.size() - 1; i++)
    {
        double l = distance_between_two_points(_Coordinates[i + 1], _Coordinates[i]);
        if (remain_distance-l < 0)
        {
            Coordinate point;
            point.x = _Coordinates[i].x + (_Coordinates[i + 1].x - _Coordinates[i].x) * (remain_distance / l);
            point.y = _Coordinates[i].y + (_Coordinates[i + 1].y - _Coordinates[i].y) * (remain_distance / l);
            point.z = _Coordinates[i].z + (_Coordinates[i + 1].z - _Coordinates[i].z) * (remain_distance / l);
            return(point);
        }
        remain_distance -= l;
    }
}
