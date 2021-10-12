// counter way
void array_reverse(int* array, int size) {
   for (int i = 0; i < size/2; i++) {
       int temp = array[i];
       array[i] = array[size - i - 1];
       array[size - i - 1] = temp;
   }
}
// pointer way
void array_reverse_ptr(int* array, int* limit) {
    limit--;
    for (int* current = array; current < limit; current++, limit--)
    {
        int temp = *current;
        *current = *limit;
        *limit = temp;
    }
}