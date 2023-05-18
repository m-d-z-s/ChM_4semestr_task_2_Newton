#ifndef TASK_2_UTILS_HPP
#define TASK_2_UTILS_HPP
#include <iostream>
#include <cmath>
#include <vector>
using namespace std;

namespace utils{
    double eps();
    double x();
    double y();
    double f1(double x, double y);
    double f2(double x, double y);
    double df1_dx(double x, double y);
    double df1_dy(double x, double y);
    double df2_dx(double x, double y);
    double df2_dy(double x, double y);
    vector<vector<double>> Jacobian1(double x, double y);
    vector<vector<double>> Jacobian2(double x, double y, double h);
}

#endif //TASK_2_UTILS_HPP
