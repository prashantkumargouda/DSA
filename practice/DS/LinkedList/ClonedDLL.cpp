// Clone a DLL with next and random pointers
// Write a C program to clone a Doubly Linked List (DLL) with next and random pointers.

// Each node in the DLL has the following pointers:

// next: Points to the next node in the DLL.
// prev: Points to the previous node in the DLL.
// random: Points to any random node in the DLL or NULL.
// The program should create an exact deep copy of the DLL, including both next and random pointers.


// Constraints:
// 1 ≤ n ≤ 10^5 (Number of nodes in the DLL)
// -10^9 ≤ node value ≤ 10^9 (Value range)
// random pointer can be NULL or point to any node.

// Example:
// Sample Input-1:

// 4
// 10 20 30 40
// 1 3 2 -1

// Sample Output-1:

// Cloned DLL: 10(1) 20(3) 30(2) 40(NULL)

// Sample Input-2:

// 3
// 1 2 3
// 2 1 -1

// Sample Output-2:

// Cloned DLL: 1(2) 2(1) 3(NULL)

// Sample Input-3:

// 5
// 5 10 15 20 25
// -1 0 4 3 2

// Sample output-3:

// Cloned DLL: 5(NULL) 10(0) 15(4) 20(3) 25(2)


// Explanation:
// Input: A DLL with n nodes, where each node has a next and a random pointer.
// Processing: Create a deep copy of the DLL, preserving both next and random pointers.
// Output: Print the cloned DLL with its elements.
