#include <iostream>

// Reminder: Information about functions is on the specification PDF

void Print2DArray(const int matrix_local[][3],
                  const int matrix_local_rows_total) {
  // Function_Start message to terminal
  std::cout << "Function Called:\nPrint2DArray\n";
  // tracks number of colums for when matrix_local size is changed
  int num_of_cols = sizeof(matrix_local)[0] / sizeof(matrix_local[0][0]);
  // formatting print of array
  for (int row = 0; row < matrix_local_rows_total; row++) {
    for (int col = 0; col < num_of_cols; col++) {
      // add brackets at the start of a row
      if (col == 0) {
        std::cout << '[';
      }
      std::cout << matrix_local[row][col];
      // adds '|' between numbers and a bracket at end of the row
      if (col < (num_of_cols - 1)) {
        std::cout << '|';
      } else {
        std::cout << ']';
      }
    }
    // seperates rows
    std::cout << '\n';
  }

  // Function_End message to terminal
  std::cout << "End of Function:\nPrint2DArray\n";
}

void MatrixAddition(const int matrix_one[][3], const int matrix_one_rows_total,
                    const int matrix_two[][3],
                    const int matrix_two_rows_total) {
  // Function_Start message to terminal
  std::cout << "Function Called\nMatrixAddition\n";

  const int num_of_cols = sizeof(matrix_one[0]) / sizeof(matrix_one[0][0]);
  int added_matrix[matrix_one_rows_total][num_of_cols] = {};
  // adds matrixes and stores it in a new matrix
  for (int row = 0; row < matrix_one_rows_total; row++) {
    for (int col = 0; col < num_of_cols; col++) {
      added_matrix[row][col] = matrix_one[row][col] + matrix_two[row][col];
    }
  }
  Print2DArray(added_matrix, 3);

  // Function_End message
  std::cout << "End of Function:\nMatrixAddition\n";
}

void TransposeMatrix(const int matrix_local[][3],
                     const int matrix_local_rows_total) {
  // Function_Start message to terminal
  std::cout << "Function Called:\nTransposeMatrix\n";
  //hardcoding size to deal with Print2DArrays column restrictions
  const int num_of_rows = 3;
  int num_of_cols = std::size(matrix_local[0]);
  int transposed_matrix[num_of_cols][num_of_rows] = {};
  // swaps the rows and columns to transpose
  for (int row = 0; row < matrix_local_rows_total; row++) {
    for (int col = 0; col < num_of_cols; col++) {
      transposed_matrix[col][row] = matrix_local[row][col];
    }
  }
  Print2DArray(transposed_matrix, 3);

  // Function_End message to terminal
  std::cout << "End of Function:\nTransposeMatrix\n";
}

void Determinant(const int matrix_local[][3], const int size) {
  // Function_Start message to terminal
  std::cout << "Function Called:\nDeterminant\n";

  int num_of_cols = std::size(matrix_local[0]);
  int determinant_value = 0;
  // Calculates determinant for a 2x2 matrix
  if (num_of_cols == 2 && size == 2) {
    determinant_value = matrix_local[0][0] * matrix_local[1][1] -
                        matrix_local[0][1] * matrix_local[1][0];
  }
  // Calculates determinant for a 3x3 matrix
  else if (num_of_cols == 3 && size == 3) {
    //increments accross every partial 2x2 matrix needed to calculate detriment
    for (int col = 0; col < num_of_cols; col++) {
      // Store the column positions needed for a determinant expanded from the 1st row
      int partial_matrix_col_position_1 = (col + 1) % 3; // 1 2 0
      int partial_matrix_col_position_2 = (col + 2) % 3; // 2 0 1
      determinant_value += matrix_local[0][col] *
                           ((matrix_local[1][partial_matrix_col_position_1] * 
                             matrix_local[2][partial_matrix_col_position_2]) -
                            (matrix_local[1][partial_matrix_col_position_2] * 
                             matrix_local[2][partial_matrix_col_position_1]));
    }
  } else {
    std::cout << "Invalid Matrix Used. Must be 2x2 or 3x3 matrix.\n";
  }
  // print the determinant value on the terminal
  std::cout << "Determinant Value of Matrix: " << determinant_value << "\n";
  // Function_End message to terminal
  std::cout << "End of Function:\nDeterminant\n";
}

