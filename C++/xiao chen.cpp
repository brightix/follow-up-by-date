#include <iostream>
#include <string>
using namespace std;
void test(string s){
    int n = s.size();
    int i,j,k,l;
    for(int i = 0;i<n;i++){
        for(int j = 0;j<n;j++){
            if(i == j)
                continue;
            for(int k = 0;k<n;k++){
                if(i == k || j == k)
                    continue;
                for(int l = 0;l<n;l++){
                    if(i == l || j== l || k == l)
                        continue;
                    cout << s[l] << s[k] << s[j] << s[i] << "\n";
                } 
            }    
        }
        
    }
}
int main(){
    string s =  "1234";
    test(s);
    //不重复
}