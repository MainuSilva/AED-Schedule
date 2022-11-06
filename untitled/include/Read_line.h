#ifndef UNTITLED_READ_LINE_H
#define UNTITLED_READ_LINE_H

#include <string>
#include <sstream>
#include <vector>

using namespace std;

class Read_line {
private:
    vector<string> values;
public:
    Read_line();
    Read_line(const Read_line& other);
    void parse(string line, char end_line = ',');
    string getString(int column);
    double getDouble(int column);
    void change_Value(string new_value, int column);

    int getInt(int column);
};


#endif //UNTITLED_READ_LINE_H
