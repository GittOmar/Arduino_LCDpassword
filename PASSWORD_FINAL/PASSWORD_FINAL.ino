// 08/07/2021      day/month/year
// 6:47 Am
#include <LiquidCrystal.h>
const int rs = 12 , en = 11 , d4 = 4 , d5 = 5 , d6 = 6 , d7 = 7 ;  // LCD 
LiquidCrystal lcd( rs , en , d4 , d5 , d6 , d7 );

char Wpass[16];    // Write PassWord
char REpass[16];  // ReWrite PassWord

char New;       // Store Pressed KeYboard Buttons

bool confirm =true ;
bool confirm2 =true ;
bool confirm3 =true ;
bool confirm4 =true ;
bool Delete =false ; // for deleting letters in Prog.
bool fix =true ;  // fix lcd problems

int count=0;

int False=0; // for LOCKING Prog. after 5 wrong Password

void setup() 
{
 Serial.begin(9600); // Serial identify
 lcd.begin(16,2);    // LCD identify
 lcd.setCursor(0,0);
 lcd.print("Write Your Pass");
 lcd.setCursor(0,1);
}

void loop()
{
////////////////////////////////////////////////////////////////////////////////////  FIRST CONFIRM //////////////////////////////  
  here:  // First Sign
  
  while(confirm)       // First Confirm = Confirm
  {
    
    if(Serial.available() && New!='c')
  { 
    delay(10);
    Wpass[count]=Serial.read();
    New=Wpass[count];
    if(New!='c')   // If C isnt Pressed
    {
    if(New!='v')   // If V isnt Pressed
    {
    if(New!='/' && count==0)   // If / isnt Pressed
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
    
////////////////////////////////////////////////////////    
    // End of if(New!='/' && count==0)
////////////////////////////////////////////////////////
    
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
    
////////////////////////////////////////////////////////   
    //End of  if(New!='v')
////////////////////////////////////////////////////////
    
    
    }else
    {
       Wpass[count]=0;
       if(count==0 || count<5) 
       {
        New=0;
        fix=Serial.read();
        goto here;  // calling sign 
       }else if(count>=5)
       {
        confirm=false;
       }
      
    } 
    
////////////////////////////////////////////////////////    
    // End of   if(New!='c')
////////////////////////////////////////////////////////
    
   } 
   Wpass[15]=0;
  
  }

  
////////////////////////////////////////////////////////    
    // End of    while(confirm)
////////////////////////////////////////////////////////

////////////////////////////////////////////////////////////////////////////////////  FIRST PART END //////////////////////////////


////////////////////////////////////////////////////////////////////////////////////  SECOND CONFIRM //////////////////////////////

   while(confirm2)   // Second Confirm = Confirm2
  {   
  if(Serial.available()) 
  {
     New=0;
     New=Serial.read();
     
     if(New=='c')confirm2=false;    //If C is Pressed
                        
             
     if(New=='v')                  // If V is Pressed        
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
    
////////////////////////////////////////////////////////  
    //End of  if(New!='v')
////////////////////////////////////////////////////////
    
     }
     
  }
  
////////////////////////////////////////////////////////   
    // End of    while(confirm2)
////////////////////////////////////////////////////////

////////////////////////////////////////////////////////////////////////////////////  SECOND PART END //////////////////////////////


////////////////////////////////////////////////////////////////////////////////////  YES  OR   NO //////////////////////////////

  New=0;
  while(confirm3)  // Third Confirm = Confirm3
  {
    for(int z=0; z<=13;z++)
    {
     lcd.scrollDisplayLeft();       // ANIMATION
     New=z;
     delay(350);
    }
     if(New==13) 
     {
      lcd.clear();
      confirm3=false;
     }
  }
  
////////////////////////////////////////////////////////
    // End of    while(confirm3)
////////////////////////////////////////////////////////

  delay(250);
  lcd.setCursor(0,0);
  lcd.print("Change PassWord");
  delay(250);
  lcd.setCursor(2,1);
  lcd.print('Y');                   // ANIMATION
  lcd.setCursor(12,1);
  lcd.print('N');
  if(Serial.available())
  {
     New=0;
     New=Serial.read();
     if(New=='y')       // If Y is pressed  GOTO  START POINT here:
     {                  // y = YES CHANGE PASSWORD
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
      goto here;  // calling sign 
     }
     
//////////////////////////////////////////////////////// 
    //End of (New=='y')
////////////////////////////////////////////////////////

     else if(New=='n')     // If N is pressed COUNTINUE PROG.
     {                     // NO CHANGE IN PASSWORD AND WRITE NEW PASSWORD
      lcd.setCursor(13,1);
      lcd.print('o'); 
      delay(500);
      no();  // calling no Function
     }
     
////////////////////////////////////////////////////////
    //End of (New=='n'))
////////////////////////////////////////////////////////

  }
    
////////////////////////////////////////////////////////////////////////////////////  THIRD PART END ////////////////////////////// 


////////////////////////////////////////////////////////////////////////////////////  WRITEING FOR CHECK //////////////////////
 
}
void no()     // New Function Called no
{
  for(int t=0;t<2;t++)                        //Saving Password Animation
{
  lcd.clear();
  lcd.setCursor(1,0);  
  lcd.print("Saving Pass");
  delay(200);
  lcd.setCursor(12,0);
  lcd.print('.');                            //Saving Password Animation
  delay(200);
  lcd.setCursor(13,0);
  lcd.print('.');
  delay(200);
  lcd.setCursor(14,0);
  lcd.print('.');                          //Saving Password Animation
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
   here2:        // Second Sign   
                 // Writw Password Again in False Condition
   confirm4=true;
   count=0;
   fix=Serial.read(); 
   
  while(confirm4)   // Fourth Confirm = Confirm4
  {
    if(Serial.available() && New!='c')
  { 
    delay(10);
    REpass[count]=Serial.read();
    New=REpass[count];
    if(New!='c')   // If C isnt Pressed
    {
    if(New!='v')  // If V isnt Pressed
    {
       if(New!='/' && count==0)  // If / isnt Pressed
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
    
////////////////////////////////////////////////////////  
    // End of if(New!='/' && count==0)
////////////////////////////////////////////////////////

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
    
////////////////////////////////////////////////////////   
    //End of  if(New!='v')
////////////////////////////////////////////////////////

    }else
    {
       REpass[count]=0;
       if(count==0 ) 
       {
        New=0;
        fix=Serial.read();
        goto here2;  //Calling Sign
       }else 
       {
        confirm4=false;
       }
      
    }
    
////////////////////////////////////////////////////////    
    // End of   if(New!='c')
////////////////////////////////////////////////////////    
   } 
   
   REpass[15]=0;
  
  }
  
////////////////////////////////////////////////////////
    // End of    while(confirm4)
////////////////////////////////////////////////////////  

////////////////////////////////////////////////////////////////////////////////////  FOURTH PART END ////////////////////////////// 


////////////////////////////////////////////////////////////////////////////////////  TRUE OR FALSE ///////////////////////////////

  for(int o=0;o<15;o++)     // Compare First Password With Second Password
  {
     if(Wpass[o]==REpass[o])
     {
      
     }else
     {
      New='x'; 
     }
  }
  if(New=='x')  // If New = x 
  {
    // Wrong Password
    
                // false
    
   False++;    
   if(False<5)    // 5 TIMES LIMIT FOR WRONG PASSWORD
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
     goto here2; //Calling Sign
   }             // GO TO WRITE PASSWORD AGAIN 
   
////////////////////////////////////////////////////////
    // End of    if(False<5)
////////////////////////////////////////////////////////
    
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
  
  }
////////////////////////////////////////////////////////
    // End of    if(New=='x')
////////////////////////////////////////////////////////  
  else  // IF PASSWORD TRUE
  {
        //true
    
      while(true)
    {
     for(int d=0;d<2;d++)
  {
     lcd.clear();
     lcd.setCursor(0,0);
     lcd.print("CORRECT PASSWORD");  // TRUE ANIMATION
     delay(500);
     lcd.setCursor(0,0);
     lcd.print("                ");
     delay(500);
  }
    }
  }
}
////////////////////////////////////////////////////////////////////////////////////  FIFTH PART END ////////////////////////////// 


////////////////////////////////////////////////////////////////////////////////////  USED KEYS !!    /////////////////////////////

// < C > =  CONFIRM

// < V > = VISABLE

// < / > = DELETE

////////////////////////////////////////////////////////////////////////////////////  END    //////////////////////////////////////

// OMAR IBRAHIM MOHAMED IBRAHIM ATYA
