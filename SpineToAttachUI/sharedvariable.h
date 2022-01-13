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

extern QList<float> bufferOneMin[4],  bufferThreeMin[4], bufferTenMin[4], bufferThirtyMin[4],
                    bufferSixtyMin[4],bufferThreeHour[4],bufferTenHour[4],bufferThirtyHour[4];

extern int channelNum;

#endif // SHAREDVARIABLE_H
