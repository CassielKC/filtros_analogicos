float vec[7]={0.0,0.0,0.0,0.0,0.0,0.0,0.0}, vec2[7]={0.0,0.0,0.0,0.0,0.0,0.0,0.0};
int i=0, j=0;
float aux,c=0, m, t;

void setup() 
{
   pinMode(A0, INPUT);
   Serial.begin(9600);
}

void loop() 
{
    c=analogRead(A0);
    c=c*(5.0/1023.0);
    t=c/0.01;

    vec[6]=vec[5];
    vec[5]=vec[4];
    vec[4]=vec[3];
    vec[3]=vec[2];
    vec[2]=vec[1];
    vec[1]=vec[0];
    vec[0]=t;

    vec2[6]=vec[6];
    vec2[5]=vec[5];
    vec2[4]=vec[4];
    vec2[3]=vec[3];
    vec2[2]=vec[2];
    vec2[1]=vec[1];
    vec2[0]=vec[0];

    for(i=0; i<7; i++)
    {
      for(j=0; j<6; j++)
      { 
        if(vec2[j]>vec2[j+1])
        {
          aux=vec2[j+1];
          vec2[j+1]=vec2[j];
          vec2[j]=aux;
        }
      }
    }
    
    m=vec2[3];
    Serial.println(m);
    delay(10);
}
