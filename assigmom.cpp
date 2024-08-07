#include<iostream>
#include<algorithm>
using namespace std;


void prints(string s){
	
	int size=s.size();
	for(int i=0; i<size;i++){
		cout<<s[i]<<endl;
	}
	cout<<endl;
}

void allcap(string s){
		int size=s.size();
	for(int i=0; i<size;i++){
		s[i]=s[i]-32;
		cout<<s[i]<<endl;
	}
	cout<<endl;
}

void all_low(string s){
	int size=s.size();
	for(int i=0; i<size;i++){
		s[i]=s[i]+32;
		cout<<s[i]<<endl;
	}
	cout<<endl;
}

void ispalindrome(string s){
	string rev= s;
	reverse(rev.begin(), rev.end());	
	if(s==rev){
		cout<<"Palindrome";
	}else{
		cout<<"not palindrome";
	}
	
}

int main(){
	string s;
	getline(cin,s);
	prints(s);
	allcap(s);
	string S;
	cout<<"TYPE CAPITAL LEETERS ONLY"<<endl;
		getline(cin,S);
	all_low(S);
	cout<<"use a palindrome to check the code for example"<<endl;
	cout<<"civic radar level rotor kayak"<<endl;
	string p;
	getline(cin,p);
	
 ispalindrome(p);
}
