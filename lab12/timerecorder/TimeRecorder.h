//
// Created by mikolaj on 01.06.18.
//

#ifndef JIMP_EXERCISES_TIMERECORDER_H
#define JIMP_EXERCISES_TIMERECORDER_H

#include <chrono>
#include <utility>

namespace profiling{
    template <class T>
    auto TimeRecorder(T function){
        auto t1 = std::chrono::high_resolution_clock::now();
        auto ret = (function)();
        auto t2 = std::chrono::high_resolution_clock::now();
        double dur = std::chrono::duration<double, std::milli>(t2-t1).count();

        return std::make_pair(ret, dur);
    };
}


#endif //JIMP_EXERCISES_TIMERECORDER_H
