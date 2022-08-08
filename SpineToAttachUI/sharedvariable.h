#ifndef SHAREDVARIABLE_H
#define SHAREDVARIABLE_H

#include <QQueue>

#define ARRAY_SIZE_TEN 10
#define ARRAY_SIZE_TWENTY 20

#define _DEBUG_ 0

#if _DEBUG_
#define OutPutInfo(...) qDebug(__VA_ARGS__)
#else
#define OutPutInfo(...)
#endif

#if _DEBUG_
#define OutPutInfoNoLineFeed(...) printf(__VA_ARGS__)
#else
#define OutPutInfoNoLineFeed(...)
#endif

#define DASH_VAL 45
#define NULL_VAL -1

#define EMPTY_STR ""

struct __attribute__ ((aligned (4))) Data_to_UI
{
    double freq_new_raw[10];
    float thA[10];
    float rate[10];
    float delta_time;
    float thickness_layer[5];

    volatile int layerTHAcheived;

    char proc_info[ARRAY_SIZE_TWENTY];
    char chan_info[5][ARRAY_SIZE_TEN];
    char ctrl_type_info[ARRAY_SIZE_TEN];

    char procState[ARRAY_SIZE_TWENTY];
    char chanState[ARRAY_SIZE_TWENTY];
    char ctrlType[ARRAY_SIZE_TWENTY];

    float powerInfo[5];

    int mainShutterStatus;

};

extern struct Data_to_UI ui_data;

extern  QQueue<Data_to_UI > q ;

struct __attribute__ ((aligned (4))) UIButtonInfo
{
    int stateMS;
    int procStart;
    int proStop;
};

extern struct UIButtonInfo ButtonStatus;

extern QList<float> bufferOneMin[4],  bufferThreeMin[4], bufferTenMin[4], bufferThirtyMin[4],
                    bufferSixtyMin[4],bufferThreeHour[4],bufferTenHour[4],bufferThirtyHour[4];

extern int channelNum;

extern QList<QPointF> points[4];

extern bool uiChangeMSFlag;

struct __attribute__ ((aligned (4))) Films
{
    int dummy[4];
    int ctype[51];
    char name[51][17];
    float dens[51];
    float Zf[51];
    int sour[51];
    int sens[51];
    float tool[51];
    float r_pid_p[51];
    float r_pid_i[51];
    float r_pid_d[51];
    float t_pid_p[51];
    float t_pid_i[51];
    float t_pid_d[51];
    float pwr_max[51];
    float rate_max[51];
    float temp_max[51];
    //  rate/pwr  ctrl
    float ini[51];
    float ramp1[51];
    float pwr1[51];
    float soak1[51];
    float ramp2[51];
    float pwr2[51];
    float soak2[51];
    float capture_ramp[51];
    float capture_rate_perc[51];
    float reduction_perc[51];
    float shut_delay_sec[51];
    float ready_deviation[51];
    float alarm_deviation[51];
    float error_deviation[51];
    float ramp3[51];
    float pwr3[51];
    float soak3[51];
    float idle[51];

};

extern struct Films film;

// proc  ~ 10k
struct __attribute__ ((aligned (4))) Processes
{
    int dummy[3];
    int lay_use_advanced_lay_par[9][33];
    char name[9][20];
    int last_L[9];
    char lay_name[9][33][17];
    float lay_th[9][33];
    int lay_chan_film[9][33][5];

    float lay_chan_sv1[9][33][5];
    float lay_chan_soak[9][33][5];
    float lay_chan_ramp[9][33][5];
    float lay_chan_sv2[9][33][5];
    int   lay_chan_meas_th[9][33][5];

    float lay_add_sec[9][33];
    int   lay_add_signal[9][33];
    int lay_wait_operator[9][33];
    int lay_add_automation[9][33];
    int lay_next_L[9][33];
    int lay_jumps_L[9][33];
    int lay_pass_N[9][33];
    int lay_is_last_L[9][33];

    int proNum;         //to demonstate the process No. and layer No. that is under deposition,
    int layerNum;

} ;

extern struct Processes proc;

extern int proNum,layerNum,chan1_film_sel,chan2_film_sel,chan3_film_sel,chan4_film_sel;

extern char ctrlMode[6][10];

void OutPutListInfo(const char *msg, QList<float> list);

#endif // SHAREDVARIABLE_H
