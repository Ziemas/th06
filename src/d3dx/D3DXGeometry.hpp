/**
*     Copyright (C) 2008-2014  Francesco Banterle
*
*     This Source Code Form is subject to the terms of the Mozilla Public
*     License, v. 2.0. If a copy of the MPL was not distributed with this
*     file, You can obtain one at http://mozilla.org/MPL/2.0/.
**/

#ifndef D3DX_GEOMETRY_HPP
#define D3DX_GEOMETRY_HPP

#include "D3DXConstants.hpp"
#include "D3DXFunctions.hpp"
#include "math_constant.hpp"

/**
 * @brief D3DXTriangleNormal computes the normal of a triangle with normalization.
 * @param pOut is the output normal.
 * @param p1 is the first vertex position of the triangle.
 * @param p2 is the second vertex position of the triangle.
 * @param p3 is the third vertex position of the triangle.
 * @return It returns the normal of the triangle (p1, p2, p3).
 */
static zD3DXVECTOR3 *zD3DXTriangleNormal(zD3DXVECTOR3 *pOut, const zD3DXVECTOR3 *p1, const zD3DXVECTOR3 *p2, const zD3DXVECTOR3 *p3)
{
	zD3DXVECTOR3 a, b;
    a.x = p1->x - p2->x;
    a.y = p1->y - p2->y;
    a.z = p1->z - p2->z;

    b.x = p2->x - p3->x;
    b.y = p2->y - p3->y;
    b.z = p2->z - p3->z;

    return zD3DXVec3Cross(pOut, &a, &b);
}

/**
 * @brief D3DXTriangleNormal2 computes the normal of a triangle without normalization.
 * @param pOut is the output normal.
 * @param p1 is the first vertex position of the triangle.
 * @param p2 is the second vertex position of the triangle.
 * @param p3 is the third vertex position of the triangle.
 * @return It returns the normal of the triangle (p1, p2, p3).
 */
static zD3DXVECTOR3 *zD3DXTriangleNormal2(zD3DXVECTOR3 *pOut, const zD3DXVECTOR3 *p1, const zD3DXVECTOR3 *p2, const zD3DXVECTOR3 *p3)
{
	zD3DXVECTOR3 a, b;
    a.x = p1->x - p2->x;
    a.y = p1->y - p2->y;
    a.z = p1->z - p2->z;

    b.x = p2->x - p3->x;
    b.y = p2->y - p3->y;
    b.z = p2->z - p3->z;

    return zD3DXVec3Cross(pOut, &a, &b);
}

/**
 * @brief D3DXTriangleArea computes the area of a triangle given its verticies.
 * @param v0 is the first vertex position of the triangle.
 * @param v1 is the second vertex position of the triangle.
 * @param v2 is the third vertex position of the triangle.
 * @return
 */
static float zD3DXTriangleArea(zD3DXVECTOR3 *v0, zD3DXVECTOR3 *v1, zD3DXVECTOR3 *v2)
{
    float v01 = zD3DXVecDistance(v0, v1);
    float v02 = zD3DXVecDistance(v0, v2);
    float v12 = zD3DXVecDistance(v1, v2);

    float s = (v01 + v02 + v12) / 2.0f;

    float area2 = s * (s - v01) * (s - v02) * (s - v12);
	return (area2 > 0.0f) ? sqrtf(area2) : 0.0f;
}

/**
 * @brief D3DXTriangleArea computes teh area of a triangle given the lengths of its edges.
 * @param v01 is the length of the edge (v0, v1).
 * @param v02 is the length of the edge (v0, v2).
 * @param v12 is the length of the edge (v1, v2).
 * @return
 */
static inline float zD3DXTriangleArea(float v01, float v02, float v12)
{
    float s = (v01 + v02 + v12) / 2.0f;

    float area2 = s * (s - v01) * (s - v02) * (s - v12);
    return (area2 > 0.0f) ? sqrtf(area2): 0.0f;
}

/**D3DXVec2ToVec3: converts a D3DXVECTOR2 into a D3DXVECTOR3*/
/**
 * @brief D3DXVec2ToVec3 converts a D3DXVECTOR2 into a D3DXVECTOR3
 * @param vec
 * @return
 */
static zD3DXVECTOR3 zD3DXVec2ToVec3(zD3DXVECTOR2 *vec)
{
	zD3DXVECTOR3 ret;

	ret.x = vec->x;
	ret.y = 0.0f;
	ret.z = vec->y;

	return ret;
}

/**
 * @brief D3DXVec3DistanceRayPoint computes the distance from a ray to a point.
 * @param rO is the ray origin.
 * @param rD is the ray direction.
 * @param p is the point.
 * @return
 */
static float zD3DXVec3DistanceRayPoint(const zD3DXVECTOR3 *rO, const zD3DXVECTOR3 *rD, const zD3DXVECTOR3 *p)
{
    zD3DXVECTOR3 tmp0 = (*rO) - (*p);
    float tmp1 = zD3DXVec3Dot(&tmp0, rD);
    zD3DXVECTOR3 tmp2 = (*rD) * tmp1;

    return zD3DXVecDistance(&tmp0, &tmp2);
}

