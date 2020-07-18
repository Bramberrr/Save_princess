#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define DECISION "Are you ready？\n1    Begin\n2    Background\n3    Check\n4    Save data (please store the game for the first time and then play it)" //待添加
#define DECISION2 "Your choice?\n1.left  2.right  3.upstairs  4.downstairs"
#define DECISION3 "Your choice?\n1      check\n2      go\n3      use\n4      save/read\nelse      exit\n"
void initgame(void);
void map(void);
struct Room print(struct Room rm);
void roomfunction(int);
void dabaojianroom(void); //大保健室
void Dungeonroom(int i);
void princessroom(void);
void nothingroom(void);
void princessroom(void);
void poisonroom(void);
void goldroom(void);
void armshop(void); //武器店
void lobby(void);
struct Room enter(struct Room *rm); //大厅
void fighting(void);				//攻击
void state(void);
void bossstate(void);
void lvup(void); //升级
void Dun(void);  //史莱姆
void Dun1(void);
void Dun2(void);  //完毕
void Dunge(void); //哥布林
void Dunge1(void);
void Dunge2(void);   //end
void Dungeon(void);  //怪兽
void Dungeon1(void); //
void Dungeon2(void);
void lobby(void);
void tired(void);
void check(void); //查看个人信息
void cd(void);	//存档
struct Room go(struct Room *rm);
void back(void);
void use(void);
void help(void); //帮助

