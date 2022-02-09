#include <stdio.h>
#include <assert.h>
int temperatureRangeIsOk(float);
int SocIsOk(float);
int chargeRateIsOk(float);

int batteryIsOk(float temperature, float soc, float chargeRate) {
 int ret_batt_stat;
 if(ret_batt_stat=temperatureRangeIsOk(temperature))!=True)
   return ret_batt_stat;
 else if(ret_batt_stat=SocIsOk(soc))!=True)
    return ret_batt_stat;
 else if(ret_batt_stat=chargeRateIsOk(chargeRate))!=True)
    return ret_batt_stat;
  return 1;
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
  else if(temperature > 80) 
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
  assert(batteryIsOk(25, 70, 0.7));
  assert(!batteryIsOk(50, 85, 0));
}
