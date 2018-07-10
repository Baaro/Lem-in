#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
#include <stdlib.h>

int main(int argc, char **argv)
{
    char *bf;
    read(0, bf, 4);
    printf("%s\n", bf);
    return (0);
}