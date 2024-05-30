#ifndef CONVOLUTION_H
#define CONVOLUTION_H
#include "matrix.h"

class convolution :public matrix{
public:
    convolution(matrix& m1, matrix& m2);
};

#endif