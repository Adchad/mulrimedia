#include "Multimedia.h"  
#include <list>
#include <memory>

#ifndef GROUP_MULTI_H
#define GROUP_MULTI_H

typedef std::shared_ptr<Multimedia> MultimediaPtr;

class GroupMulti : public std::list<MultimediaPtr>
{
private:
    
    std::string name;

public:

    GroupMulti():list<MultimediaPtr>(),name{""}{}

	GroupMulti(std::string name): list<MultimediaPtr>(),
        name{name}{}

     ~GroupMulti(){std::cout<< "test";}

    std::string getName() const {return name;} 
    

    void showValues(std::ostream& stream){
        std::list<MultimediaPtr>::iterator it;
        for(it = this->begin(); it != this->end(); ++it ){
            (*it)->showValues(std::cout);
        }
    }
};

#endif
