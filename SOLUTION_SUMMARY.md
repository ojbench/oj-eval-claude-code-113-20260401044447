# Problem 113 - Solution Summary

## Result
- **Submission ID**: 767166
- **Status**: Accepted
- **Score**: 100/100
- **Submissions Used**: 1 out of 5

## Test Points Performance
All 10 test points passed successfully:

| Test Point | Type | Result | Score | Memory | Time |
|------------|------|---------|-------|---------|------|
| 1 | LinkedList | Accepted | 24.0 | 4 MB | 42 ms |
| 2 | LinkedList | Accepted | 24.0 | 11.9 MB | 163 ms |
| 3 | Queue | Accepted | 8.0 | 4.1 MB | 24 ms |
| 4 | Stack | Accepted | 8.0 | 4.7 MB | 40 ms |
| 5 | Mixed | Accepted | 16.0 | 3.9 MB | 4 ms |
| 6 | LinkedList+MemCheck | Accepted | 6.0 | 47.7 MB | 2051 ms |
| 7 | LinkedList+MemCheck | Accepted | 6.0 | 57.7 MB | 6257 ms |
| 8 | Queue+MemCheck | Accepted | 2.0 | 48.8 MB | 1291 ms |
| 9 | Stack+MemCheck | Accepted | 2.0 | 63.0 MB | 2237 ms |
| 10 | Mixed+MemCheck | Accepted | 4.0 | 47.5 MB | 652 ms |

## Implementation Details

### Files Created
- **src.hpp**: Main implementation file containing all three classes
- **test.cpp**: Local test file to verify functionality

### Key Implementation Features

1. **LinkedList Template Class**:
   - Uses a singly-linked list with head and tail pointers
   - Maintains a length counter for O(1) size() operations
   - Implements all required functions: pushFront, pushBack, popFront, popBack, size, print
   - Includes proper copy constructor for deep copying
   - Destructor ensures no memory leaks by deleting all nodes

2. **Stack Class** (derived from LinkedList):
   - Implements LIFO (Last In First Out) behavior
   - Uses LinkedList's front as the stack top
   - push() -> pushFront()
   - pop() -> popFront()
   - peak() -> returns head->data

3. **Queue Class** (derived from LinkedList):
   - Implements FIFO (First In First Out) behavior
   - Uses LinkedList's front as queue head and back as queue tail
   - push() -> pushBack()
   - pop() -> popFront()
   - peak() -> returns head->data

### Key Design Decisions

1. **Node Structure**: Defined as a protected struct within LinkedList to allow derived classes access
2. **Virtual Functions**: Properly overridden in Stack and Queue classes
3. **Memory Management**: Careful attention to proper deletion in destructor to avoid memory leaks
4. **Edge Cases**: Handled empty list cases by returning default constructed T values

## Compliance with Requirements

✅ Only uses `<iostream>` header (no other headers)
✅ LinkedList is a proper template class
✅ Stack and Queue don't define any member variables (only inherit from LinkedList)
✅ All virtual functions properly implemented
✅ No memory leaks (passed test points 6-10)
✅ Proper copy constructor implementation
✅ Uses cout for print() function as required

## Local Testing
Tested with the provided sample input and output matched exactly.

## Conclusion
Successfully completed Problem 113 with a perfect score on the first submission, demonstrating proper understanding of:
- Template classes in C++
- Inheritance and virtual functions
- Linked list data structures
- Stack and Queue ADTs
- Proper memory management without leaks
