#include "zimage.h"

#define STB_IMAGE_IMPLEMENTATION
#include "stb_image.h"

static void rgba_to_argb(char *p, int size)
{
    unsigned char r, g, b, a;
    unsigned *c = (unsigned *)p;
    size >>= 2;

    while (size--)
    {
        r = (*c & 0xff000000) >> 24;
        g = (*c & 0x00ff0000) >> 16;
        b = (*c & 0x0000ff00) >> 8;
        a = (*c & 0x000000ff) >> 0;

        *c = (a << 24) | (r << 16) | (g << 8) | (b << 0);
        c++;
    }
}

zImage::zImage()
{
}

zImage::~zImage()
{
    stbi_image_free(m_p);
}

zImage *zImage::LoadImageMem(void *data, int len)
{
    zImage *ret = new zImage();
    ret->m_p = stbi_load_from_memory((stbi_uc *)data, len, &ret->m_w, &ret->m_h, &ret->m_ch, STBI_rgb_alpha);
    if (!ret->m_p)
    {
        return 0;
    }

    rgba_to_argb((char *)ret->m_p, ret->ByteSize());

    return ret;
}
