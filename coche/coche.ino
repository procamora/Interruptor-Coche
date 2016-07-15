/*
Exploring Arduino - Code Listing 2-5: Debounced Button Toggling
http://www.exploringarduino.com/content/ch2

Copyright 2013 Jeremy Blum ( http://www.jeremyblum.com )
This program is free software: you can redistribute it and/or modify
it under the terms of the GNU General Public License v3 as published by
the Free Software Foundation.
*/

const int LED_ON=9;				//Conexion del led, rele, led boton arriba
const int LED_OFF=8;			//Conexion del led boton abajo
const int BUTTON=2;				//Conexion del boton
boolean lastButton = LOW;		//contiene el estado anterion del boton
boolean currentButton = LOW;	//Contiene el estado actual del boton
boolean ledOn = false;			//The present state of the LED (on/off)

void setup() {
	pinMode (LED_ON, OUTPUT);
	pinMode (LED_OFF, OUTPUT);
	pinMode (BUTTON, INPUT);
}


/*
* Debouncing Function
* Pass it the previous button state,
* and get back the current debounced button state.
*/
boolean debounce(boolean last) {
	boolean current = digitalRead(BUTTON);		//Read the button state
	if (last != current) {						//if it's different?
		delay(5);								//wait 5ms
		current = digitalRead(BUTTON);			//read it again
	}
	return current;								//return the current value
}


void loop() {
	currentButton = debounce(lastButton);				//read debounced state
	if (lastButton == LOW && currentButton == HIGH)		//if it was pressed?
		ledOn = !ledOn;									//toggle the LED value

	lastButton = currentButton;							//reset button value

	digitalWrite(LED_ON, ledOn);						//cambia led arriba
	digitalWrite(LED_OFF, !ledOn);						//cambia led abajo
}
