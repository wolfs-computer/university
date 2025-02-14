#include <stdio.h>
#include <stdlib.h>
// #include "status.h"
#include "data_io.h"
#include "timer_opt_parser.h"


// 10-20 points on graphs



int main(int argc, char **argv) {

    // default args
    Opt_data opts = {
        .algorithm = ALGO_NO,
        .field = 0,
        .direction = UP,

        .element_count = 1,
        .count = 1,
    };

    parse_opts(argc, argv, &opts);


    return 0;
}
