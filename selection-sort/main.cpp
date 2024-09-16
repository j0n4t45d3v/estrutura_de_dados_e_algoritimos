#include <iostream>
#include <random>
#include <string>
#include <vector>

using namespace std;

struct StudentGrade {
  string student;
  unsigned short grade;
};

void population_vector(vector<StudentGrade> &);
void print_vector(vector<StudentGrade>);
void selection_sort(vector<StudentGrade> &);
short search_less(vector<StudentGrade>);

int main(int argc, char *argv[]) {
  vector<StudentGrade> student_grades{};
  population_vector(student_grades);
  print_vector(student_grades);
  selection_sort(student_grades);
  print_vector(student_grades);
  return 0;
}

void population_vector(vector<StudentGrade> &vector) {
  random_device rd;
  mt19937 gen(rd());
  uniform_int_distribution<> distrib(0, 10);
  for (unsigned short i = 0; i < 5; i++) {
    StudentGrade student_grade;
    student_grade.student = "Teste " + to_string(i);
    student_grade.grade = distrib(gen);
    vector.push_back(student_grade);
  }
}

void print_vector(vector<StudentGrade> student_grades) {
  cout << "=======================================" << endl;
  for (StudentGrade student_grade : student_grades) {
    cout << "Aluno: " << student_grade.student << ", Nota: " << student_grade.grade << endl;
  }
  cout << "=======================================" << endl;
}

void selection_sort(vector<StudentGrade> &student_grades) {
  vector<StudentGrade> temp_vector{};

  for (StudentGrade grade : student_grades) {
    short less = search_less(student_grades);
    temp_vector.push_back(student_grades[less]);
    student_grades.erase(student_grades.begin() + less);
  }

  student_grades = temp_vector;
}
short search_less(vector<StudentGrade> student_grades) {
  StudentGrade less = student_grades[0];
  unsigned short less_index = 0;
  for (unsigned short i; i < student_grades.size(); i++) {
    StudentGrade grade = student_grades[i];
    if (less.grade > grade.grade) {
      less = grade;
      less_index = i;
    }
  }
  return less_index;
}
