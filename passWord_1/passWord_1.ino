#define led1 10
#define led2 9
char password[]="";
char RePass;
char answer;
int Size=0;
void setup() 
{
  pinMode(led1,OUTPUT);
  pinMode(led2,OUTPUT);
  Serial.begin(9600);
  Serial.println("Enter PassWord :");
}

void loop() 
{
  if(Serial.available())
  {
    for(int i=0;i<10;i++)
    {
        password[i]=Serial.read();
    }
     for(int u=0;u<10;u++)
    {
        Serial.print(password[u]);
    }
    

 
  }

 

}
