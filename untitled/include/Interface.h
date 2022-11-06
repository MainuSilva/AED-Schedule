#ifndef UNTITLED_INTERFACE_H
#define UNTITLED_INTERFACE_H

#include "Read_line.h"
#include <vector>
#include "Turma.h"
#include "Horario.h"
#include "Uc.h"
#include "Read_line.h"
#include "Read_file.h"
#include "Aula.h"
#include "Pedido_troca.h"

class Interface{
private:
    vector<Read_line> classesCsv_lines_;
    vector<Read_line> classes_per_uc_lines_;
    vector<Read_line> student_classes_lines_;

    bool end_prog; // para terminar o programa se estiver true;

    bool login;
    string username;

    set<string> all_UCs; // saber o set de cada (útil)
    set<string> all_students;
    set<string> all_classes;

    vector<vector<Pedido_troca>> double_request; //vetor analisado no final
    vector<Pedido_troca> one_request;

    vector<vector<Pedido_troca>> accepted_two_students;
    vector<Pedido_troca> accepted_one_student;

    vector<Pedido_troca> refused_requests;
    vector<vector<Pedido_troca>> refused_two_students;



public:
    Interface (vector<Read_line> classesCsv_lines, vector<Read_line> classes_per_uc_lines, vector<Read_line> student_classes_lines);

    static bool verifyExit();
    void showMenu();
    void uc_Info();
    void list_Ucs();
    void get_UcSchedule();
    void number_Students_Uc();
    void list_All_Ucs();
    void list_By_Year_UC();

    void class_Info();
    void list_Classes();
    void class_Schedule();
    void number_Students_Class();
    void show_Classes_UC();
    void show_All_Classes();
    void show_Classes_Year();

    void student_Info();
    void list_UcStudents();
    void get_StudentSchedule();
    void list_Students();
    void list_Class_Students();
    void list_All_Students(string input, string value_1 = "", string value_2 = "");
    void alphabetic_Order(string input, string value_1 = "", string value_2 = "");
    void ascending_Order(string input, string value_1 = "", string value_2 = "");
    void descending_Order(string input, string value_1 = "", string value_2 = "");
    void number_Of_Ucs();

    void class_Permute();
    void only_One_Std();
    void bet_Two_Std();
    void process_Changes();

    string find_Up();
    string find_UC();
    string find_Class();
};
#endif //UNTITLED_INTERFACE_H
