#pragma once
#include <memory>
#include <vector>
#include <string>
#ifndef SENSOR_H
#define SENSOR_H

class Sensor
{
public:
	virtual void gatherData() = 0;
	virtual void processData() = 0;
};

class Altimeter : public Sensor
{
public:
	Altimeter();
	~Altimeter();
	void gatherData();
	void processData();

};

class Thermometer : public Sensor
{
public: 
	Thermometer();
	~Thermometer();
	void gatherData();
	void processData();

};

class FuelLevel : public Sensor
{
public:
	FuelLevel();
	~FuelLevel();
	void gatherData();
	void processData();

};

class SensorFactory 
{
public:
	static std::shared_ptr<Sensor> createSensor(std::string);
};

class AerospaceControlSystem
{
public:
	void addSensor(std::string);
	void monitorAndAdjust();
private:
	std::vector<std::shared_ptr<Sensor>> sensorArray;

};


#endif SENSOR_H
