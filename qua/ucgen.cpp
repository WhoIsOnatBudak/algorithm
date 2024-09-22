#include <iostream>
#include <iomanip> // For std::setprecision
#include <cmath>

using namespace std;

// Function to calculate the distance between two points
double distance(double x1, double y1, double x2, double y2) {
    return sqrt((x2 - x1) * (x2 - x1) + (y2 - y1) * (y2 - y1));
}

// Function to calculate the area of a triangle using vertices
double triangleArea(double x1, double y1, double x2, double y2, double x3, double y3) {
    return abs((x1 * (y2 - y3) + x2 * (y3 - y1) + x3 * (y1 - y2)) / 2.0);
}

// Function to calculate the angles at each vertex
void calculateAngles(double a, double b, double c, double &A, double &B, double &C) {
    A = acos((b * b + c * c - a * a) / (2 * b * c)) * (180.0 / M_PI);
    B = acos((a * a + c * c - b * b) / (2 * a * c)) * (180.0 / M_PI);
    C = 180.0 - A - B; // Sum of angles in triangle is 180 degrees
}

// Function to calculate the area of a sector
double sectorArea(double radius, double angle) {
    return (angle / 360.0) * M_PI * radius * radius;
}

int main() {
    // Define the triangle vertices
    int t;
    cin>>t;
    while(t>0){
    t--;
    double x1,y1,x2,y2,x3,y3;
    cin>>x1>>y1>>x2>>y2>>x3>>y3;

    // Calculate the lengths of the sides
    double a = distance(x2, y2, x3, y3); // length BC
    double b = distance(x3, y3, x1, y1); // length CA
    double c = distance(x1, y1, x2, y2); // length AB

    // Calculate the area of the triangle
    double area = triangleArea(x1, y1, x2, y2, x3, y3);

    // Calculate the semiperimeter
    double s = (a + b + c) / 2.0;

    // Calculate the inradius
    double r = area / s;

    // Calculate the incenter coordinates
    double I_x = (a * x1 + b * x2 + c * x3) / (a + b + c);
    double I_y = (a * y1 + b * y2 + c * y3) / (a + b + c);

    // Calculate distances from the incenter to each vertex
    double dA = distance(I_x, I_y, x1, y1); // distance to A
    double dB = distance(I_x, I_y, x2, y2); // distance to B
    double dC = distance(I_x, I_y, x3, y3); // distance to C

    // Calculate the effective radii for the vertex-centered circles
    double rA = dA - r;
    double rB = dB - r;
    double rC = dC - r;

    // Calculate angles at each vertex
    double A, B, C;
    calculateAngles(a, b, c, A, B, C);

    // Calculate the area of the sectors
    double A_sector = sectorArea(rA, A);
    double B_sector = sectorArea(rB, B);
    double C_sector = sectorArea(rC, C);

    // Area of the incircle
    double incircleArea = M_PI * r * r;

    // Calculate the area remaining in the triangle
    double remainingArea = area - (A_sector + B_sector + C_sector + incircleArea);

    // Output the results with two decimal points
    cout << fixed << setprecision(2);
        cout << remainingArea << endl;
    }
    

    return 0;
}
