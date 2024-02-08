#include <stdio.h>

typedef students
{
	char *name;
	int age;
	float gpa;
} student;


void exam()
{

}

int main()
{
	student s1 = {"John", 20, 3.5};
	student s2 = {"Jane", 21, 3.8};

	printf("Name: %s\n", s1.name);
	printf("Age: %d\n", s1.age);
	printf("GPA: %.2f\n", s1.gpa);

	printf("Name: %s\n", s2.name);
	printf("Age: %d\n", s2.age);
	printf("GPA: %.2f\n", s2.gpa);

	exam()
	return 0;
}
