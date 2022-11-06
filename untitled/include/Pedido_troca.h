#ifndef UNTITLED_PEDIDO_TROCA_H
#define UNTITLED_PEDIDO_TROCA_H
#include <ostream>
#include <string>

#include "Read_line.h"
#include "Turma.h"
#include "Estudante.h"

using namespace std;

class Pedido_troca {
private:
    Estudante student_;
    string atual_classCode_;
    string ucCode_;
    string new_classCode_;

public:
    Pedido_troca(Estudante student, string atual_classCode, string ucCode, string new_classCode);

//Getters
    const string &getUcCode() const;
    const string &getNewClassCode() const;
    string getStudentName(vector<Read_line> lines);
    string getStudentCode();

    bool can_student_switch_without_sobreposing_TP_PL(vector<Read_line> student_classes_lines_, vector<Read_line> classesCsv_lines_);
    bool can_student_switch_without_passing_cap(vector<Read_line> student_classes_lines_);
    bool can_student_switch_without_causing_uc( vector<Read_line> student_classes_lines_);
    bool can_student_switch(vector<Read_line> student_classes_lines_, vector<Read_line> classesCsv_lines_);


};

#endif //UNTITLED_PEDIDO_TROCA_H
