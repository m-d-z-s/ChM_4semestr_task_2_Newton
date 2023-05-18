#include "newton.hpp"
#include "utils.hpp"

int main() {
    cout << "First: " << endl;
    NewtonMethodAnalitic(-1.55, -0.8);
    NewtonMethodNumeric(-1.55, -0.8);
    cout << endl;
    cout << "Second: " << endl;
    NewtonMethodAnalitic(1.5, 0.72);
    NewtonMethodNumeric(1.5, 0.72);
    return 0;
}
//First:
//x_1 = 1.449431098059804
//y_1 = 0.6711825419246875
//Second:
//x_2 = -1.512853797049754
//y_2 = -0.7468894013546573
//http://mrexam.ru/systemofequations?solve_1=sin(x-2.2*y)-x*y%2B1%3D0&solve_2=x*x%2F1.75-y*y-0.75%3D0&x=x&x1=-20&x2=20&y=y&y1=-20&y2=20