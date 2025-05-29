/**
 *     Copyright (C) 2008-2014  Francesco Banterle
 *
 *     This Source Code Form is subject to the terms of the Mozilla Public
 *     License, v. 2.0. If a copy of the MPL was not distributed with this
 *     file, You can obtain one at http://mozilla.org/MPL/2.0/.
 **/

#pragma once

#include "quat.hpp"
#include "vec3.hpp"
#include "vec4.hpp"
#include "math_util.hpp"
#include <stdio.h>

class zMatrix
{
  public:
    union {
        struct
        {
            float _11, _12, _13, _14;
            float _21, _22, _23, _24;
            float _31, _32, _33, _34;
            float _41, _42, _43, _44;
        };
        float m[4][4];
    };

    zMatrix()
    {
    }

    void operator+=(const zMatrix &pM)
    {
        _11 += pM._11;
        _12 += pM._12;
        _13 += pM._13;
        _14 += pM._14;

        _21 += pM._21;
        _22 += pM._22;
        _23 += pM._23;
        _24 += pM._24;

        _31 += pM._31;
        _32 += pM._32;
        _33 += pM._33;
        _34 += pM._34;

        _41 += pM._41;
        _42 += pM._42;
        _43 += pM._43;
        _44 += pM._44;
    }

    void operator-=(const zMatrix &pM)
    {
        _11 -= pM._11;
        _12 -= pM._12;
        _13 -= pM._13;
        _14 -= pM._14;

        _21 -= pM._21;
        _22 -= pM._22;
        _23 -= pM._23;
        _24 -= pM._24;

        _31 -= pM._31;
        _32 -= pM._32;
        _33 -= pM._33;
        _34 -= pM._34;

        _41 -= pM._41;
        _42 -= pM._42;
        _43 -= pM._43;
        _44 -= pM._44;
    }

    void operator*=(float v)
    {
        _11 *= v;
        _12 *= v;
        _13 *= v;
        _14 *= v;

        _21 *= v;
        _22 *= v;
        _23 *= v;
        _24 *= v;

        _31 *= v;
        _32 *= v;
        _33 *= v;
        _34 *= v;

        _41 *= v;
        _42 *= v;
        _43 *= v;
        _44 *= v;
    }

    void operator/=(float v)
    {
        _11 /= v;
        _12 /= v;
        _13 /= v;
        _14 /= v;

        _21 /= v;
        _22 /= v;
        _23 /= v;
        _24 /= v;

        _31 /= v;
        _32 /= v;
        _33 /= v;
        _34 /= v;

        _41 /= v;
        _42 /= v;
        _43 /= v;
        _44 /= v;
    }

    zMatrix operator-() const
    {
        zMatrix pOut;

        pOut._11 = -_11;
        pOut._12 = -_12;
        pOut._13 = -_13;
        pOut._14 = -_14;

        pOut._21 = -_21;
        pOut._22 = -_22;
        pOut._23 = -_23;
        pOut._24 = -_24;

        pOut._31 = -_31;
        pOut._32 = -_32;
        pOut._33 = -_33;
        pOut._34 = -_34;

        pOut._41 = -_41;
        pOut._42 = -_42;
        pOut._43 = -_43;
        pOut._44 = -_44;

        return pOut;
    }

    // binary operators

    zMatrix operator+(const zMatrix &pM) const
    {
        zMatrix pOut;

        pOut._11 = _11 + pM._11;
        pOut._12 = _12 + pM._12;
        pOut._13 = _13 + pM._13;
        pOut._14 = _14 + pM._14;

        pOut._21 = _21 + pM._21;
        pOut._22 = _22 + pM._22;
        pOut._23 = _23 + pM._23;
        pOut._24 = _24 + pM._24;

        pOut._31 = _31 + pM._31;
        pOut._32 = _32 + pM._32;
        pOut._33 = _33 + pM._33;
        pOut._34 = _34 + pM._34;

        pOut._41 = _41 + pM._41;
        pOut._42 = _42 + pM._42;
        pOut._43 = _43 + pM._43;
        pOut._44 = _44 + pM._44;

        return pOut;
    }

