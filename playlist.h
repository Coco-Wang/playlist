#include "song.h"


class Playlist
{
public:
        Playlist();
        ~Playlist();
        void Addsong(const Song newsong);
        void Deletesong(const char* target);
        void Summary() const;
        void Lookup(const char *target) const;
        void Catetotal(const Style x) const;
    void Sizetotal() const;
        void Sort(const char field) const;


private:
     int maxsize;
        int current;
        Song *songlist;
        void grow();
        int Find(const char *target
