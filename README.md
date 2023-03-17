# Coding2-Final-Work_Shaohua-Yang

## overview

"I tried to find something interesting to relieve the anxiety inside me". Anxiety is often hidden in the noisy darkness and once you find it and drag it into the spotlight and blow on it hard, it will drift into the air like the seeds of a dandelion. I use the machine as a medium to establish a binary opposition between me and my troubles, and use dandelions as clues to connect what I call anxiety. When we drive the machine to operate, these troubles will also float into the air.

![Cow1](https://github.com/yrrrng/Coding2-Final-Work_Shaohua-Yang/raw/main/image/2.png "Cow1")

### Outcome:
This project is an interactive work that the user can blow to the device to make the generated virtual flowers fly with the wind. The program mainly consists of three parts: (1) Arduino - OpenFrameworks Communication System. (2) Gerative System of Virtual Flowers. (3) Interactive Control Flower Behavior System.

#### 1. Ardino-Openframeworks Communication System.
In this system, we utilize an Arduino-based microphone for detecting the user blowing. It can analog input the volume data to Arduino A0 with the random from 0-1023. We use the function "analog read" to read the data and map it to 0-255 because we want to transmit the data to OpenFrameworks through a serial port with the "Serial.write" function which can only transmit 1 byte. In the OpenFrameworks, we use the "serial.readByte" function to receive the data.

![Cow2](https://github.com/yrrrng/Coding2-Final-Work_Shaohua-Yang/raw/main/image/5.png "Cow2")
