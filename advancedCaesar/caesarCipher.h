#include <string>
using namespace std;

class caesarCipher {
private:
	int shiftValue;
		
public:
	caesarCipher(){
	  shiftValue = 1;
	}
	caesarCipher(int sv){
		shiftValue = sv;
	}
		
	string encrypt(string s){ 
		for(int i=0;i<(s.length());i++){
			if (s[i] >= 97 && s[i] <= 122){
				if (s[i]+shiftValue > 122){ 
					s[i]=122-(s[i]%97);	
				}
				else{
					s[i]+=shiftValue;
				}		
			}
		}
		return s;
    	}
	string decrypt(string s){ 
		for(int i=0;i<s.length();i++){
			if (s[i] >= 97 && s[i] <= 122){
				if (s[i]-shiftValue < 97){
					s[i]=97+(122%s[i]);
				}			
				else{
					s[i]-=shiftValue;		
				}		
			}
		}
		return s;
	}	
	void print(){
		cout << shiftValue << endl;
		return;
     }
};