int HP = 300, MP = 20, sp, ex = 0, p = 5, q = 20, lv = 1, i = 1, eak = 0, edf = 0, gold = 2000, lobchoose = 0, tire = 0, princess = 0, body = 0, heart = 0, sh, tybossHP, x, HPboss, fb;
struct Room
{
	int order;
	int type;
	int floor;
	int number;
	int flip;
	struct Room *left;
	struct Room *right;
	struct Room *up;
	struct Room *down;
} room[10], *now;
int main(void) //主程序开始
{
	initgame();
	while (1)
	{

		while (x == 0)
		{
			printf("%s\n", DECISION);
			scanf("%d", &x);
			while (x == 1)
			{
				lobby();
				lobchoose = 0;
				x = 0;
			}
			while (x == 2)
			{
				back();
				x = 0;
			}
			while (x == 3)
			{
				check();
				x = 0;
			}
			while (x == 4)
			{
				cd();
				x = 0;
			}
		}
	}
	return 0;
}
void back(void)
{
	printf("One day, you received a request from the king to rescue the princess trapped in the old castle.\nAfter all your hard work,you finally entered the castle, only to discover that the real adventure\n has just begun....");
}
void initgame(void)
{
	int i, j, k;
	int typ[10];
	int f[10] = {1, 1, 1, 1, 2, 2, 2, 3, 3, 4};
	int o[10] = {1, 2, 3, 4, 1, 2, 3, 1, 2, 1};
	for (i = 0; i < 10; i++)
	{
		room[i].floor = f[i];
		room[i].number = o[i];
		room[i].flip = 0;
		room[i].order = i;
	}
	room[0].left = NULL;
	room[0].right = &room[1];
	room[0].up = &room[4];
	room[0].down = NULL;

	room[1].left = &room[0];
	room[1].right = &room[2];
	room[1].up = &room[5];
	room[1].down = NULL;

	room[2].left = &room[1];
	room[2].right = &room[3];
	room[2].up = &room[6];
	room[2].down = NULL;

	room[3].left = &room[2];
	room[3].right = NULL;
	room[3].up = NULL;
	room[3].down = NULL;

	room[4].left = NULL;
	room[4].right = &room[5];
	room[4].up = &room[7];
	room[4].down = &room[0];

	room[5].left = &room[4];
	room[5].right = &room[6];
	room[5].up = &room[8];
	room[5].down = &room[1];

	room[6].left = &room[5];
	room[6].right = NULL;
	room[6].up = NULL;
	room[6].down = &room[2];

	room[7].left = NULL;
	room[7].right = &room[8];
	room[7].up = &room[9];
	room[7].down = &room[4];

	room[8].left = &room[7];
	room[8].right = NULL;
	room[8].up = NULL;
	room[8].down = &room[5];

	room[9].left = NULL;
	room[9].right = NULL;
	room[9].up = NULL;
	room[9].down = &room[7];

	srand((unsigned)time(0));

	for (i = 0; i < 10; i++)
	{
		typ[i] = rand() % 10 + 1;

		do
		{
			k = 0;
			for (j = 0; j < i; j++)
			{
				if (typ[i] == typ[j])
				{
					typ[i] = rand() % 10 + 1;
					k = 1;
				}
			}
		} while (k != 0);

		//printf("%d\n",typ[i]);
		room[i].type = typ[i];
	}
}
void map()
{
	printf("You are in room of Floor%d NO.%d\n", now->floor, now->number);
	printf("_____________________MAP_____________________\n");
	printf(" ");
	print(room[9]);
	printf("\n");
	printf(" ");
	print(room[7]);
	printf(" ");
	print(room[8]);
	printf("\n");
	printf(" ");
	print(room[4]);
	printf(" ");
	print(room[5]);
	printf("  ");
	print(room[6]);
	printf("\n");
	printf(" ");
	print(room[0]);
	printf(" ");
	print(room[1]);
	printf("  ");
	print(room[2]);
	printf("  ");
	print(room[3]);
	printf("\n");
	printf("\n");
}
struct Room print(struct Room rm)
{
	if (rm.flip == 1)
	{
		switch (rm.type)
		{
		case 1:
			printf("dabaojianroom");
			break;
		case 2:
			printf("Dungeonroom");
			break;
		case 3:
			printf("princessroom");
			break;
		case 4:
			printf("Dungeonroom");
			break;
		case 5:
			printf("nothingroom");
			break;
		case 6:
			printf("Dungeonroom");
			break;
		case 7:
			printf("poisonroom");
			break;
		case 8:
			printf("Dungeonroom");
			break;
		case 9:
			printf("armshop");
			break;
		case 10:
			printf("goldroom");
			break;
		}
	}
	else
	{
		printf("XXXXroom");
	}
}
void tired(void)
{
	tire += 10;
	if (tire > 1000)
	{
		if (princess == 1)
		{
			printf("You are exhausted if you have not brought back the princess, and the princess has returned to me.\n");
			getchar();
			exit(0);
		}
		else
		{
			printf("You are exhausted if you have not found the princess, and the princess has returned to me.\n");
			getchar();
			exit(0);
		}
	}
}
struct Room go(struct Room *rm)
{
	int dir;
	do
	{
		printf("%s\n", DECISION2);
		map();
		scanf("%d", &dir);
		switch (dir)
		{
		case 1:
			if (rm->left != NULL)
				enter(rm->left);
			else
			{
				printf("No way, please choose again.");
				dir = 0;
			}
			break;
		case 2:
			if (rm->right != NULL)
				enter(rm->right);
			else
			{
				printf("No way, please choose again.");
				dir = 0;
			}
			break;
		case 3:
			if (rm->up != NULL)
				enter(rm->up);
			else
			{
				printf("No way, please choose again.");
				dir = 0;
			}
			break;
		case 4:
			if (rm->down != NULL)
				enter(rm->down);
			else
			{
				printf("No way, please choose again.");
				dir = 0;
			}

			break;
		default:
			printf("Error! Please choose again.");
			dir = 0;
			break;
		}
	} while (!dir);
}
struct Room enter(struct Room *rm)
{
	char sel = '\0';
	rm->flip = 1;
	now = rm;
	printf("Welcome to the room of Floor%d NO.%d\n", rm->floor, rm->number);
	roomfunction(rm->type);
	if (rm->floor == 1)
	{
		do
		{
			printf("Do you want to get back to the lobby?(Y/N)\n");
			getchar();
			sel = getchar();
			if (sel == 'Y' || sel == 'y')

				lobby();

		} while (sel != 'Y' && sel != 'y' && sel != 'N' && sel != 'n');
	}

