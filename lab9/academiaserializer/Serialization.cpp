//
// Created by mikolaj on 08.05.18.
//

#include "Serialization.h"

namespace academia {
    Room::Room(int num, std::string name, Type type) {
        num_ = num;
        name_ = name;
        type_ = type;
    }

    Serializer::Serializer(std::ostream *out) {
        this->out = out;
    };

    std::string MakeTypeString(Room::Type type) {
        if (type == Room::Type::CLASSROOM) {
            return "CLASSROOM";
        }
        if (type == Room::Type::LECTURE_HALL) {
            return "LECTURE_HALL";
        }
        if (type == Room::Type::COMPUTER_LAB) {
            return "COMPUTER_LAB";
        }
    }

    void Room::Serialize(Serializer *s) const {
        s->Header("room");
        s->IntegerField("id", num_);
        s->StringField("name", name_);
        s->StringField("type", MakeTypeString(type_));
        s->Footer("room");
    }

    Building::Building(int number, std::string nam, std::vector<Room> rom) {
        number_ = number;
        name_ = nam;
        room_ = std::move(rom);
    }

    bool Building::operator==(const Building otherBuilding) const {
        if ( name_ == otherBuilding.name_ )
            return true;
        return false;
    }

    int Building::Id() const {
        return number_;
    }

    void Building::Serialize(Serializer *s) const {
        s->Header("building");
        s->IntegerField("id", number_);
        s->StringField("name", name_);
        std::vector<std::reference_wrapper<const Serializable>> rom;
        for (const Room &room : room_) {
            rom.emplace_back(room);
        }

        s->ArrayField("rooms", rom);
        s->Footer("building");

    }

    void BuildingRepository::Add(Building newBuilding) {
        if (std::find(Vector.begin(), Vector.end(), newBuilding) == Vector.end()) {
            Vector.push_back(newBuilding);
        }
    }

    void BuildingRepository::StoreAll(Serializer *serializer) const {
        serializer->Header("building_repository");
        serializer->ArrayField("buildings", getBuildings());
        serializer->Footer("building_repository");
    }

    std::vector<std::reference_wrapper<const Serializable>> BuildingRepository::getBuildings() const {
        std::vector<std::reference_wrapper<const Serializable> > roomsVector;
        for (const Serializable &building: Vector) {
            roomsVector.emplace_back(building);
        }
        return roomsVector;
    }

    std::experimental::optional<Building> BuildingRepository::operator[](int buildingId) const {
        for (const Building &building: Vector) {
            if (building.number_ == buildingId) {
                return building;
            }
        }
    }
}