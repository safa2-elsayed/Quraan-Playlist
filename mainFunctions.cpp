#include "AllPlaylists.h"
#include "mainFunctions.h"
#include <fstream>
void ShowMenu()
{
	cout << "\t\t\t\t\t\t ==============================================================\n"
		<< "\t\t\t\t\t\t|                Quran Playlist Management Menu                |\n"
		<< "\t\t\t\t\t\t|--------------------------------------------------------------|\n"
		<< "\t\t\t\t\t\t| 1. Add a New Playlist                                        |\n"
		<< "\t\t\t\t\t\t| 2. Add Surah To an Existing Playlist                         |\n"
		<< "\t\t\t\t\t\t| 3. Remove Surah From an Existing Playlist                    |\n"
		<< "\t\t\t\t\t\t| 4. Update The Order Of Existing Playlist                     |\n"
		<< "\t\t\t\t\t\t| 5. Display All Current Playlists                             |\n"
		<< "\t\t\t\t\t\t| 6. Display All Playlists Surah                               |\n"
		<< "\t\t\t\t\t\t| 7. Display Surah In Specific Playlist                        |\n"
		<< "\t\t\t\t\t\t| 8. Play Surah From Specific Playlist                         |\n"
		<< "\t\t\t\t\t\t|    Use Left Arrow (<-) To Play The Previous Surah            |\n"
		<< "\t\t\t\t\t\t|    Use Right Arrow (->) To Play The Next Surah               |\n"
		<< "\t\t\t\t\t\t|    Use Up Arrow (^) To Pause The Current Surah               |\n"
		<< "\t\t\t\t\t\t|    Use down Arrow (v) To Resume The Current Surah            |\n"
		<< "\t\t\t\t\t\t| 9. Save an Existing Playlist To File                         |\n"
		<< "\t\t\t\t\t\t| 10. Load an Existing Playlist From a File                    |\n"
		<< "\t\t\t\t\t\t| 11. Remove an Existing Playlist                              |\n"
		<< "\t\t\t\t\t\t| 12. Exit                                                     |\n"
		<< "\t\t\t\t\t\t ==============================================================\n";
}
void AddPlaylist(AllPlaylists& all)
{
	cout << "Playlist Name ? ";
	string name;
	cin >> name;
	Playlist playlist(name);
	all.AddPlaylist(playlist);
	cout << "Playlist " << name << " Added Succesfully" << endl;
}
void AddSurahtoExistingPlaylist(AllPlaylists& all)
{
	char choice;
	all.DisplayPlaylists();
	cout << "Which Playlist ? ";
	string name, suraName, SuraType, suraPath;
	cin >> name;
	do
	{
		cout << "Name Of Surah ? ";
		cin >> suraName;
		cout << "Type Of Surah ? ";
		cin >> SuraType;
		cout << "Path Of Surah ? ";
		getline(cin, suraPath);
		getline(cin, suraPath);
		Playlist playlist(name);
		Surah surah(suraName, SuraType, suraPath);
		all.getPlaylists().search(playlist).AddSurah(surah);
		cout << suraName << " Added Succesfully!!" << endl;
		cout << "Do You Want To Add Another Surah ? (y/n) ";
		cin >> choice;
	} while (choice != 'n');
}
void RemoveSurah(AllPlaylists& all)
{
	all.DisplayPlaylists();
	cout << "Which Playlist ? ";
	string name;
	cin >> name;
	string surahName;
	cout << "Surah Name ? ";
	cin >> surahName;
	all.getPlaylists().search(name).RemoveSurah(surahName);
	cout << "Removed Succesfully" << endl;
}
void UpdateOrder(AllPlaylists& all)
{
	all.DisplayPlaylists();
	cout << "Which Playlist ? ";
	string name;
	int pos;
	cin >> name;
	string surahName;
	cout << "Surah Name ? ";
	cin >> surahName; 
	cout << "New Position ? ";
	cin >> pos;
	all.getPlaylists().search(name).ReorderSurahPosition(surahName,pos);
	cout << "Updated Succesfully" << endl;
}
void DisplayPlaylistsSurah(AllPlaylists& all)
{
	all.DisplayPlaylistsWithSurahs();
}
void DisplaySurahFromSpecificPlaylist(AllPlaylists& all)
{
	all.DisplayPlaylists();
	cout << "Which Playlist ? ";
	string name;
	cin >> name;
	all.getPlaylists().search(name).DisplayPlaylist();
}
void DisplayPlaylists(AllPlaylists& all)
{
	all.DisplayPlaylists();
}
void PlaySurahFromPlaylist(AllPlaylists& all)
{
	all.DisplayPlaylists();
	cout << "Which Playlist ? ";
	string name;
	cin >> name;
	all.getPlaylists().search(name).PlaySurah();
}
void SavePlaylist(AllPlaylists& all)
{
	all.DisplayPlaylists();
	cout << "Which Playlist ? ";
	string name;
	cin >> name;
	Playlist p(name);
	Playlist playlist = all.getPlaylists().search(p);
	fstream inSize;
	inSize.open("size.txt", ios::in);
	string size;
	if (inSize.is_open())
	{
		inSize >> size;
		if (size.empty())
			playlist.setSavedSize(0);
		else
		{
			int size2 = toInt(size);
			playlist.setSavedSize(size2);
		}
	}
	fstream out;
	out.open("Playlists.txt", ios::app);
	if (out.is_open())
	{
		out << playlist.getPlaylistName() << endl;
		out << playlist.getSize() << endl;
		Node<Surah>* current = playlist.getPlayList().getHead();
		while (current)
		{
			out << current->data.getName() << endl;
			out << current->data.getType() << endl;
			out << current->data.getPath() << endl;
			out << "++++++++++++++++++++++++++++++++++++" << endl;
			current = current->next;
		}
		out << "------------------------------------------------------------------------------------" << endl;
		out.close();
	}
	cout << playlist.getPlaylistName() << " Playlist Saved Successfully" << endl;
	playlist.addOneToSavedSize();
	fstream outSize;
	outSize.open("size.txt", ios::out);
	if (outSize.is_open())
	{
		outSize << playlist.getSavedSize() << endl;
		outSize.close();
	}
}
void Load(AllPlaylists& all)
{
	fstream PlaylistsSizeIn;
	PlaylistsSizeIn.open("size.txt", ios::in);
	string size;
	getline(PlaylistsSizeIn, size);
	int size1 = toInt(size);
	PlaylistsSizeIn.close();
	fstream Playlists;
	Playlists.open("Playlists.txt",ios::in);
	string PlaylistName, SurahName, Type, Path,plus,under;
	for (int i = 0; i < size1;i++)
	{
		getline(Playlists, PlaylistName);
		Playlist playlist(PlaylistName);
		string size2;
		getline(Playlists, size2);
		int size3 = toInt(size2);
		for (int j = 0; j < size3 ; j++)
		{
			getline(Playlists, SurahName);
			getline(Playlists, Type);
			getline(Playlists, Path);
			getline(Playlists, plus);
			Surah surah(SurahName, Type, Path);
			playlist.AddSurah(surah);
		}
		getline(Playlists, under);
		all.AddPlaylist(playlist);
	}
	cout << "Playlists Loaded Successfully :)" << endl;
}
void RemovePlaylist(AllPlaylists& all)
{
	all.DisplayPlaylists();
	cout << "Which Playlist ? ";
	string name;
	cin >> name;
	all.RemovePlaylist(name);
}
int toInt(string value)
{
	int r = 0;
	for (int i = 0; i < value.size(); i++)
	{
		r = (value[i] - '0') + r * 10;
	}
	return r;
}
