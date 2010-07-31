/*
    Project Euler, Problem 1
    
    ==========
    If we list all the natural numbers below 10 that are multiples of
    3 or 5, we get 3, 5, 6 and 9. The sum of these multiples is 23.
    
    Find the sum of all the multiples of 3 or 5 below 1000.
    ==========
    
    Lawrence Velazquez
    31 July 2010
*/

#include <math.h>
#include <stddef.h>
#include <stdint.h>
#include <stdio.h>

uint32_t sum_multiples(int, int);

int main(int argc, char const *argv[])
{
    /*
        The approach here will be to determine the sum of all multiples of 3,
        then add the sum of all multiples of 5, then subtract the sum of all
        multiples of 15.
    */
    
    uint32_t a;
    
    a = sum_multiples(3, 1000) + sum_multiples(5, 1000) -
                                                    sum_multiples(15, 1000);
    
    printf("a = %d\n", a);
    return 0;
}

/*
    This function uses arithmetic summation to sum the multiples of
    the number "base", up to a certain ceiling ("max").
*/
uint32_t sum_multiples(int base, int max)
{
    uint16_t n;
    n = ceil((double) max / base - 1);
    return base * n * (n + 1) / 2;
}