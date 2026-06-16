# Program Design Document

## Program Name

Basic GPA calculator

## Purpose

It asks user for course credits and course grades and calculates semester gpa
---

## Inputs

Input: 

Course credit and Grade
Decision of continuing adding courses




---

## Outputs

List what the program will display or produce.

Example:

Number of Courses
GPA
Error Logs

---

## Variables

| Variable | Type   | Purpose                   |
| -------- | ------ | ------------------------- |
| score    | double | Stores test score         |
| average  | double | Stores calculated average |
| grade    | char   | Stores letter grade       |

total_points | float | stores cumulative weighted grade points
total_credits | float | stores cumalative course credits
credit_and_grade_input | string | stores course credit and grade
numer_of_courses | size_t | stores number of courses
input_validation_error | bool | false if there are no errors
current_credits | float | stores course credit for recent input
current
---

## Key Design Choices

Explain any important decisions you made when designing the program.

Examples:

* I used two main while loops. One for input validation and one for adding course because there was no way of knowing how many times the user would input wrong or ask to add courses
* I used if else statements for checking the grade because strings aren't valid data types for switch cases
* For all other if statements it was because they were short decisions that wouldn't benefit much from switch case

Example:
"I used a loop to process multiple scores because it reduces code duplication and makes the program easier to modify if the number of scores changes."

---

## Program Steps (Algorithm)

1. Ask user for course credit and grade 
2. Parse then validate input
3. Check what grades were inputted
4. Calculate GPA
5. Output number of courses and gpa
6. Ask user if they want to continue the program and loop if so

---

## Functions


---

## Sample Input/Output

Input:
Credit and Grade: 4B --> 4A

Output:
Classes taken: 1, Semester GPA: 3.0
Classes taken: 2, Semester GPA: 3.5
---

## Testing

### Test Case 1

Input: 3B

Expected Result: Classes taken: 1, Semester GPA: 3

### Test Case 2

Input: -4A

Expected Result: Notify user of error

### Test Case 3

Input: G4

Expected Result: Notify user of error
