#include <bits/stdc++.h>


using namespace std;

typedef vector<int> vi;
const int INF = 1e9;


class SuffixArray {
private:
    vi RA;                                         // rank array

    void countingSort(int k) {                     // O(n)
        int maxi = max(300, n);                      // up to 255 ASCII chars
        vi c(maxi, 0);                               // clear frequency table
        for (int i = 0; i < n; ++i) {                  // count the frequency
            ++c[i + k < n ? RA[i + k] : 0];
        }                // of each integer rank
        for (int i = 0, sum = 0; i < maxi; ++i) {
            int t = c[i];
            c[i] = sum;
            sum += t;
        }
        vi tempSA(n);
        for (int i = 0; i < n; ++i) {                  // sort SA
            tempSA[c[SA[i] + k < n ? RA[SA[i] + k] : 0]++] = SA[i];
        }
        swap(SA, tempSA);                            // update SA
    }

    void constructSA() {                           // can go up to 400K chars
        SA.resize(n);
        iota(SA.begin(), SA.end(), 0);               // the initial SA
        RA.resize(n);
        for (int i = 0; i < n; ++i) { RA[i] = T[i]; }    // initial rankings
        for (int k = 1; k < n; k <<= 1) {            // repeat log_2 n times
            // this is actually radix sort
            countingSort(k);                           // sort by 2nd item
            countingSort(0);                           // stable-sort by 1st item
            vi tempRA(n);
            int r = 0;
            tempRA[SA[0]] = r;                         // re-ranking process
            for (int i = 1; i < n; ++i) {                // compare adj suffixes
                tempRA[SA[i]] = // same pair => same rank r; otherwise, increase r
                        ((RA[SA[i]] == RA[SA[i - 1]]) && (RA[SA[i] + k] == RA[SA[i - 1] + k])) ?
                        r : ++r;
            }
            swap(RA, tempRA);                          // update RA
            if (RA[SA[n - 1]] == n - 1) break;             // nice optimization
        }
    }

    void computeLCP() {
        vi Phi(n);
        vi PLCP(n);
        PLCP.resize(n);
        Phi[SA[0]] = -1;                             // default value
        for (int i = 1; i < n; ++i) {                  // compute Phi in O(n)
            Phi[SA[i]] = SA[i - 1];
        }                      // remember prev suffix
        for (int i = 0, L = 0; i < n; ++i) {         // compute PLCP in O(n)
            if (Phi[i] == -1) {
                PLCP[i] = 0;
                continue;
            } // special case
            while ((i + L < n) && (Phi[i] + L < n) && (T[i + L] == T[Phi[i] + L])) {
                L++;
            }                                     // L incr max n times
            PLCP[i] = L;
            L = max(L - 1, 0);                           // L dec max n times
        }
        LCP.resize(n);
        for (int i = 0; i < n; ++i) {                  // compute LCP in O(n)
            LCP[i] = PLCP[SA[i]];
        }                      // restore PLCP
    }

public:
    const char* T;                                 // the input string
    const int n;                                   // the length of T
    vi SA;                                         // Suffix Array
    vi LCP;                                        // of adj sorted suffixes

    SuffixArray(const char* T, const int n) : T(T), n(n) {
        constructSA();                               // O(n log n)
        computeLCP();                                // O(n)
    }
};


// Segment Tree
const int N = 1e5 + 1;  // limit for array size
int n;  // array size
int t[2 * N];

void build() {  // build the tree
    for (int i = n - 1; i > 0; --i) { t[i] = min(t[i << 1], t[i << 1 | 1]); }
}

void modify(int p, int value) {  // set value at position p
    for (t[p += n] = value; p > 1; p >>= 1) { t[p >> 1] = min(t[p], t[p ^ 1]); }
}

int query(int l, int r) {  // min on interval [l, r)
    int res = INF;
    for (l += n, r += n; l < r; l >>= 1, r >>= 1) {
        if (l & 1) res = min(res, t[l++]);
        if (r & 1) res = min(res, t[--r]);
    }
    return res;
}


int main() {
    string s;
    cin >> s;

    s.push_back('$');
    SuffixArray SA(s.c_str(), s.size());

    // segment tree of LCP
    n = s.size();
    for (int i = 0; i < n; ++i) {
        t[n + i] = INF; // init array
    }
    build();
    for (int i = 0; i < n; ++i) {
        modify(i, SA.LCP[i]);
    }


    // map index in s -> index in SA
    map<int, int> map_s_SA;
    for (int i = 0; i < n; ++i) {
        map_s_SA[SA.SA[i]] = i;
    }

    int cases;
    cin >> cases;
    while (cases--) {
        int a, b;
        cin >> a >> b;
        if (a == b) {
            cout << 1 << endl;
        } else {
            a = map_s_SA[a];
            b = map_s_SA[b];
            cout << query(min(a, b) + 1, max(a, b) + 1) << endl;
        }
    }
    return 0;
}