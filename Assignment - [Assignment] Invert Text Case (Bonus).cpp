#include <iostream>
#include<string>
 using namespace std;

void ChangeCase(string &s){
int n=s.length();
char c;
for(int i=0;i<n;i++){
	
	if(s[i]>='A'&&s[i]<='Z'){
	s[i]=s[i]+32;
	}else if(s[i]>='a'&&s[i]<='z'){
	s[i]=s[i]-32;
	}
}	
	
}	
	


int main(){

string s1;
cout<<"Enter The string"<<endl;
getline(cin,s1);
ChangeCase(s1);

cout<<"The Updated string "<<s1;
cout<<"The SIze of the String "<<sizeof(s1)<<endl;
cout<<"The length of the string"<<s1.length();
return 0;
 
}

 
