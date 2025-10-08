#include <stdio.h>
#include <math.h>



int main() {

    double alpha;
    scanf("%lf", &alpha);

    double y1 = 2 * pow(sin(3 * M_PI - 2 * alpha), 2) * pow(cos(5 * M_PI + 2 * alpha), 2);
    printf("%lf\n", y1);
    double y2 = 1 - ((double)1 / 4) * pow(sin(2 * alpha), 2) + cos(2 * alpha);
    printf("%lf\n", y2);
    double y3 = ((double)1 / 4) - ((double)1 / 4) * sin(((double)5 / 8) * M_PI - 8 * alpha);
    printf("%lf\n", y3);
    double y4 = pow(cos(alpha), 2) * pow(cos(alpha), 4);
    printf("%lf\n", y4);



    return 0;
}
