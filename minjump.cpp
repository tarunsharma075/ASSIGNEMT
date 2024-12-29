#include<iostream>
#include <algorithm>
using namespace std;
 int minjump(int a[],int n){
 	int Jump=0;
 	int Destination=0;
 	int Position=0;

 
 for(int i=0;i<n-1;i++){
 Destination= max( Destination,i+a[i]);
 if(Position==i){
 	Position=Destination;
 	Jump++;
 }	
  
 }
 return Jump;
}

int main(){
	 
	  int n;
	  cout<<"Enter the array size"<<" ";
	  cin>>n;
	   int arr[n];
	  for(int i=0;i<n;i++){
 	cout<<"enter the value at the "<<i<<" ";
   cin>>arr[i];
   cout<<endl;
}

cout<<minjump(arr,n);

 }

