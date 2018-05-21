//
// Created by mikolaj on 20.05.18.
//

#include "Scheduler.h"

namespace academia
{
    SchedulingItem::SchedulingItem(int course_id, int teacher_id, int room_id, int time_slot, int year){
        this->course_id = course_id;
        this->teacher_id = teacher_id;
        this->room_id = room_id;
        this->time_slot = time_slot;
        this->year = year;
    }

    void Schedule::InsertScheduleItem(const SchedulingItem &item)
    {
        sched.emplace_back(item);
        size_=sched.size();
    }
    Schedule Schedule::OfTeacher(int teacher_id){
        Schedule a;
        std::copy_if(this->sched.begin(),this->sched.end(), std::back_inserter(a.sched), [teacher_id](SchedulingItem it){if(teacher_id==it.TeacherId()){return true;}else{return false;}});
        a.size_ = a.sched.size();
        return a;
    }
    Schedule Schedule::OfRoom(int room_id){
        Schedule a;
        std::copy_if(this->sched.begin(),this->sched.end(), std::back_inserter(a.sched), [room_id](SchedulingItem it){if(room_id==it.RoomId()){return true;}else{return false;}});
        a.size_ = a.sched.size();
        return a;
    }
    Schedule Schedule::OfYear(int year){
        Schedule a;
        std::copy_if(this->sched.begin(),this->sched.end(), std::back_inserter(a.sched), [year](SchedulingItem it){if(year==it.Year()){return true;}else{return false;}});
        a.size_ = a.sched.size();
        return a;
    }
    size_t Schedule::Size()const {
        return size_;
    }
    int SchedulingItem::CourseId()const
    {
        return course_id;
    }
    int SchedulingItem::TeacherId()const {
        return teacher_id;
    }
    int SchedulingItem::RoomId()const {
        return room_id;
    }
    int SchedulingItem::TimeSlot()const{
        return time_slot;
    }
    int SchedulingItem::Year()const {
        return year;
    }

    std::vector<int> Schedule::AvailableTimeSlots(int n_time_slots)
    {
        std::vector<int> free;
        for(int i=1; i<=n_time_slots; i++)
        {
            free.emplace_back(i);
        }
        for(auto a: sched)
        {
            if (a.TimeSlot()<n_time_slots)
            {
                free.erase(std::remove(free.begin(), free.end(), a.TimeSlot()), free.end());
            }
        }
        return free;
    }
    Schedule::Schedule() {
        size_=0;
    }
}