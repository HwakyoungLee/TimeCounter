//*******************************************************************************************************************
//                                                  I2C TX RX
//*******************************************************************************************************************
void I2C_TX(byte device, byte regadd, byte tx_data)                              // Transmit I2C Data
{
  Wire.beginTransmission(device);
  Wire.write(regadd);
  Wire.write(tx_data);
  Wire.endTransmission();
}

uint8_t I2C_RX(byte devicerx, byte regaddrx)                                       // Receive I2C Data
{
  uint8_t i2cData = 0;
  
  Wire.beginTransmission(devicerx);
  Wire.write(regaddrx);
  Wire.endTransmission();
  Wire.requestFrom(int(devicerx), 1);

  byte c = 0;
  if (Wire.available()) {
    i2cData = Wire.read();
  }
  
  return i2cData;
}

