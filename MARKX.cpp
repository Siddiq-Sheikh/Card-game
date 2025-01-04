#include<iostream>
#include<conio.h>
#include<dos.h>
#include<windows.h>
#include<cmath>
#include<vector>
#include<set>

using namespace std;

#define SCREEN_WIDTH 110
#define SCREEN_HEIGHT 26
#define WIN_WIDTH 110
#define MAX_BULLETS 3

COORD coord = {0,0};
HANDLE console = GetStdHandle(STD_OUTPUT_HANDLE);
int shipPos = -1 + WIN_WIDTH/2 ;
long long int score = 0, money = 20000;
bool gameover = false;
set<long long int> scores {0};

void gotoxy(int x, int y) {
	coord.X = x;
	coord.Y = y;
	SetConsoleCursorPosition(console,coord);
}

void hideCursor() {
	HANDLE hStdOut = NULL;
	CONSOLE_CURSOR_INFO curInfo;
	hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);
	GetConsoleCursorInfo(hStdOut, &curInfo);
	curInfo.bVisible = FALSE;
	SetConsoleCursorInfo(hStdOut, &curInfo);
}

class MyException {
	public:
		const char *what() {
			return "Cannot be further upgraded";
		}
};

class Ships {
	public:
		virtual void setDamage(int) = 0;
		virtual void setSpeed(int) = 0;
		virtual void setHandling(int) = 0;
		virtual void setColor(int) = 0;
		virtual int getDamage() = 0;
		virtual int getSpeed() = 0;
		virtual int getHandling() = 0;
		virtual string getColor() = 0;
		virtual void drawShip() = 0;
		virtual void eraseShip() = 0;
};

class Ship1:public Ships {
	private:
		static int handling, speed, damage, color;
	public:
		void setDamage(int temp) {
			damage = temp;
		}
		void setSpeed(int temp) {
			speed = temp;
		}
		void setHandling(int temp) {
			handling = temp;
		}
		void setColor(int temp) {
			color = temp;
		}
		int getDamage() {
			return damage;
		}
		int getSpeed() {
			return speed;
		}
		int getHandling() {
			return handling;
		}
		string getColor() {
			switch(color) {
				case 1:
					return "White";
					break;
				case 2:
					return "Green";//green
					break;
				case 3:
					return "Cyan"; //cyan
					break;
				case 4:
					return "Red";//red
					break;
				case 5:
					return "Purple";//purple
					break;
				case 6:
					return "Yellow";//yellow
					break;
				default:
					return "White";
					break;
			}
		}
		void drawShip() {
			switch(color) {
				case 1:
					SetConsoleTextAttribute(console,7);//white
					break;
				case 2:
					SetConsoleTextAttribute(console,10);//green
					break;
				case 3:
					SetConsoleTextAttribute(console,11);//cyan
					break;
				case 4:
					SetConsoleTextAttribute(console,12);//red
					break;
				case 5:
					SetConsoleTextAttribute(console,13);//purple
					break;
				case 6:
					SetConsoleTextAttribute(console,6);//yellow
					break;
				default:
					SetConsoleTextAttribute(console,7);
					break;
			}
			gotoxy(shipPos+2, SCREEN_HEIGHT-4);
			cout<<":";
			gotoxy(shipPos+1, SCREEN_HEIGHT-3);
			cout<<":::";
			gotoxy(shipPos+2, SCREEN_HEIGHT-2);
			cout<<":";
			gotoxy(shipPos, SCREEN_HEIGHT-1);
			cout<<":::::";
			SetConsoleTextAttribute(console,7);
		}
		void eraseShip() {
			gotoxy(shipPos+2, SCREEN_HEIGHT-4);
			cout<<" ";
			gotoxy(shipPos+1, SCREEN_HEIGHT-3);
			cout<<"   ";
			gotoxy(shipPos+2, SCREEN_HEIGHT-2);
			cout<<" ";
			gotoxy(shipPos, SCREEN_HEIGHT-1);
			cout<<"     ";
		}
		friend class Enemy;
};
int Ship1::speed = 1;
int Ship1::handling = 1;
int Ship1::damage = 1;
int Ship1::color = 1;

