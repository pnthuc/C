#pragma once
struct Point {
    double x;
    double y;
};

struct Triangle {
    Point p1;
    Point p2;
    Point p3;
};

double computePerimeter(Triangle triangle);
Point computeCentroid(Triangle triangle);
void inputTriangle(Triangle &triangle);
void outputPerimeter(double perimeter);
void outputCentroid( Point centroid);