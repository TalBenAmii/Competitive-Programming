#include <bits/stdc++.h>


using namespace std;


typedef long double ld;
typedef pair<int, int> ii;

struct Drone {
    int x;
    int v;
};

vector<Drone> drones;

struct Event {
    int left;
    int right;

    Event(int l, int r) : left(l), right(r) {}

    ld getCollisionTime() const {
        int dx = drones[right].x - drones[left].x;
        int dv = drones[left].v - drones[right].v;
        if (dv == 0) return -1;
        return (ld) dx / dv;
    }

    // greater (min heap)
    bool operator<(const Event& other) const {
        ld t1 = getCollisionTime();
        ld t2 = other.getCollisionTime();
        return t1 > t2;
    }
};


#define INF 1e9


int main() {
    ios_base::sync_with_stdio();
    cin.tie(0);

    int n;
    cin >> n;
    vector<bool> notCrashed(n, true);
    drones = vector<Drone>(n);
    for (int i = 0; i < n; ++i) {
        cin >> drones[i].x >> drones[i].v;
    }

    priority_queue<Event> pq;
    for (int i = 0; i < n - 1; ++i) {
        Event e{i, i + 1};
        if (e.getCollisionTime() >= 0) pq.push(e);
    }

    while (!pq.empty()) {
        Event e = pq.top();
        pq.pop();
        int left = e.left, right = e.right;

        if (notCrashed[left] && notCrashed[right]) {
            notCrashed[left] = false;
            notCrashed[right] = false;
            while (left > 0 && !notCrashed[left]) { left--; }
            while (right < n && !notCrashed[right]) { right++; }

            if (left >= 0 && right < n) {
                Event newE{left, right};
                ld t = newE.getCollisionTime();
                if (t >= 0) pq.push(newE);
            }
        }
    }


    int totalCrashed = 0;
    for (auto i : notCrashed) { totalCrashed += i; }
    cout << totalCrashed << endl;
    for (int i = 0; i < n; ++i) {
        if (notCrashed[i]) {
            cout << i + 1 << " ";
        }
    }
    cout << endl;
    return 0;
}
