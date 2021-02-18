#pragma once
#ifndef MATRIX_H
#define MATRIX_H
#include <vector>
#include <iostream>
template <typename T>
class Matrix {
public:
    Matrix();
    void printMatrix();
    void setMatrix(std::vector<std::vector<T>> vectIn);
private:
    std::vector<std::vector<T>> vect;
};
#endif