#ifndef _SONG_H
#define _SONG_H

enum Style { POP, ROCK, ALTERNATIVE, COUNTRY, HIPHOP, PARODY };

class Song
{
public:
        Song();         // default constructor, sets up blank song object
        void Set(const char* t, const char* a, Style st, int sz);
        const char* GetTitle() const;           // returns the title stored in the object
        const char* GetArtist() const;  // returns the artist
        int GetSize() const;                    // returns the file size in kilobytes
        Style GetCategory() const;              // returns the song category
        void Display() const;                   // described below

private:
        char title[36]; // may assume title is 35 characters or less
        char artist[21];        // may assume artist name is 20 characters or less
        Style category; // style of the given song
        int size;               // file size, stored in kilobytes
};
#endif
