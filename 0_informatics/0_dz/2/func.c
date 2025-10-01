#include <stdio.h>
#include <locale.h>
#include <wchar.h>



// double log( double arg );
// double pow( double base, double exponent );
// double sqrt( double arg );
// double sin( double arg );
// double cos( double arg );
// double tan( double arg );
// double asin( double arg );
// double acos( double arg );
// double atan( double arg );
// double atan2( double y, double x ); // Computes the arc tangent of y / x using the signs of arguments to determine the correct quadrant.
// double ceil( double arg ); // computes smallest integer not less than the given value 
// double floor( double arg ); // computes largest integer not greater than the given value 
// double trunc( double arg ); // rounds to nearest integer not greater in magnitude than the given value 
// double round( double arg ); // rounds to nearest integer, rounding away from zero in halfway cases 
// double fabs( double arg ); //  computes absolute value of a floating-point value (|x|) 
// double fmod( double x, double y ); // computes remainder of the floating-point division operation 




int main() {

    setlocale(LC_ALL, "ru_RU.UTF-8");


    wchar_t c;
    wscanf(L"%ls", &c);
    wprintf(L"%ls\n", c);

    return 0;
}
