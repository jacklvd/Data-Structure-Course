#ifndef TVSHOW_H
#define TVSHOW_H

#include "Show.h"
#include <cstring>

class TVshow: public Show {
  protected:
    int seasons;
    int episodes;
    Show* seArray[][24];
  
  public:
    // Constructor
    TVshow();
    TVshow(int, int, string, string);
    // Getter and Setter functions
    int getSeasons();
    int getEpisodes();
    void setSeasons(int);
    void setEpisodes(int);
    void setse(int, int);  
    // Other functions  
    void showdetails();
    void Play();
};

#endif