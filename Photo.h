#include "Multimedia.h"
#ifndef Photo_
#define Photo_


class Photo : public Multimedia
{
private:
	float latitude{};
	float longitude{};

public:
	Photo(std::string name = "", std::string file_name = "", float latitude = 0.0, float longitude = 0.0) :
	 Multimedia(name, file_name), latitude{latitude}, longitude{longitude} {}



	float getLatitude() const {return latitude;}

	float getLongitude() const {return longitude;}

	void setLatitude(float latitude_) {latitude = latitude_;}

	void setLongitude(float longitude_) {longitude = longitude_;}


	void showValues(std::ostream& stream) const override{
    stream
    << "Name: " << getName() << "\n"
    << "File Name: " << getFileName() << "\n"
	<< "Latitude: " << latitude << "\n"
	<< "Longitude: " << longitude << "\n" << std::endl;
	}

	
	void play() const override{
		std::string cmd = "imagej " + getFileName() + " &";
		std::system(  cmd.c_str() );
	}

};

#endif