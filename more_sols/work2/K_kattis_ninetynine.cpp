#include <iostream>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cout << 2 << endl;
    int x;
    cin >> x;
    while(x%3 == 0){
        cout << x+1 << endl;
        cin >> x;
        if(x >= 99) return 0;
    }
    do{
        cout << x + 3 - (x% 3) << endl;
    } while(x < 99 && cin >> x);
    return 0;
}