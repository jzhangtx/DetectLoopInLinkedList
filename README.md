Detect Loop in Linked List


Given a linked list which can have a loop, find the node at which the loop starts. If no loop exists, return NULL.

Detect Loop in Linked List
Testing
Input Format
The first line contains an integer ‘T’ denoting the number of independent test cases.

For each test case the input has three lines:

An integer ‘n’ denoting the length of the linked list.
n space-separated integers denoting elements of the linked list.
An integer ‘m’ denoting the index of the node to which the last node is connected.
Note: m is in the range [0, n-1] for valid loop. A value of -1 indicates no loop.

Output Format
For each test case, a line containing the value of the node at which the loop starts.

Sample Input
3
3
3 4 5
1
4
1 2 3 4
0
3
5 6 7
-1
Expected Output
4
1
-1