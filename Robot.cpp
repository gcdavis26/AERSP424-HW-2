#include "Robot.h"
#include <iostream>
#include <mutex>
#include <chrono>

Robot::Robot(int id)
{
	this->ID = id;
}

void Robot::grab(Tool& tool1, Tool& tool2)
{
	//grab both tools. Only grabs if both tools are available. If not, waits for the tools.
	std::lock(tool1.m, tool2.m);
	std::this_thread::sleep_for(std::chrono::seconds(1));
	std::cout << "Robot " << this->ID << " has grabbed the tools" << std::endl;
}
void Robot::release(Tool& tool1, Tool& tool2)
{
	//relase both tools
	tool1.m.unlock();
	tool2.m.unlock();
	std::cout << "Robot " << this->ID << " has finished the task and released the tools" << std::endl;

}





