#pragma once
#include <string>
#include <fstream>
#include <vector>

void JsonToObj(const std::string& jsonFile, const std::string& objFile);
void AddCube(std::ofstream& fs, float* position, int& vertexCount, const std::string& layer);

struct FVector3
{
	float x;
	float y;
	float z;
};

struct FVector2
{
	float x;
	float y;
};

struct Vertex
{
	FVector3 position{};
	FVector3 normal{};
	FVector2 uv{};
};

std::vector<Vertex> GetVerticesFromObj(const std::string& objScene);