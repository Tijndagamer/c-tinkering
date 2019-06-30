/*
 * wc2.c
 *
 * A (bad) wc clone.
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

#define BUFSIZE 256

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>

int main(int argc, char *argv[])
{
    char *fn = argv[1];

    int fd = open(fn, O_RDONLY);
    char buf[BUFSIZE];
    memset(&buf, 0, BUFSIZE);
    
    // lines, chars and word count
    int l = 0;
    int c = 0;
    int w = 0;

    int n = 1;
    while (n > 0) {
        n = read(fd, &buf, BUFSIZE);
        for (int i = 0; i < n; i++) {
            if (buf[i] != '\0') {
                c++;
                if (buf[i] == '\n')
                    l++;

                // word count isn't working correctly, hmmm...
                if (buf[i] == ' ')
                    if (buf[i-1] != ' ' && buf[i+1] != ' ')
                        w++;
            }
        }
    }

    printf("%d %d %d %s\n", l, w, c, fn);
}
