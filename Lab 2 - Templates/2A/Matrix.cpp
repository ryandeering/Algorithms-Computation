#include <iostream>
#include "MATRIX.H"
#include<vector>

template <typename T>
Matrix<T>::Matrix()
{
	vect = { {0,0,0},{0,0,0},{0,0,0} };
}

template <typename T>
void Matrix<T>::printMatrix()
{
    for (int k = 0; k < vect.size(); k = k + 1) {
        for (int l = 0; l < vect[k].size(); l = l + 1) {
            std::cout << vect[k][l] << ' ';
        }
        std::cout << std::endl;
    }
}

template<typename T>
void Matrix<T>::setMatrix(std::vector<std::vector<T>> vectIn)
{
    if (vect[1].size() == vectIn[1].size()) {
        if (vect.size() == vectIn.size()) {
            for (int i = 0; i < vect.size(); i++)
            {
                for (int j = 0; j < vect.size(); j++)
                {
                    vect[i][j] = vectIn[i][j];
                }
            }
        }
    }
}