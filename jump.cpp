#include<iostream>
#include <algorithm>
using namespace std;
bool jumpGame(int a[], int arraySize) {
    int maxIndex = 0;

    // Input the array
    for (int i = 0; i < arraySize; i++) {
        cout << "Enter integer at index " << i << ": ";
        cin >> a[i];
    }

    // Check jump game logic
    for (int i = 0; i < arraySize; i++) {
        if (i > maxIndex) {
            return false; 
        }
        maxIndex = max(maxIndex, i + a[i]); 
    }
    return true;  
}

int main(){
		int n;
			cout<<"Enter the size of the array "<<endl;
	cin>>n;
	
	int arr[n];



cout<<jumpGame(arr,n);
	
	return 0;
}
