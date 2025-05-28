/**
*     Copyright (C) 2008-2014  Francesco Banterle
*
*     This Source Code Form is subject to the terms of the Mozilla Public
*     License, v. 2.0. If a copy of the MPL was not distributed with this
*     file, You can obtain one at http://mozilla.org/MPL/2.0/.
**/

#ifndef D3DX_BOUNDING_BOX_HPP
#define D3DX_BOUNDING_BOX_HPP

#include "D3DXVECTOR3.hpp"
#include "D3DXMATRIX.hpp"

/**
 * @brief D3DXExtendBBox computes a bounding box (bMax,bMin) is expanded according to p.
 * @param bMax
 * @param bMin
 * @param p
 */
static void zD3DXExtendBBox(zD3DXVECTOR3 *bMax, zD3DXVECTOR3 *bMin, const zD3DXVECTOR3 *p)
{
	//Max
    bMax->x = MAX(p->x, bMax->x);
    bMax->y = MAX(p->y, bMax->y);
    bMax->z = MAX(p->z, bMax->z);
	//Min
    bMin->x = MIN(p->x, bMin->x);
    bMin->y = MIN(p->y, bMin->y);
    bMin->z = MIN(p->z, bMin->z);
}

/**
 * @brief D3DXMinBBox calculates the minimum box.
 * @param max
 * @param min
 * @param bMax
 * @param bMin
 */
static void zD3DXMinBBox(zD3DXVECTOR3 *max, zD3DXVECTOR3 *min, const zD3DXVECTOR3 *bMax,const zD3DXVECTOR3 *bMin)
{
    if(bMax->x < max->x) max->x = bMax->x;
    if(bMax->y < max->y) max->y = bMax->y;
    if(bMax->z < max->z) max->z = bMax->z;

    if(bMin->x > min->x) min->x = bMin->x;
    if(bMin->y > min->y) min->y = bMin->y;
    if(bMin->z > min->z) min->z = bMin->z;
}

/**
 * @brief D3DXCheckPointBBox checks if a point p is in a bounding box (bMax,bMin).
 * @param bMax
 * @param bMin
 * @param p
 * @return
 */
static bool zD3DXCheckPointBBox(const zD3DXVECTOR2 *bMax, const zD3DXVECTOR2 *bMin, const zD3DXVECTOR2 *p)
{
    return( (p->x >= bMin->x) &&
            (p->y >= bMin->y) &&
            (p->x <= bMax->x) &&
            (p->y <= bMax->y));
}

/**
 * @brief D3DXCheckPointBBox checks if a point p is in a bounding box (bMax, bMin).
 * @param bMax is the maximum of the input bounding box.
 * @param bMin is the minimum of the input bounding box.
 * @param p is an input point.
 * @return It returns true if the p is inside the bounding box, false otherwise.
 */
static bool zD3DXCheckPointBBox(const zD3DXVECTOR3 *bMax, const zD3DXVECTOR3 *bMin, const zD3DXVECTOR3 *p)
{
    return( (p->x >= bMin->x) &&
            (p->y >= bMin->y) &&
            (p->z >= bMin->z) &&
            (p->x <= bMax->x) &&
            (p->y <= bMax->y) &&
            (p->z <= bMax->z));
}

/**
 * @brief D3DXCheckPointBBoxLength checks if a point p is in a bounding box defined by its center and its length.
 * @param bCenter is the center of the bounding box.
 * @param bRadius is the lenght of the box for each directions.
 * @param p is an input point.
 * @return It returns true if the p is inside the bounding box, false otherwise.
 */
static bool zD3DXCheckPointBBoxLength(const zD3DXVECTOR3 &bCenter, const float bRadius, const zD3DXVECTOR3 &p)
{
    return (p.x >= (bCenter.x - bRadius)) && (p.x <= (bCenter.x + bRadius)) &&
           (p.y >= (bCenter.y - bRadius)) && (p.y <= (bCenter.y + bRadius)) &&
           (p.z >= (bCenter.z - bRadius)) && (p.z <= (bCenter.z + bRadius));
}

