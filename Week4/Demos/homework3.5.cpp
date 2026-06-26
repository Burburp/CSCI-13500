#include <iostream>
#include <vector>
int main() {
  int three_by_three[3][3] = {};
  int six_by_six[6][6] = {};
  int num_of_cols = sizeof(three_by_three[0]) / sizeof(three_by_three[0][0]);
  // turns every interger on or above the top right to top left diagnol of the
  // matrix into ones for a 3x3 grid
  for (int row = 0; row < num_of_cols; row++) {
    // number of columns in a row that will be turned into 1
    int iterate_cols = num_of_cols - row;
    for (int current_col = 0; current_col < iterate_cols; current_col++) {
      three_by_three[row][current_col] = 1;
    }
  }

  // prints matrix assuming its a square
  for (int row = 0; row < num_of_cols; row++) {
    for (int col = 0; col < num_of_cols; col++) {
      // add brackets at the start of a row
      if (col == 0) {
        std::cout << '[';
      }
      std::cout << three_by_three[row][col];
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

  num_of_cols = sizeof(six_by_six[0]) / sizeof(six_by_six[0][0]);
  // turns every interger on or above the top right to top left diagnol of the
  // matrix into ones for a 6x6 grid
  for (int row = 0; row < num_of_cols; row++) {
    // number of columns in a row that will be turned into 1
    int iterate_cols = num_of_cols - row;
    for (int current_col = 0; current_col < iterate_cols; current_col++) {
      six_by_six[row][current_col] = 1;
    }
  }

  // prints matrix assuming its a square
  for (int row = 0; row < num_of_cols; row++) {
    for (int col = 0; col < num_of_cols; col++) {
      // add brackets at the start of a row
      if (col == 0) {
        std::cout << '[';
      }
      std::cout << six_by_six[row][col];
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

  num_of_cols = sizeof(three_by_three[0]) / sizeof(three_by_three[0][0]);
  // resetting the arrays back to 0. Could have done this with memset() but
  // didnt want to add another library
  for (int row = 0; row < num_of_cols; row++) {
    for (int col = 0; col < num_of_cols; col++) {
      three_by_three[row][col] = 0;
    }
  }
  // makes an x shape withs 1s on a 3x3 matrix
  for (int row = 0; row < num_of_cols; row++) {
    three_by_three[row][row] = 1;
    three_by_three[row][num_of_cols - 1 - row] = 1;
  }
  // prints matrix assuming its a square
  for (int row = 0; row < num_of_cols; row++) {
    for (int col = 0; col < num_of_cols; col++) {
      // add brackets at the start of a row
      if (col == 0) {
        std::cout << '[';
      }
      std::cout << three_by_three[row][col];
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

  num_of_cols = sizeof(six_by_six[0]) / sizeof(six_by_six[0][0]);
  // resetting the arrays back to 0. Could have done this with memset() but
  // didnt want to add another library
  for (int row = 0; row < num_of_cols; row++) {
    for (int col = 0; col < num_of_cols; col++) {
      six_by_six[row][col] = 0;
    }
  }
  // makes an x shape withs 1s on a 3x3 matrix
  for (int row = 0; row < num_of_cols; row++) {
    six_by_six[row][row] = 1;
    six_by_six[row][num_of_cols - 1 - row] = 1;
  }

  // prints matrix assuming its a square
  for (int row = 0; row < num_of_cols; row++) {
    for (int col = 0; col < num_of_cols; col++) {
      // add brackets at the start of a row
      if (col == 0) {
        std::cout << '[';
      }
      std::cout << six_by_six[row][col];
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

  // the following takes a 3x3 matrix and adds values in each column and row
  // seperately
  // entering the sumed values into a 2x3 array

  // the vector that will be added
  std::vector<std::vector<int>> vector3x3 = {
      {9, -3, -4}, 
      {5, 7, 13},
      {-1, 4, 3}};

  num_of_cols = vector3x3[0].size();
  std::vector<std::vector<int>> added_matrix(2,
                                             std::vector<int>(num_of_cols, 0));
  // adds the total of each row into added_matrix
  for (int row = 0; row < num_of_cols; row++) {
    int row_total = 0;
    for (int col = 0; col < num_of_cols; col++) {
      row_total += vector3x3[row][col];
    }
    added_matrix[0][row] = row_total;
  }
  // adds the total of each column into added_matrix
  for (int col = 0; col < num_of_cols; col++) {
    int col_total = 0;
    for (int row = 0; row < num_of_cols; row++) {
      col_total += vector3x3[row][col];
    }
    added_matrix[1][col] = col_total;
  }

  // following prints matrix assuming its a square
  int num_of_rows = 2;
  num_of_cols = 3;
  // it would be so nice to have functions right now
  for (int row = 0; row < num_of_rows; row++) {
    for (int col = 0; col < num_of_cols; col++) {
      // add brackets at the start of a row
      if (col == 0) {
        std::cout << '[';
      }
      std::cout << added_matrix[row][col];
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

  // resetting the arrays back to 0. Could have done this with memset() but
  // didnt want to add another library
  for (int row = 0; row < num_of_cols; row++) {
    for (int col = 0; col < num_of_cols; col++) {
      three_by_three[row][col] = 0;
    }
  }

  // Following adds the diagonal and anti_diagonal values
  int diagonal_total = 0;
  int anti_diagonal_total = 0;
  int both_diagonal_total = 0;
  int center_value = 0;
  for (int row = 0; row < num_of_cols; row++) {
    diagonal_total += vector3x3[row][row];
    anti_diagonal_total += vector3x3[row][num_of_cols - 1 - row];
  }
  // gets the center value for an odd matrix to subtract the double count
  if (num_of_cols % 2 == 1) {
    int center_position = num_of_cols / 2;
    center_value = vector3x3[center_position][center_position];
  }
  both_diagonal_total = diagonal_total + anti_diagonal_total - center_value;
  std::cout << both_diagonal_total << '\n';

  return 0;
}