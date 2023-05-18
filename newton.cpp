#include <iomanip>
#include "newton.hpp"
void NewtonMethodAnalitic(double x, double y){
    int count = 0;
    double eps = utils::eps();
    double f1 = utils::f1(x, y);
    double f2 = utils::f2(x, y);


    vector<vector<double>> matrixJacobian1 = utils::Jacobian1(x, y);
    double a = matrixJacobian1[0][0];
    double b = matrixJacobian1[0][1];
    double c = matrixJacobian1[1][0];
    double d = matrixJacobian1[1][1];
    double determinant = a*d - b*c;


    double x_n_1 = x - ((d*f1 - b*f2)/determinant);
    double y_n_1 = y - ((a*f2 - c*f1)/determinant);

    while(abs(x_n_1 - x) >= eps || abs(y_n_1 - y) >= eps){
        x = x_n_1;
        y = y_n_1;

        matrixJacobian1 = utils::Jacobian1(x, y);
        a = matrixJacobian1[0][0];
        b = matrixJacobian1[0][1];
        c = matrixJacobian1[1][0];
        d = matrixJacobian1[1][1];

        f1 = utils::f1(x, y);
        f2 = utils::f2(x, y);
        determinant = a*d - b*c;

        x_n_1 = x - ((d*f1 - b*f2)/determinant);
        y_n_1 = y - ((a*f2 - c*f1)/determinant);
        count++;
    }
    cout <<"NewtonMethodAnalitic"<<endl;
    cout << "x: " << std::fixed << std::setprecision(6) << x_n_1 << endl;
    cout << "y: " << std::fixed << std::setprecision(6) << y_n_1 << endl;
    cout << "count: " << count << endl;
}


void NewtonMethodNumeric(double x, double y) {
    int count = 0;
    double eps = utils::eps();
    double f1 = utils::f1(x, y);
    double f2 = utils::f2(x, y);

    double h = 0.001;
    vector<vector<double>> matrixJacobian2 = utils::Jacobian2(x, y, h);
    double a = matrixJacobian2[0][0];
    double b = matrixJacobian2[0][1];
    double c = matrixJacobian2[1][0];
    double d = matrixJacobian2[1][1];
    double determinant = a*d - b*c;

    double x_n_1 = x - ((d*f1 - b*f2)/determinant);
    double y_n_1 = y - ((a*f2 - c*f1)/determinant);
    while(abs(x_n_1 - x) >= eps || abs(y_n_1 - y) >= eps){
        x = x_n_1;
        y = y_n_1;

        matrixJacobian2 = utils::Jacobian2(x, y, h);
        a = matrixJacobian2[0][0];
        b = matrixJacobian2[0][1];
        c = matrixJacobian2[1][0];
        d = matrixJacobian2[1][1];

        f1 = utils::f1(x, y);
        f2 = utils::f2(x, y);
        determinant = a*d - b*c;

        x_n_1 = x - ((d*f1 - b*f2)/determinant);
        y_n_1 = y - ((a*f2 - c*f1)/determinant);
        count++;
    }
    cout << "NewtonMethodNumeric"<< endl;
    cout << "x: " << std::fixed << std::setprecision(6) << x_n_1 << endl;
    cout << "y: " << std::fixed << std::setprecision(6) << y_n_1 << endl;
    cout << "count: " << count << endl;

}
