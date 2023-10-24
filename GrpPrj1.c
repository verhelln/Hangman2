// file name GrpPrj1.c
// This is a test to see if I can edit the file

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

int main() {

  srand(time(NULL));
  
  char posWords[][16] = {
    "america",
    "tractor",
    "hazing",
    "burger",
    "food",
    "xylophone"
  };
  
  int randPick = rand() % 6;
  printf("%s\n", posWords[randPick]);
  int Lives = 6;
  int amtcorrect = 0;
  int prevcorrect = 0;
  
  
  int WordLength = strlen(posWords[randPick]);
  char Guessedletters[26] = {0};
  
  int leave = 0;
  char guess[16];
  char enteredLetter;
  char blanks[10];
  int q;
  
  for(q=0; q < WordLength; q++) {
      blanks[q] = '_';
      printf("%c ", blanks[q]);
  }
  printf("\n");
  blanks[q] = 0;
  
  while (amtcorrect < WordLength) {
    printf("Enter a letter: ");
    fgets(guess, 16, stdin);
    enteredLetter = guess[0];
    printf("You entered %c\n", enteredLetter);
  
    prevcorrect = amtcorrect;
  
    int i = 0;
    for(i=0; i < WordLength; i++) {
        if (Guessedletters[i] == 1) {
         continue;
         }
        if(Guessedletters[i] == 0 && enteredLetter == posWords[randPick][i]) {
            Guessedletters[i] = 1;
            amtcorrect++;
            blanks[i] = enteredLetter;
        }
        
    }
    for(q=0; q < WordLength; q++) {
      printf("%c ", blanks[q]);
    }
  printf("\n");
    if (prevcorrect == amtcorrect) {
      Lives--;
      printf("Nope not right :(\n");
      if (Lives == 0) {
        break;
      }
    }
    else {
      printf("You got one :)\n");
  }
  
  printf("%d\n", Lives);
  }
  if (Lives == 0) {
    printf("You failed, rip my man, the word was %s\n", posWords[randPick]);
  }
  else {
    printf("Congrats on the dub :D\n");
  }
return 0;
}
