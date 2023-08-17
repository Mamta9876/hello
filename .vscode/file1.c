#include <stdio.h>
#include <stdlib.h>
/* Function declarations */
int even(const int num);
int prime(const int num);
int main(){
   FILE * fptrinput,
   * fptreven,
   * fptrodd,
   * fptrprime;
   int num, success;
   fptrinput = fopen("numbers.txt", "r");
   fptreven = fopen("even-numbers.txt" , "w");
   fptrodd = fopen("odd-numbers.txt" , "w");
   fptrprime= fopen("prime-numbers.txt", "w");
   if(fptrinput == NULL || fptreven == NULL || fptrodd == NULL || fptrprime == NULL){
      /* Unable to open file hence exit */
      printf("Unable to open file.");
      exit(EXIT_FAILURE);
   }
   /* File open success message */
   printf("File opened successfully. Reading integers from file. ");
   // Read an integer and store read status in success.
   while (fscanf(fptrinput, "%d", &num) != -1){
      if (prime(num))
         fprintf(fptrprime, "%d", num);
      else if (even(num))
         fprintf(fptreven, "%d", num);
      else
         fprintf(fptrodd, "%d", num);

   }
   fclose(fptrinput);
   fclose(fptreven);
   fclose(fptrodd);
   fclose(fptrprime);
   printf("Data written successfully.");
   return 0;
}
int even(const int num){
   return !(num & 1);
}
int prime(const int num){
   int i;
   if (num < 0)
      return 0;
   for ( i=2; i<=num/2; i++ ) {
      if (num % i == 0) {
         return 0;
      }
   }
   return 1;
}