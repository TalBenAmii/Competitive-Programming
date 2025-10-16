#include <bits/stdc++.h>
using namespace std;
#define fastio()                      \
    ios_base::sync_with_stdio(false); \
    cin.tie(nullptr);                 \
    cout.tie(nullptr)
#define fixed(n) fixed << setprecision(n)
#define ceil(n, m) (((n) + (m) - 1) / (m))
#define add_mod(a, b, m) (((a % m) + (b % m)) % m)
#define sub_mod(a, b, m) (((a % m) - (b % m) + m) % m)
#define mul_mod(a, b, m) (((a % m) * (b % m)) % m)
#define all(vec) vec.begin(), vec.end()
#define rall(vec) vec.rbegin(), vec.rend()
#define sz(x) int(x.size())
#define ff first
#define ss second

typedef long long ll;
typedef unsigned long long ull;
typedef long double lld;
typedef pair<int, int> ii;
typedef pair<ll, ll> pll;
typedef pair<int, ii> iii;

typedef vector<int> vi;
typedef vector<ll> vll;
typedef vector<ii> vii;
typedef vector<vii> vvii;
typedef vector<vi> vvi;
typedef vector<pll> vpll;
typedef vector<vpll> vvpll;

typedef set<int> si;
typedef vector<si> vsi;
typedef unordered_map<int, int> umii;

#define debug(x) cout << #x << ": " << (x) << "\n";
#define PI acos(-1)
#define INF 1e9
#define INF_LL 1e18
#define EPS 1e-9

template <typename T = int>
istream &operator>>(istream &in, vector<T> &v)
{
    for (auto &x : v)
        in >> x;
    return in;
}

template <typename T1 = int, typename T2 = int>
istream &operator>>(istream &in, vector<pair<T1, T2>> &v)
{
    for (auto &x : v)
        in >> x.first >> x.second;
    return in;
}

template <typename T = int>
ostream &operator<<(ostream &out, const vector<T> &v)
{
    for (const T &x : v)
        out << x << ' ';
    return out;
}

template <typename T1 = int, typename T2 = int>
ostream &operator<<(ostream &out, const vector<pair<T1, T2>> &v)
{
    for (const auto &x : v)
        out << '(' << x.first << ", " << x.second << ") ";
    return out;
}

//-----------------------------------------------------------------------------------------------------------//-----------------------------------------------------------------------------------------------------------
struct point
{
    double x, y;                                  // only used if more precision is needed
    point() { x = y = 0.0; }                      // default constructor
    point(double _x, double _y) : x(_x), y(_y) {} // user-defined
    bool operator<(point other) const
    {                                // override less than operator
        if (fabs(x - other.x) > EPS) // useful for sorting
            return x < other.x;      // first criteria , by x-coordinate
        return y < other.y;
    } // second criteria, by y-coordinate
    // use EPS (1e-9) when testing equality of two floating points
    bool operator==(point other) const
    {
        return (fabs(x - other.x) < EPS && (fabs(y - other.y) < EPS));
    }
};
struct vec
{
    double x, y; // name: `vec' is different from STL vector
    vec(double _x, double _y) : x(_x), y(_y) {}
};

vec toVec(point a, point b)
{ // convert 2 points to vector a->b
    return vec(b.x - a.x, b.y - a.y);
}

double cross(vec a, vec b) { return a.x * b.y - a.y * b.x; }
bool ccw(point p, point q, point r)
{
    return cross(toVec(p, q), toVec(p, r)) > 0;
}

