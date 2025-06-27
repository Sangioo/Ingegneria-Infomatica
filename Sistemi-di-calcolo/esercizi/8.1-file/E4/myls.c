#include <dirent.h>
#include <stdio.h>
#include <string.h>

int main(int argc, char* argv[]){
    if (argc<2){
        printf("usage: %s dirname\n", argv[0]);
        return -1;
    }
    
    DIR* dirp = opendir(argv[1]);
    if (dirp == NULL) return -1;
    struct dirent * dp;
    while((dp=readdir(dirp)) != NULL){
        printf("%s\n", dp->d_name);
    }
    closedir(dirp);
    return 0;
}