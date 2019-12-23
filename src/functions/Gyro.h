
void initGyro(){
    mpu6050.begin();
    mpu6050.calcGyroOffsets(true);
}

void getGyro(){
    mpu6050.update();
    GyroZ = mpu6050.getAngleZ();
}