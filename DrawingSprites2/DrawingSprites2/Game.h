#pragma once
#define OLC_PGE_APPLICATION 0
#include "olcPixelGameEngine.h"
#include "SpriteAnimation.h"
//#include <iostream>


//Game class inherits from class PixelGameEngine, which is in the namespace olc
class Game : public olc::PixelGameEngine
{
private:
	olc::Sprite* spritePtr = nullptr;
	olc::Decal* decalPtr = nullptr;
	SpriteAnimation spriteAnimation;
	//2d vector coordinate position
	olc::vf2d position;
	float speed = 50.0f;

public:

	~Game() {
		delete spritePtr;
		delete decalPtr;
	}

	//we need to override the following methods from PixelGameEngine
	bool OnUserCreate() override {
		//to get the starting path
		//std::filesystem::path startingPath = std::filesystem::current_path();

		//load the sprite
		spritePtr = new olc::Sprite("hadouken_sprite_sheet.png");
		decalPtr = new olc::Decal(spritePtr);

		spriteAnimation.SetParams(0.125f, spritePtr->width, spritePtr->height, 6, 5, 26);

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

		AnimationData animationData = spriteAnimation.GetInfo(fElapsedTime);
		olc::vf2d size = { 480.0f, 228.0f };
		DrawPartialDecal(position, size, decalPtr, animationData.sourcePos, animationData.sourceSize);

		//warping
		//std::array<olc::vf2d, 4> points;
		//points[0] = { 0.0f, 0.0f };
		//points[1] = { 0.0f, 228.0f };
		//points[2] = { 480.0f, 228.0f };
		//points[3] = { 480.0f, 0.0f };
		//DrawPartialWarpedDecal(decalPtr, points, animationData.sourcePos, animationData.sourceSize);

		//std::array<olc::vf2d, 4> points;
		//points[0] = { 480.0f, 0.0f };
		//points[1] = { 480.0f, 228.0f };
		//points[2] = { 0.0f, 228.0f };
		//points[3] = { 0.0f, 0.0f };
		//DrawPartialWarpedDecal(decalPtr, points, animationData.sourcePos, animationData.sourceSize);

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