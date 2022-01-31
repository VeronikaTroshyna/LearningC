#include <stdio.h>
#include <stdlib.h>

#define GET_Nth_BYTE(x, n) ((x) >> (n)*8) & 0xff

typedef union float_transmission {
    float flo;
    char arr[4];
} float_transmission;


int main() {
    float f = 2.5;
    float f_out;
                                        // CONVERTING BIT METHOD (FOT UNSIGNED INT)
    unsigned int val = 123456; // 00 01 E2 40
    unsigned char arr[4] = { 0, 0, 0, 0 };
    unsigned char cast_arr[4] = { 0, 0, 0, 0 };
    
    arr[0] = val & 0xff; //  00 01 E2 40 = 00000000 00000001 11100010 01000000
                         //& 00 00 00 FF = 00000000 00000000 00000000 11111111
                         //  00 00 00 40 = 00000000 00000000 00000000 01000000
    arr[1] = (val >> 8) & 0xff;
                         //  00 00 01 E2 = 00000000 00000000 00000001 11100010
                         //& 00 00 00 FF = 00000000 00000000 00000000 11111111
                         //  00 00 00 E2 = 00000000 00000000 00000000 11100010
    arr[2] = GET_Nth_BYTE(val, 2);
    arr[3] = GET_Nth_BYTE(val, 3);


                                         // CONVERTING POINTER METHOD (FOR FLOAT)
    unsigned char *fcp = (unsigned char*)&f;
    for (int i = 0; i < sizeof(f); i++)
        //cast_arr[i] = *(valcp + i);
        cast_arr[i] = fcp[i];
    // arr[i] == *(arr + i)

                                     // CONVERTING BIT METHOD (FOT FLOAT)
                                     
                        //I DON`T KNOW AT THIS MOMENT

                                     // CONVERTING UNION METHOD (FOT FLOAT)
    float_transmission f_uni, f_arv;
    f_uni.flo = f;

                                    // RECEIVE 4 BYTE TEST
    char arrived_arr[4] = { 0x71, 0x1d, 0x24, 0x44 }; // 656.46
    for (int i = 0; i < sizeof(f_arv.flo); i++)
        f_arv.arr[i] = arrived_arr[i];

    printf("%f\n", f_arv.flo);
    // out: 656.460022

                                    // OUTPUT FOR BIT METHOD (FOT UNSIGNED INT)
    printf("%d = %02x\'%02x\'%02x\'%02x\n", val, arr[0], arr[1], arr[2], arr[3]);
                                    // OUTPUT FOR POINTER METHOD (FOR FLOAT)
    printf("%f = %02x\'%02x\'%02x\'%02x\n", f, cast_arr[0], cast_arr[1], cast_arr[2], cast_arr[3]);
                                    // OUTPUT FOR UNION METHOD (FOT FLOAT)
    printf("%f = %02x\'%02x\'%02x\'%02x\n", f, f_uni.arr[0], f_uni.arr[1], f_uni.arr[2], f_uni.arr[3]);

    system("pause");
    
    return EXIT_SUCCESS;
}