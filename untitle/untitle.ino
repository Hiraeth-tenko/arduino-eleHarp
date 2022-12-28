char cloudTone[][2] = {
    {1, 4}, {1, 5}, {2, 1}, {0, 4}, {0, 1}, {0, 4}, {0, 6}, {1, 5}, {2, 1}, {1, 2}, {1, 5}, {2, 2}, {2, 2}, {1, 2}, {1, 7}, {1, 7}, {2, 1}, {2, 1}, {2, 1}, {1, 6}, {1, 7}, {2, 1}, {2, 1}, {1, 7}, {1, 7}, {1, 0}, {1, 0}, {1, 0}, {1, 0}, {0, 5}, {0, 2}, {0, 5}, {0, 6}, {0, 7}, {1, 0}, {0, 6}, {0, 3}, {0, 6}, {0, 7}, {1, 1}, {1, 3}, {1, 0}, {0, 5}, {0, 2}, {0, 5}, {1, 1}, {1, 2}, {1, 2}, {1, 4}, {1, 5}, {2, 1}, {2, 1}, {2, 1}, {1, 5}, {2, 1}, {1, 2}, {1, 5}, {2, 2}, {2, 2}, {2, 3}, {2, 3}, {1, 4}, {1, 5}, {2, 3}, {2, 2}, {2, 1}, {2, 1}, {2, 1}, {1, 0}, {1, 0}, {0, 6}, {1, 2}, {1, 5}, {0, 6}, {1, 2}, {1, 7}, {0, 4}, {0, 1}, {0, 4}, {0, 5}, {0, 6}, {1, 0}, {0, 5}, {0, 5}, {1, 1}, {1, 5}, {1, 5}, {0, 1}, {0, 5}, {1, 1}, {1, 4}, {1, 5}, {1, 1}, {1, 4}, {1, 5}, {1, 1}, {0, 5}, {0, 1}, {0, 5}, {1, 0}, {2, 1}, {2, 1}, {2, 1}, {0, 5}, {1, 1}, {1, 2}, {1, 2}, {0, 7}, {0, 7}, {1, 1}, {0, 5}, {0, 6}, {0, 6}, {0, 4}, {0, 5}, {0, 6}, {1, 1}, {1, 1}, {0, 7}, {0, 7}, {0, 6}, {0, 3}, {0, 6}, {0, 7}, {1, 1}, {0, 3}, {1, 0}, {1, 0}, {0, 2}, {0, 6}, {0, 7}, {0, 5}, {0, 5}, {0, 6}, {0, 1}, {0, 5}, {0, 6}, {0, 1}, {1, 0}, {1, 0}, {1, 0}, {0, 5}, {0, 5}, {0, 3}, {1, 0}, {0, 7}, {1, 1}, {1, 1}, {1, 1}, {0, 5}, {1, 1}, {1, 2}, {1, 2}, {1, 3}, {1, 3}, {1, 3}, {1, 2}, {1, 1}, {1, 1}, {0, 5}, {1, 1}, {1, 4}, {1, 5}, {1, 3}, {1, 3}, {1, 3}, {1, 3}, {1, 0}, {0, 4}, {0, 1}, {0, 5}, {0, 3}, {1, 0}, {0, 5}, {0, 1}, {0, 4}, {0, 5}, {0, 5}, {0, 4}, {0, 5}, {0, 4}, {0, 1}, {0, 5}, {0, 1}, {0, 4}, {1, 0}, {1, 0}, {0, 5}, {0, 5}, {0, 5}, {0, 5}};
