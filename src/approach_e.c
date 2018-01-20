/*
 * approach_e.c
 *
 * Simple program to approach the mathematical constant e.
 *
 *      infinity
 *     -------
 *     \
 *      \
 *       \  1
 *  e =  / ---
 *      /   n!
 *     /
 *     -------
 *      n = 0
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

float factorial(float f)
{
    if (f == 0)
        return 1;
    else
        return (f * factorial(f - 1.0));
}

float approach_e(float res, float e)
{
    if (res == 0)
        return e + 1;
    else
        e += (1.0 / factorial(res));
        return approach_e(res - 1, e);
}

int main(int argc, char* argv[])
{
    printf("%f\n", approach_e(20.0, 0));
}
