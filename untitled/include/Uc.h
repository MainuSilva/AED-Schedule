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
    vector<Aula> horario_uc;

public:

    Uc(string ucCode);

    void change_horarios_uc(vector<Read_line> lines);

    vector<Aula> get_horarios_uc_turma(std::vector<Read_line> lines, string classCode);

    vector<Aula> get_horario_uc();

    int get_number_students(vector<Read_line> lines);

    vector<Aula> get_horarios_turma_without_T(vector<Read_line> lines, string classCode);

    string get_class_Code(vector<Read_line> lines);

    void print_horario_uc_code(vector<Read_line> lines);

    int defineCap(vector<Read_line> lines, vector<Turma> classlist );

    int defineMin(vector<Read_line> lines, vector<Turma> classlist );

    vector<Turma> classList(vector<Read_line> lines);
};



#endif //UNTITLED_UC_H
