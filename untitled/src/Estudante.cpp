#include <algorithm>
#include "../include/Estudante.h"
#include <iomanip>
#include <iostream>
using namespace std;

Estudante::Estudante()= default;

Estudante::Estudante(string studentCode){
    studentCode_ = studentCode;
}

string Estudante::get_studentCode() const {return studentCode_;}

string Estudante::get_studentName(vector<Read_line> lines) const {
    Estudante student(studentCode_);
    return student.find(lines)[0].getString(1);
}

string Estudante::get_Classcode_in_UC(vector<Read_line> lines, string ucCode){
    Estudante student(studentCode_);
    for( auto line: student.find(lines)){
        if(ucCode == line.getString(2) ){
            return line.getString(3);
        }
    }
    return {};
}

int Estudante::lowerStudentIndex( vector<Read_line> students) {
    int up = stoi(studentCode_);
    int lower = 0,
            higher = students.size()-1;
    while(higher > lower){
        int medium = lower + (higher-lower)/2;
        if(students[medium].getInt(0) >= up) higher = medium;
        else  lower = medium +1;
    }
    return lower;
}
int Estudante::highStudentIndex(vector<Read_line> students){
    int index;
    int up = stoi(studentCode_);
    int low = 0;
    int high= students.size()-1;

    while(high > low){
        int medium = low + (high-low)/2;
        if(students[medium].getInt(0) >= up + 1) high = medium;
        else  low = medium +1;
    }
    if(students[low].getInt(0) > up) index = low-1;
    else index = low;

    return index;

}
vector<Read_line> Estudante::find(vector <Read_line> students){

    vector<Read_line> aux;
    int resultA = lowerStudentIndex(students);
    int resultB = highStudentIndex(students);

    for(int i = resultA; i <= resultB; i++){
        aux.push_back(students[i]);
    }
    return aux;

}


