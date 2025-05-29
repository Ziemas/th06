#include "zmath.h"

zVec3 *zVec3Project(zVec3 *pOut, const zVec3 *pV, const D3DVIEWPORT8 *pViewport,
                           const zMatrix *pProjection, const zMatrix *pView, const zMatrix *pWorld)
{
    zMatrix m;

    zMatrixIdentity(&m);
    if (pWorld)
        zMatrixMultiply(&m, &m, pWorld);
    if (pView)
        zMatrixMultiply(&m, &m, pView);
    if (pProjection)
        zMatrixMultiply(&m, &m, pProjection);

    zVec3TransformCoord(pOut, pV, &m);

    if (pViewport)
    {
        pOut->x = pViewport->X + (1.0f + pOut->x) * pViewport->Width / 2.0f;
        pOut->y = pViewport->Y + (1.0f - pOut->y) * pViewport->Height / 2.0f;
        pOut->z = pViewport->MinZ + pOut->z * (pViewport->MaxZ - pViewport->MinZ);
    }

    return pOut;
}
