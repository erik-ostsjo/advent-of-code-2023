#include <stdio.h>
#include <string.h>

void assign_values(char *first, char *last, char value) {
    *last = value;
    if(!*first) {
        *first = *last;
    }
}

int main(int argc, char **argv) {
    FILE *file =  fopen(argv[1], "r");
    if (file == NULL) return -1;

    char word_positions[9] = {0};
    char *word_numbers[9] = {
    "one",
    "two",
    "three",
    "four",
    "five",
    "six",
    "seven",
    "eight",
    "nine",
    };

    char character, first, last;
    int sum = 0;
    while((character = fgetc(file)) != EOF) {
        if (character == '\n') {
            sum += (10*first) + last;
            memset(word_positions, 0, sizeof word_positions);
            first = 0;
        }
        else if (character > 47 && character < 58) { // is a number
            assign_values(&first, &last, (character - 48));
            memset(word_positions, 0, sizeof word_positions);
        }
        else if (character > 96 && character < 123) {
            for(int i = 0; i < 9; ++i) {
                if(character == word_numbers[i][word_positions[i]]) {
                    if(word_numbers[i][++word_positions[i]] == '\0') {
                        word_positions[i] = 0;
                        assign_values(&first, &last, i+1);
                    }
                }
                else word_positions[i] = character == word_numbers[i][0] ? 1 : 0;
            }            
        }
    }
    fclose(file);
    printf("Sum: %d\n", sum);
}
