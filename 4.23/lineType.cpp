#include "lineType.h"
#include <iostream>
#include <cmath>
#include <stdexcept>
using namespace std;

// Constructor
lineType::lineType(double aVal, double bVal, double cVal) {
    a = aVal;
    b = bVal;
    c = cVal; // use getters 
}

// Check vertical
bool lineType::isVertical() const {
    return b == 0;
}

// Check horizontal
bool lineType::isHorizontal() const {
    return a == 0;
}

// Get slope
double lineType::slope() const {
    if (isVertical()) {
        throw runtime_error("Slope is undefined for vertical lines.");
    }
    return -a / b;
}

// Check equality
bool lineType::isEqual(const lineType& other) const {
    if (a == other.a && b == other.b && c == other.c) return true;
    if (other.a != 0 && a / other.a == b / other.b && a / other.a == c / other.c) return true;
    return false;
}

// Check parallel
bool lineType::isParallel(const lineType& other) const {
    if (isVertical() && other.isVertical()) return true;
    if (isVertical() || other.isVertical()) return false;
    return fabs(slope() - other.slope()) < 1e-6;
}

// Check perpendicular
bool lineType::isPerpendicular(const lineType& other) const {
    if ((isVertical() && other.isHorizontal()) || (isHorizontal() && other.isVertical())) return true;
    if (isVertical() || other.isVertical()) return false;
    return fabs(slope() * other.slope() + 1) < 1e-6;
}

// Get intersection point
bool lineType::getIntersection(const lineType& other, double& x, double& y) const {
    double det = a * other.b - other.a * b;
    if (fabs(det) < 1e-6) return false;
    x = (c * other.b - other.c * b) / det;
    y = (a * other.c - other.a * c) / det;
    return true;
}

// Display line
void lineType::display() const {
    cout << a << "x + " << b << "y = " << c << endl;
}
