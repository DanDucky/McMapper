#include <iostream>
#include "./svgTools/map.hpp"

using namespace std;
using namespace mcmap;

int main () {
	McMapSettings settings;
	settings.fileName = "zoowee";
	settings.includeRoof = false;
	settings.layerHeight = 2;
	settings.sizeX = 5000;
	settings.sizeZ = 5000;
	McMap * map = new McMap(settings);
}
