#pragma once
#include <string>
#include <fstream>

void JsonToObj(const std::string& jsonFile, const std::string& objFile);
void AddCube(std::ofstream& fs, float* position, int& vertexCount, const std::string& layer);