
// This #include statement was automatically added by the Particle IDE.
#include <libfixmath.h>

// This #include statement was automatically added by the Particle IDE.
#include <HttpClient.h>

#include "application.h"  


http_request_t request;  
http_response_t response;

HttpClient http;  
http_header_t headers[] = {  
    { "Content-Type", "application/json" },  
    { NULL, NULL }   
 };  
 
//motor 1
const int ain1=D3;
const int ain2=D4;
//const int pwm=6;
//motor 2
const int ain3=D5;
const int ain4=D6;

//Starter values
int xVelo=0;
int yVelo=1;

void setup() {
    Serial.begin(9600);  
   
    pinMode(ain1, OUTPUT);
    pinMode(ain2, OUTPUT);
    pinMode(ain3, OUTPUT);
    pinMode(ain4, OUTPUT);
  
    request.ip = IPAddress(172,20,10,5);  
    request.port = 8080;
    Serial.print("hi");
}

void loop() {
    getRequest(); 
    
    
    // put your main code here, to run repeatedly:
    
    /*double power = ((xVelo) ** 2 + yVelo) **2) ** 0.5;
    double angle= libfixmath.atan2(xVelo,yVelo)-3.14/4;//-3.14/4
    Serial.println(angle);
    drive1(power*sin(angle));
    drive2(power*cos(angle));
    */
    if(abs(yVelo)>=abs(xVelo) && abs(yVelo) >10){
        drive1(yVelo);
        drive2(yVelo);
    }
    else if (abs(xVelo)>abs(yVelo) && abs(xVelo)>10){
        drive1(xVelo);
        drive2(-xVelo);
    }
    else{
        drive1(0);
        drive2(0);
    }
    
    delay(1000);
    
    /*digitalWrite(ain1, HIGH);
    digitalWrite(ain2, LOW);
    digitalWrite(ain3, HIGH);
    digitalWrite(ain2, LOW);
    
    delay(5000);
    digitalWrite(ain1, LOW);
    digitalWrite(ain2, HIGH);
    digitalWrite(ain3, HIGH);
    digitalWrite(ain4, LOW);*/
    
}

void drive1(int speed){
  if(speed>0){
    digitalWrite(ain1, HIGH);
    digitalWrite(ain2, LOW);
    //analogWrite(pwm, speed);
  }
  else if(speed<0){
    digitalWrite(ain1, LOW);
    digitalWrite(ain2, HIGH);
    //analogWrite(pwm, abs(speed));
  }
  else{
      digitalWrite(ain1, LOW);
      digitalWrite(ain2, LOW);
  }
}
void drive2(int speed){
   if(speed>0){
    digitalWrite(ain3, HIGH);
    digitalWrite(ain4, LOW);
    //analogWrite(pwm, speed);
  }
  else if(speed<0){
    digitalWrite(ain3, LOW);
    digitalWrite(ain4, HIGH);
    //analogWrite(pwm, abs(speed));
  }
  else{
      digitalWrite(ain3, LOW);
      digitalWrite(ain4, LOW);
  }
}

void printResponse(http_response_t &response) {  
   Serial.println("HTTP Response: "); 
   Serial.println(response.status);
   Serial.println(response.body);
   Serial.println(response.body.substring(0, response.body.indexOf(",")));
   Serial.println(yVelo);
}
   
void getRequest() {  
   request.path = "/data";  
   request.body = "";  
   
   http.get(request, response, headers);  
   
   printResponse(response);//convert response to json
   
   
   xVelo=response.body.substring(0, response.body.indexOf(",")).toInt();
   yVelo=response.body.substring(response.body.indexOf(" ") +1).toInt();
   //xVelo=Parse(response.body.substring(response.body.indexOf("\"x\":")+1, response.body.indexOf(",")));
   
   //xVelo = response.body.x;
   //yVelo = response.body.y;
}  
