/*
 * otp.c
 *
 * A simple implementation of one time pad encryption.
 *
 * Copyright (c) 2019 Martijn
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
 *
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */

#include <stdio.h>
#include <string.h>
#include <errno.h>

#define BUFSIZE 256

void print_char_array(char *in)
{
    for (int i = 0; i < strlen(in); i++) {
        printf("in[%d]: %c\t%d\n", i, in[i], in[i]);
    }
    printf("\n");
}

int main(int argc, char* argv[])
{
    if (argc < 3) {
        printf("Usage: %s [MESSAGE FILE] [PAD FILE]\n", argv[0]);
        return -1;
    }

    const char *msg_fn = argv[1];
    const char *otp_fn = argv[2];
    const char *output_fn = "output.txt";

    printf("Found message file: %s\nFound otp file: %s\n", msg_fn, otp_fn);

    FILE *msg_f = fopen(msg_fn, "r");
    if (msg_f == NULL) {
        printf("Couldn't open %s, exiting.\n", msg_fn);
        return -1;
    }

    FILE *otp_f = fopen(otp_fn, "r");
    if (otp_f == NULL) {
        printf("Couldn't open %s, exiting.\n", otp_fn);
        return -1;
    }

    FILE *output_f = fopen(output_fn, "w");
    if (output_f == NULL) {
        printf("Couldn't open %s, exiting.\n", output_fn);
        return -1;
    }

    char m_buf[BUFSIZE]; // buffer for the input message
    char p_buf[BUFSIZE]; // buffer for the pad
    char o_buf[BUFSIZE]; // buffer for the output message
    int i = -1;
    int j = -1;
    int blocks = 0;
    do {
        i = fread(m_buf, 1, BUFSIZE-1, msg_f);
        j = fread(p_buf, 1, BUFSIZE-1, otp_f);

        if (j < i) {
            printf("Pad is too short! Quitting.\n");
            return -1;
        }

        for (int k = 0; k < i; k++) {
            o_buf[k] = m_buf[k] ^ p_buf[k];
        }
        blocks++;

        fwrite(o_buf, 1, BUFSIZE - 1, output_f);

        m_buf[i] = '\0';
        printf("Read %d bytes.\n", i);
        printf("%s\n", m_buf);
    } while (i == BUFSIZE - 1);
}