    zMatrix operator-(const zMatrix &pM) const
    {
        zMatrix pOut;

        pOut._11 = _11 - pM._11;
        pOut._12 = _12 - pM._12;
        pOut._13 = _13 - pM._13;
        pOut._14 = _14 - pM._14;

        pOut._21 = _21 - pM._21;
        pOut._22 = _22 - pM._22;
        pOut._23 = _23 - pM._23;
        pOut._24 = _24 - pM._24;

        pOut._31 = _31 - pM._31;
        pOut._32 = _32 - pM._32;
        pOut._33 = _33 - pM._33;
        pOut._34 = _34 - pM._34;

        pOut._41 = _41 - pM._41;
        pOut._42 = _42 - pM._42;
        pOut._43 = _43 - pM._43;
        pOut._44 = _44 - pM._44;

        return pOut;
    }

    zMatrix operator*(float v) const
    {
        zMatrix pOut;

        pOut._11 = _11 * v;
        pOut._12 = _12 * v;
        pOut._13 = _13 * v;
        pOut._14 = _14 * v;

        pOut._21 = _21 * v;
        pOut._22 = _22 * v;
        pOut._23 = _23 * v;
        pOut._24 = _24 * v;

        pOut._31 = _31 * v;
        pOut._32 = _32 * v;
        pOut._33 = _33 * v;
        pOut._34 = _34 * v;

        pOut._41 = _41 * v;
        pOut._42 = _42 * v;
        pOut._43 = _43 * v;
        pOut._44 = _44 * v;

        return pOut;
    }

    zMatrix operator/(float v) const
    {
        zMatrix pOut;

        pOut._11 = _11 / v;
        pOut._12 = _12 / v;
        pOut._13 = _13 / v;
        pOut._14 = _14 / v;

        pOut._21 = _21 / v;
        pOut._22 = _22 / v;
        pOut._23 = _23 / v;
        pOut._24 = _24 / v;

        pOut._31 = _31 / v;
        pOut._32 = _32 / v;
        pOut._33 = _33 / v;
        pOut._34 = _34 / v;

        pOut._41 = _41 / v;
        pOut._42 = _42 / v;
        pOut._43 = _43 / v;
        pOut._44 = _44 / v;

        return pOut;
    }
};

static void zMatrixPrintf(const zMatrix *pM)
{
    printf("%3.3f %3.3f %3.3f %3.3f\n", pM->_11, pM->_12, pM->_13, pM->_14);
    printf("%3.3f %3.3f %3.3f %3.3f\n", pM->_21, pM->_22, pM->_23, pM->_24);
    printf("%3.3f %3.3f %3.3f %3.3f\n", pM->_31, pM->_32, pM->_33, pM->_34);
    printf("%3.3f %3.3f %3.3f %3.3f\n", pM->_41, pM->_42, pM->_43, pM->_44);
    printf("\n");
}

static zMatrix *zMatrixIdentity(zMatrix *pOut)
{
    pOut->_11 = 1.0f;
    pOut->_12 = 0.0f;
    pOut->_13 = 0.0f;
    pOut->_14 = 0.0f;

    pOut->_21 = 0.0f;
    pOut->_22 = 1.0f;
    pOut->_23 = 0.0f;
    pOut->_24 = 0.0f;

    pOut->_31 = 0.0f;
    pOut->_32 = 0.0f;
    pOut->_33 = 1.0f;
    pOut->_34 = 0.0f;

    pOut->_41 = 0.0f;
    pOut->_42 = 0.0f;
    pOut->_43 = 0.0f;
    pOut->_44 = 1.0f;

    return pOut;
}

static zMatrix *zMatrixRotationX(zMatrix *pOut, float Angle)
{
    zMatrixIdentity(pOut);
    float cosAng = cosf(Angle);
    float sinAng = sinf(Angle);

    pOut->_22 = cosAng;
    pOut->_33 = cosAng;
    pOut->_23 = sinAng;
    pOut->_32 = -sinAng;

    return pOut;
}

static zMatrix *zMatrixRotationY(zMatrix *pOut, float Angle)
{
    zMatrixIdentity(pOut);
    float cosAng = cosf(Angle);
    float sinAng = sinf(Angle);

    pOut->_11 = cosAng;
    pOut->_33 = cosAng;
    pOut->_13 = -sinAng;
    pOut->_31 = sinAng;

    return pOut;
}

static zMatrix *zMatrixRotationZ(zMatrix *pOut, float Angle)
{
    zMatrixIdentity(pOut);
    float cosAng = cosf(Angle);
    float sinAng = sinf(Angle);

    pOut->_11 = cosAng;
    pOut->_22 = cosAng;
    pOut->_12 = sinAng;
    pOut->_21 = -sinAng;

    return pOut;
}

