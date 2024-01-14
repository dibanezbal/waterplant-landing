# waterplant-landing
This is a landing page of a project of the Tangible Interaction course in Bachelor in Digital Interaction and Multimedia Techniques at the Open University of Catalonia - UOC.

In this repo, you can find the files to link the data extracted from the Arduino water plant system into a small landing page. This is an example of the result. 

Comments on the ino file are in Spanish. 

The package.json contains the dependencies so we need to run npm install: Serialport and Socket.io.

You will need to change the SerialPort according to the one of your Arduino.

The index.html file contains also the styling and the javascript triggering the socket.io plugin.

These are two screenshots of the data extracted from Arduino. It posts the percentage of moisture of the soil and the message when it's watering the plant:

<table style="width:100%">
  <tr>
    <th><img src="https://github.com/dibanezbal/waterplant-landing/assets/63260075/127096b0-8270-4651-835a-e608c058e454" width=50% height=50%><br><em>Ex: Moisture</em></th>
    <th><img src="https://github.com/dibanezbal/waterplant-landing/assets/63260075/e9de474e-7903-47bf-b44b-295bfd251a4b" width=50% height=50%><br><em>Ex: Watering</em></th>
  </tr>
</table>

This project is a custom version of combining these other projects:

- Communicating Between an Arduino and a Node.js Server > https://github.com/codeadamca/arduino-to-nodejs
- Automatic Plant Watering with Arduino > https://littlebirdelectronics.com.au/guides/4/automatic-plant-watering-with-arduino
- Navbar taken from this example and adapted to this project > https://plantillashtmlgratis.com/categoria/efectos-css/barras-de-pestanas-css/
