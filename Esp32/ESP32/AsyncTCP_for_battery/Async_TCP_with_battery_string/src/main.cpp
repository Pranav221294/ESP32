#include <Arduino.h>
#include <WiFi.h>
#include <AsyncTCP.h>

const char* ssid     = "AIRTELDI";
const char* password = "9911227439dk";

#define  max   14.00
#define  min   11.00
//const char* ssid     = "Krishna pg";
//const char* password = "9999922556";


IPAddress serverIP = IPAddress(192, 168, 1, 6);   // change to server IP
//IPAddress serverIP = IPAddress(192, 168, 0, 111);
AsyncClient tcpClient;
unsigned long lastTick;
float a = 12.0;
char i[6]={0};
char v1[6]={0};char v8[6]={0};char v15[6]={0};char v22[6]={0};char v29[6]={0};char v36[6]={0};
char v2[6]={0};char v9[6]={0};char v16[6]={0};char v23[6]={0};char v30[6]={0};char v37[6]={0};
char v3[6]={0};char v10[6]={0};char v17[6]={0};char v24[6]={0};char v31[6]={0};char v38[6]={0};
char v4[6]={0};char v11[6]={0};char v18[6]={0};char v25[6]={0};char v32[6]={0};char v39[6]={0};
char v5[6]={0};char v12[6]={0};char v19[6]={0};char v26[6]={0};char v33[6]={0};char v40[6]={0};
char v6[6]={0};char v13[6]={0};char v20[6]={0};char v27[6]={0};char v34[6]={0};
char v7[6]={0};char v14[6]={0};char v21[6]={0};char v28[6]={0};char v35[6]={0};
float scale = 0.0;
static char tcpString[400];
const char init_str[]= "#A1RCI"; 
char tcp_read[4]={0};

 void random_values_fun()
 {

   scale = (float)rand() / (float) RAND_MAX;
    sprintf(v1,"%0.3f", (min + scale * ( max - min )));
  //  Serial.print("v1:");Serial.println(v1);


    scale = (float)rand() / (float) RAND_MAX;
    sprintf(v2,"%0.3f", (min + scale * ( max - min )));
   // Serial.print("v2:");Serial.println(v2);

    scale = (float)rand() / (float) RAND_MAX;
    sprintf(v3,"%0.3f", (min + scale * ( max - min )));
   // Serial.print("v3:");Serial.println(v3);

    scale = (float)rand() / (float) RAND_MAX;
    sprintf(v4,"%0.3f", (min + scale * ( max - min )));
 //   Serial.print("v4:");Serial.println(v4);

    scale = (float)rand() / (float) RAND_MAX;
    sprintf(v5,"%0.3f", (min + scale * ( max - min )));
 //   Serial.print("v5:");Serial.println(v5);

    scale = (float)rand() / (float) RAND_MAX;
    sprintf(v6,"%0.3f", (min + scale * ( max - min )));
 //   Serial.print("v6:");Serial.println(v6);
   
    scale = (float)rand() / (float) RAND_MAX;
    sprintf(v7,"%0.3f", (min + scale * ( max - min )));
//    Serial.print("v7:");Serial.println(v7);

     scale = (float)rand() / (float) RAND_MAX;
     sprintf(v8,"%0.3f", (min + scale * ( max - min )));
 //  Serial.print("v8:");Serial.println(v8);



  //   scale = (float)rand() / (float) RAND_MAX;
  //   sprintf(v9,"%0.3f", (min + scale * ( max - min )));
  //   Serial.print("v9:");Serial.println(v9);


  //   scale = (float)rand() / (float) RAND_MAX;
  //   sprintf(v10,"%0.3f", (min + scale * ( max - min )));
  //   Serial.print("v10:");Serial.println(v10);

  //  scale = (float)rand() / (float) RAND_MAX;
  //   sprintf(v11,"%0.3f", (min + scale * ( max - min )));
  //  Serial.print("v11:");Serial.println(v11);

  //   scale = (float)rand() / (float) RAND_MAX;
  //   sprintf(v12,"%0.3f", (min + scale * ( max - min )));
  //   Serial.print("v12:");Serial.println(v12);

  //   scale = (float)rand() / (float) RAND_MAX;
  //   sprintf(v13,"%0.3f", (min + scale * ( max - min )));
  //   Serial.print("v13:");Serial.println(v13);

  //   scale = (float)rand() / (float) RAND_MAX;
  //   sprintf(v14,"%0.3f", (min + scale * ( max - min )));
  //   Serial.print("v14:");Serial.println(v14);

  //   scale = (float)rand() / (float) RAND_MAX;
  //   sprintf(v15,"%0.3f", (min + scale * ( max - min )));
  //   Serial.print("v15:");Serial.println(v15);
   
  //   scale = (float)rand() / (float) RAND_MAX;
  //   sprintf(v16,"%0.3f", (min + scale * ( max - min )));
  //   Serial.print("v16:");Serial.println(v16);

  //    scale = (float)rand() / (float) RAND_MAX;
  //   sprintf(v17,"%0.3f", (min + scale * ( max - min )));
  //   Serial.print("v17:");Serial.println(v17);

  //   scale = (float)rand() / (float) RAND_MAX;
  //   sprintf(v18,"%0.3f", (min + scale * ( max - min )));
  //   Serial.print("v18:");Serial.println(v18);

  //   scale = (float)rand() / (float) RAND_MAX;
  //   sprintf(v19,"%0.3f", (min + scale * ( max - min )));
  //   Serial.print("v19:");Serial.println(v19);


  //   scale = (float)rand() / (float) RAND_MAX;
  //   sprintf(v20,"%0.3f", (min + scale * ( max - min )));
  //   Serial.print("v20:");Serial.println(v20);

  //    scale = (float)rand() / (float) RAND_MAX;
  //   sprintf(v21,"%0.3f", (min + scale * ( max - min )));
  //   Serial.print("v21:");Serial.println(v21);

  //   scale = (float)rand() / (float) RAND_MAX;
  //   sprintf(v22,"%0.3f", (min + scale * ( max - min )));
  //   Serial.print("v22:");Serial.println(v22); 

  //   scale = (float)rand() / (float) RAND_MAX;
  //   sprintf(v23,"%0.3f", (min + scale * ( max - min )));
  //   Serial.print("v23:");Serial.println(v23);

  //   scale = (float)rand() / (float) RAND_MAX;
  //   sprintf(v24,"%0.3f", (min + scale * ( max - min )));
  //   Serial.print("v24:");Serial.println(v24);
    
  //    scale = (float)rand() / (float) RAND_MAX;
  //   sprintf(v25,"%0.3f", (min + scale * ( max - min )));
  //   Serial.print("v25:");Serial.println(v25);

  //   scale = (float)rand() / (float) RAND_MAX;
  //   sprintf(v26,"%0.3f", (min + scale * ( max - min )));
  //   Serial.print("v26:");Serial.println(v26);

  //   scale = (float)rand() / (float) RAND_MAX;
  //   sprintf(v27,"%0.3f", (min + scale * ( max - min )));
  //   Serial.print("v27:");Serial.println(v27);

  //   scale = (float)rand() / (float) RAND_MAX;
  //   sprintf(v28,"%0.3f", (min + scale * ( max - min )));
  //   Serial.print("v28:");Serial.println(v28);
    
  //   scale = (float)rand() / (float) RAND_MAX;
  //   sprintf(v29,"%0.3f", (min + scale * ( max - min )));
  //   Serial.print("v29:");Serial.println(v29);

  //   scale = (float)rand() / (float) RAND_MAX;
  //   sprintf(v30,"%0.3f", (min + scale * ( max - min )));
  //   Serial.print("v30:");Serial.println(v30);

  //   scale = (float)rand() / (float) RAND_MAX;
  //   sprintf(v31,"%0.3f", (min + scale * ( max - min )));
  //  Serial.print("v31:");Serial.println(v31);

  //  scale = (float)rand() / (float) RAND_MAX;
  //   sprintf(v32,"%0.3f", (min + scale * ( max - min )));
  //  Serial.print("v32:");Serial.println(v32);

  //   scale = (float)rand() / (float) RAND_MAX;
  //   sprintf(v33,"%0.3f", (min + scale * ( max - min )));
  //   Serial.print("v33:");Serial.println(v33);

  //   scale = (float)rand() / (float) RAND_MAX;
  //   sprintf(v34,"%0.3f", (min + scale * ( max - min )));
  //   Serial.print("v34:");Serial.println(v34);

  //   scale = (float)rand() / (float) RAND_MAX;
  //   sprintf(v35,"%0.3f", (min + scale * ( max - min )));
  //   Serial.print("v35:");Serial.println(v35);

  //   scale = (float)rand() / (float) RAND_MAX;
  //   sprintf(v36,"%0.3f", (min + scale * ( max - min )));
  //   Serial.print("v36:");Serial.println(v36);

  //   scale = (float)rand() / (float) RAND_MAX;
  //   sprintf(v37,"%0.3f", (min + scale * ( max - min )));
  //   Serial.print("v37:");Serial.println(v37);

  //   scale = (float)rand() / (float) RAND_MAX;
  //   sprintf(v38,"%0.3f", (min + scale * ( max - min )));
  //   Serial.print("v38:");Serial.println(v38);

  //   scale = (float)rand() / (float) RAND_MAX;
  //   sprintf(v39,"%0.3f", (min + scale * ( max - min )));
  //   Serial.print("v39:");Serial.println(v39);

  //   scale = (float)rand() / (float) RAND_MAX;
  //   sprintf(v40,"%0.3f", (min + scale * ( max - min )));
  //   Serial.print("v40:");Serial.println(v40);

    scale = (float)rand() / (float) RAND_MAX;
    sprintf(i,"%0.3f", (min + scale * ( max - min )));
    Serial.print("i:");Serial.println(i);
}