static zMatrix *zMatrixMultiply(zMatrix *pOut, const zMatrix *pM1, const zMatrix *pM2)
{
    zMatrix m;
    int i, j;

    for (i = 0; i < 4; i++)
    {
        for (j = 0; j < 4; j++)
        {
            m.m[i][j] = pM1->m[i][0] * pM2->m[0][j] + pM1->m[i][1] * pM2->m[1][j] + pM1->m[i][2] * pM2->m[2][j] +
                        pM1->m[i][3] * pM2->m[3][j];
        }
    }

    *pOut = m;
    return pOut;
}

static zVec3 *zVec3TransformCoord(zVec3 *pOut, const zVec3 *pV, const zMatrix *pM)
{
    zVec3 v;

    v.x = pV->x * pM->_11 + pV->y * pM->_21 + pV->z * pM->_31 + pM->_41;
    v.y = pV->x * pM->_12 + pV->y * pM->_22 + pV->z * pM->_32 + pM->_42;
    v.z = pV->x * pM->_13 + pV->y * pM->_23 + pV->z * pM->_33 + pM->_43;
    float w = pV->x * pM->_14 + pV->y * pM->_24 + pV->z * pM->_34 + pM->_44;

    v.x /= w;
    v.y /= w;
    v.z /= w;

    *pOut = v;
    return pOut;
}

static zMatrix *zMatrixRotationQuaternion(zMatrix *pOut, const zQuaternion *pQ)
{
    zMatrixIdentity(pOut);

    float qx2 = pQ->x * pQ->x;
    float qy2 = pQ->y * pQ->y;
    float qz2 = pQ->z * pQ->z;

    pOut->_11 = 1.0f - 2.0f * (qz2 + qy2);
    pOut->_12 = 2.0f * (pQ->x * pQ->y - pQ->w * pQ->z);
    pOut->_13 = 2.0f * (pQ->x * pQ->z + pQ->w * pQ->y);

    pOut->_21 = 2.0f * (pQ->x * pQ->y + pQ->w * pQ->z);
    pOut->_22 = 1.0f - 2.0f * (qx2 + qz2);
    pOut->_23 = 2.0f * (pQ->y * pQ->z - pQ->w * pQ->x);

    pOut->_31 = 2.0f * (pQ->x * pQ->z - pQ->w * pQ->y);
    pOut->_32 = 2.0f * (pQ->y * pQ->z + pQ->w * pQ->x);
    pOut->_33 = 1.0f - 2.0f * (qx2 + qy2);

    return pOut;
}

static zMatrix *zMatrixLookAtLH(zMatrix *pOut, const zVec3 *pEye, const zVec3 *pAt, const zVec3 *pUp)
{
    zVec3 x, y, z;
    z.x = pAt->x - pEye->x;
    z.y = pAt->y - pEye->y;
    z.z = pAt->z - pEye->z;

    zVec3Normalize(&z);

    zVec3Cross(&x, pUp, &z);
    zVec3Normalize(&x);

    zVec3Cross(&y, &z, &x);

    pOut->_11 = x.x;
    pOut->_12 = y.x;
    pOut->_13 = z.x;
    pOut->_14 = 0.0f;

    pOut->_21 = x.y;
    pOut->_22 = y.y;
    pOut->_23 = z.y;
    pOut->_24 = 0.0f;

    pOut->_31 = x.z;
    pOut->_32 = y.z;
    pOut->_33 = z.z;
    pOut->_34 = 0.0f;

    pOut->_41 = -zVec3Dot(&x, pEye);
    pOut->_42 = -zVec3Dot(&y, pEye);
    pOut->_43 = -zVec3Dot(&z, pEye);
    pOut->_44 = 1.0f;

    return pOut;
}

static zMatrix *zMatrixPerspectiveFovLH(zMatrix *pOut, float fovy, float Aspect, float zn, float zf)
{
    zMatrixIdentity(pOut);

    float f = 1.0f / tanf(fovy * 0.5f);
    float d = zf - zn;

    pOut->_11 = f / Aspect;
    pOut->_22 = f;
    pOut->_33 = zf / d;
    pOut->_44 = 0.0f;
    pOut->_43 = -zn * zf / d;
    pOut->_34 = 1.0f;
    return pOut;
}
