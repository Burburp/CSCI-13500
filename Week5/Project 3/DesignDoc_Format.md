# Program Design Document

## Program Name

(Name of the assignment)

## Purpose

It creates a mutable array data structure whose main benefit is easy insertion/deletion. Unlike a vector adding an element won't require moving the entire array to a different memory space
---



## Variables

| Variable | Type   | Purpose                   |
| -------- | ------ | ------------------------- |
| score    | double | Stores test score         |
| average  | double | Stores calculated average |
| grade    | char   | Stores letter grade       |

---

## Key Design Choices

Explain any important decisions you made when designing the program.

LinkedList Class Functions:

InsertNode has a time complexity of O(n) as it will have to go through the whole list to add an element. Though it can be reduced to O(1) if LinkedList Class tracked the tail of the list.

InsertNodeFront has a time complexity of O(1) as it can direct access the head of the list and add a new element before it

~Linked List has a time complexity of O(n) because it has to go through all elements to delete them




---

## Program Steps (Algorithm)

1. Get input from the user.
2. Validate the input if necessary.
3. Perform calculations.
4. Determine results.
5. Display output.

---

## Functions

### Function: calculateAverage()

Purpose: Calculates the average score.

### Function: determineGrade()

Purpose: Converts a numeric score into a letter grade.

---

## Sample Input/Output

Input:
Homework: 90
Quiz: 85
Exam: 95

Output:
Final Average: 90
Letter Grade: A

---

## Testing

### Test Case 1

Input: Normal values

Expected Result: Correct calculation

### Test Case 2

Input: Minimum values

Expected Result: Correct handling

### Test Case 3

Input: Maximum values

Expected Result: Correct handling
