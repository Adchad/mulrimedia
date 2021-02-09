//
// main.cpp
// Created on 21/10/2018
//

#include "Multimedia.h"
#include "Video.h"
#include "Photo.h"
#include "Film.h"
#include "GroupMulti.h"
#include "DataManager.h"

#include <memory>
#include <string>
#include <iostream>
#include <sstream>
#include "tcpserver.h"

const int PORT = 3331;

using namespace std;

stringstream search(string name);

stringstream query(const string& request);

stringstream play(string name);

DataManager dataManager;


int main(int argc, const char *argv[])
{
    //DATA BASE
    int test_array[2] = {1,2};

    shared_ptr<Film> film1(new Film("film1","test", test_array, 2));
    shared_ptr<Film> film2(new Film("film2","test", test_array, 2));

    shared_ptr<Video> video1(new Video("video1", "videoplayback.mp4", 1));

    shared_ptr<Photo>  photo1(new Photo("photo1", "photo", 1,1));


    GroupMulti * group1 = new GroupMulti("Group1");
    GroupMulti * group2 = new GroupMulti("Group2");


    group1->push_back(film1);
    group1->push_back(video1);
    group1->push_back(photo1);

    group2->push_back(film1);
    group2->push_back(film2);


    //group1->showValues(cout);

    

    shared_ptr<Video> video1_table = dataManager.addVideo("compte-a-rebourd", "videoplayback.mp4", 1);
    shared_ptr<Photo> photo1_table = dataManager.addPhoto("Capture", "Capture.png", 100,200);

    //dataManager.play("compte-a-rebourd");

    
    //SERVER
    // cree le TCPServer
     auto* server =
     new TCPServer( [&](std::string const& request, std::string& response) {

       // the request sent by the client to the server
      // std::cout << "request: " << request << std::endl;

       stringstream queryResponse= query(request);

       // the response that the server sends back to the client
       string temp;
       string finalResponse;
       while(getline(queryResponse, temp)){
          finalResponse += temp +";" ; 
       }
        
       response = finalResponse;
       // return false would close the connecytion with the client
       return true;
     });


     // lance la boucle infinie du serveur
     std::cout << "Starting Server on port " << PORT << std::endl;

     int status = server->run(PORT);

     // en cas d'erreur
     if (status < 0) {
       std::cerr << "Could not start Server on port " << PORT << std::endl;
       return 1;
     }
    return 0;
}

stringstream query(const string& request){
  stringstream ss;
  stringstream ss2; 
  ss<< request<<endl;

  string queryName, name;

  ss >> queryName >> name;

  cout<< "query name: "<<queryName << "\n" << "name : " <<name<<endl;

  if(queryName=="search"){
    ss2 = search(name);
  }
  else if(queryName=="play"){
    ss2 = play(name);
  }

  else{
    ss2 << "Mauvaise commande ! :("<<endl;
  }

  

  return ss2;
}

stringstream search(string name){
  stringstream ss;
  dataManager.findMultimedia(name, ss);
  //dataManager.findMultimedia(name, cout);
 
  return ss;
}

stringstream play(string name){
  stringstream ss;
  dataManager.play(name, ss);
  //dataManager.findMultimedia(name, cout);
 
  return ss;
}
