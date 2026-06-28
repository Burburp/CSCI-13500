#include <algorithm>
#include <cctype>
#include <cmath>
#include <iostream>
#include <sstream>

int main() {
  // initializes variables for total grade points, total credits, user input of
  // course credit and grade, and number of course taken
  float total_points = 0.0;
  float total_credits = 0.0;
  std::string credit_and_grade_input = "";
  size_t number_of_courses = 0;  // Just wanna flex with that size_t I learned
                                 // from my correspondence with Gemini

  // Brief explanation of what the user should expect from the application
  std::cout << "Hello student. This is a GPA calculator.\nWe will be asking "
               "for the number of credits "
               "for a class and your letter grade for that class.\nWe will add "
               "your credits and weighted scores"
               " and calculate your GPA.\nAfter adding a class you can add "
               "more and your GPA will update.\n";

  // Keep asking the user for more course grades until user declines
  while (true) {
    // ask user for input again, if for example: input data types don't match
    // expect data types, order of inputs are wrong,  there are miscelanious
    // characters
    // initializes the input validation error tracker. Starts as true because
    // its easier to implement
    bool input_validation_error = true;
    while (input_validation_error) {
      // initializes variables that track the recent inputs for course credits
      // and grades
      float current_credits = 0;
      std::string current_letter_grade = "";

      // User instructions for input
      std::cout
          << "Please type in your course credit and grade in the form "
             "X.XLetter_Grade "
             "or XLetter_Grade.\nWhere X is an interger representing your "
             "course credit and\nLetter_Grade is the letter grade you "
             "received for that class\nPossible letter grades are: A+, A, A-, "
             "B+, B, B-, C+, C, D, F, WU, FIN, FAB\n";
      std::getline(
          std::cin,
          credit_and_grade_input);  // personal note: originally used std::cin
                                    // directly but caused unexpected behaviour
                                    // do to buffer and reading issues

      // Using stringstream to parse and seperate course credits and letter
      // grade
      std::stringstream ss(credit_and_grade_input);

      // stringstream take in user input and makes sure missmatched data types
      // aren't used
      if (ss >> current_credits) {
        // Only 0-10 credits not including 10 is considered valid
        if (0.0 <= current_credits && current_credits < 10.0) {
          // tracking total credits to divide total points later and get GPA
          total_credits += current_credits;
        } else {
          std::cout << "Error: Invalid Credit Range. Expected a number "
                       "betweeon 0 and 10 not including 10.\nYou typed: "
                    << current_credits << "\nTry again:\n\n";
          continue;
        }

      } else {
        std::cout << current_credits << "here\n" 
            << "ERROR: Invalid Credits\nPlease check your input. Make sure the "
               "number of credits and letter grade weren't swapped and "
               "re-enter according to the instructions.\n\n";
        continue;
      }

      ss >> current_letter_grade;
      // intializes a uppercase grade with the current letter grade in order to
      // preserve the original case for error logs and transform the new
      // variable to uppercase
      // to use case insensetive conditions
      std::string uppercase_grade = current_letter_grade;
      std::transform(uppercase_grade.begin(), uppercase_grade.end(),
                     uppercase_grade.begin(),
                     [](unsigned char c) { return std::toupper(c); });

      // checks that input letter grade matches real letter grades
      // converts it into a numerical grade and multiplies by course creditsand
      // adds to total points to find final gpa later basically,
      // yanderedev code
      if (uppercase_grade == "A+") {
        total_points += 4 * current_credits;
      } else if (uppercase_grade == "A") {
        total_points += 4 * current_credits;
      } else if (uppercase_grade == "A-") {
        total_points += 3.7 * current_credits;
      } else if (uppercase_grade == "B+") {
        total_points += 3.3 * current_credits;
      } else if (uppercase_grade == "B") {
        total_points += 3 * current_credits;
      } else if (uppercase_grade == "B-") {
        total_points += 2.7 * current_credits;
      } else if (uppercase_grade == "C+") {
        total_points += 2.3 * current_credits;
      } else if (uppercase_grade == "C") {
        total_points += 2 * current_credits;
      } else if (uppercase_grade == "D") {
        total_points += 1 * current_credits;
      } else if (uppercase_grade == "F") {
        total_points += 0 * current_credits;
      } else if (uppercase_grade == "WU") {
        total_points += 0 * current_credits;
      } else if (uppercase_grade == "FIN") {
        total_points += 0 * current_credits;
      } else if (uppercase_grade == "FAB") {
        total_points += 0 * current_credits;
      } else {
        // subtract the invalid course credits added this loop
        total_credits -= current_credits;
        std::cout << "ERROR: Invalid Letter Grade. You typed: "
                  << current_letter_grade << "\nPlease try again:\n\n";
        continue;
      }
      // No errors during the loop so input error tracker set to false
      input_validation_error = false;
      number_of_courses += 1;
    }
    // initializes and declares gpa and then immideiately after rounds it to two
    // decimal points
    float gpa = total_points / total_credits;
    float rounded_gpa = std::round(gpa * 100.0) / 100.0;
    std::cout << "Classes taken: " << number_of_courses
              << ", Semester GPA: " << rounded_gpa << "\n";
    std::cout << "Would you like to add more classes? Type Yes for yes and No "
                 "for no. It is case insensetive.\n";
  // label to go back to when user gives invalid input to response to adding
  // another course
  validation:
    // declares variable that accests users response to adding another course
    std::string add_another_course = "";
    std::cin >> add_another_course;
    std::cin.ignore();
    // makes response case insensetive
    std::transform(add_another_course.begin(), add_another_course.end(),
                   add_another_course.begin(),
                   [](unsigned char c) { return std::toupper(c); });
    // decides whether to continue process
    if (add_another_course == "YES") {
      std::cout << "Begining adding another course....\n....\n....\n";
    } else if (add_another_course == "NO") {
      break;
    } else {
      std::cout << "ERROR: Invalid Answer. Please type Yes or No: ";
      goto validation;
    }
  }

  return 0;
}
