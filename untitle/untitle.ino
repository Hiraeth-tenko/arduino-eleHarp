int cloudTONE[][2] = {
    {1, 4}, {1, 5}, {2, 1}, {0, 4}, {0, 1}, {0, 4}, {0, 6}, {1, 5}, {2, 1}, {1, 2}, {1, 5}, {2, 2}, {2, 2}, {1, 2}, {1, 7}, {1, 7}, {2, 1}, {2, 1}, {2, 1}, {1, 6}, {1, 7}, {2, 1}, {2, 1}, {1, 7}, {1, 7}, {1, 0}, {1, 0}, {1, 0}, {1, 0}, {0, 5}, {0, 2}, {0, 5}, {0, 6}, {0, 7}, {1, 0}, {0, 6}, {0, 3}, {0, 6}, {0, 7}, {1, 1}, {1, 3}, {1, 0}, {0, 5}, {0, 2}, {0, 5}, {1, 1}, {1, 2}, {1, 2}, {1, 4}, {1, 5}, {2, 1}, {2, 1}, {2, 1}, {1, 5}, {2, 1}, {1, 2}, {1, 5}, {2, 2}, {2, 2}, {2, 3}, {2, 3}, {1, 4}, {1, 5}, {2, 3}, {2, 2}, {2, 1}, {2, 1}, {2, 1}, {1, 0}, {1, 0}, {0, 6}, {1, 2}, {1, 5}, {0, 6}, {1, 2}, {1, 7}, {0, 4}, {0, 1}, {0, 4}, {0, 5}, {0, 6}, {1, 0}, {0, 5}, {0, 5}, {1, 1}, {1, 5}, {1, 5}, {0, 1}, {0, 5}, {1, 1}, {1, 4}, {1, 5}, {1, 1}, {1, 4}, {1, 5}, {1, 1}, {0, 5}, {0, 1}, {0, 5}, {1, 0}, {2, 1}, {2, 1}, {2, 1}, {0, 5}, {1, 1}, {1, 2}, {1, 2}, {0, 7}, {0, 7}, {1, 1}, {0, 5}, {0, 6}, {0, 6}, {0, 4}, {0, 5}, {0, 6}, {1, 1}, {1, 1}, {0, 7}, {0, 7}, {0, 6}, {0, 3}, {0, 6}, {0, 7}, {1, 1}, {0, 3}, {1, 0}, {1, 0}, {0, 2}, {0, 6}, {0, 7}, {0, 5}, {0, 5}, {0, 6}, {0, 1}, {0, 5}, {0, 6}, {0, 1}, {1, 0}, {1, 0}, {1, 0}, {0, 5}, {0, 5}, {0, 3}, {1, 0}, {0, 7}, {1, 1}, {1, 1}, {1, 1}, {0, 5}, {1, 1}, {1, 2}, {1, 2}, {1, 3}, {1, 3}, {1, 3}, {1, 2}, {1, 1}, {1, 1}, {0, 5}, {1, 1}, {1, 4}, {1, 5}, {1, 3}, {1, 3}, {1, 3}, {1, 3}, {1, 0}, {0, 4}, {0, 1}, {0, 5}, {0, 3}, {1, 0}, {0, 5}, {0, 1}, {0, 4}, {0, 5}, {0, 5}, {0, 4}, {0, 5}, {0, 4}, {0, 1}, {0, 5}, {0, 1}, {0, 4}, {1, 0}, {1, 0}, {0, 5}, {0, 5}, {0, 5}, {0, 5}};
int cloudDUR[] = {
    2, 2, 1, 2, 2, 1, 0, 1, 1,
    2, 2, 1, 0, 2, 1, 0,
    0, 0, 0, 1, 1,
    0, 0, 0, 0,
    0, 0, 0, 0,
    1, 1, 1, 1, 0, 0,
    1, 1, 1, 1, 1, 1, 0,
    1, 1, 1, 1, 0, 0,
    2, 2, 1, 0, 0, 1, 1,
    2, 2, 1, 0, 0, 0,
    2, 2, 2, 2, 1, 0, 0,
    0, 0, 2, 2, 1, 2, 2, 1,
    1, 1, 1, 1, 0, 0,
    1, 1, 0, 0, 0,
    1, 1, 1, 1, 1, 1, 1, 1,
    1, 1, 0, 0, 0,
    0, 0, 0, 1, 1,
    0, 0, 0, 0,
    0, 1, 1, 1, 1, 1, 1,
    0, 0, 0, 0,
    1, 1, 1, 1, 1, 1, 0,
    1, 1, 1, 1, 0, 0,
    1, 1, 1, 1, 1, 1, 0,
    1, 1, 1, 1, 0, 0,
    0, 0, 0, 1, 1,
    0, 0, 0, 0,
    2, 2, 1, 0, 1, 1, 1, 1,
    0, 0, 0, 0,
    0, 0, 1, 1, 1, 1,
    1, 1, 1, 1, 1, 1, 1, 1,
    1, 1, 1, 1, 0, 0,
    0, 0, 0, 0};

