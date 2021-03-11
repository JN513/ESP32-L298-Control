#include "Motors.h"

Motors :: Motors(int M1a, int M1b, int M2a, int M2b, int _speed){
    this->m1a = M1a;
    this->m1b = M1b;
    this->m2a = M2a;
    this->m2b = M2b;
    this->speed = _speed;

    pinMode(M1a, OUTPUT);
    pinMode(M1b, OUTPUT);
    pinMode(M2a, OUTPUT);
    pinMode(M2b, OUTPUT);
}

void Motors :: set_speed(int _speed){
    if(_speed < 0){
        this->speed = _speed*-1;
    } else{
        this->speed = _speed;
    }
}

void Motors :: stop(){
    digitalWrite(m1a, HIGH);
    digitalWrite(m1b, HIGH);
    digitalWrite(m2a, HIGH);
    digitalWrite(m2b, HIGH);
}

void Motors :: neutral(){
    digitalWrite(m1a, LOW);
    digitalWrite(m1b, LOW);
    digitalWrite(m2a, LOW);
    digitalWrite(m2b, LOW);
}

void Motors :: neutral_a(){
    digitalWrite(m1a, LOW);
    digitalWrite(m1b, LOW);
}

void Motors :: neutral_b(){
    digitalWrite(m2a, LOW);
    digitalWrite(m2b, LOW);
}

void Motors :: stop_a(){
    digitalWrite(m1a, HIGH);
    digitalWrite(m1b, HIGH);
}

void Motors :: stop_b(){
    digitalWrite(m2a, HIGH);
    digitalWrite(m2b, HIGH);
}

void Motors :: front_ma(int _speed){
    direction_a = 1;
    if(_speed == 0){
        digitalWrite(m1a, LOW);
        analogWrite(m1b, _speed);
    }else{
        digitalWrite(m1a, LOW);
        analogWrite(m1b, speed);
    }
}

void Motors :: behind_ma(int _speed){
    direction_a = 0;
    if(_speed == 0){
        analogWrite(m1a, _speed);
        digitalWrite(m1b, LOW);
    }else{
        analogWrite(m1a, speed);
        digitalWrite(m1b, LOW);
    }
}

void Motors :: front_mb(int _speed){
    direction_b = 1;
    if(_speed == 0){
        digitalWrite(m2a, LOW);
        analogWrite(m2b, _speed);
    }else{
        digitalWrite(m2a, LOW);
        analogWrite(m2b, speed);        
    }
}

void Motors :: behind_mb(int _speed){
    direction_b = 0;
    if(_speed == 0){
        analogWrite(m2a, _speed);
        digitalWrite(m2b, LOW);
    }else{
        analogWrite(m2a, speed);
        digitalWrite(m2b, LOW);
    }
}

void Motors :: front(int _speed){
    direction_a = 1;
    direction_b = 1;
        if(_speed == 0){
        digitalWrite(m1a, LOW);
        analogWrite(m1b, _speed);
        digitalWrite(m2a, LOW);
        analogWrite(m2b, _speed);
    }else{
        digitalWrite(m1a, LOW);
        analogWrite(m1b, speed);
        digitalWrite(m2a, LOW);
        analogWrite(m2b, speed);
    }
}

void Motors :: behind(int _speed){
    direction_a = 0;
    direction_b = 0;
    if(_speed == 0){
        analogWrite(m1a, _speed);
        digitalWrite(m1b, LOW);
        analogWrite(m2a, _speed);
        digitalWrite(m2b, LOW);
    }else{
        analogWrite(m1a, speed);
        digitalWrite(m1b, LOW);
        analogWrite(m2a, speed);
        digitalWrite(m2b, LOW);
    }
}

int Motors :: maximize_speed(){
    speed = 4095;
    return speed;
}

int Motors :: minimize_speed(){
    speed = 10;
    return speed;
}

int get_speed(){
    return speed;
}

int Motors :: get_direction_a(){
    return direction_a;
}
int Motors :: get_direction_b(){
    return direction_b;
}