class Ship2:public Ships {
	private:
		static int handling, speed, damage, color;
	public:
		void setDamage(int temp) {
			damage = temp;
		}
		void setSpeed(int temp) {
			speed = temp;
		}
		void setHandling(int temp) {
			handling = temp;
		}
		void setColor(int temp) {
			color = temp;
		}
		int getDamage() {
			return damage;
		}
		int getSpeed() {
			return speed;
		}
		int getHandling() {
			return handling;
		}
		string getColor() {
			switch(color) {
				case 1:
					return "White";
					break;
				case 2:
					return "Green";//green
					break;
				case 3:
					return "Cyan"; //cyan
					break;
				case 4:
					return "Red";//red
					break;
				case 5:
					return "Purple";//purple
					break;
				case 6:
					return "Yellow";//yellow
					break;
				default:
					return "White";
					break;
			}
		}
		void drawShip() {
			switch(color) {
				case 1:
					SetConsoleTextAttribute(console,7);//white
					break;
				case 2:
					SetConsoleTextAttribute(console,10);//green
					break;
				case 3:
					SetConsoleTextAttribute(console,11);//cyan
					break;
				case 4:
					SetConsoleTextAttribute(console,12);//red
					break;
				case 5:
					SetConsoleTextAttribute(console,13);//purple
					break;
				case 6:
					SetConsoleTextAttribute(console,6);//yellow
					break;
				default:
					SetConsoleTextAttribute(console,7);
					break;
			}
			gotoxy(shipPos+2, SCREEN_HEIGHT-4);
			cout<<":";
			gotoxy(shipPos+2, SCREEN_HEIGHT-3);
			cout<<":";
			gotoxy(shipPos, SCREEN_HEIGHT-2);
			cout<<": : :";
			gotoxy(shipPos, SCREEN_HEIGHT-1);
			cout<<":::::";
		}
		void eraseShip() {
			gotoxy(shipPos+2, SCREEN_HEIGHT-4);
			cout<<" ";
			gotoxy(shipPos+2, SCREEN_HEIGHT-3);
			cout<<" ";
			gotoxy(shipPos, SCREEN_HEIGHT-2);
			cout<<"     ";
			gotoxy(shipPos, SCREEN_HEIGHT-1);
			cout<<"     ";
		}
		friend class Enemy;
};
int Ship2::speed = 1;
int Ship2::handling = 1;
int Ship2::damage = 1;
int Ship2::color = 1;

class Ship3:public Ships {
	private:
		static int handling, speed, damage, color;
	public:
		void setDamage(int temp) {
			damage = temp;
		}
		void setSpeed(int temp) {
			speed = temp;
		}
		void setHandling(int temp) {
			handling = temp;
		}
		void setColor(int temp) {
			color = temp;
		}
		int getDamage() {
			return damage;
		}
		int getSpeed() {
			return speed;
		}
		int getHandling() {
			return handling;
		}
		string getColor() {
			switch(color) {
				case 1:
					return "White";
					break;
				case 2:
					return "Green";//green
					break;
				case 3:
					return "Cyan"; //cyan
					break;
				case 4:
					return "Red";//red
					break;
				case 5:
					return "Purple";//purple
					break;
				case 6:
					return "Yellow";//yellow
					break;
				default:
					return "White";
					break;
			}
		}
		void drawShip() {
			switch(color) {
				case 1:
					SetConsoleTextAttribute(console,7);//white
					break;
				case 2:
					SetConsoleTextAttribute(console,10);//green
					break;
				case 3:
					SetConsoleTextAttribute(console,11);//cyan
					break;
				case 4:
					SetConsoleTextAttribute(console,12);//red
					break;
				case 5:
					SetConsoleTextAttribute(console,13);//purple
					break;
				case 6:
					SetConsoleTextAttribute(console,6);//yellow
					break;
				default:
					SetConsoleTextAttribute(console,7);
					break;
			}
			gotoxy(shipPos+2, SCREEN_HEIGHT-4);
			cout<<":";
			gotoxy(shipPos+2, SCREEN_HEIGHT-3);
			cout<<":";
			gotoxy(shipPos+1, SCREEN_HEIGHT-2);
			cout<<":::";
			gotoxy(shipPos, SCREEN_HEIGHT-1);
			cout<<":::::";
			SetConsoleTextAttribute(console,7);
		}
		void eraseShip() {
			gotoxy(shipPos+2, SCREEN_HEIGHT-4);
			cout<<" ";
			gotoxy(shipPos+2, SCREEN_HEIGHT-3);
			cout<<" ";
			gotoxy(shipPos+1, SCREEN_HEIGHT-2);
			cout<<"   ";
			gotoxy(shipPos, SCREEN_HEIGHT-1);
			cout<<"     ";
		}
		friend class Enemy;
};
int Ship3::speed = 1;
int Ship3::handling = 1;
int Ship3::damage = 1;
int Ship3::color = 1;

class Bullets {
	private:
		int bulletX[MAX_BULLETS], bulletY[MAX_BULLETS];
		bool bulletFlag[MAX_BULLETS];
	public:
		Bullets() {
			for(int i=0; i<MAX_BULLETS; i++) {
				bulletFlag[i] = false;
			}
		}
		void bullet() {
			for(int i=0; i<MAX_BULLETS; i++) {
				if(bulletFlag[i]==false) {
					bulletX[i]=shipPos+2;
					bulletY[i]=22;
					bulletFlag[i]=true;
					break;
				}
			}
		}
		void drawBullet(int x,int y) {
			gotoxy(x, y);
			cout << "|";
		}
		void eraseBullet(int x,int y) {
			gotoxy(x, y);
			cout << " ";
		}
		void updateBulletPos() {
			Sleep(1);
			for(int i=0; i<MAX_BULLETS; i++) {
				if(bulletFlag[i]) {
					if (bulletY[i] > 0) {
						eraseBullet(bulletX[i],bulletY[i]);
						bulletY[i]-=1;
						drawBullet(bulletX[i],bulletY[i]);
					} else {
						eraseBullet(bulletX[i],bulletY[i]);
						bulletFlag[i]=false;
					}
				}
			}
		}
//		friend void bulletCollision(Enemy , Bullets);
		friend class Enemy;
};

