Game Class
```cpp
    class Game {
        
        vector <Room> rooms;
        
        void createRoom(string room_name);
        Room* getRoomByRoomName(string room_name);
    }
```

Room Class
```cpp
    class Room {

        string room_name;

        vector <Object> objects;

        void setRoomName(string room_name);
        string getRoomName();

        void createObject(string object_name);
        Object* getObjectByObjectName(string object_name);
    }
```