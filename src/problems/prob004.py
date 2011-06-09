#!/usr/bin/env python3.2

#
# Project Euler, Problem 4
#
# ==========
# A palindromic number reads the same both ways. The largest palindrome made
# from the product of two 2-digit numbers is 9009 = 91 * 99.
#
# Find the largest palindrome made from the product of two 3-digit numbers.
# ==========
#
# Lawrence Velazquez
# 8 June 2011

def is_palindrome(n):
    s = str(n)
    half = len(s) // 2
    front = s[:half]
    back = s[-1 * half:]
    return front == ''.join(reversed(back))

palindromes = (x * y for x in range(100, 1000) for y in range(100, 1000)
                     if is_palindrome(x * y))
print(max(palindromes))

