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

void myls(char * path) {
    DIR * stream = opendir(path);
    struct dirent * head;
    struct node * dirs = NULL;
    struct node * files = NULL;
    int size = 0;

    while ((head = readdir(stream)) != NULL) {
        int status = isfile(head->d_name);
        if (status == 0) {
            dirs = insert_front(dirs, head->d_name);
        } else {
            files = insert_front(files, head->d_name);
            size += status;
        }
    }
    printf("Total size of regular files: %d\n", size);
    printf("Directories:\n");
    print_list(dirs);
    printf("Regular files:\n");
    print_list(files);

    free_list(dirs);
    free_list(files);
}

int main(int argc, char * argv[]) {
    if (argc == 1) {
        myls(".");
    } else {
        myls(argv[1]);
    }
}