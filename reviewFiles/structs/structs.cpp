
#include<iostream>
#include<iomanip>
#include<fstream>
#include<string>

using namespace std;
const int size = 100;

struct Student{
	string studentName;
	int studentID;
};


int readFile(Student s[]){
	
	int count;
	ifstream file;
	file.open("student.txt");
	
	for(int i=0; i<size; i++){
		if(!file.eof()){
			file>>s[i].studentName;
			file>>s[i].studentID;		
			count++;
		}
		else
			file.close();
	}

	return count-1;
	
}

void printFile(Student s[], int count){
	
	cout<<"Student Name "<<"  Student ID "<<endl;
	cout<<"------------ "<<"  ---------- "<<endl;
	for(int i=0; i<count; i++){
		cout<<setfill(' ');
		cout<<left<<setw(15)<<s[i].studentName;
		cout<<right<<setw(8)<<setfill('0');
		cout<<s[i].studentID<<endl;
	}
	cout<<"------------ "<<"  ---------- "<<endl;

}

void selectionSort(Student s[], int count){
	
	int i;
	int j;
	Student key1;
	for(i=1; i<count; i++){
		key1=s[i];
		j=i-1;
		
		while(j>=0 && s[j].studentName > key1.studentName){
			s[j+1]=s[j];
			j=j-1;
		}
		s[j+1]=key1;
	}
	
}

int linearSearch(int key, Student s[]){
	
	for(int i=0; i<size; i++){
		if(s[i].studentID == key)
			return i;
	}
	return -1;
	
}

int main(){
	
	Student sarray[size];
	
	int count;
	count=readFile(sarray);
	cout<<"Student Name/ID: "<<count<<" Stored in File ~student.txt~:"<<endl<<endl;
	printFile(sarray, count);
	cout<<endl;
	
	selectionSort(sarray, count);
	cout<<"Student Name/ID: Alphabetical Order:"<<endl<<endl;
	printFile(sarray, count);
	
	int key;
	cout<<"Enter A Student ID For Student Details:";
	cin>>key;
	
	key=linearSearch(key, sarray);
	
	if(key == -1)
		cout<<"ID DOES NOT EXIST"<<endl;
	else{
		cout<<"Student File Number: "<<key+1<<endl;
		cout<<"Student First Name:  "<<sarray[key].studentName<<endl;
	}
	
	return 0;
	
}

