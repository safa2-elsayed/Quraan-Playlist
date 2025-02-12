#pragma once
#pragma once
#include"DLL.h"
#include "Playlist.h"
class AllPlaylists
{
private:
	DLL<Playlist> all;
public:
	void AddPlaylist(Playlist);
	void DisplayPlaylists();
	void DisplayPlaylistsWithSurahs();
	void DisplaySurahFromSpecificPlaylist();
	void PlaySurahFromSpecificPlaylist();
	void RemovePlaylist(string);
	DLL<Playlist>& getPlaylists();
};
