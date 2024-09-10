/*
  * File name: fsm.c
  * Compile with: gcc -std=c99 fsm.c -o fsm
  *
  * This file contains a few finite state machines that recognize various
  * patterns.
  *
  * CSCI 306 exercises (student file)
  */
 #include <stdio.h>
 #include <stdbool.h>   // bool type
 #include <stdlib.h>    // exit()
 #include <string.h>
 
 enum NUM_STATE {NON_DIGIT, DIGIT};  // states for a number
 enum ALPHA_NUM_STATE {ALPHA_NUM, NON_ALPHA_NUM};
 
 
 int const MAX_LENGTH = 16;   // max length of a int
 
 
 bool my_isdigit(char);       // returns true if char is a digit, false otherwise
 bool my_isalpha(char);         // returns true if char is alpha, false if not
 void parse_int(char *);      // parse int out of a string
 
 void parse_word(char *);    // parse out the word
 
 int  grow_number(char *, char, int);   // increase the int by a digit
 void end_number(char *, int);          // end of an int
 
 int main(int argc, char *argv[]) {
 
   if (argc != 2) {
    fprintf(stderr, "Usage: %s string\n", argv[0]);
     exit(1);
   }
 
   parse_word(argv[1]);
   //parse_word('h0w5 7h3 w347h32?');
 
   return 0;
 }
 
 bool my_isdigit(char c) {
 
   if (c >= '0' && c <= '9')
     return true;
   else
     return false;
 }
 
  bool my_isalpha(char c) {
      if ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z')) {
          return true;
      }
      else if (my_isdigit(c)) {
          return true;
      }
      return false;
 
  }



 void parse_word(char * s) {
 
    enum ALPHA_NUM_STATE state = NON_ALPHA_NUM   ;
    int  len = strlen(s);
    char one_number[MAX_LENGTH+1]; // used to store one integer
    int word_count=0;          // how many words in current int
 
    for (int i = 0; i < len; ++i) {
      if (state == NON_ALPHA_NUM) {
        if ((my_isalpha(s[i])) || (my_isdigit(s[i]))) {
          state = ALPHA_NUM;
          word_count = grow_number(one_number, s[i], word_count);
        }
      } else if (state == ALPHA_NUM) {
        if ((my_isalpha(s[i]) == true) || (my_isdigit(s[i] == true))) {
          word_count = grow_number(one_number, s[i], word_count);
        } else { // end of a number
          end_number(one_number, word_count);
          word_count = 0;              // ready to start a new number
          state = NON_ALPHA_NUM;
        }
      } else {
        printf("error, non-existing state.\n");
      }
    } // end of for
    if (word_count > 0) { // the very last token is int
      one_number[word_count] = 0;  // terminate the string
      printf("one token : [%s]\n", one_number);
    }
  }

  void parse_int(char * s) {
 
   enum NUM_STATE state = NON_DIGIT;
   int  len = strlen(s);
   char one_number[MAX_LENGTH+1]; // used to store one integer
   int  digit_count = 0;          // how many digits in current int
 
   for (int i = 0; i < len; ++i) {
     if (state == NON_DIGIT) {
       if (my_isdigit(s[i]) == true) {
         state = DIGIT;
         digit_count = grow_number(one_number, s[i], digit_count);
       }
     } else if (state == DIGIT) {
       if (my_isdigit(s[i]) == true) {
         digit_count = grow_number(one_number, s[i], digit_count);
       } else { // end of a number
         end_number(one_number, digit_count);
         digit_count = 0;              // ready to start a new number
         state = NON_DIGIT;
       }
     } else {
       printf("error, non-existing state.\n");
     }
   } // end of for
   if (digit_count > 0) { // the very last token is int
     one_number[digit_count] = 0;  // terminate the string
     printf("one token : [%s]\n", one_number);
   }
 }

 
 
 int grow_number(char *token, char ch, int cur_len) {
 
   if (cur_len < MAX_LENGTH) {
     token[cur_len] = ch;
   } else { // truncate the token
     token[cur_len] = 0;    // terminate the current one
     printf("one token : [%s]\n", token);
     cur_len = 0;              // ready to start a new token
     token[cur_len] = ch;  // the last char belongs to next int
   }
   cur_len ++;
   return cur_len;
 }
 
 void end_number(char *token, int cur_len) {
 
   token[cur_len] = 0;  // terminte the string
   printf("one token : [%s]\n", token);
 }

