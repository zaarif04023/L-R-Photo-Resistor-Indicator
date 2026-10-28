int leftPhotoResistor = A0; 
int rightPhotoResistor = A1; 
int leftMin = 6, leftMax = 1017; 
int rightMin = 0, rightMax = 1016;

int Lled = 12;
int Cled = 11;
int Rled = 10;
void setup() {
Serial.begin(9600); 
  pinMode(Lled, OUTPUT);
  pinMode(Cled, OUTPUT);
  pinMode(Rled, OUTPUT);
}
void loop() 
{
   int leftLightLevel = analogRead(leftPhotoResistor);
   int rightLightLevel = analogRead(rightPhotoResistor);

   int brightnessL = map(leftLightLevel, leftMin, leftMax, 0, 100);
   int brightnessR = map(rightLightLevel, rightMin, rightMax, 0, 100);
   Serial.print("Left Sensor:"); 
   Serial.print(leftLightLevel);
   Serial.print(brightnessL);

  Serial.println(" ");

   Serial.print("Right Sensor:"); 
   Serial.print(rightLightLevel);
   Serial.print(brightnessR);

   if(brightnessL > brightnessR + 10)
   {
     digitalWrite(Lled, HIGH);
     digitalWrite(Cled, LOW);
     digitalWrite(Rled, LOW);
     Serial.println(" Left "); 
    }
   else if(brightnessR > brightnessL + 10)
   {
     digitalWrite(Lled, LOW);
     digitalWrite(Cled, LOW);
     digitalWrite(Rled, HIGH);
     Serial.println(" Right "); 
   }
   else
    {
     digitalWrite(Lled, LOW);
     digitalWrite(Cled, HIGH);
     digitalWrite(Rled, LOW);
     Serial.println(" Center "); 
    }
   Serial.println(" ");

  delay(300);

}