char cloudDur[] = {
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
int cloudPer = 882;

const int anPin[6] = {0, 1, 2, 3, 4, 5};
const int tonePin = 11;
const int LiPin[6] = {2, 3, 4, 5, 6, 7};
const int btnPin[2] = {5, 6};
int playMode = 1; // 0 播放乐曲; 1 自行演奏
int playType = -1;
int preType = -1;
int playLH = 1;

int stopFlag = 0;
int reFlag = 0;
int musicLen = -1, musicPer = -1;
char (*musicTone)[2] = NULL, (*musicDur) = NULL;
int sounds[6] = {};
int CTONE[3][8] = {
    {0, 131, 147, 165, 175, 196, 221, 248},
    {0, 262, 294, 330, 350, 393, 441, 495},
    {0, 525, 589, 661, 700, 786, 882, 990}};
float duration[5] = {1.0, 1.0 / 2, 1.0 / 4, 1.0 / 8, 1.0 / 16};

void readCodes();
void ownInit();
void musicInit();

void setup()
{
    // put your setup code here, to run once:
    pinMode(tonePin, OUTPUT);
    pinMode(btnPin[0], INPUT);
    pinMode(btnPin[1], INPUT);
    for (int i = 0; i < 6; i++)
    {
        pinMode(LiPin[i], OUTPUT);
        digitalWrite(LiPin[i], HIGH);
    }
    ownInit();
    musicInit();
    Serial.begin(9600);
}

void loop()
{
    readCodes();
    if (playMode == 1)
    {
        for (int i = 0; i < 6; ++i)
        {
            int val = analogRead(anPin[i]);
            /*Serial.print("analogRead");
            Serial.print(i);
            Serial.print(": ");
            Serial.println(val);*/
            if (val < 600)
            {
                preType = playType;
                playType = i + 1;
                /*Serial.print("playsound: ");
                Serial.println(playType);*/
                break;
            }
            else
            {
                playType = -1;
            }
        }
        delay(1000);
        Serial.println("##########");
        if (preType != playType)
            noTone(tonePin);
        if (playType > 0 && playType < 7)
        {
            if (digitalRead(btnPin[0]) == HIGH)
            {
                playLH = 0;
                /*Serial.print("read");
                Serial.print(btnPin[0]);
                Serial.println("HIGH");*/
            }
            else if (digitalRead(btnPin[1]) == HIGH)
            {
                playLH = 2;
                /*Serial.print("read");
                Serial.print(btnPin[1]);
                Serial.println("HIGH");*/
            }
            else
            {
                playLH = 1;
                // Serial.println("read not HIGH");
            }
            tone(tonePin, CTONE[playLH][playType], musicPer);
            Serial.println("##########");
        }
    }
    else if (playMode == 0)
    {
    restart:
        Serial.println("Start");
        delay(1000);
        for (int i = 0; i < musicLen && playMode == 0;)
        {
            if (!stopFlag)
            {
                int tune = CTONE[musicTone[i][0]][musicTone[i][1]];
                float dur = musicDur[i];
                if (tune != 0)
                {
                    tone(tonePin, tune);
                    delay((int)(musicPer * dur));
                    noTone(tonePin);
                }
                else
                {
                    delay(musicPer);
                }
                ++i;
            }
            readCodes();
            if (reFlag)
            {
                reFlag = 0;
                goto restart;
            }
        }
        delay(5000);
    }
}

void ownInit()
{
    playType = preType = -1;
}

void musicInit()
{
    musicLen = sizeof(cloudDur) / sizeof(cloudDur[0]);
    musicTone = cloudTone;
    musicDur = cloudDur;
    musicPer = cloudPer;
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
                    ownInit();
                }
                break;
                case '0':
                {
                    playMode = 0;
                    Serial.println("set mode: play by program");
                    Serial.println("Select music <<Night in the Brume>>");
                    musicInit();
                }
                default:
                    break;
                }
            }
            break;
            case 's':
            case 'S':
            {
                if (playMode == 0)
                {
                    stopFlag = 1;
                }
            }
            break;
            case 'p':
            case 'P':
            {
                if (playMode == 0)
                {
                    stopFlag = 0;
                }
            }
            break;
            case 't':
            case 'T':
            {
                int val = -1;
                val = Serial.read();
                Serial.println((char)val);
                switch (val)
                {
                case '1':
                {
                    if (musicTone != cloudTone && musicDur != cloudDur)
                    {
                        reFlag = 1;
                        musicTone = cloudTone;
                        musicDur = cloudDur;
                        musicPer = cloudPer;
                        musicLen = sizeof(cloudDur) / sizeof(cloudDur[0]);
                        Serial.println("Select music <<Night in the Brume>>");
                    }
                }
                break;
                case '0':
                {
                    if (musicTone != NULL && musicDur != NULL)
                    {
                        reFlag = 1;
                        musicTone = NULL;
                        musicDur = NULL;
                        musicPer = 0;
                        musicLen = NULL;
                        Serial.println("Select music <<NULL>>");
                    }
                }
                default:
                    break;
                }
            }
            default:
                break;
            }
        }
    }
}
