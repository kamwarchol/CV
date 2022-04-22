#include <io.h>
#include "system.h"
#include <unistd.h>
#include <io.h>

void wave (int signal)
{
    switch(signal){
    case 1:
        IOWR(PIO_GPIO_BASE,0x00,1);
        break;
    case 2:
        IOWR(PIO_GPIO_BASE,0x00,2);
        break;
    case 3:
        IOWR(PIO_GPIO_BASE,0x00,4);
        break;
    case 4:
        IOWR(PIO_GPIO_BASE,0x00,8);
        break;
    }
}

void fullstep (int signal)
{
    switch(signal){
    case 1:
        IOWR(PIO_GPIO_BASE,0x00,3);
        break;
    case 2:
        IOWR(PIO_GPIO_BASE,0x00,6);
        break;
    case 3:
        IOWR(PIO_GPIO_BASE,0x00,12);
        break;
    case 4:
        IOWR(PIO_GPIO_BASE,0x00,9);
        break;
    }
}

void halfstep (int signal)
{
    switch(signal){
    case 1:
        IOWR(PIO_GPIO_BASE,0x00,1);
        break;
    case 2:
        IOWR(PIO_GPIO_BASE,0x00,3);
        break;
    case 3:
        IOWR(PIO_GPIO_BASE,0x00,2);
        break;
    case 4:
        IOWR(PIO_GPIO_BASE,0x00,6);
        break;
    case 5:
        IOWR(PIO_GPIO_BASE,0x00,4);
        break;
    case 6:
        IOWR(PIO_GPIO_BASE,0x00,12);
        break;
    case 7:
        IOWR(PIO_GPIO_BASE,0x00,8);
        break;
    case 8:
        IOWR(PIO_GPIO_BASE,0x00,9);
        break;
    }
}

int main()
{
int przycisk = 0;     //1 kierunek 2 wave 3 fullstep 4 halfstep
int counter = 0;
int button = 0;
int licznikpredkosci = 0;
while (1)
  {
	przycisk = IORD(PIO_SW_BASE,0);
  button = IORD(PIO_KEY_BASE,0);

  switch (przycisk){
      case 2:       //prawe wave
    	  if (counter > 4){counter = 1;}
    	  wave(counter);
    	  counter++;
      break;
      case 3:       //lewe wave
    	  if (counter < 1){counter = 4;}
    	  wave(counter);
    	  counter--;
      break;
      case 4:       //prawe halfstep
    	  if (counter > 8){counter = 1;}
    	  halfstep(counter);
    	  counter++;
      break;
      case 5:       //lewe halfstep
    	  if (counter < 1){counter = 8;}
    	   halfstep(counter);
    	   counter--;
      break;
      case 8:       //prawe fullstep
    	  if (counter > 4){counter = 1;}
    	  fullstep(counter);
    	  counter++;
      break;
      case 9:       // lewe fullstep
    	  if (counter < 1){counter = 4;}
    	  fullstep(counter);
    	  counter--;

  }
	if (licznikpredkosci > 9){licznikpredkosci = 9;}
	  if (licznikpredkosci < 0){licznikpredkosci = 0;}

	  if (button == 1){licznikpredkosci++;}
	  if (button == 2){licznikpredkosci--;}

	  switch (licznikpredkosci){
	  	  	case 0:
	  	  		usleep(1000000);
	  	  		IOWR(PIO_LED_BASE,0,1);
	  	    break;
	  	    case 1:
	  	    	 usleep(900000);
	  	    	 IOWR(PIO_LED_BASE,0,3);
	  	    break;
	  	    case 2:
	  	    	 usleep(800000);
	  	    	 IOWR(PIO_LED_BASE,0,7);
	  	   break;
	  	   case 3:
	  	  	    usleep(700000);
	  	  	    IOWR(PIO_LED_BASE,0,15);
	  	  break;
	  	  case 4:
	  	  	  usleep(600000);
	  	  	  IOWR(PIO_LED_BASE,0,31);
	  	  break;
	  	   case 5:
	  	  	  	  usleep(500000);
	  	  	  	  IOWR(PIO_LED_BASE,0,63);
	  	  	  break;
	  	   case 6:
	  	  	  	  usleep(400000);
	  	  	  	  IOWR(PIO_LED_BASE,0,127);
	  	  	  break;
	  	  case 7:
	  	  	  	  usleep(300000);
	  	  	  	  IOWR(PIO_LED_BASE,0,255);
	  	  	  break;
	  	   case 8:
	  	  	  	  usleep(200000);
	  	  	  	  IOWR(PIO_LED_BASE,0,511);
	  	  	  break;
	  	   case 9:
	  	  	  	  usleep(100000);
	  	  	  	  IOWR(PIO_LED_BASE,0,1023);
	  	  	  break;



  }
  };
  return 0;
}
