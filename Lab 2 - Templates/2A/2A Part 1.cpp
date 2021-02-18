#include <iostream>

using std::cout;
using std::endl;
//Interchanges the values of variable1 and variable2.
//The assignment operator must work for the type T.
template < typename T >
  void swapValues(T & variable1, T & variable2) {
    T temp;
    temp = variable1;
    variable1 = variable2;
    variable2 = temp;
  }
int main() {
  typedef int * ArrayPointer;
  ArrayPointer a, b, c;
  a = new int[3];
  b = new int[3];
  int i;
  for (i = 0; i < 3; i++) {
    a[i] = i; // Goes 0,1,2
    b[i] = i * 100; //Goes 0, 100, 200...due to the multiplication.
  }
  c = a; //becomes a pointer to the exact location in memory, of A. so they are really the same thing. 
  cout << "a contains: ";
  for (i = 0; i < 3; i++)
    cout << a[i] << " ";
  cout << endl;
  cout << "b contains: ";
  for (i = 0; i < 3; i++)
    cout << b[i] << " ";
  cout << endl;
  cout << "c contains: ";
  for (i = 0; i < 3; i++)
    cout << c[i] << " ";
  cout << endl;
  swapValues(a, b); //Pointers are swapped around. A is now pointing to B's location in memory, and vice versa for B.
  b[0] = 42; //first element within B array is now 42.
  cout << "After swapping a and b,\n" <<
    "and changing b:\n";
  cout << "a contains: ";
  for (i = 0; i < 3; i++)
    cout << a[i] << " "; //Since the B array was swapped with the contents of the A array, the A array now holds the contents of the original B array. Hence the changes in numbers, as well as the change in content.
  cout << endl;
  cout << "b contains: ";
  for (i = 0; i < 3; i++)
    cout << b[i] << " ";
  cout << endl;
  cout << "c contains: ";
  for (i = 0; i < 3; i++)
    cout << c[i] << " "; //C just points to B's location in memory, so any changes to B are changed to C also.
  cout << endl;
  return 0;
}