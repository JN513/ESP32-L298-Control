#include <Arduino.h>

#ifndef MOTORS_H
#define MOTORS_H

class Motors{
    public:
        Motors(int M1a, int M1b, int M2a, int M2b, int _speed = 2000, int _freq=1000, int _resolution=12, int _ch0=0, int _ch1=1, int _ch2=2, int _ch3=3);
        int set_freq(int _freq);
        int set_resolution(int _resolution);
        int set_speed(int _speed);
        void set_channels(int _ch0, int _ch1, int _ch2, int _ch3);
        void stop();
        void neutral();
        void neutral_ma();
        void neutral_mb();
        void stop_ma();
        void stop_mb();
        void front_ma(int _speed = 0);
        void behind_ma(int _speed = 0);
        void front_mb(int _speed = 0);
        void behind_mb(int _speed = 0);
        void front(int _speed = 0);
        void behind(int _speed = 0);
        int maximize_speed();
        int minimize_speed();
        int get_speed();
        int get_direction_ma();
        int get_direction_mb();

    private:
        int m1a, m1b, m2a, m2b;
        int speed;
        int direction_a = 1;
        int direction_b = 1;
        int freq;
        int resolution;
        int ch0, ch1, ch2, ch3;
};

#endif