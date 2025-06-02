#include <stdio.h>
#include <stdlib.h>

int *findCoordinates(name)
{

    FILE *file = fopen(name, "r");
    int s;
    // x and y of the file
    int curr_row = 1, curr_column = 1;

    // array of lengths of the platforms
    int length = 0, i = 0, lengths_count = 0, capacity = 10;
    int *lengths = (int *)malloc(sizeof(int) * capacity);

    while ((s = fgetc(file)) != EOF)
    {
        if (s == '#')
            length++;

        else
        {
            if (length > 0)
            {
                if (lengths_count == capacity)
                {
                    capacity *= 2;
                    lengths = realloc(lengths, sizeof(int) * capacity);
                }
                lengths[lengths_count++] = length;
                length = 0;
            }

            if (s == '\n')
            {
                curr_row++;
                curr_column = 1;
                continue;
            }
        }

        curr_column++;
    }

    if (length > 0)
    {
        if (lengths_count == capacity)
        {
            capacity *= 2;
            lengths = realloc(lengths, sizeof(int) * capacity);
        }
        lengths[lengths_count++] = length;
    }

    fclose(file);

    return lengths;
}

int findEdgesWeight() {}

int main()
{
    char *fileName = "map.txt";
    int *lengths;

    lengths = findCoordinates(fileName);
}