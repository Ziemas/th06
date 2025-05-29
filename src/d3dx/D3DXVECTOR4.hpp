/**
 *     Copyright (C) 2008-2014  Francesco Banterle
 *
 *     This Source Code Form is subject to the terms of the Mozilla Public
 *     License, v. 2.0. If a copy of the MPL was not distributed with this
 *     file, You can obtain one at http://mozilla.org/MPL/2.0/.
 **/

#ifndef D3DXVECTOR4_HPP
#define D3DXVECTOR4_HPP

class zVec4
{
  public:
    float x, y, z, w;

    zVec4()
    {
    }

    zVec4(float a)
    {
        x = y = z = w = a;
    }

    zVec4(float x, float y, float z, float w)
    {
        this->x = x;
        this->y = y;
        this->z = z;
        this->w = w;
    }

    zVec4 operator-(const zVec4 &v) const
    {
        return zVec4(x - v.x, y - v.y, z - v.z, w - v.w);
    }

    zVec4 operator-() const
    {
        return zVec4(-x, -y, -z, -w);
    }

    void operator-=(const zVec4 &v)
    {
        x -= v.x;
        y -= v.y;
        z -= v.z;
        w -= v.w;
    }

    zVec4 operator+(const zVec4 &v) const
    {
        return zVec4(x + v.x, y + v.y, z + v.z, w + v.w);
    }

    void operator+=(const zVec4 &v)
    {
        x += v.x;
        y += v.y;
        z += v.z;
        w += v.w;
    }

    zVec4 operator/(const zVec4 &v) const
    {
        return zVec4(x / v.x, y / v.y, z / v.z, w / v.w);
    }

    void operator/=(const zVec4 &v)
    {
        x /= v.x;
        y /= v.y;
        z /= v.z;
        w /= v.w;
    }

    zVec4 operator*(const zVec4 &v) const
    {
        return zVec4(x * v.x, y * v.y, z * v.z, w * v.w);
    }

    zVec4 operator*(const float &a) const
    {
        return zVec4(x * a, y * a, z * a, w * a);
    }

    void operator*=(const float &a)
    {
        x *= a;
        y *= a;
        z *= a;
        w *= a;
    }

    zVec4 operator=(const float v[4])
    {
        return zVec4(v[0], v[1], v[2], v[3]);
    }

    zVec4 operator/(const float &a) const
    {
        if (a != 0.0f)
            return zVec4(x / a, y / a, z / a, w / a);
        else
            return zVec4(x, y, z, w);
    }

    void operator/=(const float &a)
    {
        if (a != 0.0f)
        {
            x /= a;
            y /= a;
            z /= a;
            w /= a;
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
        case 3:
            return w;
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
        case 3:
            return w;
            break;
        }
        return x;
    }
};

#endif // D3DXVECTOR4_HPP
