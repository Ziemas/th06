/**
 *     Copyright (C) 2008-2014  Francesco Banterle
 *
 *     This Source Code Form is subject to the terms of the Mozilla Public
 *     License, v. 2.0. If a copy of the MPL was not distributed with this
 *     file, You can obtain one at http://mozilla.org/MPL/2.0/.
 **/

#ifndef D3DXVECTOR3_HPP
#define D3DXVECTOR3_HPP

class zVec3
{
  public:
    float x, y, z;

    zVec3()
    {
    }

    zVec3(const float *a)
    {
        this->x = a[0];
        this->y = a[1];
        this->z = a[2];
    }

    zVec3(float a)
    {
        this->x = a;
        this->y = a;
        this->z = a;
    }

    zVec3(float x, float y, float z)
    {
        this->x = x;
        this->y = y;
        this->z = z;
    }

    zVec3 operator-(const zVec3 &v) const
    {
        return zVec3(x - v.x, y - v.y, z - v.z);
    }

    zVec3 operator-() const
    {
        return zVec3(-x, -y, -z);
    }

    void operator-=(const zVec3 &v)
    {
        x -= v.x;
        y -= v.y;
        z -= v.z;
    }

    zVec3 operator+(const zVec3 &v) const
    {
        return zVec3(x + v.x, y + v.y, z + v.z);
    }

    void operator+=(const zVec3 &v)
    {
        x += v.x;
        y += v.y;
        z += v.z;
    }

    zVec3 operator/(const zVec3 &v) const
    {
        return zVec3(x / v.x, y / v.y, z / v.z);
    }

    void operator/=(const zVec3 &v)
    {
        x /= v.x;
        y /= v.y;
        z /= v.z;
    }

    zVec3 operator*(const zVec3 &v) const
    {
        return zVec3(x * v.x, y * v.y, z * v.z);
    }

    zVec3 operator*(const float &a) const
    {
        return zVec3(x * a, y * a, z * a);
    }

    void operator*=(const float &a)
    {
        x *= a;
        y *= a;
        z *= a;
    }

    zVec3 operator/(const float &a) const
    {
        if (a != 0.0f)
            return zVec3(x / a, y / a, z / a);
        else
            return zVec3(x, y, z);
    }

    void operator/=(const float &a)
    {
        if (a != 0.0f)
        {
            x /= a;
            y /= a;
            z /= a;
        }
    }

    float operator[](int i) const
    {
        switch (i)
        {
        case 0:
            return x;
            break;
        case 1:
            return y;
            break;
        case 2:
            return z;
            break;
        }
        return -1.0f;
    }

    float &operator[](int i)
    {
        switch (i)
        {
        case 0:
            return x;
            break;
        case 1:
            return y;
            break;
        case 2:
            return z;
            break;
        }
        return x;
    }
};

static zVec3 operator*(float f, const zVec3 &v)
{
    return zVec3(f * v.x, f * v.y, f * v.z);
}

#endif // D3DXVECTOR3_HPP
