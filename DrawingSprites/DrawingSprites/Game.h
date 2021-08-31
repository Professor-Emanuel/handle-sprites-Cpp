#pragma once
#define OLC_PGE_APPLICATION 0
#include "olcPixelGameEngine.h"
//#include <iostream>


//Game class inherits from class PixelGameEngine, which is in the namespace olc
class Game: public olc::PixelGameEngine
{
private:
	olc::Sprite* spritePtr = nullptr;
	olc::Decal* decalPtr = nullptr;
	//2d vector coordinate position
	olc::vf2d position;
	float speed = 50.0f;

public:

	~Game(){
		delete spritePtr;
		delete decalPtr;
	}

	//we need to override the following methods from PixelGameEngine
	bool OnUserCreate() override {
		//to get the starting path
		//std::filesystem::path startingPath = std::filesystem::current_path();

		//load the sprite
		spritePtr = new olc::Sprite("titanfallmech.png");
		decalPtr = new olc::Decal(spritePtr);

		position.x = 0.0f; //f -> assures it will be a float 
		position.y = 0.0f; //0.0 without f, is a double

		return true;
	}

	bool OnUserUpdate(float fElapsedTime) override {

		//clear window
		Clear(olc::DARK_BLUE);

		//get keyboard input
		if (GetKey(olc::Key::D).bHeld) {
			//the position is a distance = speed * time
			position.x += (speed * fElapsedTime);
		}
		if (GetKey(olc::Key::A).bHeld) {
			//the position is a distance = speed * time
			position.x -= (speed * fElapsedTime);
		}
		if (GetKey(olc::Key::W).bHeld) {
			//the position is a distance = speed * time
			position.y -= (speed * fElapsedTime);
		}
		if (GetKey(olc::Key::S).bHeld) {
			//the position is a distance = speed * time
			position.y += (speed * fElapsedTime);
		}

		//use according to the mouse cursor position
		//position = GetMousePos();
		//repositioning: make mouse cursor and image center to coincide
		//position.x -= decalPtr->sprite->width / 2;
		//position.y -= decalPtr->sprite->height / 2;
		
		//DrawSprite(position, spritePtr);
		//drawing without background
		DrawDecal(position, decalPtr);

		olc::vf2d stringPosition(0, 0);
		DrawString(stringPosition, "this is a string", olc::RED);
		return true;
	}

	void run() {
		//make a window 1200x600 = (600*2)x(300*2) window, each pixel 2x2
		//function returns bool if successful
		//we use the OLC_PGE_APPLICATION macro to make sure what is in the if statement only runs once
		if (Construct(600, 300, 2, 2)) {
			Start();
		}
	}

};
