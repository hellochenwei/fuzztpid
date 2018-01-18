#ifndef FUZZYPID_H
#define FUZZYPID_H

#include <stdio.h>

//e ec
#define ENB(x) ( x >= e[0][0] && x <= e[0][2] )
#define ENM(x) ( x >= e[1][0] && x <= e[1][2] )
#define ENS(x) ( x >= e[2][0] && x <= e[2][2] )
#define EZO(x) ( x >= e[3][0] && x <= e[3][2] )
#define EPS(x) ( x >= e[4][0] && x <= e[4][2] )
#define EPM(x) ( x >= e[5][0] && x <= e[5][2] )
#define EPB(x) ( x >= e[6][0] && x <= e[6][2] )
#define ENONE(x) ( x < e[0][0] || x > e[6][2] )

#define ECNB(x) ( x >= ec[0][0] && x <= ec[0][2] )
#define ECNM(x) ( x >= ec[1][0] && x <= ec[1][2] )
#define ECNS(x) ( x >= ec[2][0] && x <= ec[2][2] )
#define ECZO(x) ( x >= ec[3][0] && x <= ec[3][2] )
#define ECPS(x) ( x >= ec[4][0] && x <= ec[4][2] )
#define ECPM(x) ( x >= ec[5][0] && x <= ec[5][2] )
#define ECPB(x) ( x >= ec[6][0] && x <= ec[6][2] )
#define ECNONE(x) ( x < ec[0][0] || x > ec[6][2] )

//P I D
#define NB 1
#define NM 2
#define NS 3
#define ZO 4
#define PS 5
#define PM 6
#define PB 7
 
#define P 0
#define I 1
#define D 2

float e[7][3] = {	{-3.0, -3.0, -2.0}, //NB
					{-3.0, -2.0, -1.0},//NM
					{-2.0, -1.0, 0},//NS
					{-1.0, 0, 1.0},//ZO
					{0, 1.0, 2.0},//PS
					{1.0, 2.0, 3.0},//PM
					{2.0, 3.0, 3.0}};//PB

float ec[7][3] = {	{-3.0, -3.0, -2.0}, //NB
					{-3.0, -2.0, -1.0},//NM
					{-2.0, -1.0, 0},//NS
					{-1.0, 0, 1.0},//ZO
					{0, 1.0, 2.0},//PS
					{1.0, 2.0, 3.0},//PM
					{2.0, 3.0, 3.0}};//PB

float kp[7][3] = {	{-3.0, -3.0, -2.0}, //NB
					{-3.0, -2.0, -1.0},//NM
					{-2.0, -1.0, 0},//NS
					{-1.0, 0, 1.0},//ZO
					{0, 1.0, 2.0},//PS
					{1.0, 2.0, 3.0},//PM
					{2.0, 3.0, 3.0}};//PB
					
float ki[7][3] = {	{-0.3, -0.3, -0.2}, //NB
					{-0.3, -0.2, -0.1},//NM
					{-0.2, -0.1, 0},//NS
					{-0.1, 0, 0.1},//ZO
					{0, 0.1, 0.2},//PS
					{0.1, 0.2, 0.3},//PM
					{0.2, 0.3, 0.3}};//PB
					
float kd[7][3] = {	{-0.3, -0.3, -0.2}, //NB
					{-0.3, -0.2, -0.1},//NM
					{-0.2, -0.1, 0},//NS
					{-0.1, 0, 0.1},//ZO
					{0, 0.1, 0.2},//PS
					{0.1, 0.2, 0.3},//PM
					{0.2, 0.3, 0.3}};//PB
					
typedef struct PIDPARAMETER{
	int pwmout;
	float offset1;
	float offset2;
	float offset3;
	float cur1;
	float cur2;
	int maxout;
	int minout;
	float ratioFactorE;
	float ratioFactorEC;
	float ratioFactorP;
	float ratioFactorI;
	float ratioFactorD;
}PARAM;
					
float membershipFunc(float left, float center, float right, float x);
void eMembership(float x, float* res, int n);
void ecMembership(float x, float* res, int n);

int isMatch(char i, char j, float xe, float xec);
void PIDFuzzyRule( float xe, float xec, float res[][3], int which, int n );
float getPartOfRes(float arr[], int n, int which);
float defuzzy(float res[][3], int n, int which );



#endif