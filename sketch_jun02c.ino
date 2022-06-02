
int VRx = A0;
int VRy = A1;
int SW = 2;

int xPosition = 0;
int yPosition = 0;
int SW_state = 0;
int mapX = 0;
int mapY = 0;
int e = 0;

int n = 6;
int map1[6][6];
int map2[6][6],map3[6][6];
char showmap1[6][6],showmap2[6][6];

int playernr = 1;
int winner1 = 0,winner2 =0;


#include <SPI.h>
#include <TFT.h>
#define cs 10
#define dc 9
#define rst 8

int nrOfShots1 = 2,nrOfShots2 = 2;

int posX = 0,posY = 0;
TFT screen = TFT(cs, dc, rst);


void setup() {
  Serial.begin(9600); 
  pinMode(VRx, INPUT);
  pinMode(VRy, INPUT);
  pinMode(SW, INPUT_PULLUP); 

 for(int i = 0 ; i < 6 ; i++)
 {
  for(int j = 0 ; j < 6 ;j++)
      {
        map1[i][j] = 0;
        map2[i][j] = 0;
        map3[6][6] = 0;
        showmap1[i][j] = '-';
        showmap2[i][j] = '-';
        }
  }
  screen.begin();
  screen.background(0,0,0);
}


void display1()
{
  for(int i = 0 ; i < 6 ; i++)
    {
      for(int j = 0 ; j < 6 ;j++)
          {
            if(map1[i][j] == 0)
              {
                screen.fill(255,255,255);
                screen.rect((i+1)*20,(j+1)*15,10,10);
                screen.noFill();
                }
                else
                if(map1[i][j] == 1)
                {
                  screen.fill(0,255,0);
                  screen.rect((i+1)*20,(j+1)*15,10,10);
                screen.noFill();
                  }
                  else
                if(map1[i][j] == 2)
                {
                  screen.fill(255,0,0);
                  screen.rect((i+1)*20,(j+1)*15,10,10);
                screen.noFill();
                  }
                  else
                if(map1[i][j] == 2)
                {
                  screen.fill (0,0,128);
                  screen.rect((i+1)*20,(j+1)*15,10,10);
                screen.noFill();
                  }
            
            }
      }
      delay(500);
      screen.background(0,0,0);

  screen.stroke(255,0,255);
      screen.text("Player 2 wins",0,0);
  }

  void display2()
{
  for(int i = 0 ; i < 6 ; i++)
    {
      for(int j = 0 ; j < 6 ;j++)
          {
            if(map2[i][j] == 0)
              {
                screen.fill(255,255,255);
                screen.rect((i+1)*20,(j+1)*15,10,10);
                screen.noFill();
                }
                else
                if(map2[i][j] == 1)
                {
                  screen.fill(0,255,0);
                  screen.rect((i+1)*20,(j+1)*15,10,10);
                screen.noFill();
                  }
                  else
                if(map2[i][j] == 2)
                {
                  screen.fill(255,0,0);
                  screen.rect((i+1)*20,(j+1)*15,10,10);
                screen.noFill();
                  }
                  else
                if(map2[i][j] == 2)
                {
                  screen.fill (0,0,128);
                  screen.rect((i+1)*20,(j+1)*15,10,10);
                screen.noFill();
                  }
            
            }
            
      }
      delay(500);
      screen.background(0,0,0);

  screen.stroke(255,0,255);
      screen.text("Player 1 wins",0,0);
  }

  void display3(int x , int y){
     for(int i = 0 ; i < 6 ; i++)
    {
      for(int j = 0 ; j < 6 ;j++)
          {
            if(i != x || j != y)
              {
                screen.fill(255,255,255);
                screen.rect((i+1)*20,(j+1)*15,10,10);
                screen.noFill();
                }
                else
                {
                  screen.fill(0,255,255);
                  screen.rect((i+1)*20,(j+1)*15,10,10);
                screen.noFill();
                  }
            
            }
      }
    }

    void display4(int x , int y){
     for(int i = 0 ; i < 6 ; i++)
    {
      for(int j = 0 ; j < 6 ;j++)
          {
            if(i != x || j != y)
              {
                screen.fill(255,255,255);
                screen.rect((i+1)*20,(j+1)*15,10,10);
                screen.noFill();
                }
                else
                {
                  screen.fill(100,100,255);
                  screen.rect((i+1)*20,(j+1)*15,10,10);
                screen.noFill();
                  }
            
            }
      }
    }

