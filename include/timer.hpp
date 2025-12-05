#ifndef TIMER_H
#define TIMER_H

class Timer{
    float length;
    float time;
    bool timeout;
    public:
        Timer(float length) : length(length), time(0), timeout(false) {}

        void step(float deltaTime){
            this->time += deltaTime;
            if(this->time >= this->length){
                this->time -= this->length;
            }
        }
        void reset() {
            this->time = 0;
        }

        bool isTimeout() const { return this->timeout;}
        float getTime() const {return this->time;}
        float getLength() const {return this->length;}
        
};

#endif