void creat_tcp()
{
  Serial.println("<-- START MAKING STRING -->\r\n");
  
    memset(tcpString,'\0',400);
    Serial.println("<-- ----- -->\r\n");
    Serial.println(tcpString);strcat(tcpString,init_str);

    scale = (float)rand() / (float) RAND_MAX;
    sprintf(i,"%0.3f", (min + scale * ( max - min )));
    strcat(tcpString,i);//IMEI NO.//1
    strcat(tcpString, ",");
    
    scale = (float)rand() / (float) RAND_MAX;
    sprintf(v1,"%0.3f", (min + scale * ( max - min )));
		strcat(tcpString,v1);//SERIAL.NO//2
    strcat(tcpString, ",");  
    
    scale = (float)rand() / (float) RAND_MAX;
    sprintf(v2,"%0.3f", (min + scale * ( max - min )));
    strcat(tcpString,v2);//GIS MAPPING//3
    strcat(tcpString, ","); 
   
    scale = (float)rand() / (float) RAND_MAX;
    sprintf(v3,"%0.3f", (min + scale * ( max - min )));
	  strcat(tcpString,v3);//BATTERY VOLTAGE//4
	  strcat(tcpString, ",");  
	  
    scale = (float)rand() / (float) RAND_MAX;
    sprintf(v4,"%0.3f", (min + scale * ( max - min )));
    strcat(tcpString,v4);//CAHRGING CURRENT//5
	  strcat(tcpString, ",");
	  
    scale = (float)rand() / (float) RAND_MAX;
    sprintf(v5,"%0.3f", (min + scale * ( max - min )));
    strcat(tcpString,v5);//BATTERY POWER//6
	  strcat(tcpString, ","); 
		
    scale = (float)rand() / (float) RAND_MAX;
    sprintf(v6,"%0.3f", (min + scale * ( max - min )));
    strcat(tcpString,v6);//SOLAR VOLTAGE//7
		strcat(tcpString, ",");

    scale = (float)rand() / (float) RAND_MAX;
    sprintf(v7,"%0.3f", (min + scale * ( max - min )));
		strcat(tcpString,v7);//SOLAR CURRENT//8
		strcat(tcpString, ","); 

    scale = (float)rand() / (float) RAND_MAX;
    sprintf(v8,"%0.3f", (min + scale * ( max - min )));
		strcat(tcpString,v8);//SOLAR POWER//9
		// strcat(tcpString, "$");
		// strcat(tcpString,v9);//LOAD VOLTAGE//10
		// strcat(tcpString, "$");
		// strcat(tcpString,v10);// LOAD CURRRENT//11
		// strcat(tcpString, "$");
		// strcat(tcpString,v11);//LOAD POWER//12
		// strcat(tcpString, "$");
		// strcat(tcpString,v12);//RUNNING STATUS//13
		// strcat(tcpString, "$");
		// strcat(tcpString,v13);//BATTERY FAULT//14
		// strcat(tcpString, "$");
		// strcat(tcpString,v14);//MODULE FAULT//15
		// strcat(tcpString, "$");
		// strcat(tcpString,v15);//SSL FAULT//16
		// strcat(tcpString, "$");
		// strcat(tcpString,v16);//BATTERY FAULT DATE//17
		// strcat(tcpString, "$");
		// strcat(tcpString,v17);//MODULE FAULT DATE//18
		// strcat(tcpString, "$");
		// strcat(tcpString,v18);
		// strcat(tcpString,"$");//SSL FAULT DATE//19
		// strcat(tcpString, v19);
		// strcat(tcpString, "$");
		// strcat(tcpString,v20);//ON TIME//20
		// strcat(tcpString, "$");
		// strcat(tcpString,v21);//OFF TIME//21
		// strcat(tcpString, "$");
		// strcat(tcpString,v22);//FAULT DATTE//22
		// strcat(tcpString, "$");
		// strcat(tcpString,v23);//FAULT TIME//22
		// strcat(tcpString, "$");
		// strcat(tcpString,v24);//FAULT RECTIFICATION DATE//23
		// strcat(tcpString, "$");
		// strcat(tcpString,v25);//FAULT RECTIFICATION TIME//23
		// strcat(tcpString, "$");
		// strcat(tcpString,v26);//BRIGHTNESS LEVEL//24
		// strcat(tcpString, "$");
		// strcat(tcpString,v27);//FULL BRIGHTNESS HOURS//25
		// strcat(tcpString, "$");
		// strcat(tcpString,v28);//HALF BRIGHTNESS HOURS//26
		// strcat(tcpString, "$");
	  // strcat(tcpString,v29);//HARVESTED ENERGY//27
		// strcat(tcpString, "$");
		// strcat(tcpString,v30);//BATTERY STATE OF CHARGE//28
		// strcat(tcpString, "$");
		// strcat(tcpString,v31);//BATTERY DEPTH OF DISCHARGE//29
		// strcat(tcpString, "$");
		// strcat(tcpString,v32);//CONSUMPTION OF POWER BY GPS AND GSM//30
		// strcat(tcpString, "$");
		// strcat(tcpString,v33); //LATITUDE//31
		// strcat(tcpString,"$");
		// strcat(tcpString,v34);//LONGITUDE//32
		// strcat(tcpString,"$");
		// strcat(tcpString,v35);//APP DATE //33
		// strcat(tcpString, "$");
		// strcat(tcpString,v36);//APP TIME//33
		// strcat(tcpString, "$");
		// strcat(tcpString,v37);//SIM NO//34
		// strcat(tcpString, "$");
    // strcat(tcpString,v38);//APP DATE //33
		// strcat(tcpString, "$");
		// strcat(tcpString,v39);//APP TIME//33
		// strcat(tcpString, "$");
		// strcat(tcpString,v40);//SIM NO//34
    strcat(tcpString,"@");//SIM NO//34
    strcat(tcpString,"\n");//SIM NO//34
   Serial.println(tcpString);
}
 //float scale

