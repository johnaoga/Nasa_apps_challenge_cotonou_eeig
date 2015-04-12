int feux_pin  = 3, clock_pin = 2, reset = 4;
int feux_leds [] = {0,0,0,0,0,0,0,0,0,0,0,0},force [] = {0,0,0,0,0,0,0,0,0,0,0,0}, voie []={0,0,0,0};
int led,i,j=0,etat=0,teste;
String val="";
int dureeV = 1.5 ,dureeJ=0.5 ,dureeR=0.2;
float tempoLed[] = {1.5,0.5,0.2,1.5,0.5,0.2,1.5,0.5,0.2,1.5,0.5,0.2};
//--------------------------
void affiche(int tab[]){ //Fonction d'envoie des données vers les lampes et le port com
  val="";
  digitalWrite(reset,LOW);
  digitalWrite(reset,HIGH);
    for(led=11; led>=0;led--){
      digitalWrite(clock_pin,LOW);
        //delay(2);
          digitalWrite(feux_pin,tab[led]);
        //delay(2);
      digitalWrite(clock_pin,HIGH);
        //delay(2);
        val.concat(tab[11-led]);
    }         
  Serial.println(val);  //vers port com
}    
//-----------------------------
void change(int posi){ //configuration des etats des lampes
        feux_leds [posi] = 1 ;
    if(posi%3>0){
        feux_leds [posi-1] = 0;
    }
    if(posi%3==0){
        feux_leds [posi+2] = 0;
    }
}
//-----------------------------
void duree(int posi){ //temporisation de chaque etat
 // for(i=0;i<100;i++){
     delay(tempoLed[posi]*1000);
 //    lecture();
  //   if(Serial.available()>0){
  //   break;
  //   }
  // }  
}
//-----------------------------
void lecture(){  //Lire le buffer
  if (Serial.available()>0){
   teste= Serial.parseInt();
      if(teste==1){
          dureeV=Serial.parseInt();
          dureeJ=Serial.parseInt();
          dureeR=Serial.parseInt();
          
          for(i=0;i<12;i++){
              switch(i%3){
                
              case 0:
                    tempoLed[i]= dureeV;
              break;
              case 1:
                    tempoLed[i]= dureeJ;
              break;
              case 2:
                    tempoLed[i]= dureeR;
              break;
              }
           }
      }
      if (teste==2){

         for(i=0;i<4;i++){
              voie[i]=Serial.parseInt();
          }
         for(i=11;i>=0;i--){
           force[i]=0;
         }
  
          for(i=11;i>0;i=i-3){
              if(voie[i/3]==1){
                  force[i] = 1;
              }
              else{
                  force[i-2] = 1;
              }
              
          }
          
      }
      if(teste==3){
          for(i=0;i<12;i++){
                  tempoLed[i]=Serial.parseInt();
           }
      
      }
  }

}
//-----------------------------

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  pinMode( clock_pin,OUTPUT);
  pinMode( feux_pin,OUTPUT);
  
  for(i=0; i<4; i++){
    feux_leds [1] = 1;
    feux_leds [4] = 1;
    feux_leds [7] = 1;
    feux_leds [10] =1;
    affiche(feux_leds);
    
    delay(1000);
    feux_leds [1] = 0;
    feux_leds [4] = 0;
    feux_leds [7] = 0;
    feux_leds [10] =0;
    affiche(feux_leds);
    delay(1000);
    }
    feux_leds [2] = 1;
    feux_leds [5] = 1;
    feux_leds [8] = 1;
    feux_leds [11] =1;
    led=0;
}

void loop() {
  // put your main code here, to run repeatedly:
  
    etat=etat%12;
    
  change(etat)  ;
  affiche(feux_leds);
  duree(etat);             //A changer
  //delay(tempoLed[etat]);
  lecture();
  
  while(teste == 2){
      lecture();
      affiche(force);
      delay(500);
  }
  
  
      etat++;
}
