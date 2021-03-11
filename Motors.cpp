#include "Motors.h"

Motors :: Motors( int M1a, int M1b, int M2a, int M2b, int _speed, int _freq, int _resolution, int _ch0, int _ch1, int _ch2, int _ch3){
    this->freq = _freq;
    this->resolution = _resolution;
    this->m1a = M1a;
    this->m1b = M1b;
    this->m2a = M2a;
    this->m2b = M2b;
    this->speed = _speed;

    pinMode( M1a, OUTPUT );
    pinMode( M1b, OUTPUT );
    pinMode( M2a, OUTPUT );
    pinMode( M2b, OUTPUT );

    ledcSetup( _ch0, this->freq, this->resolution );
    ledcSetup( _ch1, this->freq, this->resolution );
    ledcSetup( _ch2, this->freq, this->resolution );
    ledcSetup( _ch3, this->freq, this->resolution );

    this->ch0 = _ch0;
    this->ch1 = _ch1;
    this->ch2 = _ch2;
    this->ch3 = _ch3;

    ledcAttachPin( this->m1a, _ch0 );
    ledcAttachPin( this->m1b, _ch1 );
    ledcAttachPin( this->m2a, _ch2 );
    ledcAttachPin( this->m2b, _ch3 );
}

int Motors :: set_freq(int _freq){
    this->freq = _freq;
    return this->freq;
}

int Motors :: set_resolution(int _resolution){
    this->resolution = _resolution;
    return this->resolution;
}

int Motors :: set_speed(int _speed){
    if(_speed < 0){
        this->speed = _speed*-1;
    } else{
        this->speed = _speed;
    }
    return this->speed;
}

void Motors ::  set_channels(int _ch0, int _ch1, int _ch2, int _ch3){
    ledcSetup( _ch0, this->freq, this->resolution );
    ledcSetup( _ch1, this->freq, this->resolution );
    ledcSetup( _ch2, this->freq, this->resolution );
    ledcSetup( _ch3, this->freq, this->resolution );

    this->ch0 = _ch0;
    this->ch1 = _ch1;
    this->ch2 = _ch2;
    this->ch3 = _ch3;

    ledcAttachPin( this->m1a, _ch0 );
    ledcAttachPin( this->m1b, _ch1 );
    ledcAttachPin( this->m2a, _ch2 );
    ledcAttachPin( this->m2b, _ch3 );
}

void Motors :: stop(){
    ledcWrite(1, 4094);
    ledcWrite(2, 4094);
    ledcWrite(2, 4094);
    ledcWrite(3, 4094);
}

void Motors :: neutral(){
    ledcWrite(1, 0);
    ledcWrite(2, 0);
    ledcWrite(2, 0);
    ledcWrite(3, 0);
}

void Motors :: neutral_ma(){
    ledcWrite(0, 0);
    ledcWrite(1, 0);
}

void Motors :: neutral_mb(){
    ledcWrite(2, 0);
    ledcWrite(3, 0);
}

void Motors :: stop_ma(){
    ledcWrite(0, 4094);
    ledcWrite(1, 4094);
}

void Motors :: stop_mb(){
    ledcWrite(2, 4094);
    ledcWrite(3, 4094);
}

void Motors :: front_ma(int _speed){
    this->direction_a = 1;
    if(_speed != 0){
        ledcWrite(0, 0);
        ledcWrite(1 , _speed);
    }else{
        ledcWrite(0, 0);
        ledcWrite(1 , this->speed);       
    }
}

void Motors :: behind_ma(int _speed){
    this->direction_a = 0;
    if(_speed != 0){
        ledcWrite(1, 0);
        ledcWrite(0 , _speed);
    }else{
        ledcWrite(1, 0);
        ledcWrite(0 , this->speed);
    }
}

void Motors :: front_mb(int _speed){
    this->direction_b = 1;
    if(_speed != 0){
        ledcWrite(2, 0);
        ledcWrite(3 , _speed);
    }else{
        ledcWrite(2, 0);
        ledcWrite(3 , this->speed);       
    }
}

void Motors :: behind_mb(int _speed){
    this->direction_b = 0;
    if(_speed != 0){
        ledcWrite(3, 0);
        ledcWrite(2 , _speed);
    }else{
        ledcWrite(3, 0);
        ledcWrite(2 , this->speed);
    }
}

void Motors :: front(int _speed){
    this->direction_a = 1;
    this->direction_b = 1;
        if(_speed != 0){
        ledcWrite(0, 0);
        ledcWrite(1 , _speed);
        ledcWrite(2, 0);
        ledcWrite(3 , _speed);
    }else{
        ledcWrite(0, 0);
        ledcWrite(1 , this->speed); 
        ledcWrite(2, 0);
        ledcWrite(3 , this->speed); 
    }
}

void Motors :: behind(int _speed){
    this->direction_a = 0;
    this->direction_b = 0;
    if(_speed != 0){
        ledcWrite(1, 0);
        ledcWrite(0 , _speed);
        ledcWrite(3, 0);
        ledcWrite(2 , _speed);
    }else{
        ledcWrite(1, 0);
        ledcWrite(0 , speed);
        ledcWrite(3, 0);
        ledcWrite(2 , speed);
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

int Motors :: get_direction_ma(){
    return this->direction_a;
}
int Motors :: get_direction_mb(){
    return this->direction_b;
}