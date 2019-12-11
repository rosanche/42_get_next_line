#include "get_next_line.h"

int main()
{
    char *line;

    printf("result: %d\nlign: %s\n", get_next_line(42, &line), line);
    printf("result: %d\nlign: %s\n", get_next_line(1, &line), line);
}