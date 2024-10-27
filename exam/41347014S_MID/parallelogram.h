#pragma once

#include <stdio.h>
#include <stdint.h>

// Setup three points for a parallelogram.
// Success : return 1; Fail: return 0

int32_t setP1( int32_t x, int32_t y);
int32_t setP2( int32_t x, int32_t y);
int32_t setP3( int32_t x, int32_t y);

// Check if the current setting is a valid parallelogram .
// Yes: return 1; No: return 0
int check();

// Return the perimeter of the parallelogram.
// If the current setting is not a parallelogram , return < 0
double getPerimeter ();

// Return the area of the parallelogram .
// If the current setting is not a parallelogram , return < 0
double getArea ();

// Get the degrees (0-360) of P1
// If the current setting is not a parallelogram , return < 0
double getP1Degree ();