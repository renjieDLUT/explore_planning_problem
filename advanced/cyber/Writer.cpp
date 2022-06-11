#include"Writer.h"
#include"schedule.h"
void Writer::Publish(Message &msg) { Schedule::Trigger(topic_, &msg); }