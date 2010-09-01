/*
 *  peutils.c
 *  Version 1.0
 *
 *  Compile with -fvisibility=hidden
 */

#include <errno.h>
#include <math.h>
#include <stddef.h>
#include "peutils.h"

#define EXPORT __attribute__((visibility("default")))

/****** Begin internal parameters for is_prime ******/
/* Upper bound for domain of argument */
#define IS_PRIME_MAX 341550071728321

/*
 *  Precomputed primes for use in trial-division primality testing.
 *  Fifty-eight are probably enough.
 */
#define NPRIMES 58
static const unsigned int _primes[NPRIMES] = {2, 3, 5, 7, 11, 13, 17, 19, 23,
  29, 31, 37, 41, 43, 47, 53, 59, 61, 67, 71, 73, 79, 83, 89, 97, 101, 103,
  107, 109, 113, 127, 131, 137, 139, 149, 151, 157, 163, 167, 173, 179, 181,
  191, 193, 197, 199, 211, 223, 227, 229, 233, 239, 241, 251, 257, 263, 269,
  271};

/* Precomputed witnesses for Miller-Rabin test */
#define NWITNESSES 7
static const unsigned int _witnesses[NWITNESSES] = {2, 3, 5, 7, 11, 13, 17};

/****** End is_prime ******/

static unsigned int _highest_power_of_two(uint_fast64_t);

EXPORT
int is_prime(uint_fast64_t n)
{
    if (n < 2 || n >= IS_PRIME_MAX) {
        errno = EDOM;
        return ERROR;
    }

    /* Trial division */
    uint_fast32_t root_n = (uint_fast32_t) floor(sqrt(n));
    size_t i;
    for (i = 0; i < NPRIMES; ++i) {
        /* Requires list of primes to be in nondecreasing order. */
        if (_primes[i] > root_n)
            return PRIME;
        if (n % _primes[i] == 0)
            return COMPOSITE;
    }

    /* Begin Miller-Rabin. */

    unsigned int s = _highest_power_of_two(n - 1);
    uint_fast64_t d = (n - 1) / pow(2, s);

    size_t r;
    for (i = 0; i < NWITNESSES; ++i) {
        if ((uint_fast64_t) pow(_witnesses[i], d) % n == 1)
            return PRIME;
        for (r = 0; r < s; ++r)
            if ((uint_fast64_t) pow(_witnesses[i], ldexp(d, r)) % n == -1)
                return PRIME;
    }

    return COMPOSITE;
}

/*
 *  Determines and returns the binary logarithm of the highest power of 2 that
 *  divides the given even integer n.
 *
 *  Returns ERROR if the arg is odd and sets errno to EDOM.
 */
static unsigned int _highest_power_of_two(uint_fast64_t n)
{
    if (n % 2 == 1) {
        errno = EDOM;
        return ERROR;
    }

    /*
        TODO Change this loop to use bit-shifting? Benchmark first! ;)
    */
    unsigned int s = 0;
    while ((n / (uint_fast64_t) pow(2, ++s)) % 2 == 0)
        ;

    return s;
}