/**
 * @brief D3DXVec3DistanceRayPointF computes the distance from a ray to a point.
 * @param rO is the ray origin.
 * @param rD is the ray direction.
 * @param p is the point.
 * @return
 */
static float zD3DXVec3DistanceRayPointF(const zD3DXVECTOR3 *rO, const zD3DXVECTOR3 *rD, const zD3DXVECTOR3 *p)
{
    zD3DXVECTOR3 tmp0 = (*p) - (*rO);
    return zD3DXVec3Dot(&tmp0, rD);
}

/**
 * @brief D3DXVec3Diffuse creates a diffuse vector given random values (u1, u2).
 * @param u1 is a value in [0, 1].
 * @param u2 is a value in [0, 1].
 * @param out
 * @return
 */
static zD3DXVECTOR3 *zD3DXVec3Diffuse(float u1, float u2, zD3DXVECTOR3 *out)
{
    #ifdef D3DX_POINTER_CHECK
        if(!out) {
            out = new zD3DXVECTOR3();
        }
    #endif

    float cosTheta = sqrtf(MAX(u1, 0.0f));
    float tmp = 1.0f - cosTheta * cosTheta;
    float sinTheta = tmp > 0.0f ? sqrtf(tmp) : 0.0f;

    float phi = C_PI_2 * u2;
	
    out->x = sinTheta * cosf(phi);
	out->y = cosTheta;
    out->z = sinTheta * sinf(phi);

	return out;
}

/**
 * @brief D3DXVec3Reflect reflects a direction (dir) against a normal (nor).
 * @param dir
 * @param nor
 * @param out
 * @return
 */
static zD3DXVECTOR3 *zD3DXVec3Reflect(const zD3DXVECTOR3 *dir, const zD3DXVECTOR3 *nor, zD3DXVECTOR3 *out)
{
    if(!out) {
		out = new zD3DXVECTOR3();
    }

    float dotx = 2.0f * zD3DXVec3Dot(nor, dir);

    out->x = dir->x - dotx * nor->x;
    out->y = dir->y - dotx * nor->y;
    out->z = dir->z - dotx * nor->z;
	zD3DXVec3Normalize(out);

	return out;
}

/**
 * @brief D3DXVec3ReflectNeg reflects a direction (-dir) against a normal (nor).
 * @param dir
 * @param nor
 * @param out
 * @return
 */
static zD3DXVECTOR3 *zD3DXVec3ReflectNeg(const zD3DXVECTOR3 *dir, const zD3DXVECTOR3 *nor, zD3DXVECTOR3 *out)
{
    #ifdef D3DX_POINTER_CHECK
        if(out) {
		    out = new zD3DXVECTOR3();
        }
    #endif
    
    float dotx = 2.0f * zD3DXVec3Dot(nor, dir);

    out->x = dotx * nor->x - dir->x;
    out->y = dotx * nor->y - dir->y;
    out->z = dotx * nor->z - dir->z;

	zD3DXVec3Normalize(out);

	return out;
}

/**
 * @brief D3DXVec3Refract refracts a directionr (dir) against a normal (nor) with (n1, n2).
 * @param dir
 * @param nor
 * @param n1
 * @param n2
 * @param out
 * @return
 */
static bool zD3DXVec3Refract(const zD3DXVECTOR3 *dir,const zD3DXVECTOR3 *nor, float n1, float n2, zD3DXVECTOR3 *out)
{
	zD3DXVECTOR3 I = (*dir);
	zD3DXVECTOR3 N = (*nor);

	float NdotI = zD3DXVec3Dot(&N, &I);
    float eta = n1 / n2;

    float k = 1.0f - eta * eta * (1.0f - NdotI * NdotI);
    if(k <= 0.0f) {
		#ifdef D3DX_TOTAL_REFRACTION_OFF
			*out = *dir;
			return true;
		#else
            zD3DXVec3Reflect(&I, &N, out);
			return false;
		#endif
    } else {
        *out =  I*eta - N * (sqrtf(MAX(k, 0.0f)) + eta * NdotI);
		return true;
	}
}

/**
 * @brief D3DXVec3RefractNeg refracts a directionr (-dir) against a normal (nor) with (n1,n2).
 * @param dir
 * @param nor
 * @param n1
 * @param n2
 * @param out
 * @return
 */
static bool zD3DXVec3RefractNeg(const zD3DXVECTOR3 *dir,const zD3DXVECTOR3 *nor, float n1, float n2, zD3DXVECTOR3 *out)
{
	zD3DXVECTOR3 I = (*dir);
	zD3DXVECTOR3 N = (*nor);

	float NdotI = - zD3DXVec3Dot(&N, &I);
    float eta = n1 / n2;

    float k = 1.0f - eta * eta * (1.0f - NdotI * NdotI);

    if(k <= 0.0f) {
		#ifdef D3DX_TOTAL_REFRACTION_OFF
			*out = *dir;
			return true;
		#else
            zD3DXVec3ReflectNeg(&I, &N, out);
			return false;
		#endif
    } else {
        *out =  - I * eta - N * (sqrtf(MAX(k, 0.0f)) + eta * NdotI);
		return true;
	}
}

#endif //D3DX_GEOMETRY_HPP
