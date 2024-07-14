#include<iostream>
#include<string>
using namespace std;

enum Grade{
	A,B_PLUS,B,C_PLUS,C,D,F,INVAILD
};

Grade stringToGrade(const string& grade)
{
	if(grade=="A") return A;
	else if(grade=="B+")return B_PLUS;
	else if(grade=="B")return B ;
	else if(grade=="C+"||grade=="c+")return C_PLUS ;
	else if(grade=="C"||grade=="c")return C;
	else if(grade=="D"||grade=="d")return D;
	else if(grade=="F"||grade=="f")return F;
	return INVAILD;

}


double gradeToPoints(Grade grade)
{
	switch(grade)
	{
		case A:return 4.0;
		case B_PLUS:return 3.5;
		case B:return 3.0;
		case C_PLUS:return 2.5;
		case C:return 2.0;
		case D:return 1.0;
		case F:return 0.0;
		default	:return 0.0;
	}
}

// Function to calculate GPA
void calculateGPA(const string grades[], const int credit_hours[], int number_of_courses, double &gpa, int &total_credits)
{
    double total_points = 0.0;
    total_credits = 0;
    for (int i = 0; i < number_of_courses; ++i) {
        Grade grade = stringToGrade(grades[i]);
        double points = gradeToPoints(grade);
        total_points += points * credit_hours[i];
        total_credits += credit_hours[i];
    }
    if (total_credits != 0)
    gpa = total_points / total_credits;
 else
    gpa = 0;
}


    // Function to calculate CGPA
double calculateCGPA(double previous_cgpa, int previous_total_credits, double current_gpa, int current_total_credits)
{
    int total_credits = previous_total_credits + current_total_credits;
    double total_points = (previous_cgpa * previous_total_credits) + (current_gpa * current_total_credits);
    double cgpa;
	if (total_credits != 0)
    cgpa = total_points / total_credits;
	else
    cgpa = 0;

    return cgpa;
}












int main()
{
	int number_of_courses;
	cout<<"Please Enter The Number Of Courses" ;
	cin>>number_of_courses;
	
	string*grades=new string[number_of_courses];
	int*credit_hours=new int[number_of_courses];
	
	for(int i=0;i<number_of_courses;i++)
	{
		cout<<"Enter the grade for course"<<(i + 1)<<": ";
		cin>>grades[i];
		cout<<"Enter the credit hours for course " <<(i + 1) <<": ";
        cin>>credit_hours[i];
	}
	
	//for preveious terms
	double previous_cgpa;
    int previous_total_credits;
    cout << "Enter previous CGPA (or 0 if none): ";
    cin >> previous_cgpa;
    cout << "Enter total credits for previous semesters (or 0 if none): ";
    cin >> previous_total_credits;
    
    
	//variables for current semester
    double current_gpa;
    int current_total_credits;
     
     
	// calculate GPA for the current semester
	 calculateGPA(grades, credit_hours, number_of_courses, current_gpa, current_total_credits);
    cout<<"Current GPA: "<<current_gpa<<endl;	
    
	// Calculate CGPA
    double cgpa = calculateCGPA(previous_cgpa, previous_total_credits, current_gpa, current_total_credits);
    cout<<"Cumulative GPA (CGPA): "<<cgpa<<endl;

	// Display individual grades and total credits/points
    cout << "\nCourse Grades and Credit Hours:\n";
    for (int i = 0; i < number_of_courses; ++i)
        cout << "Grade: " << grades[i] << ", Credit Hours: " << credit_hours[i] << endl;
    

    cout << "\nTotal Credits: " << current_total_credits << endl;
    double total_points = current_gpa * current_total_credits;
    cout << "Total Grade Points: " << total_points << endl;

    delete[] grades;
    delete[] credit_hours;




    return 0;
}
