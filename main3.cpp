#include "Airport.h"
#include <thread>
#include <iostream>

void task(Plane& plane, ATC& atc)
{
	plane.communicate(atc); //if can communicate, will do it. Else will join queue or will divert
	while (plane.inLine) //if in queue
	{
		if (atc.traffic.front() == plane.id) //if youre first in line
		{
			atc.comms.lock();
			plane.land(atc);
			plane.inLine = false; //gets us out of this loop
			atc.comms.unlock();
			atc.traffic.pop(); //move up the queue
		}
		//else just keep waiting
	}
}

int main()
{
	Plane plane1(1), plane2(2), plane3(3), plane4(4), plane5(5), plane6(6), plane7(7), plane8(8), plane9(9), plane10(10);
	ATC atc;

	std::thread t1(task, std::ref(plane1), std::ref(atc));
	std::thread t2(task, std::ref(plane2), std::ref(atc));
	std::thread t3(task, std::ref(plane3), std::ref(atc));
	std::thread t4(task, std::ref(plane4), std::ref(atc));
	std::thread t5(task, std::ref(plane5), std::ref(atc));
	std::thread t6(task, std::ref(plane6), std::ref(atc));
	std::thread t7(task, std::ref(plane7), std::ref(atc));
	std::thread t8(task, std::ref(plane8), std::ref(atc));
	std::thread t9(task, std::ref(plane9), std::ref(atc));
	std::thread t10(task, std::ref(plane10), std::ref(atc));

	t1.join();
	t2.join();
	t3.join();
	t4.join();
	t5.join();
	t6.join();
	t7.join();
	t8.join();
	t9.join();
	t10.join();
	return 0;
}