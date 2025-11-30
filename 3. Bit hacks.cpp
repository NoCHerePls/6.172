#include <iostream>
#include <stdio.h>


int main() {

    // x + ~x = -1
    // x + ~x   =   101010...10 + 010101...01   =   11111..1111   =   -2^n + 2^(n-1) + 2^(n-2) ... + 1   =   -1
    // so -x = ~x + 1

    // example: -5  -  ?
    // 5  = 0101
    // ~5 = 1010
    // -5 = 1010 + 1   =   1011
    // check: 1011  =  -8+2+1  =  -5

    // if we have 4 bits: 1111
    // then we can store numbers from -16 (-2^4 = '1000') to 15 ('0111')

    int c = 8;
    printf("C = %d\n", c); 

    int d = c << 2;
    printf("D = %d (expected 32)\n", d);

    int g = d >> 1;
    printf("G = %d (expected 16)\n", g);


    // now let's try setting 3th bit to '1' in '1001'
    int num = 9;
    num = num | (1 << 2);  // so it's '1001' or '0100' = '1101' which is 13
    printf("\n9 | (1 << 2) is %d (expected 13)", num);

    // let's set 5th bit to 1
    num = 9;  // '01001'
    num = num | (1 << 4);
    printf("\n9 | (1 << 4) is %d (expected 25)", num);


    // now let's set 3th bit to 0
    num = 14; // '1110'
    num = num & ~(1 << 2);
    printf("\n14 with 3th bit = 0 is %d (exp: 10)", num);

    num = 18; // '10010'
    num = num & ~(1 << 4);
    printf("\n18 with 5th bit = 0 is %d (exp: 2)", num);


    // now let's try switching 3th bit of '1001010'
    num = 74;
    num = num ^ (1 << 2);
    printf("\n\nSwitching 3th bit in 74 (exp 78): %d", num);

    // change 5th bit of '10010100'
    num = 148;
    num = num ^ (1 << 4);
    printf("\nSwitching 5th bit in 148 (exp 132): %d", num);


    // we now need to extract a bit field '001110' from '100100'!
    num = 36;
    num = (num & 14) >> 1;  // 14 is a mask '001110'
    printf("\nMask 001110 from 100100 is %d", num);


    // and now let's try to set a bit field
    num = 36; // '100100', we need to make '111100' from it
    int mask = 3; // '000011'
    num = num | (mask << 3);
    printf("\n'100100' + '011000' is %d (must be 60)", num);


    // what if we need to swap 2 integers?
    int a = 5;
    int b = 10;
    a = a^b;
    b = a^b;
    a = a^b;
    printf("\nSwapped integers: %d %d", a, b);


    // and now we need to find minimum of 2 ints
    a = 6;
    b = 465;
    int min = b ^ ((a^b) & -(a<b));
    // case x<y:  -(x<y) = -1, which is ob1111..11, so y^x^y = x
    // case x>=y:  -(x<y) = 0, so min = y
    printf("\n\nMin is %d", min);


    // how about modular addition?
    int x = 5;
    int y = 14;
    int mod = 10;

    int z = x+y;
    int res = z - (mod & -(z >= mod));
    // case x+y > mod:  z - mod, which is the answer
    // case x+y < mod:  z - 0 = x+y      
    printf("\nModular Sum is %d", res);


    // if you need to find least significant 1:
    a = 44; // '101100'
    res = a & -a;
    printf("\n\nLeast sign 1 is %d", res);


    return 0;
}