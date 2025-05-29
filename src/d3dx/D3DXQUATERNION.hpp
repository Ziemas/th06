/**
 *     Copyright (C) 2008-2014  Francesco Banterle
 *
 *     This Source Code Form is subject to the terms of the Mozilla Public
 *     License, v. 2.0. If a copy of the MPL was not distributed with this
 *     file, You can obtain one at http://mozilla.org/MPL/2.0/.
 **/

#ifndef D3DXQUATERNION_HPP
#define D3DXQUATERNION_HPP

#include "D3DXFunctions.hpp"

class zQuaternion
{
  public:
    float x, y, z, w;

    zQuaternion()
    {
        x = 0.0f;
        y = 0.0f;
        z = 0.0f;
        w = 1.0f;
    }
};

#endif // D3DXQUATERNION_HPP
