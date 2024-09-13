#include <LiquidCrystal.h>
const int rs = 12 , en = 11 , d4 = 4 , d5 = 5 , d6 = 6 , d7 = 7 ;
LiquidCrystal lcd( rs , en , d4 , d5 , d6 , d7 );

char Wpass[16];
char REpass[16];
char New;
bool confirm =true ;
bool confirm2 =true ;
bool confirm3 =true ;
bool confirm4 =true ;
bool Delete =false ;
bool fix =true ;

int count=0;
int False=0;
void setup() 
{
 Serial.begin(9600);
 lcd.begin(16,2);
 lcd.setCursor(0,0);
 lcd.print("Write Your Pass");
 lcd.setCursor(0,1);
}

void loop()
{
  here:
  while(confirm)
  {
    if(Serial.available() && New!='c')
  { 
    delay(10);
    Wpass[count]=Serial.read();
    New=Wpass[count];
    if(New!='c')
    {
    if(New!='v')
    {
    if(New!='/' && count==0)
    {
        
    }
    else if(New=='/' && count<16 )
    {
      Wpass[count]=0;
      lcd.setCursor(0,1);
      lcd.print("                ");
      lcd.setCursor(0,1);
      if(count==0)count=0;
      if(count>1)
      {
      count=count-2;
      for(int m=0; m<count;m++)
    
       {
       lcd.print('*');
       }
       
      }else if(count==1)
      {
      Wpass[count]=0;
      count=0;
      lcd.setCursor(0,1);
      lcd.print("      ");
      lcd.setCursor(0,1);
      Delete =true ;
      }
   
    }
    count++;
    if(count<=15 && Delete ==false)
    {
      lcd.print('*');
    }else if(Delete ==true )
    {
      count=0;
      Delete =false ;
    }
    else{
      
    }
    fix=Serial.read();
    }
    else
    {
      Wpass[count]=0;
      if(count>=15)count=15;
      lcd.setCursor(0,1);
      lcd.print("                ");
      delay(500);
      lcd.setCursor(0,1);
      for(int u=0; u<count;u++)
  {
   lcd.print(Wpass[u]);
  }
  
      delay(2000);
      lcd.setCursor(0,1);
      lcd.print("                ");
      lcd.setCursor(0,1);
      
      for(int q=0; q<count;q++)
  {
   lcd.print('*');
  }
    fix=Serial.read(); 
    }
    }else
    {
       Wpass[count]=0;
       if(count==0 || count<5) 
       {
        New=0;
        fix=Serial.read();
        goto here;
       }else if(count>=5)
       {
        confirm=false;
       }
      
    }
   } 
   Wpass[15]=0;
  
  }
  
  
   while(confirm2)
  {   
  if(Serial.available())
  {
     New=0;
     New=Serial.read();
     if(New=='c')confirm2=false;
        if(New=='v')
    {
      lcd.setCursor(0,1);
      lcd.print("                ");
      delay(500);
      lcd.setCursor(0,1);
      for(int u=0; u<count;u++)
  {
   lcd.print(Wpass[u]);
  }
      delay(2000);
      lcd.setCursor(0,1);
      lcd.print("                ");
      lcd.setCursor(0,1);
      for(int q=0; q<count;q++)
  {
   lcd.print('*');
  }
    }
    
     }
     
  }
  New=0;
  while(confirm3)
  {
    for(int z=0; z<=13;z++)
    {
     lcd.scrollDisplayLeft();
     New=z;
     delay(350);
    }
     if(New==13) 
     {
      lcd.clear();
      confirm3=false;
     }
  }
  delay(250);
  lcd.setCursor(0,0);
  lcd.print("Change PassWord");
  delay(250);
  lcd.setCursor(2,1);
  lcd.print('Y');
  lcd.setCursor(12,1);
  lcd.print('N');
  if(Serial.available())
  {
     New=0;
     New=Serial.read();
     if(New=='y')
     {
      lcd.setCursor(3,1);
      lcd.print("es");
      delay(500);
      lcd.clear();
      lcd.setCursor(0,0);
      lcd.print("Write New Pass");
      lcd.setCursor(0,1);
      
      confirm =true ;
      confirm2 =true ;
      confirm3 =true ;
      fix =true ;
      count=0;
      New=0;
      for(int y=0; y<=15;y++)
      {
        Wpass[y]=0;
      }
      confirm4 =true ;
       fix=Serial.read();
      goto here;
     }
     else if(New=='n')
     {
      lcd.setCursor(13,1);
      lcd.print('o'); 
      delay(500);
      no();
     }
  }
}
void no()
{
  for(int t=0;t<2;t++)
{
  lcd.clear();
  lcd.setCursor(1,0);
  lcd.print("Saving Pass");
  delay(200);
  lcd.setCursor(12,0);
  lcd.print('.');
  delay(200);
  lcd.setCursor(13,0);
  lcd.print('.');
  delay(200);
  lcd.setCursor(14,0);
  lcd.print('.');
  delay(200);
  lcd.setCursor(15,0);
  lcd.print('.');
  delay(200);
  lcd.setCursor(12,0);
  lcd.print("    ");
  delay(250);
}

  lcd.setCursor(1,0);
  lcd.print("PassWord Saved");
  delay(1500);
  
  lcd.clear();
  lcd.setCursor(4,0);
  lcd.print("PassWord");
  lcd.setCursor(0,1);
   here2:
   confirm4=true;
   count=0;
   fix=Serial.read(); 
   
  while(confirm4)
  {
    if(Serial.available() && New!='c')
  { 
    delay(10);
    REpass[count]=Serial.read();
    New=REpass[count];
    if(New!='c')
    {
    if(New!='v')
    {
       if(New!='/' && count==0)
    {
        
    }
    else if(New=='/' && count<16 )
    {
      REpass[count]=0;
      lcd.setCursor(0,1);
      lcd.print("                ");
      lcd.setCursor(0,1);
      if(count==0)count=0;
      if(count>1)
      {
      count=count-2;
      for(int m=0; m<count;m++)
    
       {
       lcd.print('*');
       }
       
      }else if(count==1)
      {
      REpass[count]=0;
      count=0;
      lcd.setCursor(0,1);
      lcd.print("      ");
      lcd.setCursor(0,1);
      Delete =true ;
      }
   
    }
    count++;
     if(count<=15 && Delete ==false)
    {
      lcd.print('*');
    }else if(Delete ==true )
    {
      count=0;
      Delete =false ;
    }
    else{
      
    }
    fix=Serial.read();
    }
    else
    {
      REpass[count]=0;
      if(count>=15)count=15;
      lcd.setCursor(0,1);
      lcd.print("                ");
      delay(500);
      lcd.setCursor(0,1);
      for(int u=0; u<count;u++)
  {
   lcd.print(REpass[u]);
  }
  
      delay(2000);
      lcd.setCursor(0,1);
      lcd.print("                ");
      lcd.setCursor(0,1);
      
      for(int q=0; q<count;q++)
  {
   lcd.print('*');
  }
    fix=Serial.read(); 
    }
    }else
    {
       REpass[count]=0;
       if(count==0 ) 
       {
        New=0;
        fix=Serial.read();
        goto here2;
       }else 
       {
        confirm4=false;
       }
      
    }
   } 
   REpass[15]=0;
  
  }
  for(int o=0;o<15;o++)
  {
     if(Wpass[o]==REpass[o])
     {
      
     }else
     {
      New='x';
     }
  }
  if(New=='x')
  {
    // false
   False++;
   if(False<5)
   {
     for(int x=0;x<2;x++)
  {
     lcd.clear();
     lcd.setCursor(1,0);
     lcd.print("Wrong Password");
     delay(250);
     lcd.setCursor(1,0);
     lcd.print("               ");
     delay(250);
  }
     lcd.clear();
     lcd.setCursor(4,0);
     lcd.print("PassWord");
     lcd.setCursor(0,1);
     confirm4=true;
     count=0;
     fix=Serial.read(); 
     goto here2;
   }
   else
   {
    while(true)
    {
     lcd.clear();
     lcd.setCursor(5,0);
     lcd.print("LOCKED");
     delay(500);
     lcd.setCursor(1,0);
     lcd.print("               ");
     delay(500);
    }
   }
  
  }else
  {
    //true
      while(true)
    {
     for(int d=0;d<2;d++)
  {
     lcd.clear();
     lcd.setCursor(0,0);
     lcd.print("CORRECT PASSWORD");
     delay(500);
     lcd.setCursor(0,0);
     lcd.print("                ");
     delay(500);
  }
    }
  }
}
