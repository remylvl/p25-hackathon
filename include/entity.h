#ifndef ENTITY_H
#define ENTITY_H

typedef enum{
    ROOM,
    CORRIDOR,
} room_type;

typedef struct
{
    float x,y;
    int w, h;
    room_type type;
} Room;


typedef struct
{
    float x, y;
    float vx, vy;
    int w, h;
} Entity;

#endif
