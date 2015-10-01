//
//  main.c
//  AssemblerTaskCalculate
//
//  Created by Serhii Kopach on 01.10.15.
//  Copyright (c) 2015 Serhii Kopach. All rights reserved.
//

#include <stdio.h>

void sum () {
    __asm__(
            "add %ebx,%eax\n"
            );
}
void substract () {
    __asm__(
            "sub %ebx,%eax\n"
            );
}
void multiply () {
    __asm__(
            "imul %ebx,%eax\n"
            );
}
void divide () {
    __asm__(
            "cdq\n"
            "idivl %ebx\n"
            );
}

int main () {
    int a = 12;
    int b = 4;
    int result;
    
    __asm__(
            "mov %0,%%eax\n"
            "mov %1,%%ebx\n"
            "call _multiply\n"
            "mov %%eax,%%ecx\n"
            "mov %0,%%eax\n"
            "mov %1,%%ebx\n"
            "call _divide\n"
            "sub %%eax,%%ecx\n"
            "mov %%ecx,%2\n"
            : "+m" (a), "+m" (b), "+m" (result));
    
    printf("Result: %d\n", result);
    return 0;
}
