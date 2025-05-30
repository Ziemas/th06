#ifndef ZIMAGE_H_
#define ZIMAGE_H_

#include "stb_image.h"

class zImage
{
  public:
    ~zImage();

    char *Pixels()
    {
        return (char *)m_p;
    };

    int Width()
    {
        return m_w;
    };
    int Height()
    {
        return m_h;
    };

    int ByteSize()
    {
        return m_w * m_h * 4;
    }

    static zImage *LoadImageMem(void *data, int len);

  private:
    zImage();
    int m_w, m_h, m_ch;
    stbi_uc *m_p;
};

#endif // ZIMAGE_H_
