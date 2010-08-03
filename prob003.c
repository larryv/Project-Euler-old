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


#define ERROR    -1
#define COMPOSITE 0
#define PRIME     1
#define TARGET 600851475143


/* Auxiliary functions */
int is_prime(uint32_t);
static uint8_t highest_power_of_two(uint32_t);


/* Unit tests */
static void test_is_prime(void);
static void test_highest_power_of_two(void);
static void print_test_table(int trials, int inputs[], int expected[],
                             int actual[]);


/* External constant values for use in primality testing */
static const unsigned int primes[58] = {2, 3, 5, 7, 11, 13, 17, 19, 23, 29,
  31, 37, 41, 43, 47, 53, 59, 61, 67, 71, 73, 79, 83, 89, 97, 101, 103, 107,
  109, 113, 127, 131, 137, 139, 149, 151, 157, 163, 167, 173, 179, 181, 191,
  193, 197, 199, 211, 223, 227, 229, 233, 239, 241, 251, 257, 263, 269, 271};


int main(int argc, char const *argv[])
{
    printf("To be factored: %ld\n", TARGET);
    
    uint32_t target_sqrt = floor(sqrt(TARGET));
    uint32_t i;
    for (i = target_sqrt; i > 1; --i) {
        if (TARGET % i == 0 && is_prime(i)) {
            printf("Largest prime factor: %u\n", i);
            break;
        }
    }
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
        /* Requires list of primes to be in nondecreasing order. */
        if (primes[i] > root_n)
            return PRIME;
        if (n % primes[i] == 0)
            return COMPOSITE;
    }
    
    /*
        Begin Miller-Rabin. Algorithm details at:
        http://en.wikipedia.org/wiki/
            Miller–Rabin_primality_test#Deterministic_variants_of_the_test
    */
    
    uint8_t s = highest_power_of_two(n - 1);
    uint32_t d = (n - 1) / pow(2, s);
    
    size_t r;
    int witnesses[3] = {2, 7, 61};
    for (i = 0; i < 3; ++i) {
        if ((int32_t) pow(witnesses[i], d) % n == 1)
            return PRIME;
        for (r = 0; r < s; ++r)
            if ((int32_t) pow(witnesses[i], pow(2, r) * d) % n == -1)
                return PRIME;
    }
    
    return COMPOSITE;
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
    Unit test for is_prime() function.
*/
static void test_is_prime(void)
{
    size_t i;
    
    
    /* Test the set of precomputed primes */
    
    int num_precomp_primes = sizeof primes / sizeof(uint16_t);
    
    int test_solutions[num_precomp_primes];
    int test_results[num_precomp_primes];
    for (i = 0; i < num_precomp_primes; ++i) {
        test_solutions[i] = PRIME;
        test_results[i] = is_prime(primes[i]);
    }
    
    puts("PRIMES\n");
    print_test_table(58, (int *) primes, test_solutions, test_results);
    
    
    /* Test some regular old composites */
    int test_inputs[8] = {4, 10, 100, 555, 65452, 99, 1000000, 1729};
    
    for (i = 0; i < 8; ++i) {
        test_solutions[i] = COMPOSITE;
        test_results[i] = is_prime(test_inputs[i]);
    }
    
    puts("\n\nUNREMARKABLE COMPOSITES\n");
    print_test_table(8, test_inputs, test_solutions, test_results);
    
    
    /* Test some Carmichael numbers */
    int carmichael[33] = {561, 1105, 1729, 2465, 2821, 6601, 8911, 10585,
      15841, 29341, 41041, 46657, 52633, 62745, 63973, 75361, 101101, 115921,
      126217, 162401, 172081, 188461, 252601, 278545, 294409, 314821, 334153,
      340561, 399001, 410041, 449065, 488881, 512461};
    
    int cm_solutions[33];
    int cm_results[33];
    for (i = 0; i < 33; ++i) {
        cm_solutions[i] = COMPOSITE;
        cm_results[i] = is_prime(carmichael[i]);
    }
    
    puts("\n\nCARMICHAEL NUMBERS\n");
    print_test_table(33, carmichael, cm_solutions, cm_results);    
}


/*
    Unit test for highest_power_of_two() function.
*/
static void test_highest_power_of_two(void)
{
    int test_figures[10] = {2,220,5632,1112,612352,38,96,3145728,2432,454656};
    int test_solutions[10] = {1,2,9,3,11,1,5,20,7,12};
    int test_results[10];
    
    size_t i;
    for (i = 0; i < 10; ++i) {
        test_results[i] = highest_power_of_two(test_figures[i]);
    }
    
    print_test_table(10, test_figures, test_solutions, test_results);
}

/*
    Used by unit tests to print table of inputs and results.
*/
static void print_test_table(int trials, int inputs[], int expected[],
                             int actual[])
{
    printf("%15s %15s %15s\n", "Input", "Expected", "Actual");
    
    size_t i;
    for (i = 0; i < trials; ++i) {
        printf("%15d %15d %15d\n", inputs[i], expected[i], actual[i]);
    }
}
