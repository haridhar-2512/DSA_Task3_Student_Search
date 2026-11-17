
#include <stdio.h>
#include <string.h>

#define TABLE_SIZE 47

struct Student {
    int id;
    char name[30];
    char department[20];
};

struct HashEntry {
    struct Student student;
    int occupied;
};

struct HashEntry hashTable[TABLE_SIZE];

// Hash function
int hashFunction(int id) {
    return id % TABLE_SIZE;
}

// Insert a student using Linear Probing
int insertStudent(struct Student s) {
    int index = hashFunction(s.id);
    int collisions = 0;
    int start = index;

    while (hashTable[index].occupied) {
        if (hashTable[index].student.id == s.id) {
            printf("Student ID already exists!\n");
            return -1;
        }

        collisions++;
        index = (index + 1) % TABLE_SIZE;

        if (index == start) {
            printf("Hash table is full!\n");
            return -1;
        }
    }

    hashTable[index].student = s;
    hashTable[index].occupied = 1;

    return collisions;
}

// Search for a student
int searchStudent(int id, int *comparisons) {
    int index = hashFunction(id);
    int start = index;

    *comparisons = 0;

    while (hashTable[index].occupied) {
        (*comparisons)++;

        if (hashTable[index].student.id == id) {
            return index;
        }

        index = (index + 1) % TABLE_SIZE;

        if (index == start) {
            break;
        }
    }

    return -1;
}

// Display hash table
void displayTable() {
    printf("\n--- HASH TABLE ---\n");
    printf("Index\tID\tName\t\tDepartment\n");

    for (int i = 0; i < TABLE_SIZE; i++) {
        if (hashTable[i].occupied) {
            printf("%d\t%d\t%-15s\t%s\n",
                   i,
                   hashTable[i].student.id,
                   hashTable[i].student.name,
                   hashTable[i].student.department);
        }
    }
}

int main() {
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

    int totalCollisions = 0;

    // Insert the 30 student records
    for (int i = 0; i < 30; i++) {
        int result = insertStudent(students[i]);

        if (result >= 0) {
            totalCollisions += result;
        }
    }

    printf("30 student records inserted successfully.\n");
    printf("Total collisions during initial insertion: %d\n",
           totalCollisions);

    displayTable();

    // Insert a new student
    struct Student newStudent;

    printf("\n--- INSERT NEW STUDENT ---\n");
    printf("Enter Student ID: ");
    scanf("%d", &newStudent.id);

    printf("Enter Student Name (one word): ");
    scanf("%29s", newStudent.name);

    printf("Enter Department: ");
    scanf("%19s", newStudent.department);

    int newCollisions = insertStudent(newStudent);

    if (newCollisions >= 0) {
        printf("New student inserted successfully!\n");
        printf("Collisions during this insertion: %d\n",
               newCollisions);
    }

    // Search for a student
    int searchID, comparisons;
    int result;

    printf("\n--- SEARCH STUDENT ---\n");
    printf("Enter Student ID to search: ");
    scanf("%d", &searchID);

    result = searchStudent(searchID, &comparisons);

    if (result != -1) {
        printf("\nStudent Found!\n");
        printf("ID: %d\n", hashTable[result].student.id);
        printf("Name: %s\n", hashTable[result].student.name);
        printf("Department: %s\n",
               hashTable[result].student.department);
    } else {
        printf("\nStudent Not Found!\n");
    }

    printf("Number of comparisons: %d\n", comparisons);

    return 0;
}

