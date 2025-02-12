#include"Playlist.h"
#include <iostream>
#include <iomanip>
#include <fstream>
#include <conio.h>
#include <irrKlang.h>
#include "Node.h"
using namespace irrklang;
using namespace std;

int Playlist::PlaylistsSaved = 0;
Playlist::Playlist() {}
Playlist::Playlist(string name) :playlistName(name) {}
Playlist::Playlist(Playlist& playlist)
{
	this->playlistName = playlist.playlistName;
	this->playlist = playlist.playlist;
}
Playlist& Playlist::operator=(Playlist& playlist)
{
	if (this != &playlist)
	{
		this->playlistName = playlist.playlistName;
		this->playlist = playlist.playlist;
	}
	return *this;
}
DLL<Surah>& Playlist::getPlayList()
{
	return playlist;
}
void Playlist::setPlaylistName(string playlistName)
{
	this->playlistName = playlistName;
}
string Playlist::getPlaylistName()
{
	return playlistName;
}

void Playlist::DisplayPlaylist()
{
	cout << "             Playlist : " << playlistName << endl;
	cout << "----------------------------------------------------------------" << endl;
	cout << left << setw(4) << "ID" << setw(20) << "Surah" << setw(20) << "Type" << setw(20) << "Path" << endl;
	cout << "----------------------------------------------------------------" << endl;
	int id = 1;
	Node<Surah>* current = playlist.getHead();
	while (current)
	{
		cout << left << setw(4) << id << current->data << endl;
		id++;
		current = current->next;
	}
	cout << endl;
}
int Playlist::getSize()
{
	return playlist.getSize();
}
void Playlist::ReorderSurahPosition(string surah, int pos)
{
	Surah s(surah);
	Surah newSurah = playlist.search(s);
	playlist.deleteElement(s);
	playlist.insertAt(newSurah, pos);
}
void Playlist::RemoveSurah(string surah)
{
	Surah s(surah);
	Surah newSurah = playlist.search(s);
	playlist.deleteElement(s);
}
void Playlist::AddSurah(Surah surah)
{
	playlist.insertAtEnd(surah);
}
void Playlist::PlaySurah()
{
	Node<Surah>* current = playlist.getHead();
	ISoundEngine* engine = createIrrKlangDevice(irrklang::ESOD_WIN_MM);
	if (!engine) {
		cerr << "Error: Could not initialize sound engine!" << endl;
		return;
	}
	string path = current->data.getPath();
	const char* filePath = path.c_str();
	ISound* sound = engine->play2D(filePath, true, false, true);
	if (!sound) {
		cerr << "Error: Could not open sound file! Path: " << filePath << endl;
	}
	else {
		cout << "Playing" << current->data.getName() << "..." << endl;
	}
	cout << "Press Up Arrow to pause, Down Arrow to resume, or 'q' to quit." << endl;
	char input;
	while (true)
	{
		input = _getch();
		if (input == 72)
		{
			sound->setIsPaused(true);
			cout << "Audio paused!" << endl;
		}
		else if (input == 80)
		{
			sound->setIsPaused(false);
			cout << "Audio resumed!" << endl;
		}
		else if (input == 'q' || input == 'Q')
		{
			engine->stopAllSounds();
			cout << playlistName << " Stopped!!" << endl;
			break;
		}
		else if (input == 77)
		{
			current = current->next;
			engine->stopAllSounds();
			if (current == nullptr)
			{
				engine->stopAllSounds();
				cout << "End Of Playlist!!" << endl;
				break;
			}
			path = current->data.getPath();
			filePath = path.c_str();
			engine->play2D(filePath, true, false, true);
			if (!sound) {
				cerr << "Error: Could not open sound file! Path: " << filePath << endl;
			}
			else {
				cout << "Playing" << current->data.getName() << "..." << endl;
			}
		}
		else if (input == 75)
		{
			current = current->prev;
			engine->stopAllSounds();
			if (current == nullptr)
			{
				engine->stopAllSounds();
				current = playlist.getHead();
			}
			path = current->data.getPath();
			filePath = path.c_str();
			engine->play2D(filePath, true, false, true);
			if (!sound) {
				cerr << "Error: Could not open sound file! Path: " << filePath << endl;
			}
			else {
				cout << "Playing" << current->data.getName() << "..." << endl;
			}
		}
	}
}
bool Playlist::operator==(Playlist playlist)
{
	return this->playlistName == playlist.playlistName;
}
void Playlist::setSavedSize(int num)
{
	PlaylistsSaved = num;
}
int Playlist::getSavedSize()
{
	return PlaylistsSaved;
}
void Playlist::addOneToSavedSize()
{
	PlaylistsSaved++;
}

