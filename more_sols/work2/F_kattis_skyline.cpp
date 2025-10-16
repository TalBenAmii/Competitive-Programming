#include <bits/stdc++.h>


using namespace std;

#define EPS 1e-9

struct point {
    double x, y;   // only used if more precision is needed
    point() { x = y = 0.0; }                      // default constructor
    point(double _x, double _y) : x(_x), y(_y) {}        // user-defined
    bool operator<(point other) const { // override less than operator
        if (fabs(x - other.x) > EPS)                 // useful for sorting
            return x < other.x;          // first criteria , by x-coordinate
        return y < other.y;
    }          // second criteria, by y-coordinate
    // use EPS (1e-9) when testing equality of two floating points
    bool operator==(point other) const {
        return (fabs(x - other.x) < EPS && (fabs(y - other.y) < EPS));
    }
};


struct line {
    double a, b, c;
};          // a way to represent a line

// the answer is stored in the third parameter (pass by reference)
void pointsToLine(point p1, point p2, line& l) {
    if (fabs(p1.x - p2.x) < EPS) {              // vertical line is fine
        l.a = 1.0;
        l.b = 0.0;
        l.c = -p1.x;           // default values
    } else {
        l.a = -(double) (p1.y - p2.y) / (p1.x - p2.x);
        l.b = 1.0;              // IMPORTANT: we fix the value of b to 1.0
        l.c = -(double) (l.a * p1.x) - p1.y;
    }
}

bool areParallel(line l1, line l2) {       // check coefficients a & b
    return (fabs(l1.a - l2.a) < EPS) && (fabs(l1.b - l2.b) < EPS);
}

// returns true (+ intersection point) if two lines are intersect
bool areIntersect(line l1, line l2, point& p) {
    if (areParallel(l1, l2)) return false;            // no intersection
    // solve system of 2 linear algebraic equations with 2 unknowns
    p.x = (l2.b * l1.c - l1.b * l2.c) / (l2.a * l1.b - l1.a * l2.b);
    // special case: test for vertical line to avoid division by zero
    if (fabs(l1.b) > EPS) p.y = -(l1.a * p.x + l1.c);
    else p.y = -(l2.a * p.x + l2.c);
    return true;
}

double calcArea(const point& p1, const point& p2) {
    return 0.5 * (p1.y + p2.y) * fabs(p1.x - p2.x);
}

double calcY(const point& p1, const point& p2, double x) {
    return (x - p1.x) / (p2.x - p1.x) * (p2.y - p1.y) + p1.y;
}

struct Building {
    point p1, p2;
};


int main() {
    int n;
    cin >> n;
    set<double> xSet;
    vector<Building> buildings;
    for (int i = 0; i < n; ++i) {
        point p1, p2;
        cin >> p1.x >> p1.y >> p2.x >> p2.y;
        xSet.emplace(p1.x);
        xSet.emplace(p2.x);

        // insert intersections
        line currLine{};
        pointsToLine(p1, p2, currLine);
        for (auto b : buildings) {
            point p{};
            line nextLine{};
            pointsToLine(b.p1, b.p2, nextLine);
            if (areIntersect(currLine, nextLine, p)) {
                xSet.emplace(p.x);
            }
        }
        buildings.push_back({p1, p2});
    }

    map<double, double> maxLeftY, maxRightY;
    for (auto b : buildings) {
        double allArea = calcArea(b.p1, b.p2);
        double visibleArea = 0;

        for (auto it = xSet.find(b.p1.x), end = xSet.find(b.p2.x); it != end; ++it) {
            double currX = *it, nextX = *next(it);
            double currY = calcY(b.p1, b.p2, currX), nextY = calcY(b.p1, b.p2, nextX);
            if (currY + EPS >= maxRightY[currX] && nextY + EPS >= maxLeftY[nextX]) {
                visibleArea += calcArea({currX, currY}, {nextX, nextY}) -
                               calcArea({currX, maxRightY[currX]}, {nextX, maxLeftY[nextX]});
                maxRightY[currX] = currY;
                maxLeftY[nextX] = nextY;
            }
        }

        cout << visibleArea / allArea << endl;
    }
    return 0;
}