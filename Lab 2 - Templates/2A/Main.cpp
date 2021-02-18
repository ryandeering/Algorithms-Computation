#include <iostream>
#include "Matrix.h"
#include "Matrix.cpp"


//Ryan Deering - X00144631
//Algorithms and Computation -- Lab 2A
//Part 1 of the lab is available as a txt file.

template <class T>
T absoluteValue(T var1, T var2) 
{
if (var1 > var2) {
		return (var1 - var2);
} else {
	return (var2 - var1); }
}

int main() {
	int int1 = 10; 
	int int2 = 20;
	double double1 = 68.2; 
	double double2 = 419.3;
	char char1 = 6; 
	char char2 = 1;
	 
	std::cout << absoluteValue(int1,int2) << std::endl; 
	 
	std::cout << absoluteValue(double1,double2) << std::endl; 
	 
	std::cout << absoluteValue((int)char1, (int)char2) << std::endl; //This can add chars like normal, but it'll only return a character. Casting to int for display purposes.
	
	std::cout << std::endl;

	Matrix<int> m1 = Matrix<int>();
	std::vector<std::vector<int>> vect1 = { {1,2,3},{4,5,6},{7,8,9} };


	m1.setMatrix(vect1);

	m1.printMatrix();
	std::cout << std::endl;

	Matrix<double> m2 = Matrix<double>();
	std::vector<std::vector<double>> vect2 = { {3.2,5.6,3.2},{10.2,56.4,98.2},{104.53,27.1,99.9} };

	m2.setMatrix(vect2);

	m2.printMatrix();

	std::cout << std::endl;

	Matrix<float> m3 = Matrix<float>();
	std::vector<std::vector<float>> vect3 = { {1.625741,3.832026,4.853078},{0.687247,0.568085,2.810053},{3.561830,3.674827,2.814782} };

	m3.setMatrix(vect3);

	m3.printMatrix();


	return 0;
}
