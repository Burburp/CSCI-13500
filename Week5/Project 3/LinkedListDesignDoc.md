


## Key Design Choices

Explain any important decisions you made when designing the program.

LinkedList Class Functions:

InsertNode has a time complexity of O(n) as it will have to go through the whole list to add an element. Though it can be reduced to O(1) if LinkedList Class tracked the tail of the list.

InsertNodeFront has a time complexity of O(1) as it can direct access the head of the list and add a new element before it

Contains is O(n) as it might has to check all nodes for a value

Remove is O(n) since you might need to remove the last node

PrintValues and PrintAddress are both O(n) as they go to every node for printing

GetValueAtPosition is O(n) as it might have to traverse to the last value;

InsertNodeAt is also O(n) as it might have to traverse to the end of the list for insertion

GetSize is O(1) as it just has to access a data member

ReverseList is O(n) as it has to go to every node and chance the next address

~Linked List has a time complexity of O(n) because it has to go through all elements to delete them




