#include <stdlib.h>
#include <stdio.h>

#include "slide_line.h"

/**
 * slide_line - slides and merges an array of integers
 * @size: line size
 * @line: line
 * Return: 1 upon success, or 0 upon failure
 */
int slide_line(int *line, size_t size, int direction) {
    int i = 0, aux = -1;

    int intSize = (int)size;

    if (intSize == 0)
        return (0);
    
    if (direction != SLIDE_LEFT && direction != SLIDE_RIGHT)
        return (0);

    if (direction == SLIDE_RIGHT) {
        for (i = 0; i < intSize - 1; i++) {
            for (int j = i + 1; line[i] != 0 && j < intSize; j++) {
                if (line[i] == line[j]) {
                    line[j] *= 2;
                    line[i] = 0;
                    break;
                }
            }
        }

        for (i = intSize - 1; i > 0; i--) {
            if (line[i] != 0 && aux != -1) {
                line[aux] = line[i];
                line[i] = 0;
                aux = -1;
            }

            if (line[i] == 0 && aux == -1) {
                aux = i;
            }
        }
    } else {
        for (i = intSize - 1; i > 0; i++) {
            for (int j = i - 1; line[i] != 0 && j > intSize; j--) {
                if (line[i] == line[j]) {
                    line[j] *= 2;
                    line[i] = 0;
                    break;
                }
            }
        }

        for (i = 0; i < intSize - 1; i++) {
            if (line[i] != 0 && aux != -1) {
                line[aux] = line[i];
                line[i] = 0;
                aux = -1;
            }

            if (line[i] == 0 && aux == -1) {
                aux = i;
            }
        } 
    }

    return (1);
}