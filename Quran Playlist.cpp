#include <iostream>
#include <conio.h>
#include"mainFunctions.h"
using namespace std;

int main()
{
    AllPlaylists Givenplaylist;
    cout << "\t\t\t\t\t\t\tQuraan Playlist Manager Simulation System\n" << endl;
    while (true)
    {
        ShowMenu();
        cout << "Enter your choice : ";
        int choice;
        cin >> choice;
        system("cls");
        switch (choice)
        {
        case 1:
            AddPlaylist(Givenplaylist);
            break;
        case 2:
            AddSurahtoExistingPlaylist(Givenplaylist);
            break;
        case 3:
            RemoveSurah(Givenplaylist);
            break;
        case 4:
            UpdateOrder(Givenplaylist);
            break;
        case 5:
            DisplayPlaylists(Givenplaylist);
            break;
        case 6:
            DisplayPlaylistsSurah(Givenplaylist);
            break;
        case 7:
            DisplaySurahFromSpecificPlaylist(Givenplaylist);
            break;
        case 8:
            PlaySurahFromPlaylist(Givenplaylist);
            break;
        case 9:
            SavePlaylist(Givenplaylist);
            break;
        case 10:
            Load(Givenplaylist);
            break;
        case 11:
            RemovePlaylist(Givenplaylist);
            break;
        case 12:
            system("cls");
            return 0;
        default:
            cout << "Invalid Choice :(  Please Try Again )" << endl << endl;
        }
    }
    return 0;
}