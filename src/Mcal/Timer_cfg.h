/*example 2s and 350ms and 50us -accuracy might be low in us-*/
/*--on and off time selection--*/
#define onTime_sec 1
#define onTime_ms 0
#define onTime_us 0

#define offTime_sec 1
#define offTime_ms 0
#define offTime_us 0
/*end selection*/
/*Clock*/
#define Clock 12000000
/*end selection*/
#if (onTime_ms > 999 || offTime_ms > 999) 
	#error "total ms should be less than a second"
#endif
#if (offTime_us > 999 || offTime_us > 999) 
	#error "total us should be less than a milisecond"
#endif
#if (offTime_sec > 255 || offTime_sec > 255) 
	#error "seconds limit is 255"
#endif
