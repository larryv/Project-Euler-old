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
 *  Determines (deterministically!) whether the nonnegative integer argument
 *  n is prime.
 *
 *  Returns:
 *      COMPOSITE   if n is composite.
 *      PRIME       if n is prime.
 *      ERROR       if n is outside the range [2, 341550071728320]. The
 *                  variable errno is set to EDOM. (See errno.h.)
 */
int is_prime(uint_fast64_t n);

/* End peutils.h */

#endif
