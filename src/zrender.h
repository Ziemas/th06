#ifndef ZRENDER_H_
#define ZRENDER_H_

#include "d3d8.h"
#include "stb_image.h"

struct zIMAGE_INFO
{
    int Width;
    int Height;
};

void copy_rgba_to_argb(void *dst, void *src, int len);
int zLoadPixelsFromFile(char *file, stbi_uc **px, zIMAGE_INFO *info);
void zFreePixels(stbi_uc *px);

HRESULT zLoadSurfaceFromFileInMemory(IDirect3DSurface8 *pDestSurface, const void *pSrcData, UINT SrcDataSize,
                                     zIMAGE_INFO *pSrcInfo);

HRESULT zLoadSurfaceFromSurface(IDirect3DSurface8 *dst_surface, const RECT *dst_rect, IDirect3DSurface8 *src_surface,
                                const RECT *src_rect, DWORD filter);

#endif // ZRENDER_H_