void SearchValue(const int matrix_local[][3], const int rows,
                 const int target) {
  // Function_Start message to terminal
  std::cout << "Function Called:\nSearchValue\n";
  // Used to tell user that target value wasn't found
  bool found = false;
  const int cols = sizeof(matrix_local[0]) / sizeof(matrix_local[0][0]);
  // body of the function
  for (int row = 0; row < rows; row++){
    for (int col = 0; col < cols; col++){
      if (target == matrix_local[row][col]){
        found = true;
        std::cout << "Found " << target << " at [" << row << "][" <<  col << "]\n";
      }
    }
  }
  if (found == false){
    std::cout << "Could not find target value in matrix.\n";
  }

  // Function_End message to terminal
  std::cout << "End of Function:\nSearchValue\n";

}

void MatrixMultiplication(const int matrix_a[][3], const int matrix_b[][3],
                          const int rows_a, const int cols_a, const int rows_b,
                          const int cols_b) {
  // Function_Start message to terminal
  std::cout << "Function Called:\nMatrixMultiplication\n";

  // check for valid arrays
  if (!(cols_a == rows_b)){
    std::cout << "Invalid Pair of Matrixes. The first matrix must have the same number of columns as there are rows for the second matrix.\n";
    exit;
  }
  // Body of the function
  const int multiplied_matrix_rows = rows_a;
  //using const to deal with compilation errors due to vector size specifically with print array
  const int multiplied_matrix_cols = sizeof(matrix_b[0]) / sizeof(matrix_b[0][0]);
  int multiplied_matrix[multiplied_matrix_rows][multiplied_matrix_cols] = {};
  // Moves through the new array made by multiplication
  for (int row = 0; row < multiplied_matrix_rows; row++){
    for (int col = 0; col < multiplied_matrix_cols; col++){
      int element_total = 0;
      // The logic for calculating an element in a matrix product
      for (int matrix_increment = 0; matrix_increment < rows_b; matrix_increment++){
        multiplied_matrix[row][col] += matrix_a[row][matrix_increment] * matrix_b[matrix_increment][col];
      }
    }
  }
  Print2DArray(multiplied_matrix, multiplied_matrix_rows);

  // Function_End message to terminal
  std::cout << "End of Function:\nMatrixMultiplication\n";
}

int main() {
  // Use these two matrices for basic testing.

  int testing_matrix_one[3][3] = {
      {1, 2, 3},
      {4, 5, 6},
      {7, 8, 9},
  };

  int testing_matrix_two[3][3] = {{12, 65, 82}, {83, 2, 8}, {10, 96, 67}};

  // Not used in this class, but it is nice to know other ways to find the size
  // of primitive array. This method below is similar to how you will find the
  // size of vectors (future material) DO NOT USE IN THIS PROJECT FUNCTION, but
  // you could test it yourselves. int size_row_one =
  // std::size(testing_matrix_one); int size_col_one =
  // std::size(testing_matrix_one[0]);

  // This is a way to find the dimensions of an array without hardcoding values.
  // It dynamically reflects the array's actual declared size, so if you change
  // the array dimensions, the calculation updates automatically.
  //
  // How it works:
  //
  // To find the number of ROWS:
  //   sizeof(testing_matrix_one)      = total bytes of the whole array = 3*9*4
  //   = 108 bytes sizeof(testing_matrix_one[0])   = total bytes of one row =
  //   1*9*4 =  36 bytes 108 / 36 = 3 rows

  int size_row_one = sizeof(testing_matrix_one) / sizeof(testing_matrix_one[0]);

  // To find the number of COLUMNS:
  //   sizeof(testing_matrix_one[0])      = total bytes of one row          =
  //   1*9*4 = 36 bytes sizeof(testing_matrix_one[0][0])   = total bytes of one
  //   element(int) = 1*4   =  4 bytes 36 / 4 = 9 cols

  int size_col_one =
      sizeof(testing_matrix_one[0]) / sizeof(testing_matrix_one[0][0]);

  std::cout << "row: " << size_row_one << " col: " << size_col_one << std::endl
            << std::endl;

  Print2DArray(testing_matrix_one, size_row_one);
  MatrixAddition(testing_matrix_one, 3, testing_matrix_two, 3);
  Determinant(testing_matrix_one, 3);
  TransposeMatrix(testing_matrix_one, 3);
  MatrixMultiplication(testing_matrix_one, testing_matrix_two, 3, 3, 3, 3);
  SearchValue(testing_matrix_one, 3, 4);

  return 0;
}