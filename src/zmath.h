#ifndef ZMATH_H_
#define ZMATH_H_

#include <d3d8.h>
#include "math/math.hpp"

zVec3 *zVec3Project(zVec3 *pOut, const zVec3 *pV, const D3DVIEWPORT8 *pViewport,
                           const zMatrix *pProjection, const zMatrix *pView, const zMatrix *pWorld);

#endif // ZMATH_H_
