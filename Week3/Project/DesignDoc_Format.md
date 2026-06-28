# Program Design Document

## Program Name

Matrix Operations

## Purpose

It prints and performs matrix oppositions as a test for the engineers skills

---

## Inputs

*Matrixes
*Target Value being searched for in matrix

---

## Outputs

* Determinant Value
* Matrixes gone through addition, multiplication, transposition, or without any operations
* Position in which a target value is found in a matrix

---

## Key Design Choices

Explain any important decisions you made when designing the program.

For most of the functions I used two nested for loops of time complexity O(n * m) to traverse the arrays for most of the functions. Since we know home many times it will take to travel the entire array a for loop was the best choice. Looping here allowed for a controlled itteration through the array instead of manually accessing each element. Time complexity is n*m because for n rows it has to travel m columns.

However for matrix multiplication I used 3 nested for loops as for each element in the multiplied matrix I also had to loop through a row of matrix_a and a column of matrix_b. This brings the time complexity to O(n* m *k)

For calculating the determinant I used a for loop to make the code easier to read, but the difficulty in implementation and the small improvement in readiblity did not make this worth it. This loop is technically O(1) because it will only ever recieve the value of 3x3 matrixes and thus constant






