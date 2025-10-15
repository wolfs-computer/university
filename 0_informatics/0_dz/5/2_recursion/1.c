#include <stdio.h>
#include <math.h>



double RootK(double x, int k, int n) {
    // x -- numer
    // k -- power
    // n -- number of iterations left

    if (n == 0) {
        return 1;
    } else {
        return (RootK(x, k, n - 1) - (RootK(x, k, n - 1) - x / pow(RootK(x, k, n - 1), k - 1)) / k);
    }
}




int main() {
    // printf causes rounding! (actually there is more precision in double)

    // calc -- 2.2360679775
    // 1 -- 3.0000000000
    // 2 -- 2.3333333333
    // 3 -- 2.2380952381
    // 4 -- 2.2360688956
    // 5 -- 2.2360679775
    // 6 -- 2.2360679775
    printf("%.10lf\n", RootK(5, 2, 1));
    printf("%.10lf\n", RootK(5, 2, 2));
    printf("%.10lf\n", RootK(5, 2, 3));
    printf("%.10lf\n", RootK(5, 2, 4));
    printf("%.10lf\n", RootK(5, 2, 5));
    printf("%.10lf\n", RootK(5, 2, 6));

    // // calc -- 1.41421356237
    // // 3 -- 1.4142156863
    // // 10 -- 1.4142135624
    // printf("%.10lf\n", RootK(2, 2, 3));

    // // calc -- 1.44224957031
    // // 3 -- 1.4428120982
    // // 10 -- 1.4422495703
    // printf("%.10lf\n", RootK(3, 3, 3));


    return 0;
}
