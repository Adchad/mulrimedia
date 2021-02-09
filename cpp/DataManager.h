#ifndef DATA_MANAGER_H
#define DATA_MANAGER_H

#include "Photo.h"
#include "Video.h"
#include "Film.h"
#include "GroupMulti.h"
#include <map>
#include <string>
#include <memory>

class DataManager
{
	private:
        std::map<std::string, std::shared_ptr<Multimedia>> multimedia_table;
        std::map<std::string, GroupMulti> group_table;

		
	public:

		DataManager(): multimedia_table{}, group_table{} {}

        std::shared_ptr<Photo> addPhoto(std::string name, std::string file_name, float latitude, float longitude){
            std::shared_ptr<Photo> temp(new Photo(name, file_name, latitude, longitude));

            multimedia_table[name] = temp;

            return temp;
        }


        std::shared_ptr<Video> addVideo(std::string name, std::string file_name, float length){
            std::shared_ptr<Video> temp(new Video(name, file_name, length));

            multimedia_table[name] = temp;

            return temp;
        }


        std::shared_ptr<Film> addFilm(std::string name, std::string file_name, int * chapters, int nb_chapters){
            std::shared_ptr<Film> temp(new Film(name, file_name, chapters, nb_chapters));

            multimedia_table[name] = temp;

            return temp;
        }


        GroupMulti addGroup(std::string name){
            GroupMulti temp(name);

            group_table[name] = temp;

            return temp;
        }

        void findMultimedia(std::string name, std::ostream& stream ){
            auto it = multimedia_table.find(name);

            if(it != multimedia_table.end()){
                   it->second->showValues(stream); 
            }
            else{
                stream << "L'objet cherché n'existe pas :(" << std::endl;
            }

            
        }

        void findGroup(std::string name,std::ostream& stream){
            auto it = group_table.find(name);

            if(it != group_table.end()){
                   it->second.showValues(stream); 
            }
            else{
                stream << "Le groupe cherché n'existe pas" << std::endl;
            }
        }

        
        void play(std::string name, std::ostream& stream){
            auto it = multimedia_table.find(name);

            if(it != multimedia_table.end()){
                   it->second->play(); 
                   stream << "Playing..."<<std::endl;
            }
            else{
                stream << "L'objet cherché n'existe pas :(" << std::endl;
            }
        }


};

#endif
