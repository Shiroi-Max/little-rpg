#include "defs.h"
/**
    \mainpage Little RPG - Programming Technology Project
    The application consists of a game that tries to collect as many coins as possible. If you collide with an enemy, the game ends and you are redirected to the record screen, where your total points and the highest record in the game are displayed. To attack enemies, throw fireballs in order to kill them. Coins return 2 mana points, while throwing a fireball consumes 1 mana point.
*/

int main(int argc, char **argv)
{
    create_Screen("Little RPG", 800, 600);

    Image title = readImage_Screen("img/screens/title.bmp", 0);
    Image startingScreen = readImage_Screen("img/screens/startingScreen.bmp", 0);
    Image gameScreen = readImage_Screen("img/screens/level_1.bmp", 0);
    Image recordScreen = readImage_Screen("img/screens/record_screen.bmp", 0);
    Image messageBox = readImage_Screen("img/boxes/message_box.bmp", 0);

    Image mibo = readImage_Screen("img/boxes/menu_box.bmp", 0);
    Image mico1 = readImage_Screen("img/boxes/continue.bmp", 0);
    Image mict1 = readImage_Screen("img/boxes/controls.bmp", 0);
    Image miex1 = readImage_Screen("img/boxes/exit.bmp", 0);
    Image mico2 = readImage_Screen("img/boxes/continue(on).bmp", 0);
    Image mict2 = readImage_Screen("img/boxes/controls(on).bmp", 0);
    Image miex2 = readImage_Screen("img/boxes/exit(on).bmp", 0);
    Image controlsBox = readImage_Screen("img/boxes/controls_box.bmp", 0);

    Image pisr = readImage_Screen("img/token/character/stay/right/1.bmp", 255);
    Image pisl = readImage_Screen("img/token/character/stay/left/1.bmp", 255);
    Image pirr = readImage_Screen("img/token/character/run/right/1.bmp", 255);
    Image pirl = readImage_Screen("img/token/character/run/left/1.bmp", 255);
    Image pijr = readImage_Screen("img/token/character/jump/right/1.bmp", 255);
    Image pijl = readImage_Screen("img/token/character/jump/left/1.bmp", 255);

    Image eir = readImage_Screen("img/token/enemy/right/1.bmp", 255);
    Image eil = readImage_Screen("img/token/enemy/left/1.bmp", 255);

    Image coin = readImage_Screen("img/token/Coin.bmp", 255);

    Menu m = createMenu(mibo, mico1, mico2, mict1, mict2, miex1, miex2, width_Screen() - 500, height_Screen() - 400, 200, 200);
    Character p = createCharacter(pisr, pisl, pirr, pirl, pijr, pijl, 350, height_Screen() - 160, 50, 70);
    Treasure t = createTreasure(1);
    Shooting s = createShooting();
    Army a = createArmy(1);

    int end = 0;
    int control = 1;
    int last = 0;
    int endMenuScreen = 0;
    int endControlsScreen = 0;
    int endStartingScreen = 0;
    int endGameScreen = 0;
    int endRecordsScreen = 0;

    char name[20];
    char *nameAux = NULL;
    int counter = 50;
    int mana = 20;
    int nCoins = 0;
    int nDeaths = 0;
    int score = 0;

    while (!end)
    {
        switch (control)
        {
            // Menu Screen
        case 0:
        {
            endMenuScreen = 0;
            int goRecordsScreen = 0;
            int goControlsScreen = 0;
            while (active_Screen() && !endMenuScreen && !goRecordsScreen && !goControlsScreen)
            {
                drawMenu(m);
                int menuStatus = actionMenu(m);

                if ((menuStatus == 1) && (isisButtonMousePressed_Screen(SDL_BUTTON_LEFT)))
                    endMenuScreen++;

                if ((menuStatus == 2) && (isButtonMousePressed_Screen(SDL_BUTTON_LEFT)))
                    goControlsScreen++;

                if ((menuStatus == 3) && (isButtonMousePressed_Screen(SDL_BUTTON_LEFT)))
                    goRecordsScreen++;

                update_Screen();
                wait_Screen(150);
            }
            control = last;
            if (goRecordsScreen == 1)
                control = 3;
            if (goControlsScreen == 1)
                control = 5;
        }
        break;

        case 5: // Controls Screen
        {
            endControlsScreen = 0;
            while (active_Screen() && !endControlsScreen)
            {
                drawImage_Screen(controlsBox, width_Screen() - 600, height_Screen() - 500, 400, 400);

                if (isKeyPressed_Screen(SDL_SCANCODE_ESCAPE))
                    endControlsScreen = 1;
                update_Screen();
                wait_Screen(150);
            }
            control = last;
        }
        break;

        case 1: // Starting Screen
        {
            endStartingScreen = 0;
            while (active_Screen() && !endStartingScreen)
            {
                drawImage_Screen(title, 0, 0, width_Screen(), height_Screen());

                int change = 0;
                if (isKeyPressed_Screen(SDL_SCANCODE_SPACE))
                    change++;
                switch (change)
                {
                case 0:
                {
                    if (counter % 10)
                    {
                        drawImage_Screen(messageBox, width_Screen() - 575, height_Screen() - 150, 334, 64);
                        drawText_Screen("Press SPACE to sign up your name", 250, 465);
                        strokeColor_Screen(255, 255, 255, 255);
                    }
                    counter++;
                }
                break;
                case 1:
                {
                    drawImage_Screen(startingScreen, 0, 0, width_Screen(), height_Screen());
                    nameAux = readText_Screen(width_Screen() - 500, height_Screen() - 300, 20, "Adventurer's name");
                    if (nameAux != NULL)
                        endStartingScreen++;
                }
                }
                update_Screen();
                wait_Screen(150);
            }
            sprintf(name, "%s", nameAux);
            free(nameAux);
            control = 2;
        }
        break;

        case 2: // Game Screen
        {
            counter = 10;
            endGameScreen = 0;
            while (active_Screen() && !endGameScreen && (control == 2))
            {
                score = nCoins + nDeaths;

                if (isKeyPressed_Screen(SDL_SCANCODE_ESCAPE))
                {
                    last = control;
                    control = 0;
                }

                if (rand() % 2 == 0)
                    insertArmy(a, eir, eil, width_Screen() + 100, height_Screen() - 160, 50, 70, 3);
                if (rand() % 2 == 1)
                    insertArmy(a, eir, eil, -100, height_Screen() - 160, 50, 70, 3);

                if (rand() % 150 == 0)
                    insertTreasure(t, coin, rand() % (width_Screen() - 20), height_Screen() - 120, 20, 20);

                if (mana > 0)
                {
                    if (counter == 50 && isKeyPressed_Screen(SDL_SCANCODE_C))
                    {
                        {
                            insertShooting(s, p);
                            mana -= 1;
                            counter = 0;
                        }
                    }
                    else if (counter < 50)
                        counter++;
                }

                moveCharacter(p, 3, 5);
                animateCharacter(p);
                moveArmy(a);
                animateArmy(a);
                moveShooting(s);

                int ecf = collisionArmyShooting(a, s);
                nDeaths++;

                int ec = collisionArmy(a, p);
                if (ec != 0)
                    endGameScreen++;

                int tc = collisionTreasure(t, p);
                if (tc != 0)
                {
                    mana += 2;
                    nCoins++;
                }

                char s[100];
                sprintf(s, "%d", score);
                char m[100];
                sprintf(m, "%d", mana);

                drawImage_Screen(gameScreen, 0, 0, width_Screen(), height_Screen());
                drawCharacter(p);
                drawArmy(a);
                drawShooting(s);
                drawTreasure(t);
                drawText_Screen("Press ESC to menu", 25, 15);
                strokeColor_Screen(255, 255, 255, 255);
                drawText_Screen("Mana:", 25, 40);
                drawText_Screen(m, 70, 40);
                drawText_Screen(s, 775, 15);

                update_Screen();
                wait_Screen(10);
            }
            if (control == 2)
                control = 3;
        }
        break;

        case 3: // Records Screen
        {
            int r;
            char recordName[20];
            FILE *f = fopen("record_results.txt", "r");
            fscanf(f, "%d", &r);
            fclose(f);
            if (r < score)
            {
                f = fopen("record_results.txt", "w");
                fprintf(f, "%d", score);
                fclose(f);
                f = fopen("record_results.txt", "r");
                fscanf(f, "%d", &r);
                fclose(f);
                f = fopen("record_players.txt", "w");
                fprintf(f, "%s", name);
                fclose(f);
            }
            f = fopen("record_players.txt", "r");
            fscanf(f, "%s", recordName);
            fclose(f);

            endRecordsScreen = 0;
            while (active_Screen() && !endRecordsScreen)
            {
                if (isKeyPressed_Screen(SDL_SCANCODE_RETURN))
                    endRecordsScreen++;

                char s1[100];
                sprintf(s1, "%d", r);
                char s2[100];
                sprintf(s2, "%d", score);

                drawImage_Screen(recordScreen, 0, 0, width_Screen(), height_Screen());

                drawText_Screen("Press ENTER to exit", 30, 20);
                strokeColor_Screen(255, 255, 255, 255);
                drawText_Screen("HIGHEST RECORD", 335, 220);
                drawText_Screen(recordName, 320, 250);
                drawText_Screen(s1, 465, 250);
                drawText_Screen("YOUR RECORD", 350, 300);
                drawText_Screen(name, 320, 330);
                drawText_Screen(s2, 465, 330);

                update_Screen();
                wait_Screen(150);
            }
            control = 4;
        }
        break;

        case 4: // End Screen
            end = 1;
        }
    }

    freeImage_Screen(title);
    freeImage_Screen(startingScreen);
    freeImage_Screen(gameScreen);
    freeImage_Screen(recordScreen);
    freeImage_Screen(messageBox);

    freeImage_Screen(controlsBox);

    freeMenu(m);
    freeCharacter(p);
    freeArmy(a);
    freeShooting(s);
    freeTreasure(t);
    free_Screen();
    return 0;
}
