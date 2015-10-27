#pragma once

#include <string>
using std::string;

#include "utils.h"
#include "globals.h"

class Boat {

	public:
		static void InitModel();
		static void DestroyModel();

		Boat();
		void update(float dt);
		void draw();
		void onkeydown(string keyname);
		void onkeyup(string keyname);
		bool testWaveCollision(glm::vec3 wavePos);
		void startEntranceAnimation();
		void testBigWaveCollision(glm::vec3 wavePos);
		
		glm::vec3 position;
		glm::vec3 rotation;
		glm::vec3 scale;

	private:
		static glModelData model;
		static GLint uniProj;
		static GLint uniView;
		static GLint uniModel;
		static GLint uniWave;
		static GLint uniStorminess;
		static GLint uniLightning;

		glm::mat4 transform;

		float speed;
		glm::vec3 velocity;
		bool movingLeft, movingRight, movingForward, movingBack;

		float totalTime;

		glm::vec3 goalRot, startRot;
		float goalRotTimer;

		bool isStunned;
		float stunTimer;

		float scaleNormFactor;

		bool startedEntranceAnimation;
		float entranceAnimationTimer;

		bool hasBoatSunk;
		float sinkTimer;

		void untilt();
		void tiltLeft();
		void tiltRight();
		void sinkTilt();
		void stunSpin(float dt);
};