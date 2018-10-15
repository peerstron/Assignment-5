#include <iostream>
#include <fstream>
#include <string>
using namespace std;


//A c++ Program To Write Students Details To File.


//struct definition of datatypes
struct StudentRecord {
	int StudentAge; 
	int StudentScore;
	int StudentID;
	char StudentGrade;
	string StudentName;
	string StudentGender;
};
	
	
	
//Grading system checker
		char checkGrade(float StudentScore){
	char StudentGrade;

	
	if(StudentScore >=80 && StudentScore <100){
		StudentGrade = 'A';
	}else if (StudentScore >=70 && StudentScore <80){
		StudentGrade = 'B';
	}else if (StudentScore >=60 && StudentScore <70){
		StudentGrade = 'C';
	}else if (StudentScore >=50 && StudentScore < 60){
		StudentGrade = 'D';
	}else if (StudentScore >=40 && StudentScore < 50){
		StudentGrade = 'E';
	}else {
		StudentGrade = 'F';
	}
	
	return StudentGrade;
}
	

int main(){

	int maleCount=0, femaleCount=0;
	int sumScore=0, sumAge=0;
	StudentRecord student[5];
	
	for (int i=0; i<5; i++){
		cout<<"StudentID: ";
		cin>>student[i].StudentID;
		
		cout<<"Student Name: ";
		cin>>student[i].StudentName;
		
		cout<<"Student Age: ";
		cin>>student[i].StudentAge;
		for (i=0; i<5; i++){
			sumAge += student[i].StudentAge;
		}
		
		cout<<"Student Gender: ";
		cin>>student[i].StudentGender;
		for (i=0; i<5; i++){
			if (student[i].StudentGender == "Male"){
				maleCount += 1;
			}
			else{
				femaleCount += 1;
			}
			
		}
		
		cout<<"Student Score: ";
		cin>>student[i].StudentScore;
		for (i=0; i<5; i++){
			sumScore += student[i].StudentScore;
		}
		
		student[i].StudentGrade = checkGrade(student[i].StudentScore);
		
	}
	
	cout<<"Total Male is: "<<maleCount<<endl;
	cout<<"Total Female is: "<<femaleCount<<endl;
	cout<<"Total Age is: "<<sumAge<<endl;
	cout<<"Total Score is: "<<sumScore<<endl;
	
	
	
	fstream fin;
	fin.open("studentrecord.txt");

	fin << "StudentID\tStudentName\tStudentAge\tStudentGender\tStudentScore\t\StudentGrade" << endl;
	for(int i=0; i<5; i++){
		fin << i << " " << student[i].StudentID <<"\t\t"<<student[i].StudentName << "\t" << student[i].StudentAge << "\t" << student[i].StudentGender<< "\t" << student[i].StudentScore << "\t" << student[i].StudentGrade << endl;
	}
	
}
