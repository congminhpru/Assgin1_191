/* Created by Nguyen Duc Dung on 2019-09-03.
 * =========================================================================================
 * Name        : dbLib.h
 * Author      : Duc Dung Nguyen
 * Email       : nddung@hcmut.edu.vn
 * Copyright   : Faculty of Computer Science and Engineering - HCMUT
 * Description : The data structure library for Assignment 1
 * Course      : Data Structure and Algorithms - Fall 2019
 * =========================================================================================
 */

#ifndef DSA191_A1_DBLIB_H
#define DSA191_A1_DBLIB_H

#include <iostream>
#include <fstream>
#include <iomanip>
#include <string>
#include <cstring>
#include <sstream>
#include <math.h>

#include "dsaLib.h"

/* TODO: Please design your data structure carefully so that you can work with the given dataset
 *       in this assignment. The below structures are just some suggestions.
 */
struct TCity {
    // The structure to store city information
	int id;
	string name;
	string coords;
	int start_year;
	string url_name;
	string country;
	string country_state;
};

struct TLine {
    // The structure to store line information
	int id;
	int city_id;
	string name;
	string url_name;
	string color;
	int system_id;
	int transport_mode_id;
};
struct Tstation_lines {
	int id, station_id, line_id, city_id;
	string created_at, updated_at;
};

struct Tstations {
	// The structure to store track information
	int id, buildstart, opening, closure, city_id;
	string name, geometry;

};

struct Tsystems {
	// The structure to store track information
	int id, city_id;
	string name;
};

struct TTrack_lines {
	// The structure to store track information
	int id, section_id, line_id, city_id;
	string created_at, updated_at;
};

struct TTracks {
    // The structure to store track information
	int	id, buildstart, opening, closure, length, city_id;
	string geometry;
};

class TDataset {
    // This class can be a container that help you manage your tables
public:
	L1List<TCity> *City=new L1List<TCity>;
	L1List<TLine> *Line=new L1List<TLine>;
	L1List<Tstation_lines> *station_lines=new L1List<Tstation_lines>;
	L1List<Tstations> *stations=new L1List<Tstations>;
	L1List<Tsystems> *systems=new L1List<Tsystems>;
	L1List<TTracks> *Tracks=new L1List<TTracks>;
	L1List<TTrack_lines> *Track_lines=new L1List<TTrack_lines>;
	

};

// Please add more or modify as needed

void LoadData(void* & m);
void ReleaseData(void* & n);

#endif //DSA191_A1_DBLIB_H
