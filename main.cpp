#include <iostream>
#include <vector>
#include <conio.h>
#include <ctime>
#include<bits/stdc++.h>



#define KEY_UP 72
#define KEY_DOWN 80
#define KEY_LEFT 75
#define KEY_RIGHT 77
#define ESC 27


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
    notAnArrow:
        PrintGrid(gameGrid);


        key = getch();
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
            case ESC:
                finish = true;
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

void upArrow(std::vector<std::vector<int>> &a) {
    int i,j,li,ri;
    for(j=0;j<4;j++)
    {
        li=0,ri=j;
        for(i=1;i<4;i++)
        {
            if(a[i][j]!=0)
            {
                if(a[i-1][j]==0 || a[i-1][j]==a[i][j])
                {
                    if(a[li][ri]==a[i][j])
                    {
                        a[li][ri]*=2;
                        a[i][j]=0;
                    }
                    else
                    {
                        if(a[li][ri]==0)
                        {
                            a[li][ri]=a[i][j];
                            a[i][j]=0;
                        }
                        else
                        {
                            a[++li][ri]=a[i][j];
                            a[i][j]=0;
                        }
                    }
                }
                else li++;
            }
        }
    }

}

void downArrow(std::vector<std::vector<int>> &a) {
    int i,j,li,ri;
    for(j=0;j<4;j++)
    {
        li=3,ri=j;
        for(i=2;i>=0;i--)
        {
            if(a[i][j]!=0)
            {
                if(a[i+1][j]==0 || a[i+1][j]==a[i][j])
                {
                    if(a[li][ri]==a[i][j])
                    {
                        a[li][ri]*=2;
                        a[i][j]=0;
                    }
                    else
                    {
                        if(a[li][ri]==0)
                        {
                            a[li][ri]=a[i][j];
                            a[i][j]=0;
                        }
                        else
                        {
                            a[--li][ri]=a[i][j];
                            a[i][j]=0;
                        }
                    }
                }
                else li--;
            }
        }
    }
}

void leftArrow(std::vector<std::vector<int>> &a) {
    int i,j,li,ri;
    for(i=0;i<4;i++)
    {
        li=i,ri=0;
        for(j=1;j<4;j++)
        {
            if(a[i][j]!=0)
            {
                if(a[i][j-1]==0 || a[i][j-1]==a[i][j])
                {
                    if(a[li][ri]==a[i][j])
                    {
                        a[li][ri]*=2;
                        a[i][j]=0;
                    }
                    else
                    {
                        if(a[li][ri]==0)
                        {
                            a[li][ri]=a[i][j];
                            a[i][j]=0;
                        }
                        else
                        {
                            a[li][++ri]=a[i][j];
                            a[i][j]=0;
                        }
                    }
                }
                else ri++;
            }
        }
    }
}

void rightArrow(std::vector<std::vector<int>> &a) {
    int i,j,li,ri;
    for(i=0;i<4;i++)
    {
        li=i,ri=3;
        for(j=2;j>=0;j--)
        {
            if(a[i][j]!=0)
            {
                if(a[i][j+1]==0 || a[i][j+1]==a[i][j])
                {
                    if(a[li][ri]==a[i][j])
                    {
                        a[li][ri]*=2;
                        a[i][j]=0;
                    }
                    else
                    {
                        if(a[li][ri]==0)
                        {
                            a[li][ri]=a[i][j];
                            a[i][j]=0;
                        }
                        else
                        {
                            a[li][--ri]=a[i][j];
                            a[i][j]=0;
                        }
                    }
                }
                else ri--;
            }
        }
    }
}

void PrintGrid(const std::vector<std::vector<int>>& a){
    system("cls");

    std::cout << "\n\t\tPress Esc anytime to quit the game";
    std::cout << "\n\n\n\n";
    int i,j;
    for(i=0;i<4;i++)
    {
        std::cout << "\t\t\t\t-----------------\n\t\t\t\t";
        for(j=0;j<4;j++)
        {
            if(a[i][j]==0) std::cout << "|   ";
            else
                std::cout << "| " << a[i][j] << " ";
        }
        std::cout << "|" << std:: endl;
    }
    std::cout << "\t\t\t\t-----------------\n";
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

    std::cout << "You win" << std::endl;
}

void loose() {

    std::cout << "You loose" << std::endl;
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

void PlaceNewNumber(std::vector<std::vector<int>> &grid) {
    int li,ri;
    srand(time(0));
    while(1)
    {
        li=rand()%4;
        ri=rand()%4;
        if(grid[li][ri]==0)
        {
            grid[li][ri]=pow(2,li%2 + 1);
            break;
        }
    }
}

