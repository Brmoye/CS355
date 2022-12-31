/*
 * Brian Moye
 * CS355-01
 * Game engine created by Dr. Ray to load .ifd files for users to play.
 * Parts indicated were modified by me.
 */

#include <vector>
#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <stdlib.h>

using namespace std;

class IFDParser{
	public:
	IFDParser(){
		pos = 0;
	   	gameFile = "";
	}

	void tokenIt(){
		string token="";
		string nextLine;
		char c;

    // Assignment #2
        if(gameFile == "")
        {
            cout << "Please enter the name of your .ifd file:" << endl;
            getline(cin, gameFile);
        }
    // end first part Assignment #2

	   	ifstream inFile;
	   	inFile.open(gameFile.c_str());

    // Assignment #2 cont.
        if(!inFile.is_open())
        {
            cout << "Error opening file: " << gameFile << endl;
            // exit() example found on https://www.cplusplus.com/reference/cstdlib/exit/
            exit(EXIT_FAILURE);
        }
        if(!inFile.good())
        {
            cout << "Error reading file: " << gameFile << endl;
            exit(EXIT_FAILURE);
        }
    // end Assignment #2

		while(!inFile.eof()){
			getline(inFile, nextLine);
			trim(nextLine);
		        c=nextLine[0];

			//dump any comment or blank line (all comments exist alone on their lines)
			if(c=='%' || nextLine == ""){
				//do nothing
			}
			else{
				//tokenize the entire line
				//cout<<nextLine<<endl;
				for(int i=0; i<nextLine.length(); i++){
					if(nextLine[i] == '>'){
						token = token + nextLine[i];
						if(token !="\n" && token !="" && token !=" " && token !="\t"){
							tokenVec.push_back(token);
						}
						token = "";
					}
					else if(nextLine[i]=='<'){
						if(token !="\n" && token !="" && token !=" " && token !="\t"){
							tokenVec.push_back(token);
						}
						token = "";
						token = token + nextLine[i];
					}
					else{
						token = token + nextLine[i];
					}
				}
			}
		}//while !eof
		inFile.close();
		return;
	}// end of tokenIt()

	void eatToken(){
		pos++;
	}

	string getNext(){
		return tokenVec[pos];
	}

	//helpre function for trimming a string's white space
	void trim(string& s)
    	{
       	size_t p = s.find_first_not_of(" \t");
       	s.erase(0, p);
    		p = s.find_last_not_of(" \t");
       	if (string::npos != p)
          		s.erase(p+1);
    	}

	void printTokens(){
		cout<<":::Printing the Tokens in Order:::"<<endl;
		for(int i=0; i<tokenVec.size(); i++){
			cout<<i<<": "<<tokenVec[i]<<endl;
		}
	}



	private:
		int pos;
		string gameFile;
        vector<string> tokenVec;
};
