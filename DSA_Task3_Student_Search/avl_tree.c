
#include <stdio.h>
#include <stdlib.h>

struct Student {
    int id;
    char name[30];
    char department[20];
};

struct Node {
    struct Student data;
    struct Node *left, *right;
    int height;
};

// Find maximum of two numbers
int max(int a, int b) {
    return (a > b) ? a : b;
}

// Get node height
int height(struct Node *node) {
    if (node == NULL)
        return 0;

    return node->height;
}

// Create a new node
struct Node* createNode(struct Student s) {
    struct Node* node =
        (struct Node*)malloc(sizeof(struct Node));

    if (node == NULL) {
        printf("Memory allocation failed!\n");
        exit(1);
    }

    node->data = s;
    node->left = NULL;
    node->right = NULL;
    node->height = 1;

    return node;
}

// Get balance factor
int getBalance(struct Node *node) {
    if (node == NULL)
        return 0;

    return height(node->left) - height(node->right);
}

// Right rotation
struct Node* rightRotate(struct Node *y) {
    struct Node *x = y->left;
    struct Node *T2 = x->right;

    x->right = y;
    y->left = T2;

    y->height = 1 + max(height(y->left),
                        height(y->right));

    x->height = 1 + max(height(x->left),
                        height(x->right));

    return x;
}

// Left rotation
struct Node* leftRotate(struct Node *x) {
    struct Node *y = x->right;
    struct Node *T2 = y->left;

    y->left = x;
    x->right = T2;

    x->height = 1 + max(height(x->left),
                        height(x->right));

    y->height = 1 + max(height(y->left),
                        height(y->right));

    return y;
}

// Insert student into AVL Tree
struct Node* insert(struct Node* node,
                    struct Student s) {

    if (node == NULL)
        return createNode(s);

    if (s.id < node->data.id)
        node->left = insert(node->left, s);

    else if (s.id > node->data.id)
        node->right = insert(node->right, s);

    else {
        printf("Duplicate ID: %d\n", s.id);
        return node;
    }

    node->height = 1 + max(height(node->left),
                           height(node->right));

    int balance = getBalance(node);

    // LL Case
    if (balance > 1 && s.id < node->left->data.id)
        return rightRotate(node);

    // RR Case
    if (balance < -1 && s.id > node->right->data.id)
        return leftRotate(node);

    // LR Case
    if (balance > 1 && s.id > node->left->data.id) {
        node->left = leftRotate(node->left);
        return rightRotate(node);
    }

    // RL Case
    if (balance < -1 && s.id < node->right->data.id) {
        node->right = rightRotate(node->right);
        return leftRotate(node);
    }

    return node;
}

// Search student
struct Node* search(struct Node* root, int id,
                    int *comparisons) {

    if (root == NULL)
        return NULL;

    (*comparisons)++;

    if (root->data.id == id)
        return root;

    if (id < root->data.id)
        return search(root->left, id, comparisons);

    return search(root->right, id, comparisons);
}

// Display records in ascending order
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

    struct Student students[] = {
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

    struct Node* root = NULL;

    // Insert all records
    for (int i = 0; i < n; i++) {
        root = insert(root, students[i]);
    }

    printf("STUDENT RECORD SEARCH - AVL TREE\n");
    printf("--------------------------------\n");

    printf("\nStudent Records:\n");
    printf("ID     Name          Department\n");
    display(root);

    printf("\nAVL Tree Height: %d\n", height(root));

    int id, comparisons = 0;

    printf("\nEnter Student ID to search: ");
    scanf("%d", &id);

    struct Node* result =
        search(root, id, &comparisons);

    if (result != NULL) {
        printf("\nStudent Found!\n");
        printf("ID: %d\n", result->data.id);
        printf("Name: %s\n", result->data.name);
        printf("Department: %s\n",
               result->data.department);
    }
    else {
        printf("\nStudent Not Found!\n");
    }

    printf("Search Comparisons: %d\n", comparisons);

    return 0;
}
