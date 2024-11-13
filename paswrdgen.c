#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <unistd.h>

int main()
{
  printf("Length: ");

  int length;
  scanf("%d", &length);

  if (length <= 0)
  {
    printf("Password length must be >= 1!");

    return 1;
  }

  char *password = malloc(length + 1); //allocating memory for the inputed value of length +1,+1 for the endline character

  char *digits = "0123456789"; // using numbers as a string as it would make the using random function similar to using your usual characters
  int digits_length = strlen(digits);
  
  char *lowers = "abcdefghijklmnopqrstuwxyz";
  int lowers_length = strlen(lowers);
  
  char *uppers = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
  int uppers_length = strlen(uppers);
  
  char *symbols = "!@#$%^&*()";
  int symbols_length = strlen(symbols);
    

  
  srand(time(NULL) * getpid()); // srand is a function that takes in the input in the bracker, in this case i have inputed current time as an 
                                // argument and program id as they are alwasys unique, making a the overall argument totally unique and random
  
  for (int i = 0; i < length; i++)
  {
    int char_type = rand() % 4;
    
    if (char_type == 0)
      password[i] = digits[rand() % digits_length];
    else if (char_type == 1)
      password[i] = lowers[rand() % lowers_length];
    else if (char_type == 2)
      password[i] = uppers[rand() % uppers_length];
    else
      password[i] = symbols[rand() % symbols_length];
    
  }

  password[length] = '\0';
  
  printf("Password: %s\n", password);

  free(password);

  return 0;
}