	sel = '\0';

	while (sel != 'Y' && sel != 'y' && sel != 'N' && sel != 'n')
	{
		printf("Do you want to get help?(Y/N)\n");
		getchar();
		sel = getchar();
		if (sel == 'Y' || sel == 'y')
			help();
		if (sel == 'N' || sel == 'n')
			go(now);
	}
}

void roomfunction(int c)
{
	switch (c)
	{
	case 1:
		dabaojianroom();
		break;
	case 2:
		Dungeonroom(2);
		break;
	case 3:
		princessroom();
		break;
	case 4:
		Dungeonroom(1);
		break;
	case 5:
		nothingroom();
		break;
	case 6:
		Dungeonroom(2);
		break;
	case 7:
		poisonroom();
		break;
	case 8:
		Dungeonroom(3);
		break;
	case 9:
		armshop();
		break;
	case 10:
		goldroom();
		break;
	}
}

void nothingroom()
{
	printf("There is nothing in this room.\n");
}
void princessroom()
{
	printf("Congratulations! You found the princess, please bring her back to the LOBBY now.\n");
	princess = 1;
}
void poisonroom()
{
	printf("You are poisoned and your tire has doubled.\n");
	tire *= 2;
}
void goldroom()
{
	printf("You have found 1000 gold.\n");
	gold += 1000;
}
void cd(void) //存档模块
{
	int du = 0;
	int a[] = {lv, HP, MP, ex, gold, tire, princess};
	int or ;
	while (du == 0)
	{
		printf("Do you want to read or store?\n1  Read\n2  Store\n3  Exit\n");
		scanf("%d", &du);
		while (du == 1)
		{
			FILE *fpRead = fopen("data.txt", "r");
			int b[30];

			for (int i = 0; i < 7; i++)
			{
				fscanf(fpRead, "%d ", &b[i]);
				a[i] = b[i];
			}

			for (i = 0; i < 10; i++)
			{
				fscanf(fpRead, "%d ", &b[i + 7]);
				room[i].type = b[i + 7];
			}
			for (i = 0; i < 10; i++)
			{
				fscanf(fpRead, "%d ", &b[i + 17]);
				room[i].flip = b[i + 17];
			}
			fscanf(fpRead, "%d ", &b[27]);
			or = b[27];
			lv = a[0], HP = a[1], MP = a[2], ex = a[3], gold = a[4], tire = a[5], princess = a[6];
			enter(&room[or]);
			du = -1;
		}
		while (du == 2)
		{
			FILE *fpWrite = fopen("data.txt", "w");
			for (int i = 0; i < 7; i++)
			{
				fprintf(fpWrite, "%d ", a[i]);
			}
			for (i = 0; i < 10; i++)
			{
				fprintf(fpWrite, "%d ", room[i].type);
			}
			for (i = 0; i < 10; i++)
			{
				fprintf(fpWrite, "%d ", room[i].flip);
			}
			fprintf(fpWrite, "%d ", now->order);
			fclose(fpWrite);
			du = -1;
		}
		while (du == 3)
		{
			du = -1;
			return;
		}
		if (du != 1 && du != 2 && du != 3)
			du = 0;
	}

	return;
}
void check(void)
{
	printf("______________________Personal information_______________________\n");
	printf("TIRE：%d \n", tire); //暂无
	printf("LV:%d    HP:%d     MP:%d     Exp:%d     Gold:%d    \n", lv, HP, MP, ex, gold);
	printf("Ablity: 1.Slam :%d   2.Bloodsucking: Depending on the boss    3.Starburst:%d  \n", p, q);
	printf("___________________________Personal Bag__________________________\n");
	printf("肾宝:%d    经验果:%d    \n", body, heart);
	printf("_________________________________________________________________\n");
}
void lvup(void)
{
	while (ex > 100 * lv)

	{
		tire = 0;
		printf("Upgraded, your level is %d, tire is cleared\n", lv + 1);

		p = p + 3;

		q = q + 10;

		ex = ex - 100 * lv;

		lv = lv + 1;

		HP = 200 + 20 * lv;

		MP = 20 + 2 * lv;
	}
}
void help(void)
{
	int c = 0;
	while (c == 0)
	{
		printf("_____________________HELP_____________________\n");
		printf("%s\n", DECISION3);
		scanf("%d", &c);
		while (c == 1)
		{
			check();
			c = 0;
		}
		while (c == 2)
		{
			go(now);
			c = 0;
		}
		while (c == 3)
		{
			use();
			c = 0;
		}
		while (c == 4)
		{
			cd();
			c = 0;
		}
		if (c != 1 && c != 2 && c != 3 && c != 4)
			c = -1;
	}
}

