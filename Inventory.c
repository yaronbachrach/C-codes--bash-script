#include <string.h>
#include <stdio.h>



//function to display the items
list(){


   printf("\t        item  quantity limit\tprice \n");
   FILE *pointer;
   pointer= fopen("inventory.csv", "r");//open the file for reading
   char temp[100];
   printf("\t");
   while (fgets(temp,100,pointer)!=NULL){
	char* next = strtok(temp, ",");
	printf("\t");
	while(next != NULL){
	
	printf("%s\t", next); 
		next = strtok('\0', ",");
 
        }
      
   }   
   fclose(pointer);//close the file for reading

}



//function for reordering
reorder(int quantity[],int limit[],char *item[100]){

   printf("\t        item  quantity limit\tprice \n");
   FILE *pointer;//pointer is a pointer in a text file
   pointer= fopen("inventory.csv", "r+");
   char temp[100];
   printf("\t");
   while (fgets(temp,100,pointer)!=NULL){
	char* next = strtok(temp, ",");//plug in into next the first filed in the line
	printf("\t");
	while(next != NULL){
	
	   printf("%s\t", next);//plug in into next the rest of the fileds in the line 
	   next = strtok('\0', ",");
 
        }
      
}   
   fclose(pointer);

   printf("\n");
   printf("MUST PURCHASE THE FOLLOWING ITEMS:\n");
   int i;
   for (i=0;i<10;i++)
     if (quantity[i]<=limit[i])// the case where our quantity is smaller or equal to the limit aloud
        printf("%s\n",item[i]);

}




//Function to deduct one unit from the quantity of of an item
deduct(char *food, int quantity[100], char *item[100],int limit[], double price[]){

   int i,j;
   FILE *file = fopen("inventory.csv", "r");
   for (i=0; i<10; i++)
    if (strcmp(item[i],food)==0)// The case where the input from the user is our item of food
       quantity[i]=quantity[i]-1;
    
     FILE *tempFile = fopen("change.csv", "w");
                for(j=0;j<i;j++)
            {
                fprintf (tempFile, "%s,%d,%d,%.2lf\n", item[j], quantity[j], limit[j], price[j]) ;
            }
                fclose(file);
                fclose(tempFile);
                remove("inventory.csv");
                rename("change.csv", "inventory.csv");

}




//Function to add a new item to our list
add(char *newItem,char *newQuantity,char *newLimit,char *newCost,int quantity[],int limit[],char *item[100],double price[]){
   FILE *file = fopen("inventory.csv", "r");	
   int i;
   char *temp;
   FILE *tempFile = fopen("change.csv", "w");
   //plug in the new values in to the appropriate arrays

    temp=strdup(newQuantity);
    quantity[10]=atoi(temp);
    limit[10]=atoi(newLimit);
    sscanf(newCost, "%lf", &price[10]);
    item[10]=strdup(newItem);
       
    for(i=0;i<11;i++)
            
        fprintf (tempFile, "%s,%d,%d,%.2lf\n", item[i], quantity[i], limit[i], price[i]) ;//writing to the file
                           
    fclose(file);//closing file 1
    fclose(tempFile);//closing file 2
    remove("inventory.csv");//removing the first file
    rename("change.csv", "inventory.csv");//rename the second file as the first file
}


//Main Function

int main(int argc, char *argv[]){

    printf("\n");
    int i = 0, j = 0;
    char command[50], argument[50], str[100];
    int quantity[100], limit[100];
    double price[100];
    char *item[100];
    char *token, *ptr;

    FILE *file = fopen("inventory.csv", "r");
    if(file == NULL)
    {
        printf("Error opening file\n");
    }


    //Scanning our file and plug in to the appropriate arrays
    
    while(fgets(str, 100, file) != NULL)
    {
        token = strtok (str,",");
        ptr = strdup(token);
        item[i] = ptr;
        sscanf (token, "%s", item[i]);
        token = strtok (NULL,",");
        sscanf (token, "%d", &quantity[i]);
        token = strtok (NULL,",");
        sscanf (token, "%d", &limit[i]);
        token = strtok (NULL,"\n");
        sscanf (token, "%lf", &price[i]);
        i++;
    }



// Calling the function according to the user input and handling errors of invalid input


   if (argc==2)
       if ((strcmp(argv[1],"list"))==0)
          list();
       else
          if ((strcmp(argv[1],"reorder"))==0)
      	    reorder(quantity,limit,item);
          else
             printf("Command not valid\n");
   else
       if (argc==3)
          if ((strcmp(argv[1],"deduct"))==0)
             deduct(argv[2],quantity,item,limit,price);
          else
             printf("Command not valid\n");
      else
          if (argc==6)
              if ((strcmp(argv[1],"add"))==0)
                  add(argv[2],argv[3],argv[4],argv[5],quantity,limit,item,price);
              else
                  printf("Command not valid\n");
         else
           printf("Command not found\n");




   printf("\n");
                   
}

