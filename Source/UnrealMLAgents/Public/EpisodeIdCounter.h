#pragma once

class EpisodeIdCounter
{
public:
	static int32 GetEpisodeId();

private:
	static int32 Counter;
};