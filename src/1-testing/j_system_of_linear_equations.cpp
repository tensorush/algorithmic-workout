#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

constexpr double DEFAULT_EPSILON = 1e-5;


enum SolutionType {
    NoSolution = 0,
    InfinitelyManySolutions_Linear = 1,
    SingleSolution = 2,
    InfinitelyManySolutions_AnyX = 3,
    InfinitelyManySolutions_AnyY = 4,
    InfinitelyManySolutions_AnyXYPair = 5
};

auto Solve2x2SystemOfLinearEquations(double a, double b, double c, double d, double e, double f, const double& EPS = DEFAULT_EPSILON) {
    vector<double> solution;
    double determinant = a * d - b * c;
    if (abs(determinant) < EPS) {
        if (abs(a) < EPS && abs(c) < EPS) {
            if (abs(b) < EPS && abs(d) < EPS) {
                if (abs(e) < EPS && abs(f) < EPS)
                    return make_pair(InfinitelyManySolutions_AnyXYPair, solution);
                else
                    return make_pair(NoSolution, solution);
            } else if (e * d == f * b) {
                (abs(b) < EPS) ? (solution.emplace_back(f / d)) : (solution.emplace_back(e / b));
                return make_pair(InfinitelyManySolutions_AnyY, solution);
            } else {
                return make_pair(NoSolution, solution);
            }
        } else {
            if (abs(b) < EPS && abs(d) < EPS) {
                if (abs(e * c - f * a) < EPS) {
                    (abs(a) < EPS) ? (solution.emplace_back(f / c)) : (solution.emplace_back(e / a));
                    return make_pair(InfinitelyManySolutions_AnyX, solution);
                } else {
                    return make_pair(NoSolution, solution);
                }
            } else if (abs(a) < EPS) {
                b -= a / c * d;
                e -= a / c * f;
                if (abs(b) < EPS && abs(e) < EPS) {
                    solution.emplace_back(-c / d);
                    solution.emplace_back(f / d);
                    return make_pair(InfinitelyManySolutions_Linear, solution);
                }
            } else {
                d -= c / a * b;
                f -= c / a * e;
                if (abs(d) < EPS && abs(f) < EPS) {
                    solution.emplace_back(-a / b);
                    solution.emplace_back(e / b);
                    return make_pair(InfinitelyManySolutions_Linear, solution);
                }
            }
            return make_pair(NoSolution, solution);
        }
    } else {
        double x, y;
        if (abs(d) < EPS)
            x = (f - d * e / b) / (c - d * a / b), y = (e - a * x) / b;
        else
            x = (e - b * f / d) / (a - b * c / d), y = (f - c * x) / d;
        solution.emplace_back(x);
        solution.emplace_back(y);
        return make_pair(SingleSolution, solution);
    }
}


int main() {
    double a, b, c, d, e, f;
    cin >> a >> b >> c >> d >> e >> f;

    auto [solutionType, solution] = Solve2x2SystemOfLinearEquations(a, b, c, d, e, f);
    cout << solutionType << ' ';
    for (const double& constant : solution) {
        cout << constant << ' ';
    }
    cout << endl;

    return EXIT_SUCCESS;
}