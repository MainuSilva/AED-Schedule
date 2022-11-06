#ifndef UNTITLED_UC_H
#define UNTITLED_UC_H

#include <string>
#include "Horario.h"
#include <iostream>
#include "Aula.h"
#include "Turma.h"

using namespace std;

class Uc {

private:

    std::string ucCode_;

public:
    Uc(string ucCode);

    vector<Aula> get_horarios_uc_turma(std :: string classCode, vector<Read_line> lines);

    vector<Aula> get_horario_uc(vector<Read_line> lines);

    int get_number_students(vector<Read_line> lines);

    vector<Aula> get_horarios_turma_without_T(std:: string classCode, vector<Read_line> lines);

    string get_class_Code(vector<Read_line> lines);

    void print_horario_uc_code(vector<Read_line> lines);

    int defineCap(vector<Read_line> lines, vector<Turma> classlist );

    vector<Turma> classList(vector<Read_line> lines);

    int highStudentIndex(vector<Read_line> classes, int index);

    int lowStudentIndex(vector<Read_line> classes, int index);

    vector<Read_line> find_uc(vector<Read_line> classes, int index);
};



#endif //UNTITLED_UC_H
