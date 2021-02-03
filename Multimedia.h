#include <string>
#include <iostream>
#ifndef MULTIMEDIA_H
#define MULTIMEDIA_H

class Multimedia  
{
	private:
		std::string name;
		std::string file_name;


	public:

		Multimedia():name{""}, file_name{""}{}

		Multimedia(std::string name, std::string file_name):
		name{name}, file_name{file_name}{}

		virtual ~Multimedia(){std::cerr<<"destructeur multimedia";}


		std::string getName() const {return name;}

		std::string getFileName() const {return file_name;}

		void setName(std::string name_){name=name_;}

		void setFileName(std::string file_name_){file_name=file_name_;}

		virtual void showValues(std::ostream& stream) const;
		// sends the values of the instance variables to a stream

		virtual void play() const{};
};

#endif