void lobby(void) //大厅
{
	lobchoose = 0;
	if (princess == 1)
	{
		char s = '\0';
		printf("You have successfully rescued the princess!\n\nOnce again?\n");
		while (s != 'Y' && s != 'y' && s != 'N' && s != 'n')
		{
			printf("Y(yes)/N(exit)\n");
			getchar();
			s = getchar();
		}
		if (s == 'Y' || s == 'y')
		{
			princess = 0;
			initgame();
		}
		else
		{
			exit(0);
		}
	}
	else
	{
		while (lobchoose == 0)
		{
			printf("Welcome back to the first floor of the lobby, warrior!\nPlease choose a number of room: \n1    \n2    \n3    \n4    \n5    Exit\n");
			scanf("%d", &lobchoose);
			while (lobchoose >= 5)
			{
				printf("You have exited.\n");
				int x = 0;
				while (x == 0)
				{
					printf("%s\n", DECISION);
					scanf("%d", &x);
					while (x == 1)
					{
						lobby();
						lobchoose = 0;
						x = 0;
					}
					while (x == 2)
					{
						back();
						x = 0;
					}
					while (x == 3)
					{
						check();
						x = 0;
					}
					while (x == 4)
					{
						cd();
						x = 0;
					}
				}

				lobchoose = -1;
			}

			while (lobchoose == 1)
			{
				enter(&room[0]);
			}
			while (lobchoose == 2)
			{
				enter(&room[1]);
			}
			while (lobchoose == 3)
			{
				enter(&room[2]);
			}
			while (lobchoose == 4)
			{
				enter(&room[3]);
			}
		}
	}
	return;
} //大厅模块
void armshop(void) //武器店
{
	int cho = 1;
	while (cho == 1)
	{
		int wq = 0, dj = 1, cj = 1;
		printf("Hello Warrior, welcome to the weapons store\nWhat do you need?\n1    Short sword (injury + 10) 500golds\n2    Long sword (injury + 30) 2000golds\n3    Exit weapons shop\n");
		printf("Your gold: %d\n", gold);
		scanf("%d", &wq);
		if (wq > 2)
		{
			while (wq > 3)
			{
				printf("Not on the shelves, so stay tuned.\n");
				wq = 0;
			}
			while (wq == 3)
			{
				printf("Come back next time.\n");
				cho = 0;
				wq = 0;
			}
		}
		else
		{
			while (wq == 1)
			{
				if (gold >= 500)
				{
					if (dj = 1)
					{
						printf("You bought a short sword, the injury is increased by 10, and the repeated purchase is invalid.\n");
						eak = 10;
						p = p + eak; //声明全局变量，装备加成攻击力
						dj = 0;
						wq = 0;
						gold -= 500;
					}
					else
					{
						printf("You have bought it.\n");
					}
				}
				else
				{
					printf("No enough money.\n");
				}
				wq = 0;
			}
			while (wq == 2)
			{
				if (gold >= 2000)
				{
					if (cj = 1)
					{
						printf("You bought a long sword, the injury is increased by 30, and the repeated purchase is invalid.\n");
						eak = 30;
						p = p + eak; //声明全局变量，装备加成攻击力
						cj = 0;
						gold -= 2000;
					}
					else
					{
						printf("You have bought it.\n");
					}
				}
				else
				{
					printf("No enough money.\n");
				}
				wq = 0;
			}
		}
	}
}
void use(void)
{
	int daoju = 0;
	while (daoju == 0)
	{
		printf("What do you want to use？\n1  肾宝*%d\n2  经验果*%d\n3  Exit\n", body, heart);
		scanf("%d", &daoju);
		while (daoju > 3)
		{
			printf("Choose again!");
			daoju=0;
		}
		while (daoju == 3)
			daoju = -1;
		while (daoju == 1)
		{
			if (body > 0)
			{
				if (tire > 200)
					tire -= 200;
				else
					tire = 0;
				body--;
				printf("You have a great body care, the tire is reduced by 200, and the tire is now %d.\n", tire);
			}
			else
			{
				printf("No enough 肾宝.");
			}
			daoju = 0;
		}
		while (daoju == 2)
		{
			if (heart > 0)
			{
				ex += 100;
				heart--;
				printf("You have a great heart care, the experience has increased by 100, and now the experience is %d\n", ex);
			}
			else
			{
				printf("No enough 经验果.");
			}
			daoju = 0;
		}
	}
	help();
}
void dabaojianroom(void) //大保健室
{
	int choose = 0;
	while (choose == 0)
	{
		int fj = 0;
		printf("Hello Warrior, welcome to the care room\nWhat do you need?\n1    肾宝(疲劳度减200)  50 golds\n2  经验果(经验增加100)  100 golds\n3  Exit\n");
		printf("Your gold: %d\n", gold);
		scanf("%d", &fj);
		if (fj > 2)
		{
			while (fj > 3)
			{
				printf("No such things.\n");
				fj = 0;
			}
			while (fj == 3)
			{
				printf("Come back next time.\n");
				choose = -1;
				fj = 0;
			}
		}
		else
		{
			while (fj == 1)
			{
				if (gold >= 50)
				{
					printf("You have bought a 肾宝.\n");
					body++;
					gold -= 50;
				}
				else
				{
					printf("No enough money.\n");
				}
				fj = 0;
			}
			while (fj == 2)
			{
				if (gold >= 100)
				{
					heart++;
					printf("You have bought a 经验果.\n");
					gold -= 100;
				}
				else
				{
					printf("No enough money.\n");
				}
				fj = 0;
			}
		}
	}
}

