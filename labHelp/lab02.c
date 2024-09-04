                                                                                                                    
 /**
  * Owen Reilly
  * CSCI 306
  * lab 02 - switchcase.c
  * notes: none
  */
 
 #include <stdio.h>
 #include <string.h>
 #include <ctype.h>
 
 int main(){
     char string[256];   // store input string
 
     // this loop will read one line of input at a time
     // if EOF is reached, fgets() will return false, thus the loop will exit.
     while ( fgets(string, sizeof(string), stdin) != NULL){
        int len = strlen(string);
        //char string2[len];
        for (int i = 0; i < len; i++){
            string[i] = toupper(string[i]);
        }

         /* use strlen and toupper in a loop to convert the string here */
 
         // print the result
         printf("%s", string);
     }
 
     // C main programs return an error code. Typically 0 means “No errors.”
     return 0;
 }
 


//  #include <stdio.h>
//  #include <math.h>

//  int main(){
//     long long int n = 2147483645;
//     int i=2;
//     while(i<n){
//         if(n%i==0){
//             printf("%d\n",i);
//             n/=i;
//         }
//         else{
//             i++;
//         }
//  }
//      if (n > 1) {
//         printf("%lld\n", n);
//     }
//  }
 


//  int main(void) {
//      float hourly_wage;
//      int weeks;
//      printf("Enter hourly wage (float): ");
//      scanf("%f", &hourly_wage);
//      printf("Enter number of weeks (integer): ");
//      scanf("%d",&weeks);
//      printf("Annual salary is:  %.2f\n", hourly_wage * 40 * weeks);
//      return 0;
//  } 