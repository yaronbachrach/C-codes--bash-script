#include <string.h>
#include <stdio.h>


int numExperiments = 0;

//function To display names of the experiments with  all the data
void Displayall(char *experiments[20],int data[10][20]){
   int i,j;
   printf("\n");
   for (i=0; i<numExperiments; i++){
    printf("%s\n",experiments[i]);
    for (j=0; j<10; j++)
        printf ("%d ",data[j][i]);
    printf("\n");
    }
 }


//function to return the avarage of a spesific experiment
double IndividualAvarage(char *name, char *experiments[20], int data[10][20]){
   printf("%s",name);
   int i,j,temp, valid;
   int count=0;
   valid = 0;
   for (i=0;i<numExperiments; i++){
      if (strcmp(name,experiments[i])==0){
         temp=i;
	 valid = 1;
         break;
      }
    }
  if (valid)
   {	
  for (j=0; j<10; j++)
     count= count+data[j][temp];//Summing the date in the spesific experiment
     
     
     return(count/10.0);
   } 
    else //this for the when there is no match between the input name and the names of experiments
	return -1;

}



//Function to return the avarage of all the experiments together
double allAvarage(int data[10][20]){
   int i,j;
   int sum=0;

   for (i=0; i<numExperiments; i++){
      for (j=0; j<10; j++)
         sum=sum+data[j][i];// summing up all the values of all the experiments 
    }


return (sum/(10*numExperiments));//returning the avarage of all the experiments together



//Main Method
}
int main(){
    char help[100];
    char *experiments[20];
    int data[10][20];
   


 //Scaning the name and the data
    while (numExperiments<=20){
         
         scanf("%[^\n]\n", help);// scaning the line of the name of the experiment and put it inside help
       
        if(strcmp("***END***",help) == 0) 
            break; 
        experiments[numExperiments] = strdup(help);//creating a copy
        scanf("%[^\n]\n", help);// scaning the line of the data(values) of the experiment and put it inside help
        
        int i=0;
        char *move = strtok(help, " ");// plug in the first value in move(where the data is) until the space bar
        while (i < 10){
            data[i][numExperiments]=atoi(move);
            move = strtok(NULL, " ");// plug in the rest of the values
             i++;
        }

        numExperiments=numExperiments+1;//increment numExperiment by one

       
     }
     int choice;
     
     //setting the stdin back to the keyboard
     freopen("/dev/tty", "rw", stdin);
    

    do{
        //Print instructions         
    	printf("\nDATA SET ANALYSIS\n");
    	printf("1.   show all the data\n");
    	printf("2.   calculate the avarage for an experiments\n");
    	printf("3.   calculate the avarage across all experiments\n");
    	printf("4.   Quit\n");
  	  printf(".   Selection:_");
            
          scanf("%d",&choice);//scanning our choice
          char takeit = getchar();
	
     	 choice= choice;
           switch (choice){
		 
                 case 1://Case to display
                     Displayall(experiments,data);
                 break;
                 

                 case 2://case of individual avrage
                     printf("\nPlease type the name of experiment for which you want to calculate its avarage\n");
                     char name[512];
                     scanf("%[^\n]%*c", name);
                 
                
                     double result=IndividualAvarage(name,experiments,data);
                
                     if (result==-1)
                          printf("\nThere is no experiment with this name, Please try again\n");
                     else 
                         printf("\n\nThe Individual Avarage of %s is: %f\n",name,result);
                      break;
                 
                 
                 case 3://case of all avarage
                 
                     printf("\nThe avarage of all the experiments is: %f\n",allAvarage(data));
                     break;
                 
                 case 4 ://case of exit
                         break;
                 
                 default:
                 printf("\nWrong typing, please try again \n");
                 break;
                   
             }
     }
    while (choice != 4);//the loop will comtinue untill the user press 4
	
      return 0;

 }



    