void Dun(void)
{
	Dun1();
	fighting();
	Dun2();
}
void Dunge(void)
{
	Dunge1();
	fighting();
	Dunge2();
}
void Dungeon(void)
{
	Dungeon1();
	fighting();
	Dungeon2();
}
void state()
{
	printf("-----------------------------------Your state-----------------------------\n");
	printf("MP:%d\n", MP);
	printf("HP:%d\n", HP);
	printf("Tire:%d\n", tire);
	printf("LV:%d\n", lv);
	printf("EXP:%d\n", ex);
	printf("SKILL：\n1.Slam:%d\n2.Bloodsucking:depending on the boss\n3.Starburst:%d\n", (int)(p - 0.01 * tire), (int)(q - 0.01 * tire));
	printf("---------------------------------------------------------------------------\n");
}
void bossstate()
{
	printf("----------------------------------Boss's state-----------------------------\n");
	printf("HP:%d\n\n", tybossHP);
	printf("---------------------------------------------------------------------------\n");
}
void fighting(void) //战斗模块
{
	while (HP > 0 && tybossHP > 0)
	{

		i = 1;
		state();
		bossstate();
		printf("\nChoose your skill:\n1.Slam     (%d injury，MP+1)\n2.Bloodsucking     (8 percent injury of boss's HP，MP-3)\n3.Starburst     (%d injury，MP-5)\n", (int)(p - 0.01 * tire), (int)(q - 0.01 * tire)); //待添加
		scanf("%d", &sp);
		tired();
		while (4 < sp)
		{
			printf("Error, please choose again.\n");
			sp = -1;
		}
		while (sp == 1)
		{

			tybossHP = tybossHP - p + 0.01 * tire;
			MP++;
			printf("You use skill slam to deal %d injury to boss, restore 1 MP\n\n", (int)(p - 0.01 * tire));
			sp = 0;
		}

		while (sp == 2)
		{

			while (MP >= 3 && sp == 2)
			{
				sh = tybossHP * 0.08 - 0.01 * tire;
				tybossHP -= sh;
				MP = MP - 3;
				printf("You use skill bloodsucking to deal %d injury to boss, use 3 MP\n\n", sh);
				sp = 0;
			}

			while (MP < 3 && sp == 2)
			{
				printf("MP is less than 3, you can't bloodsucking.\n\n");
				sp = -1;
			}
		}

		while (sp == 3)
		{

			while (MP >= 5 && sp == 3)
			{
				tybossHP = tybossHP - q + 0.01 * tire;
				MP = MP - 5;
				sp = 0;
				printf("You use skill starburst to deal %d injury to boss, use 5 MP\n\n", (int)(q - 0.01 * tire)); //待定
			}
			while (MP < 5 && sp == 3)
			{
				printf("MP is less than 5, you can't bloodsucking starburst \n\n");
				sp = -1;
			}
		}
		while (tybossHP > 0 && sp == 0)
		{
			if (tybossHP > HPboss * 0.1) //boss血量下降到10%以下暴怒
			{
				sh = 15 + HP * 0.01 - edf;
				HP = HP - sh;
				printf("Boss hit you, your HP has reduced %d points\n\n", sh);
				sp = -1;
			}
			else
			{
				printf("Boss becomes violent.");
				sh = 15 + HPboss * 0.1 - edf; //伤害提升
				HP = HP - sh;
				printf("Boss uses crazy chaos, your HP reduces %d points.\n\n", sh);
				sp = -1;
			}
		}
	}
	while (tybossHP <= 0 && i == 1)
	{
		printf("You have killed BOSS, congratulations!\n");
		i = i + 1;
	}
	while (HP < 0 && i == 1)
	{
		printf("You have been killed and your tire has increased dramatically.\n");
		i = i + 2;
		tire += 200;
		getchar();
		printf("You have been resurrected in place.\nYour HP, MP have been recovered.\n");
		HP = 200 + 20 * lv;
		MP = 20 + 2 * lv;
	}
}