// double randomDouble(double minf, double maxf)
// {
//   //return minf + random(1UL << 31) * (maxf - minf) / (1UL << 31);  // use 1ULL<<63 for max double values)
  

// }

// float float_rand( float min, float max )
// {
//     float scale = (float)rand() / (float) RAND_MAX; /* [0, 1.0] */
//     return min + scale * ( max - min );      /* [min, max] */
//}

void sendStringToServer( String sendMsg )
{
    if( !tcpClient.connected()) { return; }
    if( !tcpClient.canSend() )  { return; }
    
    if ( tcpClient.space() > sendMsg.length() ) 
    {
          tcpClient.add( sendMsg.c_str() , sendMsg.length() );
          tcpClient.send();
    }
}

static void handleData(void* arg, AsyncClient* client, void *data, size_t len)
{
    //Serial.print("[CALLBACK] data received, ip: " + client->remoteIP().toString());
    //Serial.println( " [" + String((char*)data) + "]");
    // Serial.write((uint8_t*)data, len);
     sprintf(tcp_read,"%s",data);
     Serial.printf(tcp_read);
    // or loop through data , using data[i] and len:
    // for ( int i = 0 ; i < len ; i++ ) {
    //     if ( uint8_t*)data[i] == 0 ) { } }

    // could send to server here, by doing:
    // sendToServer( "Hello!"); 
}

