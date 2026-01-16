/*
 * LSC i/o Example
 *
 * Copyright (C) 2026 gm123744
 * SPDX-License-Identifier: GPL-2.0-only
 *
 * Description:
 *   This program demonstrates how to take input and output from the 
 *   terminal using LSC (Linux Syscall Collection), a minimal syscall wrapper.
 *
 * Key Features:
 *   - Works without libc or standard libraries
 * Usage:
 *   gcc -nostartfiles -nodefaultlibs helloworld.c lsc.s -o hello
 *
 * Output:
 *   Enter something: 
 *
 * Notes:
 *   - Both lsc.h and lsc.s must be in the build directory
 *   - This example uses the struct-based interface
 *     (see stdin_read for a simpler shortcut)
 */
#define X86_64_LINUX 1 //specify backend target
#include "lsc.h"

int main(void) {
    //prompt user for input
    lsc_write enter;
    enter.wtype = WRITE_STDOUT;
    enter.dataptr = "Enter something: ";
    enter.datalen = 17;
    lsc_stdout(&enter);
/*-----------------------------------------------------------*/
    char iobuffer[64]; //create a buffer with 64 bytes len 
    lsc_read input; // create read struct
    input.rtype = READ_STDIN; //specify read from stdin
    input.dataptr = iobuffer; //point to buffer
    input.datalen = 64; //specify length to read
    lsc_stdin(&input); //call lsc_stdin with pointer to struct
    return 0; 
}
