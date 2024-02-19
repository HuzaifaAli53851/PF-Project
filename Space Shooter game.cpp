#include <fstream>
#include <graphics.h>
#include <iostream>
#include <string>
#include<sstream>
using namespace std;

int score=0;
// Function to write the score to a file
void WriteScoreToFile(int totalScore) {
    ofstream file("score.txt");
    if (file.is_open()) {
        file << totalScore;
        file.close();
    } else {
        cout << "Unable to open the score file for writing." << endl;
    }
}

// Function to read the score from a file
int ReadScoreFromFile() {
    int savedScore = 0;
    ifstream file("score.txt");
    if (file.is_open()) {
        file >> savedScore;
        file.close();
    } else {
        cout << "Unable to open the score file for reading." << endl;
    }
    return savedScore;
}


void Game()
{
	int x = 400;
	initwindow(800, 700);
	int bul = 0;
	int bulx;
	int buly = 600;
	int enex[3] = { 200,400,600 };
	int eney = 100;
	int rad[3] = { 40,40,40 };



	for (;;) {
		
		circle(x, 600, 20);
		setfillstyle(SOLID_FILL, BLUE);
	    floodfill(x, 600, WHITE);
		if (GetAsyncKeyState('A')) {
			x -= 2;
		}
		if (GetAsyncKeyState('D')) {
			x += 2;
		}
		if (GetAsyncKeyState(' ') && bul == 0) {
			bul = 1;
			bulx = x;
		}
		if (bul == 1) {
			circle(bulx, buly, 10);
			buly -= 10;
		}
		if (buly <= 0) {
			bul = 0;
			buly = 600;
		}

		for (int a = 0; a < 3; a++) {
			circle(enex[a], eney, rad[a]);
			if (buly == eney && bulx >= (enex[a] - 20) && bulx <= (enex[a] + 20)) {
				rad[a] = 0;
				bul = 0;
				buly = 600;
				score = score+100;
			}

		}

		for (int a = 0; a < 3; a++)
		{
			if (rad[a] > 0)
			{
				setfillstyle(SOLID_FILL, RED);
				floodfill(enex[a], eney, WHITE);
			}
		}
		
		stringstream ss;
		ss << "Score: " << score;
		outtextxy(getmaxx() - 100, 20, const_cast<char*>(ss.str().c_str()));
		
		
		if(rad[0] == 0 && rad[1] == 0 && rad[2] == 0)
		{
			system("cls");
		cout << "======================================================" << endl;
		cout << "||                                                  ||" << endl;
		cout << "||               LEVEL 1 ENDED                      ||" << endl;
		cout << "||                                                  ||" << endl;
		cout << "======================================================" << endl;
    WriteScoreToFile(score);
    int savedScore = ReadScoreFromFile();
    cout << "Your Total Score: " << savedScore << endl;
	
		cout<<"Procediing to Next level......."<<endl;
		cout<<"Press any key to proceed to next level: "<<endl;
		system("pause");
		break;
		}
		





		delay(10);
		cleardevice();
		
		



	}
	
}


