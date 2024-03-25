#include "Sensor.h"
#include <iostream>
#include <memory>

Altimeter::Altimeter()
{
	std::cout << "Altimter on" << std::endl;
}
Altimeter::~Altimeter()
{
	std::cout << "Altimeter off";
}

void Altimeter::processData()
{
	std::cout << "Processing data from the Altimeter Sensor" << std::endl;
}

void Altimeter::gatherData()
{
	std::cout << "Gathering data from the Altimeter Sensor" << std::endl;

}

Thermometer::Thermometer()
{
	std::cout << "Thermometer on" << std::endl;
}
Thermometer::~Thermometer()
{
	std::cout << "Thermometer off";
}

void Thermometer::processData()
{
	std::cout << "Processing data from the Thermometer Sensor" << std::endl;
}

void Thermometer::gatherData()
{
	std::cout << "Gathering data from the Thermometer Sensor" << std::endl;
}


FuelLevel::FuelLevel()
{
	std::cout << "FuelLevel on" << std::endl;
}
FuelLevel::~FuelLevel()
{
	std::cout << "FuelLevel off";
}

void FuelLevel::processData()
{
	std::cout << "Processing data from the FuelLevel Sensor" << std::endl;
}

void FuelLevel::gatherData()
{
	std::cout << "Gathering data from the FuelLevel Sensor" << std::endl;

}

std::unique_ptr<Sensor> SensorFactory::createSensor(std::string sensortype)
{
	std::unique_ptr<Sensor> ptr;
	if (sensortype == "Altimeter")
	{
		ptr = std::make_unique<Altimeter>();
	}
	else if (sensortype == "Thermometer")
	{
		ptr = std::make_unique<Thermometer>();
	}
	else if (sensortype == "FuelLevel")
	{
		ptr = std::make_unique<FuelLevel>();
	}
	else
	{
		ptr = nullptr;
	}

	return ptr;
}
