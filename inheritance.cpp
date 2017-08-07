#include <bits/stdc++.h>
#include <iostream>
#include <vector>

using namespace std;


class Person{
	protected:
		string firstName;
		string lastName;
		int id;
	public:
		Person(string firstName, string lastName, int identification){
			this->firstName = firstName;
			this->lastName = lastName;
			this->id = identification;
		}
		void printPerson(){
			cout<< "Name: "<< lastName << ", "<< firstName <<"\nID: "<< id << "\n"; 
		}
	
};

class Student :  public Person{
	private:
		vector<int> testScores;  
	public:
        /*	
        *   Class Constructor
        *   
        *   Parameters:
        *   firstName - A string denoting the Person's first name.
        *   lastName - A string denoting the Person's last name.
        *   id - An integer denoting the Person's ID number.
        *   scores - An array of integers denoting the Person's test scores.
        */

        // Write your constructor here
            Student(string fName,string lName,int idi,vector<int> scores) : Person(firstName,lastName,id)
            {   
                firstName = fName;
                lastName = lName;
                id = idi;     
                this->testScores = scores;
            }
        
        /*	
        *   Function Name: calculate
        *   Return: A character denoting the grade.
        */
        // Write your function here
        char calculate()
        {
            int size = testScores.size();
            int i,sum = 0;
            for(i = 0; i < size; i++)
            {
                sum += testScores[i];
            }
            sum = sum/size;
            if(sum>=90 && sum <= 100)
                return 'O';
            if(sum>=80 && sum < 90)
                return 'E';
            if(sum>=70 && sum < 80)
                return 'A';
            if(sum>=55 && sum < 70)
                return 'P';
            if(sum>=40 && sum < 55)
                return 'D';
            if(sum<40)
                return 'T';
            return 'X';
        }
        
};

int main() {
	string firstName;
  	string lastName;
	int id;
  	int numScores;
	cin >> firstName >> lastName >> id >> numScores;
  	vector<int> scores;
  	for(int i = 0; i < numScores; i++){
	  	int tmpScore;
	  	cin >> tmpScore;
		scores.push_back(tmpScore);
	}
	Student* s = new Student(firstName, lastName, id, scores);
	s->printPerson();
	cout << "Grade: " << s->calculate() << "\n";
	return 0;
}