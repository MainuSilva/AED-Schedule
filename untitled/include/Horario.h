#ifndef UNTITLED_HORARIO_H
#define UNTITLED_HORARIO_H

#include <vector>
#include <set>
#include "Aula.h"
#include "Read_line.h"

/**
 * @brief Classe que representa o horário
 */
class Horario {
private:

    /// Horário
    std::vector<Aula> horario_;

public:
    /**
     * @brief Default Constructor da classe
     */
    Horario();

    /**
     * @brief Constructor da classe
     * Complexidade temporal: O(1)
     * @param horario : Horário
     */
    Horario(vector<Aula> horario);

    /**
     * @brief Outro Constructor da classe
     * Percorre linha em linha, comparando o código de uma determinada coluna do ficheiro classes.csv para adicionar no vetor de aulas (Horario)
     * Complexidade temporal: O(n) sendo n o número de linhas de classes.csv
     * @param lines : vetor com todas as linhas do ficheiro classes.csv
     * @param code : classCode ou ucCode
     * @param num : número da coluna a consultar
     */
    Horario(std::vector<Read_line> lines, string code, int num);

    /**
     * @brief Getter para horário
     * Complexidade temporal: O()
     * @return O horário
     */
    vector<Aula> get_horario();

    void add_class(std::vector<Read_line> lines, string classCode, string ucCode);

};

#endif //UNTITLED_HORARIO_H
