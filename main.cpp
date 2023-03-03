#include <iostream>
#include <vector>
#include <conio.h>
#include <stdio.h>
#include "time.h"


#define KEY_UP 72
#define KEY_DOWN 80
#define KEY_LEFT 75
#define KEY_RIGHT 77

void PrintGrid(const std::vector<std::vector<int>>& grid);
std::vector<std::vector<int>> StarterGrid(std::vector<std::vector<int>>& grid);
std::vector<std::vector<int>> DevGridGen();
std::vector<std::vector<int>> Initialize();
void upArrow(std::vector<std::vector<int>>& grid);
void downArrow(std::vector<std::vector<int>>& grid);
void leftArrow(std::vector<std::vector<int>>& grid);
void rightArrow(std::vector<std::vector<int>>& grid);
void checkFinal(std::vector<std::vector<int>>& grid, bool end, bool win, bool loose);
void winer();
void loose();
int GetRandomNumber(int a, int b);
int SetNewNumber();
void PlaceNewNumber(std::vector<std::vector<int>>& grid);

int main() {
	bool finish = false;
    bool winner = false;
    bool looser = false;
	std::vector<std::vector<int>> gameGrid = Initialize();
    std::cout << "Rows: " << gameGrid.size() << std::endl << "Columns: " << gameGrid[0].size() << std::endl;

	gameGrid = StarterGrid(gameGrid);
    std::cout << "Rows: " << gameGrid.size() << std::endl << "Columns: " << gameGrid[0].size() << std::endl;

    int key;

	while (!finish)
	{

        PrintGrid(gameGrid);

notAnArrow:
        key = getch();
        //#TODO Make arrows functions
        switch(key) {
            case KEY_UP:
                upArrow(gameGrid);
                PlaceNewNumber(gameGrid);
                break;
            case KEY_DOWN:
                downArrow(gameGrid);
                PlaceNewNumber(gameGrid);
                break;
            case KEY_LEFT:
                leftArrow(gameGrid);
                PlaceNewNumber(gameGrid);
                break;
            case KEY_RIGHT:
                rightArrow(gameGrid);
                PlaceNewNumber(gameGrid);
                break;
            default:
                goto notAnArrow;
                break;
        }

        PrintGrid(gameGrid);
        checkFinal(gameGrid, finish, winner, looser);
        if(winner){
            winer();
        }
        if(looser){
            loose();
        }

	}

    system("pause");
    return 0;

}

void upArrow(std::vector<std::vector<int>> &grid) {

}

void downArrow(std::vector<std::vector<int>> &grid) {

}

void leftArrow(std::vector<std::vector<int>> &grid) {

}

void rightArrow(std::vector<std::vector<int>> &grid) {

}

void PrintGrid(const std::vector<std::vector<int>>& grid){
    system("cls");

	for(int i = 0; i < grid.size(); ++i){
        for(int j = 0; j < grid[i].size(); ++j){
            if(grid[i][j] != 0){
                std::cout << "| "<< grid[i][j] << " | ";
            } else{
                std::cout << "| "<< " " << " | ";
            }
        }
        std::cout << std::endl;
    }
}

std::vector<std::vector<int>> StarterGrid(std::vector<std::vector<int>>& grid){
    std::vector<std::vector<int>> tmp = grid;
    for(int i = 0; i < 4; ++i){
        for(int j = 0; j < 4; ++j){
            srand(time(NULL));
            int tmp1 = GetRandomNumber(0, 4);
            int tmp2 = GetRandomNumber(0, 4);

            tmp[tmp1][tmp2] = SetNewNumber();

        }
    }
    tmp[0][0] = 2;
    tmp[0][1] = 2;
    tmp[1][0] = 2;
    return tmp;

}

std::vector<std::vector<int>> DevGridGen(){
    std::vector<std::vector<int>> grid;

	int tmp = 0;
	for (int i = 0; i < 5; ++i) {
		std::vector<int> tmpRow;
		for (int j = 0; j < 5; ++j) {
			tmpRow.push_back(tmp++);
		}
		grid.push_back(tmpRow);
	}

    return grid;
}

void checkFinal(std::vector<std::vector<int>> &grid, bool end, bool win, bool loose) {

    for (auto v: grid){
        if(std::find(v.begin(), v.end(), 2048) != v.end()){
            end = true;
            win = true;
        }

        if (std::count(v.begin(), v.end(), 0)) {
            loose = true;
            end = true;
        } else{
            loose = false;
            end = false;
        }
    }

    if(win && loose){
        win = false;
        end = true;
    }

}

void winer() {

}

void loose() {

}

std::vector<std::vector<int>> Initialize() {
    std::vector<std::vector<int>> tmp;

    for (int i = 0; i < 5; ++i) {
        std::vector<int> tmpRow;
        for (int j = 0; j < 5; ++j) {
            tmpRow.push_back(0);
        }
        tmp.push_back(tmpRow);
    }

    return tmp;
}

int GetRandomNumber(int a, int b) {
    srand(rand());

    int num = a + rand() % (b - a + 1);
    return num;
}

int SetNewNumber() {
    int vault[2] = {2, 4};
    int index = GetRandomNumber(0,1);

    return vault[index];
}

// #TODO Fix PlaceNewNumber function
void PlaceNewNumber(std::vector<std::vector<int>> &grid) {
    int tmp1 = GetRandomNumber(0, 4);
    int tmp2 = GetRandomNumber(0, 4);
Fail:
    while (grid[tmp1][tmp2] == 0){
        tmp1 = GetRandomNumber(0, 4);
        tmp2 = GetRandomNumber(0, 4);
    }
    if(grid[tmp1][tmp2] == 0){
        goto Fail;
    }
    grid[tmp1][tmp2] = SetNewNumber();
}

