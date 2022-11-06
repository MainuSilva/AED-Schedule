#ifndef UNTITLED_TURMA_H
#define UNTITLED_TURMA_H

#include <ostream>
#include <string>
#include <list>
#include "Horario.h"
#include "Aula.h"


class Turma {

private:
    std::string classCode_;
    std::string ucCode_;


public:
    Turma(string classCode, string ucCode);

    Turma(std::string classCode);

    vector<Aula> get_horario_turma(std::vector<Read_line> lines);

    void print_horario_class_code( vector<Aula> horario);

    int getStudentNumber(vector<Read_line> lines);

    const string &getClassCode() const;


};


#endif //UNTITLED_TURMA_H
