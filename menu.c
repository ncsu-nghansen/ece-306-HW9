#include "msp430.h"
#include "macros.h"
#include "functions.h"

char isQuit = 0;
char isSelected = 0;

char Song[225] = "We're the Red and White from State, and we know we are the best. A hand behind our back, We can take on all the rest. Come over the hill, Carolina. Devils and Deacs stand in line. The Red and White from N.C. State. Go State!";


void ResistorMenu(void)
{
  while(!isQuit)
  {
          ADC_Process();      
          //          "0123456789abcdef"
          display_1 = "  Value  Color  ";
          
          switch(ADC_Thumb/102)
          {
          case 0:
            //          "123456789abcdef"
            display_2 = "   0   Black   ";
            break;
          case 1:
            //          "123456789abcdef"
            display_2 = "   1   Brown   ";
            break;
          case 2:
            //          "123456789abcdef"
            display_2 = "   2   Brown   ";
            break;
          case 3:
            //          "123456789abcdef"
            display_2 = "   3     Red   ";
            break;
          case 4:
            //          "123456789abcdef"
            display_2 = "   4   Yellow  ";
            break;
          case 5:
           //          "123456789abcdef"
            display_2 = "   5   Green  ";
            break;
          case 6:
           //          "123456789abcdef"
            display_2 = "   6    Blue  ";
            break;
          case 7:
            //          "123456789abcdef"
            display_2 = "   7   Violet  ";
            break;
          case 8:
            //          "123456789abcdef"
            display_2 = "   8    Gray   ";
            break;
          case 9:
            //          "123456789abcdef"
            display_2 = "   9   White   ";
            break;
          default:
            break;
          }
          
          if(TimeMsec % EVERY_50 == RESET_TIME)
                  Display_Process();
  }
  
  isQuit = 0;
}

void ShapesMenu(void)
{
  while(!isQuit)
  {
          ADC_Process();      
          
          switch(ADC_Thumb/102)
          {
          case 0:
            //          "123456789abcdef"
            display_1 = "     Circle    ";
            display_2 = "     Square    ";
            break;
          case 1:
            //          "123456789abcdef"
            display_1 = "     Square    ";
            display_2 = "    Triangle   ";
            break;
          case 2:
            //          "123456789abcdef"
            display_1 = "    Triangle   ";
            display_2 = "    Octagon    ";
            break;
          case 3:
            //          "123456789abcdef"
            display_1 = "    Octagon    ";
            display_2 = "    Pentagon   ";
            break;
          case 4:
            //          "123456789abcdef"
            display_1 = "    Pentagon   ";
            display_2 = "    Hexagon    ";
            break;
          case 5:
            //          "123456789abcdef"
            display_1 = "    Hexagon    ";
            display_2 = "      Cube     ";
            break;
          case 6:
           //           "123456789abcdef"
            display_1 = "      Cube     ";
            display_2 = "      Oval     ";
            break;
          case 7:
            //          "123456789abcdef"
            display_1 = "      Oval     ";
            display_2 = "     Sphere    ";
            break;
          case 8:
            //          "123456789abcdef"
            display_1 = "     Sphere    ";
            display_2 = "    Cylinder   ";
            break;
          case 9:
            //          "123456789abcdef"
            display_1 = "    Cylinder   ";
            display_2 = "  END OF LIST  ";
            break;
          default:
            break;
          }
          
          if(TimeMsec % EVERY_50 == RESET_TIME)
                  Display_Process();
  }
  
  isQuit = 0;
}

void SongMenu(void)
{
  ScrollIndex = 0;
  
  while(!isQuit)
  {
    
    
    for(int i = 0; i < DISPLAY_SIZE; i++)
      display_2[i] = Song[i+ScrollIndex];
    
    if(TimeMsec % 10 == 0)
    {
            ADC_Process();
      
      if(ADC_Thumb - OldThumb > 5)
        ScrollIndex++;
      
      OldThumb = ADC_Thumb;
      ScrollIndex %= sizeof Song;
    }
    
    if(TimeMsec % EVERY_50 == RESET_TIME)
    {
      Display_Process();
    }
    

  }
  
  isQuit = 0;
}

void Menu_Process(void)
{
  if(!isSelected)
    return;
  
  switch(ProgramState)
  {
    case 0:
      ResistorMenu();
      break;
    case 1:
      ShapesMenu();
      break;
    case 2: 
      SongMenu();
      break;    
  }
  
  isSelected = 0;
}

void MenuSelect(void)
{
  isSelected = 1;
}

void MenuQuit(void)
{
  isQuit = 1;
}