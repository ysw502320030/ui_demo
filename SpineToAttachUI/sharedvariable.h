#ifndef SHAREDVARIABLE_H
#define SHAREDVARIABLE_H

#include <QQueue>

struct Data_to_UI
{
    double freq_new_raw[10];
    float thA[10];
    float rate[10];
    float delta_time;
};

extern Data_to_UI ui_data;

extern QQueue<Data_to_UI > q ;



#endif // SHAREDVARIABLE_H
