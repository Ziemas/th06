/**
*     Copyright (C) 2008-2014  Francesco Banterle
*
*     This Source Code Form is subject to the terms of the Mozilla Public
*     License, v. 2.0. If a copy of the MPL was not distributed with this
*     file, You can obtain one at http://mozilla.org/MPL/2.0/.
**/

#ifndef D3DX_CONSTANTS_HPP
#define D3DX_CONSTANTS_HPP

#include "D3DXVECTOR3.hpp"
#include "D3DXVECTOR4.hpp"

//Empty D3DXVECTOR3
const zD3DXVECTOR3 VecNull   = zD3DXVECTOR3(0.0f);

//Empty D3DXVECTOR4
const zD3DXVECTOR4 Vec4Null  = zD3DXVECTOR4(0.0f);

//Constant Vector
const zD3DXVECTOR3 VecHalf   = zD3DXVECTOR3(0.5f);
const zD3DXVECTOR3 VecOne    = zD3DXVECTOR3(1.0f);

//Space Axis
const zD3DXVECTOR3 E0        = zD3DXVECTOR3(1.0f, 0.0f, 0.0f);
const zD3DXVECTOR3 E1        = zD3DXVECTOR3(0.0f, 1.0f, 0.0f);
const zD3DXVECTOR3 E2        = zD3DXVECTOR3(0.0f, 0.0f, 1.0f);

#endif //D3DX_CONSTANTS_HPP
