#include "Animation.h"
#include <chrono>
#include <iostream>


Animation::Animation(double ticks_per_second, double duration, aiNodeAnim** channels, unsigned int channelCount, const aiString name)
	: ticksPerSecond(ticks_per_second),
	duration(duration),
	channels(channels),
	channelCount(channelCount),
	name(name)
{

}

int Animation::GetTimePassed()
{
	auto now = std::chrono::high_resolution_clock::now();
	auto nowMillis = std::chrono::duration_cast<std::chrono::milliseconds>(now.time_since_epoch()).count();
	if (!animationStartTime)
	{
		animationStartTime = nowMillis;
	}

	float timePassedInSeconds = animationStartTime - nowMillis;
	return timePassedInSeconds / 1000;
}

void Animation::Play()
{
	int timePassedInSeconds = GetTimePassed();

	for (int i = 0; i < channelCount; ++i)
	{
		float time = timePassedInSeconds * ticksPerSecond;
		aiNodeAnim* channel = channels[i];
		aiVectorKey* positionKey = &channel->mPositionKeys[lastPositionKey];
		
		// TODO: Come here to end your endless animation
		if (lastPositionKey + 1 > channel->mNumPositionKeys - 1) {
			lastPositionKey = 0;
			animationEnded = true;
			animationStartTime = 0;
		}

		// We have exceeded the time for this keyframe get the next one
		if(positionKey->mTime < time)
		{
			lastPositionKey += 1;
			positionKey = &channel->mPositionKeys[lastPositionKey];
		}

		aiVectorKey* positionKey2 = &channel->mPositionKeys[lastPositionKey + 1];

		// TODO: Use modulus instead it already gives the difference...
		float maxTimeDelta = positionKey2->mTime - positionKey->mTime;
		float timeDelta = time - positionKey->mTime;
		float factor = maxTimeDelta / timeDelta;

		glm::quat* interpolatedPos = InterpolatePosition(positionKey->mValue, positionKey2->mValue, factor);
	}
}

glm::quat* Animation::InterpolatePosition(aiVector3D positionVec, aiVector3D positionVec2, float factor)
{
//	glm::quat pos1 = glm::quat(positionVec.x, positionVec.y, positionVec.z, 1.0);
//	glm::quat pos2 = glm::quat(positionVec2.x, positionVec2.y, positionVec2.z, 1.0);
//
//	glm::quat interpolatedPos = glm::lerp(pos1, pos2, factor);
	return 0;
}