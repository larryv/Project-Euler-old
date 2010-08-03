/*
    Project Euler, Problem 3
    
    ==========
    The prime factors of 13195 are 5, 7, 13 and 29.
    
    What is the largest prime factor of the number 600851475143?
    ==========
    
    Lawrence Velazquez
    2 August 2010
*/

#include <math.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>


#define TARGET 600851475143


int is_prime(uint32_t);
static int16_t primes[58] = {2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37, 41,
                             43, 47, 53, 59, 61, 67, 71, 73, 79, 83, 89, 97,
                             101, 103, 107, 109, 113, 127, 131, 137, 139, 149,
                             151, 157, 163, 167, 173, 179, 181, 191, 193, 197,
                             199, 211, 223, 227, 229, 233, 239, 241, 251, 257,
                             263, 269, 271};

int main(int argc, char const *argv[])
{
    double target_sqrt = sqrt(TARGET);
    return 0;
}

/*
    Determines whether the positive integer argument n is prime, to a high
    degree of certainty. Uses trial division to rule out relatively small 
    potential prime factors, then switches to the Miller-Rabin test.
    
    Returns:
        0 if n is composite,
        1 if n is very likely to be prime,
       -1 if n is less than 2.
*/
int is_prime(uint32_t n) {
    if (n < 2) {
        return -1;
    }
    
    size_t i;
    for (i = 0; i < 58; ++i) {
        if (n % primes[i] == 0) {
            return 0;
        }
    }
    
    
        
    return 0;
}