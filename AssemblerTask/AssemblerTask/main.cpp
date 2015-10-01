//
//  main.cpp
//  AssemblerTask
//
//  Created by Serhii Kopach on 01.10.15.
//  Copyright (c) 2015 Serhii Kopach. All rights reserved.
//

#include <stdio.h>

int multiply (int a, int b) {
    int result;
    
    __asm__(
            "mov %0,%%eax\n"
            "mov %1,%%ecx\n"
            "imul %%eax,%%ecx\n"
            "mov %%ecx,%2\n"
            : "+r" (a), "+r" (b), "+m" (result));
    
    return result;
}

int divide (int a, int b) {
    int result;
    
    __asm__(
            "mov %0,%%eax\n"
            "cdq\n"
            "mov %1,%%ebx\n"
            "idivl %%ebx\n"
            "mov %%eax,%2\n"
            : "+r" (a), "+r" (b), "+m" (result));
    
    return result;
}

int main() {
    int a = 21;
    int b = 3;
    int result = divide(a, b);
    
    printf("Result: %d\n", result);
    
    return 0;
}
