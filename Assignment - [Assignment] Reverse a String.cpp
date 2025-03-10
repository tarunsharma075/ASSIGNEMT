#include <iostream>
#include<string>
 using namespace std;
void reverseString(string &s){
int n= s.length();
for(int i=0;i<n/2;i++)
{
    char temp= s[i];
    s[i]=s[n-i-1];
    s[n-1-i]=temp;
}
}

int main(){

    string s;
getline(cin,s);
reverseString(s);
cout<<s;
}

 