//史莱姆
void Dun1(void)
{
	printf("Slime is coming!\n");

	HPboss = 100;

	tybossHP = HPboss;
}
void Dun2(void)
{
	if (i == 2)
	{
		printf("You gain 20ex, 50 golds"); //怪物经验已全部调整

		ex = ex + 20;

		gold = gold + 50;

		printf("Your exp is %d\n", ex);
	}
	else
	{
		printf("I feel sorry for you.\n");
	}
}

void Dunge1(void) //哥布林
{
	printf("Goblin is coming!\n");

	HPboss = 300; //BOSS的HP

	tybossHP = HPboss;
}
void Dunge2(void) //end
{
	if (i == 2)
	{
		printf("You gain 100ex, 200 golds\n");

		ex = ex + 100;

		gold = gold + 200;

		printf("Your exp is %d\n", ex);
	}
	else
	{
		printf("I feel sorry for you.\n");
	}
}
void Dungeon1(void)
{
	printf("Monster is coming!\n");

	HPboss = 800;

	tybossHP = HPboss;
}
void Dungeon2(void)
{
	if (i == 2)
	{
		printf("You gain 300ex, 500 golds.\n");

		ex = ex + 300;

		gold = gold + 500;

		printf("Your exp is %d\n", ex);
	}
	else
	{
		printf("I feel sorry for you.\n");
	}
}

void Dungeonroom(int i)
{
	switch (i)

	{

	case 1:
		Dun();
		break;

	case 2:
		Dun();
		Dunge();
		break;

	case 3:
		Dun();
		Dun();
		Dunge();
		Dungeon();
		break;
	}
	lvup();
	HP = 200 + 20 * lv;
	MP = 20 + 2 * lv;
}
