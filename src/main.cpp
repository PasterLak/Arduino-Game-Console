
#include <Arduino.h>
#include "Engine.hpp"


Engine engine;


void setup()
{
	Serial.begin(9600);

	randomSeed( analogRead(0) );

	engine.start();

	oldTime = millis();

	
}

void loop()
{
updateDelta();
 
	Device::updateInput();
	
	engine.update();
}
