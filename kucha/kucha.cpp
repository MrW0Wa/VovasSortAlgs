#include <iostream>
#include <fstream>
#include <vector>
#include <chrono>
#include <algorithm>

using namespace std;

vector<int> v = {0,1};
vector<int> v3 = { 0,1 };




void shift_up(int x) {
    while (x > 1 && v[x / 2] > v[x]) {
        swap(v[x], v[x / 2]);
        x /= 2;
    }
}



//void shift_down(int x) {
//    while (x * 2 + 1 < v.size() && x * 2 < v.size() && (v[x * 2] < v[x] || v[x * 2 + 1] < v[x])) {
//        if ((v[x * 2 + 1] < v[x * 2])) {
//            swap(v[x * 2 + 1], v[x]);
//            x = x * 2 + 1;
//
//        }
//        else {
//            swap(v[x * 2], v[x]);
//            x *= 2;
//        }
//    }
//}

//void shift_down(int x) {
//        while (x <= v.size() && v[x] > v[x+1]) {
//            swap(v[x], v[x + 1]);
//            x++;
//        }
//        while (x * 2 + 1 < v.size() || x * 2 < v.size()) {
//            if (x * 2 < v.size() && v[x] > v[x * 2]) {
//                swap(v[x], v[x * 2]);
//                x *= 2;
//            }
//            else if (x * 2 + 1 < v.size() && v[x] > v[x * 2 + 1]) {
//                swap(v[x], v[x * 2 + 1]);
//                x = x * 2 + 1;
//            }
//            else break;
//        }
//}

void shift_down(int k) {
    // пока не пришли в лист
    int n = v.size()-1;
    while (2 * k <= n) { // n -- количество элементов в куче
        int l = 2 * k; // левый сын
        int r = 2 * k + 1; // правый сын
        // если правый сын существует и меньше, выбираем его
        int u;
        if (r <= n && v[r] < v[l]) {
            u = r;
        }
        else {
            u = l;
        }
        if (v[k] <= v[u]) {
            break; // инвариант и так выполняется, завершаемс
        }
        swap(v[k], v[u]);
        k = u;
    }
}

void bubbleSort()
{
    int n = v3.size();
    int i, j;
    for (i = 0; i < n - 1; i++)
        // Last i elements are already in place
        for (j = 0; j < n - i - 1; j++)
            if (v3[j] > v3[j + 1])
                swap(v3[j], v3[j + 1]);
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
    v.pop_back();
    ifstream file;
    int num = 0;
    file.open("U:/Khmelevskiy Vladimir/kucha/task5.txt");
    for (int i = 0; i < 160000; i++) {
        file >> num;
        v.push_back(num);
    }
    // sort(v.begin(), v.end());

    // v[7] = 777;
    //show();
    for (int i = 1; i < v.size(); i++) {
        shift_up(i);
    }
   // show();
    int size = v.size();

    vector<int> v1 = v;
    vector<int> v2;
    v3 = v;


    using namespace std::chrono;
    auto t1 = high_resolution_clock::now();
    for (int i = 1; i < size; i++) {
        //cout << v[1] << ' ';
        v2.push_back(v[1]);
        swap(v[1], v[v.size() - 1]);
        v.pop_back();
        shift_down(1);
    }
    std::cout << endl;
    auto t2 = high_resolution_clock::now();
    long micro = chrono::duration_cast<microseconds>(t2 - t1).count();

    using namespace std;
    cout << "HeapSort() " << micro << " ms (10^(-6) sek" << endl;
    cout << endl;


    using namespace std::chrono;
     t1 = high_resolution_clock::now();
     sort(v1.begin(), v1.end());
     t2 = high_resolution_clock::now();
     micro = chrono::duration_cast<microseconds>(t2 - t1).count();

    using namespace std;
    cout << "Sort() " << micro << " ms (10^(-6) sek" << endl;
    cout << endl;


    using namespace std::chrono;
    t1 = high_resolution_clock::now();
    bubbleSort();
    t2 = high_resolution_clock::now();
    micro = chrono::duration_cast<microseconds>(t2 - t1).count();

    using namespace std;
    cout << "bubble() " << micro << " ms (10^(-6) sek" << endl;
    cout << endl;
    //show();


}