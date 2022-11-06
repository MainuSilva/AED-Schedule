#include "../include/Horario.h"
#include "../include/Read_file.h"

Horario::Horario() = default;

Horario::Horario(vector<Aula> horario){
    horario_ = horario;
}
//Percorre linha em linha, comparando o código de uma determinada coluna do ficheiro classes.csv para adicionar no vetor de aulas (Horario)

Horario::Horario(std::vector<Read_line> lines, string code, int num){
    for (auto line : lines) {
        if(line.getString(num) == code){
            Aula aula(line);                // cria uma nova aula com a line
            horario_.push_back(aula);      //e adiciona no vetor de aulas horario
        }
    }
}

//Getters
vector<Aula> Horario::get_horario(){
    return horario_;
}

void Horario::add_class(std::vector<Read_line> lines, string classCode, string ucCode){

    for (auto line : lines) {

        if((line.getString(0) == classCode) && (line.getString(1) == ucCode)){

            Aula aula(line);                // cria uma nova aula com a line
            horario_.push_back(aula);      //e adiciona no vetor de aulas horario
        }
    }
}

