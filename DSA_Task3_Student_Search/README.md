
# Student Record Search System Using C

## 1. Project Title
Student Record Search System Using Binary Search Tree, AVL Tree and Hashing with Linear Probing.

## 2. Problem Statement
Managing student records requires an efficient method to store and search student information. Searching records one by one takes more time when the number of students increases.

This project compares three data structures to identify an efficient method for student record searching.

## 3. Objective
- To store student records using C.
- To implement BST, AVL Tree and Hashing.
- To perform insertion and searching operations.
- To count search comparisons and hash collisions.
- To compare the performance of all three data structures.

## 4. Dataset Description
The project uses 30 student records.

Each record contains:
- Student ID
- Student Name
- Department

Departments used: CSE, AIML and ECE.

Student IDs range from 1001 to 1030.

## 5. Data Structures Used

### A. Binary Search Tree (BST)
BST stores student records based on Student ID. Smaller IDs are placed in the left subtree and larger IDs in the right subtree.

### B. AVL Tree
AVL Tree is a self-balancing Binary Search Tree. It uses rotations to maintain balance and reduce tree height.

### C. Hashing with Linear Probing
Hashing uses the hash function:

index = Student ID % 47

If a collision occurs, Linear Probing checks the next available position.

## 6. Algorithms and Operations
The following operations are performed:
1. Insert student records.
2. Display student records.
3. Search for an existing student.
4. Search for a non-existing student.
5. Insert a new student record.
6. Count search comparisons.
7. Calculate tree height for BST and AVL.
8. Count collisions in Hashing.

## 7. Experimental Results

Number of initial student records: 30

| Measurement | BST | AVL | Hashing |
|---|---:|---:|---:|
| Successful search (1015) | 1 | 1 | 1 |
| Unsuccessful search (9999) | 3 | 6 | 10 |
| Tree height | 8 | 6 | N/A |
| New student insertion (1031) | Pending test | Pending test | Successful |
| New insertion collisions | N/A | N/A | 0 |

Hashing table size: 47

Hashing successful search for 1015: 1 comparison.

Hashing unsuccessful search for 9999: 10 comparisons.

## 8. Comparison and Analysis
- BST has a tree height of 8.
- AVL Tree has a tree height of 6.
- AVL maintains balance using rotations.
- Hashing provides direct access when collisions are low.
- Linear Probing handles collisions by checking the next available position.

The number of comparisons depends on the structure and the search key.

## 9. Final Conclusion
The Student Record Search System was implemented using BST, AVL Tree and Hashing with Linear Probing.

Based on the experimental results, AVL provides a balanced tree structure with a smaller height than the BST in this experiment. Hashing provides efficient searching when collisions are low.

Therefore, Hashing is suitable for fast student record searching, while AVL Tree is a good choice when balanced searching performance is required.
