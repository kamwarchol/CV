#ifdef DE10
 #include <io.h>
 #include "system.h"
 #include "sys/alt_stdio.h"
#else
 #include <stdio.h>
 #include <unistd.h>
#endif
/*--------------------------------------------------------------------*/
void Show7D(unsigned char a, unsigned char b,
            unsigned char c, unsigned char d,
            unsigned char e, unsigned char f)
{
#ifdef DE10
    const unsigned char DispTab[10]={0xC0,0xF9,0xA4,0xB0,0x99,0x92,0x82,0xF8,0x80,0x90};
    IOWR(PIO_A_BASE,0,DispTab[a%10]);
    IOWR(PIO_B_BASE,0,DispTab[b%10]);
    IOWR(PIO_C_BASE,0,DispTab[c%10]&0x7F);
    IOWR(PIO_D_BASE,0,DispTab[d%10]);
    IOWR(PIO_E_BASE,0,DispTab[e%10]&0x7F);
    IOWR(PIO_F_BASE,0,DispTab[f%10]);
#else
    /* Yoy can change \r to \n */
    printf("%i%i:%i%i.%i%i    \r",f%10,e%10,d%10,c%10,b%10,a%10);
    fflush(stdout);
#endif
}
/*--------------------------------------------------------------------*/
/* Do not edit this function */
unsigned char GetButton(void)
{
unsigned char ret;
#ifdef DE10
    ret=((IORD(PIO_KEY_BASE,0)^0x03) ? 1 : 0);
#else
    static unsigned int i=0;
    unsigned char c=0;
    /* Button Simulator */
    if (i<14000) {i++;} else {i=0;};
    if (((i>200) && (i<208)) || ((i>800) && (i<810)) || ((i>1000) && (i<1010))
       || ((i>1200) && (i<1208)) || ((i>13800) && (i<13810)) || ((i>13900) && (i<13910)))
    {ret=1;} else {ret=0;};
    if (ret) {c='1';} else {c='0';};
    printf("  [%c]   ",c);
#endif
    return ret;
}
/*--------------------------------------------------------------------*/
/* Do not edit this function */
void Wait5ms(void)
{
#ifdef DE10
    static unsigned int t=0;
    while (IORD(PIO_TRIGGER_BASE,0)==t);
    t=IORD(PIO_TRIGGER_BASE,0);
#else
    usleep(5000);
#endif
}
/*--------------------------------------------------------------------*/
int main()
{
    int counter = 0;
    int status = 0;
    unsigned char a=0,b=0,c=0,d=0,e=0,f=0;
    unsigned char button;
    while (1)
    {
        Wait5ms();
        button=GetButton();
        /*----------------------*/
         if (button == 1 && status == 0)
         {
           counter += 1;
           status = 1;
         }
         else if(button == 0)
         {
          status = 0;
          if (counter == 1)    // COUNTING
           {

             f += 5;
             if (f == 10)
             {
              f = 0;
              e += 1;
                if (e == 10)
                {
                  e = 0;
                  d += 1;
                  if (d == 10)
                  {
                    d = 0;
                    c += 1;
                    if (c == 6)
                    {
                      c = 0;
                      b += 1;
                      if (b == 10)
                      {
                        b = 0;
                        a += 1;
                      }
                    }
                  }
                }
             }
          }
            else if (counter == 3)
          {
            counter = 0;
            a=0,b=0,c=0,d=0,e=0,f=0;
          }
        }
        Show7D(a,b,c,d,e,f);
    };
    return 0;
}
/*--------------------------------------------------------------------*/
