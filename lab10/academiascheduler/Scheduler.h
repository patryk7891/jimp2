//
// Created by mikolaj on 20.05.18.
//

#ifndef JIMP_EXERCISES_SCHEDULER_H
#define JIMP_EXERCISES_SCHEDULER_H
#include <vector>
#include <algorithm>
namespace academia {


    class SchedulingItem
    {
        int course_id;
        int teacher_id;
        int room_id;
        int time_slot;
        int year;
    public:
        int CourseId() const;
        int TeacherId() const;
        int RoomId() const;
        int TimeSlot() const;
        int Year() const;

        SchedulingItem()= default;
        SchedulingItem(int course_id, int teacher_id, int room_id, int time_slot, int year);
        ~SchedulingItem()= default;
    };

    class Schedule
    {
        std::vector<SchedulingItem> sched;
        size_t size_;
    public:
        Schedule();
        size_t Size() const;
        std::vector<int> AvailableTimeSlots(int n_time_slots);
        void InsertScheduleItem(const SchedulingItem &item);
        Schedule OfTeacher(int teacher_id);
        Schedule OfRoom(int room_id);
        Schedule OfYear(int year);

        SchedulingItem & operator[](int el) {return sched[el];};
        const SchedulingItem & operator[](int el) const {return sched[el];};

    };

    class Scheduler
    {

    };

    class GreedyScheduler
    {

    };

    class NoViableSolutionFound{

    };
}

#endif //JIMP_EXERCISES_SCHEDULER_H
