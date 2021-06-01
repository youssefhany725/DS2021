#pragma once
#include <iostream>
#include <fstream>
#include <string>
using namespace std;
class MarsStation;
class UI
{
private:
	ifstream ReadActionParameters();
public:
	void input(MarsStation* ms);
	void output();
};

