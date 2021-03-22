

// Ryan Deering

// Algorithms and Computation - CA1

// https://www.geeksforgeeks.org/sorted-merge-one-array/
// https://www.mygreatlearning.com/blog/merge-sort/
// https://www.geeksforgeeks.org/merge-sort/

// sources

int main() {
  // DEF FN mergeSort(a[], b[], aSize, bSize)
  // pivot1 = aSize - 1
  // pivot2 = bSize - 1

  // index = n + m - 1

  // WHILE(j >= 0){
  // IF ( i >= 0 AND arr1[aSize] > arr2[bSize])
  // a[index] = a[pivot1] *moves position*
  // aSize - 1 *decrement*
  // ELSE
  // a[index] = b[pivot2] *moves position*
  // bSize - 1

  // index - 1
  // END

  // Input: a[] = { 10, 12, 13, 14, 18, empty, empty, empty, empty, empty };
  // b[] = { 16, 17, 19, 20, 22 };

  // aSize = 5
  // bSize = 5

  // mergeSort(a,b,aSize,bSize)
  // FOR (I = 0, I < 10, I++)
  // PRINT a[I]

  // Output: a[] = { 10, 12, 13, 14, 16, 17, 18, 19, 20, 22 };
  return 0;
}
