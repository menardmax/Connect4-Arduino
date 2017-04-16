#define InDrive_1 22
#define InDrive_2 24
#define InDrive_3 26
#define InDrive_4 28

int d = 950;
bool Button = 0;

int InDrives[] = {InDrive_1, InDrive_2, InDrive_3, InDrive_4};
int InDrivesLength = 4;

int startPos = 0;
int increment = 1;

void setup() {

  Serial.begin(9600);

  
     
      pinMode(InDrive_1, OUTPUT);
      pinMode(InDrive_2, OUTPUT);
      pinMode(InDrive_3, OUTPUT);
      pinMode(InDrive_4, OUTPUT);
      
      digitalWrite(InDrive_1, LOW);
      digitalWrite(InDrive_2, LOW);
      digitalWrite(InDrive_3, LOW);
      digitalWrite(InDrive_4, LOW);

      

}

void loop() {


//RIGHT CYCLE Regular

for(int i=0; i< 500 ; i++){

  for(int i = 3; i >= 0; i--) {
    digitalWrite(InDrives[i], HIGH);
    
    if(i + 1 > 1) {
    digitalWrite(InDrives[i-1], HIGH);
    }
    else{
    digitalWrite(InDrives[3], HIGH);
 
    }
    delayMicroseconds(d);
    digitalWrite(InDrives[i], LOW);
    delayMicroseconds(d);

   
  }

}

// LEFT CYCLE regular


for(int i=0; i< 500 ; i++){
  

  for (int i = startPos; i < InDrivesLength && i >= 0; i = i + increment) {
    digitalWrite(InDrives[i], HIGH);
  
    if (i + increment < InDrivesLength && i + increment >= 0 ) {
      digitalWrite(InDrives[i + increment], HIGH);
    }
    else{
    digitalWrite(InDrives[startPos], HIGH);
 
    }
    delayMicroseconds(d);
    digitalWrite(InDrives[i], LOW);
    delayMicroseconds(d);
   
  }
}


//  if (!isClockwise) {
//    startPos = InDrivesLength - 1;
//    increment = -1;
//  }









}
