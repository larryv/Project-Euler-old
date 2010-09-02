#ifndef PROJEULER_H

/*
 *  peutils.h
 *  VERSION: 1.0.0
 *  AUTHOR: Lawrence Velazquez
 *
 *  Interface to libpeutils.dylib
 */

#define PROJEULER_H

#include <stdint.h>

#define ERROR    -1
#define COMPOSITE 0
#define PRIME     1

/*
 *  Determines whether the nonnegative integer argument n is prime. Uses trial
 *  division to rule out relatively small potential prime factors, then
 *  switches to a deterministic variant of the Miller-Rabin test. See
 *  http://en.wikipedia.org/wiki/
 *      Miller–Rabin_primality_test#Deterministic_variants_of_the_test.
 *
 *  Returns:
 *      COMPOSITE   if n is composite.
 *      PRIME       if n is prime.
 *      ERROR       if n is outside the range [2, 341550071728320]. (The
 *                  upper bound was chosen so that the Miller-Rabin algorithm
 *                  could be deterministic with only 7 witnesses.) The
 *                  variable errno is set to EDOM.
 *
 *  These macros are defined in peutils.h.
 */
int is_prime(uint_fast64_t n);

/* End peutils.h */

#endif
