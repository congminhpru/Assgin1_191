/* Created by Nguyen Duc Dung on 2019-09-03.
 * =========================================================================================
 * Name        : processData.cpp
 * Author      : Duc Dung Nguyen
 * Email       : nddung@hcmut.edu.vn
 * Copyright   : Faculty of Computer Science and Engineering - HCMUT
 * Description : Implementation of main features in the assignment
 * Course      : Data Structure and Algorithms - Fall 2019
 * =========================================================================================
 */

#include "processData.h"
#include "dbLib.h"
using namespace std;
/* TODO: You can implement methods, functions that support your data structures here.
 * */
using namespace std;

void Initialization() {
    // If you use global variables, please initialize them explicitly in this function.
}

void Finalization() {
    // Release your data before exiting
}

void ProcessRequest(const char* pRequest, void* pData, void* &pOutput, int &N) {
	// TODO: Implement this function for processing a request
	// NOTE: You can add other functions to support this main process.
	//       pData is a pointer to a data structure that manages the dataset
	//       pOutput is a pointer reference. It is set to nullptr and student must allocate data for it in order to save the required output
	//       N is the size of output, must be a non-negative numbe

	TDataset *datashet = (TDataset*)pData;

	if (!strcmp(pRequest, "CL")) {
		pOutput = new int(datashet->City->getSize());
		N = 1;
		return;
	};

	stringstream ss;
	ss << pRequest;
	string quest, strs1, str2;
	ss >> quest >> strs1 >> str2;
	// for CL <city_name>

	if (quest == "CL") {
		N = 0;
		int countCity = 0;
		for (int i = 1; i <= datashet->City->getSize(); i++)
		{
			if (strs1 == datashet->City->at(i).name) countCity++;
		};
		if (countCity == 0) countCity = -1;
		pOutput = new int(countCity);
		N = 1;
	}

	if (quest == "LSC") {
		N = 0;
		int cityid = 0;
		int count = 0;
		for (int i = 1; i <= datashet->City->getSize(); i++)
		{

			if (strs1 == datashet->City->at(i).name) cityid = datashet->City->at(i).id;
		};
		for (int i = 1; i <= datashet->stations->getSize(); i++)
		{
			if (cityid == datashet->stations->at(i).city_id) count++;
		}
		pOutput = new int[count];
		N = 0;
		for (int i = 1; i <= datashet->stations->getSize(); i++)
		{
			if (cityid == datashet->stations->at(i).city_id) ((int*)pOutput)[N++] = datashet->stations->at(i).id;
		}
		N = count;
	}

	//-----------------------------
	if (quest == "LLC") {
		N = 0;
		int cityid = 0;
		int count = 0;
		for (int i = 1; i <= datashet->City->getSize(); i++)
		{

			if (strs1 == datashet->City->at(i).name) cityid = datashet->City->at(i).id;
		};
		for (int i = 1; i <= datashet->Line->getSize(); i++)
		{
			if (cityid == datashet->Line->at(i).city_id) count++;
		}
		pOutput = new int[count];
		N = 0;
		for (int i = 1; i <= datashet->Line->getSize(); i++)
		{
			if (cityid == datashet->Line->at(i).city_id) ((int*)pOutput)[N++] = datashet->Line->at(i).id;
		}
		N = count;
	}
	//--------------
	if (quest == "LSL") {
		int count = 0;
		N = 0;
		int lineid = stoi(strs1);
		for (int i = 1; i <= datashet->station_lines->getSize(); i++)
		{
			if (lineid == datashet->station_lines->at(i).line_id) count++;
		}
		
		pOutput = new int[count];
		for (int i = 1; i <= datashet->station_lines->getSize(); i++)
		{
			if (lineid == datashet->station_lines->at(i).line_id) ((int*)pOutput)[N++]= datashet->station_lines->at(i).station_id;
		}
		N = count;
	}
	//===============
	if (quest == "FC") {
		N = 0;
		int cityid = 0;
		int count = 0;
		for (int i = 1; i <= datashet->City->getSize(); i++)
		{

			if (strs1 == datashet->City->at(i).name) cityid = datashet->City->at(i).id;
		};
		pOutput = new int(cityid);
		N = 1;
	}

	if (quest == "FS") {
		N = 0;
		int stationid = 0;
		int count = 0;
		for (int i = 1; i <= datashet->stations->getSize(); i++)
		{

			if (strs1 == datashet->stations->at(i).name) {
				count++; stationid = i; break;
			};
		}
		if (!count) {
			pOutput = new int(-1);
			N = 1;
		}
		else {
			pOutput = new int(datashet->stations->at(stationid).id);
			N = 1;
		}
	}
	//-----------------------------

	if (quest == "SLP") {
		N = 0;
		int index = 0;
		string checkgeo;
		string geosta = "";
		string geotra = "";
		bool check = false;
		for (int i = 1; i <= datashet->stations->getSize(); i++) {
			if (stoi(strs1) == datashet->stations->at(i).id)
			{
				geosta = datashet->stations->at(i).geometry;

				geosta = geosta.substr(6, geosta.length() - 7);
				check = true;
				break;

			}
		}
		if (!check) {
			pOutput = new int(-1);
			N = 1;
		}
		check = false;
		for (int i = 1; i <= datashet->Tracks->getSize(); i++) {
			if (stoi(str2) == datashet->Tracks->at(i).id)
			{
				geotra = datashet->Tracks->at(i).geometry;

				geotra = "1,2,3";
				check = true;
				break;
			}
		}
		if (!check) {
			pOutput = new int(-1);
			N = 1;
		}
		stringstream ss(geotra);
		getline(ss, checkgeo, ',');
		check = false;
		while (checkgeo != "")
		{
			if (checkgeo != geosta)
			{
				index++;
				if (!(getline(ss, checkgeo, ','))) break;
			}
			else {
				check = true; break;
			}
		}
		if (!check)
		{
			pOutput = new int(-1);
			N = 1;
		}
		else {
			pOutput = new int(index );
			N = 1;
		}
	}
	//---------------------

	if (quest == "IS") {
		N = 0;
		stringstream ss(strs1);
		string mystring;
		Tstations *stations = new Tstations;
		int max = 0;
		for (int i = 1; i <= datashet->stations->getSize(); i++)
		{
			if (datashet->stations->at(i).id > max) max = datashet->stations->at(i).id;
		}
		stations->id = max + 1;
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
		if (mystring != "") stations->city_id = stoi(mystring); else  stations->city_id = -1;

		datashet->stations->push_back(*stations);
		delete stations;
	}
	//-------------------
	if (quest == "US") {
		N = 0;
		int n = 0;
		for (int i = 1; i <= datashet->stations->getSize(); i++)
		{
			if (stoi(strs1) == datashet->stations->at(i).id) { n = i; break; }
		}
		if (!n) 
		{
			pOutput = new int(-1);
			N = 1;
			return;
		}
		stringstream ss(str2);
		string mystring;
		Tstations *stations = new Tstations;
		stations->id = datashet->stations->at(n).id;
		if (ss.peek() == '"') { getline(ss, stations->name, '"'); getline(ss, stations->name, '"'); getline(ss, mystring, ','); }
		else  getline(ss, stations->name, ',');
		getline(ss, stations->geometry, ',');
		getline(ss, mystring, ',');
		if (mystring != "") stations->buildstart = stoi(mystring); else stations->buildstart = datashet->stations->at(n).buildstart;
		getline(ss, mystring, ',');
		if (mystring != "") stations->opening = stoi(mystring); else stations->opening= datashet->stations->at(n).opening;
		getline(ss, mystring, ',');
		if (mystring != "") stations->closure = stoi(mystring); else stations->closure= datashet->stations->at(n).closure;
		getline(ss, mystring);
		if (mystring != "") stations->city_id = stoi(mystring); else stations->city_id = datashet->stations->at(n).city_id;

		datashet->stations->at(n)=*stations;
		delete stations;
	}
	//-------------------

	//-------------------
	if (quest == "RS") {
		N = 0;
		bool found = false;
		int i = 1;
		while (i<= datashet->stations->getSize())
		{

			if (stoi(strs1) == datashet->stations->at(i).id) {
				datashet->stations->remove(i);
				found = true;
				i--;
			}; 
			i++;
		}
		if (!found)
		{
			pOutput = new int(-1);
			N = 1;
		}
	}
	/*if (quest == "RSL") {
		bool found = false;
		int cityid = 0;
		for (int i = 1; i < datashet->Line->getSize(); i++)
		{
			if (stoi(str2) == datashet->Line->at(i).id) {

				found = true; cityid = datashet->Line->at(i).city_id; break;
			}
		
		}
		if (!found)
		{
			pOutput = new int(-1);
			N = 1;
		}
		else {
			int j = 1;
			while (j <= datashet->stations->getSize())
			{

				if (stoi(strs1) == datashet->stations->at(j).city_id) {
					datashet->stations->remove(j);
					found = true;
				};
				j++;
			}

		}

	}*/
}