//
// Created by mikolaj on 20.05.18.
//

#ifndef JIMP_EXERCISES_SCHEDULER_H
#define JIMP_EXERCISES_SCHEDULER_H
#include <vector>
#include <algorithm>
#include <numeric>
#include <string>
#include <memory>
#include <set>
#include <vector>
#include <utility>
#include <map>
#include <ostream>
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
        Schedule(std::vector<SchedulingItem> scheduling_items);
        size_t Size() const;
        std::vector<int> AvailableTimeSlots(int n_time_slots);
        void InsertScheduleItem(const SchedulingItem &item);
        Schedule OfTeacher(int teacher_id)const;
        Schedule OfRoom(int room_id)const;
        Schedule OfYear(int year)const;

        SchedulingItem & operator[](int el) {return sched[el];};
        const SchedulingItem & operator[](int el) const {return sched[el];};

    };

    class Scheduler
    {
    public:
        virtual Schedule PrepareNewSchedule(const std::vector<int> &rooms, const std::map<int, std::vector<int>> &teacher_courses_assignment, const std::map<int, std::set<int>> &courses_of_year, int n_time_slots) = 0;
    };

    class GreedyScheduler: public Scheduler
    {
    public:
        Schedule PrepareNewSchedule(const std::vector<int> &rooms, const std::map<int, std::vector<int>> &teacher_courses_assignment, const std::map<int, std::set<int>> &courses_of_year, int n_time_slots) override ;
    };

    class NoViableSolutionFound{
    };
}

#endif //JIMP_EXERCISES_SCHEDULER_H
