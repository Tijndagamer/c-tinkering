/*
 * factorize.c
 *
 * Simple program to factorize smaller composite numbers.
 *
 * Copyright (c) 2018 Martijn
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.*
 *
 */

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

const int PRIMES[] = {2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 27, 41, 43, 47, 53,
                    59, 61, 67, 71, 73, 79, 83, 89, 97, 101, 103, 107, 109, 113,
                    127, 131, 137, 139, 149, 151, 157, 163, 167, 173, 179, 181,
                    191, 193, 197, 199, 211, 223, 227, 229, 233, 239, 241, 251,
                    257, 263, 269, 271, 277, 281};

int factorize(int i, int *primefactors, size_t size)
{
    memset(primefactors, 0, size);
    int j = i;
    for (int q = 0, p = 0; j > 1; ) {
        printf("j: %d\tp: %d\tp: %d\tq: %d\n", j, PRIMES[q], p, q);
        if (j % PRIMES[q] == 0) {
            j = j / PRIMES[q];
            primefactors[p] = PRIMES[q];
            p++;
        } else {
            q++;
        }
    }
}

int main(int argc, char *argv[])
{
    int d[256];
    factorize(atoi(argv[1]), d, sizeof(d));
    for (int i = 0; i < sizeof(d); i++) {
        if (d[i] == 0)
            break;
        printf(" %d *", d[i]);
    }
    printf("\n");
}
