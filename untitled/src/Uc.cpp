#include "../include/Uc.h"
#include "../include/Turma.h"
#include <iomanip>
#include <iostream>

using namespace std;

Uc::Uc(std::string ucCode){
    ucCode_ = ucCode;
}

//altera o horário de todas as aulas de uma uc
void Uc::change_horarios_uc(vector<Read_line> lines) {
    Horario horario(lines, ucCode_,1);
    horario_uc = horario.get_horario();
}

vector<Aula> Uc::get_horario_uc(){
    return horario_uc;
}

//obtemos o horário da uc de determinada turma
vector<Aula> Uc::get_horarios_uc_turma(vector<Read_line> lines,  string classCode) {
    change_horarios_uc(lines);
    vector<Aula> new_horario;

    for(int i = 0; i < horario_uc.size(); i++ ){

        if(horario_uc[i].get_classCode() == classCode){

            new_horario.push_back(horario_uc[i]);
        }
    }
    return new_horario;
};
// obter o horário da uc de determinada turma sem aulas teóricas
vector<Aula> Uc::get_horarios_turma_without_T(vector<Read_line> lines,  string classCode) {
    change_horarios_uc(lines);

    vector<Aula> new_horario;

    for(int i = 0; i < horario_uc.size(); i++ ){

        if(horario_uc[i].get_classCode() == classCode && horario_uc[i].get_type() != "T"){

            new_horario.push_back(horario_uc[i]);
        }
    }
    return new_horario;
};

//fazer a lista de todas as turmas a cada uc
vector <Turma> Uc::classList(vector<Read_line> lines) {
    vector <Turma> classList;

    for (auto line: lines) {

        if(line.getString(2) == ucCode_) {

            Turma new_turma = Turma(line.getString(3), line.getString(2));

            classList.push_back(new_turma);

        }
    }
    return classList;
}

// obter o número de estudantes de uma UC
int Uc::get_number_students(vector<Read_line> lines){
    int num = 0;
    set<string> students;

    for(auto line: lines){

        auto i = students.find(line.getString(0));

        //verificar se o ucCode é igual e o up não se encontra no set

        if(line.getString(2) == ucCode_ && i == students.end()){
            num++;
            students.insert(line.getString(0));
        }
    }

return num;
}

int Uc::defineCap(vector<Read_line> lines, vector<Turma> classlist ) {

    int cap = 0;

    for (auto turma: classlist) {

        if (turma.getStudentNumber(lines) > cap) {

            cap = turma.getStudentNumber(lines);

        }
    }
    return cap;
}


int Uc::defineMin(vector<Read_line> lines, vector<Turma> classlist ) {

    int min = classlist[0].getStudentNumber(lines);

    for (auto turma: classlist) {

        if (turma.getStudentNumber(lines) < min && turma.getUcCode() == ucCode_) {

            min = turma.getStudentNumber(lines);

        }
    }

    return min;
}