static void handleError(void* arg, AsyncClient* client, int8_t error) 
{
    Serial.println("[CALLBACK] error");
     switch (error) {
    case 0:
      // No error
      break;
    case 1:
      // DNS lookup failed
      Serial.println("Error: DNS lookup failed");
      break;
    case 2:
      // Failed to connect to the server
      Serial.println("Error: Failed to connect to the server");
      break;
    case 3:
      // Connection timeout
      Serial.println("Error: Connection timeout");
      break;
    default:
      // Unknown error
      Serial.println("Error: Unknown error");
  }



}

static void handleTimeOut(void* arg, AsyncClient* client, uint32_t time) 
{
    Serial.println("[CALLBACK] ACK timeout");
}

static void handleDisconnect(void* arg, AsyncClient* client) 
{
    Serial.println("[CALLBACK] discconnected");
     // Handle disconnection
  Serial.println("Disconnected from server");
  // Reconnect to the server after 2 seconds
  delay(2000);
   tcpClient.connect( serverIP , 100 );
}

static void handleConnect(void* arg, AsyncClient* client) 
{
    Serial.println("[CALLBACK] connected");
}

void setup()
{
    Serial.begin(115200);
    Serial.println("");

     //dtostrf(f_val,7, 3, outstr);

    WiFi.begin(ssid, password);
    Serial.print("[WIFI] connecting to network " + String(ssid) );
    
    while (WiFi.status() != WL_CONNECTED) {  delay(500); Serial.print(".");  }
    Serial.println("[WIFI] connected with Ip: " + WiFi.localIP().toString() );

    tcpClient.onData(&handleData, NULL);
    tcpClient.onError(&handleError, NULL);
    tcpClient.onTimeout(&handleTimeOut, NULL);
    tcpClient.onDisconnect(&handleDisconnect, NULL);
    tcpClient.onConnect(&handleConnect,NULL);
    
    tcpClient.connect( serverIP , 100 );
}

void loop()
{
   // if( millis() - lastTick > 2000 ) // every 2 sec
   if(tcp_read[0]=='1'&&tcp_read[1]=='R'&&tcp_read[2]=='2')
  {
       Serial.println("[MAIN] loop still going , connected: " + String( tcpClient.connected()) );
     //   lastTick = millis();
       // random_values_fun();
        creat_tcp();
        sendStringToServer(tcpString);
        tcp_read[0] = 0;tcp_read[1] = 0;tcp_read[2] = 0;tcp_read[3] = 0;
       // sendStringToServer("D1I5V12.000,10.000,13.000,2.000,10.000,13.000,2.000,10.000,13.000,2.000,10.000,13.000,2.000,10.000,13.000,2.000,10.000,13.000,2.000,10.000,13.000,2.000,10.000,13.000,2.000,10.000,13.000,2.000,10.000,13.000,2.000,10.000,13.000,2.000,10.000,13.000");
    }
}