void Estudante::print_horario_class_uc(vector<Aula> horario){

    cout << "______________________________________________________________________________________________________________________" <<endl;
    cout << "|                                           SCHEDULE OF " << studentCode_ << "                                                    |" <<endl;
    cout << "|____________________________________________________________________________________________________________________|" <<endl;
    cout << "|    Weekday   |     UcCode    |      Type      |    StartHour    |     EndHour     |    Duration    |   classCode   |" <<endl;
    cout << "|______________|_______________|________________|_________________|_________________|________________|_______________|" <<endl;
    int i = 0;
    for(Aula aula : horario) {
        if(aula.get_weekDay() == "Monday" && i == 0){
            i++;
            cout << "|Monday        |" << left << setw(15) << aula.get_ucCode() << "|" << left << setw(16) << aula.get_type() << "|" << left << setw(17) << aula.get_startHour() << "|" << left << setw(17) << aula.get_endingTime() << "|" << left << setw(16) << aula.get_duration() << "|" << left << setw(15) << aula.get_classCode() << "|"  <<endl;
        } else if (aula.get_weekDay() == "Monday" && i != 0){
            cout << "|              |_______________|________________|_________________|_________________|________________|_______________|" <<endl;
            cout << "|              |" << left << setw(15) << aula.get_ucCode() << "|" << left << setw(16) << aula.get_type() << "|" << left << setw(17) << aula.get_startHour() << "|" << left << setw(17) << aula.get_endingTime() << "|" << left << setw(16) << aula.get_duration() << "|" << left << setw(15) << aula.get_classCode() << "|"  <<endl;
        }
    }

    cout << "|______________|_______________|________________|_________________|_________________|________________|_______________|" <<endl;
    i = 0;
    for(Aula aula : horario) {
        if(aula.get_weekDay() == "Tuesday" && i == 0){
            i++;
            cout << "|Tuesday       |" << left << setw(15) << aula.get_ucCode() << "|" << left << setw(16) << aula.get_type() << "|" << left << setw(17) << aula.get_startHour() << "|" << left << setw(17) << aula.get_endingTime() << "|" << left << setw(16) << aula.get_duration() << "|" << left << setw(15) << aula.get_classCode() << "|"  <<endl;
        } else if (aula.get_weekDay() == "Tuesday" && i != 0){
            cout << "|              |_______________|________________|_________________|_________________|________________|_______________|" <<endl;
            cout << "|              |" << left << setw(15) << aula.get_ucCode() << "|" << left << setw(16) << aula.get_type() << "|" << left << setw(17) << aula.get_startHour() << "|" << left << setw(17) << aula.get_endingTime() << "|" << left << setw(16) << aula.get_duration() << "|" << left << setw(15) << aula.get_classCode() << "|"  <<endl;
        }
    }

    cout << "|______________|_______________|________________|_________________|_________________|________________|_______________|" <<endl;
    i = 0;
    for(Aula aula : horario) {
        if(aula.get_weekDay() == "Wednesday" && i == 0){
            i++;
            cout << "|Wednesday     |" << left << setw(15) << aula.get_ucCode() << "|" << left << setw(16) << aula.get_type() << "|" << left << setw(17) << aula.get_startHour() << "|" << left << setw(17) << aula.get_endingTime() << "|" << left << setw(16) << aula.get_duration() << "|" << left << setw(15) << aula.get_classCode() << "|"  <<endl;
        }else if (aula.get_weekDay() == "Wednesday" && i != 0){
            cout << "|              |_______________|________________|_________________|_________________|________________|_______________|" <<endl;
            cout << "|              |" << left << setw(15) << aula.get_ucCode() << "|" << left << setw(16) << aula.get_type() << "|" << left << setw(17) << aula.get_startHour() << "|" << left << setw(17) << aula.get_endingTime() << "|" << left << setw(16) << aula.get_duration() << "|" << left << setw(15) << aula.get_classCode() << "|"  <<endl;
        }
    }

    cout << "|______________|_______________|________________|_________________|_________________|________________|_______________|" <<endl;
    i = 0;
    for(Aula aula : horario) {
        if(aula.get_weekDay() == "Thursday" && i == 0){
            i++;
            cout << "|Thursday      |" << left << setw(15) << aula.get_ucCode() << "|" << left << setw(16) << aula.get_type() << "|" << left << setw(17) << aula.get_startHour() << "|" << left << setw(17) << aula.get_endingTime() << "|" << left << setw(16) << aula.get_duration() << "|" << left << setw(15) << aula.get_classCode() << "|"  <<endl;
        }else if (aula.get_weekDay() == "Thursday" && i != 0){
            cout << "|              |_______________|________________|_________________|_________________|________________|_______________|" <<endl;
            cout << "|              |" << left << setw(15) << aula.get_ucCode() << "|" << left << setw(16) << aula.get_type() << "|" << left << setw(17) << aula.get_startHour() << "|" << left << setw(17) << aula.get_endingTime() << "|" << left << setw(16) << aula.get_duration() << "|" << left << setw(15) << aula.get_classCode() << "|"  <<endl;
        }
    }

    cout << "|______________|_______________|________________|_________________|_________________|________________|_______________|" <<endl;
    i = 0;
    for(Aula aula : horario) {
        if (aula.get_weekDay() == "Friday" && i == 0) {
            i++;
            cout << "|Friday        |" << left << setw(15) << aula.get_ucCode() << "|" << left << setw(16) << aula.get_type() << "|" << left << setw(17) << aula.get_startHour() << "|" << left << setw(17) << aula.get_endingTime() << "|" << left << setw(16) << aula.get_duration() << "|" << left << setw(15) << aula.get_classCode() << "|"  <<endl;
        } else if (aula.get_weekDay() == "Friday" && i != 0) {
            cout << "|              |_______________|________________|_________________|_________________|________________|_______________|" << endl;
            cout << "|              |" << left << setw(15) << aula.get_ucCode() << "|" << left << setw(16) << aula.get_type() << "|" << left << setw(17) << aula.get_startHour() << "|" << left << setw(17) << aula.get_endingTime() << "|" << left << setw(16) << aula.get_duration() << "|" << left << setw(15) << aula.get_classCode() << "|"  <<endl;
        }
    }
    cout << "|______________|_______________|________________|_________________|_________________|________________|_______________|" <<endl;
}


