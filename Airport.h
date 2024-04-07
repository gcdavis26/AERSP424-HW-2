#pragma once
#include <queue>
#include <mutex>

#ifndef AIRPORT_H
#define AIRPORT_H


class ATC
{
public:
	std::mutex comms;
	std::queue<int> traffic;
	std::mutex mutexqueue;
};


class Plane
{
public:
	int id;
	bool inLine;
	Plane(int);

	void communicate(ATC&);
	void land(ATC&);
};




#endif 