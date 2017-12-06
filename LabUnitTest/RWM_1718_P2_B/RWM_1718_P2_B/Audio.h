#pragma once



class Audio
{

public:
	//constructor that takes a rect as an input and initialiases all other variables except col
	/*Audio(Rect r) :rect(r) {

	};*/


	Audio();
	~Audio();


	bool play = false;


	//void Render(Renderer & r);

	void Init();

	bool Play();

	void Update(int masterV, int musicVol, int sfxVol);


	void SfxPlay();

};

