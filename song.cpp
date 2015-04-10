#include <iostream>
#include <cstring>
#include <iomanip>
#include "song.h"

using namespace std;

Song::Song()
{
        strcpy(title, " ");
        strcpy(artist, " ");
        size = 0;
        category = ALTERNATIVE;
}

void Song::Set(const char* t, const char* a, Style st, int sz)
{
        for (int i = 0; i < 36;i++)
            title[i]=t[i];
        for (int i = 0; i < 21;i++)
            artist[i]=a[i];
        category = st;
        size = sz;
}


const char* Song::GetTitle() const
{
        return title;
}

const char* Song::GetArtist() const
{
        return artist;
}


int Song::GetSize() const
{
        return size;
}

Style Song::GetCategory() const
{
        return category;
}

void Song::Display() const
{


        cout << left;
        cout << setw(30) << title;
        cout << setw(20) << artist;
        cout << setw(15);
        switch (category)
        {
        case POP:                  cout << "Pop";       break;
        case ROCK:                 cout << "Rock";      break;
        case ALTERNATIVE:          cout << "Alt";       break;
        case COUNTRY:              cout << "Ctry";      break;
        case HIPHOP:               cout << "HH";        break;
        case PARODY:               cout << "Par";       break;
        }

        double sz;
        sz = size*0.001;
        cout << right << setw(10) << setprecision(1)<<fixed;
        cout << sz << "\n";
}
