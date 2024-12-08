#include <iostream>
#include <cmath>
#include "process1.h"

void inputTriangle(Triangle &triangle) {
    std::cin >> triangle.p1.x >> triangle.p1.y;
    std::cout << "Enter coordinates for point 2 (x y): ";
    std::cin >> triangle.p2.x >> triangle.p2.y;
    std::cout << "Enter coordinates for point 3 (x y): ";
    std::cin >> triangle.p3.x >> triangle.p3.y;
}

double distance(Point a,  Point b) {
    return std::sqrt((b.x - a.x) * (b.x - a.x) + (b.y - a.y) * (b.y - a.y));
}

double computePerimeter( Triangle triangle) {
    return distance(triangle.p1, triangle.p2) + distance(triangle.p2, triangle.p3) + distance(triangle.p3, triangle.p1);
}

Point computeCentroid( Triangle triangle) {
    Point centroid;
    centroid.x = (triangle.p1.x + triangle.p2.x + triangle.p3.x) / 3.0;
    centroid.y = (triangle.p1.y + triangle.p2.y + triangle.p3.y) / 3.0;
    return centroid;
}

void outputPerimeter(double perimeter) {
    std::cout << "Perimeter of the triangle: " << perimeter << std::endl;
}

void outputCentroid( Point centroid) {
    std::cout << "Centroid of the triangle: (" << centroid.x << ", " << centroid.y << ")" << std::endl;
}