#include "../include/header.h"




int jsoneq(const char *json, jsmntok_t *tok, const char *s) {
	if (tok->type == JSMN_STRING && (int) strlen(s) == tok->end - tok->start &&
			strncmp(json + tok->start, s, tok->end - tok->start) == 0) {
		return 0;
	}
	return -1;
}

struct Constants CstExt(char *_JSON_STRING,initParser _IP,int _i){
		struct Constants C;
		char * tempchar;
		jsmntok_t *_t = _IP.t;
		//char * jsonobjectname=stBeaconid";
		int constantsrank = objectRank(stConstants,_JSON_STRING, _IP)-1;
		int vdefrank=objectRank(stvdef,_JSON_STRING, _IP)-constantsrank;
		int adefrank=objectRank(stadef,_JSON_STRING, _IP)-constantsrank;
		int v1rank=objectRank(stv1,_JSON_STRING, _IP)-constantsrank;
		int v2rank=objectRank(stv2,_JSON_STRING, _IP)-constantsrank;
		//---
		tempchar = malloc(sizeof(double));
		strncpy(tempchar,  _JSON_STRING + _t[_i+ vdefrank].start, sizeof(double));
		C.vdef=strtof(tempchar,NULL);
		free(tempchar);
		tempchar = malloc(sizeof(double));
		strncpy(tempchar,  _JSON_STRING + _t[_i+ adefrank].start, sizeof(double));
		C.adef=strtof(tempchar,NULL);
		free(tempchar);
		tempchar = malloc(sizeof(double));
		strncpy(tempchar,  _JSON_STRING + _t[_i+ v1rank].start, sizeof(double));
		C.v1=strtof(tempchar,NULL);
		free(tempchar);
		tempchar = malloc(sizeof(double));
		strncpy(tempchar,  _JSON_STRING + _t[_i+ v2rank].start, sizeof(double));
		C.v2=strtof(tempchar,NULL);
		free(tempchar);
		return C;
  }

struct Constraints ConstrExt(char *_JSON_STRING,initParser _IP,int _i,int objRank){
		struct Constraints ct;
		char * tempchar;
		char * namechar;
		char * typechar;
		
		
		jsmntok_t *_t = _IP.t;
		//char * jsonobjectname=stBeaconid";

		int ctrank = objectRank(stConstraints,_JSON_STRING, _IP)-1;
		int tab=nextObjectTab(stCid,_JSON_STRING, _IP);

		int idrank=objectRank(stCid,_JSON_STRING, _IP)-ctrank+objRank*tab;
		int valuerank=objectRank(stCvalue,_JSON_STRING, _IP)-ctrank+objRank*tab;
		int namerank=objectRank(stCname,_JSON_STRING, _IP)-ctrank+objRank*tab;
		int typerank=objectRank(stCtype,_JSON_STRING, _IP)-ctrank+objRank*tab;
		int xrank=objectRank(stCx,_JSON_STRING, _IP)-ctrank+objRank*tab;
		int yrank=objectRank(stCy,_JSON_STRING, _IP)-ctrank+objRank*tab;
		int zrank=objectRank(stCz,_JSON_STRING, _IP)-ctrank+objRank*tab;
		
		//---
		tempchar = malloc(sizeof(int));
		strncpy(tempchar,  _JSON_STRING + _t[_i+ idrank].start, sizeof(int));
		ct.id=atoi(tempchar);
		free(tempchar);
		//---
		typechar = malloc(14*sizeof(char));
		strncpy(typechar,  _JSON_STRING + _t[_i+ typerank].start, 14*sizeof(char));
		ct.type=typechar;
		//free(typechar);
		//---
		namechar = malloc(5*sizeof(char));
		strncpy(namechar,  _JSON_STRING + _t[_i+ namerank].start, 4*sizeof(char));
		ct.name=namechar;
		//free(namechar);

		tempchar = malloc(sizeof(double));
		strncpy(tempchar,  _JSON_STRING + _t[_i+ valuerank].start, sizeof(double));
		ct.value=strtof(tempchar,NULL);
		free(tempchar);

		tempchar = malloc(sizeof(double));
		strncpy(tempchar,  _JSON_STRING + _t[_i+ xrank].start, sizeof(double));
		ct.x=strtof(tempchar,NULL);
		free(tempchar);

		tempchar = malloc(sizeof(double));
		strncpy(tempchar,  _JSON_STRING + _t[_i+ yrank].start, sizeof(double));
		ct.y=strtof(tempchar,NULL);
		free(tempchar);

