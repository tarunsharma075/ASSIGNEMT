#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cout << "Enter the size of Array: ";
    cin >> n;
    int a[n];
    
    for (int i = 0; i < n; i++) {
        cout << "Input at index " << i << ": ";
        cin >> a[i];
    }

 

for(int i=0;i<n;i++){
	  if(n==1){
   	cout<<"peakelement index is "<<i<<" "<<"And the value is "<<a[i]<<endl;
}else if(i==n-1&&a[i]>a[i-1]){
	cout<<"peakelement index is "<<i<<" "<<"And the value is "<<a[i]<<endl;
}else if(i>0&&a[i]>a[i-1]&&a[i]>a[i+1]){
		cout<<"peakelement index is "<<i<<" "<<"And the value is "<<a[i]<<endl;
}
}
return 0;
}
