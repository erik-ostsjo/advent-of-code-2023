#include <stdio.h>
#include <string.h>

int get_line(FILE* file, char line[]) {
    int c;
    int i = 0;
    line[0] = '\0';
    while((c=fgetc(file)) != EOF) {
        if(c == '\n') {
            line[i] = '\0';
            return i;
        }
        line[i++] = c;
    }
    if(i > 0){
        line[i+1] = '\0';
    }
    return 0;
}

int main(int argc, char** argv) {
    FILE *fp = fopen("input.txt", "r");
    unsigned int max[] = {12, 14, 13}; // input
    
    int game[100][3] = {0};
    char line[256];
    char color[6]; // green\0

    unsigned int amount, id, len, position, n, color_index;
    while(len = get_line(fp, line)) {
        position = 7 + sscanf(line, "Game %u", &id); // add value so we can use offset
        while(position < len) {
            sscanf(line + position, "%u %[^,;]%n", &amount, color, &n);
            color_index = strlen(color) - 3;
            if (game[id-1][color_index] < amount) game[id-1][color_index] = amount;
            position += (n + 2);
            
        }
    }
    fclose(fp);
    unsigned int id_sum = 0;
    unsigned int power_sum = 0;
    for(int i = 0; i<100; ++i) {
        if(game[i][0] == 0 && game[i][1] == 0 && game[i][2] == 0) {
            continue;
        }
        if(game[i][0] <= max[0] && game[i][2] <= max[2] && game[i][1] <= max[1]) {
            id_sum += i+1;
        }
        power_sum += game[i][0] * game[i][1] * game[i][2];
    }
    printf("Part 1 Sum : %u\n", id_sum);
    printf("Part 2 Sum : %u\n", power_sum);
}
