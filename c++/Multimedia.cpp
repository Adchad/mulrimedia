#include "Multimedia.h"  

void Multimedia::showValues(std::ostream& stream) const {
    stream
    << "Name: " << name << "\n"
    << "File Name: " << file_name << std::endl;
}