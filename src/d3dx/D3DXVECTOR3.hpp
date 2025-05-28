/**
*     Copyright (C) 2008-2014  Francesco Banterle
*
*     This Source Code Form is subject to the terms of the Mozilla Public
*     License, v. 2.0. If a copy of the MPL was not distributed with this
*     file, You can obtain one at http://mozilla.org/MPL/2.0/.
**/

#ifndef D3DXVECTOR3_HPP
#define D3DXVECTOR3_HPP

/**
 * @brief The D3DXVECTOR3 class
 */
class zD3DXVECTOR3
{
public:
    float x, y, z;

    /**
     * @brief D3DXVECTOR3
     */
    zD3DXVECTOR3()
    {
	}

    /**
     * @brief D3DXVECTOR3
     * @param a
     */
    zD3DXVECTOR3(float a)
    {
		this->x = a;
		this->y = a;
		this->z = a;
	}

    /**
     * @brief D3DXVECTOR3
     * @param x
     * @param y
     * @param z
     */
    zD3DXVECTOR3(float x, float y, float z)
    {
		this->x = x;
		this->y = y;
		this->z = z;
	}

    /**
     * @brief operator -
     * @param v
     * @return
     */
    zD3DXVECTOR3 operator -(const zD3DXVECTOR3 &v) const
    {
        return zD3DXVECTOR3(x - v.x, y - v.y, z - v.z);
	}

    /**
     * @brief operator -
     * @return
     */
    zD3DXVECTOR3 operator -()const
    {
		return zD3DXVECTOR3(-x, -y, -z);
	}

    /**
     * @brief operator -=
     * @param v
     */
    void operator -=(const zD3DXVECTOR3 &v)
    {
		x -= v.x;
		y -= v.y;
		z -= v.z;
	}

    /**
     * @brief operator +
     * @param v
     * @return
     */
    zD3DXVECTOR3 operator +(const zD3DXVECTOR3 &v) const
    {
        return zD3DXVECTOR3(x + v.x, y + v.y, z + v.z);
	}

    /**
     * @brief operator +=
     * @param v
     */
    void operator +=(const zD3DXVECTOR3 &v)
    {
		x += v.x;
		y += v.y;
		z += v.z;
	}

    /**
     * @brief operator /
     * @param v
     * @return
     */
    zD3DXVECTOR3 operator /(const zD3DXVECTOR3 &v) const
    {
		return zD3DXVECTOR3(x/v.x, y/v.y, z/v.z);
	}

    void operator /=(const zD3DXVECTOR3 &v)
    {
		x /= v.x;
		y /= v.y;
		z /= v.z;
	}

    /**
     * @brief operator *
     * @param v
     * @return
     */
    zD3DXVECTOR3 operator *(const zD3DXVECTOR3 &v)const
    {
		return zD3DXVECTOR3(x*v.x,y*v.y,z*v.z);
	}

    /**
     * @brief operator *
     * @param a
     * @return
     */
    zD3DXVECTOR3 operator *(const float &a) const
    {
		return zD3DXVECTOR3(x*a, y*a, z*a);
	}

    /**
     * @brief operator *=
     * @param a
     */
    void operator *=(const float &a)
    {
		x *= a;
		y *= a;
		z *= a;
	}

    /**
     * @brief operator /
     * @param a
     * @return
     */
    zD3DXVECTOR3 operator /(const float &a)const
    {
        if(a != 0.0f)
            return zD3DXVECTOR3(x / a, y / a, z / a);
		else
			return zD3DXVECTOR3(x,y,z);
	}

    /**
     * @brief operator /=
     * @param a
     */
    void operator /=(const float &a)
    {
        if(a != 0.0f){
			x /= a;
			y /= a;
			z /= a;
		}
	}

    /**
     * @brief operator []
     * @param i
     * @return
     */
    float operator [](int i) const
    {
		switch(i){
			case 0:
				return x; break;
			case 1:
				return y; break;
			case 2:
				return z; break;
		}
		return -1.0f;
	}

    /**
     * @brief operator []
     * @param i
     * @return
     */
    float &operator [](int i)
    {
		switch(i){
			case 0:
				return x; break;
			case 1:
				return y; break;
			case 2:
				return z; break;
		}
		return x;
	}
};

static zD3DXVECTOR3 operator * (float f, const zD3DXVECTOR3 &v)
{
    return zD3DXVECTOR3(f*v.x, f*v.y, f*v.z);
}



#endif //D3DXVECTOR3_HPP
