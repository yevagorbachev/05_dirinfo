#include<stdio.h>
#include<stdlib.h>

#include<fcntl.h>
#include<dirent.h>
#include<sys/stat.h>
#include<sys/types.h>

#include<errno.h>
#include<string.h>
#include<time.h>

void print_metric(long num) {
    char * prefs[5] = {"B","KB","MB","GB","TB"};
    int i;
    for (i = 0; i < 5, num >= 1000; i++, num /= 1000) {}
    printf("%ld %s\n", num, prefs[i]);
}



int main() {
    
}