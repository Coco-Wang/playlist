#include "playlist.h"
#include <cstring>
#include <iostream>
#include <cctype>
#include <iomanip>
using namespace std;

Playlist::Playlist()
{
        maxsize = 5;
        current = 0;
        songlist = new Song[maxsize];
}

Playlist::~Playlist()
{
        delete[] songlist;
}

void Playlist::Addsong(const Song newsong)
{
        if (current == maxsize)
                grow();
        songlist[current++]=newsong;
}

void Playlist::Deletesong(const char* t)
{
        int thissong = Find(t, 'T');
        if (thissong == -1)
        {
                cout << "* No deletion performed *";
                return;
        }
        else
        {
                for (int j = thissong + 1; j < current; j++)
                        songlist[j - 1] = songlist[j];
                current--;
                cout << "Song removed!";
        }
}

void Playlist::Summary() const
{
        cout << left;
        cout << setw(30) << "*Title*";
        cout << setw(20) << "*Artist*";
        cout << setw(15) << "*Style*";
        cout << right;
        cout << setw(10) << "*Size(MB)" << "*\n";
        cout << endl;

        int totalsize = 0;
        for (int i = 0; i < current; i++)
                songlist[i].Display();

        for (int i = 0; i < current; i++)
                totalsize = totalsize + songlist[i].GetSize();

        double ts = totalsize*0.001;
        cout << "\n"<<"Number of songs = " << current;

        int oldprecision = cout.precision();
        cout << "\n" << "Total playlist Size = "
                << setprecision(2) << ts << " "<<"MB";
        cout.precision(oldprecision);
}
void Playlist::Lookup(const char* t) const
{
        int tsong = Find(t, 'T');
        int rsong=Find(t, 'A');
        for (int i = 0; i < current;i++)
            if (tsong != -1)
            {
                    cout << "Song Found: \n";
                    songlist[tsong].Display();
            }
            else if ((tsong == -1) && (rsong != -1))
            {
                    cout << "Song Found: \n";
                    songlist[rsong].Display();
            }
            else
                    cout <<": Not Found";
}
void Playlist::Catetotal(const Style x) const
{
        int total = 0;
        int sum = 0;
        for (int i = 0; i < current; i++)
        {
                if (songlist[i].GetCategory() == x)
                {
                        songlist[i].Display();
                        total = total + i;
                        sum = sum + songlist[i].GetSize();
                }
        }
        cout << "\n";
        cout << "Total songs in this category = " << total <<endl;


        double sm = sum*0.001;

        int oldprecision = cout.precision();
        cout <<  setw(10) << setprecision(2)<< "Total file size = " << sm <<" MB";
        cout.precision(oldprecision);
}

void Playlist::grow()
{

        maxsize = current + 5;
        cout << "** Array being resized to" << maxsize << "allocated slots**";
        Song *temp = new Song[maxsize];
        for (int i = 0; i < current; i++)
                temp[i] = songlist[i];
        delete[] songlist;
        songlist = temp;
}



void Playlist::Sizetotal() const
{
        int size = 0;
        for (int i = 0; i < current; i++)
                size = size + songlist[i].GetSize();
        cout << "Total size of playlist = "
                << size << " kilobytes";
}
int Playlist::Find(const char* t, const char field) const
{
        if (field == 'T')
        {
                for (int i = 0; i < current; i++)
                        if (strcmp(songlist[i].GetTitle(), t) == 0)
                            return i;
                return -1;
        }

        if (field == 'A')
        {
                for (int i = 0; i < current; i++)
                        if (strcmp(songlist[i].GetArtist(), t) == 0)
                                return i;
                return -1;
        }
}
void Playlist::Sort(const char field) const
{
        Song t;
        int flag=1;
        if (field == 'T')
        {
                for (int i = 1; (i <= current) && flag; i++)
                {
                        flag = 0;
                        for (int j = 0; j < current - 1; j++)
                        {
                                if (songlist[j].GetTitle()[0] > songlist[j + 1].GetTitle()[0])
                                {
                                        t = songlist[j];
                                        songlist[j] = songlist[j + 1];
                                        songlist[j + 1] = t;
                                        flag = 1;
                                }

                        }
                }
                cout << "**Sorted by Title**"<<endl;
        }

   flag = 1;
   if (field == 'A')
   {
         for (int i = 1; (i <= current) && flag; i++)
         {
             flag = 0;
             for (int j = 0; j < current - 1; j++)
                {
                  if (songlist[j].GetArtist()[0]>songlist[j+1].GetArtist()[0])
                     {
                        t = songlist[j];
                        songlist[j] = songlist[j + 1];
                        songlist[j + 1] = t;
                        flag = 1;
                      }
                 }

          }
          cout << "**Sorted by Artist**"<< endl;
   }

}

