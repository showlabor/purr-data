#include "fftease.h"void bloscbank( float *S, float *O, int D, float iD, float *lf, float *la, float *index, float *tab, 	int len, float synt, int lo, int hi ){  int    amp,freq,chan, i;  float    a,ainc,f,finc,address;    for ( chan = lo; chan < hi; chan++ ) {    freq = ( amp = ( chan << 1 ) ) + 1;    if ( S[amp] > synt ){       finc = ( S[freq] - ( f = lf[chan] ) )* iD;      ainc = ( S[amp] - ( a = la[chan] ) )* iD;      address = index[chan];      for ( i = 0; i < D ; i++ ) {	O[i] += a*tab[ (int) address ];	    	address += f;	while ( address >= len )	  address -= len;	while ( address < 0 )	  address += len;	a += ainc;	f += finc;      }      lf[chan] = S[freq];      la[chan] = S[amp];      index[chan] = address;    }      }}