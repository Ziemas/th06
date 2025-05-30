#ifndef ZRENDER_H_
#define ZRENDER_H_

#include "d3d8.h"

struct zIMAGE_INFO
{
    unsigned int Width;
    unsigned int Height;
};

HRESULT zLoadSurfaceFromFileInMemory(IDirect3DSurface8 *pDestSurface, const void *pSrcData, UINT SrcDataSize,
                                     zIMAGE_INFO *pSrcInfo);

HRESULT zLoadSurfaceFromSurface(IDirect3DSurface8 *dst_surface, const RECT *dst_rect, IDirect3DSurface8 *src_surface,
                                const RECT *src_rect, DWORD filter);

HRESULT zCreateTextureFromFileInMemoryEx(struct IDirect3DDevice8 *device, const void *srcdata, UINT srcdatasize,
                                         D3DFORMAT format, D3DPOOL pool, DWORD filter, D3DCOLOR colorkey,
                                         struct IDirect3DTexture8 **texture);

#endif // ZRENDER_H_
