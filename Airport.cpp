#include "Airport.h"
#include <queue>
#include <mutex>
#include <iostream>
#include <chrono>

std::mutex stream; //to make sure printing is smooth



Plane::Plane(int id)
{
	this->id = id; 
	this->inLine = false; //for traffic 
}

void Plane::land(ATC& atc) //stuff to print during landing
{
	stream.lock();
	std::cout << "Plane " << this->id << " has requested landing" << std::endl;
	stream.unlock();
	std::this_thread::sleep_for(std::chrono::seconds(1));
	stream.lock();
	std::cout << "Plane " << this->id << " has landed" << std::endl;
	stream.unlock();
}

void Plane::communicate(ATC& atc)
{
	if (atc.comms.try_lock()) //if the plane can get communication, immediately signal for landing
	{
		(*this).land(atc);
		atc.comms.unlock();
	}
	else //someone is already on call
	{
		atc.mutexqueue.lock(); //to join queue smoothly, lock it 
		if ((atc.traffic.size()) < 3) //if traffic not full, join the traffic  
		{
			atc.traffic.push(this->id);
			stream.lock();
			std::cout << "Plane " << this->id << " has joined the traffic pattern" << std::endl;
			this->inLine = true;
			stream.unlock();
			atc.mutexqueue.unlock(); //successfully joined queue, let others queue in

		}
		else //cannot get on call or join traffic, divert
		{
			atc.mutexqueue.unlock();
			stream.lock();
			std::cout << "Plane " << this->id << " diverting to another airport" << std::endl;
			stream.unlock();
		}
	}
}

