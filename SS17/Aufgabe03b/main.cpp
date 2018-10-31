#include <string>
using namespace std;

#include "Student.cpp"
#include "Mitarbeiter.cpp"
#include "Professor.cpp"
unsigned int YEAR = 2017;

int main() {
    Student *student = new Student(1980, "Einstein", "Albert", "Maschinenbau", 22084754);
    Mitarbeiter *mitarbeiter = new Mitarbeiter(1975, "Zuse", "Konrad", 18344226, "The Impact of Listening Music on C++ Programming");
    Professor *professor = new Professor(1955, "Planck", "Max", 18344266, "Software");

    student->to_out();
    mitarbeiter->to_out();
    professor->to_out();

    return 0;
}