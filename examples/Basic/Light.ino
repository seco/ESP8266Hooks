int lightValue = 0;
int lightTimes = 0;

void readLight()
{
  int value = analogRead(A0);
  Serial.println(value);

  lightValue += value;
  lightTimes++;

  if(value < 600)
    writeLed("on");
}

void sendLight()
{
  int value = lightValue / lightTimes;
  String body = "{light: " + String(value, DEC) + "}";
  hooks.triggerEvent("Light_each_30_seconds", body);
  lightValue = 0;
  lightTimes = 0;
}
