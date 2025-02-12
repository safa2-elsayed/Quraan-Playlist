#pragma once
#pragma once
#include<string>
#include"DLL.h"
#include"Surah.h"
#include <irrKlang.h>
using namespace irrklang;
using namespace std;

class Playlist
{
private:
	string playlistName;
	DLL<Surah> playlist;
	static int PlaylistsSaved;
public:
	Playlist();
	Playlist(string);
	Playlist(Playlist&);
	Playlist& operator=(Playlist&);
	DLL<Surah>& getPlayList();
	void setPlaylistName(string);
	string getPlaylistName();
	void DisplayPlaylist();
	int getSize();
	void ReorderSurahPosition(string, int);
	void RemoveSurah(string);
	void AddSurah(Surah);
	void PlaySurah();
	static void setSavedSize(int);
	static int getSavedSize();
	static void addOneToSavedSize();
	bool operator==(Playlist);
};
