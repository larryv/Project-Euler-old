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


#define COMPOSITE 0
#define PRIME     1
#define ERROR    -1

#define TARGET 600851475143


int is_prime(uint32_t);
static uint8_t highest_power_of_two(uint32_t);
static void test_highest_power_of_two(void);

static uint16_t primes[58] = {2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37, 41,
                              43, 47, 53, 59, 61, 67, 71, 73, 79, 83, 89, 97,
                              101, 103, 107, 109, 113, 127, 131, 137, 139,
                              149, 151, 157, 163, 167, 173, 179, 181, 191,
                              193, 197, 199, 211, 223, 227, 229, 233, 239,
                              241, 251, 257, 263, 269, 271};

int main(int argc, char const *argv[])
{
    test_highest_power_of_two();
    return 0;
}

/*
    Determines whether the positive integer argument n is prime. Uses trial
    division to rule out relatively small potential prime factors, then
    switches to a deterministic variant of the Miller-Rabin test.
    
    Returns:
        COMPOSITE   if n is composite
        PRIME       if n is prime
        ERROR       if n is less than 2
    
    These macros are defined above.
*/
int is_prime(uint32_t n)
{
    if (n < 2)
        return ERROR;
    
    /* Trial division */
    size_t num_of_primes = sizeof primes / sizeof(uint16_t);
    uint16_t root_n = floor(sqrt(n));
    size_t i;
    for (i = 0; i < num_of_primes; ++i) {
        if (primes[i] > root_n)
            return PRIME;
        if (n % primes[i] == 0)
            return COMPOSITE;
    }
    
    /* Begin Miller-Rabin */
    
    
    
    return 0;
}

/*
    Determines and returns the binary logarithm of the highest power of 2 that
    divides the given even integer n.
    
    Returns ERROR if the arg is odd.
*/
static uint8_t highest_power_of_two(uint32_t n)
{
    if (n % 2 == 1)
        return ERROR;
    
    uint8_t s = 0;
    uint32_t d;
    while ((d = n / pow(2, ++s)) % 2 == 0)
        ;
    
    return s;
}







// ================================================================
// =                          UNIT TESTS                          =
// ================================================================


/*
    Unit test for highest_power_of_two() function. Prints table of inputs,
    expected results, and computed results.
*/
static void test_highest_power_of_two(void)
{
    int test_figures[10] = {2,220,5632,1112,612352,38,96,3145728,2432,454656};
    int test_solutions[10] = {1,2,9,3,11,1,5,20,7,12};
    
    printf("%10s %10s %10s\n", "Input", "Expected", "Actual");
    
    size_t i;
    for (i = 0; i < 10; ++i) {
        printf("%10d %10d %10d\n",
                test_figures[i],
                test_solutions[i],
                highest_power_of_two(test_figures[i]));
    }
}