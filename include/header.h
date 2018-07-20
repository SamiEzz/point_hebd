#ifndef _head__
#define _head__

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stddef.h>

#include "jsmn.h"

#define stBeacons	   "Beacons"
    #define stBeaconid      "Beaconid"
    #define stBeaconx		"Beaconx"
    #define stBeacony	    "Beacony"
    #define stBeaconz	    "Beaconz"
#define stConstants	        "Constants"
    #define stvdef "VDEF"
    #define stadef "ADEF"
    #define stv1 "V1"
    #define stv2 "V2"
#define stConstraints       "Constraints"
    #define stCid     "Cid"
    #define stCvalue  "Cvalue"
    #define stCname   "Cname"
    #define stCtype   "Ctype"
    #define stCx      "Cx"
    #define stCy      "Cy"
    #define stCz      "Cz"
#define stWaypoints	   "Waypoints"
    #define stwpid          "wpid"
    #define stwptype        "wptype"
    #define stwpx           "wpx"
    #define stwpy           "wpy"
    #define stwpz           "wpz"
#define stLegs		   "Legs"
    #define stlegId         "legId"
    #define stlegLength     "legLength"
    #define stlegStartx     "legStartx"
    #define stlegStarty     "legStarty"
    #define stlegStartz     "legStartz"
    #define stlegEndx       "legEndx"
    #define stlegEndy       "legEndy"
    #define stlegEndz       "legEndz"


typedef struct {
    int r;
	jsmn_parser p;
	jsmntok_t * t;
} initParser;

struct Beacons {
    
    int     id;
    float    x;
    float    y;
    float    z; 
};

struct Constants
{
    float vdef;
    float adef;
    float v1;
    float v2;
} ;

struct Constraints
{
    int id;
    float value;
    char *name;
    char *type;
    float    x;
    float    y;
    float    z; 
} ;

struct Waypoints
{
    int id;
    char *type;
    float    x;
    float    y;
    float    z; 
} ;


struct Legs
{
    int id;
    double length;
    double    startx;
    double    starty;
    double    startz;    
    double    endx;
    double    endy;
    double    endz;
} ;


int jsoneq(const char *json, jsmntok_t *tok, const char *s);
struct Beacons beaconsExt(char *_JSON_STRING,initParser _IP,int _i,int objRank);
struct Waypoints waypointsExt(char *_JSON_STRING,initParser _IP,int _i,int objRank);
struct Legs legsExt(char *_JSON_STRING,initParser _IP,int _i,int objRank);
struct Constraints ConstrExt(char *_JSON_STRING,initParser _IP,int _i,int objRank);
struct Constants CstExt(char *_JSON_STRING,initParser _IP,int _i);



initParser getJsonToken(int expectNvalues,char * JSON_STRING);
int objectOccurance(char * objectName,char * JSON_STRING, initParser IP);
int objectRank(char * objectName,char * JSON_STRING, initParser IP);
int nextObjectTab(char * objectName,char * JSON_STRING, initParser IP);





#endif