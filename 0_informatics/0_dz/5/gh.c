#include <stdio.h>
#include <math.h>



float f1(float a, float b, float c) {
    return a * b *c;
}

float f2(float d) {
    return pow(d, 0.5);
}

void f3(float e) {
    printf("%6.3f\n", e);
}



int main() {

    f1(2, 4, 3);



    return 0;
}