		tempchar = malloc(sizeof(double));
		strncpy(tempchar,  _JSON_STRING + _t[_i+ zrank].start, sizeof(double));
		ct.z=strtof(tempchar,NULL);
		free(tempchar);

		
		
		return ct;
  }

struct Legs legsExt(char *_JSON_STRING,initParser _IP,int _i,int objRank){
		struct Legs lg;
		char * tempchar;
		
		jsmntok_t *_t = _IP.t;
		//char * jsonobjectname=stBeaconid";

		int lgrank = objectRank(stLegs,_JSON_STRING, _IP)-1;
		int tab=nextObjectTab(stlegId,_JSON_STRING, _IP);

		int idrank=objectRank(stlegId,_JSON_STRING, _IP)-lgrank+objRank*tab;
		int lengthrank=objectRank(stlegLength,_JSON_STRING, _IP)-lgrank+objRank*tab;
		int sxrank=objectRank(stlegStartx,_JSON_STRING, _IP)-lgrank+objRank*tab;
		int syrank=objectRank(stlegStarty,_JSON_STRING, _IP)-lgrank+objRank*tab;
		int szrank=objectRank(stlegStartz,_JSON_STRING, _IP)-lgrank+objRank*tab;
		int exrank=objectRank(stlegEndx,_JSON_STRING, _IP)-lgrank+objRank*tab;
		int eyrank=objectRank(stlegEndy,_JSON_STRING, _IP)-lgrank+objRank*tab;
		int ezrank=objectRank(stlegEndz,_JSON_STRING, _IP)-lgrank+objRank*tab;
				
		//---
		tempchar = malloc(sizeof(int));
		strncpy(tempchar,  _JSON_STRING + _t[_i+ idrank].start, sizeof(int));
		lg.id=atoi(tempchar);
		free(tempchar);

		tempchar = malloc(sizeof(double));
		strncpy(tempchar,  _JSON_STRING + _t[_i+ lengthrank].start, sizeof(double));
		lg.length=strtof(tempchar,NULL);
		free(tempchar);
		
		tempchar = malloc(sizeof(double));
		strncpy(tempchar,  _JSON_STRING + _t[_i+ sxrank].start, sizeof(double));
		lg.startx=strtof(tempchar,NULL);
		free(tempchar);

		tempchar = malloc(sizeof(double));
		strncpy(tempchar,  _JSON_STRING + _t[_i+ syrank].start, sizeof(double));
		lg.starty=strtof(tempchar,NULL);
		free(tempchar);

		tempchar = malloc(sizeof(double));
		strncpy(tempchar,  _JSON_STRING + _t[_i+ szrank].start, sizeof(double));
		lg.startz=strtof(tempchar,NULL);
		free(tempchar);
		
		tempchar = malloc(sizeof(double));
		strncpy(tempchar,  _JSON_STRING + _t[_i+ exrank].start, sizeof(double));
		lg.endx=strtof(tempchar,NULL);
		free(tempchar);
		tempchar = malloc(sizeof(double));
		strncpy(tempchar,  _JSON_STRING + _t[_i+ eyrank].start, sizeof(double));
		lg.endy=strtof(tempchar,NULL);
		free(tempchar);
		tempchar = malloc(sizeof(double));
		strncpy(tempchar,  _JSON_STRING + _t[_i+ ezrank].start, sizeof(double));
		lg.endz=strtof(tempchar,NULL);
		free(tempchar);
		
		
		return lg;
  }

struct Waypoints waypointsExt(char *_JSON_STRING,initParser _IP,int _i,int objRank){
		struct Waypoints wp;
		char * tempchar;
		char * typechar;
		
		jsmntok_t *_t = _IP.t;
		int wprank = objectRank(stWaypoints,_JSON_STRING, _IP)-1;
		int tab=nextObjectTab(stwpid,_JSON_STRING, _IP);
		int idrank=objectRank(stwpid,_JSON_STRING, _IP)-wprank+objRank*tab;
		int xrank=objectRank(stwpx,_JSON_STRING, _IP)-wprank+objRank*tab;
		int yrank=objectRank(stwpy,_JSON_STRING, _IP)-wprank+objRank*tab;
		int zrank=objectRank(stwpz,_JSON_STRING, _IP)-wprank+objRank*tab;
		int typerank=objectRank(stwptype,_JSON_STRING, _IP)-wprank+objRank*tab;
		
		//---
		typechar = malloc(13*sizeof(char));
		strncpy(typechar,  _JSON_STRING + _t[_i+ typerank].start, 13*sizeof(char));
		wp.type=typechar;
		//free(typechar);

