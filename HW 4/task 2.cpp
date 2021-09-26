#include <iostream>
#include <string>
#include <vector>

struct Student;

struct Lesson
{
	Lesson(std::string n) :
		name(n)
	{}

	std::string name;
	std::vector <Student*> students;

	void add_student(Student* s)
	{
		students.push_back(s);
	}
};


struct Student
{
	Student(std::string n):
		name(n)
	{}

	std::string name;
	std::vector <Lesson*> lessons;

	void add_lesson(Lesson* l)
	{
		(*l).add_student(this);
		lessons.push_back(l);
	}
};


int main()
{
	Student s_1("student_1"), s_2("student_2");
	Lesson l_1("lesson_1"), l_2("lesson_2");

	s_1.add_lesson(&l_1);
	s_2.add_lesson(&l_1);
	s_2.add_lesson(&l_2);

	std::vector <Student> students_array = {s_1, s_2};
	std::vector <Lesson> lessons_array = { l_1, l_2 };

	for (auto i = 0U; i < lessons_array.size(); ++i)
	{
		std::cout << "students of lesson: " << lessons_array[i].name << std::endl;
		for (auto j = 0U; j < lessons_array[i].students.size(); ++j)
		{
	/*		std::cout << (*s_1.lessons[i]).name;*/
			std::cout << (*lessons_array[i].students[j]).name << std::endl;
		}
	}
	/*int number_s;
	int number_l;
	std::vector <Student> students;
	std::string student;
	std::cout << "Enter number of students: ";
	std::cin >> number_s;
	for (auto i = 0U; i < number_s; ++i)
	{
		std::cout << "Enter student number " << i << " : ";
		std::cin >> student;
		students.push_back(student);
		std::cout << "Enter number of lessons of student " << students[i].name << ": ";
		std::cin >> number_l;
		for (auto j = 0U; j < number_l; ++j)
		{
			students[i].add_lesson()
		}
	}*/

}
