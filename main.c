/******************************************************************************/
/* Files to Include                                                           */
/******************************************************************************/

/* Device header file */
#if defined(__dsPIC33E__)
	#include <p33Exxxx.h>
#elif defined(__dsPIC33F__)
	#include <p33Fxxxx.h>
#endif

#include <dsp.h>
#include <libq.h>

#define PI 3.141529

/******************************************************************************/
/* Global Variable Declaration                                                */
/******************************************************************************/

/* i.e. uint16_t <variable_name>; */

/******************************************************************************/
/* Main Program                                                               */
/******************************************************************************/

void main(void)
{

    float time = 0;
    unsigned long ms = 0;
    float fparg = 1.0;
    float fpres = 1.0;

    float famp = 250.0;
    float fpfreq = 1.0;

    _Q15 fixamp = 250;
    _Q15 fixfreq = 1000;

    //_Q15 fixarg = 0;
    long fixarg;
    _Q15 fixres = 0;

    float fdelta = 32767.0 / ((float)fixfreq * 0.001);
    long fixdelta = (unsigned int)fdelta;

    while(1)
    {
        fixarg += fixdelta;
        fixres = _Q15sinPI(fixarg);
        //fixres = (fixres * fixamp) >> 10;

        fparg = 2 * PI * fpfreq * time;
        //fpres = famp * sin(fparg);
        fpres = sin(fparg);

        ms++;
        time = (float)ms/1000.0;
    }
}
