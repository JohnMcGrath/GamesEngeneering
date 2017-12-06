#pragma once

#include "Audio.h"
#include "SDL.h"
#include"SDL_mixer.h"
using namespace std;
#include <iostream>

Audio::Audio()
{
}

Audio::~Audio()
{
}



void Audio::Init()
{

}


void Audio::SfxPlay()
{
	Mix_Chunk *scratch = NULL;
	scratch = Mix_LoadWAV("sfx.wav");


	Mix_PlayChannel(-1, scratch, 0);
}


bool Audio::Play()
{
	SDL_INIT_AUDIO;

	if (SDL_Init(SDL_INIT_EVERYTHING) < 0)
	{
		exit(0);
	}
	//if (SDL_Init(SDL_INIT_EVERYTHING) < 0)
	//{
	//	exit(0);
	//}

	//The music that will be played
	Mix_Music *music = NULL;

	//The sound effects that will be used

	Mix_Chunk *high = NULL;
	Mix_Chunk *med = NULL;
	Mix_Chunk *low = NULL;

	//Initialize SDL_mixer
	if (Mix_OpenAudio(22050, MIX_DEFAULT_FORMAT, 2, 4096) == -1)
	{
		return false;
	}

	//Load the music
	music = Mix_LoadMUS("music2.mp3");








	Mix_VolumeMusic(25);

	//If there was a problem loading the music
	if (music == NULL)
	{
		cout << Mix_GetError() << endl;
		return false;
	}

	////Load the sound effects
	//scratch = Mix_LoadWAV("scratch.wav");
	//high = Mix_LoadWAV("high.wav");
	//med = Mix_LoadWAV("medium.wav");
	//low = Mix_LoadWAV("low.wav");

	//If there was a problem loading the sound effects
	//if ((scratch == NULL) || (high == NULL) || (med == NULL) || (low == NULL))
	//{

	//}


	//If there is no music playing
	if (Mix_PlayingMusic() == 0)
	{
		//Play the music
		if (Mix_PlayMusic(music, -1) == -1)
		{
			return 1;
		}
	}
}


void Audio::Update(int masterV, int musicVol, int sfxVol)
{
	int muVol = musicVol * (masterV / 100.0f);
	Mix_VolumeMusic(128 * (muVol / 100.0f));

	int seVol = sfxVol * (masterV / 100.0f);
	Mix_Volume(-1, 128 * (seVol / 100.0f));
	/*if (masterV != 0)
	{
		if (musicVol != 0)
		{
			int muVol = musicVol * (masterV / 100.0f);
			Mix_VolumeMusic(128 * (muVol / 100.0f));
		}
		else
		{
			Mix_VolumeMusic(0);
		}
		if (sfxVol != 0)
		{
			int seVol = sfxVol * (masterV / 100.0f);
			Mix_Volume(-1,5);
		}
		else
		{
			Mix_Volume(-1, 0);
		}
	}
	else
	{
		Mix_VolumeMusic(0);
		Mix_Volume(-1,0);
	}*/

}

