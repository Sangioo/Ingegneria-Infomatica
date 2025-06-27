#include <dirent.h>
#include <stdio.h>
#include <string.h>

int main(int argc, char* argv[]){
    if (argc<3){
        printf("usage: %s dirname name\n", argv[0]);
        return -1;
    }
    int found=0;
    DIR* dirp = opendir(argv[1]);
    if (dirp == NULL) return -1;
    struct dirent * dp;
    while((dp=readdir(dirp)) != NULL){
        if (strcmp(dp->d_name, argv[2]) == 0){
            found=1;
            break;
        }
    }
    printf("%s\n", found ? "trovato" : "non trovato");
    closedir(dirp);
    return 0;
}