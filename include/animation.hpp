#ifndef ANIMATION_H
#define ANIMATION_H

    #include "timer.hpp"

    class Animation{
        Timer timer;
        int frameCount;

        public:
            Animation() : timer(0), frameCount(0) {}
            Animation(int framecount, float length) : frameCount(frameCount), timer(length)
            {
            }

            float getLength() const {return this->timer.getLength();}
            int currentFrame() const {
                return static_cast<int>(this->timer.getTime() / this->timer.getLength() * frameCount);
            }

            void step(float deltaTime){
                this->timer.step(deltaTime);
            }


    };

#endif