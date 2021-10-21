The Program Explanation
We begin by including SoftwareSerial library into the program.  In the next line, we create a constructor of SoftwareSerial with name mySerial and we pass the digital pin numbers as parameters. The actual format is like SoftwareSerial mySerial (Rx, Tx);

So in our code, pin number 9 will act as Rx of Arduino and 10 will act as Tx of Arduino.  Lets get to the configuration part of program inside setup. The first task is to set baud rates of SoftwareSerial library to communicate with GSM module. We achieve this by invoking mySerial.begin function. Our second task is to set the baud rate of Arduino IDE’s Serial Monitor. We do this by invoking Serial.begin function. Both should be set at the same baud rate and we use 9600 bits/second here in our tutorial.  Configuration part is over with setting baud rates and its good to give a small delay of 100 milli seconds.

Now lets get to the actual program inside loop(). To make things simpler, I have developed a user input based program. The program seeks user input via serial monitor of Arduino. If the input is ‘s’ the program will invoke function to send an sms from GSM module. If the user input is ‘r’, the program will invoke the function to receive a live SMS from GSM module and display it on serial monitor of Arduino. The whole program is as simple as that!

Serial.available() – checks for any data coming through serial port of arduino. The function returns the number of bytes available to read from serial buffer. If there is no data available, it returns a -1 (value less than zero).
Serial.read() – Reads all the data available on serial buffer (or incoming serial data if put otherwise). Returns the first byte of incoming serial data.

mySerial.available() – checks for any data coming from GSM module through the SoftwareSerial pins 9 and 10. Returns the number of bytes available to read from software serial port. Returns a -1 if no data is available to read.

mySerial.read() – Reads the incoming data through software serial port.
Serial.write() – Prints data to serial monitor of arduino. So the function Serial.write(mySerial.read()) – prints the data collected from software serial port to serial monitor of arduino.
Lets get the functions SendMessage()  and RecieveMessage()

These are the functions in which we actually send commands to GSM module from Arduino. These commands to communicate with GSM module are called AT Commands. There are different commands to perform different tasks using the GSM module. You can read complete AT Commands Library to understand all that is possible with GSM module.

SendMessage() – is the function we created in our arduino sketch to send an SMS. To send an SMS, we should set our GSM module to Text mode first. This is achieved by sending an AT Command “AT+CMGF=1”  We send this command by writing this to SoftwareSerial port. To achieve this we use the mySerial.println() function. mySerial.println writes data to software serial port (the Tx pin of our Software Serial – that is pin 10) and this will be captured by GSM module (through its Rx pin). After setting the GSM module to Text mode, we should the the mobile number to which we shall send the SMS. This is achieved with AT command “AT+CMGS=\”+91xxxxxxxxxx\”\r” – where you may replace all x with the mobile number.

In next step, we should send the actual content of SMS. The end of SMS content is identified with CTRL+Z symbol. The ASCII value of this CTRL+Z is 26. So we send a char(26) to GSM module using the line mySerial.println((char)26); Each and every AT command may be followed by 1 second delay. We must give some time for GSM module to respond properly. Once these commands are send to GSM module, you shall receive an SMS in the set mobile number.
RecieveMessage() – is the function to receive an SMS (a live SMS). The AT command to receive a live SMS is “AT+CNMI=2,2,0,0,0” – we just need to send this command to GSM module and apply a 1 second delay. Once you send this command, try sending an SMS to the SIM card number put inside GSM module. You will see the SMS you had sent displayed on your Arduino serial monitor.

There are different AT commands for different tasks. If you want to read all SMS’s stored in your SIM card, send the following AT Command to gsm module – “AT+CMGL=\”ALL\”\r”

Okay! That’s all and you are done. And you have learnt how to use arduino to send sms and receive sms message with example code.

I shall summarize this tutorial on how to send/receive a text message using arduino and gsm module with the following notes:-
AT Commands to Send SMS using Arduino and GSM Module
AT+CMGF=1 // Set the GSM module in text mode
AT+CMGS=\"+YYxxxxxxxxxx\"\r // Input the mobile number| YY is country code
“the message” with stopping character (char)26 // ASCII of ctrl+z
AT Commands to Receive SMS using Arduino and GSM Module
AT+CMGF=1 // Set the GSM Module in text mode
AT+CNMI=2,2,0,0,0 // AT Command to receive live sms
Read the AT commands library and start playing with your GSM module and Arduino! If you have any doubts please ask in comments.

So that’s all about interfacing GSM module to Arduino. If you’ve any doubts, feel free to comment.

