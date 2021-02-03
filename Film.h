#ifndef FILM_H
#define FILM_H
#include "Video.h"

class Film : public Video
{
	private:
		int * chapters{};
		int nb_chapters{};

		
	public:

		Film(std::string name , std::string file_name, int * chapters_, int nb_chapters_) : Video(name,file_name,0)
		{	

			changeChapters(chapters_, nb_chapters_ );

			int total_length=0;
			for (int i = 0; i <nb_chapters ; i++)
			{
				total_length+=chapters[i];
			}
			

			setLength(total_length);
		}

		Film(const Film &f) : Video(f.getName(), f.getFileName(), f.getLength() ){ // constructeur par recopie
			changeChapters(f.chapters, f.nb_chapters);

		}

		const Film & operator=(const Film &f){ // operateur d'affectation =
			
			this->setName(f.getName());
			this->setFileName(f.getFileName());
			this->setLength(f.getLength());
			changeChapters(f.chapters, f.nb_chapters);
			
			return *this;
		}
		

		~Film(){
			delete[] chapters;
		}



		void changeChapters(int * chapters_, int nb_chapters_){
			delete[] chapters;

			nb_chapters=nb_chapters_;
			chapters = new int [nb_chapters];
			for(int i =0; i<nb_chapters; ++i){
				chapters[i] = chapters_[i];
			}
		}

};
 
/*Film var("film1", ...);

Film var2(var); constructeur par recopie
Film var2 = var;

Film var3("film2", ...);
var3=var2; operateur d'affectation (=)*/


#endif
