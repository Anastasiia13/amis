#include <stdio.h>
#include <conio.h>
#include <string.h>
#include <stdlib.h>
#include "playlist_validation.h"

int validate_playlist (char playlist_path[200]) {
    FILE *playlist_file;
    char buff[200];
    int songs_counter=0;

    playlist_file=fopen(playlist_path,"r");

    if (playlist_file==NULL)
        return 0;

    while (!feof(playlist_file)) {
        fgets(buff, 200, playlist_file);
        songs_counter++;
    }
    fclose(playlist_file);
    return songs_counter;
}
