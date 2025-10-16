#include <iostream>
#include <vector>
#include <sstream>
using namespace std;

typedef vector<int> vi;
typedef vector<vi> vvi;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;
    vvi amat(n, vi (n, 0));
    vi tEdge;
    for(int i = 1; i <= n; i++){
        int tEdgeCur;
        cout << "? " << i << endl;
        cin >> tEdgeCur;
        if(tEdgeCur < 0) return 0;
        tEdge.push_back(tEdgeCur);
    }
    for(int i = 1; i <= n; i++){
        for(int j = i+1; j <= n; j++){
            int mEdgeNum;
            cout << "? " << i << " " << j << endl;
            cin >> mEdgeNum;
            if(mEdgeNum < 0) return 0;
            if(mEdgeNum != tEdge[i-1] + tEdge[j-1]){
                amat[i-1][j-1] = 1;
                amat[j-1][i-1] = 1;
            }
        }
    }
    stringstream outMat;
    outMat << "!\n";
    for (vi& v : amat){
        for(int i =0; i < n-1; i++){
            outMat << v[i] << " ";
        }
        outMat << v.back()<< "\n";
    }
    cout << outMat.str();
    cout.flush();
    return 0;
}