/**
 * @brief D3DXCheckPlaneBBox checks if a plane (nor, d) intersects a bounding box (bMax,bMin).
 * @param bMax is the maximum of the input bounding box.
 * @param bMin is the minimum of the input bounding box.
 * @param nor is the normal of the input plane.
 * @param d is the distance of the input plane.
 * @return It returns true if the bounding box intersects the plane , false otherwise.
 */
static bool zD3DXCheckPlaneBBox(const zD3DXVECTOR3 *bMax, const zD3DXVECTOR3 *bMin,
                        const zD3DXVECTOR3 *nor, float d)
{

	zD3DXVECTOR3 vMax, vMin;
    for(int i=0; i<3; i++) {
        if((*nor)[i] > 0.0f) {
			vMax[i] = (*bMax)[i];
			vMin[i] = (*bMin)[i];
        } else {
			vMax[i] = (*bMin)[i];
			vMin[i] = (*bMax)[i];
		}
	}

    if((zD3DXVec3Dot(nor, &vMax) + d) < 0.0f) {
		return false;
    }
	
    if((zD3DXVec3Dot(nor, &vMin) + d) > 0.0f) {
		return false;
    } else {
		return true;
    }
}

/**
 * @brief D3DXBBoxFromSphere computes bounding box froma a sphere.
 * @param center is the center of the sphere.
 * @param radius is the radius of the sphere.
 * @param bMax is the maximum of the output bounding box.
 * @param bMin is the minimum of the output bounding box.
 */
static void zD3DXBBoxFromSphere(const zD3DXVECTOR3 *center, float radius,
                        zD3DXVECTOR3 *bMax, zD3DXVECTOR3 *bMin)
{
    zD3DXVECTOR3 rVec = zD3DXVECTOR3(radius, radius, radius);
    *bMax = *center + rVec;
    *bMin = *center - rVec;
}

/**
 * @brief D3DXBBoxFromTri computes bounding box from a triangle.
 * @param v0 is the first vertex in the triangle.
 * @param v1 is the second vertex in the triangle.
 * @param v2 is the third vertex in the triandle.
 * @param bMax is the maximum of the output bounding box.
 * @param bMin is the minimum of the output bounding box.
 */
static void zD3DXBBoxFromTri(const zD3DXVECTOR3 *v0, const zD3DXVECTOR3 *v1, const zD3DXVECTOR3 *v2,
                    zD3DXVECTOR3 *bMax,zD3DXVECTOR3 *bMin)
{

	bMax->x = v0->x;
	bMax->y = v0->y;
	bMax->z = v0->z;

	bMin->x = v0->x;
	bMin->y = v0->y;
	bMin->z = v0->z;

	//Min X
	bMin->x = bMin->x > v1->x ? v1->x : bMin->x;
	bMin->x = bMin->x > v2->x ? v2->x : bMin->x;
	//Min Y
	bMin->y = bMin->y > v1->y ? v1->y : bMin->y;
	bMin->y = bMin->y > v2->y ? v2->y : bMin->y;
	//Min Z
	bMin->z = bMin->z > v1->z ? v1->z : bMin->z;
	bMin->z = bMin->z > v2->z ? v2->z : bMin->z;

	//Max X
	bMax->x = bMax->x < v1->x ? v1->x : bMax->x;
	bMax->x = bMax->x < v2->x ? v2->x : bMax->x;
	//Max Y
	bMax->y = bMax->y < v1->y ? v1->y : bMax->y;
	bMax->y = bMax->y < v2->y ? v2->y : bMax->y;
	//Max Z
	bMax->z = bMax->z < v1->z ? v1->z : bMax->z;
	bMax->z = bMax->z < v2->z ? v2->z : bMax->z;
}

/**
 * @brief D3DXCheckBBoxBBox checks if two bounding boxes overlaps.
 * @param aMax is the maximum of the bounding box A
 * @param aMin is the minimum of the bounding box A
 * @param bMax is the maximum of the bounding box B
 * @param bMin is the minimum of the bounding box B
 * @return
 */
