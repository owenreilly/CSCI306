
#include <stdio.h>

struct Address{
    char streetName[20];
    int houseNumber;
    char city[20];
};

struct Guest{
    char name[30];
    char contract[15];
    struct Address address;
};

struct Guest guest1 = {"Owen Reilly", 3109905750, {"Hilts Avenue", 941, "Los Angeles"}};



// struct Student{
//    char name[30];
//    char major[40]; 
// };

// int main(){

//     struct Student students[1];

//     unsigned int stuLen = sizeof(students)/sizeof(students[0]);

//     for (int i = 0; i<(stuLen); i++){
//         printf("Enter the first name of the student: ");
//         //scanf("%s", students[i].name);
//         fgets(students[i].name, sizeof(students[i].name), stdin);
//         printf("Enter the major of the student: ");
//         fgets(students[i].major, sizeof(students[i].major), stdin);
//         //scanf("%s", students[i].major);
//     }

//     for (int i = 0; i<(stuLen); i++){
//         printf("%s %s\n", students[i].name, students[i].major);
//     }
// }