class Enemy {
	private:
		int health;
		static int count;
		int ind;
		int enemyX, enemyY;
		static vector<int> occ;
	public:
		bool enemyFlag;
		Enemy() {
			enemyY = 0;
			health = 3;
			count++;
		}
		int getEnemyY() {
			return enemyY;
		}
		void genEnemy() {
			enemyX = 18 + rand() % 72;
			while(nearbyShips(enemyX)) {
				enemyX = 30 + rand() % 60;
			}
			occ.push_back(enemyX);
		}
		bool nearbyShips(int x) {
			if(abs(occ.back() - x)<5) {
				return true;
			}
			return false;
		}
		void drawEnemy() {
			if( enemyFlag == true ) {
				if(health == 3) {
					gotoxy(enemyX, enemyY);
					cout<<"*****";
					gotoxy(enemyX+2, enemyY+1);
					cout<<"*";
					gotoxy(enemyX+1, enemyY+2);
					cout<<"***";
					gotoxy(enemyX+2, enemyY+3);
					cout<<"*";
				}
				if(health == 2) {
					gotoxy(enemyX, enemyY);
					cout<<"*****";
					gotoxy(enemyX+2, enemyY+1);
					cout<<"*";
					gotoxy(enemyX+1, enemyY+2);
					cout<<"***";
					SetConsoleTextAttribute(console,12);
					gotoxy(enemyX+2, enemyY+3);
					cout<<"*";
				}
				if(health == 1) {
					gotoxy(enemyX, enemyY);
					cout<<"*****";
					SetConsoleTextAttribute(console,12);
					gotoxy(enemyX+2, enemyY+1);
					cout<<"*";
					gotoxy(enemyX+1, enemyY+2);
					cout<<"***";
					gotoxy(enemyX+2, enemyY+3);
					cout<<"*";
				}
				SetConsoleTextAttribute(console,7);
			}
		}
		void eraseEnemy() {
			if( enemyFlag == true ) {
				gotoxy(enemyX, enemyY);
				cout<<"     ";
				gotoxy(enemyX+2, enemyY+1);
				cout<<" ";
				gotoxy(enemyX+1, enemyY+2);
				cout<<"   ";
				gotoxy(enemyX+2, enemyY+3);
				cout<<" ";
			}
		}
		void resetEnemy() {
			score+=100;
			health = 3;
			eraseEnemy();
			enemyY = 0;
			genEnemy();
		}
		void updateEnemy() {
			if(enemyFlag) {
				if(enemyY<SCREEN_HEIGHT-4) {
					eraseEnemy();
					enemyY++;
					drawEnemy();
				} else {
					resetEnemy();
				}
			}
		}
		void collision() {
			if((enemyY==SCREEN_HEIGHT-7)) {
				if((enemyX==shipPos)) {
					resetEnemy();
					gameover = true;
//					cin.get();
				}
			}
			if((enemyY==SCREEN_HEIGHT-6)) {
				if((enemyX-shipPos>=-1&&enemyX-shipPos<=1)) {
					resetEnemy();
					gameover = true;
//					cin.get();
				}
			}
			if((enemyY==SCREEN_HEIGHT-5)) {
				if((enemyX-shipPos>=-1&&enemyX-shipPos<=1)) {
					resetEnemy();
					gameover = true;
//					cin.get();
				}
			}
			if((enemyY==SCREEN_HEIGHT-4)) {
				if((enemyX-shipPos>=-2&&enemyX-shipPos<=2)) {
					resetEnemy();
					gameover = true;
//					cin.get();
				}
			}
		}
		void bulletCollision(Bullets& B, int damage) {
			if(enemyFlag == true) {
				float bulletRadius=0.5;
				float shipRadius=2.25;
				float distance;
				for(int i=0; i<MAX_BULLETS; i++) {
					if(B.bulletFlag[i]) {
						float distance=sqrt(pow(B.bulletX[i]-2-enemyX,2)+pow(B.bulletY[i]-2-enemyY,2));
						if(distance<=bulletRadius+shipRadius) {
							B.eraseBullet(B.bulletX[i],B.bulletY[i]);
							B.bulletFlag[i]=false;
							health=health-damage;
							if(health <= 0) {
								resetEnemy();
							}
						}
					}
				}
			}
		}
};

vector<int> Enemy::occ {0};
int Enemy::count=0;