void Game2()
{
	int x = 400;
	initwindow(800, 700);
	int bul = 0;
	int bulx;
	int buly = 600;
	int enex[3] = { 200,400,600 };
	int eney = 100;
	int rad[3] = { 40,40,40 };
	int direction[3] = { 1, -1, 1 };



	for (;;) {
		
		circle(x, 600, 20);
		setfillstyle(SOLID_FILL, YELLOW);
	    floodfill(x, 600, WHITE);
		if (GetAsyncKeyState('A')) {
			x -= 2;
		}
		if (GetAsyncKeyState('D')) {
			x += 2;
		}
		if (GetAsyncKeyState(' ') && bul == 0) {
			bul = 1;
			bulx = x;
		}
		if (bul == 1) {
			circle(bulx, buly, 10);
			buly -= 10;
		}
		if (buly <= 0) {
			bul = 0;
			buly = 600;
		}

		for (int a = 0; a < 3; a++) {
			circle(enex[a], eney, rad[a]);
			
			// Move enemies horizontally
			enex[a] += direction[a] * 2;
			
			if (buly == eney && bulx >= (enex[a] - 20) && bulx <= (enex[a] + 20)) {
				rad[a] = 0;
				bul = 0;
				buly = 600;
				score = score+200;
			}

		}
		
		// Reverse direction if an enemy reaches the window edge
		for (int a = 0; a < 3; a++) {
			if (enex[a] <= 0 || enex[a] >= getmaxx()) {
				direction[a] *= -1;
			}
		}

		for (int a = 0; a < 3; a++)
		{
			if (rad[a] > 0)
			{
				setfillstyle(SOLID_FILL, RED);
				floodfill(enex[a], eney, WHITE);
			}
		}
		
		stringstream ss;
		ss << "Score: " << score;
		outtextxy(getmaxx() - 100, 20, const_cast<char*>(ss.str().c_str()));
		
		
		if(rad[0] == 0 && rad[1] == 0 && rad[2] == 0)
		{
			system("cls");
		cout << "======================================================" << endl;
		cout << "||                                                  ||" << endl;
		cout << "||               LEVEL 2 ENDED                      ||" << endl;
		cout << "||                                                  ||" << endl;
		cout << "======================================================" << endl;
		WriteScoreToFile(score);
        int savedScore = ReadScoreFromFile();
        cout << "Your Total Score: " << savedScore << endl;

		cout<<"Procediing to Next level......."<<endl;
		cout<<"Press any key to proceed to next level: "<<endl;
		system("pause");
		break;
		}
		





		delay(10);
		cleardevice();
		
		



	}

}


void Game3()
{
	int x = 400;
	initwindow(800, 700);
	int bul = 0;
	int bulx;
	int buly = 600;
	int enex[3] = { 200,400,600 };
	int eney = 100;
	int rad[3] = { 40,40,40 };
	int eneBulrad[3] = {5,5,5};
	int direction[3] = { 1, -1, 1 };
	
	int eneBulX[3], eneBulY[3], eneBulStatus[3] = {0};
    int eneBulSpeed = 5;  // Adjust bullet speed as needed

	for (;;) {
		
		circle(x, 600, 20);
		setfillstyle(SOLID_FILL, GREEN);
	    floodfill(x, 600, WHITE);
		if (GetAsyncKeyState('A')) {
			x -= 2;
		}
		if (GetAsyncKeyState('D')) {
			x += 2;
		}
		if (GetAsyncKeyState(' ') && bul == 0) {
			bul = 1;
			bulx = x;
		}
		if (bul == 1) {
			circle(bulx, buly, 10);
			buly -= 10;
		}
		if (buly <= 0) {
			bul = 0;
			buly = 600;
		}

		for (int a = 0; a < 3; a++) {
			circle(enex[a], eney, rad[a]);
			
			// Move enemies horizontally
			enex[a] += direction[a] * 2;
			
			
			if (rad[a] > 0) 
		{
			// Shoot bullets
            if (rand() % 100 < 5 && eneBulStatus[a] == 0) {
                eneBulStatus[a] = 1;
                eneBulX[a] = enex[a];
                eneBulY[a] = eney + rad[a] + 5;  // Adjust the offset as needed
            }

            // Update enemy bullet positions
            if (eneBulStatus[a] == 1) {
                eneBulY[a] += eneBulSpeed;
                // Draw enemy bullets
                circle(eneBulX[a],eneBulY[a],eneBulrad[a]);
                

                if (eneBulY[a] > getmaxy()) {
                    eneBulStatus[a] = 0;  // Reset bullet when it goes out of screen
                }
            }
        }

            // Check for collision with player's shooter
            if (eneBulStatus[a] == 1 && eneBulX[a] >= (x - 20) && eneBulX[a] <= (x + 20) && eneBulY[a] >= (600 - 20)) {
                // Shooter is hit
                system("cls");
		cout << "======================================================" << endl;
		cout << "||                                                  ||" << endl;
		cout << "||               LEVEL 3 FAILED                     ||" << endl;
		cout << "||                                                  ||" << endl;
		cout << "======================================================" << endl;
                cout << "Game Over! Your shooter got hit." << endl;
                system("pause");
                exit(0);  // Terminate the program
            }

			
			
			if (buly == eney && bulx >= (enex[a] - 20) && bulx <= (enex[a] + 20)) {
				rad[a] = 0;
				bul = 0;
				buly = 600;
				score = score+300;
			}

		}
		
		// Reverse direction if an enemy reaches the window edge
		for (int a = 0; a < 3; a++) {
			if (enex[a] <= 0 || enex[a] >= getmaxx()) {
				direction[a] *= -1;
			}
		}

		for (int a = 0; a < 3; a++)
		{
			if (rad[a] > 0)
			{
				setfillstyle(SOLID_FILL, RED);
				floodfill(enex[a], eney, WHITE);
			}
		}
		
		stringstream ss;
		ss << "Score: " << score;
		outtextxy(getmaxx() - 100, 20, const_cast<char*>(ss.str().c_str()));
		
		
		if(rad[0] == 0 && rad[1] == 0 && rad[2] == 0)
		{
			system("cls");
		cout << "======================================================" << endl;
		cout << "||                                                  ||" << endl;
		cout << "||               LEVEL 3 ENDED                      ||" << endl;
		cout << "||                                                  ||" << endl;
		cout << "======================================================" << endl;
		WriteScoreToFile(score);
        int savedScore = ReadScoreFromFile();
        cout << "Your Total Score: " << savedScore << endl;

		system("pause");
		break;
		}
		





		delay(10);
		cleardevice();
		
		



	}
	
}