void pl1(){
    
    if(mapX > 450)
      posX+=1;
      else
      if(mapX < -450 && posX > 0)
      posX-=1;

      if(mapY > 450)
      posY+=1;
      else
      if(mapY < -450 && posY > 0)
      posY-=1;

      display3(posX,posY);
      
      delay(100);

      if(SW_state == LOW && map1[posX][posY]!=1)
        map1[posX][posY] = 1;
      
        
  }

void pl2(){
    
    if(mapX > 450)
      posX+=1;
      else
      if(mapX < -450 && posX > 0)
      posX-=1;

      if(mapY > 450)
      posY+=1;
      else
      if(mapY < -450 && posY > 0)
      posY-=1;

      display4(posX,posY);
      
      delay(100);

      if(SW_state == LOW && map2[posX][posY]!=1)
        map2[posX][posY] = 1;
      
        
  }

  int map1Count(){
    int cnt = 0;
    for(int i = 0 ; i < 6 ; i++)
    {
      for(int j = 0 ; j < 6 ; j++)
          if(map1[i][j] == 0 || map1[i][j] == 2 || map1[i][j] == 3)
            cnt += 1;
      }

      return cnt;
    }

    int map2Count(){
    int cnt = 0;
    for(int i = 0 ; i < 6 ; i++)
    {
      for(int j = 0 ; j < 6 ; j++)
          if(map2[i][j] == 0 || map2[i][j] == 2 || map2[i][j] == 3)
            cnt += 1;
      }

      return cnt;
    }


  void pl1Attack(){
      if(mapX > 450)
      posX+=1;
      else
      if(mapX < -450 && posX > 0)
      posX-=1;

      if(mapY > 450)
      posY+=1;
      else
      if(mapY < -450 && posY > 0)
      posY-=1;

      display3(posX,posY);
       if(SW_state == LOW && map2[posX][posY]==1)
       {
        map2[posX][posY] = 2;
        nrOfShots1-=1;
       }
        else
        if(SW_state == LOW && map2[posX][posY]==0)
        {
         map2[posX][posY] = 3;
         nrOfShots1-=1;
        }
    }

    void pl2Attack(){
      if(mapX > 450)
      posX+=1;
      else
      if(mapX < -450 && posX > 0)
      posX-=1;

      if(mapY > 450)
      posY+=1;
      else
      if(mapY < -450 && posY > 0)
      posY-=1;

      display4(posX,posY);
       if(SW_state == LOW && map1[posX][posY]==1)
       {
        map1[posX][posY] = 2;
        nrOfShots2-=1;
       }
        else
        if(SW_state == LOW && map1[posX][posY]==0)
        {
         map1[posX][posY] = 3;
         nrOfShots2-=1;
        }
    }

void winner(){
    for(int i = 0 ; i < 6 ; i++)
    {
      for(int j = 0 ; j < 6 ; j++)
      {
        if(map1[i][j] == 2)
          winner2 +=1;

          if(map2[i][j] == 2)
          winner1 +=1;
        }
      }
  }

void loop() {
  
  xPosition = analogRead(VRx);
  yPosition = analogRead(VRy);
  SW_state = digitalRead(SW);
  mapX = map(xPosition, 0, 1023, -512, 512);
  mapY = map(yPosition, 0, 1023, -512, 512);
  
  Serial.print("X: ");
  Serial.print(mapX);
  Serial.print(" | Y: ");
  Serial.print(mapY);
  Serial.print(" | Button: ");
  Serial.println(SW_state);
  if(map1Count() >=35 )
  {
       pl1();
       delay(500);
  }
  
   if(map2Count() >=35 && map1Count()<35)
  {
       pl2();
       delay(500);
  }

  if(nrOfShots1 == nrOfShots2 && nrOfShots1!=0 && map1Count() < 35 && map2Count() < 35)
  {
      pl1Attack();
      delay(500);
  }
      else
      if(nrOfShots1 < nrOfShots2 && nrOfShots2!=0 && map1Count() < 35 && map2Count() < 35)
      {
      pl2Attack();
      delay(500);
      }
      else
      if(nrOfShots2==0 && nrOfShots1==0 )
      {
        if(winner1 > winner2)
            display2();
            else
            display1();
        }
  
}

 
