#include "Robot.h"
#include <chrono>
#include <iostream>



void task(Robot& robot, Tool& tool1, Tool& tool2) //first grab, then sleep, then release
{
	robot.grab(tool1, tool2);
	std::this_thread::sleep_for(std::chrono::seconds(5));
	robot.release(tool1, tool2);
}

int main()
{

	auto startTime = std::chrono::high_resolution_clock::now();
	

	Tool tool1, tool2, tool3, tool4, tool5;
	Robot robot1(1);
	Robot robot2(2);
	Robot robot3(3);
	Robot robot4(4);
	Robot robot5(5);

	std::thread t1(task, std::ref(robot1), std::ref(tool1), std::ref(tool5));
	std::thread t2(task, std::ref(robot2), std::ref(tool1), std::ref(tool2));
	std::thread t3(task, std::ref(robot3), std::ref(tool2), std::ref(tool3));
	std::thread t4(task, std::ref(robot4), std::ref(tool3), std::ref(tool4));
	std::thread t5(task, std::ref(robot5), std::ref(tool4), std::ref(tool5));

	t1.join();
	t2.join();
	t3.join();
	t4.join();
	t5.join();

	auto stopTime = std::chrono::high_resolution_clock::now();
	auto duration = std::chrono::duration_cast<std::chrono::seconds>(stopTime - startTime);

	std::cout << "This simulation took " << duration.count() << " seconds";
}