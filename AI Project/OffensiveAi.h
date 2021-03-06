#include "Constants.h"
#include "DataTrack.h"

class aiArrayOffensive
{
      short int moveSet[ARRAY_SIZE][ARRAY_SIZE];//negative values indicate lack of initiation to actual positions
      int totalScore;                  //for the current iteration
      int wins;
      int losses;
      int draws;
      unsigned int identNum;     //do not exceed ~200,000 iterations, or this # will be too high and u go kaput.
      
      public:
              aiArrayOffensive();
              void setArray(short int arr[][ARRAY_SIZE]);
              void setElement(int row, int col, int val);
              void setScore(int score);
              void setWins(int w);
              void setLoss(int l);
              void setDraws(int d);
              void printArray();
              int dumpToFile();       //writes contents of the class to a predetermined file, useful in death
              void kill();             //does all the necessary things before killing a class member (like logs)
              int getScore();
              int getWins();
              int getLoss();
              int getDraws();
              unsigned int getIdent();
              //public for convenience... dont want to write all those get and set functions... bleh
              DataTrack stats;           // lifetime wins, losses, draws, birth(iteration #),
                           //death(iteration #), id#, spawned from id#, gave birth to id#.
                           //0 values indicate data not relevant or set (if generated randomly, spawned from
                           //will be 0, or if did not give birth to anyone.)
};

aiArrayOffensive::aiArrayOffensive()
{
   for(int i=0; i<ARRAY_SIZE; i++)
   {
           for(int s=0; s<ARRAY_SIZE; s++)
           {
                   moveSet[i][s]=-1;          //Row-Major order, rows filled row by row (across), 
                                              //going across columns s,
                                              //i.e. 'i' denotes the row #, s the column #.
           }
   }
   
   totalScore=0;
   wins=0;
   losses=0;
   draws=0;
   identNum=idCount;
   stats.birth=onIteration;
   stats.death=0;
   stats.lifeDraws=0;
   stats.lifeLosses=0;
   stats.lifeWins=0;
   stats.numReproduced=0;
   stats.parent1=0;
   stats.parent2=0;
   stats.survivalCount=0;
   stats.numReproduced=0;
   idCount++;
}

void aiArrayOffensive::setArray(short int arr[][ARRAY_SIZE])
{
     for(int i=0; i<ARRAY_SIZE; i++)
   {
           for(int s=0; s<ARRAY_SIZE; s++)
           {
                   moveSet[i][s]=arr[i][s];          
                                              //Row-Major order, rows filled row by row (across), 
                                              //going across columns s,
                                              //i.e. 'i' denotes the row #, s the column #.
           }
   }
}

void aiArrayOffensive::setElement(int row, int col, int val)
{
     moveSet[row][col]=val;
}

void aiArrayOffensive::setScore(int score)
{
     totalScore=score;
}

void aiArrayOffensive::setWins(int w)
{
     wins=w;
}

void aiArrayOffensive::setLoss(int l)
{
     losses=l;
}

void aiArrayOffensive::setDraws(int d)
{
     draws=d;
}

void aiArrayOffensive::printArray()
{
     for(int k=0; k<ARRAY_SIZE; k++)
     {
             for(int j=0;j<ARRAY_SIZE; j++)
             {
                     cout<<moveSet[k][j]<<" ";
             }
             
             cout<<endl;
     }
}

int aiArrayOffensive::dumpToFile()
{
     printf("Not implemented yet.... finish the code and try again later.\n");
     
     return 1;
}

void aiArrayOffensive::kill()
{
     printf("Cant kill me! ..\n");
}

int aiArrayOffensive::getScore()
{
     return totalScore;
}

int aiArrayOffensive::getWins()
{
     return wins;
}

int aiArrayOffensive::getLoss()
{
     return losses;
}

int aiArrayOffensive::getDraws()
{
     return draws;
}

unsigned int aiArrayOffensive::getIdent()
{
     return identNum;
}