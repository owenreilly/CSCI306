#include <stdio.h>


#define GUESTS 5
#define MAX_NAME_LENGTH 10
#define MAX_CONTACT_LENGTH 15


struct Guest{
    char name[MAX_NAME_LENGTH];
    char contact[MAX_CONTACT_LENGTH];
    int age;
};


int main(){
    struct Guest guests[GUESTS];

    for(int i=0; i<GUESTS; i++){
        printf("Enter the name of guest %d: ", i+1);
        scanf("%s", guests[i].name);
        printf("Enter the contact of guest %d: ", i+1);
        scanf("%s", guests[i].contact);
        printf("Enter the age of guest %d: ", i+1);
        scanf("%d", &guests[i].age);
    }
    
}





// int main(){
//     float temperature[7]={35.2, 29.4, 32.1, 36.3, 37.5, 38.7, 39.9};

//     // Not a direct length function, but it tells how many bytes the array is, 
//     // then dividing by how many bytes a given type is
//     int numDays= sizeof(temperature)/sizeof(temperature[0]);

//     float sum = 0.0;
//     for(int i=0; i<numDays; i++){ 
//         sum += temperature[i];
//     }

//     float average = sum/numDays;

//     printf("The average temperature for the week is %.2f degrees Fahrenheit.\n", average);

//     return 0;
// }


