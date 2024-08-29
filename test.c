
#include <stdio.h>
#include <string.h>


int main() {
    // **Challenge 1: Monitoring Environmental Data**

    // TODO: Declare variables for temperature, oxygen level, greenhouse pressure, and humidity.
    // Example: int temperature;
    // Choose appropriate data types based on the range of values needed.
    
    int temperature;
    float oxygenLevel;
    int greenhousePressure;
    float humidity;

    // TODO: Use scanf to gather input from the user for these environmental variables.
    // Example: printf("Enter the current temperature (°C): ");
    // scanf("%d", &temperature);
    
    printf("Enter the current temperature (°C): "); 
    scanf("%d", &temperature);
    printf("Enter the current oxygen level: ");
    scanf("%f", &oxygenLevel);
    printf("Enter the current greenhouse pressure (psi): ");
    scanf("%d", &greenhousePressure);
    printf("Enter the current humidity: ");
    scanf("%f", &humidity);
    
    
    // TODO: Use printf to display the values entered by the user.
    // Example: printf("Temperature: %d°C\n", temperature);

    printf("Temperature: %d°C\n", temperature);
    printf("Oxygen Level: %.2f\n", oxygenLevel);
    printf("Greenhouse Pressure: %d\n", greenhousePressure);
    printf("Humidity: %.2f\n", humidity);
    
    // **Challenge 2: Water Quality Control**

    // TODO: Declare variables for pH level, contamination level, and water temperature.
    // Example: float pH_level;

    float pH_level;
    float contamination_level;
    int water_temperature;
    
    // TODO: Use scanf to take input from the user for each variable.
    // Example: printf("Enter pH level: ");
    // scanf("%f", &pH_level);

    printf("Enter pH level: ");
    scanf("%f", &pH_level);
    printf("Enter contamination level: ");
    scanf("%f", &contamination_level);
    printf("Enter water temperature: ");
    scanf("%d", &water_temperature);
    
    // TODO: Use printf to display the values entered by the user.
    // Example: printf("pH Level: %.2f\n", pH_level);

    printf("pH Level: %.2f\n", pH_level);
    printf("Contamination Level: %.2f\n", contamination_level);
    printf("Water Temperature: %d°\n", water_temperature);

    
    // **Challenge 3: Recording Crew Member Details**

    // TODO: Declare variables for name, age, initial, and height.
    // Example: char name[50];

    char name[50];
    int age;
    char initial;
    int height;
    
    // TODO: Use scanf and getchar to take input for each variable.
    // Example: printf("Enter your name: ");
    // scanf("%s", name);

    printf("Enter your name: ");
    scanf("%s", name);
    printf("Enter your age: ");
    scanf("%d", &age);
    printf("Enter your initial: ");
    scanf("%c", &initial);
    printf("Enter your height (inches) : ");
    scanf("%d", &height);
    
    // TODO: Use printf and putchar to display the recorded information.
    // Example: printf("Name: %s\n", name);

    printf("Name: %s\n", name);
    printf("Age: %d years\n", age);
    printf("Initial: %c\n", initial);
    printf("Height: %d' meters\n", height);

    
    // **Challenge 4: Interactive Console for Engineers**

    // TODO: Create prompts for updating and viewing data.
    // Example: printf("Enter the current temperature (°C): ");


    printf("--- Crew Member Details ---\n");
    printf("Name: %s\n", name);
    printf("Age: %d years\n", age);
    printf("Initial: %c\n", initial);
    printf("Height: %d inches\n\n\n", height);

    printf("--- Mars Colony System Console ---\n");
    printf("Current Enviornmental Data:\n");
    printf("Temperature: %d°C\n", temperature);
    printf("Oxygen Level: %.2f\n", oxygenLevel);
    printf("Greenhouse Pressure: %d\n", greenhousePressure);
    printf("GreenhouseHumidity: %.2f\n", humidity);
    printf("\n");
    printf("Current Water Quality Data:\n");
    printf("pH Level: %.2f\n", pH_level);
    printf("Contamination Level: %.2f\n", contamination_level);
    printf("Water Temperature: %d°\n", water_temperature);
   

    // TODO: Use scanf to gather input from the user and printf to display the results.
    // Example: scanf("%d", &temperature);
    // printf("Temperature: %d°C\n", temperature);
    
    return 0;
}


