float d;

void setup() {
  Serial.begin(9600);
  pinMode(7, INPUT); //echo pin of ultraSonic
  pinMode(8, OUTPUT); //trig pin of ultraSonic
  pinMode(10, OUTPUT); // relay
  pinMode(9, OUTPUT); // buzzer pin
}

int low = 20;
int high = 10;

void vol() //distance calculaion...
{
  digitalWrite(8, HIGH);
  delayMicroseconds(8);
  digitalWrite(8, LOW);
  delayMicroseconds(2);
  d = pulseIn(7, HIGH);
  d = d / 69;
}

void loop() {
  vol(); 
  while (1)
  {
  b: digitalWrite(10, HIGH); // Pump On...
    vol();
    if (d < high) //check high...
    {
      Serial.println(d);
      digitalWrite(9, HIGH); // buzzer on.....
      digitalWrite(9, LOW);
      goto a;
    }
  }
  while (1)
  {
    a: digitalWrite(10, LOW); // pump off...
    vol(); 
    if (d > low) //check low
    {
      Serial.println(d);
      digitalWrite(9, HIGH); //Buzzer beeping......
      digitalWrite(9, LOW);
      digitalWrite(9, HIGH);
      digitalWrite(9, LOW);
      goto b;
    }
  }
}