class menu {
		Ship1 s1;
		Ship2 s2;
		Ship3 s3;
	public:
		void title() {
			system("cls");
			system("Color 08");
			char c = 219, s = ' ';
//			cout<<"¦¦¦¦¦  ¦¦¦¦¦  ¦¦¦¦¦  ¦¦¦¦¦  ¦¦¦¦¦  ¦     ¦ ";
//			cout<<"¦      ¦   ¦  ¦   ¦  ¦      ¦      ¦     ¦ ";
//			cout<<"¦      ¦   ¦  ¦   ¦  ¦      ¦       ¦   ¦  ";
//			cout<<"¦      ¦   ¦  ¦   ¦  ¦      ¦       ¦   ¦  ";
//			cout<<"¦      ¦   ¦  ¦   ¦  ¦      ¦        ¦ ¦   ";
//			cout<<"¦¦¦¦¦  ¦¦¦¦¦  ¦¦¦¦¦  ¦      ¦¦¦¦¦    ¦ ¦   ";
//			cout<<"    ¦  ¦      ¦   ¦  ¦      ¦        ¦ ¦   ";
//			cout<<"    ¦  ¦      ¦   ¦  ¦      ¦       ¦   ¦  ";
//			cout<<"    ¦  ¦      ¦   ¦  ¦      ¦       ¦   ¦  ";
//			cout<<"    ¦  ¦      ¦   ¦  ¦      ¦      ¦     ¦ ";
//			cout<<"¦¦¦¦¦  ¦      ¦   ¦  ¦¦¦¦¦  ¦¦¦¦¦  ¦     ¦ ";
			for(int i=1; i<25; i++) {
				gotoxy(1+rand()%110,i);
				cout<<"*";
				gotoxy(1+rand()%110,i);
				cout<<"*";
				gotoxy(1+rand()%110,i);
				cout<<"*";
				gotoxy(1+rand()%110,i);
				cout<<"*";
			}
			gotoxy(37,2);
			cout<<c<<c<<c<<c<<c<<s<<s<<c<<c<<c<<c<<c<<s<<s<<c<<c<<c<<c<<c<<s<<s<<c<<c<<c<<c<<c<<s<<s<<c<<c<<c<<c<<c<<s<<s<<c<<s<<s<<s<<s<<s<<c<<endl;
			gotoxy(37,3);
			cout<<c<<s<<s<<s<<s<<s<<s<<c<<s<<s<<s<<c<<s<<s<<c<<s<<s<<s<<c<<s<<s<<c<<s<<s<<s<<s<<s<<s<<c<<s<<s<<s<<s<<s<<s<<c<<s<<s<<s<<s<<s<<c<<endl;
			gotoxy(37,4);
			cout<<c<<s<<s<<s<<s<<s<<s<<c<<s<<s<<s<<c<<s<<s<<c<<s<<s<<s<<c<<s<<s<<c<<s<<s<<s<<s<<s<<s<<c<<s<<s<<s<<s<<s<<s<<s<<c<<s<<s<<s<<c<<s<<endl;
			gotoxy(37,5);
			cout<<c<<s<<s<<s<<s<<s<<s<<c<<s<<s<<s<<c<<s<<s<<c<<s<<s<<s<<c<<s<<s<<c<<s<<s<<s<<s<<s<<s<<c<<s<<s<<s<<s<<s<<s<<s<<c<<s<<s<<s<<c<<s<<endl;
			gotoxy(37,6);
			cout<<c<<s<<s<<s<<s<<s<<s<<c<<s<<s<<s<<c<<s<<s<<c<<s<<s<<s<<c<<s<<s<<c<<s<<s<<s<<s<<s<<s<<c<<s<<s<<s<<s<<s<<s<<s<<s<<c<<s<<c<<s<<s<<endl;
			gotoxy(37,7);
			cout<<c<<c<<c<<c<<c<<s<<s<<c<<c<<c<<c<<c<<s<<s<<c<<c<<c<<c<<c<<s<<s<<c<<s<<s<<s<<s<<s<<s<<c<<c<<c<<c<<c<<s<<s<<s<<s<<c<<s<<c<<s<<s<<endl;
			gotoxy(37,8);
			cout<<s<<s<<s<<s<<c<<s<<s<<c<<s<<s<<s<<s<<s<<s<<c<<s<<s<<s<<c<<s<<s<<c<<s<<s<<s<<s<<s<<s<<c<<s<<s<<s<<s<<s<<s<<s<<s<<c<<s<<c<<s<<s<<endl;
			gotoxy(37,9);
			cout<<s<<s<<s<<s<<c<<s<<s<<c<<s<<s<<s<<s<<s<<s<<c<<s<<s<<s<<c<<s<<s<<c<<s<<s<<s<<s<<s<<s<<c<<s<<s<<s<<s<<s<<s<<s<<c<<s<<s<<s<<c<<s<<endl;
			gotoxy(37,10);
			cout<<s<<s<<s<<s<<c<<s<<s<<c<<s<<s<<s<<s<<s<<s<<c<<s<<s<<s<<c<<s<<s<<c<<s<<s<<s<<s<<s<<s<<c<<s<<s<<s<<s<<s<<s<<s<<c<<s<<s<<s<<c<<s<<endl;
			gotoxy(37,11);
			cout<<s<<s<<s<<s<<c<<s<<s<<c<<s<<s<<s<<s<<s<<s<<c<<s<<s<<s<<c<<s<<s<<c<<s<<s<<s<<s<<s<<s<<c<<s<<s<<s<<s<<s<<s<<c<<s<<s<<s<<s<<s<<c<<endl;
			gotoxy(37,12);
			cout<<c<<c<<c<<c<<c<<s<<s<<c<<s<<s<<s<<s<<s<<s<<c<<s<<s<<s<<c<<s<<s<<c<<c<<c<<c<<c<<s<<s<<c<<c<<c<<c<<c<<s<<s<<c<<s<<s<<s<<s<<s<<c<<endl;
			gotoxy(90,25);
			cout<<"Enter Esc to go back"<<endl;
		}
		void start() {
			title();
			gotoxy(90,25);
			cout<<"                    "<<endl;
			gotoxy(42,15);
			system("pause");
			startMenu();
		}
		void startMenu() {
			while(1) {
				title();
				gotoxy(52,15);
				cout<<"1. Start Game"<<endl;
				gotoxy(52,16);
				cout<<"2. Garage"<<endl;
				gotoxy(52,17);
				cout<<"3. Highscores"<<endl;
				gotoxy(52,18);
				cout<<"4. Instructions"<<endl;
				gotoxy(90,25);
				cout<<"                    "<<endl;
				char ch = getche();
				if(ch == '1') {
					startGame();
					break;
				}
				if(ch == '2') {
					garage();
					break;
				}
				if(ch == '3') {
					highscores();
					break;
				}
				if(ch == '4') {
					instructions();
					break;
				}
			}
		}
		void startGame() {
			while(1) {
				title();
				gotoxy(46,15);
				cout<<"Choose your BattleShip";
				gotoxy(52,17);
				cout<<"1. TF-420";
				gotoxy(52,18);
				cout<<"2. WX-72000";
				gotoxy(52,19);
				cout<<"3. G-69z";
				gotoxy(90,24);
				char ch = getche();
				if(ch == 27) {
					startMenu();
				}
				if(ch == '1') {
					game(1);
					game(1);
				}
				if(ch == '2') {
					game(2);
					game(2);
				}
				if(ch == '3') {
					game(3);
					game(3);
				}
			}
			startMenu();
		}
		void garage() {
			while(1) {
				title();
				gotoxy(46,15);
				cout<<"Choose your BattleShip";
				gotoxy(52,17);
				cout<<"1. TF-420";
				gotoxy(52,18);
				cout<<"2. WX-72000";
				gotoxy(52,19);
				cout<<"3. G-69z";
				gotoxy(90,24);
				char ch = getche();
				if(ch == 27) {
					startMenu();
				}
				if(ch == '1') {
					ship<Ship1>(s1);
				}
				if(ch == '2') {
					ship<Ship2>(s2);
				}
				if(ch == '3') {
					ship<Ship3>(s3);
				}
			}
			startMenu();
		}
		template<typename T>
		void ship(T s) {
			while(1) {
				title();
				gotoxy(44,15);
				cout<<"Choose what you want to upgrade: ";
				gotoxy(52,17);
				cout<<"1. Speed    "<<s.getSpeed()<<"    5000$";
				gotoxy(52,18);
				cout<<"2. Handling "<<s.getHandling()<<"    5000$";
				gotoxy(52,19);
				cout<<"3. Damage   "<<s.getDamage()<<"    5000$";
				gotoxy(52,20);
				cout<<"4. Color    "<<s.getColor()<<"    1000$";
				gotoxy(90,24);
				cout<<"Your Money: "<<money;
				gotoxy(90,24);
				char ch = getche();
				if(ch == 27) {
					garage();
				}
				if(ch == '1') {
					title();
					try {
						if(s.getSpeed()<3&&money>=5000) {
							s.setSpeed(s.getSpeed()+1);
							money-=5000;
							gotoxy(46,15);
							cout<<"Speed has been upgraded to "<<s.getSpeed();
							gotoxy(90,24);
							getche();
							system("cls");
						} else {
							MyException z;
							throw z;
						}
					} catch (MyException& z) {
						gotoxy(46,15);
						cout<<z.what();
						gotoxy(90,24);
						getche();
						system("cls");
					}
				}
				if(ch == '2') {
					title();
					try {
						if(s.getHandling()<3&&money>=5000) {
							s.setHandling(s.getHandling()+1);
							money-=5000;
							gotoxy(46,15);
							cout<<"Handling has been upgraded to "<<s.getHandling();
							gotoxy(90,24);
							getche();
							system("cls");
						} else {
							MyException z;
							throw z;
						}
					} catch (MyException& z) {
						gotoxy(46,15);
						cout<<z.what();
						gotoxy(90,24);
						getche();
						system("cls");
					}
				}
				if(ch == '3') {
					title();
					try {
						if(s.getDamage()<3&&money>=5000) {
							s.setDamage(s.getDamage()+1);
							money-=5000;
							gotoxy(46,15);
							cout<<"Handling has been upgraded to "<<s.getDamage();
							gotoxy(90,24);
							getche();
							system("cls");
						} else {
							MyException z;
							throw z;
						}
					} catch (MyException& z) {
						gotoxy(46,15);
						cout<<z.what();
						gotoxy(90,24);
						getche();
						system("cls");
					}
				}
				if(ch == '4') {
					while(1) {
						title();
						if(money>=1000) {
							gotoxy(48,15);
							cout<<"Choose the new color: ";
							SetConsoleTextAttribute(console,7);
							gotoxy(52,17);
							cout<<"1. White";
							SetConsoleTextAttribute(console,10);
							gotoxy(52,18);
							cout<<"2. Green";
							SetConsoleTextAttribute(console,11);
							gotoxy(52,19);
							cout<<"3. Cyan";
							SetConsoleTextAttribute(console,12);
							gotoxy(52,20);
							cout<<"4. Red";
							SetConsoleTextAttribute(console,13);
							gotoxy(52,21);
							cout<<"5. Purple";
							SetConsoleTextAttribute(console,6);
							gotoxy(52,22);
							cout<<"6. Yellow";
							char ch1 = getche();
							if(ch1 == 27) {
								break;
							}
							if(ch1 == '1') {
								title();
								gotoxy(43,15);
								cout<<"Color has been changed to white";
								s.setColor(1);
								getche();
							}
							if(ch1 == '2') {
								title();
								gotoxy(43,15);
								cout<<"Color has been changed to green";
								s.setColor(2);
								getche();
							}
							if(ch1 == '3') {
								title();
								gotoxy(43,15);
								cout<<"Color has been changed to cyan";
								s.setColor(3);
								getche();
							}
							if(ch1 == '4') {
								title();
								gotoxy(43,15);
								cout<<"Color has been changed to red";
								s.setColor(4);
								getche();
							}
							if(ch1 == '5') {
								title();
								gotoxy(43,15);
								cout<<"Color has been changed to purple";
								s.setColor(5);
								getche();
							}
							if(ch1 == '6') {
								title();
								gotoxy(43,15);
								cout<<"Color has been changed to yellow";
								s.setColor(6);
								getche();
							}
							money -= 1000;
						} else {
							gotoxy(46,15);
							cout<<"Insufficient amount of money";
							gotoxy(90,24);
							getche();
							break;
							system("cls");
						}
					}
				}

			}
		}
		void highscores() {
			title();
			set<long long int>::iterator itr;
			itr = scores.end();
			gotoxy(51,15);
			cout<<"Highest Scores";
			int i=1;
			while(itr!=scores.begin()) {
				itr--;
				gotoxy(52,15+i);
				cout<<i<<". "<<*itr;
				i++;
				if(i>6) {
					break;
				}
			}
			char ch = getch();
			if(ch == 27) {
				startMenu();
			} else {
				highscores();
			}
		}
		void instructions() {
			title();
			gotoxy(50,15);
			cout<<"Move Left: A or <-";
			gotoxy(50,16);
			cout<<"Move right: D or ->";
			gotoxy(47,17);
			cout<<"Fire Bullet: J or spacebar";
			gotoxy(25,18);
			cout<<"After succesfully destroying or dogding one enemy you get 100 points.";
			gotoxy(28,19);
			cout<<"Hundred points are equal to one dollar the money can be used to";
			gotoxy(25,20);
			cout<<"upgrade the three ships. Health of the enemy ships are shown by their";
			gotoxy(29,21);
			cout<<"changing color. Game will be over when u crash into an enemy.";
			gotoxy(47,22);
			cout<<"Press P to pause the game.";
			gotoxy(90,24);
			char ch = getche();
			if(ch == 27) {
				startMenu();
			} else {
				instructions();
			}
		}
		void game(int number) {
			system("cls");
			gameover = false;
			drawBorder();
			Ships *s;
			if(number == 1)
				s = new Ship1;
			if(number == 2)
				s = new Ship2;
			if(number == 3)
				s = new Ship3;
			Enemy *e;
			e = new Enemy[10];
			e[0].enemyFlag = true;
			for(int i=0; i<10; i++) {
				if(i != 0)
					e[i].enemyFlag = false;
				e[i].genEnemy();
			}
			Bullets b;
			int no_of_enemy = 3 ;
			while(1) {
				if(gameover == true) {
					gameOver();
					scores.insert(score);
					money = score/100;
					break;
				}
				if(score>1000) {
					no_of_enemy = 4;
				}
				if(score>5000) {
					no_of_enemy = 5;
				}
				if(score>10000) {
					no_of_enemy = 6;
				}
				if(score>25000) {
					no_of_enemy = 7;
				}
				if(score>50000) {
					no_of_enemy = 8;
				}
				if(score>75000) {
					no_of_enemy = 9;
				}
				if(score>100000) {
					no_of_enemy = 10;
				}
				if( GetAsyncKeyState(VK_ESCAPE)) {
					money += score/100;
					scores.insert(score);
					break;
				}
				if( GetAsyncKeyState('A')||GetAsyncKeyState(VK_LEFT) ) {
					if( shipPos > 18 )
						shipPos -= s->getHandling() ;
				}
				if( GetAsyncKeyState('D')||GetAsyncKeyState(VK_RIGHT)) {
					if( shipPos < 90 )
						shipPos += s->getHandling() ;
				}
				if(kbhit()) {
					char ch = getch();
					if(ch == 'j'||ch == 'J'||ch == ' ')
						b.bullet();
					if( ch == 'p'||ch == 'P') {
						getch();
						for(int i=0; i<27; i++) {
							for(int j=0; j<110; j++) {
								gotoxy(j,i);
								cout<<' ';
							}
						}
						system("Color 08");
						drawBorder();
					}
				}

				s->drawShip();
				for(int j=0; j<no_of_enemy; j++) {
					e[j].bulletCollision(b, s->getDamage());
					e[j].updateEnemy();
					e[j].collision();
				}
				b.updateBulletPos();
				DWORD acc = 0;
				if(s->getSpeed()==1) {
					if(score % 200 == 0 && score != 0 && score > 4000) {
						acc+=1;
					}
					Sleep(45-acc);
				}
				if(s->getSpeed()==2) {
					if(score % 200 == 0 && score != 0 && score > 4000) {
						acc+=1;
					}
					Sleep(40-acc);
				}
				if(s->getSpeed()==3) {
					if(score % 200 == 0 && score != 0 && score > 4000) {
						acc+=1;
					}
					Sleep(35-acc);
				}
				s->eraseShip();

				for(int j=0; j<no_of_enemy; j++) {
					if(e[j].getEnemyY() == 5+rand()%5)
						if( e[j+1].enemyFlag == false )
							e[j+1].enemyFlag = true;
				}
				gotoxy(WIN_WIDTH-9,12);
				cout<<"SCORE";
				gotoxy(WIN_WIDTH-9,13);
				cout<<score;
			}
			score = 0;
			gameover = false;
		}
		void gameOver() {
			system("cls");
			char c = 219, s = ' ';
			system("Color 08");
			//			cout<<"¦¦¦¦¦  ¦¦¦¦¦  ¦¦ ¦¦  ¦¦¦¦¦  ¦¦¦¦¦  ¦    ¦  ¦¦¦¦¦  ¦¦¦¦¦  ¦";
			//			cout<<"¦      ¦   ¦  ¦¦ ¦¦  ¦      ¦   ¦  ¦    ¦  ¦      ¦   ¦  ¦";
			//			cout<<"¦      ¦   ¦  ¦¦ ¦¦  ¦      ¦   ¦  ¦    ¦  ¦      ¦   ¦  ¦";
			//			cout<<"¦      ¦   ¦  ¦¦ ¦¦  ¦      ¦   ¦  ¦    ¦  ¦      ¦   ¦  ¦";
			//			cout<<"¦      ¦   ¦  ¦¦ ¦¦  ¦      ¦   ¦  ¦    ¦  ¦      ¦   ¦  ¦";
			//			cout<<"¦ ¦¦¦  ¦¦¦¦¦  ¦ ¦ ¦  ¦¦¦¦¦  ¦   ¦  ¦    ¦  ¦¦¦¦¦  ¦¦¦¦¦  ¦";
			//			cout<<"¦ ¦ ¦  ¦   ¦  ¦ ¦ ¦  ¦      ¦   ¦   ¦  ¦   ¦      ¦ ¦    ¦";
			//			cout<<"¦   ¦  ¦   ¦  ¦   ¦  ¦      ¦   ¦   ¦  ¦   ¦      ¦  ¦   ¦";
			//			cout<<"¦   ¦  ¦   ¦  ¦   ¦  ¦      ¦   ¦   ¦  ¦   ¦      ¦  ¦   ¦";
			//			cout<<"¦   ¦  ¦   ¦  ¦   ¦  ¦      ¦   ¦    ¦¦    ¦      ¦   ¦   ";
			//			cout<<"¦¦¦¦¦  ¦   ¦  ¦   ¦  ¦¦¦¦¦  ¦¦¦¦¦    ¦¦    ¦¦¦¦¦  ¦   ¦  ¦";
			for(int i=1; i<25; i++) {
				gotoxy(1+rand()%110,i);
				cout<<"*";
				gotoxy(1+rand()%110,i);
				cout<<"*";
				gotoxy(1+rand()%110,i);
				cout<<"*";
				gotoxy(1+rand()%110,i);
				cout<<"*";
			}
			gotoxy(29,2);
			cout<<c<<c<<c<<c<<c<<s<<s<<c<<c<<c<<c<<c<<s<<s<<c<<c<<s<<c<<c<<s<<s<<c<<c<<c<<c<<c<<s<<s<<c<<c<<c<<c<<c<<s<<s<<c<<s<<s<<s<<s<<c<<s<<s<<c<<c<<c<<c<<c<<s<<s<<c<<c<<c<<c<<c<<s<<s<<c<<endl;
			gotoxy(29,3);
			cout<<c<<s<<s<<s<<s<<s<<s<<c<<s<<s<<s<<c<<s<<s<<c<<c<<s<<c<<c<<s<<s<<c<<s<<s<<s<<s<<s<<s<<c<<s<<s<<s<<c<<s<<s<<c<<s<<s<<s<<s<<c<<s<<s<<c<<s<<s<<s<<s<<s<<s<<c<<s<<s<<s<<c<<s<<s<<c<<endl;
			gotoxy(29,4);
			cout<<c<<s<<s<<s<<s<<s<<s<<c<<s<<s<<s<<c<<s<<s<<c<<c<<s<<c<<c<<s<<s<<c<<s<<s<<s<<s<<s<<s<<c<<s<<s<<s<<c<<s<<s<<c<<s<<s<<s<<s<<c<<s<<s<<c<<s<<s<<s<<s<<s<<s<<c<<s<<s<<s<<c<<s<<s<<c<<endl;
			gotoxy(29,5);
			cout<<c<<s<<s<<s<<s<<s<<s<<c<<s<<s<<s<<c<<s<<s<<c<<c<<s<<c<<c<<s<<s<<c<<s<<s<<s<<s<<s<<s<<c<<s<<s<<s<<c<<s<<s<<c<<s<<s<<s<<s<<c<<s<<s<<c<<s<<s<<s<<s<<s<<s<<c<<s<<s<<s<<c<<s<<s<<c<<endl;
			gotoxy(29,6);
			cout<<c<<s<<s<<s<<s<<s<<s<<c<<s<<s<<s<<c<<s<<s<<c<<c<<s<<c<<c<<s<<s<<c<<s<<s<<s<<s<<s<<s<<c<<s<<s<<s<<c<<s<<s<<c<<s<<s<<s<<s<<c<<s<<s<<c<<s<<s<<s<<s<<s<<s<<c<<s<<s<<s<<c<<s<<s<<c<<endl;
			gotoxy(29,7);
			cout<<c<<s<<c<<c<<c<<s<<s<<c<<c<<c<<c<<c<<s<<s<<c<<s<<c<<s<<c<<s<<s<<c<<c<<c<<c<<c<<s<<s<<c<<s<<s<<s<<c<<s<<s<<c<<s<<s<<s<<s<<c<<s<<s<<c<<c<<c<<c<<c<<s<<s<<c<<c<<c<<c<<c<<s<<s<<c<<endl;
			gotoxy(29,8);
			cout<<c<<s<<c<<s<<c<<s<<s<<c<<s<<s<<s<<c<<s<<s<<c<<s<<c<<s<<c<<s<<s<<c<<s<<s<<s<<s<<s<<s<<c<<s<<s<<s<<c<<s<<s<<s<<c<<s<<s<<c<<s<<s<<s<<c<<s<<s<<s<<s<<s<<s<<c<<s<<c<<s<<s<<s<<s<<c<<endl;
			gotoxy(29,9);
			cout<<c<<s<<s<<s<<c<<s<<s<<c<<s<<s<<s<<c<<s<<s<<c<<s<<s<<s<<c<<s<<s<<c<<s<<s<<s<<s<<s<<s<<c<<s<<s<<s<<c<<s<<s<<s<<c<<s<<s<<c<<s<<s<<s<<c<<s<<s<<s<<s<<s<<s<<c<<s<<s<<c<<s<<s<<s<<c<<endl;
			gotoxy(29,10);
			cout<<c<<s<<s<<s<<c<<s<<s<<c<<s<<s<<s<<c<<s<<s<<c<<s<<s<<s<<c<<s<<s<<c<<s<<s<<s<<s<<s<<s<<c<<s<<s<<s<<c<<s<<s<<s<<c<<s<<s<<c<<s<<s<<s<<c<<s<<s<<s<<s<<s<<s<<c<<s<<s<<c<<s<<s<<s<<c<<endl;
			gotoxy(29,11);
			cout<<c<<s<<s<<s<<c<<s<<s<<c<<s<<s<<s<<c<<s<<s<<c<<s<<s<<s<<c<<s<<s<<c<<s<<s<<s<<s<<s<<s<<c<<s<<s<<s<<c<<s<<s<<s<<c<<s<<s<<c<<s<<s<<s<<c<<s<<s<<s<<s<<s<<s<<c<<s<<s<<s<<c<<s<<s<<s<<endl;
			gotoxy(29,12);
			cout<<c<<c<<c<<c<<c<<s<<s<<c<<s<<s<<s<<c<<s<<s<<c<<s<<s<<s<<c<<s<<s<<c<<c<<c<<c<<c<<s<<s<<c<<c<<c<<c<<c<<s<<s<<s<<s<<c<<c<<s<<s<<s<<s<<c<<c<<c<<c<<c<<s<<s<<c<<s<<s<<s<<c<<s<<s<<c<<endl;
			Sleep(1000);
			gotoxy(42,15);
			system("pause");
		}
		void drawBorder() {
			char c = 219;
			for(int i=0; i<SCREEN_HEIGHT; i++) {
				for(int j=0; j<18; j++) {
					gotoxy(j,i);
					cout<<c;
					if(i>10&&i<16&&j>2&&j<15) {
						gotoxy(WIN_WIDTH-j+2,i);
						cout<<' ';
					} else {
						gotoxy(WIN_WIDTH-j+2,i);
						cout<<c;
					}
				}
			}
			//    for(int i=0; i<SCREEN_HEIGHT; i++){
			//        gotoxy(SCREEN_WIDTH,i); cout<<c;
			//    }
		}
};
int main() {
	hideCursor();
	menu  m;
	m.start();
}