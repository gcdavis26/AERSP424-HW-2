#include "Sensor.h"
#include "string"

int main()
{
	AerospaceControlSystem ctrlSys;
	ctrlSys.addSensor("Altimeter");
	ctrlSys.addSensor("Thermometer");
	ctrlSys.addSensor("FuelLevel");


	ctrlSys.monitorAndAdjust();
	return 0;
}