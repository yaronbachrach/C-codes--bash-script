#include<stdio.h>
#include<stdlib.h>


int main(int argc, char *argv[]){
   char word[50];// declare an array char in the length of 50

   do {
      printf(">>");
     // Scaning into the first line
      scanf("%[^\n]%*c",word);

      if (strcmp(word,"done")==0)//in case the user want to exit
          break;
   
      system(word);//Send our command-line command(word) to the operating system
    }
   while (1); //it will continue always unless we break from inside the loop
      {}
   
   
   printf("Thank you for using mysh!\n");
   return 0;
}
