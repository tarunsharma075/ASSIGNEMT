#include<bits/stdc++.h>
using namespace std;
enum box{
	R=10,
	B=20,
};


int main(){
 string p;
 int ran;
 srand(time(0));	
for(int i=0;i<5;i++){
	ran=rand()%2;
	if(ran==0){
		p+="R";
	}else if(ran==1){
		p+="B";
	}
}	
int total_score=0;
char cchar=p[0];
int streak=1;

for(int i=1;i<p.length();i++){
	char c=p[i];
	if(c==cchar){
		streak++;
	}else{
		int base=(cchar=='R')?R:B;
		for(int j=1;j<=streak;j++){
		 total_score+=base*j;
		}
		cchar=p[i];
		streak=1;
	}
}


if(streak>0){
int base=(cchar=='R')?R:B;
for(int i=0;i<=streak;i++){
	total_score+=base*i;
}	
}

cout<<p<<"   "<<endl;
cout<<endl;
cout<<total_score<<endl;
	
}
