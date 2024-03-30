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
	std::lock(tool1.m, tool2.m);
	std::this_thread::sleep_for(std::chrono::seconds(1));
	std::cout << "Robot " << this->ID << " has grabbed the tools" << std::endl;
}
void Robot::release(Tool& tool1, Tool& tool2)
{
	tool1.m.unlock();
	tool2.m.unlock();
	std::cout << "Robot " << this->ID << " has finished the task and released the tools" << std::endl;

}





