/*
 * euclid_algorithm.c
 * 
 * A simple C implementation of Euclid's algorithm to find the greatest
 * common divisor (gcd) of two integers a and b.
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
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */

#include <stdio.h>
#include <string.h>

int get_gcd(int a, int b)
{
    int k = a / b;
    int r = a % b;
    if (r == 0) {
        return b;
    } else {
        return get_gcd(b, r);
    }
}

int main(int argc, char* argv[])
{
    printf("%d\n", get_gcd(120, 84));
    return 0;
}
