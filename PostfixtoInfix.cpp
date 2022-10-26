#include<iostream>
#include<cstring>
using namespace std;
struct stack{
	string ele[30];
	int top;
};
void push(stack &st,string s1){
	st.top++;
	st.ele[st.top]=s1;
	
}
string pop(stack &st){
	return st.ele[st.top--];
}
int main()
{   stack st;
    int i=0; 
    string res;
    st.top=-1;
    string c;
    cin>>c;
   	while(c[i]!='\0'){
   		if(c[i]>='a' && c[i]<='z'){
   			char c1=c[i];
   			char ch[1]={c1};
   			push(st,ch);
		   }
		   else{
		   	string s1=pop(st);
		   	string s2=pop(st);
		   	push(st,s2+c[i]+s1);
		
		   }
	   i++;
	   
	}
	
	cout<<pop(st);
    
}