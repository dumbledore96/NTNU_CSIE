#include <stdio.h>
#include <stdint.h>
#include <math.h>
#include "parallelogram.h"

// Setup three points for a parallelogram.
// Success : return 1; Fail: return 0
static int32_t x1=0,y01=0;
static int32_t x2=0,y2=0;
static int32_t x3=0,y3=0;
int32_t setP1( int32_t x, int32_t y){
    x1 = x;
    y01 = y;
    return 1;
}
int32_t setP2( int32_t x, int32_t y){
    x2 = x;
    y2 = y;
    return 1;
}
int32_t setP3( int32_t x, int32_t y){
    x3 = x;
    y3 = y;
    return 1;
}

// Check if the current setting is a valid parallelogram .
// Yes: return 1; No: return 0
int check( void ){
    int32_t dx1 = x2 - x1, dy1 = y2 - y01;
    int32_t dx2 = x3 - x1, dy2 = y3 - y01;
    int32_t isParallelogram = (dx1 * dy2 == dy1 * dx2) ? 1 : 0;
    return isParallelogram;
}

double distance(int32_t a1, int32_t b1, int32_t a2, int32_t b2) {
    return sqrt(pow(a2 - a1, 2) + pow(b2 - b1, 2));
}

// Return the perimeter of the parallelogram.
// If the current setting is not a parallelogram , return < 0
double getPerimeter(void) {
    if (!check()) return -1;
    double side1 = sqrt(pow(x2 - x1, 2) + pow(y2 - y01, 2));
    double side2 = sqrt(pow(x3 - x1, 2) + pow(y3 - y01, 2));
    return 2 * (side1 + side2);
}

// Return the area of the parallelogram .
// If the current setting is not a parallelogram , return < 0
double getArea(void) {
    if (!check()) return -1;
    return fabs((x2 - x1) * (y3 - y01) - (x3 - x1) * (y2 - y01));
}

// Get the degrees (0-360) of P1
// If the current setting is not a parallelogram , return < 0
double getP1Degree(void) {
    if (!check()) return -1;
    double dot_product = (x2 - x1) * (x3 - x1) + (y2 - y01) * (y3 - y01);
    double magnitude1 = sqrt(pow(x2 - x1, 2) + pow(y2 - y01, 2));
    double magnitude2 = sqrt(pow(x3 - x1, 2) + pow(y3 - y01, 2));
    double angle_rad = acos(dot_product / (magnitude1 * magnitude2));
    return angle_rad * (180.0 / M_PI);
}