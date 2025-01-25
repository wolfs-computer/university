#include <stdio.h>
#include <stdlib.h>
#include "status.h"
#include "data_io.h"
#include "opt_parser.h"
#include "status.h"



/*
// h -- display this help message

// i -- input method (std, txt, bin)
// o -- output method (std, txt, bin)

// a -- algorithm (1, 2, 3)
// f -- fields of the structure (1, 2, 3) plain string (32)
// d -- sort direction (-, +)
*/


/*
- get arguments with getopt()
- check if input data is correct, if not - just continue
    all arguments data is correct (default if not)
    input file exists (if not -> std input method)

- if specific struct have wrong format just skip it
    specific field error (3 or 11 symbols where should be 8) (pretend there is no such struct)

- format error
    number of fields is wrong (lines - 1)/3 % == 0
    too much/little structs


same file at input and output

sorts work like qsort
comparator
*/


void DEBUG_opts(Opt_data opts) {
    printf("input source -- %d\n", opts.input);
    printf("input filename -- %s\n\n", opts.input_filename);

    printf("output source -- %d\n", opts.output);
    printf("output filename -- %s\n", opts.output_filename);

    printf("algorithm -- %d\n", opts.algorithm);
    printf("struct field -- %d\n", opts.field);
    printf("sort direction -- %s\n", opts.direction == 0 ? "UP" : "DOWN");
}



void DEBUG_data() {

    Data a = {
        "7777777",
        "random random!",
        772
    };

    Data b = {
        "0110101",
        "S T R I N G",
        1
    };

    Data l1[] = {a, b};
    int l1_len = 2;

    // data_write_text("./tests/2_text", l1, l1_len);
    // data_write_bin("./tests/2_bin", l1, l1_len);


    // Data *data = NULL;
    // int data_len = 0;
    //
    // data_read_text("./tests/2_text", &data, &data_len);
    //
    // data_write_std(data, data_len);


    Data *data = NULL;
    int data_len = 0;

    data_read_std(&data, &data_len);
    data_write_std(data, data_len);



    // write_data_text("1test", list, 2);
    //
    // int data_len = 0;
    // Data *l = NULL;
    // read_data_text("1test", &l, &data_len);
    //
    // for (int i = 0; i < data_len; i++) {
    //     printf("%s\n", l[i].str);
    //     printf("%s\n", l[i].name);
    //     printf("%d\n", l[i].quantity);
    //     free(l[i].name);
    // }
    // free(l);


    // write_data_bin("2test", list, 2);
    //
    // int data_len = 0;
    // Data *l = NULL;
    // read_data_bin("2test", &l, &data_len);
    //

    for (int i = 0; i < data_len; i++) {
        free(data[i].name);
    }
    free(data);
}



int main(int argc, char **argv) {


    // default args
    Opt_data opts = {
        .input = FLOW_STD,
        .output = FLOW_STD,

        .input_filename = NULL,
        .output_filename = NULL,

        .algorithm = ALGO_NO,
        .field = 0,
        .direction = UP,
    };

    parse_opts(argc, argv, &opts);



    // input
    // output
    // algo



    // DEBUG
    DEBUG_opts(opts);


    // DEBUG_data();



    return 0;
}