static bool zD3DXCheckBBoxBBox(const zD3DXVECTOR3 *aMax, const zD3DXVECTOR3 *aMin,
                       const zD3DXVECTOR3 *bMax,const  zD3DXVECTOR3 *bMin)
{
    //X axis
    if(aMin->x > bMin->x) {
        if(aMin->x > bMax->x)
			return false;
    } else {
        if(bMin->x > aMax->x)
			return false;
	}

    //Y axis
    if(aMin->y > bMin->y) {
        if(aMin->y > bMax->y)
			return false;
    } else {
		if(bMin->y>aMax->y) 
			return false;
	}

    //Z axis
    if(aMin->z > bMin->z) {
        if(aMin->z > bMax->z)
			return false;
    } else {
        if(bMin->z > aMax->z)
			return false;
	}

	return true;
}

/**
 * @brief D3DXAreaBBox calculates the area of the bounding box.
 * @param bMax is the maximum of the bounding box
 * @param bMin is the minimum of the bounding box
 * @return
 */
static float zD3DXAreaBBox(const zD3DXVECTOR3 *bMax, const zD3DXVECTOR3 *bMin)
{
    zD3DXVECTOR3 size = *bMax - *bMin;

    float ret =	size.x * size.y +
                size.x * size.z +
                size.z * size.y;

    return ret * 2.0f;
}

/**
 * @brief D3DXCheckSphereSphere
 * @param c0 is the center of sphere 0
 * @param c1 is the center of sphere 1
 * @param r0 is the radius of sphere 0
 * @param r1 is the radius of sphere 1
 * @return
 */
static bool zD3DXCheckSphereSphere(const zD3DXVECTOR3 *c0, const zD3DXVECTOR3 *c1, float r0, float r1)
{
	return (zD3DXVecDistance(c0, c1) <= (r0 + r1));
}

/**
 * @brief D3DXCheckSphereBBox
 * @param bMax is the maximum of the bounding box
 * @param bMin is the minimum of the bounding box
 * @param sph_center is the sphere's center
 * @param sph_radius2 is the sphere's center
 * @return
 */
static bool zD3DXCheckSphereBBox(const zD3DXVECTOR3 *bMax, const zD3DXVECTOR3 *bMin,
                         const zD3DXVECTOR3 *sph_center, float sph_radius2)
{
    float dmin = 0.0f;
	for(int i=0; i<3; i++) {
		if((*sph_center)[i] < (*bMin)[i]) {
			float tmp = (*sph_center)[i] - (*bMin)[i];
            dmin += tmp * tmp;
		} else {
			if((*sph_center)[i] > (*bMax)[i]) {
				float tmp = (*sph_center)[i] - (*bMax)[i];
                dmin += tmp * tmp;
			}
		}
    }

    return (dmin <= (sph_radius2));
}

/**
 * @brief D3DXClosestCube computes the closest cube from a starting bounding box (bMax,bMin).
 * @param bMax
 * @param bMin
 * @param aMax
 * @param aMin
 */
static void zD3DXClosestCube(const zD3DXVECTOR3 *bMax, const zD3DXVECTOR3 *bMin, zD3DXVECTOR3 *aMax, zD3DXVECTOR3 *aMin)
{
    zD3DXVECTOR3 len = *bMax - *bMin;
    float maxLen = MAX(MAX(len.x, len.y), len.z) / 2.0f + 1e-6f;
    zD3DXVECTOR3 c = (*bMax + *bMin) / 2.0f;

    len = zD3DXVECTOR3(maxLen, maxLen, maxLen);

    *aMax = c + len;
    *aMin = c - len;

    *aMax = zD3DXVECTOR3( 1.0f,  1.0f,  1.0f);
    *aMin = zD3DXVECTOR3(-1.0f, -1.0f, -1.0f);
}

/**
 * @brief D3DXBBoxClamp
 * @param max
 * @param min
 * @param p
 */
static void zD3DXBBoxClamp(const zD3DXVECTOR3 *max, const zD3DXVECTOR3 *min, zD3DXVECTOR3 *p)
{
	p->x = (p->x < min->x) ? min->x : p->x;
	p->y = (p->y < min->y) ? min->y : p->y;
	p->z = (p->z < min->z) ? min->z : p->z;

	p->x = (p->x > max->x) ? max->x : p->x;
	p->y = (p->y > max->y) ? max->y : p->y;
	p->z = (p->z > max->z) ? max->z : p->z;
}

