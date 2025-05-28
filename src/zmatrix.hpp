#ifndef ZMATRIX_H_
#define ZMATRIX_H_

struct ZMatrix
{
    union {
        float m[4][4];
        struct
        {
            float _11, _12, _13, _14;
            float _21, _22, _23, _24;
            float _31, _32, _33, _34;
            float _41, _42, _43, _44;
        };
    };
};

#endif // ZMATRIX_H_
