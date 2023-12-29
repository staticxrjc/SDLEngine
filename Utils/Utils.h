#ifndef UTILS_UTILS_H
#define UTILS_UTILS_H

static const float EPSILON = 0.0001f;

const float PI = 3.14159265f;

const float TWO_PI = 2.0f * PI;

bool IsEqual(float x, float y);

bool IsGreaterThanOrEqual(float x, float y);

bool IsLessThanOrEqual(float x, float y);

float MillisecondsToSeconds(unsigned int milliseconds);

#endif  // UTILS_UTILS_H