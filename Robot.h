#pragma once
#include <mutex>

#ifndef ROBOT_H
#define ROBOT_H

class Tool
{
public:
	std::mutex m;

};

class Robot 
{
public:
	int ID;
	Robot(int);
	void grab(Tool&, Tool&);
	void release(Tool&, Tool&);


};




#endif 