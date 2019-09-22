/* Created by Nguyen Duc Dung on 2019-09-03.
 * =========================================================================================
 * Name        : dbLib.cpp
 * Author      : Duc Dung Nguyen
 * Email       : nddung@hcmut.edu.vn
 * Copyright   : Faculty of Computer Science and Engineering - HCMUT
 * Description : The data structure library for Assignment 1
 * Course      : Data Structure and Algorithms - Fall 2019
 * =========================================================================================
 */

#include "dbLib.h"

/* TODO: You can implement methods, functions that support your data structures here.
 * */

void LoadData(void* & m) {
	TDataset *Dataset = new TDataset;
	m = Dataset;
	
	// Doc Cities.csv
	ifstream Citycsv;
	Citycsv.open("cities.csv");
	string readcity;
	string mystring;
	getline(Citycsv, readcity);

	while (getline(Citycsv,readcity))
	{
		TCity *City = new TCity;
		stringstream ss(readcity);
		getline(ss, mystring, ',');
		City->id = stoi(mystring);
		if (ss.peek() == '"') { getline(ss, City->name, '"'); getline(ss, City->name, '"'); getline(ss, mystring, ','); }
		
		else  getline(ss, City->name, ',');
		
		getline(ss, City->coords, ',');
		getline(ss, mystring, ',');
		if (mystring!="") City->start_year = stoi(mystring);
		getline(ss, City->url_name, ',');
		getline(ss, City->country, ',');
		getline(ss, City->country_state);
		Dataset->City->push_back(*City);
		delete City;

	};
	Citycsv.close();
	// Read data from stations.csv
	Citycsv.open("stations.csv");
	getline(Citycsv, readcity);
	
	
	while (getline(Citycsv, readcity))
	{
		Tstations *stations=new Tstations;
		stringstream ss(readcity);
		getline(ss, mystring, ',');
		stations->id = stoi(mystring);
	
		if (ss.peek() == '"') { getline(ss, stations->name, '"'); getline(ss, stations->name, '"'); getline(ss, mystring, ','); }
		else  getline(ss, stations->name, ',');
		getline(ss, stations->geometry, ',');
		getline(ss, mystring, ',');
		if (mystring != "") stations->buildstart = stoi(mystring);
		getline(ss, mystring, ',');
		if (mystring != "") stations->opening = stoi(mystring);
		getline(ss, mystring, ',');
		if (mystring != "") stations->closure = stoi(mystring);
		getline(ss, mystring);
		if (mystring != "") stations->city_id = stoi(mystring);
		
		Dataset->stations->push_back(*stations);
		delete stations;
	}
	Citycsv.close();
	//----------------------------------------

	Citycsv.open("lines.csv");
	getline(Citycsv, readcity);


	while (getline(Citycsv, readcity))
	{
		TLine *lines = new TLine;	
		stringstream ss(readcity);
		getline(ss, mystring, ',');
		lines->id = stoi(mystring);
		getline(ss, mystring, ',');
		lines->city_id = stoi(mystring);
		if (ss.peek() == '"') { getline(ss, lines->name, '"'); getline(ss, lines->name, '"'); getline(ss, mystring, ','); }	else  getline(ss, lines->name, ',');

		getline(ss, lines->url_name, ',');
		getline(ss, lines->color, ',');
		getline(ss, mystring, ',');
		if (mystring != "") lines->system_id = stoi(mystring);
		getline(ss, mystring);
		if (mystring != "") lines->transport_mode_id = stoi(mystring);
		Dataset->Line->push_back(*lines);
		delete lines;
	}
	Citycsv.close();
	//-------------------------
	
	Citycsv.open("tracks.csv");
	getline(Citycsv, readcity);


	while (getline(Citycsv, readcity))
	{
		TTracks *tracks = new TTracks;
		stringstream ss(readcity); 
		getline(ss, mystring, ',');
		tracks->id = stoi(mystring);
		if (ss.peek() == '"') { getline(ss, tracks->geometry, '"'); getline(ss, tracks->geometry, '"');getline(ss, mystring, ','); }
		else  getline(ss, tracks->geometry, ',');
		getline(ss, mystring, ',');
		if (mystring != "") tracks->buildstart = stoi(mystring);
		getline(ss, mystring, ',');

		if (mystring != "") tracks->opening = stoi(mystring);
		getline(ss, mystring, ',');
		if (mystring != "") tracks->closure= stoi(mystring);
		getline(ss, mystring, ',');
		if (mystring != "") tracks->length = stoi(mystring);
		getline(ss, mystring);
		if (mystring != "") tracks->city_id = stoi(mystring);
		Dataset->Tracks->push_back(*tracks);
		delete tracks;
	}
	Citycsv.close();
	//-------------------------
	Citycsv.open("station_lines.csv");
	getline(Citycsv, readcity);


	while (getline(Citycsv, readcity))
	{
		Tstation_lines  *station_lines = new Tstation_lines;
		stringstream ss(readcity);
		getline(ss, mystring, ',');
		if (mystring != "") station_lines->id = stoi(mystring);
		getline(ss, mystring, ',');
		if (mystring != "") station_lines->station_id = stoi(mystring);
		getline(ss, mystring, ',');
		if (mystring != "") station_lines->line_id = stoi(mystring);
		getline(ss, mystring, ',');
		if (mystring != "") station_lines->city_id = stoi(mystring);
		getline(ss, station_lines->created_at, ',');
		getline(ss, station_lines->updated_at, ',');
		Dataset->station_lines->push_back(*station_lines);
		delete station_lines;
	}
	Citycsv.close();
	//-------------------------
};
void ReleaseData(void* & n) {};