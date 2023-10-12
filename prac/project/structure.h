#ifndef STRUCTURE
#define STRUCTURE
struct Course{
    char course_code[100];
	char course_name[100];
    char facultyUID[100];
    int  credits;
    int  currentStudentsEnrolled;
    int  maxStudentsAllowed;
};
struct Admin{
	char name[100];
	char emailId[100];
	char password[100];
};
struct Student{
	char name[100];
	char rollno[100];
	char emailId[100];
	char password[100];
	int  status;
	//struct Course courseEnrolled[6];
};
struct Faculty{
	char name[100];
    char facultyUID[100];
	char emailId[100];
	char password[100];
	//struct Course courseOffered[6];
};
#endif
