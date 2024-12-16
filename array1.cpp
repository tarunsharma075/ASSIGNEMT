#include <bits/stdc++.h>
using namespace std;

int main() {
    int arr_1[5] = {2, 4, 6, 8, 10};
    int arr_3[5]= {3,5,7,11,13};
    int* arr_2 = arr_1;
   	int *arr_4= arr_3;
    for (int i = 0; i < 5; i++) {
        cout << *(arr_2+i) << endl;
    }
 for (int i = 0; i < 5; i++) {
        cout << *(arr_4+i) << endl; 
    }
    return 0;
}
