#include "zrender.h"
#include "FileSystem.hpp"
#include "d3d8.h"
#include "d3dx8.h"
#include <cstdio>

#include "stb_image.h"

void copy_rgba_to_argb(void *dst, void *src, int len)
{
    unsigned *d = (unsigned *)dst, *s = (unsigned *)src;
    unsigned tmp;

    len >>= 2;

    while (len--)
    {
        tmp = *s;

        *d = (tmp & 0x000000ff) << 16 | (tmp & 0x0000ff00) << 0 | (tmp & 0x00ff0000) >> 16 | (tmp & 0xff000000);

        s++;
        d++;
    }
}

int zLoadPixelsFromFile(char *file, stbi_uc **px, zIMAGE_INFO *info_out)
{
    zIMAGE_INFO info;
    u8 *img_data = th06::FileSystem::OpenPath(file, 0);
    stbi_uc *pixels = stbi_load_from_memory(img_data, th06::g_LastFileSize, &info.Width, &info.Height, 0, 4);
    if (!pixels)
    {
        return -1;
    }

    if (info_out)
    {
        *info_out = info;
    }

    if (px)
    {
        *px = pixels;
    }

    return 0;
}

void zFreePixels(stbi_uc *px) {
    stbi_image_free(px);
}

HRESULT zLoadSurfaceFromFileInMemory(IDirect3DSurface8 *pDestSurface, const void *pSrcData, UINT SrcDataSize,
                                     zIMAGE_INFO *pSrcInfo)
{
    D3DLOCKED_RECT rect;
    RECT dst;
    zIMAGE_INFO info;
    stbi_uc *p;

    p = stbi_load_from_memory((stbi_uc *)pSrcData, SrcDataSize, &info.Width, &info.Height, 0, 4);
    if (!p)
    {
        return -1;
    }

    dst.left = 0;
    dst.top = 0;
    dst.right = info.Width;
    dst.bottom = info.Height;

    if (pDestSurface->LockRect(&rect, &dst, D3DLOCK_NO_DIRTY_UPDATE) != D3D_OK)
    {
        return -1;
    }

    copy_rgba_to_argb(rect.pBits, p, info.Width * info.Height * 4);

    pDestSurface->UnlockRect();

    if (pSrcInfo)
    {
        *pSrcInfo = info;
    }

    return D3D_OK;
}

HRESULT zLoadSurfaceFromSurface(IDirect3DSurface8 *dst_surface, const RECT *dst_rect, IDirect3DSurface8 *src_surface,
                                const RECT *src_rect, DWORD filter)

{
    HRESULT res;

    if (filter == 0) {
        filter = D3DX_FILTER_NONE;
    }

    res = D3DXLoadSurfaceFromSurface(dst_surface, 0, dst_rect, src_surface, 0, src_rect, filter, 0);

    if (res != D3D_OK)
    {
        printf("fuck 2\n");
        return res;
    }

    return res;
}
