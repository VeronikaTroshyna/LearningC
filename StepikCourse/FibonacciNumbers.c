#include<stdio.h>
void array_fib(int* array, int* limit) {
    int size = limit - array;
    if (size == 1)
    array[0] = 1;
    else if (size >= 2)
    {
        array[0] = 1;
        array[1] = 1;
    }
        for (int* current = array + 2; current < limit; current++)
        {
            *current = *(current - 1) + *(current - 2);
    }
    }



int main(void) {
    int myarray[15] ;
array_fib( myarray, myarray + 15 );
  for (int i = 0; i < 15; i++)
  {
    printf("%d\n", myarray[i]);
  }
}