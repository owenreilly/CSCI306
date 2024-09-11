  //Owen Reilly
  // Section 60 
  // Lab 03
  //
  //
 

#include <stdio.h>
#include <stdlib.h>

#define MAXLINES 100
#define MAXBYTE 255

// Function to read lines from a file into a buffer
int read_file_lines(FILE *fp, char buffer[MAXLINES][MAXBYTE + 1], int lines_expected) {
    int lines_read = 0; 

    while (lines_read < lines_expected && fgets(buffer[lines_read], MAXBYTE + 1, fp) != NULL) {
        lines_read++;  
    }

    return lines_read; // Return the actual number of lines read
}

int main(int argc, char *argv[]) {
    if (argc < 2 || argc > 3) {
        perror("Error: Incorrect number of arguments.\n");
        return 1;
    }

    // Get the filename from the arguments
    char *filename = argv[1];

    // Set the default number of lines to read
    int num_lines = 10;

    // If a second argument is provided, set num_lines to that value
    if (argc == 3) {
        num_lines = atoi(argv[2]);
        if (num_lines <= 0) {
            perror("Error: Invalid number of lines.\n");
            return 1;
        }
    }

    // Open the file
    FILE *file = fopen(filename, "r");
    if (file == NULL) {
        perror("fopen failed");
        return 1;
    }

    // Declare the buffer to store lines, read the lines, close the file
    char buffer[MAXLINES][MAXBYTE + 1]; // 2-D array to store lines from the file

    int lines_read = read_file_lines(file, buffer, num_lines);

    fclose(file);

    // Print the actual number of lines read
    printf("Number of lines read: %d\n", lines_read);

    // Print each line that was read
    for (int i = 0; i < lines_read; i++) {
        printf("%s", buffer[i]);
    }

    return 0;
}
 
 
//    #include <stdio.h>
//    #include <stdlib.h>
//    #include <stdbool.h>
//    #include <string.h>
//    #include <ctype.h>
 
 
//    enum intOrString {START, INT, STRING}; // make sure we have valid operands
 
//    // Prototype for checking if the command is valid
//    bool isvalid(char *s);
 
//    // Prototype for checking if a string is an integer
//    bool isinteger(char *s);
 
//    void add(int *n, int numInputs);
//    void mult(int *n, int numInputs);
//    void divide(int *n, int numInputs);
//    void len(char *s);
 
 
 
//    void add(int *n, int numInputs){
//      if (numInputs == 1){printf("More arguments are needed");}
//      exit(1);
//          int sum = 0;
//       for (int i=0; i<numInputs; i++){
//           sum += n[i];
//       }
//       printf("%d\n",sum);
//    }


// void mult(int *n, int numInputs){
//      if (numInputs == 1){printf("More arguments are needed");}
//      exit(1);
//      int product = 1;
//      for (int i=0; i<numInputs; i++){
//          product *= n[i];
//      }
//      printf("%d\n",product);
//    }
 
//     void divide(int *n, int numInputs){
//      if (numInputs == 1){printf("More arguments are needed");}
//      exit(1);
//      int quotient = n[0];
//      for (int i=1; i<numInputs; i++){
//          if (n[i]==0){
//              printf("Divide by zero\n");
//              exit(1);
//          }
//          quotient /= n[i];
//      }
//      printf("%d\n",quotient);
//    }
 
//    void len(char *s){
//      int length = 0;
//      while (s[length] != '\0'){
//          length++;
//      }
//      printf("%d",length);
//    }

//    // Main function
//    int main(int argc, char *argv[]) {
 
//      enum intOrString state = START; // to make sure we have valid operands
 
 
//       int myNums[argc-2];
//       char myStr[0];
 
 
//        // Check if there are at least three arguments including the program name
 
//        if (argc < 3) {
//            printf("Incorrect number of arguments.\n");
//            exit(1);
//        }
 
//        // Check if the first argument (command) is valid
//        if (!isvalid(argv[1])) {
//            printf("Unsupported function, try: add, mult, div, or len\n");
//            exit(1);
//        }
 
//        // Loop through remaining arguments and check if they are integers
//        for (int i = 2; i < argc; i++) {
 
//            if (isinteger(argv[i])) {
//              if (state == START || state == INT) {
//                state = INT;
//                myNums[i-2]=atoi(argv[i]);
//            }
//            else{
//              printf("Invalid operands\n"); // check the int state
//              exit(1);
//            }
//            }
//           else {
//              if (state==START || state==STRING){
//              state = STRING;
//              char myStr[strlen(argv[2])];
//              strcpy(myStr, argv[2]);
//            }
//            else{
//              printf("Invalid operands\n");
//              exit(1);
//            }
//        }
//        }
 
 
//       if (strcmp(argv[1],"add")==0){add(myNums, argc-2);}
//       else if (strcmp(argv[1],"mult")==0){ mult(myNums, argc-2);}
//       else if (strcmp(argv[1],"div")==0){divide(myNums, argc-2);}
//       else if (strcmp(argv[1],"len")==0){len(myStr);}
  
//      state = START;
//      return 0;
//    }

    
//    // Function to check if the command is valid
//    bool isvalid(char *s) {
//        // Array of valid commands
//        char *valid_commands[] = {"add", "mult", "div","len"};
//        for (int i = 0; i < 4; i++) {
//            if (strcmp(s, valid_commands[i]) == 0) {
//                return true;
//            }
//        }
//        return false;
//    }
 
//    // Function to check if a string is an integer
//    bool isinteger(char *s) {
//        // Check if each character is a digit
//        for (int i = 0; s[i] != '\0'; i++) {
//            if (!isdigit(s[i])) {
//                return false;
//            }
//        }
//        return true;
//    }
 


 
