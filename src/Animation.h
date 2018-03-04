#pragma once
#include <assimp/anim.h>
#include <glm/mat4x2.hpp>
#include <vector>

struct BoneTransform
{
	aiString name;
	glm::mat4 *transform;
};

class Animation
{
	double ticksPerSecond = 0;
	double duration = 0;
	unsigned int channelCount = 0;
	int animationStartTime = 0;
	time_t timer;

	aiNodeAnim** channels;
	aiString name;

	int lastPositionKey = 0;
	int lastRotationKey = 0;
	int lastScalingKey = 0;

	glm::quat* InterpolatePosition(aiVector3D positionMat1, aiVector3D positionMat2, float factor);
public:
	Animation(double ticks_per_second, double duration, aiNodeAnim** channels, unsigned int channelCount, const aiString name);
	int GetTimePassed();
	void Play();
	bool animationEnded = false;
};

