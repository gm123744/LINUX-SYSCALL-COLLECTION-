#define X86_64_LINUX 1
#include "lsc.h"

int main() {
    //write 1st side of hello world
    lsc_write hello; //call write struct 
    hello.wtype = WRITE_STDOUT; //specify stdout type
    hello.dataptr = "Hello,"; //data pointer to string
    hello.datalen = 6;  //length of string
    lsc_stdout(&hello); //call lsc_stdout function with pointer to struct

    //second side of hello world
    lsc_write world;
    world.wtype = WRITE_STDOUT;
    world.dataptr = "world\n";
    world.datalen = 6;  
    lsc_stdout(&world);
    return 0;
}
//compile and link with:
//gcc -nostartfiles -nodefaultlibs helloworld.c lsc.s -o hello -Wa,--no-warn
