#include<stdio.h>
#include<stdlib.h>

#include<fcntl.h>
#include<unistd.h>
#include<dirent.h>
#include<sys/stat.h>
#include<sys/types.h>

#include<errno.h>
#include<string.h>
#include<time.h>

#include "llist.h"

void print_metric(long num) {
    char * prefs[5] = {"B","KB","MB","GB","TB"};
    int i;
    for (i = 0; i < 5, num >= 1000; i++, num /= 1000) {}
    printf("%ld %s\n", num, prefs[i]);
}

int isfile(char * path) {
    struct stat meta;
    if (stat(path, &meta) < 0) {
        printf("Error #%d when checking metadata of %s: %s\n", errno, path, strerror(errno));
    }
    if (meta.st_mode > 041000) {
        return meta.st_size;
    } else {
        return 0;
    }
}



int main() {
    struct dirent * stream = opendir('.');
}