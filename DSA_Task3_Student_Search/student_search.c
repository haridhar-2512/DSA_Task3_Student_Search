
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Student record
struct Student {
    int id;
    char name[30];
    char department[20];
};

// BST node
struct Node {
    struct Student data;
    struct Node *left;
    struct Node *right;
};

// Create a new node
struct Node* createNode(struct Student s) {
    struct Node* newNode =
        (struct Node*)malloc(sizeof(struct Node));

    if (newNode == NULL) {
        printf("Memory allocation failed!\n");
        exit(1);
    }

    newNode->data = s;
    newNode->left = NULL;
    newNode->right = NULL;

    return newNode;
}

// Insert student into BST
struct Node* insert(struct Node* root, struct Student s) {
    if (root == NULL) {
        return createNode(s);
    }

    if (s.id < root->data.id) {
        root->left = insert(root->left, s);
    }
    else if (s.id > root->data.id) {
        root->right = insert(root->right, s);
    }

    return root;
}

// Calculate BST height
int height(struct Node *root) {
    if (root == NULL) {
        return 0;
    }

    int leftHeight = height(root->left);
    int rightHeight = height(root->right);

    return 1 + (leftHeight > rightHeight
                    ? leftHeight : rightHeight);
}

// Search student in BST
struct Node* search(struct Node* root, int id,
                    int *comparisons) {
    if (root == NULL) {
        return NULL;
    }

    (*comparisons)++;

    if (root->data.id == id) {
        return root;
    }

    if (id < root->data.id) {
        return search(root->left, id, comparisons);
    }

    return search(root->right, id, comparisons);
}

// Display students using inorder traversal
void display(struct Node* root) {
    if (root != NULL) {
        display(root->left);

        printf("%d  %-12s  %s\n",
               root->data.id,
               root->data.name,
               root->data.department);

        display(root->right);
    }
}

int main() {
    struct Node* root = NULL;

    struct Student students[30] = {
        {1015, "Ajay", "ECE"},
        {1005, "Kavin", "AIML"},
        {1025, "Gokul", "CSE"},
        {1002, "Priya", "AIML"},
        {1018, "Naveen", "ECE"},
        {1001, "Arun", "CSE"},
        {1030, "Varun", "ECE"},
        {1010, "Ram", "CSE"},
        {1020, "Surya", "AIML"},
        {1003, "Rahul", "ECE"},
        {1004, "Divya", "CSE"},
        {1006, "Nisha", "ECE"},
        {1007, "Sanjay", "CSE"},
        {1008, "Meena", "AIML"},
        {1009, "Vijay", "ECE"},
        {1011, "Anu", "AIML"},
        {1012, "Hari", "ECE"},
        {1013, "Karthik", "CSE"},
        {1014, "Sneha", "AIML"},
        {1016, "Bala", "CSE"},
        {1017, "Keerthi", "AIML"},
        {1019, "Deepa", "CSE"},
        {1021, "Rohan", "ECE"},
        {1022, "Kavya", "CSE"},
        {1023, "Manoj", "AIML"},
        {1024, "Asha", "ECE"},
        {1026, "Pooja", "AIML"},
        {1027, "Santhosh", "ECE"},
        {1028, "Lakshmi", "CSE"},
        {1029, "Dinesh", "AIML"}
    };

    int n = sizeof(students) / sizeof(students[0]);

    // Insert all student records
    for (int i = 0; i < n; i++) {
        root = insert(root, students[i]);
    }

    printf("STUDENT RECORD SEARCH - BST\n");
    printf("----------------------------\n");

    printf("\nStudent Records:\n");
    printf("ID     Name          Department\n");

    display(root);

    // Display BST height
    printf("\nBST Tree Height: %d\n", height(root));

    // Search operation
    int id;
    int comparisons = 0;

    printf("\nEnter Student ID to search: ");
    scanf("%d", &id);

    struct Node* result = search(root, id, &comparisons);

    if (result != NULL) {
        printf("\nStudent Found!\n");
        printf("ID: %d\n", result->data.id);
        printf("Name: %s\n", result->data.name);
        printf("Department: %s\n", result->data.department);
    }
    else {
        printf("\nStudent Not Found!\n");
    }

    printf("Search Comparisons: %d\n", comparisons);

    return 0;
}
