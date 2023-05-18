#include "utils.hpp"

using namespace std;
namespace utils {


    double eps() {
        return pow(10, -5);
    }

    double x() {
        return -1.7;
    }

    double y() {
        return -0.9;
    }

    double f1(double x, double y) {
        return ::sin(x - 2.2 * y) - x * y + 1.0;
    }


    double f2(double x, double y) {
        return (x * x) / 1.75 - (y * y) - 0.75;
    }

    double df1_dx(double x, double y) {
        return cos(x - 2.2 * y) - y;
    }

    double df1_dy(double x, double y) {
        return -2.2 * cos(x - 2.2 * y) - x;
    }

    double df2_dx(double x, double y) {
        return 2.0 * x / 1.75;
    }

    double df2_dy(double x, double y) {
        return -2.0 * y;
    }


    vector<vector<double>> Jacobian1(double x, double y) {
        double j11 = df1_dx(x, y);
        double j12 = df1_dy(x, y);
        double j21 = df2_dx(x, y);
        double j22 = df2_dy(x, y);
        vector<vector<double>> matrixJacobian1 = {{j11, j12},
                                                  {j21, j22}};

        return matrixJacobian1;
    }

    vector<vector<double>> Jacobian2(double x, double y, double h) {
        double j11 = (f1(x + h, y) - f1(x, y))/h;
        double j12 = (f1(x, y + h) - f1(x, y))/h;
        double j21 = (f2(x + h, y) - f2(x, y))/h;
        double j22 = (f2(x, y + h) - f2(x, y))/h;
        vector<vector<double>> matrixJacobian2 = {{j11, j12},
                                                 {j21, j22}};
        return matrixJacobian2;
    }
};

