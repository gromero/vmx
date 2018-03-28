#include <stdlib.h>
#include <stdio.h>
#include <inttypes.h>

int main()
{

 uint64_t *pointer = malloc(16);

 asm (
     "li 3, 1;"
     "mtvsrd 3, 3;" 
     "xxswapd 3,3;"
     "stxvd2x 3, 0, %[pointer];"
     "lxvd2x  4, 0, %[pointer];"
    : 
    : [pointer] "r" (pointer) 
    ); 
}
