#include<bits/stdc++.h>
using namespace std;
string str="GeeksforGeeks",pattern="GfG";
bool back(unordered_map<char,string>mp,int l,int r,int patternIndex){
    cout<<l<<"\n";
	if(patternIndex==pattern.length()){
		string ans="";
        // mp[pattern[patternIndex]]=str.substr(l);
		for(char c:pattern){
			ans+=mp[c];
        }
        if(str==ans)return true;
        return false;
}
for(int i=l+1;i<=r;i++){
    if(mp.find(pattern[patternIndex])!=mp.end() ){
        if(mp[pattern[patternIndex]]!=str.substr(l,i))
            {
                cout<<str.substr(l,i)<<"\tSkipped\n";
                    continue;
            }
    }
	mp[pattern[patternIndex]]=str.substr(l,i);
    cout<<mp['G']<<"\t"<<mp['f']<<"\n"<<str.substr(l,i)<<"\t"<<str.substr(i)<<"\n\n";
    for(long long j=0;j<1000000000;j++);
	if(back(mp,i,r,patternIndex+1))return true;
	mp.erase(pattern[patternIndex]);
}
return false;
}
int main(){
    unordered_map<char,string>mp;
    cout<<back(mp,0,str.length(),0);
}