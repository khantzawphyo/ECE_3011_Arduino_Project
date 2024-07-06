/**
 * @file car_parking_system_slave.ino
 * @author ECE 3011 (Group 2)
 * 
 */
#include <LiquidCrystal.h>
#include <Servo.h>

#define trigIn 2
#define echoIn 4
#define trigOut 5
#define echoOut 7
LiquidCrystal lcd(13, 12, 11, 10, 9, 8);

Servo inGate;
Servo outGate;

char check_slots[6] = {'0', '0', '0', '0', '0', '0'};
char slots[6];
int free_slot = 6; // free slot for parking
void setup()
{

    Serial.begin(9600);
    inGate.attach(3);
    outGate.attach(6);

    pinMode(echoIn, INPUT);
    pinMode(echoOut, INPUT);
    pinMode(trigIn, OUTPUT);
    pinMode(trigOut, OUTPUT);

    lcd.begin(20, 4);

    ECE 3011

        20

        inGate.write(180);
    outGate.write(0);
}

void loop()
{
    long distanceIn, distanceOut = 0;
    int inflag = 1;
    if (Serial.available() >= 6)
    {
        for (int i = 0; i < 6; i++)
        {
            slots[i] = Serial.read();
        }

        for (int i = 0; i < 6; i++)
        {
            Serial.print("slot");
            Serial.print(i + 1);
            Serial.print(":");
            Serial.println(slots[i]);
        }
        int total = 0;
        for (int j = 0; j < 6; j++)
        {
            if (slots[j] == check_slots[j])
            {
                total += 0;
            }
            else
            {
                if (slots[j] == '1')
                {
                    check_slots[j] = slots[j];
                    total += 1;
                }
                if (slots[j] == '0')
                {
                    check_slots[j] = slots[j];
                    total -= 1;
                    ECE 3011

                        21
                }
            }
        }
        Serial.print("Total = ");
        Serial.println(total);
        free_slot -= total;

        // lcd display
        lcd.clear();
        lcd.setCursor(0, 0);
        lcd.print("Free slots :");
        lcd.print(free_slot);

        // Display Parking Full message if no free slots available
        if (free_slot == 0)
        {
            lcd.setCursor(0, 1);
            lcd.print("Parking FULL");
        }
        else
        {
            lcd.setCursor(0, 1);
            lcd.print("             "); // Clear the line if not full.
        }

        // Display available slots numbers for upstairs
        lcd.setCursor(0, 2);
        lcd.print("1st: ");
        for (int i = 0; i < 3; i++)
        {
            if (slots[i] == '0')
            {
                lcd.print(i + 1);
                lcd.print(" ");
            }
            ECE 3011

                22
        }
        // Display available slots numbers for downstairs
        lcd.setCursor(0, 3);
        lcd.print("2nd: ");
        for (int i = 3; i < 6; i++)
        {
            if (slots[i] == '0')
            {
                lcd.print(i + 1);
                lcd.print(" ");
            }
        }

        Serial.print("Free_slot = ");
        Serial.println(free_slot);

        if (free_slot == 0)
        {
            inflag = 0;
        }

        // for ingate and outgate with ultrasonic sensors
        long durationIn, durationOut;

        digitalWrite(trigIn, LOW);
        delayMicroseconds(2);
        digitalWrite(trigIn, HIGH);
        delayMicroseconds(10);
        digitalWrite(trigIn, LOW);

        durationIn = pulseIn(echoIn, HIGH);
        distanceIn = durationIn / 29 / 2;
        ECE 3011

            23

            if (distanceIn < 7 && inflag != 0)
        {
            inGate.write(90);
            Serial.println("InGate opened.");
        }
        else
        {
            inGate.write(180);
            Serial.println("InGate not opened.");
        }

        digitalWrite(trigOut, LOW);
        delayMicroseconds(2);
        digitalWrite(trigOut, HIGH);
        delayMicroseconds(10);
        digitalWrite(trigOut, LOW);

        durationOut = pulseIn(echoOut, HIGH);
        distanceOut = durationOut / 29 / 2;

        if (distanceOut < 7)
        {
            outGate.write(90);
            Serial.println("OutGate Opened.");
        }
        else
        {
            outGate.write(0);
            Serial.println("OutGate not opened.");
        }
    }
    delay(1000);
}