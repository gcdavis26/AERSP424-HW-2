#include "Sensor.h"
#include <iostream>
#include <memory>
#include <string>


// Altimeter class

Altimeter::Altimeter()
{
	std::cout << "Altimter on" << std::endl;
}
Altimeter::~Altimeter()
{
	std::cout << "Altimeter off" << std::endl;
}

void Altimeter::processData()
{
	std::cout << "Processing data from the Altimeter Sensor" << std::endl;
}

void Altimeter::gatherData()
{
	std::cout << "Gathering data from the Altimeter Sensor" << std::endl;

}

//Thermometer class

Thermometer::Thermometer()
{
	std::cout << "Thermometer on" << std::endl;
}
Thermometer::~Thermometer()
{
	std::cout << "Thermometer off" << std::endl;
}

void Thermometer::processData()
{
	std::cout << "Processing data from the Thermometer Sensor" << std::endl;
}

void Thermometer::gatherData()
{
	std::cout << "Gathering data from the Thermometer Sensor" << std::endl;
}

//Fuel level class

FuelLevel::FuelLevel()
{
	std::cout << "FuelLevel on" << std::endl;
}
FuelLevel::~FuelLevel()
{
	std::cout << "FuelLevel off" << std::endl;
}

void FuelLevel::processData()
{
	std::cout << "Processing data from the FuelLevel Sensor" << std::endl;
}

void FuelLevel::gatherData()
{
	std::cout << "Gathering data from the FuelLevel Sensor" << std::endl;

}

// Sensor factory class


std::shared_ptr<Sensor> SensorFactory::createSensor(std::string sensortype)
{
	std::shared_ptr<Sensor> ptr;
	if (sensortype == "Altimeter")
	{
		ptr = std::make_shared<Altimeter>();
	}
	else if (sensortype == "Thermometer")
	{
		ptr = std::make_shared<Thermometer>();
	}
	else if (sensortype == "FuelLevel")
	{
		ptr = std::make_shared<FuelLevel>();
	}
	else
	{
		ptr = nullptr;
	}

	return ptr;
}

// AerospaceControlSystem
void AerospaceControlSystem::addSensor(std::string type)
{
	sensorArray.push_back(SensorFactory::createSensor(type)); //add sensor to vector of senso pointers
}

void AerospaceControlSystem::monitorAndAdjust()
{
	for (auto iter : sensorArray) // go through vector and call functions for each sensor
	{
		(*iter.get()).gatherData();
		(*iter.get()).processData();

		std::cout << "Adjusting controls based on sensor data" << std::endl;

	}
}