#include "Motors.h"

Motors :: Motors( int M1a, int M1b, int M2a, int M2b, int _speed ){
    this->m1a = M1a;
    this->m1b = M1b;
    this->m2a = M2a;
    this->m2b = M2b;
    this->speed = _speed;

    pinMode( M1a, OUTPUT );
    pinMode( M1b, OUTPUT );
    pinMode( M2a, OUTPUT );
    pinMode( M2b, OUTPUT );
}

void Motors :: set_speed(int _speed){
    if(_speed < 0){
        this->speed = _speed*-1;
    } else{
        this->speed = _speed;
    }
}

void Motors :: stop(){
    digitalWrite( this->m1a, HIGH );
    digitalWrite( this->m1b, HIGH );
    digitalWrite( this->m2a, HIGH );
    digitalWrite( this->m2b, HIGH );
}

void Motors :: neutral(){
    digitalWrite( this->m1a, LOW );
    digitalWrite( this->m1b, LOW );
    digitalWrite( this->m2a, LOW );
    digitalWrite( this->m2b, LOW );
}

void Motors :: neutral_a(){
    digitalWrite( this->m1a, LOW );
    digitalWrite( this->m1b, LOW );
}

void Motors :: neutral_b(){
    digitalWrite( this->m2a, LOW );
    digitalWrite( this->m2b, LOW );
}

void Motors :: stop_a(){
    digitalWrite( this->m1a, HIGH );
    digitalWrite( this->m1b, HIGH );
}

void Motors :: stop_b(){
    digitalWrite( this->m2a, HIGH );
    digitalWrite( this->m2b, HIGH );
}

void Motors :: front_ma(int _speed){
    this->direction_a = 1;
    if(_speed == 0){
        digitalWrite( this->m1a, LOW );
        analogWrite( this->m1b, _speed );
    }else{
        digitalWrite( this->m1a, LOW );
        analogWrite( this->m1b, speed );
    }
}

void Motors :: behind_ma(int _speed){
    this->direction_a = 0;
    if(_speed == 0){
        analogWrite( this->m1a, _speed );
        digitalWrite( this->m1b, LOW );
    }else{
        analogWrite( this->m1a, speed );
        digitalWrite( this->m1b, LOW );
    }
}

void Motors :: front_mb(int _speed){
    this->direction_b = 1;
    if(_speed == 0){
        digitalWrite( this->m2a, LOW );
        analogWrite( this->m2b, _speed );
    }else{
        digitalWrite( this->m2a, LOW );
        analogWrite( this->m2b, speed );        
    }
}

void Motors :: behind_mb(int _speed){
    this->direction_b = 0;
    if(_speed == 0){
        analogWrite( this->m2a, _speed );
        digitalWrite( this->m2b, LOW );
    }else{
        analogWrite( this->m2a, speed );
        digitalWrite( this->m2b, LOW );
    }
}

void Motors :: front(int _speed){
    this->direction_a = 1;
    this->direction_b = 1;
        if(_speed == 0){
        digitalWrite( this->m1a, LOW );
        analogWrite( this->m1b, _speed );
        digitalWrite( this->m2a, LOW );
        analogWrite( this->m2b, _speed );
    }else{
        digitalWrite( this->m1a, LOW );
        analogWrite( this->m1b, speed );
        digitalWrite( this->m2a, LOW );
        analogWrite( this->m2b, speed );
    }
}

void Motors :: behind(int _speed){
    this->direction_a = 0;
    this->direction_b = 0;
    if(_speed == 0){
        analogWrite( this->m1a, _speed );
        digitalWrite( this->m1b, LOW );
        analogWrite( this->m2a, _speed );
        digitalWrite( this->m2b, LOW );
    }else{
        analogWrite( this->m1a, speed );
        digitalWrite( this->m1b, LOW );
        analogWrite( this->m2a, speed);
        digitalWrite( this->m2b, LOW );
    }
}

int Motors :: maximize_speed(){
    this->speed = 4095;
    return speed;
}

int Motors :: minimize_speed(){
    this->speed = 10;
    return this->speed;
}

int Motors :: get_speed(){
    return this->speed;
}

int Motors :: get_direction_a(){
    return this->direction_a;
}
int Motors :: get_direction_b(){
    return this->direction_b;
}