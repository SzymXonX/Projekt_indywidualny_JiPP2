#include "Data.h"

Data::Data()
{
    time = std::time({}) + 3600;
}

time_t Data::getData()
{
    return time;
}

void Data::setData(time_t time)
{
    this->time = time;
}