		tempchar = malloc(sizeof(int));
		strncpy(tempchar,  _JSON_STRING + _t[_i+ idrank].start, sizeof(int));
		wp.id=atoi(tempchar);
		free(tempchar);
		
		tempchar = malloc(sizeof(float));
		strncpy(tempchar,  _JSON_STRING + _t[_i+ xrank].start, sizeof(float));
		wp.x=strtof(tempchar,NULL);
		free(tempchar);
		
		tempchar = malloc(sizeof(float));
		strncpy(tempchar,  _JSON_STRING + _t[_i+ yrank].start, sizeof(float));
		wp.y=strtof(tempchar,NULL);
		free(tempchar);
		
		tempchar = malloc(sizeof(float));
		strncpy(tempchar,  _JSON_STRING + _t[_i+ zrank].start, sizeof(float));
		wp.z=strtof(tempchar,NULL);
		free(tempchar);
		
		return wp;
  }

struct Beacons beaconsExt(char *_JSON_STRING,initParser _IP,int _i,int objRank){
		struct Beacons B;
		char * tempchar;
		jsmntok_t *_t = _IP.t;
		//char * jsonobjectname=stBeaconid";
		int Beaconrank = objectRank(stBeacons,_JSON_STRING, _IP)-1;
		int tab=nextObjectTab(stBeaconid,_JSON_STRING, _IP);
		int idrank=objectRank(stBeaconid,_JSON_STRING, _IP)-Beaconrank+objRank*tab;
		int xrank=objectRank(stBeaconx,_JSON_STRING, _IP)-Beaconrank+objRank*tab;
		int yrank=objectRank(stBeacony,_JSON_STRING, _IP)-Beaconrank+objRank*tab;
		int zrank=objectRank(stBeaconz,_JSON_STRING, _IP)-Beaconrank+objRank*tab;
		//---
		tempchar = malloc(sizeof(char));
		strncpy(tempchar,  _JSON_STRING + _t[_i+ idrank].start, sizeof(int));
		B.id=atoi(&tempchar[0]);
		free(tempchar);

		tempchar = malloc(sizeof(float));
		strncpy(tempchar,  _JSON_STRING + _t[_i+ xrank].start, sizeof(float));
		B.x=strtof(tempchar,NULL);
		free(tempchar);
		
		tempchar = malloc(sizeof(float));
		strncpy(tempchar,  _JSON_STRING + _t[_i+ yrank].start, sizeof(float));
		B.y=strtof(tempchar,NULL);
		free(tempchar);
		
		tempchar = malloc(sizeof(float));
		strncpy(tempchar,  _JSON_STRING + _t[_i+ zrank].start, sizeof(float));
		B.z=strtof(tempchar,NULL);
		free(tempchar);
		
		return B;
  }


initParser getJsonToken(int expectNvalues,char * JSON_STRING){
	initParser IP;
	int r;
	jsmn_parser p;
	jsmntok_t  t[expectNvalues]; /* We expect no more than 128 tokens */

	jsmn_init(&p);
	r = jsmn_parse(&p, JSON_STRING, strlen(JSON_STRING), t, sizeof(t)/sizeof(t[0]));
    IP.r=r;
	IP.p=p;
	IP.t=t;
	if (r < 0) {
		printf("Failed to parse JSON: %d\n", r);
		//return 1;
	}

	/* Assume the top-level element is an object */
	if (r < 1 || t[0].type != JSMN_OBJECT) {
		printf("Object expected\n");
		//return 1;
	}
    
    return IP;
}

int objectRank(char * objectName,char * JSON_STRING, initParser IP){
	int rank;
	jsmntok_t * t = IP.t;
	int r = IP.r;
	for (int i = 1; i < r; i++) {
		if (jsoneq(JSON_STRING, &t[i], objectName) == 0) {
			return i;
		}
	}
	return -1;
}

int objectOccurance(char * objectName,char * JSON_STRING, initParser IP){
	int occurance=0;
	jsmntok_t * t = IP.t;
	int r = IP.r;
	for (int i = 1; i < r; i++) {
		if (jsoneq(JSON_STRING, &t[i], objectName) == 0) {
			occurance++;
		}
	}
	return occurance;
}


int nextObjectTab(char * objectName,char * JSON_STRING, initParser IP){
	int tab=0;
	int lasti=-1;
	jsmntok_t * t = IP.t;
	int r = IP.r;
	for (int i = 1; i < r; i++) {
		if (jsoneq(JSON_STRING, &t[i], objectName) == 0) {
			if(lasti==-1){
				lasti=i;
			}
			else{
				tab=i-lasti;
				return tab;
			}
		}
	}
}
