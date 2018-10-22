//Suppose a positive integer is entered through the keyboard, write a function to find the binary equivalent of this number using recursion.
#include<stdio.h>
int BinaryConversion(int n)                                             //Function to compute the binary equivalent of input number
{
   if(n==0)
           return 0;
   else 
	   return (n%2)+10*BinaryConversion(n/2);                        //Recursive Call

}

void main()
{
    int n,num;
    printf("Enter the number whose binary equivalentis to be found ");  //Input the number whose binary equivalent is to be found      
    scanf("%d",&n);
    num=BinaryConversion(n);
    printf("\n The binary equivalent of the input number is : %d",num); //Displaying the binary equivalent

}

