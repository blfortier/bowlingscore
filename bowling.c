#include <cs50.h>
#include <stdio.h>
#include <assert.h>

void tests(void);
void bowlGameInit(void);
void bowlGameRoll(int pins);
int bowlGameScore(void);



int main(void)
{
    tests();
}

void rollMany(int rolls, int value)
{
    for(int i = 0; i < rolls; i++)
    {
        bowlGameRoll(value);
    }
}


void testGutterGame()
{
    bowlGameInit();
   rollMany(20, 0);
    assert(bowlGameScore() == 0 && "Gutter game should result in 0");
}


void testAllOnes()
{
    bowlGameInit();
    rollMany(20, 1);
    assert(bowlGameScore() == 20 && "All one game should result in 1");
}

void testOneSpare()
{
    bowlGameInit();
    bowlGameRoll(5);
    bowlGameRoll(5);
    bowlGameRoll(3);  //spare
    rollMany(17, 0);
    asseert(bowlGameScore() == 16 && "single spare and 3 should result in 16");
}

void testOneStrike()
{
    bowlGameInit();
    bowlGameRoll(10);
    bowlGameRoll(4);  // strike bonus
    bowlGameRoll(3);
    rollMany(16, 0);
    assert(bowlGameScore() == 24 && "strike and frame of 4 and 3 should result in 24");
}

void testPerfectGame()
{
    bowlGameInit();
    rollMany(12, 10);
    assert(bowlGameScore() == 300 && "perfect game should result in 300")
}

void testGivenGame()
{
    bowlGameInit();
    int bowlGame[21] = {1,4,4,5,6,4,5,5,10,0,0,1,7,3,6,4,10,0,2,8,6};
    int rollIndex = 0;
    for (int frame = 0; frame < 21; frame++)
    {
        if (bowlGame[rollIndex] == 10)
        {
            bowlGameRoll(bowlGame[rollIndex]);
            rollIndex += 2;
            
        }
        else
        {
            bowlGameRoll(bowlGame[rollIndex]);
            bowlGameRoll(bowlGame[rollIndex + 1]);
            rollIndex += 2;
        }
    }
    
    bowlGameRoll(bowlGame[20]);
    printf();
    assert(bowlGameScore() == 133 && "Given game should result in 133");
}


void test(void)
{
    testGutterGame();
    testAllOnes();
    testOneSpare();
    testOneStrike();
    testGivenGame();
}

int MAXROLLS = 21;
int rolls[21];
int currentRoll;

void bowlGameInit(void)
{
    for (int i = 0; i < MAXROLLS; i++)
    {
        rolls[i] = 0;
    }
    currentRoll = 0;
    
}

void bowlGameRoll(int pins)
{
    rolls[currentRoll++] = pins;
    
}

bool isSpare(int rollIndex)
{
    return rolls[rollIndex] + rolls[rollIndex + 1] == 10;
}

bool isStrike(int rollIndex)
{
    return rolls[rollIndex] == 10;   
}

int spareScore(rollIndex)
{
    score += 10 + rolls[rollIndex + 1] + rolls[rollIndex + 2];
}

int applySpareScore()
{
     return rolls[rollIndex] + rolls[rollIndex + 2];
}

int applyStrikeScore()
{
     return 10 + rolls[rollIndex + 1] + rolls[rollIndex + 2];   
}

int applyNormalScore()
{
    return rolls[rollIndex] + rolls[rollIndex + 1];
}

int bowlGameScore(void) 
{
    int score = 0;
    int rollIndex = 0;
    for (int frames = 0; frames < MAXROLLS; frames++)
    {
        if(isSpare(rollIndex))   
        {
            score += applySpareScore( int rollIndex);
            rollIndex += 2;
        }
        else if (isStrike(rollIndex))
        {
            score += applyStrikeScore(int rollIndex);
            rollIndex += 1;
        }
        else
        {
            score += applyNormalScore(int rollIndex);
            rollIndex += 2;
        }
    }

    return score;
}


