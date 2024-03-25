#include "Class.h"

int main() {
	setlocale(LC_ALL, "Russian");
	Station a;
	int count = 27;
	Station* stations = new Station[count];
	a.ReadFile(stations);
	//a.GetLineData(2, stations, count);
	a.OneLineStationsRoad(stations, count);
}