void Uc::print_horario_uc_code(vector<Read_line> lines){
    change_horarios_uc(lines);

    cout << endl;


    cout << "______________________________________________________________________________________________________" <<endl;
    cout << "|                                        SCHEDULE OF " << ucCode_ << "                                        |" <<endl;
    cout << "|____________________________________________________________________________________________________|" <<endl;
    cout << "|    Weekday   |   classCode   |      Type      |    StartHour    |     EndHour     |    Duration    |" <<endl;
    cout << "|______________|_______________|________________|_________________|_________________|________________|" <<endl;
    int i = 0;
    for(Aula aula : horario_uc) {
        if(aula.get_weekDay() == "Monday" && i == 0){
            i++;
            cout << "|Monday        |" << left << setw(15) << aula.get_classCode() << "|" << left << setw(16) << aula.get_type() << "|" << left << setw(17) << aula.get_startHour() << "|" << left << setw(17) << aula.get_endingTime() << "|" << left << setw(16) << aula.get_duration() << "|" <<endl;
        } else if (aula.get_weekDay() == "Monday" && i != 0){
            cout << "|              |_______________|________________|_________________|_________________|________________|" <<endl;
            cout << "|              |" << left << setw(15) << aula.get_classCode() << "|" << left << setw(16) << aula.get_type() << "|" << left << setw(17) << aula.get_startHour() << "|" << left << setw(17) << aula.get_endingTime() << "|" << left << setw(16) << aula.get_duration() << "|" <<endl;
        }
    }

    cout << "|______________|_______________|________________|_________________|_________________|________________|" <<endl;
    i = 0;
    for(Aula aula : horario_uc) {
        if(aula.get_weekDay() == "Tuesday" && i == 0){
            i++;
            cout << "|Tuesday       |" << left << setw(15) << aula.get_classCode() << "|" << left << setw(16) << aula.get_type() << "|" << left << setw(17) << aula.get_startHour() << "|" << left << setw(17) << aula.get_endingTime() << "|" << left << setw(16) << aula.get_duration() << "|" <<endl;
        } else if (aula.get_weekDay() == "Tuesday" && i != 0){
            cout << "|              |_______________|________________|_________________|_________________|________________|" <<endl;
            cout << "|              |" << left << setw(15) << aula.get_classCode() << "|" << left << setw(16) << aula.get_type() << "|" << left << setw(17) << aula.get_startHour() << "|" << left << setw(17) << aula.get_endingTime() << "|" << left << setw(16) << aula.get_duration() << "|" <<endl;
        }
    }

    cout << "|______________|_______________|________________|_________________|_________________|________________|" <<endl;
    i = 0;
    for(Aula aula : horario_uc) {
        if(aula.get_weekDay() == "Wednesday" && i == 0){
            i++;
            cout << "|Wednesday     |" << left << setw(15) << aula.get_classCode() << "|" << left << setw(16) << aula.get_type() << "|" << left << setw(17) << aula.get_startHour() << "|" << left << setw(17) << aula.get_endingTime() << "|" << left << setw(16) << aula.get_duration() << "|" <<endl;
        }else if (aula.get_weekDay() == "Wednesday" && i != 0){
            cout << "|              |_______________|________________|_________________|_________________|________________|" <<endl;
            cout << "|              |" << left << setw(15) << aula.get_classCode() << "|" << left << setw(16) << aula.get_type() << "|" << left << setw(17) << aula.get_startHour() << "|" << left << setw(17) << aula.get_endingTime() << "|" << left << setw(16) << aula.get_duration() << "|" <<endl;
        }
    }

    cout << "|______________|_______________|________________|_________________|_________________|________________|" <<endl;
    i = 0;
    for(Aula aula : horario_uc) {
        if(aula.get_weekDay() == "Thursday" && i == 0){
            i++;
            cout << "|Thursday      |" << left << setw(15) << aula.get_classCode() << "|" << left << setw(16) << aula.get_type() << "|" << left << setw(17) << aula.get_startHour() << "|" << left << setw(17) << aula.get_endingTime() << "|" << left << setw(16) << aula.get_duration() << "|" <<endl;
        }else if (aula.get_weekDay() == "Thursday" && i != 0){
            cout << "|              |_______________|________________|_________________|_________________|________________|" <<endl;
            cout << "|              |" << left << setw(15) << aula.get_classCode() << "|" << left << setw(16) << aula.get_type() << "|" << left << setw(17) << aula.get_startHour() << "|" << left << setw(17) << aula.get_endingTime() << "|" << left << setw(16) << aula.get_duration() << "|" <<endl;
        }
    }

    cout << "|______________|_______________|________________|_________________|_________________|________________|" <<endl;
    i = 0;
    for(Aula aula : horario_uc) {
        if (aula.get_weekDay() == "Friday" && i == 0) {
            i++;
            cout << "|Friday        |" << left << setw(15) << aula.get_classCode() << "|" << left << setw(16) << aula.get_type() << "|" << left << setw(17) << aula.get_startHour() << "|" << left << setw(17) << aula.get_endingTime() << "|" << left << setw(16) << aula.get_duration() << "|" << endl;
        } else if (aula.get_weekDay() == "Friday" && i != 0) {
            cout << "|              |_______________|________________|_________________|_________________|________________|" << endl;
            cout << "|              |" << left << setw(15) << aula.get_classCode() << "|" << left << setw(16) << aula.get_type() << "|" << left << setw(17) << aula.get_startHour() << "|" << left << setw(17) << aula.get_endingTime() << "|" << left << setw(16) << aula.get_duration() << "|" << endl;
        }
    }
    cout << "|______________|_______________|________________|_________________|_________________|________________|" <<endl;
};



