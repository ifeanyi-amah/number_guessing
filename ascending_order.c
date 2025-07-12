#include <stdio.h>

int sizeOfArray(int array[]){
    int count = 0;
    while (array[count] != 0 ) {
        count++;
    }
    return count;
}

int main(void) 
{

    int array[] = {1,5,2,3,4};
    int count = sizeOfArray(array);

    int a = 0;
    while (a < count)
    {
        for(int i = a; i<count; i++) {
            int num = array[a];
            int num2 = array[i];
            if (num > num2)
            {
                array[a] = num2;
                array[i] = num;
            }
        }
        a++;
    }

    for(int i =0; i<count; i++) {
        printf("Index %d is %d \n", i, array[i]);
    }

    return 0;
}



