#include <stdio.h>
#include <assert.h>
int temperatureRangeIsOk(float);
int SocIsOk(float);
int chargeRateIsOk(float);

int batteryIsOk(int (*Batt_Chek[])(float),float *BMS_Input,int NoOfCheck) 
{
 int ret_batt_stat=1;
 int i;

   for(i=0;i<NoOfCheck;i++)
   {
      if(Batt_Chek[i](BMS_Input[i])!=1)
      return ret_batt_stat;
   }
  return ret_batt_stat;
}

int temperatureRangeIsOk(float temperature)
{
  int temperature_stat=1;
   if(temperature < 0) 
   {
       printf("Temperature is lesser than minimum and is out of range!\n");
       temperature_stat=0;
   }
  else if(temperature > 45) 
   {
       printf("Temperature is greater than maximum and is out of range!\n");
       temperature_stat=0;
   }
  return temperature_stat;
}

int SocIsOk(float soc)
{
  int soc_stat=1;
   if(soc < 20) 
   {
       printf("Soc is lesser than minimum and is out of range!\n");
       soc_stat=0;
   }
  else if(soc > 80) 
   {
       printf("Soc is greater than maximum and is out of range!\n");
       soc_stat=0;
   }
  return soc_stat;
}

int chargeRateIsOk(float chargeRate)
{
  int chargeRate_stat=1;
   if(chargeRate > 0.8) 
   {
       printf("chargeRate is out of range!\n");
       chargeRate_stat=0;
   }
  return chargeRate_stat;
}
  
int main() {
 int Batt_Stat;
 int (*Batt_Chek[3])(float);
 Batt_Chek[0]=temperatureRangeIsOk;
 Batt_Chek[1]=SocIsOk;
 Batt_Chek[2]=chargeRateIsOk;
 float BMS_Input[3]={2,90,0.9};
 Batt_Stat=batteryIsOk(Batt_Chek,BMS_Input,3);
 assert(Batt_Stat==1);
  }
