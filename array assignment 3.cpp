//Problem Statement:
//
//Write a C++ program that performs the following operations:
//
//Create an array based on user-specified size.
//Fills the array with integers provided by the user.
//Asks the user to specify an integer to be removed from the array.
//Deletes the first occurrence of the specified integer from the array, if it exists, and shifts the remaining elements accordingly.
//If the specified integer is not found, the program should inform the user.
//Print the updated array after the deletion operation.
//
//Input Format:
//
//A single integer n, the size of the array.
//Followed by n integers, representing the elements to fill the array.
//
//
//Output Format:
//
//A single line starting with the phrase "Updated array: ", followed by the elements of the array after the deletion operation. Each element should be separated by a space.
//If the element to delete is not found, output "Element not found. No deletion performed."
//
#include<iostream>
using namespace std;
void DeleteElement(int*a,int*size){
	int elementIndex=-1;
	int elementToDelete=0;
	cout<<"Enter the Elements ";
	
	for(int i=0;i<*size;i++){
	cout<<"Value at index "<<i<<" :";
	cin>>*(a+i);
	}
	
	cout<<"Enter the Element to delete ";
	cin>>elementToDelete;
	
for(int i=0;i<*size;i++){
	if(*(a+i)== elementToDelete){
	elementIndex=i;	
	}
}
	
	
cout<<"Array before update"<<endl;
	for(int i=0;i<*size;i++){
		cout<<*(a+i)<<" ";
		
	}
	cout<<endl;
	if(	elementIndex!=-1){
		for(int i=	elementIndex;i<*size;i++){
			*(a+i)=*(a+i+1);
		}
		(*size)--;
		}else{
			cout<<"Not Found The element";
			return ;
		}
	
	cout<<"Element is Found And the array is ";
	for(int i=0;i<*size;i++){
		
	cout<<*(a+i)<<" ";
}
}


int main() {
 int size = 0;

  cout<<"Enter the size :";
  cin>>size;
  int arr[size];

    DeleteElement(arr, &size);

    return 0;
}
