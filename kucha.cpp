#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> v{ 0,45,33,37,48,26,20,53,55,59,50,56,20,33,50,28,11,41,26,38,41 };



void shift_up(int x) {
    while (x > 1 && v[x / 2] > v[x]) {
        swap(v[x], v[x / 2]);
        x /= 2;
    }
}

void shift_down(int x) {
    while (v[x * 2] < v[x] || v[x * 2 + 1] < v[x]) {
        if (v[x * 2 + 1] < v[x * 2]) {
            swap(v[x * 2 + 1], v[x]);
            x = x * 2 + 1;

        }
        else {
            swap(v[x * 2], v[x]);
            x *= 2;
        }
    }
}


void show() {
    int deg2[] = { 2, 4, 8, 16, 32, 64, 128 };
    int j = 0;
    for (int k = 1; k < v.size(); k++) {
        if (k == deg2[j]) {
            cout << '\n';
            j++;
        }
        cout << v[k] << ' ';
    }
    cout << '\n' << '\n';
}

int main()
{
    // sort(v.begin(), v.end());
    for (int i : v) {
        cout << i << ' ';
    } cout << endl;

    // v[7] = 777;
    show();
    for(int i = v.size()-1; i >= 1; i--){
        shift_up(i);        
    }

    show();


}