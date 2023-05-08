#!/usr/bin/env python
#
# Mersenne Twister predictor
#
# Feed this program the output of any 32-bit MT19937 Mersenne Twister and
# after seeing 624 values it will correctly predict the rest.
#
# The values may come from any point in the sequence -- the program does not
# need to see the first 624 values, just *any* 624 consecutive values.  The
# seed used is also irrelevant, and it will work even if the generator was
# seeded from /dev/random or any other high quality source.
#
# The values should be in decimal, one per line, on standard input.
#
# The program expects the actual unsigned 32 bit integer values taken directly
# from the output of the Mersenne Twister.  It won't work if they've been
# scaled or otherwise modified, such as by using modulo or
# std::uniform_int_distribution to alter the distribution/range.  In principle
# it would be possible to cope with such a scenario if you knew the exact
# parameters used by such an algorithm, but this program does not have any
# such knowledge.
#
# For more information, refer to the original 1998 paper:
#
#  "Mersenne Twister: A 623-dimensionally equidistributed uniform pseudorandom
#   number generator", Makoto Matsumoto, Takuji Nishimura, 1998
#
#   http://citeseerx.ist.psu.edu/viewdoc/summary?doi=10.1.1.215.1141
#
# This code is not written with speed or efficiency in mind, but to follow
# as closely as possible to the terminology and naming in the paper.
#
# License: CC0 http://creativecommons.org/publicdomain/zero/1.0/

from __future__ import print_function
import sys
import collections

class Params:
    # clearly a mathematician and not a programmer came up with these names
    # because a dozen single-letter names would ordinarily be insane
    w = 32              # word size
    n = 624             # degree of recursion
    m = 397             # middle term
    r = 31              # separation point of one word
    a = 0x9908b0df      # bottom row of matrix A
    u = 11              # tempering shift
    s = 7               # tempering shift
    t = 15              # tempering shift
    l = 18              # tempering shift
    b = 0x9d2c5680      # tempering mask
    c = 0xefc60000      # tempering mask

def undo_xor_rshift(x, shift):
    ''' reverses the operation x ^= (x >> shift) '''
    result = x
    for shift_amount in range(shift, Params.w, shift):
        result ^= (x >> shift_amount)
    return result

def undo_xor_lshiftmask(x, shift, mask):
    ''' reverses the operation x ^= ((x << shift) & mask) '''
    window = (1 << shift) - 1
    for _ in range(Params.w // shift):
        x ^= (((window & x) << shift) & mask)
        window <<= shift
    return x

def temper(x):
    ''' tempers the value to improve k-distribution properties '''
    x ^= (x >> Params.u)
    x ^= ((x << Params.s) & Params.b)
    x ^= ((x << Params.t) & Params.c)
    x ^= (x >> Params.l)
    return x

def untemper(x):
    ''' reverses the tempering operation '''
    x = undo_xor_rshift(x, Params.l)
    x = undo_xor_lshiftmask(x, Params.t, Params.c)
    x = undo_xor_lshiftmask(x, Params.s, Params.b)
    x = undo_xor_rshift(x, Params.u)
    return x

def upper(x):
    ''' return the upper (w - r) bits of x '''
    return x & ((1 << Params.w) - (1 << Params.r))

def lower(x):
    ''' return the lower r bits of x '''
    return x & ((1 << Params.r) - 1)

def timesA(x):
    ''' performs the equivalent of x*A '''
    if x & 1:
        return (x >> 1) ^ Params.a
    else:
        return (x >> 1)

seen = collections.deque(maxlen=Params.n)

n = int(input())
a = []
for i in range(min(Params.n, n)):
    print("? " + str(i + 1) + " " + str(i + 1), flush = True)
    val = int(input())
    seen.append(untemper(val))
    a.append(val)

for i in range(Params.n, n):
    # The recurrence relation is:
    #
    #     x[k + n] = x[k + m] ^ timesA(upper(x[k]) | lower(x[k + 1]))
    #
    # Substituting j = k + n gives
    #
    #     x[j] = x[j - n + m] ^ timesA(upper(x[j - n]) | lower(x[j - n + 1]))
    #
    # The 'seen' deque holds the last 'n' seen values, where seen[-1] is the
    # most recently seen, therefore letting j = 0 gives the equation for the
    # next predicted value.

    next_val = seen[-Params.n + Params.m] ^ timesA(upper(seen[-Params.n]) | lower(seen[-Params.n + 1]))
    seen.append(next_val)
    a.append(temper(next_val))
print("! " + str(min(a)), flush = True)