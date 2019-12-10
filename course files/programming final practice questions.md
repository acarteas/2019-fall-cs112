# CS 112 Midterm
Use the following guide to help you study for the programming final.

## Rules
* Closed book, closed note, closed friend, closed internet

## Tips
* If you get stuck on one problem, skip it and move on to the next


Questions #1-3 use the following class definition to build linked lists:
```
class ListNode
{
public:
   int value;
   ListNode *next = nullptr;
};
```



### Question #1: Delete item in linked list
Write a function called ```int deleteNode(ListNode *front, int value)``` that removes the first occurrence of the specified value from the linked list.  The function should return the index of the item that was deleted or -1 if nothing was deleted.

### Question 2: Linked List to Vector
Write a function called ```vector<int> toArray(ListNode *front)``` that converts the supplied linked list into a vector.  

### Question 3: Reverse Linked List
Write a funciton called ```ListNode reverse(ListNode *head)```.  The function should return the front of the new list.  E.g. Calling reverse on 1->2->3->4 should return a node value 4 who points to 3->2->1


### Question 4: flip text
Write a function called ```string flipText(string text)``` that reverses the contents of the supplied string.  E.g. "CS112" would return "211SC"

### Question 5: Complete a class _*(this will be on the test!)*_
Given a UML diagram, create a class with private member variables and basic getters and setters.  

### Question 6: Difference
Write a function called ```vector<int> difference(vector<int> first, vector<int> second)``` that returns a vector whose items only consist of items that are unique to first.  E.g., given vectors first = {3, 2, 9} and second = {5, 3}, your function should return a vector whose items are {2, 9}.

### Question 7: toUpper
Write a function called ```char toUpper(char ch)``` that accepts a single character and returns its upper-case equivalent.  Non-characters should not be converted.  E.g., the character 'b' would be converted to 'B' whereas the character '$' would remain '$'.

### Question 8: File I/O
Complete a function that finds the most commonly repeating integer in a supplied text file.  Example function prototype:
```
int findMode(string input_file) {}
```

### Question 9: More File I/O
Write a function called ```void findLongSentences(string input_file, int sentence_length)``` that outputs all sentences that exceed the supplied integer value from the supplied file (one sentence per line).  Example, if our text file contained:

```
this is a test.
You learn lots of interesting things in CS 112. 
this is another test.
I bet you can't wait for CS 211!
```

calling findLongSentences with sentence_length = 5, your function would output

```
You learn lots of interesting things in CS 112.  
I bet you can't wait for CS 211!
```