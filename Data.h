#pragma once
#include <iostream>
#include <time.h>
#include <string>
#include <ctime>

using namespace std;

class Data
{
	time_t time;

public:
	Data();
	//Data(string s);
	time_t getData();
	void setData(time_t time);
};

