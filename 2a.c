    /*

     * C Program to find the possible subsets of the String

     */

    #include <stdio.h>
   #include<stdlib.h>
     

    

    void subset(int, int, int,char string[],int n);

     

    int main()

    {

        int i, n;
        char *array;
     

        printf("Enter the len of main set : ");

        scanf("%d", &n);
        array=(char*)malloc(n*sizeof(char));

        printf("Enter the elements of main set : ");

        scanf("%s", array);

       

        printf("The subsets are :\n");

        for (i = 1;i <= n;i++)

            subset(0, 0, i,array,n);

    }

     

    /*Function to find the number of subsets in the given string*/

     

    void subset(int start, int index, int num_sub,char string[],int n)

    {

        int i, j;

        if (index - start + 1  ==  num_sub)

        {

            if (num_sub  ==  1)

            {

                for (i = 0;i < n;i++)

                    printf("%c\n", string[i]);

            }

            else

            {

                for (j = index;j < n;j++)

                {

                    for (i = start;i < index;i++)

                        printf("%c", string[i]);

                    printf("%c\n", string[j]);

                }

                if (start != n - num_sub)

                    subset(start + 1, start + 1, num_sub,string,n);

            }

        }

        else

        {

            subset(start, index + 1, num_sub,string,n);

        }

    }
