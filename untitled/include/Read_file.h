#ifndef UNTITLED_READ_FILE_H
#define UNTITLED_READ_FILE_H

#include "Read_line.h"
#include <vector>
#include <fstream>

class Read_file {
public:
    Read_file();
    std::vector<Read_line> read(std::string fileName, bool hasHeader = false);
};


#endif //UNTITLED_READ_FILE_H