/**
 * @brief D3DXBBoxLocal
 * @param max
 * @param min
 * @param p
 */
static void zD3DXBBoxLocal(const zD3DXVECTOR3 *max, const zD3DXVECTOR3 *min, zD3DXVECTOR3 *p)
{
	zD3DXVECTOR3 len = *max - *min;
    *p = (*p - *min) / len;
}

/**
 * @brief D3DXBBoxApplyTransform
 * @param bbox
 * @param transform
 * @param bboxOut
 */
static void zD3DXBBoxApplyTransform(const zD3DXVECTOR3 *bMax, const zD3DXVECTOR3 *bMin, const zD3DXMATRIX *transform,
                            zD3DXVECTOR3 *pMax, zD3DXVECTOR3 *pMin)
{
    zD3DXVECTOR3 frame[8];
    frame[0] = *bMin;
    frame[1] = zD3DXVECTOR3(bMax->x, bMin->y, bMax->z);
    frame[2] = zD3DXVECTOR3(bMin->x, bMin->y, bMax->z);
    frame[3] = zD3DXVECTOR3(bMax->x, bMin->y, bMin->z);

    frame[4] = *bMax;
    frame[5] = zD3DXVECTOR3(bMin->x, bMax->y, bMin->z);
    frame[6] = zD3DXVECTOR3(bMin->x, bMax->y, bMax->z);
    frame[7] = zD3DXVECTOR3(bMax->x, bMax->y, bMin->z);

    for(int i=0;i<8;i++) {
        zD3DXVECTOR3 tmp;
        zD3DXVec3TransformCoord(&tmp, &frame[i], transform);
        frame[i] = tmp;
    }

    *pMax = frame[0];
    *pMin = frame[0];

    for(int i=1;i<8;i++) {
        zD3DXExtendBBox(pMax, pMin, &frame[i]);
    }
}

/**
 * @brief D3DXBBoxClampLocal
 * @param max
 * @param min
 * @param p
 */
static void zD3DXBBoxClampLocal(const zD3DXVECTOR3 *max, const zD3DXVECTOR3 *min, zD3DXVECTOR3 *p)
{
    zD3DXBBoxClamp(max, min, p);
    zD3DXBBoxLocal(max, min, p);
}

/**
 * @brief Bool2Ind
 * @param x
 * @param y
 * @param z
 * @return
 */
static inline int Bool2Ind(bool x, bool y, bool z)
{
    return (x << 0) + (y << 1) + (z << 2);
}

/**
 * @brief Ind2Bool
 * @param ind
 * @param pos
 * @return
 */
static inline bool Ind2Bool(int ind, int pos)
{
    return (ind >> pos) & 0x1;
}

/**
 * @brief D3DXBoxOctant calculates an octant of a box.
 * @param max
 * @param min
 * @param maxOut
 * @param minOut
 * @param ind
 */
static void zD3DXBoxOctant(zD3DXVECTOR3 *max, zD3DXVECTOR3 *min, zD3DXVECTOR3 *maxOut, zD3DXVECTOR3 *minOut, int ind)
{
    for(int i=0;i<3;i++) {
        if(Ind2Bool(ind,i)) {
            (*maxOut)[i] = ((*max)[i] + (*min)[i]) / 2.0f;
			(*minOut)[i] = (*min)[i];
        } else {
			(*maxOut)[i] = (*max)[i];
            (*minOut)[i] = ((*max)[i] + (*min)[i]) / 2.0f;
        }
    }
}

/**
 * @brief D3DXVec3ShiftOctant calculates an octant shift vector.
 * @param vecOut
 * @param ind
 * @return
 */
static zD3DXVECTOR3 *zD3DXVec3ShiftOctant(zD3DXVECTOR3 *vecOut, int ind)
{
    for(int i=0;i<3;i++) {
        if(Ind2Bool(ind,i)) {
			(*vecOut)[i] = -1.0f;
        } else {
			(*vecOut)[i] =  1.0f;
        }
    }
    return vecOut;
}

#endif //D3DX_BOUNDING_BOX_HPP
