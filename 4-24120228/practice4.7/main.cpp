#include <iostream>
#include "process1.h"

int main() {
    Triangle triangle;

    inputTriangle(triangle);

    double perimeter = computePerimeter(triangle);
    outputPerimeter(perimeter);

    Point centroid = computeCentroid(triangle);
    outputCentroid(centroid);

    return 0;
}