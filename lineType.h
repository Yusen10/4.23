#ifndef LINETYPE_H
#define LINETYPE_H

class lineType {
private:
    double a, b, c;

public:
    // Constructors
    lineType(double aVal = 0, double bVal = 1, double cVal = 0);

    // Slope-related methods
    bool isVertical() const;
    bool isHorizontal() const;
    double slope() const;

    // Comparison methods
    bool isEqual(const lineType& other) const;
    bool isParallel(const lineType& other) const;
    bool isPerpendicular(const lineType& other) const;

    // Intersection
    bool getIntersection(const lineType& other, double& x, double& y) const;

    // Display
    void display() const;
};

#endif#pragma once