void Menu()
{
	int choice;
	do
	{
		cout << "-----------------------------------------------------" << endl;
		cout << endl;
		cout << "         WELCOME TO SPACE SHOOTER GAME" << endl;
		cout << endl;
		cout << "-----------------------------------------------------" << endl;
		cout << endl;
		cout << endl;

		cout << "======================================================" << endl;
		cout << "||                                                  ||" << endl;
		cout << "||   1. Start                                       ||" << endl;
		cout << "||   2. Exit                                        ||" << endl;
		cout << "||                                                  ||" << endl;
		cout << "======================================================" << endl;
		cout << endl;
		cout << "Enter Your Choice (1/2) : ";

		cin >> choice;
		switch (choice)
		{
		case 1:
			cout << "You are playing game\n  Use (A) to move Left \n Use (D) to move Right \n Use (SpaceBar) to Shoot Bullets \n";
			Game();
			system("cls");
		    cout << "======================================================" << endl;
		    cout << "||                                                  ||" << endl;
			cout << "||               LEVEL 2 START!                     ||" << endl;
			cout << "||                                                  ||" << endl;
			cout << "======================================================" << endl;
			Game2();
			system("cls");
		    cout << "======================================================" << endl;
		    cout << "||                                                  ||" << endl;
			cout << "||               LEVEL 3 START!                     ||" << endl;
			cout << "||                                                  ||" << endl;
			cout << "======================================================" << endl;
			Game3();
			system("cls");
			cout << "======================================================" << endl;
		    cout << "||                                                  ||" << endl;
			cout << "||               CONGRATULATIONS!                   ||" << endl;
			cout << "||               YOU BEAT THE GAME!                 ||" << endl;
			cout << "||                                                  ||" << endl;
			cout << "======================================================" << endl;
			system("pause");
			break;
		case 2:
			system("cls");
			cout << "-----------------------------------------------------" << endl;
			cout << endl;
			cout << "                        GOOD BYE" << endl;
			cout << "                        GAME ENDED" << endl;
			cout << endl;
			cout << "-----------------------------------------------------" << endl;
			system("pause");


			break;
			
		default:
			cout<<"Enter A Valid Input From (1/2)!! ";
			system("pause");
		}
		system("cls");
		
	} while (choice != 2);

}




int main()
{

	Menu();

	system("pause");

	return 0;

}
