/**
 *     Copyright (C) 2008-2014  Francesco Banterle
 *
 *     This Source Code Form is subject to the terms of the Mozilla Public
 *     License, v. 2.0. If a copy of the MPL was not distributed with this
 *     file, You can obtain one at http://mozilla.org/MPL/2.0/.
 **/

#ifndef D3DX_FUNCTIONS_HPP
#define D3DX_FUNCTIONS_HPP

#include <math.h>

#include "D3DXVECTOR2.hpp"
#include "D3DXVECTOR3.hpp"
#include "D3DXVECTOR4.hpp"

static zVec3 *zVec3Cross(zVec3 *pOut, const zVec3 *A, const zVec3 *B)
{
    pOut->x = A->y * B->z - B->y * A->z;
    pOut->y = A->z * B->x - B->z * A->x;
    pOut->z = A->x * B->y - B->x * A->y;
    return pOut;
}

static inline float zVec3Dot(const zVec3 *a, const zVec3 *b)
{
    return (a->x * b->x + a->y * b->y + a->z * b->z);
}

static zVec3 *zVec3Normalize(zVec3 *pOut, const zVec3 *pV)
{
    float length = (pV->x * pV->x + pV->z * pV->z + pV->y * pV->y);

    if (length > 0.0f)
    {
        length = sqrtf(length);
        pOut->x = pV->x / length;
        pOut->y = pV->y / length;
        pOut->z = pV->z / length;
        return pOut;
    }
    else
    {
        return pOut;
    }
}

static zVec3 *zVec3Normalize(zVec3 *pOut)
{
    float length = (pOut->x * pOut->x + pOut->z * pOut->z + pOut->y * pOut->y);

    if (length > 0.0f)
    {
        length = sqrtf(length);
        pOut->x /= length;
        pOut->y /= length;
        pOut->z /= length;
        return pOut;
    }
    else
    {
        return pOut;
    }
}

static float zVec3LengthSq(const zVec3 *pV)
{
    return pV->x * pV->x + pV->z * pV->z + pV->y * pV->y;
}

static float zVec3Length(const zVec3 *pV)
{
    return sqrtf(pV->x * pV->x + pV->z * pV->z + pV->y * pV->y);
}

#endif // D3DX_FUNCTIONS_HPP
