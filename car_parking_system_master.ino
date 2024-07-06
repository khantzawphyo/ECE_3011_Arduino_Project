/**
 * @file car_parking_system_master.ino
 * @author ECE 3011 (Group 2)
 * 
 */

int trigpins[6] = {2, 4, 6, 8, 10, 12};
int echopins[6] = {3, 5, 7, 9, 11, 13};
void setup()
{
    Serial.begin(9600);
    // trigpins
    pinMode(2, OUTPUT);
    pinMode(4, OUTPUT);
    pinMode(6, OUTPUT);
    pinMode(8, OUTPUT);
    pinMode(10, OUTPUT);
    pinMode(12, OUTPUT);

    // echopins
    pinMode(3, INPUT);
    pinMode(5, INPUT);
    pinMode(7, INPUT);
    pinMode(9, INPUT);
    pinMode(11, INPUT);
    pinMode(13, INPUT);
}

void loop()
{
    char slot;
    int trig, echo;
    for (int i = 0; i < 6; i++)
    {
        trig = trigpins[i];
        ECE 3011

            18

            echo = echopins[i];
        slot = ultrasensor_slot_assigning(trig, echo);
        Serial.write(slot);
    }
    delay(100);
}

char ultrasensor_slot_assigning(int trig, int echo)
{
    char slot;
    long duration, distance;

    digitalWrite(trig, LOW);
    delayMicroseconds(2);
    digitalWrite(trig, HIGH);
    delayMicroseconds(10);
    digitalWrite(trig, LOW);

    duration = pulseIn(echo, HIGH);
    distance = duration / 29 / 2;

    if (distance < 5)
    {
        slot = '1';
    }
    else
    {
        slot = '0';
    }
    return slot;
}