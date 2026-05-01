#include "read_cones.h"
#include <stdio.h>

int main()
{
    Cones c = {};

    const size_t test_count = 5;
    int tests[test_count];
    int expected_return_values[test_count];
    size_t ti = 0;
    
    tests[ti] = read_cones(&c, "tests/cone_files/cones1_good.csv");
    expected_return_values[ti++] = 0;
    tests[ti] = read_cones(&c, "tests/cone_files/cones_NO_FILE.csv");
    expected_return_values[ti++] = 1;
    tests[ti] = read_cones(&c, "tests/cone_files/cones2_empty.csv");
    expected_return_values[ti++] = 2;
    tests[ti] = read_cones(&c, "tests/cone_files/cones3_less_lines.csv");
    expected_return_values[ti++] = 3;
    tests[ti] = read_cones(&c, "tests/cone_files/cones4_no_separator.csv");
    expected_return_values[ti++] = 4;
    
    for (size_t i = 0; i < test_count; i++)
    {
        printf("Test %zu: ", i+1);
        if (tests[i] == expected_return_values[i])
            printf("OK!\n");
        else
            printf("FAILED! return code: %d\n", tests[i]);
    }

    return 0;
}