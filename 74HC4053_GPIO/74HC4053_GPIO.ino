int pins[3] = {2,3,4};
int select = 0;

void setup() {
    pinMode(pins[0], OUTPUT);
    pinMode(pins[1], OUTPUT);
    pinMode(pins[2], OUTPUT);
}

void loop() {
    for (select = 0; select < 8; select++) {
        digitalWrite(pins[0], bitRead(select, 0));
        digitalWrite(pins[1], bitRead(select, 1));
        digitalWrite(pins[2], bitRead(select, 2));
    }
}