const int anPin[6] = {0, 1, 2, 3, 4, 5};
const int tonePin = 11;
const int LiPin[6] = {2, 3, 4, 5, 6, 7};
void setup()
{
    // put your setup code here, to run once:
    pinMode(tonePin, OUTPUT);
    for (int i = 0; i < 6; i++)
    {
        pinMode(LiPin[i], OUTPUT);
        digitalWrite(LiPin[i], HIGH);
    }

    Serial.begin(9600);
}

int playMode = 1; // 0 播放乐曲; 1 自行演奏
int playType = -1;
int preType = -1;
int sounds[6] = {};
int CTONE[3][8] = {
    {0, 131, 147, 165, 175, 196, 221, 248},
    {0, 262, 294, 330, 350, 393, 441, 495},
    {0, 525, 589, 661, 700, 786, 882, 990}};
float duration[5] = {1.0, 1.0 / 2, 1.0 / 4, 1.0 / 8, 1.0 / 16};

void readCodes();

void loop()
{
    readCodes();
    if (playMode == 2)
    {
        for (int i = 0; i < 6; ++i)
        {
            int val = analogRead(anPin[i]);
            Serial.print("analogRead");
            Serial.print(i);
            Serial.print(": ");
            Serial.println(val);
            delay(1);
        }
        Serial.println("##########");
        delay(1000);
    }
    else if (playMode == 1)
    {
        for (int i = 0; i < 6; ++i)
        {
            int val = analogRead(anPin[i]);
            /*Serial.print("analogRead");
            Serial.print(i);
            Serial.print(": ");
            Serial.println(val);
            */
            if (val > 600)
            {
                preType = playType;
                playType = i + 1;
                Serial.print("playsound: ");
                Serial.println(playType);
                break;
            }
        }
        if (preType != playType)
            noTone(tonePin);
        if (playType > 0 && playType < 7)
        {
            tone(tonePin, CTONE[1][playType], 882);
            Serial.println("##########");
        }
        if (playType != -1)
        {
            playType = -1;
        }
    }
    else if (playMode == 0)
    {
        int len = sizeof(cloudTONE) / sizeof(int) / 2;
        int len2 = sizeof(cloudDUR) / sizeof(int);
        /*Serial.print("len: ");
        Serial.println(len);
        Serial.print("len2: ");
        Serial.println(len2);
        delay(10000);*/
        Serial.println("Start");
        delay(1000);
        for (int i = 0; i < len && playMode == 0; i++)
        {
            int tune = CTONE[cloudTONE[i][0]][cloudTONE[i][1]];
            float dur = cloudDUR[i];
            /*Serial.print(i);
            Serial.print(": tune:");
            Serial.print(tune);
            Serial.print(", dur:");
            Serial.println(dur);*/
            if (tune != 0)
            {
                tone(tonePin, tune);
                delay((int)(882 * dur));
                noTone(tonePin);
            }
            else
            {
                delay(882);
            }
            readCodes();
        }
        delay(5000);
    }
}

/*
    S -> Stop
    P -> Play
    Tx -> at mode 0 and tone Song x
    Cx -> Change mode x
*/
void readCodes()
{
    int ava = 0;
    ava = Serial.available();
    if (ava > 0)
    {
        Serial.println("t");
        int op = -1;
        op = Serial.read();
        Serial.print((char)op);
        if (op != -1 && op != '\n')
        {
            delay(20);
            switch (op)
            {
            case 'c':
            case 'C':
            {
                int val = -1;
                val = Serial.read();
                Serial.println((char)val);
                switch (val)
                {
                case '1':
                {
                    playMode = 1;
                    Serial.println("set mode: play by own");
                }
                break;
                case '0':
                {
                    playMode = 0;
                    Serial.println("set mode: play by program");
                }
                default:
                    break;
                }
            }
            break;

            default:
                break;
            }
        }
    }
}
