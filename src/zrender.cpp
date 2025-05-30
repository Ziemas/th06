#include "zrender.h"
#include "d3d8.h"
#include "d3dx8.h"
#include <cstdio>

HRESULT zLoadSurfaceFromFileInMemory(IDirect3DSurface8 *pDestSurface, const void *pSrcData, UINT SrcDataSize,
                                     zIMAGE_INFO *pSrcInfo)
{
    HRESULT res;
    D3DXIMAGE_INFO info;

    res = D3DXLoadSurfaceFromFileInMemory(pDestSurface, 0, 0, pSrcData, SrcDataSize, 0, D3DX_FILTER_NONE, 0, &info);
    if (res != D3D_OK)
    {
        printf("fuck 1\n");
        return res;
    }

    pSrcInfo->Width = info.Width;
    pSrcInfo->Height = info.Height;
    return res;
}

HRESULT zLoadSurfaceFromSurface(IDirect3DSurface8 *dst_surface, const RECT *dst_rect, IDirect3DSurface8 *src_surface,
                                const RECT *src_rect, DWORD filter)

{
    HRESULT res;

    res = D3DXLoadSurfaceFromSurface(dst_surface, 0, dst_rect, src_surface, 0, src_rect, filter, 0);

    if (res != D3D_OK)
    {
        printf("fuck 2\n");
        return res;
    }

    return res;
}

HRESULT zCreateTextureFromFileInMemoryEx(struct IDirect3DDevice8 *device, const void *srcdata, UINT srcdatasize,
                                         D3DFORMAT format, D3DPOOL pool, DWORD filter, D3DCOLOR colorkey,
                                         struct IDirect3DTexture8 **texture)
{

    HRESULT res;

    res = D3DXCreateTextureFromFileInMemoryEx(device, srcdata, srcdatasize, 0, 0, 0, 0, format, pool, filter, D3DX_DEFAULT,
                                              colorkey, 0, 0, texture);

    if (res != D3D_OK)
    {
        printf("fuck 3\n");
        return res;
    }

    return res;
}
