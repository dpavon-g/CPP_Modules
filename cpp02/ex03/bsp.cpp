#include "Point.hpp"

bool bsp( Point const a, Point const b, Point const c, Point const point) {
    double  signAB = (point.getx().toFloat() - a.getx().toFloat()) * (b.gety().toFloat() - a.gety().toFloat()) - (b.getx().toFloat() - a.getx().toFloat()) * (point.gety().toFloat() - a.gety().toFloat());
    double  signBC = (point.getx().toFloat() - b.getx().toFloat()) * (c.gety().toFloat() - b.gety().toFloat()) - (c.getx().toFloat() - b.getx().toFloat()) * (point.gety().toFloat() - b.gety().toFloat());
    double  signCA = (point.getx().toFloat() - c.getx().toFloat()) * (a.gety().toFloat() - c.gety().toFloat()) - (a.getx().toFloat() - c.getx().toFloat()) * (point.gety().toFloat() - c.gety().toFloat());

    bool hasNegative = (signAB < 0) || (signBC < 0) || (signCA < 0);
    bool hasPositive = (signAB < 0) || (signBC < 0) || (signCA < 0);
    
    return !(hasNegative && hasPositive);
}