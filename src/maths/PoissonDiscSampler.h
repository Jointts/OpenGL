//
// Created by Joonas on 11/17/2017.
//

#define STB_IMAGE_WRITE_IMPLEMENTATION

#ifndef GAME_POISSONDISCSAMPLER_H

#define GAME_POISSONDISCSAMPLER_H
#include <cmath>
#include <vector>
#include <iostream>
#include <random>

#include <stb_image_write.h>

struct Point{
    double x, y;
};

struct PoissonSample{
    double x, y;
    int sample;
    int iterations;
};


// Generate up to k points chosen uniformly from the spherical annulus between radius r and 2r around xi
// http://www.cs.ubc.ca/~rbridson/docs/bridson-siggraph07-poissondisk.pdf
class PoissonDiscSampler {

public:

    static std::vector<Point*> poissonSamplesOutput;
    static int _distanceBetweenSamples;
	static int _gridSize;
	static int _cellSize;
	static Point* _coordBoundaries;

    static std::vector<Point *> GetSamples(int sampleIndex, int distanceBetweenSamples, int gridSize, int rejectionSampleLimit = 30, int dimensions = 2) {
		_coordBoundaries = new Point;
		_coordBoundaries->x = 320;
		_coordBoundaries->y = 320;
        _distanceBetweenSamples = distanceBetweenSamples;
		_gridSize = gridSize;
    	std::random_device rd;
        std::default_random_engine generator(rd());
        _cellSize = distanceBetweenSamples / sqrt(dimensions);
        std::vector<PoissonSample*> grid;
        std::vector<int> activeList = std::vector<int>();

        activeList.push_back(sampleIndex);
        for(int pos = 0; pos < gridSize * gridSize; ++pos) {
            int x = pos % gridSize;
            int y = pos / gridSize;

            auto *poissonSample = new PoissonSample();
            poissonSample->x = x * _cellSize;
            poissonSample->y = y * _cellSize;
            poissonSample->sample = -1;
            poissonSample->iterations = rejectionSampleLimit;

            grid.push_back(poissonSample);
        }

        grid[sampleIndex]->sample = 0;

        while(!activeList.empty()){
            std::uniform_int_distribution<int> distribution(0, (int) (activeList.size() - 1));
            int activeListIndex = distribution(generator);
            CheckAnnulus(grid, activeList, activeListIndex, generator);
        }

        std::cout << "Shit";

        DrawPoints(200, 200);
        return poissonSamplesOutput;
    }

    static void CheckAnnulus(std::vector<PoissonSample*> &grid, std::vector<int> &activeList, int activeListIndex, std::default_random_engine& generator) {
		int activeSampleGridIndex = activeList[activeListIndex];
        PoissonSample* activeSample = grid[activeSampleGridIndex];
        if(activeSample->iterations == 0){
            activeList.erase(activeList.begin() + activeListIndex);
            return;
        }

        Point* point = GenerateRandomPoint(_distanceBetweenSamples, generator);
        point->x += activeSample->x;
        point->y += activeSample->y;

        for (int x = -1; x <= 1; ++x) {
            for(int y = -1; y <= 1; ++y){
				int yAdd = y * _gridSize;
				int xAdd = x;

				int indexToScan = activeSampleGridIndex + xAdd + yAdd;

                if(indexToScan >= 0 && indexToScan < grid.size()){
					PoissonSample* cellToScan = grid[indexToScan];
					if(cellToScan->sample == -1)
					{
						auto *resultPoint = new Point;
						resultPoint->x = cellToScan->x - point->x;
						resultPoint->y = cellToScan->y - point->y;

						Point *finalPoint = new Point;
						finalPoint->x = cellToScan->x + point->x;
						finalPoint->y = cellToScan->y + point->y;

						double pointDistance = sqrt(pow(resultPoint->x, 2) + pow(resultPoint->y, 2));
						if (pointDistance > _distanceBetweenSamples && pointDistance < _distanceBetweenSamples * 2) {
//							if (finalPoint->x > 0 && finalPoint->y > 0 && finalPoint->x < _coordBoundaries->x && finalPoint->y < _coordBoundaries->y)
//							{
								poissonSamplesOutput.push_back(finalPoint);
//							}
							activeList.push_back(indexToScan);
							cellToScan->sample = indexToScan;
						}
					}
                }
            }
        }

        activeSample->iterations -= 1;
    }

    static Point* GenerateRandomPoint(int r, std::default_random_engine &generator) {
        std::uniform_real_distribution<double> magnitudeDistribution(r, 2 * r);
        double magnitude = magnitudeDistribution(generator);

        std::uniform_int_distribution<int> angleDistribution(0, 360);
        double angle = angleDistribution(generator);

        double x = cos(angle);
        double y = sin(angle);

        auto *point = new Point;
        point->x = x * magnitude;
        point->y = y * magnitude;

        return point;
    }

    static void DrawPoints(int width, int height) {
		int scale = 10;
        std::vector<uint8_t> pixels;
        for (int i = 0; i < width * height * scale; ++i) {
            pixels.push_back(0);
            pixels.push_back(0);
            pixels.push_back(0);
        }
        for(Point* point: poissonSamplesOutput){
			int row = (point->x / _cellSize) / _gridSize;
			int col = (int) point->y % _gridSize;
			int pixelIndex = (row * _gridSize + col) * 3 * scale;
			if(pixelIndex >= 0 && pixelIndex + 2 < pixels.size())
			{
				pixels.at(pixelIndex) = 255;
				pixels.at(pixelIndex + 1) = 255;
				pixels.at(pixelIndex + 2) = 255;
			}
		}
//        pixels.at(0) = 255;
//        pixels.at(1) = 255;
//        pixels.at(2) = 255;
//        pixels.at((width - 1) * 3) = 255;
//        pixels.at((width - 1) * 3 + 1) = 255;
//        pixels.at((width - 1) * 3 + 2) = 255;
        stbi_write_jpg("C:/Users/Joonas/Desktop/test.jpg", _gridSize * scale, _gridSize * scale, 3, pixels.data(), 100);
    }
};

std::vector<Point*> PoissonDiscSampler::poissonSamplesOutput = std::vector<Point*>();
int PoissonDiscSampler::_distanceBetweenSamples = 0;
int PoissonDiscSampler::_gridSize = 0;
int PoissonDiscSampler::_cellSize = 0;
Point* PoissonDiscSampler::_coordBoundaries = new Point;


#endif //GAME_POISSONDISCSAMPLER_H