vector<point> convex_hull(vector<point> Points)
{

    //-------------- incremental alg. ---------
    // upper hull
    sort(Points.begin(), Points.end());
    stack<point> stk_up;
    stk_up.push(Points[0]);
    stk_up.push(Points[1]);
    for (int i = 2; i < Points.size(); i++)
    {
        while ((stk_up.size() >= 2))
        {
            point p2, p3;
            p2 = stk_up.top();
            stk_up.pop();
            p3 = stk_up.top();
            if (ccw(Points[i], p2, p3))
            {
                stk_up.push(p2);
                break;
            }
        }
        stk_up.push(Points[i]);
    }
    // lower hull
    for (int i = 0; i < Points.size(); i++)
    {
        Points[i].x = -Points[i].x;
        Points[i].y = -Points[i].y;
    }
    sort(Points.begin(), Points.end());
    stack<point> stk_low;
    stk_low.push(Points[0]);
    stk_low.push(Points[1]);
    for (int i = 2; i < Points.size(); i++)
    {
        while ((stk_low.size() >= 2))
        {
            point p2, p3;
            p2 = stk_low.top();
            stk_low.pop();
            p3 = stk_low.top();
            if (ccw(Points[i], p2, p3))
            {
                stk_low.push(p2);
                break;
            }
        }
        stk_low.push(Points[i]);
    }

    // print convex hull - cw order from leftmost point
    vector<point> CH;
    stk_low.pop();
    point p;
    while (!stk_low.empty())
    {
        p = stk_low.top();
        p.x = -p.x;
        p.y = -p.y;
        CH.push_back(p);
        stk_low.pop();
    }
    stk_up.pop();
    while (!stk_up.empty())
    {
        CH.push_back(stk_up.top());
        stk_up.pop();
    }
    reverse(CH.begin(), CH.end()); // ccw -> cw
    return CH;
}
struct line
{
    double a, b, c;
}; // a way to represent a line

bool areParallel(line l1, line l2)
{ // check coefficients a & b
    return (fabs(l1.a - l2.a) < EPS) && (fabs(l1.b - l2.b) < EPS);
}

// returns true (+ intersection point) if two lines are intersect
bool areIntersect(line l1, line l2, point &p)
{
    if (areParallel(l1, l2))
        return false; // no intersection
    // solve system of 2 linear algebraic equations with 2 unknowns
    p.x = (l2.b * l1.c - l1.b * l2.c) / (l2.a * l1.b - l1.a * l2.b);
    // special case: test for vertical line to avoid division by zero
    if (fabs(l1.b) > EPS)
        p.y = -(l1.a * p.x + l1.c);
    else
        p.y = -(l2.a * p.x + l2.c);
    return true;
}
void pointsToLine(point p1, point p2, line &l)
{
    if (fabs(p1.x - p2.x) < EPS)
    { // vertical line is fine
        l.a = 1.0;
        l.b = 0.0;
        l.c = -p1.x; // default values
    }
    else
    {
        l.a = -(double)(p1.y - p2.y) / (p1.x - p2.x);
        l.b = 1.0; // IMPORTANT: we fix the value of b to 1.0
        l.c = -(double)(l.a * p1.x) - p1.y;
    }
}

int main()
{
    fastio();
    int M, C;

    while (cin >> M >> C)
    {
        if (!M && !C)
            break;
        vector<point> v1(M), v2(C);
        int x, y;
        for (int i = 0; i < M; i++)
        {
            cin >> x >> y;
            v1[i] = point(x, y);
        }
        for (int i = 0; i < C; i++)
        {
            cin >> x >> y;
            v2[i] = point(x, y);
        }
        vector<point> p1, p2;
        p1 = convex_hull(v1);
        p2 = convex_hull(v2);
        line l1, l2;
        point intersection;

        bool res = true;
        for (int a = 0; a < sz(p1); a++)
        {
            for (int b = a + 1; b <= sz(p1); b++)
            {
                pointsToLine(p1[a], p1[b % sz(p1)], l1);
                for (int c = 0; c < sz(p2); c++)
                {
                    for (int d = c + 1; d <= sz(p2); d++)
                    {
                        pointsToLine(p2[c], p2[d % sz(p2)], l2);
                        auto on_segment = [](point a1, point b2, point p)
                        {
                            return min(a1.x, b2.x) - EPS <= p.x && p.x <= max(a1.x, b2.x) + EPS &&
                                   min(a1.y, b2.y) - EPS <= p.y && p.y <= max(a1.y, b2.y) + EPS;
                        };
                        if (areIntersect(l1, l2, intersection) && on_segment(p1[a], p1[b % sz(p1)], intersection) &&
                            on_segment(p2[c], p2[d % sz(p2)], intersection))
                        {
                            res = false;
                            break;
                        }
                    }
                    if (!res)
                        break;
                }
                if (!res)
                    break;
            }
            if (!res)
                break;
        }
        if (res)
            cout << "Yes" << endl;
        else
            cout << "No" << endl;
    }
    return 0;
}