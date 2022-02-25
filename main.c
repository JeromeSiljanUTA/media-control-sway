#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char *argv[]){
    char buff[255];
    char prev_buff[255];

    FILE * raw_players = popen("playerctl metadata -a", "r");

    int comp;
    char *token;
    int player_arr_size = 0;
    static int player_arr_index = 0;
    char prev_token[255];
    char stable_token[255];
    char **players = malloc(sizeof(char*) * player_arr_size);

    while(comp != 0){
        fgets(buff, 255, raw_players);
        comp = strcmp(prev_buff, buff); 
        strcpy(prev_buff, buff);
        strcpy(prev_token, stable_token);
        token = strtok(buff, " ");
        strcpy(stable_token, token);
        
        if(strcmp(prev_token, stable_token) != 0){
            player_arr_size++;
            players = realloc(players, sizeof(char*) * player_arr_size);
            players[player_arr_index] = malloc(sizeof(char*) * 255);
            strcpy(players[player_arr_index], token);
            player_arr_index++;
        }
    }
    fclose(raw_players);

    FILE * focused_window = popen("swaymsg -t get_tree | jq '.. | select(.type?) | select(.focused==true).app_id' | cut -b 2- | rev | cut -b 2- | rev", "r");
    fgets(buff, 255, focused_window);

    buff[strlen(buff) - 1] = '\0';
    char selected[255];
    strcpy(selected, "cmus");

    if(strcmp(buff, "mpv") == 0){
        strcpy(selected, buff);
    }
    else if(strcmp(buff, "firefox") == 0){
        for(int i = 0; i < player_arr_size; i++){
            if(strcmp(players[i], "firefox") == 0){
                strcpy(selected, buff);
            }
        }
    }
    else if(strcmp(buff, "spotify") == 0){
        strcpy(selected, buff);
    }

    char command[255];

    strcpy(command, "playerctl ");
    strcat(command, argv[1]);
    strcat(command, " -p ");

    system(strcat(command, selected));

    for(int i = 0; i < player_arr_size; i++){
        free(&players[i]);
    }

    return 0;
}
