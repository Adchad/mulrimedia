#include "Multimedia.h"
#ifndef VIDEO_H
#define VIDEO_H

class Video : public Multimedia
{
private:
	int length{};

public:
	Video(std::string name = "", std::string file_name = "", int length = 0) :
	 Multimedia(name, file_name), length{length} {}



	int getLength() const {return length;}

	void setLength(int length_) {length = length_;}


	void showValues(std::ostream& stream) const override {
    stream
    << "Name: " << getName() << "\n"
    << "File Name: " << getFileName() << "\n"
	<< "Length: " << length << "\n" <<std::endl;
	}


	void play() const override{

		std::string cmd = "mpv " + getFileName() + " >/dev/null 2>&1 &";
		std::system(  cmd.c_str() );
	}
};

#endif
