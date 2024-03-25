#pragma once
#include <memory>

#ifndef SENSOR_H
#define SENSOR_H

class Sensor
{
protected:
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

class SensorFactory {
public:
	SensorFactory();
	~SensorFactory();

	static std::unique_ptr<Sensor> createSensor(std::string);
};
#endif SENSOR_H
