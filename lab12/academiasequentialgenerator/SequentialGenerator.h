//
// Created by mikolaj on 02.06.18.
//

#ifndef JIMP_EXERCISES_SEQUENTIALGENERATOR_H
#define JIMP_EXERCISES_SEQUENTIALGENERATOR_H




template <typename typ_ID, typename typ_prosty>
class SequentialIdGenerator{
private:
    bool head;
    typ_prosty val;

public:
    SequentialIdGenerator(){
        head = true;
        val = typ_prosty();
    }
    SequentialIdGenerator(typ_prosty v){
        head = true;
        val = v;
    }

    typ_ID NextValue(){
        if(!head){
            ++val;
        }
        head = false;

        return typ_ID(val);
    }
};

#endif //JIMP_EXERCISES_SEQUENTIALGENERATOR_H
